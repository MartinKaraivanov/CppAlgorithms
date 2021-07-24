#include<iostream>
using namespace std;

int sumata;
int doKadePoznava;

int priTolkova[1000000];

int kolkoNaiMalkoChisla(int sumichka){
    //cout<<"Sumichkata sega e "<<sumichka<<endl;
    if(sumichka == 0){
        return 0;
    }

    if(sumichka < 0){
        return 30000000;
    }

    if(priTolkova[sumichka] > 0){
        return priTolkova[sumichka];
    }

    int naiDobroto = 10000000;

    for(int i = 1; i <= min(doKadePoznava, sumichka); i++){
        int sPlus;
        int sPo = 10000000;

        //out<<"Pri sumichka "<<sumichka<<" sega psukam splus i spo pri i = "<<i<<endl;

        sPlus = 1 + kolkoNaiMalkoChisla(sumichka - i);

        if(i > 1 && sumichka%i == 0){
            sPo = 1 + kolkoNaiMalkoChisla(sumichka/i);
        }

        //cout<<"Pri sumichka "<<sumichka<<" sPlus e "<<sPlus<<" a sPo "<<sPo<<" i e "<<i<<endl;

        int tekushtoNaiDobro = min(sPlus, sPo);

        if(tekushtoNaiDobro < naiDobroto){
            naiDobroto = tekushtoNaiDobro;
        }

    }

    priTolkova[sumichka] = naiDobroto;

    return naiDobroto;
}

int main(){
    cin>>sumata>>doKadePoznava;

    int naiMalkiqBroiChisla = kolkoNaiMalkoChisla(sumata);

    cout<<naiMalkiqBroiChisla<<endl;

    return 0;
}
