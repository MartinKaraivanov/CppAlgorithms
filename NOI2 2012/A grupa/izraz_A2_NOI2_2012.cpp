#include<iostream>
using namespace std;

int stoinostKolko;
int doKoeChislo;

long long priTolkova[100];

long long broiNachiniZaPoluchavane(int naKoeChislo){
    if(naKoeChislo == 0){
        return 1;
    }

    if(naKoeChislo == 1){
        return 0;
    }

    if(priTolkova[naKoeChislo] > -1){
        return priTolkova[naKoeChislo];
    }

    long long zaTuk = 0;

    long long doKade = min(naKoeChislo, doKoeChislo);

    for(long long i = 2; i <= doKade; i++){
        zaTuk += broiNachiniZaPoluchavane(naKoeChislo-i);
        if(naKoeChislo % i == 0){
            zaTuk += broiNachiniZaPoluchavane(naKoeChislo/i);
        }
    }

    priTolkova[naKoeChislo] = zaTuk;
    return zaTuk;
}

long long sCycli(long long zaKoeChislo){
    priTolkova[0] = 1;

    for(int naKoeChislo = 2; naKoeChislo <= zaKoeChislo; naKoeChislo++){
        long long zaTuk = 0;

        long long doKade = min(naKoeChislo, doKoeChislo);

        for(long long i = 2; i <= doKade; i++){
            zaTuk += priTolkova[naKoeChislo-i];
            if(naKoeChislo % i == 0){
                zaTuk += priTolkova[naKoeChislo/i];
            }
        }

        priTolkova[naKoeChislo] = zaTuk;
    }

    return priTolkova[zaKoeChislo];
}

int main(){
    cin>>stoinostKolko>>doKoeChislo;

    /*for(int i = 0; i <= stoinostKolko; i++){
        priTolkova[i] = -1;
    }

    long long kolkoNachina = broiNachiniZaPoluchavane(stoinostKolko);*/
    long long kolkoNachina = sCycli(stoinostKolko);

    cout<<kolkoNachina<<endl;

    return 0;
}
