#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaSaseda{
    int koiSased;
    int razstoqnie;
};

struct DanniZaKvartala{
    int nomerNaKvartala;
    int razstoqnieDoNego;

    DanniZaKvartala(int nomerNaKvartala, int razstoqnieDoNego)
        : nomerNaKvartala(nomerNaKvartala), razstoqnieDoNego(razstoqnieDoNego)
    {

    }
};

struct DanniZaKvartalaNaPetuk13{
    int nomerNaKvartala;
    int razstoqnieDoNego;
    int priOstatuci;

    DanniZaKvartalaNaPetuk13(int nomerNaKvartala, int razstoqnieDoNego, int priOstatuci)
        : nomerNaKvartala(nomerNaKvartala), razstoqnieDoNego(razstoqnieDoNego), priOstatuci(priOstatuci)
    {

    }
};

int broiPatuvaniq;

int broiKvartali;
int broiTransporti;

vector<DanniZaSaseda> sasedstvo[55];

string petuk13LiE;

int naiKasPat[55];
bool imameLiNaiKasPatDo[55];

void dijkstra(){
    for(int i = 1; i <= broiKvartali; i++){
        naiKasPat[i] = 1000000;
    }

    for(unsigned int i = 0; i < sasedstvo[1].size(); i++){
        naiKasPat[sasedstvo[1][i].koiSased] = min(sasedstvo[1][i].razstoqnie, naiKasPat[sasedstvo[1][i].koiSased]);
    }

    bool pravimLiNeshto = true;

    while(pravimLiNeshto == true){
        pravimLiNeshto = false;

        int naiKaso = 1000000;
        int doKoiENaiKasoto = -1;

        for(int i = 1; i <= broiKvartali; i++){
            if(naiKasPat[i] < naiKaso && imameLiNaiKasPatDo[i] == false){
                naiKaso = naiKasPat[i];
                doKoiENaiKasoto = i;
                pravimLiNeshto = true;
            }
        }

        if(pravimLiNeshto == true){
            imameLiNaiKasPatDo[doKoiENaiKasoto] = true;

            for(unsigned int i = 0; i < sasedstvo[doKoiENaiKasoto].size(); i++){
                if(imameLiNaiKasPatDo[sasedstvo[doKoiENaiKasoto][i].koiSased] == false &&
                   naiKasPat[sasedstvo[doKoiENaiKasoto][i].koiSased] >
                   naiKasPat[doKoiENaiKasoto] + sasedstvo[doKoiENaiKasoto][i].razstoqnie)
                {
                    naiKasPat[sasedstvo[doKoiENaiKasoto][i].koiSased] =
                    naiKasPat[doKoiENaiKasoto] + sasedstvo[doKoiENaiKasoto][i].razstoqnie;
                }
            }
        }

    }

}

int startovZaPetuk13;
int kraenZaPetuk13;

int broiVarhoveZaPetuk13;

vector<DanniZaSaseda> sasedstvoZaPetuk13[207000];

int naiKasPatZaPetuk13[207000];
bool imameLiNaiKasPatDozaPetuk13[207000];

void dijkstraZaPetuk13(){
    for(int i = 1; i <= broiVarhoveZaPetuk13; i++){
        naiKasPatZaPetuk13[i] = 1000000;
    }

    for(unsigned int i = 0; i < sasedstvoZaPetuk13[startovZaPetuk13].size(); i++){
        naiKasPatZaPetuk13[sasedstvoZaPetuk13[startovZaPetuk13][i].koiSased] =
            min(sasedstvoZaPetuk13[startovZaPetuk13][i].razstoqnie, naiKasPatZaPetuk13[sasedstvoZaPetuk13[startovZaPetuk13][i].koiSased]);
    }

    bool pravimLiNeshto = true;

    while(pravimLiNeshto == true){
        pravimLiNeshto = false;

        int naiKaso = 1000000;
        int doKoiENaiKasoto = -1;

        for(int i = 1; i <= broiVarhoveZaPetuk13; i++){
            if(naiKasPatZaPetuk13[i] < naiKaso && imameLiNaiKasPatDozaPetuk13[i] == false){
                naiKaso = naiKasPatZaPetuk13[i];
                doKoiENaiKasoto = i;
                pravimLiNeshto = true;
            }
        }

        if(pravimLiNeshto == true){
            imameLiNaiKasPatDozaPetuk13[doKoiENaiKasoto] = true;

            for(unsigned int i = 0; i < sasedstvoZaPetuk13[doKoiENaiKasoto].size(); i++){
                if(imameLiNaiKasPatDozaPetuk13[sasedstvoZaPetuk13[doKoiENaiKasoto][i].koiSased] == false &&
                   naiKasPatZaPetuk13[sasedstvoZaPetuk13[doKoiENaiKasoto][i].koiSased] >
                   naiKasPatZaPetuk13[doKoiENaiKasoto] + sasedstvoZaPetuk13[doKoiENaiKasoto][i].razstoqnie)
                {
                    naiKasPatZaPetuk13[sasedstvoZaPetuk13[doKoiENaiKasoto][i].koiSased] =
                    naiKasPatZaPetuk13[doKoiENaiKasoto] + sasedstvoZaPetuk13[doKoiENaiKasoto][i].razstoqnie;
                }
            }
        }

    }

}

void nulirane(){
    for(int i = 1; i <= broiKvartali; i++){
        sasedstvo[i].clear();
        naiKasPat[i] = 0;
        imameLiNaiKasPatDo[i] = false;
    }

    for(int i = 0; i <= broiVarhoveZaPetuk13; i++){
        sasedstvoZaPetuk13[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiPatuvaniq;

    for(int p = 0; p < broiPatuvaniq; p++){
        cin>>broiKvartali>>broiTransporti;

        for(int i = 0; i < broiTransporti; i++){
            int otKade;
            int doKade;
            int kolkoEDalgo;
            cin>>otKade>>doKade>>kolkoEDalgo;
            sasedstvo[otKade].push_back({doKade, kolkoEDalgo});
        }

        cin>>petuk13LiE;

        if(petuk13LiE == "False"){
            dijkstra();

            if(imameLiNaiKasPatDo[broiKvartali]){
                cout<<naiKasPat[broiKvartali]<<endl;
            }else{
                cout<<-1<<endl;
            }
        }else{
            dijkstraZaPetuk13();
        }

        nulirane();
    }

    return 0;
}
