#include<iostream>
#include<cmath>
using namespace std;

int broiEtaji;
int broiYaica;

long long priTolkova[1000010][24];

long long broiOpiti(int zaEtaji, int zaYaica){
    if(zaYaica == 1){
        return zaEtaji;
    }
    if(zaYaica == 0){
        return 0;
    }
    if(zaEtaji <= 1){
        return 1;
    }

    if(priTolkova[zaEtaji][zaYaica] > 0){
        return priTolkova[zaEtaji][zaYaica];
    }

    long long zaTuka = 1000010;

    for(int i = 1; i <= zaEtaji; i++){
        long long tekushto = 1 + max(broiOpiti(zaEtaji - i, zaYaica), broiOpiti(i - 1, zaYaica - 1));
        zaTuka = min(zaTuka, tekushto);
    }

    priTolkova[zaEtaji][zaYaica] = zaTuka;
    return zaTuka;
}

int main(){

    cin>>broiEtaji>>broiYaica;

    if(broiEtaji == 1){
        cout<<1<<endl;
        return 0;
    }

    int logEtaji = ceil(log((double)broiEtaji)/log(2));

    if(broiYaica >= logEtaji){
        cout<<logEtaji<<endl;
        return 0;
    }


    long long otgovor = broiOpiti(broiEtaji, broiYaica);

    cout<<otgovor<<endl;

    return 0;
}
