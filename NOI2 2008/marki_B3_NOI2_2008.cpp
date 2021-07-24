#include<iostream>
#include<algorithm>
using namespace std;

int nuzhnaCena;
int broiMarki;
int marki[3100];
int priTolkova[5100];

int naiMalkoMarki(int suma){
    if(suma == 0){
        return 0;
    }
    if(suma <= -1){
        return 3000000;
    }

    if(priTolkova[suma] > -1){
        return priTolkova[suma];
    }

    int naiDobro = 1000000;

    for(int koqMonetka = 0; koqMonetka < broiMarki; koqMonetka++){
        int eventualno;
        eventualno = 1 + naiMalkoMarki(suma - marki[koqMonetka]);
        naiDobro = min(naiDobro, eventualno);
    }

    priTolkova[suma] = naiDobro;

    return naiDobro;
}

int main(){
    cin>>nuzhnaCena>>broiMarki;

    for(int i = 0; i < broiMarki; i++){
        cin>>marki[i];
    }

    for(int i = 0; i <= nuzhnaCena; i++){
        priTolkova[i] = -1;
    }

    sort(marki, marki + broiMarki);

    int naiMalakBroiMarki = naiMalkoMarki(nuzhnaCena);

    cout<<naiMalakBroiMarki<<endl;

    return 0;
}
