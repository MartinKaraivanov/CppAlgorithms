#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int broi;
    cin>>broi;
    char lubimec[broi][30];

    for(int i=0;i<broi;i++){
        cin>>lubimec[i];
    }

    string naKakvoPrilicha[broi];

    for(int i=0;i<broi;i++){
        int broiA=0;
        int broiG=0;
        int broiT=0;
        int broiP=0;
        int broiC=0;
        int broiI=0;

        for(int j=0;j<strlen(lubimec[i]);j++){
            char bukva=lubimec[i][j];
            if(bukva=='A'){
                broiA++;
            }else{
                if(bukva=='I'){
                    broiI++;
                }else{
                    if(bukva=='C'){
                        broiC++;
                    }else{
                        if(bukva=='T'){
                            broiT++;
                        }else{
                            if(bukva=='G'){
                                broiG++;
                            }else{
                                if(bukva=='P'){
                                    broiP++;
                                }
                            }
                        }
                    }
                }
            }
        }
        int sborCat=broiA+broiT+broiC;
        int sborGpi=broiG+broiI+broiP;

        if(sborCat==sborGpi){
            naKakvoPrilicha[i]="CAT-GPI";
        }else{
            if(sborCat>sborGpi){
                naKakvoPrilicha[i]="CAT";
            }else{
                if(sborGpi>sborCat){
                    naKakvoPrilicha[i]="GPI";
                }
            }
        }

        if((sborCat==0) && (sborGpi==0)){
            naKakvoPrilicha[i]="UFO";
        }

    }

    for(int i=0;i<broi;i++){
        cout<<naKakvoPrilicha[i]<<endl;
    }

    return 0;
}
