#include<iostream>
using namespace std;

const long long mnogo = 998244353;

long long daljinaPasport;
long long broiPechati;
long long daljinaPechat;

long long priTolkova[1000010];

long long broiNachini(long long doKade){
    if(doKade == 1){
        return broiPechati;
    }

    if(priTolkova[doKade] > -1){
        return priTolkova[doKade];
    }

    long long sumaTuka = 0;

    long long doKadeVartim = min(daljinaPechat - 1, doKade - 1);

    for(long long i = 1; i <= doKadeVartim; i++){
        long long tekushto = broiNachini(doKade - i);
        sumaTuka = (sumaTuka + tekushto)%mnogo;
    }

    sumaTuka = (sumaTuka * (broiPechati - 1))%mnogo;

    priTolkova[doKade] = sumaTuka;
    return sumaTuka;
}

long long sumaOtNachalotoDo[1000010];

void sCycli(long long zaDoKade){
    priTolkova[1] = broiPechati;
    sumaOtNachalotoDo[1] = broiPechati;

    for(long long doKade = 2; doKade <= zaDoKade; doKade++){

        long long doKadeVartim = min(daljinaPechat - 1, doKade - 1);

        /*long long sumaTuka = 0;

        for(long long i = 1; i <= doKadeVartim; i++){
            long long tekushto = priTolkova[doKade - i];
            sumaTuka = (sumaTuka + tekushto)%mnogo;
        }*/

        long long sumaTuka = (mnogo + sumaOtNachalotoDo[doKade - 1] - sumaOtNachalotoDo[doKade - doKadeVartim - 1]);

        sumaTuka = (sumaTuka * (broiPechati - 1))%mnogo;

        priTolkova[doKade] = sumaTuka;
        sumaOtNachalotoDo[doKade] = (sumaOtNachalotoDo[doKade - 1] + priTolkova[doKade])%mnogo;
    }

}

int main(){

    cin>>daljinaPasport>>broiPechati>>daljinaPechat;

    long long obshtoBroiNachini = 1;

    for(long long i = 1; i <= daljinaPasport; i++){
        obshtoBroiNachini = (obshtoBroiNachini*broiPechati)%mnogo;
    }

    /*for(long long i = 0; i <= daljinaPasport; i++){
        priTolkova[i] = -1;
    }*/

    sCycli(daljinaPasport);

    long long broiBezPoredni = 0;

    for(long long i = 1; i < daljinaPechat; i++){
        //long long tukaBrNachini = broiNachini(daljinaPasport - i + 1);
        long long tukaBrNachini = priTolkova[daljinaPasport - i + 1];
        broiBezPoredni = (broiBezPoredni + tukaBrNachini)%mnogo;
    }

    long long otgovor = (mnogo + obshtoBroiNachini - broiBezPoredni)%mnogo;

    cout<<otgovor<<endl;

    return 0;
}
