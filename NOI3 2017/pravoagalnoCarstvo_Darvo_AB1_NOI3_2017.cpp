#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaOtsechka{
    DanniZaTochka gorna;
    DanniZaTochka dolna;
};

struct DanniZaGranica{
    DanniZaOtsechka otsechka;
    int tip;
    /// 1 - otvarqshta, 2 - zatvarqshta
};

int broiPravoagalnici;

int broiGranici;
DanniZaGranica granici[200010];

long long naiGolqmY;

bool koqEPoNapred(DanniZaGranica a, DanniZaGranica b){
    if(a.otsechka.gorna.x < b.otsechka.gorna.x){
        return true;
    }else{
        if(a.otsechka.gorna.x > b.otsechka.gorna.x){
            return false;
        }else{
            return a.otsechka.gorna.y < b.otsechka.gorna.y;
        }
    }
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
    return stoinost(koi) > -1;
}

void izchistiStoinostta(int naKoi){
    slojiStoinost(naKoi, -1);
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
        return daiNovVrah({-1, otIndex, doIndex, nqmaVrah, nqmaVrah});
    }

    int lqvoDeteNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDeteNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({-1, otIndex, doIndex, lqvoDeteNomer, dqsnoDeteNomer});
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

    int kvoPishe = -1;

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiPravoagalnici;

    for(int i = 0; i < broiPravoagalnici; i++){
        DanniZaTochka gornaLqva;
        int shirochina;
        int visochina;

        cin>>gornaLqva.x>>gornaLqva.y>>shirochina>>visochina;

        //cout<<"----------"<<gornaLqva.x<<" "<<gornaLqva.y<<" "<<gornaLqva.x + shirochina<<" "<<gornaLqva.y + visochina<<endl;

        naiGolqmY = max(naiGolqmY, (long long)gornaLqva.y + visochina);

        granici[broiGranici] =
            {{{gornaLqva.x, gornaLqva.y}, {gornaLqva.x, gornaLqva.y + visochina}}, 1};
        broiGranici++;

        granici[broiGranici] =
            {{{gornaLqva.x + shirochina, gornaLqva.y}, {gornaLqva.x + shirochina, gornaLqva.y + visochina}}, 2};
        broiGranici++;
    }

    sort(granici, granici + broiGranici, koqEPoNapred);

    nomerNaKorena = napraviDarvo(0, naiGolqmY);

    int broiSushinki = 0;

    //cout<<"--------------------------------"<<endl;

    for(int i = 0; i < broiGranici; i++){
        int kakvoImaDoSega = query(nomerNaKorena, granici[i].otsechka.gorna.y);

        //cout<<"tuka ima "<<kakvoImaDoSega<<endl;

        if(kakvoImaDoSega <= 0 && granici[i].tip == 1){
            //cout<<i<<" "<<granici[i].otsechka.gorna.x<<" "<<granici[i].otsechka.gorna.y<<" ";
            //cout<<granici[i].otsechka.dolna.x<<" "<<granici[i].otsechka.dolna.y<<endl;
            //cout<<"tuka e taka ---------------------------"<<endl;
            broiSushinki++;
        }

        //cout<<i<<" "<<granici[i].tip<<" "<<granici[i].otsechka.gorna.x<<" "<<granici[i].otsechka.gorna.y<<" ";
        //cout<<granici[i].otsechka.dolna.x<<" "<<granici[i].otsechka.dolna.y<<endl;

        //cout<<"updatevam ot "<<granici[i].otsechka.gorna.y<<" do "<<granici[i].otsechka.dolna.y<<endl<<endl;
        int kakvoDaSloja = 0;
        if(kakvoImaDoSega <= 0){
            kakvoDaSloja = 1;
        }
        update(nomerNaKorena, granici[i].otsechka.gorna.y, granici[i].otsechka.dolna.y, kakvoDaSloja);

        //cout<<endl;
    }

    cout<<broiSushinki<<endl;

    return 0;
}
