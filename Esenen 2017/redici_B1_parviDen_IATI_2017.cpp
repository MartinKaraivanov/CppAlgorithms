#include<iostream>
using namespace std;

int dalzhinaNaRedicata;
int doKoeChisloSadarzha;
int naiMnogoKolkoPati;

long long priTolkova[35][35][35];

long long broiRedici(int poziciqOtRedicata, int otKakvoChisloIdvame, int kolkoPutiGoEImalo){
    if(poziciqOtRedicata == 0){
        return 1;
    }

    if(priTolkova[poziciqOtRedicata][otKakvoChisloIdvame][kolkoPutiGoEImalo] > -1){
        return priTolkova[poziciqOtRedicata][otKakvoChisloIdvame][kolkoPutiGoEImalo];
    }

    long long zaTuk = 0;

    if(kolkoPutiGoEImalo < naiMnogoKolkoPati){
        zaTuk += broiRedici(poziciqOtRedicata - 1, otKakvoChisloIdvame, kolkoPutiGoEImalo + 1);
    }

    for(int i = 1; i < otKakvoChisloIdvame; i++){
        zaTuk += broiRedici(poziciqOtRedicata - 1, i, 1);
    }

    priTolkova[poziciqOtRedicata][otKakvoChisloIdvame][kolkoPutiGoEImalo] = zaTuk;
    return zaTuk;
}

int main(){
    cin>>dalzhinaNaRedicata>>doKoeChisloSadarzha>>naiMnogoKolkoPati;

    for(int i = 0; i <= dalzhinaNaRedicata; i++){
        for(int k = 0; k <= doKoeChisloSadarzha; k++){
            for(int j = 0; j <= naiMnogoKolkoPati; j++){
                priTolkova[i][k][j] = -1;
            }
        }
    }

    long long broiDobriRedici = 0;

    for(int i = 1; i <= doKoeChisloSadarzha; i++){
        broiDobriRedici += broiRedici(dalzhinaNaRedicata - 1, i, 1);
    }

    cout<<broiDobriRedici<<endl;

    return 0;
}
