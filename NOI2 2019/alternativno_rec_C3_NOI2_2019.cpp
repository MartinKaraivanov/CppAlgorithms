#include<iostream>
using namespace std;

int promqnaS;
int otKolkoPoMalko;
int broiChisla;

long long priTolkova[70][70];

long long broiRedici(int brChis, long long chislo){
    if(chislo < 1){
        return 0;
    }
    if(chislo >= otKolkoPoMalko){
        return 0;
    }

    if(brChis == 0){
        return 1;
    }

    if(priTolkova[brChis][chislo] > -1){
        return priTolkova[brChis][chislo];
    }

    long long naiDobro = 0;

    naiDobro += broiRedici(brChis - 1, chislo + promqnaS);
    naiDobro += broiRedici(brChis - 1, chislo - promqnaS);

    priTolkova[brChis][chislo] = naiDobro;
    return naiDobro;
}

int main(){
    cin>>promqnaS>>otKolkoPoMalko>>broiChisla;

    long long brRedichki = 0;

    for(int i = 0; i < 70; i++){
        for(int j = 0; j < 70; j++){
            priTolkova[i][j] = -1;
        }
    }

    for(int i = 1; i < otKolkoPoMalko; i++){
        brRedichki += broiRedici(broiChisla - 1, i);
        //cout<<brRedichki<<endl;
    }

    cout<<brRedichki;

    return 0;
}
