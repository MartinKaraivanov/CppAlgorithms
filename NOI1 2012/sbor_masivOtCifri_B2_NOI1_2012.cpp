#include<iostream>
#include<vector>
using namespace std;

int kolkoPatiImameCifrata[10];

vector<int> naiMalkotochislo;
vector<int> naiGolqmotoChislo;

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

    kolkoPatiImameCifrata[naiMalkaCifrichkaRazlOtNula]--;

    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < kolkoPatiImameCifrata[i]; j++){
            naiMalkotochislo.push_back(i);
        }
    }

    naiMalkotochislo.push_back(naiMalkaCifrichkaRazlOtNula);

    kolkoPatiImameCifrata[naiMalkaCifrichkaRazlOtNula]++;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < kolkoPatiImameCifrata[i]; j++){
            naiGolqmotoChislo.push_back(i);
        }
    }

    vector<int> otgovor;

    int ostatak = 0;
    for(unsigned int i = 0; i < naiMalkotochislo.size() && i < naiGolqmotoChislo.size(); i++){
        int novaCifra = (naiMalkotochislo[i] + naiGolqmotoChislo[i] + ostatak)%10;
        otgovor.push_back(novaCifra);
        int novOstatak = 0;
        for(int j = 10; j <= naiMalkotochislo[i] + naiGolqmotoChislo[i] + ostatak; j+=10){
            novOstatak++;
        }
        ostatak = novOstatak;
    }

    if(ostatak > 0){
        otgovor.push_back(ostatak);
    }

    for(int i = otgovor.size() - 1; i >= 0; i--){
        cout<<otgovor[i];
    }

    cout<<endl;

    return 0;
}
