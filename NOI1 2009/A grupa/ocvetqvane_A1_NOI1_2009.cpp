#include<iostream>
using namespace std;

int naiMalakX = 500001;
int naiGolqmX = 0;

int broiIntervaliPreocvetqvane;

int tukaKakuvCvqtE[500010];

int tukaKolkoZapochvat[500010];
int tukaKolkOSvurshvat[500010];

int main(){
    cin>>broiIntervaliPreocvetqvane;

    for(int i = 0; i < broiIntervaliPreocvetqvane; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        tukaKolkoZapochvat[otKade]++;
        tukaKolkOSvurshvat[doKade]++;

        naiMalakX = min(naiMalakX, otKade);
        naiGolqmX = max(naiGolqmX, doKade);
    }

    int broiaktivniIntervali = 0;

    for(int i = naiMalakX; i <= naiGolqmX; i++){
        broiaktivniIntervali += tukaKolkoZapochvat[i];

        tukaKakuvCvqtE[i] = broiaktivniIntervali%2;

        broiaktivniIntervali -= tukaKolkOSvurshvat[i];
    }

    int naiGolqmBroiPoredni = 0;

    int broiPoredniTakiva = 0;

    for(int i = naiMalakX; i <= naiGolqmX; i++){
        if(tukaKakuvCvqtE[i] == 1){
            broiPoredniTakiva++;
        }else{
            broiPoredniTakiva = 0;
        }
        naiGolqmBroiPoredni = max(naiGolqmBroiPoredni, broiPoredniTakiva);
    }

    cout<<naiGolqmBroiPoredni<<endl;

    return 0;
}
