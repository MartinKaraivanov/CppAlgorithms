#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int broiVarhove;

vector<int> sasedstvo[200010];

int broiTransportiraniq;

struct DanniZaTransporta{
    int otKade;
    int doKade;
    int pechalba;
};

DanniZaTransporta transportiraniq[200010];

int koren;

struct DanniZaObnhvashtaneto{
    int otKade;
    int doKade;
};

DanniZaObnhvashtaneto kadeObhvashtaTozi[200010];

int momentNaVlizane[200010];
int momentNaIzlizane[200010];
int vreme;

int bashta[200010];

void nameriMomentite(int segashenVrah, int otKadeIdvame){

    vreme++;
    momentNaVlizane[segashenVrah] = vreme;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i] != otKadeIdvame){
            nameriMomentite(sasedstvo[segashenVrah][i], segashenVrah);
        }
    }

    vreme++;
    momentNaIzlizane[segashenVrah] = vreme;
}

int nomerche;

int broiLista;

int originalnoKoiE[200010];

DanniZaObnhvashtaneto nameriObhvashtaniqta(int segashenVrah, int otKadeIdvame){
    bashta[segashenVrah] = otKadeIdvame;

    if(sasedstvo[segashenVrah].size() == 1){
        nomerche++;
        kadeObhvashtaTozi[segashenVrah] = {nomerche, nomerche};

        originalnoKoiE[nomerche] = segashenVrah;
        broiLista++;

        return {nomerche, nomerche};
    }

    int naiMalkiq = 200010;
    int naiGolemiq = 0;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i] != otKadeIdvame){
            DanniZaObnhvashtaneto tuka = nameriObhvashtaniqta(sasedstvo[segashenVrah][i], segashenVrah);
            naiMalkiq = min(naiMalkiq, tuka.otKade);
            naiGolemiq = max(naiGolemiq, tuka.doKade);
        }
    }

    kadeObhvashtaTozi[segashenVrah] = {naiMalkiq, naiGolemiq};

    return kadeObhvashtaTozi[segashenVrah];
}

struct Koordinati{
    int x;
    int y;
};

struct DanniZaOtsechka{
    Koordinati lqvKrai;
    Koordinati desenKrai;
    int tip;
    int pechlb;
};

int detetoKoetoEKum(int otKoi, int koeDete){

    for(int i = 0; i < (int)sasedstvo[otKoi].size(); i++){
        int sledvasht = sasedstvo[otKoi][i];
        if(momentNaVlizane[sledvasht] <= momentNaVlizane[koeDete] && momentNaIzlizane[sledvasht] >= momentNaIzlizane[koeDete] && sledvasht != bashta[otKoi]){
            return sledvasht;
        }
    }

    return 0;
}

vector<DanniZaOtsechka> otsechki;

