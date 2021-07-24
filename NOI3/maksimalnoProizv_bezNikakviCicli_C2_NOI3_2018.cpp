#include<iostream>
using namespace std;

int n;
long long melo[250][250];

long long maxpro(long sboraKolkoDaE, long long otKolkoDaePMR){
    if(sboraKolkoDaE < 0 || otKolkoDaePMR < 0){
        return 0;
    }
    if(sboraKolkoDaE == 1 || sboraKolkoDaE == 0){
        return 1;
    }
    if(melo[sboraKolkoDaE][otKolkoDaePMR] > 0){
        return melo[sboraKolkoDaE][otKolkoDaePMR];
    }

    long long naiDobroto = max(maxpro(sboraKolkoDaE, otKolkoDaePMR-1),
                otKolkoDaePMR * maxpro(sboraKolkoDaE-otKolkoDaePMR, otKolkoDaePMR-1));

    melo[sboraKolkoDaE][otKolkoDaePMR] = naiDobroto;
    return naiDobroto;
}

int main(){
    cin>>n;

    long long maksPr = maxpro(n, n);
    cout<<maksPr<<endl;

    return 0;
}
