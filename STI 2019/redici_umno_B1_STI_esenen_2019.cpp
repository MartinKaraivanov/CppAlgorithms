#include<iostream>
using namespace std;

const long long mnogo = 1000000007;

long long dalzhinaNaRedicata;
long long doKolkoEDulgaEdnaPodredica;

long long priTolkova[2000010];

long long broiInteresniRedici(long long sDalzhina){
    if(sDalzhina == 0){
        return 1;
    }

    if(priTolkova[sDalzhina] > -1){
        return priTolkova[sDalzhina];
    }

    long long zaTuk = 0;

    for(long long i = 1; i <= min(sDalzhina, doKolkoEDulgaEdnaPodredica); i++){
        zaTuk = (zaTuk + broiInteresniRedici(sDalzhina - i))%mnogo;
    }

    priTolkova[sDalzhina] = zaTuk;
    return zaTuk;
}

long long sborNaPTDo[2000010];

long long sCycli(long long zaSDalzhina){
    priTolkova[0] = 1;
    sborNaPTDo[0] = 1;

    for(long long sDalzhina = 1; sDalzhina <= zaSDalzhina; sDalzhina++){
        //long long zaTuk = 0;

        /*for(long long i = 1; i <= min(sDalzhina, doKolkoEDulgaEdnaPodredica); i++){
            zaTuk = (zaTuk + priTolkova[sDalzhina - i])%mnogo;
        }*/

        long long otKade = max((long long)0, sDalzhina - doKolkoEDulgaEdnaPodredica);
        long long doKade = sDalzhina - 1;

        /*for(long long i = otKade; i <= doKade; i++){
            zaTuk = (zaTuk + priTolkova[i])%mnogo;
        }*/

        long long zaTuk = sborNaPTDo[doKade]%mnogo;

        if(otKade > 0){
            zaTuk = (zaTuk + mnogo - sborNaPTDo[otKade - 1])%mnogo;
        }

        /*if(sDalzhina > doKolkoEDulgaEdnaPodredica){

        }else{
            zaTuk = priTolkova[sDalzhina - 1] +
        }*/

        priTolkova[sDalzhina] = zaTuk%mnogo;
        sborNaPTDo[sDalzhina] = (sborNaPTDo[sDalzhina - 1] + priTolkova[sDalzhina])%mnogo;
    }

    return priTolkova[zaSDalzhina]%mnogo;
}

int main(){
    cin>>dalzhinaNaRedicata>>doKolkoEDulgaEdnaPodredica;

    /*for(long long i = 0; i <= dalzhinaNaRedicata; i++){
        priTolkova[i] = -1;
    }*/

    long long brInteresnRedci = sCycli(dalzhinaNaRedicata)%mnogo;

    cout<<brInteresnRedci<<endl;

    return 0;
}
