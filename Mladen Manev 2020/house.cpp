#include<iostream>
#include<vector>
#include<queue>
#include "house.h"
using namespace std;

int get_neighbour(int v);

void submit_house(int h);

vector<int> sasedstvo[600010];

int roditel[600010];
//int dalbochina[600010];
//int naiGolqmataDalbochinaNaPoddarvotoSKoren[600010];

int kolkoSaVarhoveteNadoluSNego[600010];
bool zadraskanLiE[600010];

void zaRoditel(int vrah, int parent){
    roditel[vrah] = parent;

    for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
        if(sasedstvo[vrah][i] != roditel[vrah] && zadraskanLiE[sasedstvo[vrah][i]] == false){
            zaRoditel(sasedstvo[vrah][i], vrah);
        }
    }
}

int izchislqvaneNaVarhoveteNadolu(int vrah){
    int broiZaTozi = 1;

    for(int i = 0; i < sasedstvo[vrah].size(); i++){
        if(sasedstvo[vrah][i] != roditel[vrah] && zadraskanLiE[sasedstvo[vrah][i]] == false){
            broiZaTozi += izchislqvaneNaVarhoveteNadolu(sasedstvo[vrah][i]);
        }
    }

    kolkoSaVarhoveteNadoluSNego[vrah] = broiZaTozi;

    return broiZaTozi;
}

int namiraneNaCentroid(int vrah, int n){

    bool centroidLiE = true;
    int naiGolqmaStoinost = 0;
    int naiGolqmotoMuDete = 0;

    for(int i = 0; i < sasedstvo[vrah].size(); i++){
        if(zadraskanLiE[sasedstvo[vrah][i]]){
            continue;
        }
        int broiZaTozi;

        //cout<<vrah<<" "<<sasedstvo[vrah][i]<<endl;

        if(sasedstvo[vrah][i] == roditel[vrah]){
            broiZaTozi = n - kolkoSaVarhoveteNadoluSNego[vrah];
        }else{
            broiZaTozi = kolkoSaVarhoveteNadoluSNego[sasedstvo[vrah][i]];
        }

        if(broiZaTozi > naiGolqmaStoinost){
            naiGolqmaStoinost = broiZaTozi;
            naiGolqmotoMuDete = sasedstvo[vrah][i];
        }

        if(broiZaTozi > n/2){
            centroidLiE = false;
            break;
        }else{

        }
    }

    int centroid;

    if(centroidLiE){
        centroid = vrah;
    }else{
        centroid = namiraneNaCentroid(naiGolqmotoMuDete, n);
    }

    return centroid;
}

/*void zaDalbochina(int vrah, int depth){
    dalbochina[vrah] = depth;

    for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
        if(roditel[vrah] != sasedstvo[vrah][i]){
            zaDalbochina(sasedstvo[vrah][i], depth + 1);
        }
    }

}

int koqENaiGolqmtaDalbochinaVPoddarvoto(int vrah){
    int naiGolqmataD = -1;

    for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
        if(roditel[vrah] != sasedstvo[vrah][i]){
            naiGolqmataD = max(naiGolqmataD, koqENaiGolqmtaDalbochinaVPoddarvoto(sasedstvo[vrah][i]));
        }
    }

    if(naiGolqmataD == -1){
        naiGolqmataD = dalbochina[vrah];
    }

    naiGolqmataDalbochinaNaPoddarvotoSKoren[vrah] = naiGolqmataD;

    return naiGolqmataD;
}

int nomerNaVarhaSDalbochinaPriBezDolen(int vrah, int dalbochinaKoqtoTarsim){
    if(dalbochina[vrah] == dalbochinaKoqtoTarsim){
        return vrah;
    }

    int nomerNaVarha = vrah;  // ???

    for(int i = 0; i < sasedstvo[vrah].size(); i++){
        if(sasedstvo[vrah][i] != roditel[vrah]){
            nomerNaVarha = nomerNaVarhaSDalbochinaPriBezDolen(sasedstvo[vrah][i], dalbochinaKoqtoTarsim);
            if(nomerNaVarha != 0){
                break;
            }
        }
    }

    return nomerNaVarha;
}

int nomerAkoImaVrahDolen(int vrah, int dalbochinaKoqtoTarsim){
    int nomerHubav = vrah;

    for(int i = vrah; i != -1; vrah = roditel[vrah]){
        if(dalbochina[i] == dalbochinaKoqtoTarsim){
            nomerHubav = i;
            break;
        }
    }

    return nomerHubav;
}

bool vEdnoPoddarvoLiSa(int koren, int dolen, int zaTarsen){
    for(int i = dolen; i != koren; i = roditel[i]){
        if(i == zaTarsen){
            return true;
        }
    }
    return false;
}*/

