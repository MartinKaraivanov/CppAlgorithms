#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaOtgovora{
    long long nomerNaRoditel;
    long long nomerNaLqvoDete;
    long long nomerNaDqsnoDete;
};

long long koiNomer;

long long koeEChisloto(long long otKade, long long doKade, long long koeChislo){
    return otKade + (koeChislo/2)*1 + (koeChislo%2)*((doKade - otKade + 1)/2);
}

long long naKoqPoziciqEChisloto(long long otKade, long long doKade, long long koeChislo){
    koeChislo -= otKade;

    long long naKoqPoziciqE = -1;

    if(koeChislo < (doKade - otKade + 1)/2){
        naKoqPoziciqE = koeChislo * 2;
    }else{
        koeChislo -= (doKade - otKade + 1)/2;
        naKoqPoziciqE = koeChislo*2 + 1;
    }

    return naKoqPoziciqE;
}

long long pow2(long long naKoqStepen){
    return (long long)1 << naKoqStepen;
}

DanniZaOtgovora otgovor(){
    long long naKoiRedE = 1;
    long long naKoqPoziciqVReda = 0;

    for(long long i = 1; true; i *= 2){
        if(koiNomer >= i-1 && koiNomer < i*2 - 1){
            break;
        }
        naKoiRedE++;
    }

    long long nachalnoNaReda = pow2(naKoiRedE - 1) - 1;
    long long krainoNaReda = pow2(naKoiRedE) - 2;

    naKoqPoziciqVReda = naKoqPoziciqEChisloto(nachalnoNaReda, krainoNaReda, koiNomer);

    //cout<<naKoiRedE<<" "<<naKoqPoziciqVReda<<endl;

    long long nachalenNaRedaNaRoditelq = pow2(naKoiRedE - 2) - 1;
    long long kraenNaRedaNaRoditelq = pow2(naKoiRedE - 1) - 2;
    long long roditelqKoiSiEVReda = naKoqPoziciqVReda/2;

    long long nachalenNaRedaNaDecata = pow2(naKoiRedE) - 1;
    long long kraenNaRedaNaDecata = pow2(naKoiRedE + 1) - 2;
    long long lqvotoDeteNaKoqPoziciqSiEVreda = naKoqPoziciqVReda*2;

    //cout<<nachalenNaRedaNaRoditelq<<" "<<roditelqKoiSiEVReda<<endl;
    //cout<<nachalenNaRedaNaDecata<<" "<<lqvotoDeteNaKoqPoziciqSiEVreda<<endl;

    long long koiERoditelq = koeEChisloto(nachalenNaRedaNaRoditelq, kraenNaRedaNaRoditelq, roditelqKoiSiEVReda);
    long long koiELqqvotoDete = koeEChisloto(nachalenNaRedaNaDecata, kraenNaRedaNaDecata, lqvotoDeteNaKoqPoziciqSiEVreda);
    long long koiEDqsnotoDete = koeEChisloto(nachalenNaRedaNaDecata, kraenNaRedaNaDecata, lqvotoDeteNaKoqPoziciqSiEVreda + 1);

    return {koiERoditelq, koiELqqvotoDete, koiEDqsnotoDete};
}

int main(){
    cin>>koiNomer;

    DanniZaOtgovora kakvoE = otgovor();

    cout<<kakvoE.nomerNaRoditel<<endl;
    cout<<kakvoE.nomerNaLqvoDete<<" "<<kakvoE.nomerNaDqsnoDete<<endl;

    return 0;
}
