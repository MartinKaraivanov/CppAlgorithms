/* Програма за въртене и разместване на куб на Рубик.  От стандартния вход
   прочита развивка.  На стандартния изход извежда развивка, резултат от
   преобразуването.  Ако се изпълнява без параметър, извършва се само
   пространствено завъртане на куба.  С (какъв да е) параметър на командния
   ред извършва и въртене на куба, и разместване на цветовете по стените му
   чрез въртене на частите една спрямо друга.
   Може да се използва за пораждане на тестове за програмата за сравняване
   на развивки и за други цели, свързани с куба на Рубик.
   Съвсем лесно може да се промени или допълни, така че завъртанията и
   разместванията да бъдат не случайни, а какви да е конкретно избрани.
   В този вид може да служи за изследване на резултатите от преобразованията
   над куба.

   Схема на номериране на местата в/у развивката:
        4
      3 0 1 2
        5                                                                 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// куб с 6 стени, 9 клетки на стена:
char f[6][9];

// литери, използвани за задаване на цветовете в/у куб:
char cols[6];

// номера на клетки в/у стена при завъртане на 0°\90°\180°\270°:
int cn[][9] =  {
  {0,1,2,3,4,5,6,7,8},  {2,5,8,1,4,7,0,3,6},
  {8,7,6,5,4,3,2,1,0},  {6,3,0,7,4,1,8,5,2}
};

int fs[] = {0,1,2,3,4,5},   // текуща пермутация на 6-те стени
                            // (f[fs[0]] е челната стена на f и т.н.)
    rn[] = {0,0,0,0,0,0};   // текущи кратности на въртене (0-3) на всяка
                            // от стените, както са в/у развивката

// цвят на клетка k от стена n, в каноничния интервал и в оригинал:
#define ICELL(n,k) f[fs[n]][cn[rn[fs[n]]][k]]
#define CCELL(n,k) cols[(unsigned)ICELL(n,k)]
// цветове на ред k от клетки на стена n, в оригинал:
#define CCROW(n,k) CCELL(n,3*k),CCELL(n,3*k+1),CCELL(n,3*k+2)

// циклична замяна на 2, 3 или 4 посочени по индекси елемента в масив:
#define SWAP(i,j)  {int t=fs[j]; fs[j]=fs[i]; fs[i]=t;}
#define ROT3(i,j,k)  {int t=fs[k]; fs[k]=fs[j]; fs[j]=fs[i]; fs[i]=t;}
#define ROT4(i,j,k,m)  {int t=fs[m]; fs[m]=fs[k]; fs[k]=fs[j]; fs[j]=fs[i]; fs[i]=t;}
// завъртане на i*90° на стената fs[n] в равнината на развивката:
#define RT90(n,i)  (rn[fs[n]]=(rn[fs[n]]+i)%4)

void trn1()  {    // въртене y(90)
  ROT4(0,1,2,3)
  RT90(4,1);  RT90(5,3);
}

void trn2()  {    // въртене z(180)
  int i;
  SWAP(1,3)  SWAP(4,5)
  for (i=0; i<6; ++i)  RT90(i,2);
}

void trn3()  {    // въртене z(90), после x(90)
  ROT3(5,1,0)  ROT3(4,3,2)
  RT90(0,1);  RT90(1,2);  RT90(2,3);  RT90(4,1);  RT90(5,1);
}

// разместване на куба чрез въртене на горния му слой на n*90°
void scramble(int n)  {
  int i,j,t;
  RT90(4,n);
  for (n=4-n; n>0; --n)
    for (j=0; j<3; ++j)  {
      t = ICELL(0,j);
      for (i=0; i<3; ++i)  ICELL(i,j) = ICELL((i+1)%4,j);
      ICELL(i,j) = t;
    }
}

void rdcube()  {    // прочитане на развивка
  char *p, *q;  int n,i;
  scanf(" %3c %3c %3c ",f[4]+0,f[4]+3,f[4]+6);
  scanf("%3c%3c%3c%3c ",f[3]+0,f[0]+0,f[1]+0,f[2]+0);
  scanf("%3c%3c%3c%3c ",f[3]+3,f[0]+3,f[1]+3,f[2]+3);
  scanf("%3c%3c%3c%3c ",f[3]+6,f[0]+6,f[1]+6,f[2]+6);
  scanf("%3c %3c %3c ",f[5]+0,f[5]+3,f[5]+6);
  for (n=0,p=(char*)f,q=p+sizeof(f); p<q; *p++=i)  {
    for (i=0; i<n && *p!=cols[i]; ++i)  ;
    if (i==n)  cols[n++] = *p;
  }
}

void prncube()  {    // отпечатване на развивка
  printf("   %c%c%c\n",CCROW(4,0));
  printf("   %c%c%c\n",CCROW(4,1));
  printf("   %c%c%c\n",CCROW(4,2));
  printf("%c%c%c%c%c%c%c%c%c%c%c%c\n",CCROW(3,0),CCROW(0,0),CCROW(1,0),CCROW(2,0));
  printf("%c%c%c%c%c%c%c%c%c%c%c%c\n",CCROW(3,1),CCROW(0,1),CCROW(1,1),CCROW(2,1));
  printf("%c%c%c%c%c%c%c%c%c%c%c%c\n",CCROW(3,2),CCROW(0,2),CCROW(1,2),CCROW(2,2));
  printf("   %c%c%c\n",CCROW(5,0));
  printf("   %c%c%c\n",CCROW(5,1));
  printf("   %c%c%c\n",CCROW(5,2));
}

// Прочита развивка на куб, извършва 1000 случайно избрани завъртания на куба,
// а ако е с параметър – извършва някакъв (случаен) брой размествания на куба,
// пръснати по случаен начин между завъртанията му
int main(int argc, char *argv[])  {
  int i,j;
  void (*ts[])() = {trn1,trn2,trn3};
  srand(time(NULL));
  rdcube();
  for (i=1000; i>0;)  {
    for (j=rand()%50,i-=j; j>=0; --j)  ts[rand()%3]();
    if (argc>1)  scramble(1+rand()%3);
  }
  prncube();
}
