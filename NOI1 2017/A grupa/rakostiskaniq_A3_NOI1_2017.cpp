#include<iostream>
using namespace std;

int broiHora;

int nachalniRakostiskaniq[200010];

int kolkoSledTqhSaSeZdravisali[200010];
int kolkoSledTqhSaZdravsaliVsichkiPrediTqh[200010];

int main(){
    cin>>broiHora;

    for(int i = 0; i < broiHora; i++){
        cin>>nachalniRakostiskaniq[i];
    }

    for(int i = broiHora - 2; i >= 0; i--){
        if(nachalniRakostiskaniq[i + 1] > 0){
            kolkoSledTqhSaSeZdravisali[i] = kolkoSledTqhSaSeZdravisali[i + 1] + 1;
        }else{
            kolkoSledTqhSaSeZdravisali[i] = kolkoSledTqhSaSeZdravisali[i + 1];
        }
    }

    for(int i = broiHora - 2; i >= 0; i--){
        if(nachalniRakostiskaniq[i + 1] == i + 1){
            kolkoSledTqhSaZdravsaliVsichkiPrediTqh[i] = kolkoSledTqhSaZdravsaliVsichkiPrediTqh[i + 1] + 1;
        }else{
            kolkoSledTqhSaZdravsaliVsichkiPrediTqh[i] = kolkoSledTqhSaZdravsaliVsichkiPrediTqh[i + 1];
        }
    }

    int maksimalenBroiZdravisvaniq = 0;
    int minimalenBroiZdravisvaniq = 10000000;

    for(int i = 0; i < broiHora; i++){
        maksimalenBroiZdravisvaniq = max(maksimalenBroiZdravisvaniq, nachalniRakostiskaniq[i] + kolkoSledTqhSaSeZdravisali[i]);
    }

    for(int i = 0; i < broiHora; i++){
        minimalenBroiZdravisvaniq =
            min(minimalenBroiZdravisvaniq, nachalniRakostiskaniq[i] + kolkoSledTqhSaZdravsaliVsichkiPrediTqh[i]);
    }

    cout<<maksimalenBroiZdravisvaniq<<endl;
    cout<<minimalenBroiZdravisvaniq<<endl;

    return 0;
}
