#include<iostream>
using namespace std;


int brCifriPredposledenChlen;
int predposledenChlen[1000];

int brCifriPosledenChlen;
int posledenChlen[1000];

int brCifriNovChlen;
int novChlen[1000];


void kopiraneNaPosledenVPredposleden(){
    for(int i=0;i<brCifriPosledenChlen;i++){
        predposledenChlen[i]=posledenChlen[i];
    }
    brCifriPredposledenChlen=brCifriPosledenChlen;
}

void kopiraneNaNovVPosleden(){
    for(int i=0;i<brCifriNovChlen;i++){
        posledenChlen[i]=novChlen[i];
    }
    brCifriPosledenChlen=brCifriNovChlen;
}

void sabiraneNaPredPosledeIPosledenVNov(){
    //nov = predposleden + posleden;
    long long prenos=0;
    brCifriNovChlen=0;
    for(int i=0;i<brCifriPosledenChlen;i++){
        int sbor = predposledenChlen[i]+posledenChlen[i]+prenos;
        novChlen[i]=sbor%10;
        prenos=sbor/10;
        brCifriNovChlen++;
    }
    while(prenos>0){
        brCifriNovChlen++;
        novChlen[brCifriNovChlen-1]=prenos%10;
        prenos/=10;
    }
}

int ostatakPriDeleneNaPosledenChlenNaDelitel(int delitel){
    //return posleden%delitel;
    int ostatak=0;

    for(int i=brCifriPosledenChlen-1;i>=0;i--){
        ostatak=ostatak*10+posledenChlen[i];
        ostatak=ostatak%delitel;
    }

    return ostatak;
}

int main(){
    long long koiChlen;
    long long naKolkoDaSeDeli;
    cin>>koiChlen>>naKolkoDaSeDeli;

    predposledenChlen[0] = 1;
    brCifriPredposledenChlen = 1;

    posledenChlen[0] = 1;
    brCifriPosledenChlen = 1;

    for(int i=3;i<=koiChlen;i++){
        sabiraneNaPredPosledeIPosledenVNov();
        kopiraneNaPosledenVPredposleden();
        kopiraneNaNovVPosleden();
    }

    cout<<ostatakPriDeleneNaPosledenChlenNaDelitel(naKolkoDaSeDeli);

    return 0;
}
