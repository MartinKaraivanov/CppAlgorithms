#include<iostream>
#include<stdio.h>
using namespace std;

int broiOtcheti;

char nuzhenBroiZaPredstavqneNaTova[1000010];

const int mnogo = 100000000;

int broiNuzhniCifriZaPredstavqne(int chislo){
    int br = 1;
    while(chislo != 0){
        br++;
        chislo /= 2;
    }

    return br;
}

int priTolkovaSkrishno[2][18];

int daiPriTolkova(int doKade, int sKakvaShirina){
    return priTolkovaSkrishno[doKade%2][sKakvaShirina];
}

void slojiPriTolkova(int doKade, int sKakvaShirina, int kolko){
    priTolkovaSkrishno[doKade%2][sKakvaShirina] = kolko;
}

/*int naiMalakBroiImpulsi(int doKade, int sKakvaShirina){
    if(doKade == 0 && sKakvaShirina == 17){
        return 0;
    }
    if(doKade == 0 && sKakvaShirina != 17){
        return mnogo;
    }
    if(sKakvaShirina < nuzhenBroiZaPredstavqneNaTova[doKade]){
        return mnogo;
    }

    if(priTolkova[doKade][sKakvaShirina] > 0){
        return priTolkova[doKade][sKakvaShirina];
    }

    int naiMBroiImpulsi = sKakvaShirina + naiMalakBroiImpulsi(doKade - 1, sKakvaShirina);

    for(int i = 1; i <= 17; i++){
        int segashno = 4 + i + sKakvaShirina + naiMalakBroiImpulsi(doKade - 1, i);
        naiMBroiImpulsi = min(naiMBroiImpulsi, segashno);
    }

    priTolkova[doKade][sKakvaShirina] = naiMBroiImpulsi;
    return naiMBroiImpulsi;
}*/

void sCycli(){
    for(int i = 0; i < 17; i++){
        slojiPriTolkova(0, i, mnogo);
    }
    slojiPriTolkova(0, 17, 0);

    for(int doKade = 1; doKade <= broiOtcheti; doKade++){

        for(int j = 0; j < nuzhenBroiZaPredstavqneNaTova[doKade]; j++){
            slojiPriTolkova(doKade, j, mnogo);
        }

        for(int sKakvaShirina = nuzhenBroiZaPredstavqneNaTova[doKade]; sKakvaShirina <= 17; sKakvaShirina++){
            int naiMBroiImpulsi = sKakvaShirina + daiPriTolkova(doKade - 1, sKakvaShirina);

            for(int i = 1; i <= 17; i++){
                int segashno = 4 + i + sKakvaShirina + daiPriTolkova(doKade - 1, i);
                naiMBroiImpulsi = min(naiMBroiImpulsi, segashno);
            }

            slojiPriTolkova(doKade, sKakvaShirina, naiMBroiImpulsi);
        }
    }
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //cin>>broiOtcheti;

    scanf("%i", &broiOtcheti);

    int predno = 0;

    for(int i = 1; i <= broiOtcheti; i++){
        int segashno;
        //cin>>segashno;
        scanf("%i", &segashno);
        int segashnaDelta = segashno - predno;
        predno = segashno;
        nuzhenBroiZaPredstavqneNaTova[i] = broiNuzhniCifriZaPredstavqne(segashnaDelta);
    }

    nuzhenBroiZaPredstavqneNaTova[0] = 17;

    sCycli();

    int naiMalkotoImpulsi = mnogo;

    for(int i = nuzhenBroiZaPredstavqneNaTova[broiOtcheti]; i <= 17; i++){
        int zaTuk = daiPriTolkova(broiOtcheti, i);
        naiMalkotoImpulsi = min(naiMalkotoImpulsi, zaTuk);
    }

    //cout<<naiMalkotoImpulsi<<endl;
    printf("%i \n", naiMalkotoImpulsi);

    return 0;
}
