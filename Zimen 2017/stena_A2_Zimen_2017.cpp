#include<iostream>
#include<vector>
using namespace std;

int daljinaStena;

bool prostiqSluchaiLiE;

long long prostaVisochina[10010];
long long maxProstaVisochina[10010];

struct DanniZaVarha{
    long long segashnaStoinost;
    long long maximalnaStoinost;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDeteNomer;
    int dqsnoDeteNomer;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(DanniZaVarha novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int postroiDarvo(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah({0, 0, otKade, doKade, -1, -1});
    }

    int lqvoDete = postroiDarvo(otKade, (otKade + doKade)/2);
    int dqsnoDete = postroiDarvo((otKade + doKade)/2 + 1, doKade);

    return daiNovVrah({0, 0, otKade, doKade, lqvoDete, dqsnoDete});
}

void update(int segashenVrah, int otKade, int doKade, int sKolko){
    if(segashenVrah == -1 || varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return ;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        varhove[segashenVrah].segashnaStoinost += sKolko;
        varhove[segashenVrah].maximalnaStoinost = max(varhove[segashenVrah].maximalnaStoinost, varhove[segashenVrah].segashnaStoinost);
        return ;
    }

    update(varhove[segashenVrah].lqvoDeteNomer, otKade, doKade, sKolko);
    update(varhove[segashenVrah].dqsnoDeteNomer, otKade, doKade, sKolko);
}

long long query(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1 || varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return 0;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        return varhove[segashenVrah].maximalnaStoinost;
    }

    long long nadolu = max(query(varhove[segashenVrah].lqvoDeteNomer, otKade, doKade), query(varhove[segashenVrah].dqsnoDeteNomer, otKade, doKade));

    return varhove[segashenVrah].maximalnaStoinost + nadolu;
}

void init(int N)
{
    daljinaStena = N;

    if(N <= 10000){
        prostiqSluchaiLiE = true;
    }

    if(prostiqSluchaiLiE == false){
        korenNomer = postroiDarvo(0, N - 1);
    }
}

void change_wall(int L, int R, int dh)
{

    L--;
    R--;

    if(prostiqSluchaiLiE == true){
        for(int i = L; i <= R; i++){
            prostaVisochina[i] += dh;
            maxProstaVisochina[i] = max(maxProstaVisochina[i], prostaVisochina[i]);
        }
    }else{
        update(korenNomer, L, R, dh);
    }
}

long long get_wall_h(int L, int R)
{

    L--;
    R--;

    if(prostiqSluchaiLiE == true){
        long long maximalnoto = 0;

        for(int i = L; i <= R; i++){
            maximalnoto = max(maximalnoto, maxProstaVisochina[i]);
        }

        return maximalnoto;
    }else{
        return query(korenNomer, L, R);
    }
}
