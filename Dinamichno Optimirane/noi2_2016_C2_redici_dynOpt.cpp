#include<iostream>
using namespace std;

int otKolkoDaEPoMalakVsekiChlen;
int broiSabiraemi;
int otKolkoDaEPoMalkoSbora;

long long brRedici[100][100];


void namirane(){
    for(int m=1;m<=broiSabiraemi;m++){
        for(int x=0;x<=otKolkoDaEPoMalkoSbora;x++){
            if(m==1){
                if(x<otKolkoDaEPoMalakVsekiChlen){
                    brRedici[m][x]=1;
                }else{
                    brRedici[m][x]=0;
                }
            }else{
                long long broRedici=0;
                for(int posledenChlen=0;posledenChlen<=min(otKolkoDaEPoMalakVsekiChlen-1,x);posledenChlen++){
                    broRedici+=brRedici[m-1][x-posledenChlen];
                }
                brRedici[m][x]=broRedici;
            }
        }
    }
}

int main(){
    cin>>otKolkoDaEPoMalakVsekiChlen>>broiSabiraemi>>otKolkoDaEPoMalkoSbora;

    namirane();

    long long broiRedichki=0;

    for(int sbor=0;sbor<otKolkoDaEPoMalkoSbora;sbor++){
        broiRedichki+=brRedici[broiSabiraemi][sbor];
    }

    cout<<broiRedichki<<endl;

    return 0;
}
