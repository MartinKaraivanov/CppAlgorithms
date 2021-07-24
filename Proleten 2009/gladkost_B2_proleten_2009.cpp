#include<iostream>
using namespace std;

unsigned long long dalzhinaNaAleqta;
unsigned long long dalzhinaNaKashtata;

unsigned long long visochini[1000010];

unsigned long long sboraOtNachalotoDoTuk[1000010];

unsigned long long darvo[2500050];
unsigned long long broiNuzhniVarhove;

unsigned long long daiListo(unsigned long long index){
    return index + broiNuzhniVarhove/2;
}

void praveneNaBroiNuzhniVarhove(){
    for(unsigned long long i = 1; true; i *= 2){
        if(i > dalzhinaNaAleqta){
            broiNuzhniVarhove = 2 * i;
            break;
        }
    }
}

void praveneNaDarvoto(){
    for(unsigned long long i = 0; i < dalzhinaNaAleqta; i++){
        darvo[daiListo(i)] = visochini[i];
    }
    for(unsigned long long i = daiListo(0) - 1; i > 0; i--){
        darvo[i] = min(darvo[i * 2], darvo[i * 2 + 1]);
    }
}

unsigned long long kolkoENaiMalkotoOtTukDoTuk(unsigned long long otKade, unsigned long long doKade){
    unsigned long long lqvIndex = daiListo(otKade);
    unsigned long long desenIndex = daiListo(doKade);

    if(lqvIndex == desenIndex){
        return darvo[lqvIndex];
    }

    unsigned long long naiMalkoto = min(darvo[lqvIndex], darvo[desenIndex]);

    while(lqvIndex + 1 != desenIndex){
        if(lqvIndex % 2 == 0){
            naiMalkoto = min(darvo[lqvIndex + 1], naiMalkoto);
        }
        if(desenIndex % 2 == 1){
            naiMalkoto = min(darvo[desenIndex - 1], naiMalkoto);
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return naiMalkoto;
}

void praveneNaPrefixiqMasiv(){
    for(unsigned long long i = 0; i < dalzhinaNaAleqta; i++){
        if(i > 0){
            sboraOtNachalotoDoTuk[i] = sboraOtNachalotoDoTuk[i - 1] + visochini[i];
        }else{
            sboraOtNachalotoDoTuk[i] = visochini[i];
        }
    }
}

unsigned long long kolkoESboraOtDo(unsigned long long otKade, unsigned long long doKade){
    if(otKade == 0){
        return sboraOtNachalotoDoTuk[doKade];
    }else{
        return sboraOtNachalotoDoTuk[doKade] - sboraOtNachalotoDoTuk[otKade - 1];
    }
}

int main(){
    cin>>dalzhinaNaAleqta>>dalzhinaNaKashtata;

    for(unsigned long long i = 0; i < dalzhinaNaAleqta; i++){
        cin>>visochini[i];
    }

    praveneNaPrefixiqMasiv();
    praveneNaBroiNuzhniVarhove();
    praveneNaDarvoto();

    unsigned long long naiMalkoto = 100000000000000;
    unsigned long long otkadeZapochva = -1;

    for(unsigned long long i = 0; i <= dalzhinaNaAleqta - dalzhinaNaKashtata; i++){
        unsigned long long naiMalkotoZaTezi = kolkoENaiMalkotoOtTukDoTuk(i, i + dalzhinaNaKashtata - 1);

        unsigned long long zaTuKKopaene = kolkoESboraOtDo(i, i + dalzhinaNaKashtata - 1);

        zaTuKKopaene -= (dalzhinaNaKashtata * naiMalkotoZaTezi);

        if(zaTuKKopaene < naiMalkoto){
            naiMalkoto = zaTuKKopaene;
            otkadeZapochva = i + 1;
        }
    }

    cout<<naiMalkoto<<endl<<otkadeZapochva<<endl;

    return 0;
}
