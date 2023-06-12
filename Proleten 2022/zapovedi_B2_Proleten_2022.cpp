#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int broiZaqvki;

struct DanniZaZaqvka{
    int tip;
    int koqZapoved;
};

DanniZaZaqvka zaqvki[1000010];

int broiZapovedi;

int golqmKoren = 0;

vector<int> deca[1000010];
int bashta[1000010];

int momentNaVlizane[1000010];
int momentNaIzlizane[1000010];
int vreme;

void dfs(int segashenVrah){

    vreme++;
    momentNaVlizane[segashenVrah] = vreme;

    for(int i = 0; i < (int)deca[segashenVrah].size(); i++){
        dfs(deca[segashenVrah][i]);
    }

    vreme++;
    momentNaIzlizane[segashenVrah] = vreme;

}

struct DanniZaVarha{
    int stoinost;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVarha> varhove;
int korenNomer = -1;

int daiNovVrah(DanniZaVarha novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah({0, otKade, doKade, -1, -1});
    }

    int lqvoDete = napraviDarvo(otKade, (otKade + doKade)/2);
    int dqsnoDete = napraviDarvo((otKade + doKade)/2 + 1, doKade);

    return daiNovVrah({0, otKade, doKade, lqvoDete, dqsnoDete});
}

void update(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1 || varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade || otKade > doKade){
        return ;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        varhove[segashenVrah].stoinost++;
        return ;
    }

    update(varhove[segashenVrah].lqvoDete, otKade, doKade);
    update(varhove[segashenVrah].dqsnoDete, otKade, doKade);
}

int query(int segashenVrah, int koi){
    if(varhove[segashenVrah].otKadeObhvashta > koi || varhove[segashenVrah].doKadeObhvashta < koi){
        return 0;
    }

    if(koi == varhove[segashenVrah].otKadeObhvashta && koi == varhove[segashenVrah].doKadeObhvashta){
        return varhove[segashenVrah].stoinost;
    }

    return varhove[segashenVrah].stoinost + query(varhove[segashenVrah].lqvoDete, koi) + query(varhove[segashenVrah].dqsnoDete, koi);
}

vector<int> otgovori;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        char tip;
        cin>>tip;

        if(tip == '?'){
            int zaKoiPitame;
            cin>>zaKoiPitame;

            zaqvki[i] = {1, zaKoiPitame};
        }else{
            broiZapovedi++;

            zaqvki[i] = {2, broiZapovedi};

            int kolkoZakriva;

            cin>>kolkoZakriva;

            for(int j = 0; j < kolkoZakriva; j++){
                int zakrivana;
                cin>>zakrivana;

                deca[broiZapovedi].push_back(zakrivana);
                bashta[zakrivana] = broiZapovedi;
            }
        }

    }

    for(int i = 1; i <= broiZapovedi; i++){
        if(bashta[i] == 0){
            deca[golqmKoren].push_back(i);
        }
    }

    dfs(golqmKoren);

    korenNomer = napraviDarvo(0, vreme);

    for(int i = 0; i < broiZaqvki; i++){
        if(zaqvki[i].tip == 1){
            int kolkoETozi = query(korenNomer, momentNaVlizane[zaqvki[i].koqZapoved]);
            if(kolkoETozi%2 == 1){
                otgovori.push_back(0);
            }else{
                otgovori.push_back(1);
            }
        }else{
            update(korenNomer, momentNaVlizane[zaqvki[i].koqZapoved] + 1, momentNaIzlizane[zaqvki[i].koqZapoved] - 1);
        }
    }

    for(int i = 0; i < (int)otgovori.size(); i++){
        cout<<otgovori[i];
    }
    cout<<endl;

    return 0;
}
