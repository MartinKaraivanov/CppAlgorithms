#include<iostream>
using namespace std;

int naKoqStepen;

int priTolkova[50000];

int minimalenBroiStapki(int daSmetnemStepen){
    if(daSmetnemStepen == 1){
        return 0;
    }

    if(priTolkova[daSmetnemStepen] > 0){
        return priTolkova[daSmetnemStepen];
    }

    int minBroi = minimalenBroiStapki(daSmetnemStepen - 1) + 1;

    for(int i = 2; i <= daSmetnemStepen/2; i++){
        if(daSmetnemStepen % i == 0){
            int kolkoPati = daSmetnemStepen/i;
            int segashno = minimalenBroiStapki(i) + minimalenBroiStapki(kolkoPati);

            minBroi = min(minBroi, segashno);
        }
    }

    priTolkova[daSmetnemStepen] = minBroi;
    return minBroi;
}

int main(){
    cin>>naKoqStepen;

    int zaKolkoStapkiShteUspeem = minimalenBroiStapki(naKoqStepen);

    cout<<zaKolkoStapkiShteUspeem<<endl;

    return 0;
}
