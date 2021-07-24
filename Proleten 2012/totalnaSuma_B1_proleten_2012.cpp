#include<iostream>
#include<cmath>
using namespace std;

int cifriNaChisloto[12];
int broiCifri;

long long priTolkova[20];

long long sborKoitoMozhemDaPoluchim(int broiCifriZaPolzvane){
    if(broiCifriZaPolzvane == 1){
        return cifriNaChisloto[1];
    }

    if(priTolkova[broiCifriZaPolzvane] > -1){
        return priTolkova[broiCifriZaPolzvane];
    }

    long long akoQVzema = (1 << (broiCifriZaPolzvane - 1)) * (cifriNaChisloto[broiCifriZaPolzvane]) +
        10 * sborKoitoMozhemDaPoluchim(broiCifriZaPolzvane - 1);
    long long akoNeQVzema = sborKoitoMozhemDaPoluchim(broiCifriZaPolzvane - 1);

    long long zaTuk = akoQVzema+akoNeQVzema;

    priTolkova[broiCifriZaPolzvane] = zaTuk;
    return zaTuk;
}

long long sCycli(int zaBroiCifri){
    long long priT;
    priT = cifriNaChisloto[1];

    for(int broiCifriZaPolzvane = 2; broiCifriZaPolzvane <= zaBroiCifri; broiCifriZaPolzvane++){
        long long akoQVzema =
            (1 << (broiCifriZaPolzvane - 1)) * (cifriNaChisloto[broiCifriZaPolzvane]) + 10 * priT;

        long long akoNeQVzema = priT;

        long long zaTuk = akoQVzema+akoNeQVzema;

        priT = zaTuk;
    }

    return priT;
}

int main(){
    char cifra;

    while(cin>>cifra){
        broiCifri++;
        cifriNaChisloto[broiCifri] = cifra - '0';
    }

    /*for(int i = 0; i <= broiCifri; i++){
        priTolkova[i] = -1;
    }*/

    long long sumaKoqtoMozhemDaPoluchim = sCycli(broiCifri);

    cout<<sumaKoqtoMozhemDaPoluchim<<endl;

    return 0;
}
