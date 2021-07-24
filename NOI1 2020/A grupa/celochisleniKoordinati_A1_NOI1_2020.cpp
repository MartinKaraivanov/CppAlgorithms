#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaOtsechka{
    DanniZaTochka lqvKrai;
    DanniZaTochka desenKrai;
};

struct DanniZaPrava{
    int a;
    int b;
    int c;
};

int broiOtsechki;
DanniZaOtsechka otsechki[5050];

bool imaLiQ[1010][1010];
long long broiTakivaTochki;

int daiKoordinat(int a){
    return a + 500;
}

void otbelezhi(int x, int y){
    if(imaLiQ[daiKoordinat(x)][daiKoordinat(y)] == false){
        imaLiQ[daiKoordinat(x)][daiKoordinat(y)] = true;
        broiTakivaTochki++;
    }
}

DanniZaPrava pravataNaDveteTochki(DanniZaTochka tochka1, DanniZaTochka tochka2){
    int a = tochka1.y - tochka2.y;
    int b = tochka2.x - tochka1.x;
    int c = tochka1.x*tochka2.y - tochka2.x*tochka1.y;

    DanniZaPrava zaVrasht = {a, b, c};

    return zaVrasht;
}

bool tochkataOtPravataLiE(DanniZaPrava p, DanniZaTochka t){
    int suma = p.a*t.x+p.b*t.y+p.c;
    if(suma == 0){
        return true;
    }else{
        return false;
    }
}

int naiGolqmObshtDelitel(int a, int b){
    while(b != 0){
        int p = b;
        b = a%b;
        a = p;
    }
    return a;
}

int main(){
    cin>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        cin>>otsechki[i].lqvKrai.x>>otsechki[i].lqvKrai.y>>otsechki[i].desenKrai.x>>otsechki[i].desenKrai.y;

        if(otsechki[i].lqvKrai.x > otsechki[i].desenKrai.x){
            swap(otsechki[i].lqvKrai, otsechki[i].desenKrai);
        }
    }



    for(int i = 0; i < broiOtsechki; i++){
        DanniZaPrava pravataNaTaziOtsechka = pravataNaDveteTochki(otsechki[i].lqvKrai, otsechki[i].desenKrai);

        if(otsechki[i].lqvKrai.x == otsechki[i].desenKrai.x){
            int otKade = min(otsechki[i].lqvKrai.y, otsechki[i].desenKrai.y);
            int doKade = max(otsechki[i].lqvKrai.y, otsechki[i].desenKrai.y);
            for(int y = otKade; y <= doKade; y++){
                otbelezhi(otsechki[i].lqvKrai.x, y);
            }
        }else{
            int otKade = otsechki[i].lqvKrai.x;
            int doKade = otsechki[i].desenKrai.x;

            int d =
                abs((abs(doKade - otKade))/
                        (naiGolqmObshtDelitel(abs(doKade - otKade), abs(otsechki[i].lqvKrai.y - otsechki[i].desenKrai.y))));

            for(int x = otKade; x <= doKade; x+=d){
                int yZaToziX = (-pravataNaTaziOtsechka.a*x - pravataNaTaziOtsechka.c)/(pravataNaTaziOtsechka.b);

                otbelezhi(x, yZaToziX);
            }
        }
    }

    cout<<broiTakivaTochki<<endl;

    return 0;
}
