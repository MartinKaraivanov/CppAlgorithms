#include<iostream>
#include<vector>
using namespace std;

int broiHora;
int daljinaReklama;

struct DanniZaPoseshtenie{
    int momentVlizane;
    int momentIzlizane;
};

DanniZaPoseshtenie hora[3000010];

int naiGolqmMoment = 0;
int naiMalakMoment = 100000001;

struct DanniZaVarha{
    int maximalno;
    int lazyDelta;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVarha> varhove;
int koreNomer = -1;

int daiNovVrah(DanniZaVarha novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah({0, 0, otKade, doKade, -1, -1});
    }

    int lqvoDete = napraviDarvo(otKade, (otKade + doKade)/2);
    int dqsnoDete = napraviDarvo((otKade + doKade)/2 + 1, doKade);

    return daiNovVrah({0, 0, otKade, doKade, lqvoDete, dqsnoDete});
}



int main(){

    cin>>broiHora>>daljinaReklama;

    for(int i = 0; i < broiHora; i++){
        cin>>hora[i].momentVlizane>>hora[i].momentIzlizane;
        naiMalakMoment = min(naiMalakMoment, hora[i].momentVlizane);
        naiGolqmMoment = max(naiGolqmMoment, hora[i].momentIzlizane);
    }

    koreNomer = napraviDarvo(naiMalakMoment, naiGolqmMoment);

    int nai

    for(int i = 0; i < broiHora; i++){

    }

    return 0;
}
