#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct DanniZaDaskata{
    int nomer;
    int dalbochina;
};

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaOtsechka{
    DanniZaTochka nachalnaTochka;
    int daljina;
};

int broiOtsechki;
DanniZaOtsechka otsechki[100010];

int maximalenX;

int broiBrambari;
int tochkiNaPuskane[60010];

vector<int> sasedstvo[100010];

bool koqEPoParva(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.nachalnaTochka.y > b.nachalnaTochka.y){
        return false;
    }
    if(a.nachalnaTochka.y < b.nachalnaTochka.y){
        return true;
    }

    return a.nachalnaTochka.x < b.nachalnaTochka.x;
}

struct DanniZaVrah{
    int stoinost;
    int otKoiIndexObhvashta;
    int doKoiIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};

vector<DanniZaVrah> varhove;
int nomerNaKorena = -1;

int otKoiIndexObhvashta(int koi){
    return varhove[koi].otKoiIndexObhvashta;
}

int doKoiIndexObhvashta(int koi){
    return varhove[koi].doKoiIndexObhvashta;
}

int lqvoDeteVrahNomer(int naKoi){
    return varhove[naKoi].lqvoDeteVrahNomer;
}

int dqsnoDeteVrahNomer(int naKoi){
    return varhove[naKoi].dqsnoDeteVrahNomer;
}

void slojiStoinost(int naKoi, int kolko){
    varhove[naKoi].stoinost = kolko;
}

int stoinost(int naKoi){
    return varhove[naKoi].stoinost;
}

bool imaLiStoinost(int koi){
    return stoinost(koi) > 0;
}

void izchistiStoinostta(int naKoi){
    slojiStoinost(naKoi, 0);
}

const int nqmaVrah = -1;

int broiChisla;
vector<int> chisla;

int daiNovVrah(DanniZaVrah novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otIndex, int doIndex){
    if(otIndex == doIndex){
        return daiNovVrah({0, otIndex, doIndex, nqmaVrah, nqmaVrah});
    }

    int lqvoDeteNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDeteNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({0, otIndex, doIndex, lqvoDeteNomer, dqsnoDeteNomer});
}

void update(int korenNaPoddarvoVrahNomer, int otIndex, int doIndex, int kolko){
    if(korenNaPoddarvoVrahNomer == nqmaVrah ||
       otIndex > doKoiIndexObhvashta(korenNaPoddarvoVrahNomer) ||
       doIndex < otKoiIndexObhvashta(korenNaPoddarvoVrahNomer)){

        return;
    }

    if(otIndex <= otKoiIndexObhvashta(korenNaPoddarvoVrahNomer) &&
       doIndex >= doKoiIndexObhvashta(korenNaPoddarvoVrahNomer)){

        //cout<<"updatevam "<<korenNaPoddarvoVrahNomer<<" i go slagam da e "<<kolko<<endl;
        slojiStoinost(korenNaPoddarvoVrahNomer, kolko);
        return;
    }

    if(imaLiStoinost(korenNaPoddarvoVrahNomer)){
        int tekushtaStoinost = stoinost(korenNaPoddarvoVrahNomer);

        izchistiStoinostta(korenNaPoddarvoVrahNomer);

        update(
            lqvoDeteVrahNomer(korenNaPoddarvoVrahNomer),
            otKoiIndexObhvashta(korenNaPoddarvoVrahNomer),
            doKoiIndexObhvashta(korenNaPoddarvoVrahNomer),
            tekushtaStoinost);

        update(
            dqsnoDeteVrahNomer(korenNaPoddarvoVrahNomer),
            otKoiIndexObhvashta(korenNaPoddarvoVrahNomer),
            doKoiIndexObhvashta(korenNaPoddarvoVrahNomer),
            tekushtaStoinost);
    }

    update(lqvoDeteVrahNomer(korenNaPoddarvoVrahNomer), otIndex, doIndex, kolko);
    update(dqsnoDeteVrahNomer(korenNaPoddarvoVrahNomer), otIndex, doIndex, kolko);
}


int query(int korenNaPoddarvoVrahNomer, int naKoiIndex){
    int segashenVrah = korenNaPoddarvoVrahNomer;

    int kvoPishe = 0;

    while(segashenVrah != nqmaVrah){
        if(otKoiIndexObhvashta(segashenVrah) > naKoiIndex ||
           doKoiIndexObhvashta(segashenVrah) < naKoiIndex)
        {
            break;
        }

        if(imaLiStoinost(segashenVrah)){
            kvoPishe = stoinost(segashenVrah);
            break;
        }

        if(lqvoDeteVrahNomer(segashenVrah) != nqmaVrah &&
           otKoiIndexObhvashta(lqvoDeteVrahNomer(segashenVrah)) <= naKoiIndex &&
           doKoiIndexObhvashta(lqvoDeteVrahNomer(segashenVrah)) >= naKoiIndex)
        {
            segashenVrah = lqvoDeteVrahNomer(segashenVrah);
        }else{
            segashenVrah = dqsnoDeteVrahNomer(segashenVrah);
        }
    }

    return kvoPishe;
}

int dalbochini[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOtsechki;

    for(int i = 1; i <= broiOtsechki; i++){
        cin>>otsechki[i].nachalnaTochka.x>>otsechki[i].nachalnaTochka.y>>otsechki[i].daljina;
        maximalenX = max(maximalenX, otsechki[i].nachalnaTochka.x + otsechki[i].daljina);
    }

    cin>>broiBrambari;

    for(int i = 0; i < broiBrambari; i++){
        cin>>tochkiNaPuskane[i];
    }

    sort(otsechki, otsechki + broiOtsechki + 1, koqEPoParva);

    nomerNaKorena = napraviDarvo(0, maximalenX);

    for(int i = 1; i <= broiOtsechki; i++){
        int otLqvo = query(nomerNaKorena, otsechki[i].nachalnaTochka.x - 1);
        int otDqsno = query(nomerNaKorena, otsechki[i].nachalnaTochka.x + otsechki[i].daljina);

        dalbochini[i] = min(dalbochini[otLqvo], dalbochini[otDqsno]) + 1;

        update(nomerNaKorena, otsechki[i].nachalnaTochka.x, otsechki[i].nachalnaTochka.x + otsechki[i].daljina - 1, i);
    }

    for(int i = 0; i < broiBrambari; i++){
        int dalb = dalbochini[query(nomerNaKorena, tochkiNaPuskane[i])];
        cout<<dalb<<" ";
    }

    return 0;
}
