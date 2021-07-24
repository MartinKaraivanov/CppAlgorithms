#include<iostream>
using namespace std;

int n;
int melo[250][250];

long long maxpro(int sboraKolkoDaE, int otKolkoDaePMR){
    if(sboraKolkoDaE == 1 || sboraKolkoDaE == 0){
        return 1;
    }
    if(melo[sboraKolkoDaE][otKolkoDaePMR] > 0){
        return melo[sboraKolkoDaE][otKolkoDaePMR];
    }

    long long naiDobroto = 0;

    for(int i = 1; i <= otKolkoDaePMR; i++){
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

int main(){
    cin>>n;

    long long maksPr = maxpro(n, n);
    cout<<maksPr<<endl;

    return 0;
}
