#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaTochkata{
    int x;
    int y;
};

struct DanniZaOkrazhnostta{
    DanniZaTochkata centar;
    int radius;
};

int broiOkrazhnosti;

DanniZaOkrazhnostta kragcheta[10010];

bool tochkataVOkrazhnosttaLiE(DanniZaTochkata tochka, DanniZaOkrazhnostta okri){
    int kvadratche = (tochka.x - okri.centar.x)*(tochka.x - okri.centar.x) +
        (tochka.y - okri.centar.y)*(tochka.y - okri.centar.y);
    double dalzhinka = sqrt(kvadratche);
    if(okri.radius - dalzhinka > 0.0){
        return true;
    }else{
        return false;
    }
}

bool taziOkrazhnostVatreLiEVDrugata(DanniZaOkrazhnostta vatreshna, DanniZaOkrazhnostta vanshna){
    int kvadratche = (vatreshna.centar.x - vanshna.centar.x)*(vatreshna.centar.x - vanshna.centar.x) +
        (vatreshna.centar.y - vanshna.centar.y)*(vatreshna.centar.y - vanshna.centar.y);
    ///(r1-r2)*(r1-r2) =

    if(vanshna.radius > vatreshna.radius &&
       (vanshna.radius - vatreshna.radius)*(vanshna.radius - vatreshna.radius)  > kvadratche){
        return true;
    }else{
        return false;
    }
}

int naiMnogoKragchetaVTova[10010];

int naiMnogoOkrazhnosti(int koeKragche){
    if(naiMnogoKragchetaVTova[koeKragche] > -1){
        return naiMnogoKragchetaVTova[koeKragche];
    }

    int naiMnogoto = 0;

    for(int i = 0; i < broiOkrazhnosti; i++){
        int segashno = 0;
        if(taziOkrazhnostVatreLiEVDrugata(kragcheta[i], kragcheta[koeKragche]) == true){
            segashno = naiMnogoOkrazhnosti(i);
        }
        if(segashno > naiMnogoto){
            naiMnogoto = segashno;
        }
    }

    int zaVrashtane = naiMnogoto + 1;
    naiMnogoKragchetaVTova[koeKragche] = zaVrashtane;
    return zaVrashtane;
}

int main(){
    cin>>broiOkrazhnosti;

    for(int i = 0; i < broiOkrazhnosti; i++){
        cin>>kragcheta[i].centar.x>>kragcheta[i].centar.y>>kragcheta[i].radius;
    }

    for(int i = 0; i < broiOkrazhnosti; i++){
        naiMnogoKragchetaVTova[i] = -1;
    }

    int naiMnogotoOkrazhnostiEdnaVDruga = 0;

    for(int i = 0; i < broiOkrazhnosti; i++){
        int tekushtaMamaTokuSePribra = naiMnogoOkrazhnosti(i);
        if(tekushtaMamaTokuSePribra > naiMnogotoOkrazhnostiEdnaVDruga){
            naiMnogotoOkrazhnostiEdnaVDruga = tekushtaMamaTokuSePribra;
        }
    }

    cout<<naiMnogotoOkrazhnostiEdnaVDruga<<endl;

    return 0;
}
