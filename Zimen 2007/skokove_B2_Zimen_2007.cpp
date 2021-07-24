#include<iostream>
using namespace std;

long long broiPloshtadki;

long long broiVazmozhniSkokove;
long long vazmozhniSkokove[205];

long long qbalkiNaPloshtadka[200010];

long long priTolkova[200010];

long long maximalnoKolichestvoQbalki(long long doPloshtadka){
    if(doPloshtadka == 0){
        return qbalkiNaPloshtadka[doPloshtadka];
    }

    if(doPloshtadka < 0){
        return -1000000000;
    }

    if(priTolkova[doPloshtadka] > -1){
        return priTolkova[doPloshtadka];
    }

    long long zaTuk = -1;

    for(long long i = 0; i < broiVazmozhniSkokove; i++){
        long long tekushto = qbalkiNaPloshtadka[doPloshtadka] + maximalnoKolichestvoQbalki(doPloshtadka - vazmozhniSkokove[i]);

        zaTuk = max(zaTuk, tekushto);
    }

    priTolkova[doPloshtadka] = zaTuk;
    return zaTuk;
}

int main(){
    cin>>broiPloshtadki>>broiVazmozhniSkokove;

    for(long long i = 0; i < broiVazmozhniSkokove; i++){
        cin>>vazmozhniSkokove[i];
    }

    for(long long i = 0; i <= broiPloshtadki; i++){
        cin>>qbalkiNaPloshtadka[i];
    }

    for(long long i = 0; i <= broiPloshtadki; i++){
        priTolkova[i] = -1;
    }

    long long naiMnogotQbalki = -1;
    long long doKoqPloshtdka = -1;

    for(long long i = 0; i <= broiPloshtadki; i++){
        long long tuk = maximalnoKolichestvoQbalki(i);

        if(tuk > naiMnogotQbalki){
            naiMnogotQbalki = tuk;
            doKoqPloshtdka = i;
        }
    }

    cout<<naiMnogotQbalki<<" "<<doKoqPloshtdka<<endl;

    return 0;
}
