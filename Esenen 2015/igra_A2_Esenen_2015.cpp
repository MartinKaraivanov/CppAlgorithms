#include<iostream>
using namespace std;

long long doKoeChislo;

int cenaNe;
int cenaDa;

long long priTolkova[10005];

long long minimalnaNuzhnaSuma(long long dalzhina){
    if(dalzhina == 1){
        return 0;
    }

    if(priTolkova[dalzhina] > 0){
        return priTolkova[dalzhina];
    }

    long long zaTuk = 10000000000000;

    for(long long slDalzhina = 1; slDalzhina < dalzhina; slDalzhina++){
        long long akoEDa = cenaDa + minimalnaNuzhnaSuma(slDalzhina);
        long long akoENe = cenaNe + minimalnaNuzhnaSuma(dalzhina - slDalzhina);

        long long tekushto = max(akoEDa, akoENe);

        if(tekushto < zaTuk){
            zaTuk = tekushto;
        }

    }

    priTolkova[dalzhina] = zaTuk;
    return zaTuk;
}

long long sCycli(long long zaDalzhina){

    for(int dalzhina = 2; dalzhina <= zaDalzhina; dalzhina++){
        long long zaTuk = 10000000000000;

        for(long long slDalzhina = 1; slDalzhina < dalzhina; slDalzhina++){
            long long akoEDa = cenaDa + priTolkova[slDalzhina];
            long long akoENe = cenaNe + priTolkova[dalzhina - slDalzhina];

            long long tekushto = max(akoEDa, akoENe);

            if(tekushto < zaTuk){
                zaTuk = tekushto;
            }

        }

        priTolkova[dalzhina] = zaTuk;
    }

    return priTolkova[zaDalzhina];
}

int main(){
    cin>>doKoeChislo>>cenaNe>>cenaDa;

    long long cenaKoqtoDaPlatiGosho = sCycli(doKoeChislo);

    cout<<cenaKoqtoDaPlatiGosho<<endl;

    return 0;
}
