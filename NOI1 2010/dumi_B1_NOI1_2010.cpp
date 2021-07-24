#include<iostream>
#include<cmath>
using namespace std;

int broiDumi;
string dumi[110];

int kolkoStruvaTaziDuma(string duma){
    int cenichka = 0;

    for(unsigned int i = 0; i < duma.size(); i++){
        cenichka += (pow(2, i) * (toupper(duma[i]) - 64));
    }

    return cenichka;
}

int main(){
    cin>>broiDumi;

    for(int i = 0; i < broiDumi; i++){
        cin>>dumi[i];
    }

    int naiGolqmaCena = 0;
    int indexNaNaiGolqmaCena = -1;

    for(int i = 0; i < broiDumi; i++){
        int cenaNaTaziDuma = kolkoStruvaTaziDuma(dumi[i]);

        if(cenaNaTaziDuma > naiGolqmaCena){
            naiGolqmaCena = cenaNaTaziDuma;
            indexNaNaiGolqmaCena = i;
        }
    }

    cout<<dumi[indexNaNaiGolqmaCena]<<endl;

    return 0;
}
