#include<iostream>
using namespace std;

int broiDarveta;
int darveta[100010];

int priTolkovaNamalqvashto[100010];
int priTolkovaReversenatoo[100010];

int naiMnogoNamalqvashtiKoitoZapochvatTuk(int darvo){
    if(priTolkovaNamalqvashto[darvo] > 0){
        return priTolkovaNamalqvashto[darvo];
    }

    int naiMnogoto = 0;

    for(int i = darvo + 1; i < broiDarveta; i++){
        int segashno = 0;
        if(darveta[i] < darveta[darvo]){
            segashno = naiMnogoNamalqvashtiKoitoZapochvatTuk(i);
        }
        naiMnogoto = max(naiMnogoto, segashno);
    }

    naiMnogoto++;
    priTolkovaNamalqvashto[darvo] = naiMnogoto;
    return naiMnogoto;
}

int naiMnogoNarastvashtiKoitoPrikluchvatTuk(int darvo){
    if(priTolkovaReversenatoo[darvo] > 0){
        return priTolkovaReversenatoo[darvo];
    }

    int naiMnogoto = 0;

    for(int i = darvo - 1; i >= 0; i--){
        int segashno = 0;
        if(darveta[i] < darveta[darvo]){
            segashno = naiMnogoNarastvashtiKoitoPrikluchvatTuk(i);
        }
        naiMnogoto = max(naiMnogoto, segashno);
    }

    naiMnogoto++;
    priTolkovaReversenatoo[darvo] = naiMnogoto;
    return naiMnogoto;
}

int main(){
    cin>>broiDarveta;

    for(int i = 0; i < broiDarveta; i++){
        cin>>darveta[i];
    }

    int naiDalgoRastqshto = 0;
    int naiDalgoNamalqvashto = 0;
    int naiDalgoSmeseno = 0;

    //cout<<naiMnogoNarastvashtiKoitoPrikluchvatTuk(5)<<endl;

    for(int i = 0; i < broiDarveta; i++){
        int doNego = naiMnogoNarastvashtiKoitoPrikluchvatTuk(i);
        int otNegoDoKraq = naiMnogoNamalqvashtiKoitoZapochvatTuk(i);
        int sumarno = doNego + otNegoDoKraq - 1;

        //cout<<i<<" "<<doNego<<" "<<otNegoDoKraq<<" "<<sumarno<<endl;

        if(sumarno > naiDalgoSmeseno){
            naiDalgoSmeseno = sumarno;
        }
        if(doNego > naiDalgoRastqshto){
            naiDalgoRastqshto = doNego;
        }
        if(otNegoDoKraq > naiDalgoNamalqvashto){
            naiDalgoNamalqvashto = otNegoDoKraq;
        }
    }

    int koetoNiTrqbva = max(max(naiDalgoRastqshto, naiDalgoNamalqvashto), naiDalgoSmeseno);

    cout<<koetoNiTrqbva<<endl;

    return 0;
}
