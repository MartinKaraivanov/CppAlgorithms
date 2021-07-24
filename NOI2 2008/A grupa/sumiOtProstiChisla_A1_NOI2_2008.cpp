#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int koeChislo;
int p;

bool sastavnoLiE[51010];

vector<int> prostiChisla;

void eratosten(){
    int doKade = koeChislo + 100;

    int korenKvadraten = sqrt(doKade);

    for(int i = 2; i <= korenKvadraten; i++){
        if(sastavnoLiE[i] == false){
            for(int j = i*i; j <= doKade; j += i){
                sastavnoLiE[j] = true;
            }
        }
    }
}

void namiraneNaProstiteChislaIP(){
    for(int j = koeChislo + 1; true; j++){
        if(sastavnoLiE[j] == false){
            p = j;
            break;
        }
    }

    for(int i = 2; i <= koeChislo; i++){
        if(sastavnoLiE[i] == false){
            prostiChisla.push_back(i);
        }
    }
}

int priTolkovaEdin[51000];

int sCycliEdinParam(int zaChislo){
    priTolkovaEdin[0] = 1;

    for(unsigned int i = 0; i < prostiChisla.size(); i++){
        int prostoChislo = prostiChisla[i];
        priTolkovaEdin[prostoChislo] = (priTolkovaEdin[prostoChislo] + 1)%p;
        for(int chislo = prostoChislo + 1; chislo <= zaChislo; chislo++){
            priTolkovaEdin[chislo] = (priTolkovaEdin[chislo] + priTolkovaEdin[chislo - prostoChislo])%p;
        }
    }

    return priTolkovaEdin[zaChislo];
}

int main(){
    cin>>koeChislo;

    eratosten();
    namiraneNaProstiteChislaIP();

    int kolkoSumiIma = sCycliEdinParam(koeChislo);

    if(sastavnoLiE[koeChislo] == false){
        kolkoSumiIma--;
    }

    if(kolkoSumiIma < 0){
        kolkoSumiIma = p + kolkoSumiIma;
    }

    cout<<kolkoSumiIma<<endl;

    return 0;
}
