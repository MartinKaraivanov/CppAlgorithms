#include<iostream>
using namespace std;

const int mnogo = 100000000;

int broiChisla;
int kolkoVzimame;

int chisla[860];

int priTolkova[860][860];
bool imameLiPriTolkova[860][860];

int optimalenPoslElement[860][860][24];
bool imameLiOptimalenPE[860][860][24];

int naiDobroVPodredicata(int otKade, int doKade);
int izchisliOptimalenPE(int otKade, int doKade, int kolkoPodredica);

int naiDobroVPodredicata(int otKade, int doKade){
    if(doKade - otKade + 1 < kolkoVzimame){
        return 0;
    }

    if(imameLiPriTolkova[otKade][doKade]){
        return priTolkova[otKade][doKade];
    }

    int zaTuka = izchisliOptimalenPE(otKade, doKade, kolkoVzimame - 2) - chisla[otKade]*chisla[doKade];

    priTolkova[otKade][doKade] = zaTuka;
    imameLiPriTolkova[otKade][doKade] = true;

    return zaTuka;
}


int izchisliOptimalenPE(int otKade, int doKade, int kolkoPodredica){
    if(kolkoPodredica == 0){
        return naiDobroVPodredicata(otKade,doKade);
    }

    if(imameLiOptimalenPE[otKade][doKade][kolkoPodredica] == true){
        return optimalenPoslElement[otKade][doKade][kolkoPodredica];
    }

    int zaTuka = -mnogo;

    for(int i = otKade + 1; i < doKade; i += kolkoVzimame){
        int tekushto = naiDobroVPodredicata(otKade, i) + izchisliOptimalenPE(i, doKade, kolkoPodredica - 1) + chisla[i];

        zaTuka = max(zaTuka, tekushto);
    }

    optimalenPoslElement[otKade][doKade][kolkoPodredica] = zaTuka;
    imameLiOptimalenPE[otKade][doKade][kolkoPodredica] = true;

    return zaTuka;
}

int main(){

    cin>>broiChisla>>kolkoVzimame;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    int otgovor = naiDobroVPodredicata(1, broiChisla);

    cout<<otgovor<<endl;

    return 0;
}
