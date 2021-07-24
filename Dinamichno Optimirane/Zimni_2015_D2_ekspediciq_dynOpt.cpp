#include<iostream>
using namespace std;

int broiVidoveKonteineri;
int vmestimostNaVidoveKonteineri[120];
int minBrKonteinteriZaKilogrami[20000];

void PopalniMinimalenBroiKonteineri(int maxKilogramiBagaj){
    minBrKonteinteriZaKilogrami[0] = 0;

    for (int kilogramiBagaj = 1; kilogramiBagaj <= maxKilogramiBagaj; kilogramiBagaj++){
        int minBr=36000;

        for(int izbranKonteiner=0;izbranKonteiner<broiVidoveKonteineri;izbranKonteiner++){
            if(vmestimostNaVidoveKonteineri[izbranKonteiner]<=kilogramiBagaj){
                int ostanaloKolichestvo=kilogramiBagaj-vmestimostNaVidoveKonteineri[izbranKonteiner];
                int tekushtMinBr = 1+minBrKonteinteriZaKilogrami[ostanaloKolichestvo];
                if(tekushtMinBr<minBr){
                    minBr=tekushtMinBr;
                }
            }
        }

        minBrKonteinteriZaKilogrami[kilogramiBagaj]=minBr;
    }
}

int main(){
    int kilogrami;

    cin>>kilogrami;
    cin>>broiVidoveKonteineri;

    for(int i=0;i<broiVidoveKonteineri;i++){
        cin>>vmestimostNaVidoveKonteineri[i];
    }

    PopalniMinimalenBroiKonteineri(kilogrami);
    int minBroiKonteineri = minBrKonteinteriZaKilogrami[kilogrami];

    cout<<minBroiKonteineri<<endl;

    return 0;
}