void play(int n, vector<pair<int, int>> e){

    for(unsigned int i = 0; i < e.size(); i++){
        sasedstvo[e[i].first].push_back(e[i].second);
        sasedstvo[e[i].second].push_back(e[i].first);
    }

    /*for(int i = 1; i <= n; i++){
        cout<<i<<": "<<endl;
        for(int j : sasedstvo[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/

    int koren = 1;

    zaRoditel(koren, -1);

    izchislqvaneNaVarhoveteNadolu(koren);

    /*for(int i = 1; i <= n; i++){
        cout<<i<<" "<<kolkoSaVarhoveteNadoluSNego[i]<<endl;
    }*/

    int hubavaKashta = -1;

    while(kolkoSaVarhoveteNadoluSNego[koren] > 1){
        int centroid = namiraneNaCentroid(koren, kolkoSaVarhoveteNadoluSNego[koren]);

        int poDobar = get_neighbour(centroid);

        if(poDobar == -1){
            hubavaKashta = centroid;
            break;
        }

        zadraskanLiE[centroid] = true;
        koren = poDobar;
        zaRoditel(koren, -1);
        izchislqvaneNaVarhoveteNadolu(koren);
    }

    if(hubavaKashta == -1){
        hubavaKashta = koren;
    }

    for(int i = 0; i <= n; i++){
        sasedstvo[i].clear();
        zadraskanLiE[i] = false;
        kolkoSaVarhoveteNadoluSNego[i] = 0;
    }

    submit_house(hubavaKashta);

    /*int koren = 1;

    for(int i = 1; i <= n; i++){
        if(sasedstvo[i].size() > 1){
            koren = i;
            break;
        }
    }

    zaRoditel(koren, -1);
    zaDalbochina(koren, 0);
    koqENaiGolqmtaDalbochinaVPoddarvoto(koren);

    int gorenVrah = koren;
    int dolenVrah = -1;

    int gornaDalbochina = dalbochina[gorenVrah];
    int dolnaDalbochina = naiGolqmataDalbochinaNaPoddarvotoSKoren[gorenVrah];

    int hubavaKashta = -1;

    //cout<<"predi dvoichnotoTarsen"<<endl;

    while(dolnaDalbochina > gornaDalbochina){
        int srednaStoinost = (gornaDalbochina + dolnaDalbochina)/2;

        int sredenVrah;

        //cout<<gorenVrah<<" "<<dolenVrah<<endl;

        if(dolenVrah == -1){
            sredenVrah = nomerNaVarhaSDalbochinaPriBezDolen(gorenVrah, srednaStoinost);
        }else{
            sredenVrah = nomerAkoImaVrahDolen(dolenVrah, srednaStoinost);
        }

        int novVrah = get_neighbour(sredenVrah);

        //cout<<novVrah<<endl;

        if(novVrah == -1){
            hubavaKashta = sredenVrah;
            break;
        }

        if(dalbochina[novVrah] < dalbochina[sredenVrah]){
            dolenVrah = novVrah;
            dolnaDalbochina = dalbochina[dolenVrah];
        }else{
            gorenVrah = novVrah;
            gornaDalbochina = dalbochina[gorenVrah];
            if(dolenVrah == -1){
                dolnaDalbochina = naiGolqmataDalbochinaNaPoddarvotoSKoren[gorenVrah];
            }else{
                if(vEdnoPoddarvoLiSa(sredenVrah, dolenVrah, novVrah)){

                }else{
                    dolenVrah = -1;
                    dolnaDalbochina = naiGolqmataDalbochinaNaPoddarvotoSKoren[gorenVrah];
                }
            }
        }

    }
    if(hubavaKashta == -1){
        hubavaKashta = gorenVrah;
    }

    for(int i = 0; i <= n; i++){
        sasedstvo[i].clear();
    }

    submit_house(hubavaKashta);*/

    /*int dobraKashta = 0;
    int segashnaKushta = 1;
    int predishna = 0;

    while(segashnaKushta != -1){
        predishna = segashnaKushta;
        segashnaKushta = get_neighbour(segashnaKushta);
    }

    dobraKashta = predishna;

    submit_house(dobraKashta);*/
}
