#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaMqstoto{
    int x;
    int y;
    int hod;
};

struct Coordinati{
    int x;
    int y;
};

struct DanniZaZadacha{
    Coordinati c;
    int vremeZaIzpalnenie;
};

struct DanniZaSaseda{
    int doKoi;
    int razstoqnie;

    DanniZaSaseda(int doKoi, int razstoqnie)
        : doKoi(doKoi), razstoqnie(razstoqnie)
    {

    }
};

struct DoKoiEPoMalkoRazst{
    bool operator()(DanniZaSaseda const& a, DanniZaSaseda const& b)
    {
        return a.razstoqnie > b.razstoqnie;
    }
};

int broiOtbori;
int broiZadachiZaIzpal;

Coordinati startove[600];
Coordinati finaal;

int broiVazmozhniZad;

Coordinati mqstoNaZadachite[600];
int neobhodimoVreme[600];

int nomerche;

vector<DanniZaSaseda> sasedstvo[6000];

DanniZaZadacha zadachi[600];

int nomercheZaStartvoto[550];

int daiNomercheZaStartovoto(int nomerNaStartovot){
    if(nomercheZaStartvoto[nomerNaStartovot] > 0){
        return nomercheZaStartvoto[nomerNaStartovot];
    }

    nomerche++;
    nomercheZaStartvoto[nomerNaStartovot] = nomerche;
    return nomerche;
}

int nomercheZaZadachata[550][15];

int daiNomercheZaZadachata(int nomerceNaZad, int red){
    if(nomercheZaZadachata[nomerceNaZad][red] > 0){
        return nomercheZaZadachata[nomerceNaZad][red];
    }
    nomerche++;
    nomercheZaZadachata[nomerceNaZad][red] = nomerche;
    return nomerche;
}

int nomercheNaFinala;

int daiNomercheZaFinala(){
    if(nomercheNaFinala > 0){
        return nomercheNaFinala;
    }
    nomerche++;
    nomercheNaFinala = nomerche;
    return nomerche;
}

