#include<iostream>
using namespace std;

int sumata;
int doKadePoznava;

int priTolkova[1000000];

void kolkoNaiMalkoChisla(int sumichka){
    priTolkova[0] = 0;

    for(int s = 1; s <= sumichka; s++){
        int naiDobroto = 10000000;

        for(int i = 1; i <= doKadePoznava; i++){
            int sPlus = 10000000;
            int sPo = 10000000;

            if(s >= i){
                sPlus = 1 + priTolkova[s - i];
            }

            if(i > 1 && s%i == 0){
                sPo = 1 + priTolkova[s/i];
            }

            int tekushtoNaiDobro = min(sPlus, sPo);

            if(tekushtoNaiDobro < naiDobroto){
                naiDobroto = tekushtoNaiDobro;
            }

        }

        priTolkova[s] = naiDobroto;

    }
}

int main(){
    cin>>sumata>>doKadePoznava;

    kolkoNaiMalkoChisla(sumata);

    int naiMalkiqBroiChisla = priTolkova[sumata];

    cout<<naiMalkiqBroiChisla<<endl;

    return 0;
}
