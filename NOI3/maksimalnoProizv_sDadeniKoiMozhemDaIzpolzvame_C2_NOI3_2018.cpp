#include<iostream>
#include<algorithm>
using namespace std;

int n;
int broiChisla;
int chisla[250];
int melo[250][250];

long long maxpro(int sboraKolkoDaE, int otKolkoDaePMR){
    if(sboraKolkoDaE == 1 || sboraKolkoDaE == 0){
        return 1;
    }
    if(melo[sboraKolkoDaE][otKolkoDaePMR] > 0){
        return melo[sboraKolkoDaE][otKolkoDaePMR];
    }

    long long naiDobroto = 0;

    for(int k = 0; k < broiChisla; k++){
        int i = chisla[k];
        if(i > otKolkoDaePMR){
            break;
        }
        if(sboraKolkoDaE - i >= 0 && otKolkoDaePMR - 1 >= 0){
            long long potencialnoNaiDobro = i * maxpro(sboraKolkoDaE - i, min(i - 1, sboraKolkoDaE - i));
            if(potencialnoNaiDobro > naiDobroto){
                naiDobroto = potencialnoNaiDobro;
            }
        }
    }

    melo[sboraKolkoDaE][otKolkoDaePMR] = naiDobroto;
    return naiDobroto;
}

bool poMalkoLie(int a, int b){
    return a < b;
}

int main(){
    cin>>n>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    sort(chisla, chisla + broiChisla, poMalkoLie);

    long long maksPr = maxpro(n, n);
    cout<<maksPr<<endl;

    return 0;
}
