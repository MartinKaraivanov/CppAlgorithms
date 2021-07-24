#include<iostream>
using namespace std;

long long broiMasivi;

long long dalzhinaNaMasiva;
long long masiv[20010];

long long sborOtNachalotDoTuk[20010];

long long sborOtNqkudeDoNqkude(long long otKade, long long doKade){
    return sborOtNachalotDoTuk[doKade] - sborOtNachalotDoTuk[otKade - 1];
}

long long kadeSeRazdelq(long long otKade, long long doKade){
    long long polovinataSbor = sborOtNqkudeDoNqkude(otKade, doKade)/2;
    long long kadeSeRazdelq = -1;

    /*for(long long i = otKade; i < doKade; i++){
        if(sborOtNqkudeDoNqkude(otKade, i) == polovinataSbor){
            kadeSeRazdelq = i;
            break;
        }
    }*/

    long long lqvKrai = otKade;
    long long desenKrai = doKade;

    while(lqvKrai < desenKrai){
        long long sreda = (lqvKrai + desenKrai)/2;

        if(sborOtNqkudeDoNqkude(otKade, sreda) >= polovinataSbor){
            desenKrai = sreda;
        }else{
            lqvKrai = sreda + 1;
        }
    }

    if(sborOtNqkudeDoNqkude(otKade, lqvKrai) == polovinataSbor){
        kadeSeRazdelq = lqvKrai;
    }

    return kadeSeRazdelq;
}

long long maximalenBroiTochki(long long otKade, long long doKade){
    if(doKade - otKade <= 0 || (sborOtNqkudeDoNqkude(otKade, doKade))%2 == 1){
        return 0;
    }

    long long kadeERazdqlata = kadeSeRazdelq(otKade, doKade);

    long long zaVrashtane = 0;

    if(kadeERazdqlata > -1){
        zaVrashtane =
        1 +
        max(maximalenBroiTochki(otKade, kadeERazdqlata),
            maximalenBroiTochki(kadeERazdqlata + 1, doKade));
    }

    return zaVrashtane;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiMasivi;

    for(long long t = 0; t < broiMasivi; t++){
        cin>>dalzhinaNaMasiva;

        for(long long i = 1; i <= dalzhinaNaMasiva; i++){
            cin>>masiv[i];
        }

        for(long long i = 1; i <= dalzhinaNaMasiva; i++){
            sborOtNachalotDoTuk[i] = sborOtNachalotDoTuk[i - 1] + masiv[i];
        }

        long long naiGolqmBroiTochki = maximalenBroiTochki(1, dalzhinaNaMasiva);

        cout<<naiGolqmBroiTochki<<endl;
    }

    return 0;
}
