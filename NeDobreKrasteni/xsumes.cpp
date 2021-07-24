#include<iostream>
using namespace std;

const int maxChislo = 100000;
int kolkoPutiGoImaTovaChisloVRedicaEdno[maxChislo+1];

int main(){
int broiChislaVRedica;
    int sborytNakoitoDaErawno;
    cin>>broiChislaVRedica>>sborytNakoitoDaErawno;

    for(int i=0;i<broiChislaVRedica;i++){
        int chislo;
        cin>>chislo;
        kolkoPutiGoImaTovaChisloVRedicaEdno[chislo]++;
    }

    int brPati=0;
    for(int i=0;i<broiChislaVRedica;i++){
        int chislo;
        cin>>chislo;
        int chisloOtRedicaEdno=sborytNakoitoDaErawno-chislo;
        if((chisloOtRedicaEdno >= 0) && (chisloOtRedicaEdno <= maxChislo) && (kolkoPutiGoImaTovaChisloVRedicaEdno[chisloOtRedicaEdno]>0)){
            brPati+=kolkoPutiGoImaTovaChisloVRedicaEdno[chisloOtRedicaEdno];
        }
    }

    cout<<brPati;

    return 0;
}
