#include<iostream>
using namespace std;

int kolkoPatiImameCifrata[10];

int main(){
    char cifrichka;

    int naiMalkaCifrichkaRazlOtNula = 10;

    while(cin>>cifrichka){
        int cifr = cifrichka - '0';
        kolkoPatiImameCifrata[cifr]++;

        if(cifr != 0 && cifr < naiMalkaCifrichkaRazlOtNula){
            naiMalkaCifrichkaRazlOtNula = cifr;
        }

    }

    unsigned long long naiMalkoChislo = naiMalkaCifrichkaRazlOtNula;
    kolkoPatiImameCifrata[naiMalkaCifrichkaRazlOtNula]--;

    for(int i = 0; i <10; i++){
        for(int j = 0; j < kolkoPatiImameCifrata[i]; j++){
            //cout<<i<<endl;
            naiMalkoChislo = 10*naiMalkoChislo + i;
        }
    }

    //cout<<"-----------"<<endl;

    kolkoPatiImameCifrata[naiMalkaCifrichkaRazlOtNula]++;

    unsigned long long naiGolqmoChislo = 0;

    //cout<<naiGolqmoChislo<<endl;

    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < kolkoPatiImameCifrata[i]; j++){
            //cout<<i<<endl;
            naiGolqmoChislo = 10*naiGolqmoChislo + i;
        }
    }

    cout<<naiGolqmoChislo + naiMalkoChislo<<endl;


    return 0;
}
