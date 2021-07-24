#include<iostream>
using namespace std;

int n;
int m;

int chislaNaCatalan[20500];

int priTolkova[20500];

int broiNachiniNaZdravisvaniq(int broiHora){
    if(broiHora == 0){
        return 1;
    }

    if(broiHora % 2 == 1){
        return 0;
    }

    if(priTolkova[broiHora] > 0){
        return priTolkova[broiHora];
    }

    int segashno = 0;

    for(int j = 0; j <= broiHora - 2; j+=2){
        segashno = (segashno + ((broiNachiniNaZdravisvaniq(j) * broiNachiniNaZdravisvaniq(broiHora - j - 2))%m))%m;
    }

    priTolkova[broiHora] = segashno;

    return segashno;
}

int sCycli(int zaChislo){
    priTolkova[0] = 1;

    for(int broiHora = 2; broiHora <= zaChislo; broiHora+=2){
        int segashno = 0;

        for(int j = 0; j <= broiHora - 2; j+=2){
            segashno = (segashno + ((priTolkova[j] * priTolkova[broiHora - j - 2])%m))%m;
        }

        priTolkova[broiHora] = segashno;
    }

    return priTolkova[zaChislo];
}

int zaKoeChislonaCatalan(int zaChislo){
    chislaNaCatalan[0] = 1;

    for(int i = 0; i < zaChislo; i++){
        for(int j = 0; j <= i; j++){
            chislaNaCatalan[i + 1] = (chislaNaCatalan[i + 1] + ((chislaNaCatalan[j] * chislaNaCatalan[i - j])%m))%m;
        }
    }

    return chislaNaCatalan[zaChislo];
}

int main(){
    cin>>n>>m;

    int koeChisloNaCatalan = n / 2;

    int broiRakostiskaniq = sCycli(n);

    cout<<broiRakostiskaniq<<endl;

    return 0;
}
