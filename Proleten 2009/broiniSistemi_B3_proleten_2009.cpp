#include<iostream>
using namespace std;

const long long dve = 2;

long long broiChisla;
long long doKolkoNaiMnogo;

long long chisla[15];

long long koeficienti[15];

long long broiChetniStoinosti = 0;

void smqtaneDaliEDobro(){
    long long chisloVDesetichnaBroinaSistema = 0;
    long long poKolko = 1;

    for(long long i = broiChisla - 1; i >= 0; i--){
        chisloVDesetichnaBroinaSistema += chisla[i]*poKolko;
        if(i > 0){
            poKolko *= koeficienti[i - 1];
        }
    }

    if(chisloVDesetichnaBroinaSistema%2 == 0){
        broiChetniStoinosti++;
    }
}

void praveneNaSmetki(long long indexNaKoitoSme){
    if(indexNaKoitoSme == broiChisla - 1){
        smqtaneDaliEDobro();

        return ;
    }

    //koeficienti[indexNaKoitoSme] = 1;

    for(long long i = max(chisla[indexNaKoitoSme + 1] + 1, dve); i <= doKolkoNaiMnogo; i++){
        koeficienti[indexNaKoitoSme] = i;
        praveneNaSmetki(indexNaKoitoSme + 1);
    }

}

void broiHunaviStoinosti(long long broiOstavashti, long long doTuk, long long natrupano){
    if(broiOstavashti == 0){
        if(doTuk % 2 == 0){
            broiChetniStoinosti++;
        }
        return ;
    }

    if(broiOstavashti < broiChisla){
        for(int i = max(dve, chisla[broiOstavashti] + 1); i <= doKolkoNaiMnogo; i++){
            broiHunaviStoinosti(broiOstavashti - 1, doTuk + natrupano*i*chisla[broiOstavashti - 1], natrupano*i);
        }
    }else{
        broiHunaviStoinosti(broiOstavashti - 1, doTuk + chisla[broiOstavashti - 1], natrupano);
    }

}

int main(){
    cin>>broiChisla>>doKolkoNaiMnogo;

    for(long long i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    //praveneNaSmetki(0);

    broiHunaviStoinosti(broiChisla, 0, 1);

    cout<<broiChetniStoinosti<<endl;

    return 0;
}
