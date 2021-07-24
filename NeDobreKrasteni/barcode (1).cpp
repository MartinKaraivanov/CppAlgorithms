#include<iostream>
using namespace std;

int barcod[9000];
int obshtBroiCifriVBarcodovete;

int barkodove[1000];

int main(){
    char cifra;

    while(cin>>cifra){
        barcod[obshtBroiCifriVBarcodovete]=cifra-'0';
        obshtBroiCifriVBarcodovete++;
    }

    int broiBarcodove=obshtBroiCifriVBarcodovete/8;

    int chetiricifrenoChisloZaOpredelqeNaVidaNaShokolada[broiBarcodove];

    int broqch=0;

    for(int i=3;i<=obshtBroiCifriVBarcodovete;i+=8){
        chetiricifrenoChisloZaOpredelqeNaVidaNaShokolada[broqch]=1000*barcod[i]+100*barcod[i+1]+10*barcod[i+2]+barcod[i+3];
        broqch++;
    }

    int broiMlechni=0;
    int broiLeshnici=0;
    int broiStafidi=0;

    for(int i=0;i<broqch;i++){
        if(chetiricifrenoChisloZaOpredelqeNaVidaNaShokolada[i]%2==0){
            broiMlechni++;
        }else{
            if(chetiricifrenoChisloZaOpredelqeNaVidaNaShokolada[i]%3==0){
                broiLeshnici++;
            }else{
                broiStafidi++;
            }
        }
    }

    cout<<broiMlechni<<" "<<broiLeshnici<<" "<<broiStafidi<<endl;

    return 0;
}