int razstoqnietoMezhduDveteTochki(Coordinati a, Coordinati b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void praveneNaSasedstvoto(){
    for(int i = 0; i < broiOtbori; i++){
        int nomercheNaNashiq = daiNomercheZaStartovoto(i);
        for(int j = 0; j < broiVazmozhniZad; j++){
            int nomercheNaZadachata = daiNomercheZaZadachata(j, 1);
            DanniZaSaseda zaDob = {nomercheNaNashiq, razstoqnietoMezhduDveteTochki(startove[i], zadachi[j].c) +
                    zadachi[j].vremeZaIzpalnenie};
            sasedstvo[nomercheNaZadachata].push_back(zaDob);
        }
    }

    for(int z = 1; z < broiZadachiZaIzpal; z++){
        for(int i = 0; i < broiVazmozhniZad; i++){
            for(int j = 0; j < broiVazmozhniZad; j++){
                if(j == i){
                    continue;
                }

                int nomercheNaParvata = daiNomercheZaZadachata(i, z);
                int nomercheNaVtorata = daiNomercheZaZadachata(j, z + 1);

                DanniZaSaseda zaDob = {nomercheNaParvata,
                    razstoqnietoMezhduDveteTochki(zadachi[i].c, zadachi[j].c) + zadachi[j].vremeZaIzpalnenie};

                sasedstvo[nomercheNaVtorata].push_back(zaDob);

            }
        }
    }

    for(int i = 0; i < broiVazmozhniZad; i++){
        int nomercheNaZad = daiNomercheZaZadachata(i, broiZadachiZaIzpal);

        int nomercheFinal = daiNomercheZaFinala();

        DanniZaSaseda zaDob = {nomercheNaZad, razstoqnietoMezhduDveteTochki(zadachi[i].c, finaal)};

        sasedstvo[nomercheFinal].push_back(zaDob);

    }

}

int naiKasPat[6000];
bool imameLiNaiKasPatDo[6000];

void deikstra(){
    for(int i = 0; i < nomerche; i++){
        naiKasPat[i] = 10000000;
    }

    for(unsigned int i = 0; i < sasedstvo[nomercheNaFinala].size(); i++){
        naiKasPat[sasedstvo[nomercheNaFinala][i].doKoi] = sasedstvo[nomercheNaFinala][i].razstoqnie;
    }

    imameLiNaiKasPatDo[nomercheNaFinala] = true;

    bool pravimLiNeshto = true;

    while(pravimLiNeshto == true){
        pravimLiNeshto = false;

        int naiKaso = 10000000;
        int doKoIENaiKasoto;

        for(int i = 0; i < nomerche; i++){
            if(naiKasPat[i] < naiKaso && imameLiNaiKasPatDo[i] == false){
                naiKaso = naiKasPat[i];
                doKoIENaiKasoto = i;
                pravimLiNeshto = true;
            }
        }

        if(pravimLiNeshto == true){
            imameLiNaiKasPatDo[doKoIENaiKasoto] = true;

            for(unsigned int i = 0; i < sasedstvo[doKoIENaiKasoto].size(); i++){
                if(imameLiNaiKasPatDo[sasedstvo[doKoIENaiKasoto][i].doKoi] == false &&
                   naiKasPat[sasedstvo[doKoIENaiKasoto][i].doKoi] >
                   naiKasPat[doKoIENaiKasoto] + sasedstvo[doKoIENaiKasoto][i].razstoqnie)
                {
                    naiKasPat[sasedstvo[doKoIENaiKasoto][i].doKoi] =
                   naiKasPat[doKoIENaiKasoto] + sasedstvo[doKoIENaiKasoto][i].razstoqnie;
                }
            }

        }

    }

}

void sPrioritetnaOpashka(){
    priority_queue<DanniZaSaseda, vector<DanniZaSaseda>, DoKoiEPoMalkoRazst> q;

    int broiNamereni = 0;

    q.push({nomercheNaFinala, 0});

    while(q.empty() == false){
        DanniZaSaseda naiOtgore = q.top();
        q.pop();

        if(imameLiNaiKasPatDo[naiOtgore.doKoi] == true){
            continue;
        }

        naiKasPat[naiOtgore.doKoi] = naiOtgore.razstoqnie;
        imameLiNaiKasPatDo[naiOtgore.doKoi] = true;
        broiNamereni++;

        if(broiNamereni == nomerche){
            break;
        }

        for(unsigned int i = 0; i < sasedstvo[naiOtgore.doKoi].size(); i++){
            if(imameLiNaiKasPatDo[sasedstvo[naiOtgore.doKoi][i].doKoi] == false){
                q.push({sasedstvo[naiOtgore.doKoi][i].doKoi, naiOtgore.razstoqnie + sasedstvo[naiOtgore.doKoi][i].razstoqnie});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOtbori>>broiZadachiZaIzpal;

    for(int i = 0; i < broiOtbori; i++){
        int x;
        int y;
        cin>>x>>y;
        startove[i] = {x, y};
    }

    cin>>broiVazmozhniZad;

    for(int i = 0; i < broiVazmozhniZad; i++){
        int x;
        int y;
        int zaVreme;
        cin>>x>>y>>zaVreme;
        zadachi[i] = {x, y, zaVreme};
    }

    cin>>finaal.x>>finaal.y;

    praveneNaSasedstvoto();
    deikstra();
    //sPrioritetnaOpashka();

    /*for(int i = 0; i <= nomerche; i++){
        for(int j = 0; j <= nomerche; j++){
            if(sasedstvo[i][j] > 0){
                cout<<i<<" "<<j<<" "<<sasedstvo[i][j]<<endl;//<<b.x<<" "<<b.y<<" "<<b.hod<<endl<<sasedstvo[i][j]<<endl<<endl;
            }
        }
    }*/

    for(int i = 0; i < broiOtbori; i++){
        int nomercheNaOtbora = daiNomercheZaStartovoto(i);
        cout<<naiKasPat[nomercheNaOtbora]<<endl;
    }

    return 0;
}
