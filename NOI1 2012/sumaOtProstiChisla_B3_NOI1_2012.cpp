#include<iostream>
#include<cmath>
using namespace std;

int koeChislo;

bool sastavno[11000];

void Eratosten(){
    int korenKvadraten = sqrt(koeChislo);
    for(int i = 2; i <= korenKvadraten; i++){
        if(sastavno[i] == false){
            for(int j = i * i; j <= koeChislo; j+=i){
                sastavno[j] = true;
            }
        }
    }
}

int main(){
    cin>>koeChislo;

    Eratosten();

    int broiPredstavqniq = 0;

    sastavno[0] = true;
    sastavno[1] = true;

    for(int i = 2; i <= koeChislo; i++){
        if(sastavno[i] == false && sastavno[koeChislo - i] == false){
            broiPredstavqniq++;
            sastavno[i] = true;
            sastavno[koeChislo - i] = true;
        }
    }

    cout<<broiPredstavqniq<<endl;

    return 0;
}
