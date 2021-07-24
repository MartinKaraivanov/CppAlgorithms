#include<iostream>
using namespace std;

int kakuvSbor;
long long otKolkoPoMalko;

long long brRedichkiPriTolkova[280][280];

long long broiRedichki(long long sborche, int naiGolqmoChislo){
    if(sborche == 0){
        return 1;
    }

    if(sborche < 0){
        return 0;
    }

    if(naiGolqmoChislo <= 0){
        return 0;
    }

    if(brRedichkiPriTolkova[sborche][naiGolqmoChislo] > 0){
        return brRedichkiPriTolkova[sborche][naiGolqmoChislo];
    }

    long long vazmozhenBroiRedichki = 0;

    for(int kolkoPati = 0; kolkoPati < sborche/naiGolqmoChislo + 1; kolkoPati++){
        vazmozhenBroiRedichki += broiRedichki(sborche - kolkoPati*naiGolqmoChislo, naiGolqmoChislo - 1);
    }

    brRedichkiPriTolkova[sborche][naiGolqmoChislo] = vazmozhenBroiRedichki;

    return vazmozhenBroiRedichki;
}

int main(){
    cin>>kakuvSbor>>otKolkoPoMalko;

    long long brRedichki = broiRedichki(kakuvSbor, otKolkoPoMalko);

    cout<<brRedichki<<endl;

    return 0;
}
