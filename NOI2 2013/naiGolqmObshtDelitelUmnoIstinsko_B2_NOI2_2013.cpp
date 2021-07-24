#include<iostream>
using namespace std;

int kolkoPatiSluchvaSe;

int cifriNaPredishno[200];
int broiCifriNaPredishno;

int cifriNaSegashno[200];
int broiCifriNaSegashno;

int cifriNaSledvashto[200];
int broiCifriNaSledvashto;

int main(){
    cin>>kolkoPatiSluchvaSe;

    cifriNaPredishno[0] = 1;
    broiCifriNaPredishno = 1;

    cifriNaSegashno[0] = 1;
    broiCifriNaSegashno = 1;

    for(int i = 1; i <= kolkoPatiSluchvaSe; i++){
        int ostatak = 0;
        broiCifriNaSledvashto = 0;

        for(int j = 0; j < broiCifriNaPredishno; j++){
            cifriNaSledvashto[j] = (cifriNaPredishno[j] + cifriNaSegashno[j] + ostatak) % 10;
            ostatak = (cifriNaPredishno[j] + cifriNaSegashno[j] + ostatak)/10;
            broiCifriNaSledvashto++;
        }

        for(int j = broiCifriNaPredishno; j < broiCifriNaSegashno; j++){
            cifriNaSledvashto[j] = (cifriNaSegashno[j] + ostatak) % 10;
            ostatak = (cifriNaSledvashto[j] + ostatak)/10;
            broiCifriNaSledvashto++;
        }

        if(ostatak > 0){
            cifriNaSledvashto[broiCifriNaSegashno] = ostatak;
            broiCifriNaSledvashto++;
        }

        for(int j = 0; j < broiCifriNaSegashno; j++){
            cifriNaPredishno[j] = cifriNaSegashno[j];
        }
        broiCifriNaPredishno = broiCifriNaSegashno;

        for(int j = 0; j < broiCifriNaSledvashto; j++){
            cifriNaSegashno[j] = cifriNaSledvashto[j];
        }
        broiCifriNaSegashno = broiCifriNaSledvashto;

    }

    for(int i = broiCifriNaPredishno - 1; i >= 0; i--){
        cout<<cifriNaPredishno[i];
    }

    cout<<" ";

    for(int i = broiCifriNaSegashno - 1; i >= 0; i--){
        cout<<cifriNaSegashno[i];
    }

    cout<<endl;


    return 0;
}
