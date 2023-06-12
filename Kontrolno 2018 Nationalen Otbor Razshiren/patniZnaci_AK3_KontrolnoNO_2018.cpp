#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int broiZnaci;

int toziKadeNalqvo[100010];
int toziKadeNadqsno[100010];

vector<int> tochki;

vector<int> otKoiZnaci[4000010];

int daiMqsto(int ot){
    return ot + 2000000;
}

int broiOtTazi[4000010];
int kolkoImatTakavPopular[100010];

bool promeneneLiE[4000010];

void dobaviZnak(int poziciq){
    promeneneLiE[poziciq] = false;
    kolkoImatTakavPopular[broiOtTazi[poziciq]]--;
    broiOtTazi[poziciq]++;
    kolkoImatTakavPopular[broiOtTazi[poziciq]]++;
}

void mahniZnak(int poziciq){
    promeneneLiE[poziciq] = true;
    kolkoImatTakavPopular[broiOtTazi[poziciq]]--;
    broiOtTazi[poziciq]--;
    kolkoImatTakavPopular[broiOtTazi[poziciq]]++;
}

struct DanniZaTochka{
    int popularnost;
    int tochka;
};

bool koqEPoNapred(DanniZaTochka a, DanniZaTochka b){
    return a.popularnost > b.popularnost;
}

int main(){

    cin>>broiZnaci;

    for(int i = 0; i < broiZnaci; i++){
        int kadeE;
        int nalqvo;
        int nadqsno;

        cin>>kadeE>>nalqvo>>nadqsno;

        int lqva = daiMqsto(kadeE - nalqvo);
        int dqsna = daiMqsto(kadeE + nadqsno);

        toziKadeNalqvo[i] = lqva;
        toziKadeNadqsno[i] = dqsna;

        tochki.push_back(lqva);
        tochki.push_back(dqsna);

        otKoiZnaci[lqva].push_back(i);
        otKoiZnaci[dqsna].push_back(i);

        dobaviZnak(lqva);
        dobaviZnak(dqsna);
    }

    vector<DanniZaTochka> poPopularnosti;

    for(int i = 0; i <= 4000000; i++){
        if(broiOtTazi[i] > 0){
            poPopularnosti.push_back({broiOtTazi[i], i});
        }
    }

    sort(poPopularnosti.begin(), poPopularnosti.end(), koqEPoNapred);

    sort(tochki.begin(), tochki.end());
    tochki.resize(unique(tochki.begin(), tochki.end()) - tochki.begin());

    int naiMnogoto = 0;
    long long broiDvoiki = 0;

    for(int i = 0; i < (int)tochki.size(); i++){
        int tekushtaTochka = tochki[i];

        for(int j = 0; j < (int)otKoiZnaci[tekushtaTochka].size(); j++){
            mahniZnak(toziKadeNalqvo[otKoiZnaci[tekushtaTochka][j]]);
            mahniZnak(toziKadeNadqsno[otKoiZnaci[tekushtaTochka][j]]);
        }

        int zaTukaNaiMn = 0;

        for(int j = 0; j < (int)poPopularnosti.size(); j++){
            int drugaTochka = poPopularnosti[j].tochka;

            if(tekushtaTochka != drugaTochka){
                zaTukaNaiMn = max(zaTukaNaiMn, broiOtTazi[drugaTochka]);
                if(promeneneLiE[drugaTochka] == false){
                    break;
                }
            }
        }

        int znaciTuka = otKoiZnaci[tekushtaTochka].size() + zaTukaNaiMn;
        long long tukaDvoiki = 1;
        if(zaTukaNaiMn > 0){
            tukaDvoiki = kolkoImatTakavPopular[zaTukaNaiMn];
        }

        if(znaciTuka > naiMnogoto){
            naiMnogoto = znaciTuka;
            broiDvoiki = tukaDvoiki;
        }else{
            if(znaciTuka == naiMnogoto){
                broiDvoiki += tukaDvoiki;
            }
        }

        for(int j = 0; j < (int)otKoiZnaci[tekushtaTochka].size(); j++){
            dobaviZnak(toziKadeNalqvo[otKoiZnaci[tekushtaTochka][j]]);
            dobaviZnak(toziKadeNadqsno[otKoiZnaci[tekushtaTochka][j]]);
        }
    }

    cout<<naiMnogoto<<" "<<broiDvoiki/2<<endl;

    return 0;
}
