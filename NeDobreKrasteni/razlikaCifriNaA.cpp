#include<iostream>
#include<cmath>
using namespace std;

int broiOtTaziCifra[10];
int broiCifriNaChislata;

int parvonachaloChilo[100];
int naiGolqmoChisloSTeziCifri[100];
int naiMalkoChisloSTeziCifri[100];
int chisloSledIzvazhdaneto[100];


void izvazhdane (){
    int prenos=0;
    for(int i=0;i<broiCifriNaChislata;i++){
        int razlika=(naiGolqmoChisloSTeziCifri[i]-prenos)-naiMalkoChisloSTeziCifri[i];
        if(razlika<0){
            prenos=1;
            chisloSledIzvazhdaneto[i]=10-abs(razlika);
        }else{
            prenos=0;
            chisloSledIzvazhdaneto[i]=razlika;
        }
    }

}

int main(){
    char cifra;

    while(cin>>cifra){
        parvonachaloChilo[broiCifriNaChislata]=cifra-'0';
        broiOtTaziCifra[cifra-'0']++;
        broiCifriNaChislata++;
    }

    int copieNabroiCifriNaChislata[10];
    for(int i=0;i<=9;i++){
        copieNabroiCifriNaChislata[i]=broiOtTaziCifra[i];
    }

    int broibroiCifriNaChislata=broiCifriNaChislata;
    for(int i=9;i>=0;i--){
        if(copieNabroiCifriNaChislata[i]>0){
            while(copieNabroiCifriNaChislata[i]>0){
                naiGolqmoChisloSTeziCifri[broibroiCifriNaChislata-1]=i;
                broibroiCifriNaChislata--;
                copieNabroiCifriNaChislata[i]--;
            }
        }
    }

     for(int i=0;i<=9;i++){
        copieNabroiCifriNaChislata[i]=broiOtTaziCifra[i];
    }

    broibroiCifriNaChislata=broiCifriNaChislata;
    for(int i=0;i<=9;i++){
        if(copieNabroiCifriNaChislata[i]>0){
            while(copieNabroiCifriNaChislata[i]>0){
                naiMalkoChisloSTeziCifri[broibroiCifriNaChislata-1]=i;
                broibroiCifriNaChislata--;
                copieNabroiCifriNaChislata[i]--;
            }
        }
    }

    /*if(naiMalkoChisloSTeziCifri[broiCifriNaChislata-1]==0){
        for(int i=broiCifriNaChislata-2;i>=0;i--){
            if(naiMalkoChisloSTeziCifri[i]>0){
                int kopieNaCifrinkata=naiMalkoChisloSTeziCifri[i];
                naiMalkoChisloSTeziCifri[i]=0;
                naiMalkoChisloSTeziCifri[broiCifriNaChislata-1]=kopieNaCifrinkata;
                break;
            }
        }
    }*/

    izvazhdane();

    for(int i=broiCifriNaChislata-1;i>=0;i--){
        cout<<chisloSledIzvazhdaneto[i];
    }

    cout<<endl;


    return 0;
}
