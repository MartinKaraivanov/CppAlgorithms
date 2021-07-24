#include<iostream>
#include<algorithm>
using namespace std;

int broeveBalniOtCviat[25001];

int main(){
    int broiObshtoBaloni;
    int broiZaPodarqvane;
    cin>>broiObshtoBaloni>>broiZaPodarqvane;

    int baloni[broiObshtoBaloni];
    for(int i=0; i<broiObshtoBaloni; i++){
        cin>>baloni[i];
    }

    for(int i=0; i<broiObshtoBaloni; i++){
        broeveBalniOtCviat[baloni[i]]++;
    }

    int brRazlichniCvetove=0;
    for(int cviat=0;cviat<25001;cviat++){
        if(broeveBalniOtCviat[cviat] != 0){
            brRazlichniCvetove++;
        }
    }


    int brZaVzemaneOshte = broiZaPodarqvane;
    int brPovtariashtiZaVzemaneOshte = max(broiZaPodarqvane - brRazlichniCvetove, 0);
    for(int cviat=0; (cviat<25001)&&(brZaVzemaneOshte>0); cviat++){
        if(broeveBalniOtCviat[cviat] > 0){
            int broiPovtariashtiVzemameOtToziCviat = min(brPovtariashtiZaVzemaneOshte, broeveBalniOtCviat[cviat]-1);
            int broiVzemameOtToziCviat = 1 + broiPovtariashtiVzemameOtToziCviat;

            for (int j=1; j<=broiVzemameOtToziCviat; j++){
                cout<<cviat<<" ";
            }

            brZaVzemaneOshte = brZaVzemaneOshte - broiVzemameOtToziCviat;
            brPovtariashtiZaVzemaneOshte = brPovtariashtiZaVzemaneOshte - broiPovtariashtiVzemameOtToziCviat;
        }
    }

    return 0;
}