void nameriOtsechkite(){

    for(int i = 0; i < broiTransportiraniq; i++){
        int otKadeTransport = transportiraniq[i].otKade;
        int doKadeTransport = transportiraniq[i].doKade;
        int pechalba = transportiraniq[i].pechalba;

        if(momentNaVlizane[doKadeTransport] < momentNaVlizane[otKadeTransport]){
            swap(otKadeTransport, doKadeTransport);
        }

        if(momentNaVlizane[doKadeTransport] > momentNaVlizane[otKadeTransport] && momentNaIzlizane[doKadeTransport] < momentNaIzlizane[otKadeTransport]){

            int mejdinnotoDete = detetoKoetoEKum(otKadeTransport, doKadeTransport);

            if(kadeObhvashtaTozi[mejdinnotoDete].otKade > 1){
                int lqvX = 1;
                int desenX = kadeObhvashtaTozi[mejdinnotoDete].otKade - 1;
                int dolenY = kadeObhvashtaTozi[doKadeTransport].otKade;
                int gorenY = kadeObhvashtaTozi[doKadeTransport].doKade;

                otsechki.push_back({{lqvX, dolenY}, {desenX, dolenY}, 1, pechalba});
                otsechki.push_back({{lqvX, gorenY}, {desenX, gorenY}, -1, pechalba});
            }

            if(kadeObhvashtaTozi[mejdinnotoDete].doKade < broiLista){
                int lqvX = kadeObhvashtaTozi[doKadeTransport].otKade;
                int desenX = kadeObhvashtaTozi[doKadeTransport].doKade;
                int dolenY = kadeObhvashtaTozi[mejdinnotoDete].doKade + 1;
                int gorenY = broiLista;

                otsechki.push_back({{lqvX, dolenY}, {desenX, dolenY}, 1, pechalba});
                otsechki.push_back({{lqvX, gorenY}, {desenX, gorenY}, -1, pechalba});
            }
        }else{
            int lqvX = kadeObhvashtaTozi[otKadeTransport].otKade;
            int desenX = kadeObhvashtaTozi[otKadeTransport].doKade;
            int dolenY = kadeObhvashtaTozi[doKadeTransport].otKade;
            int gorenY = kadeObhvashtaTozi[doKadeTransport].doKade;

            otsechki.push_back({{lqvX, dolenY}, {desenX, dolenY}, 1, pechalba});
            otsechki.push_back({{lqvX, gorenY}, {desenX, gorenY}, -1, pechalba});
        }
    }
}

bool koqEPoNapred(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.lqvKrai.y < b.lqvKrai.y){
        return true;
    }
    if(a.lqvKrai.y > b.lqvKrai.y){
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
    int otKadeObhvashta;
    int doKadeObhvashta;
    int maxVIntervalaMu;
    int kadeEMaxa;
    int lazyDelta;
    int lqvoDeteNomer;
    int dqsnoDeteNomer;
};

vector<DanniZaVrah> varhove;

int korenNomer = -1;

