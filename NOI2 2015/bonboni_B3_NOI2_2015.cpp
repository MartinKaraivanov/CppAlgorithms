#include<iostream>
#include<cmath>
using namespace std;

int broiTorbichki;
int broiBonboniVTorbichka;

int tipNaToziBonbonVTaziTorbichka[2010][1010];

int chetnostNaToziTipBonbOtNachDoTuk[2010][1010];

int main(){
    cin>>broiTorbichki>>broiBonboniVTorbichka;

    for(int i = 1; i <= broiTorbichki; i++){
        for(int j = 1; j <= broiBonboniVTorbichka; j++){
            int brBonbonchetaTuk;
            cin>>brBonbonchetaTuk;
            if(brBonbonchetaTuk%2==0){
                tipNaToziBonbonVTaziTorbichka[i][j] = 2;
            }else{
                tipNaToziBonbonVTaziTorbichka[i][j] = 1;
            }

            chetnostNaToziTipBonbOtNachDoTuk[i][j] = chetnostNaToziTipBonbOtNachDoTuk[i - 1][j] +
                tipNaToziBonbonVTaziTorbichka[i][j];

            if(chetnostNaToziTipBonbOtNachDoTuk[i][j] % 2 == 0){
                chetnostNaToziTipBonbOtNachDoTuk[i][j] = 2;
            }else{
                chetnostNaToziTipBonbOtNachDoTuk[i][j] = 1;
            }
        }
    }

    int naiGolqmoPodred = 0;
    int otKadeZapochva = 0;

    for(int i = 1; i <= broiTorbichki; i++){
        for(int j = i; j <= broiTorbichki; j++){
            int kakvoTarsim = abs(chetnostNaToziTipBonbOtNachDoTuk[j][1] - chetnostNaToziTipBonbOtNachDoTuk[i - 1][1]);
            bool vsichkiLiSaTakiva = true;
            for(int b = 2; b <= broiBonboniVTorbichka; b++){
                int segashno = abs(chetnostNaToziTipBonbOtNachDoTuk[j][b] - chetnostNaToziTipBonbOtNachDoTuk[i - 1][b]);
                if(segashno != kakvoTarsim){
                    vsichkiLiSaTakiva = false;
                    break;
                }
            }
            if(vsichkiLiSaTakiva){
                if(j - i + 1 > naiGolqmoPodred){
                    naiGolqmoPodred = j - i + 1;
                    otKadeZapochva = i;
                }
            }
        }
    }

    cout<<otKadeZapochva<<" "<<naiGolqmoPodred<<endl;

    return 0;
}
