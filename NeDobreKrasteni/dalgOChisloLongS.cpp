#include<iostream>
#include<cmath>
using namespace std;

int broiCifri(int k){
    if(k==0){
        return 1;
    }

    int brCifri=0;
    while(k>0){
        brCifri++;
        k/=10;
    }

    return brCifri;
}

int ostatakPriDelenieNa10naNtaNaK(int n, int k){
    int ostatak=1;

    for(int i=0;i<n;i++){
        ostatak=ostatak*10+0;
        ostatak=ostatak%k;
    }

    return ostatak;
}

int main(){
    long long kolkoCifreno;
    long long naKOlkoDaEkratno;
    cin>>kolkoCifreno>>naKOlkoDaEkratno;


    if(kolkoCifreno<=8){
        long long krugloChislo = pow(10,kolkoCifreno-1);
        long long ostatak = krugloChislo % naKOlkoDaEkratno;
        long long zaPribavqne = naKOlkoDaEkratno-ostatak;

        if(ostatak==0){
            zaPribavqne=0;
        }

        long long rezultat = krugloChislo + zaPribavqne;
        cout<<rezultat;

        /*for(int i=pow(10,kolkoCifreno-1);i<pow(10,kolkoCifreno);i++ ){
        if(i%naKOlkoDaEkratno==0){
            cout<<i;
            break;
        }*/


    }else{

        long long ostatak = ostatakPriDelenieNa10naNtaNaK(kolkoCifreno-1,naKOlkoDaEkratno);

        long long zaPribavqne = naKOlkoDaEkratno-ostatak;

        if(ostatak==0){
            zaPribavqne=0;
        }

        long long kolkoNuli = kolkoCifreno-1-broiCifri(zaPribavqne);

        cout<<1;

        for(int i=0;i<kolkoNuli;i++){
            cout<<0;
        }

        cout<<zaPribavqne;
    }

    return 0;
}