int daiNovVrah(DanniZaVrah vrah){
    varhove.push_back(vrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otIndex, int doIndex){
    if(otIndex == doIndex){
        return daiNovVrah({otIndex, doIndex, 0, otIndex, 0, -1, -1});
    }

    int lqvoDete = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDete = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({otIndex, doIndex, 0, lqvoDete, 0, lqvoDete, dqsnoDete});
}

int maxaTam(int kade){
    if(kade == -1){
        return 0;
    }

    return varhove[kade].maxVIntervalaMu;
}

void update(int korenPoddarvoNomer, int otKade, int doKade, int delta){
    if(korenPoddarvoNomer == -1 || varhove[korenPoddarvoNomer].otKadeObhvashta > doKade || varhove[korenPoddarvoNomer].doKadeObhvashta < otKade){
        return ;
    }

    if(otKade <= varhove[korenPoddarvoNomer].otKadeObhvashta && doKade >= varhove[korenPoddarvoNomer].doKadeObhvashta){
        varhove[korenPoddarvoNomer].maxVIntervalaMu += delta;
        varhove[korenPoddarvoNomer].lazyDelta += delta;

        return ;
    }

    update(varhove[korenPoddarvoNomer].lqvoDeteNomer, otKade, doKade, delta);
    update(varhove[korenPoddarvoNomer].dqsnoDeteNomer, otKade, doKade, delta);

    /// zasumata

    if(maxaTam(varhove[korenPoddarvoNomer].lqvoDeteNomer) > maxaTam(varhove[korenPoddarvoNomer].dqsnoDeteNomer)){
        varhove[korenPoddarvoNomer].maxVIntervalaMu = maxaTam(varhove[korenPoddarvoNomer].lqvoDeteNomer) + varhove[korenPoddarvoNomer].lazyDelta;
        varhove[korenPoddarvoNomer].kadeEMaxa = varhove[varhove[korenPoddarvoNomer].lqvoDeteNomer].kadeEMaxa;
    }else{
        varhove[korenPoddarvoNomer].maxVIntervalaMu = maxaTam(varhove[korenPoddarvoNomer].dqsnoDeteNomer) + varhove[korenPoddarvoNomer].lazyDelta;
        varhove[korenPoddarvoNomer].kadeEMaxa = varhove[varhove[korenPoddarvoNomer].dqsnoDeteNomer].kadeEMaxa;
    }
}

int query(){
    return varhove[korenNomer].maxVIntervalaMu;
}

//(int, int) queryMaxAll()

//(int, int) queryMax(ot, do)

//int queryKolko(kade)

//int QuerySuma(ot, do)


/*int querySuma(int korenPoddarvoNomer, int kadeKolkoE){
    if(korenPoddarvoNomer == -1 || kadeKolkoE < varhove[korenPoddarvoNomer].otKadeObhvashta || kadeKolkoE > varhove[korenPoddarvoNomer].doKadeObhvashta){
        return 0;
    }

    if(kadeKolkoE == varhove[korenPoddarvoNomer].otKadeObhvashta && kadeKolkoE == varhove[korenPoddarvoNomer].doKadeObhvashta){
        return varhove[korenPoddarvoNomer].lazyDelta;
    }

    int zaTuka = varhove[korenPoddarvoNomer].lazyDelta;

    zaTuka += querySuma(varhove[korenPoddarvoNomer].lqvoDeteNomer);
    zaTuka += querySuma(varhove[korenPoddarvoNomer].dqsnoDeteNomer);

    return zaTuka;
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove-1; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    cin>>broiTransportiraniq;

    for(int i = 0; i < broiTransportiraniq; i++){
        int otKade;
        int doKade;
        int pechalba;

        cin>>otKade>>doKade>>pechalba;

        transportiraniq[i] = {min(otKade, doKade), max(otKade, doKade), pechalba};
    }

    for(int i = 1; i <= broiVarhove; i++){
        if(sasedstvo[i].size() > 1){
            koren = i;
            break;
        }
    }

    nameriMomentite(koren, 0);

    nameriObhvashtaniqta(koren, 0);

    /*cout<<"korenat e "<<koren<<endl;

    for(int i = 1; i <= broiVarhove; i++){
        cout<<i<<" ot "<<kadeObhvashtaTozi[i].otKade<<" do "<<kadeObhvashtaTozi[i].doKade<<endl;
    }*/

    nameriOtsechkite();

    sort(otsechki.begin(), otsechki.end(), koqEPoNapred);

    /*for(int i = 0; i < (int)otsechki.size(); i++){
        cout<<otsechki[i].lqvKrai.x<<" "<<otsechki[i].lqvKrai.y<<"  "<<otsechki[i].desenKrai.x<<" "<<otsechki[i].desenKrai.y<<"  "<<otsechki[i].tip*otsechki[i].pechlb<<endl;
    }*/

    korenNomer = napraviDarvo(1, broiLista);

    int naiGolqmqPechalba = 0;
    int otKadeEPechalbata = 0;
    int doKadeEPechalbata = 0;

    for(int i = 0; i < (int)otsechki.size(); i++){
        update(korenNomer, otsechki[i].lqvKrai.x, otsechki[i].desenKrai.x, otsechki[i].tip*otsechki[i].pechlb);

        int tuka = query();

        //cout<<"v momenta e "<<tuka<<endl;

        if(tuka > naiGolqmqPechalba){
            naiGolqmqPechalba = tuka;
            //cout<<"SHE UPDATEVAME I SE NAMIRA MAXA V "<<varhove[koren].kadeEMaxa<<endl;
            otKadeEPechalbata = varhove[koren].kadeEMaxa;
            doKadeEPechalbata = otsechki[i].lqvKrai.y;
        }
    }

    cout<<originalnoKoiE[otKadeEPechalbata]<<" "<<originalnoKoiE[doKadeEPechalbata]<<" "<<naiGolqmqPechalba<<endl;

    return 0;
}
