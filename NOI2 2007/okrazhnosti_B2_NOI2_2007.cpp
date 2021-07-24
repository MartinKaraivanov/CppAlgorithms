#include<iostream>
#include<cmath>
#include<vector>
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
    if(okri.radius*okri.radius > kvadratche){
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

vector<int> sasedstvo[10010];

int naiMnogoOkrazhnosti(int koeKragche){
    if(naiMnogoKragchetaVTova[koeKragche] > -1){
        return naiMnogoKragchetaVTova[koeKragche];
    }

    int naiMnogoto = 0;

    for(unsigned int i = 0; i < sasedstvo[koeKragche].size(); i++){
        int segashno = 0;
        segashno = naiMnogoOkrazhnosti(sasedstvo[koeKragche][i]);
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

    for(int i = 0; i < broiOkrazhnosti; i++){
        for(int j = 0; j < broiOkrazhnosti; j++){
            if(i == j){
                continue;
            }
            if(taziOkrazhnostVatreLiEVDrugata(kragcheta[i], kragcheta[j])){
                sasedstvo[j].push_back(i);
                ///cout<< i << " < " << j << endl;
            }
        }
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
