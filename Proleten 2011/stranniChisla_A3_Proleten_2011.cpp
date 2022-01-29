#include<iostream>
#include<algorithm>
using namespace std;

const unsigned long long mnogo = 999999999;

long long broiCifriNa(unsigned long long chi){

    long long br = 0;

    while(chi > 0){
        br++;
        chi /= 10;
    }

    return br;
}

long long desetNaStepen(int stepen){
    long long resultat = 1;

    for(int i = 1; i <= stepen; i++){
        resultat *= 10;
    }

    return resultat;
}

int main(){

    for(unsigned long long chislo = 1; chislo <= mnogo; chislo++){

        unsigned long long kvadrat = chislo*chislo;

        int broiCifri = broiCifriNa(kvadrat);

        if(broiCifri%2 == 1){
            continue;
        }

        long long copieNaChi = kvadrat;

        string chisloto;

        while(copieNaChi > 0){
            char cifrata = copieNaChi%10 + '0';
            chisloto += cifrata;
            copieNaChi /= 10;
        }

        reverse(chisloto.begin(), chisloto.end());

        long long parvaChast = 0;

        for(int j = 0; j < broiCifri/2; j++){
            int cifra = chisloto[j] - '0';
            parvaChast = 10*parvaChast + cifra;
        }

        long long vtoraChast = 0;

        for(int j = broiCifri/2; j < broiCifri; j++){
            int cifra = chisloto[j] - '0';
            vtoraChast = 10*vtoraChast + cifra;
        }

        long long sbor = parvaChast + vtoraChast;

        if(sbor*sbor == kvadrat){
            cout<<kvadrat<<endl;
        }

    }

    return 0;
}
