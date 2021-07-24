#include<iostream>
using namespace std;

long long maksimalenBroiVzemane;

/// 0 - gubeshta; 1 - pechelivsha; 2 - neutralna

const long long mnogo = 100000000;

int priTolkovka[mnogo][2][2];

const int Gubeshta = 0;
const int Pechelivsha = 1;
const int Neutralna = 2;

int kakvaEPoziciqta(long long broiOstavashtiNaKupchinkata, bool naNasChetnoLiNiTrqbva, bool naNegoChetnoLiMuTrqbva){
    if(broiOstavashtiNaKupchinkata == 0){
        if(naNasChetnoLiNiTrqbva && !naNegoChetnoLiMuTrqbva){
            return Pechelivsha;
        }
        if(!naNasChetnoLiNiTrqbva && naNegoChetnoLiMuTrqbva){
            return Gubeshta;
        }
        return Neutralna;
    }

    if(broiOstavashtiNaKupchinkata < mnogo){
        if(priTolkovka[broiOstavashtiNaKupchinkata][naNasChetnoLiNiTrqbva][naNegoChetnoLiMuTrqbva] > -1){
            return priTolkovka[broiOstavashtiNaKupchinkata][naNasChetnoLiNiTrqbva][naNegoChetnoLiMuTrqbva];
        }
    }

    bool imameLiZagubaZaDrugiq = false;
    bool vsichkiLiSaPobediZaNego = true;

    for(long long i = 1; i <= min(broiOstavashtiNaKupchinkata, maksimalenBroiVzemane); i++){
        int priTakova;

        if(i % 2 == 0){
            priTakova = kakvaEPoziciqta(broiOstavashtiNaKupchinkata - i, naNegoChetnoLiMuTrqbva, naNasChetnoLiNiTrqbva);
        }else{
            priTakova = kakvaEPoziciqta(broiOstavashtiNaKupchinkata - i, naNegoChetnoLiMuTrqbva, !naNasChetnoLiNiTrqbva);
        }

        if(priTakova == Gubeshta){
            imameLiZagubaZaDrugiq = true;
            vsichkiLiSaPobediZaNego = false;
            break;
        }
        if(priTakova == Neutralna){
            vsichkiLiSaPobediZaNego = false;
        }
    }

    int zaVrashtane;

    if(imameLiZagubaZaDrugiq){
        zaVrashtane = Pechelivsha;
    }else{
        if(vsichkiLiSaPobediZaNego){
            zaVrashtane = Gubeshta;
        }else{
            zaVrashtane = Neutralna;
        }
    }

    priTolkovka[broiOstavashtiNaKupchinkata][naNasChetnoLiNiTrqbva][naNegoChetnoLiMuTrqbva] = zaVrashtane;
    return zaVrashtane;
}

int main(){
    cin>>maksimalenBroiVzemane;

    for(long long i = 0; i <= mnogo; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                priTolkovka[i][j][k] = -1;
            }
        }
    }

    int broiNapechatani = 0;

    for(long long i = 5; i < mnogo; i += 2){
        if(broiNapechatani == 10){
            break;
        }
        if(kakvaEPoziciqta(i, true, true) == Gubeshta){
            cout<<i;
            broiNapechatani++;
            if(broiNapechatani < 10){
                cout<<" ";
            }
        }
        //cout<<kakvaEPoziciqta(i, true, true)<<endl;
        //cout<<"Napechatanite sa "<<broiNapechatani<<", a i e "<<i<<endl;
    }

    cout<<endl;

    return 0;
}
