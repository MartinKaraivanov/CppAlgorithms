#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int broiRedove;
char dumi[65][35];
int dalzhinaNaDumi[65];
int broiDumi;

void pribavqneNaSimvola(char novSimvol){
    dumi[broiDumi][dalzhinaNaDumi[broiDumi]]=novSimvol;
    dalzhinaNaDumi[broiDumi]++;
}

string prerabotenRed(string redove, int nomerNaRed){
    for(int g=0;g<65;g++){
        for(int h=0;h<35;h++){
            dumi[g][h]=0;
        }
        dalzhinaNaDumi[g]=0;
    }
    broiDumi=0;

    int broiNeIntervali=0;
    bool vDumaLiSum=false;
    for(int i=0;i<redove.size();i++){
        if((redove[i]!=' ') && (vDumaLiSum==false)){
            vDumaLiSum=true;
            pribavqneNaSimvola(redove[i]);
        }else{
            if((redove[i]!=' ') && (vDumaLiSum==true)){
                pribavqneNaSimvola(redove[i]);
            }
        }
        if((redove[i]==' ') && (vDumaLiSum==true)){
            vDumaLiSum=false;
            broiDumi++;
        }
        if(redove[i]!=' '){
            broiNeIntervali++;
        }
    }

    int broiNuzhniIntervali=60-broiNeIntervali;
    int broiMestaZaPostavqne=broiDumi-1;
    int poziciiZaSlagane[broiMestaZaPostavqne];

    if(broiNuzhniIntervali%broiMestaZaPostavqne==0){
        int m=0;
        int zaPribavqne=broiNuzhniIntervali/broiMestaZaPostavqne;
        while(broiNuzhniIntervali>0){
            poziciiZaSlagane[m]=zaPribavqne;
            m++;
            broiNuzhniIntervali-=zaPribavqne;
            broiMestaZaPostavqne--;
        }
    }else{
        int m=0;
        int zaPribavqne=broiNuzhniIntervali/broiMestaZaPostavqne+1;
        while(broiNuzhniIntervali%broiMestaZaPostavqne!=0){
            poziciiZaSlagane[m]=zaPribavqne;
            m++;
            broiNuzhniIntervali-=zaPribavqne;
            broiMestaZaPostavqne--;
        }
        zaPribavqne=broiNuzhniIntervali/broiMestaZaPostavqne;
        while(broiNuzhniIntervali>0){
            poziciiZaSlagane[m]=zaPribavqne;
            m++;
            broiNuzhniIntervali-=zaPribavqne;
            broiMestaZaPostavqne--;
        }
    }

    string zaVrashtane;

    if(nomerNaRed<broiRedove-1){
        for(int j=0;j<broiDumi-1;j++){
            zaVrashtane+=dumi[j];
            for(int k=0;k<poziciiZaSlagane[j];k++){
                zaVrashtane+=' ';
            }
        }
        zaVrashtane+=dumi[broiDumi-1];
    }else{
        for(int j=0;j<broiDumi-1;j++){
            zaVrashtane+=dumi[j];
            zaVrashtane+=' ';
        }
        zaVrashtane+=dumi[broiDumi-1];
    }

    return zaVrashtane;
}

int main(){
    cin>>broiRedove;

    string konecZaUnishtozhavane;

    getline(cin, konecZaUnishtozhavane);

    string otgovori[500];

    for(int kp=0;kp<broiRedove;kp++){
        string redove;

        getline(cin, redove);

        redove+=' ';

        string novRed=prerabotenRed(redove, kp);

        otgovori[kp]=novRed;
    }

    for(int i=0;i<broiRedove;i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
