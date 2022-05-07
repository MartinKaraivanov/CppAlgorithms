#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int broiTochki;
int shirina;
int visochina;

int naiGolqmX = 0;

struct Koordinati{
    int x;
    int y;
};

struct DanniZaOtsechka{
    Koordinati lqvKrai;
    Koordinati desenKrai;
    int tip;
};

vector<DanniZaOtsechka> otsechki;

bool koqEPoNapred(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.lqvKrai.y > b.lqvKrai.y){
        return true;
    }
    if(a.lqvKrai.y < b.lqvKrai.y){
        return false;
    }
    if(a.tip > b.tip){
        return true;
    }
    if(a.tip < b.tip){
        return false;
    }
    return a.lqvKrai.x < b.lqvKrai.x;
}

struct DanniZaVrah{
    int lazyDelta;
    int maximalno;
    //int otKoiIndexObhvashta;
    //int doKoiIndexObhvashta;
    int lqvoDeteNomer;
    int dqsnoDeteNomer;
};

//vector<DanniZaVrah> varhove;
DanniZaVrah varhove[10000010];
int broiVarhove = 0;
int korenNomer = -1;

int daiNovVrah(DanniZaVrah novVrah){
    varhove[broiVarhove] = novVrah;
    broiVarhove++;
    return broiVarhove - 1;
    //varhove.push_back(novVrah);
    //return varhove.size() - 1;
}

int napraviDarvo(int otKade, int doKade){
    return -1;

    //vinagi dava -1

    if(otKade == doKade){
        return daiNovVrah({0, 0, -1, -1});
    }

    int lqvoDete = napraviDarvo(otKade, (otKade + doKade)/2);
    int dqsnoDete = napraviDarvo((otKade + doKade)/2 + 1, doKade);

    return daiNovVrah({0, 0, lqvoDete, dqsnoDete});
}

int daiMaximalnotoNa(int naKoiVrah){
    if(naKoiVrah == -1){
        return 0;
    }

    return varhove[naKoiVrah].maximalno;
}

int update(int segashenVrah, int otKadeUpd, int doKadeUpd, int delta, int otKoiIndexObh, int doKoiIndexObh){    //oshte 2 parametara
    //tuk pravim vraha, ako e -1 i e nujno (ima sechenie na intervalite) - vikame daiNovVrah

    if(otKoiIndexObh > doKadeUpd || doKoiIndexObh < otKadeUpd){
        return segashenVrah;
    }

    if(segashenVrah == -1){
        segashenVrah = daiNovVrah({0, 0, -1, -1});
    }

    if(otKadeUpd <= otKoiIndexObh && doKadeUpd >= doKoiIndexObh){
        varhove[segashenVrah].lazyDelta += delta;
        varhove[segashenVrah].maximalno += delta;
        return segashenVrah;
    }

    int novoLqvoDete =
        update(varhove[segashenVrah].lqvoDeteNomer,
                otKadeUpd,
                doKadeUpd,
                delta,
                otKoiIndexObh,
                (otKoiIndexObh + doKoiIndexObh)/2);
    varhove[segashenVrah].lqvoDeteNomer = novoLqvoDete;

    int novoDqsnoDete =
        update(varhove[segashenVrah].dqsnoDeteNomer,
                otKadeUpd,
                doKadeUpd,
                delta,
                (otKoiIndexObh + doKoiIndexObh)/2 + 1,
                doKoiIndexObh);
    varhove[segashenVrah].dqsnoDeteNomer = novoDqsnoDete;


    //tuk triabvat funkcii za vzimane na stojnost ot dete, zashotot moje da niama dete
    varhove[segashenVrah].maximalno =
        max(daiMaximalnotoNa(varhove[segashenVrah].lqvoDeteNomer), daiMaximalnotoNa(varhove[segashenVrah].dqsnoDeteNomer)) + varhove[segashenVrah].lazyDelta;

    ///tuk triem nashia vrah ako e prazen (niama deca i niama stoinosti), vrashtame -1 ako go iztriem

    return segashenVrah;
}


int query(){
    return varhove[korenNomer].maximalno;
}

void otpechataiDarvo(int segashenVrah){
    if(segashenVrah == -1){
        return ;
    }

    cout<<"sega sam na vrah "<<segashenVrah;
    //cout<<" obhvashta ot "<<varhove[segashenVrah].otKoiIndexObhvashta<<" "<<varhove[segashenVrah].doKoiIndexObhvashta;
    cout<<" ima lazyDelta "<<varhove[segashenVrah].lazyDelta;
    cout<<" ima lqvo dete "<<varhove[segashenVrah].lqvoDeteNomer;
    cout<<" i dqsno dete "<<varhove[segashenVrah].dqsnoDeteNomer<<endl;

    otpechataiDarvo(varhove[segashenVrah].lqvoDeteNomer);
    otpechataiDarvo(varhove[segashenVrah].dqsnoDeteNomer);
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //cin>>broiTochki>>shirina>>visochina;

    scanf("%i %i %i", &broiTochki, &shirina, &visochina);

    for(int i = 0; i < broiTochki; i++){
        int x;
        int y;
        //cin>>x>>y;

        scanf("%i %i", &x, &y);

        x *= 2;
        y *= 2;

        Koordinati gornaLqvaT = {max((int)0, x - shirina), y + visochina};
        Koordinati gornaDqsnaT = {x + shirina, y + visochina};
        Koordinati dolnaDqsnaT = {x + shirina, max((int)0, y - visochina)};
        Koordinati dolnaLqvaT = {max((int)0, x - shirina), max((int)0, y - visochina)};

        naiGolqmX = max(naiGolqmX, x + shirina);

        DanniZaOtsechka gorna = {gornaLqvaT, gornaDqsnaT, 1};
        DanniZaOtsechka dolna = {dolnaLqvaT, dolnaDqsnaT, -1};

        otsechki.push_back(gorna);
        otsechki.push_back(dolna);
    }

    sort(otsechki.begin(), otsechki.end(), koqEPoNapred);


    korenNomer = napraviDarvo(0, naiGolqmX);

    int naiMnogotoEdnovremenno = 0;

    for(int i = 0; i < (int)otsechki.size(); i++){

        korenNomer = update(korenNomer, otsechki[i].lqvKrai.x, otsechki[i].desenKrai.x, otsechki[i].tip, 0, naiGolqmX);

        if(otsechki[i].tip == 1){
            int tuka = query();
            naiMnogotoEdnovremenno = max(naiMnogotoEdnovremenno, tuka);
        }
    }

    //cout<<naiMnogotoEdnovremenno<<endl;

    printf("%i \n", naiMnogotoEdnovremenno);

    return 0;
}
