#include<iostream>
using namespace std;

int broiVidoveKonteineri;
int vmestimostNaVidoveKonteineri[120];
int minBrKonteinteriZaKilogrami[20000];

void zapalvane(){
    for(int i=0;i<=20000;i++){
        minBrKonteinteriZaKilogrami[i]=-1;
    }
}

int MinimalenBroiKonteineri(int kilogramiBagaj){
    if(kilogramiBagaj==0){
        return 0;
    }

    if(minBrKonteinteriZaKilogrami[kilogramiBagaj]!=-1){
        return minBrKonteinteriZaKilogrami[kilogramiBagaj];
    }

    int minBr=36000;

    for(int izbranKonteiner=0;izbranKonteiner<broiVidoveKonteineri;izbranKonteiner++){
        if(vmestimostNaVidoveKonteineri[izbranKonteiner]<=kilogramiBagaj){
            int ostanaloKolichestvo=kilogramiBagaj-vmestimostNaVidoveKonteineri[izbranKonteiner];
            int tekushtMinBr = 1+MinimalenBroiKonteineri(ostanaloKolichestvo);
            if(tekushtMinBr<minBr){
                minBr=tekushtMinBr;
            }
        }
    }

    minBrKonteinteriZaKilogrami[kilogramiBagaj]=minBr;
    return minBr;
}

int main(){
    zapalvane();
    int kilogrami;

    cin>>kilogrami;
    cin>>broiVidoveKonteineri;

    for(int i=0;i<broiVidoveKonteineri;i++){
        cin>>vmestimostNaVidoveKonteineri[i];
    }

    int minBroiKonteineri=MinimalenBroiKonteineri(kilogrami);

    cout<<minBroiKonteineri<<endl;

    return 0;
}
