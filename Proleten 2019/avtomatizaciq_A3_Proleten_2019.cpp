#include<iostream>
#include<vector>
using namespace std;

int nachalniStoinosti[300010];

struct DanniZaVarha{
    long long sumaVPoddarvo;
    long long lazyStoinost;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

//vector<DanniZaVarha> varhove;
DanniZaVarha varhove[600010];
int broiVarhove = 0;
int korenNomer = -1;

int daiNovVrah(DanniZaVarha novVrah){
    //varhove.push_back(novVrah);
    //return varhove.size() - 1;
    varhove[broiVarhove] = novVrah;
    broiVarhove++;
    return broiVarhove - 1;
}

void slojiStoinost(int vrah, long long stoinost){
    if(vrah != -1){
        varhove[vrah].lazyStoinost = stoinost;
        varhove[vrah].sumaVPoddarvo = stoinost*(varhove[vrah].doKadeObhvashta - varhove[vrah].otKadeObhvashta + 1);
    }
}

void pushValuEDown(int segashenVrah){
    if(segashenVrah == -1){
        return ;
    }

    if(varhove[segashenVrah].lazyStoinost != -1){

        slojiStoinost(varhove[segashenVrah].lqvoDete, varhove[segashenVrah].lazyStoinost);
        slojiStoinost(varhove[segashenVrah].dqsnoDete, varhove[segashenVrah].lazyStoinost);

        varhove[segashenVrah].lazyStoinost = -1;
    }
}

void tryPullValueUp(int segashenVrah){
    if(segashenVrah == -1 || varhove[segashenVrah].lqvoDete == -1 || varhove[segashenVrah].dqsnoDete == -1){
        return ;
    }

    if(varhove[varhove[segashenVrah].lqvoDete].lazyStoinost == varhove[varhove[segashenVrah].dqsnoDete].lazyStoinost && varhove[varhove[segashenVrah].lqvoDete].lazyStoinost != -1){
        slojiStoinost(segashenVrah, varhove[varhove[segashenVrah].lqvoDete].lazyStoinost);
    }
}

void recalc(int segashenVrah){

    if(varhove[segashenVrah].lazyStoinost != -1){
        varhove[segashenVrah].sumaVPoddarvo = varhove[segashenVrah].lazyStoinost*(varhove[segashenVrah].doKadeObhvashta - varhove[segashenVrah].otKadeObhvashta + 1);
    }else{
        if(varhove[segashenVrah].lqvoDete != -1 && varhove[segashenVrah].dqsnoDete != -1){
            varhove[segashenVrah].sumaVPoddarvo = varhove[varhove[segashenVrah].lqvoDete].sumaVPoddarvo + varhove[varhove[segashenVrah].dqsnoDete].sumaVPoddarvo;
        }else{
            varhove[segashenVrah].sumaVPoddarvo = 0;
        }
    }
}

int napraviDarvo(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah({nachalniStoinosti[otKade], nachalniStoinosti[otKade], otKade, doKade, -1, -1});
    }

    int lqvoDete = napraviDarvo(otKade, (otKade + doKade)/2);
    int dqsnoDete = napraviDarvo((otKade + doKade)/2 + 1, doKade);

    int tukaVrah = daiNovVrah({varhove[lqvoDete].sumaVPoddarvo + varhove[dqsnoDete].sumaVPoddarvo, -1, otKade, doKade, lqvoDete, dqsnoDete});

    tryPullValueUp(tukaVrah);
    recalc(tukaVrah);

    return tukaVrah;
}

void updateKonkretno(int segashenVrah, int otKade, int doKade, long long novaStoinost){
    if(segashenVrah == -1){
        return ;
    }

     if(varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return ;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){

        slojiStoinost(segashenVrah, novaStoinost);

        return ;
    }

    pushValuEDown(segashenVrah);

    updateKonkretno(varhove[segashenVrah].lqvoDete, otKade, doKade, novaStoinost);
    updateKonkretno(varhove[segashenVrah].dqsnoDete, otKade, doKade, novaStoinost);

    tryPullValueUp(segashenVrah);
    recalc(segashenVrah);
}

void updateDelenie(int segashenVrah, int otKade, int doKade, long long delenoNaKolko){
    if(segashenVrah == -1){
        return ;
    }

    if(varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return ;
    }

    if(varhove[segashenVrah].lazyStoinost != -1 && otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){

        slojiStoinost(segashenVrah, varhove[segashenVrah].lazyStoinost/delenoNaKolko);

        return ;
    }

    pushValuEDown(segashenVrah);

    updateDelenie(varhove[segashenVrah].lqvoDete, otKade, doKade, delenoNaKolko);
    updateDelenie(varhove[segashenVrah].dqsnoDete, otKade, doKade, delenoNaKolko);

    tryPullValueUp(segashenVrah);
    recalc(segashenVrah);
}

long long querySuma(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1){
        return 0;
    }

    if(varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return 0;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        return varhove[segashenVrah].sumaVPoddarvo;
    }

    if(varhove[segashenVrah].lazyStoinost != -1){
        int sechenie = min(varhove[segashenVrah].doKadeObhvashta, doKade) - max(varhove[segashenVrah].otKadeObhvashta, otKade) + 1;
        return sechenie*varhove[segashenVrah].lazyStoinost;  // todo int*long = int...
    }

    return querySuma(varhove[segashenVrah].lqvoDete, otKade, doKade) + querySuma(varhove[segashenVrah].dqsnoDete, otKade, doKade);
}

void init(int subtask, int N, const int A[]){
    for(int i = 0; i < N; i++){
        nachalniStoinosti[i] = A[i];
    }

    korenNomer = napraviDarvo(0, N - 1);

    /*for(int i = 0; i < (int)varhove.size(); i++){
        cout<<i<<" obhvashta ot "<<varhove[i].otKadeObhvashta<<" do "<<varhove[i].doKadeObhvashta<<" stoinostta e "<<varhove[i].sumaVPoddarvo;
        cout<<" lazy stoinost "<<varhove[i].lazyStoinost<<" lqvoto dete "<<varhove[i].lqvoDete<<" dqsno dete "<<varhove[i].dqsnoDete<<endl;
    }
    cout<<endl;*/
}

long long getSum(int L, int R){
    return querySuma(korenNomer, L, R);
}

void setValues(int L, int R, int K){
    updateKonkretno(korenNomer, L, R, K);
    /*for(int i = 0; i < (int)varhove.size(); i++){
        cout<<i<<" obhvashta ot "<<varhove[i].otKadeObhvashta<<" do "<<varhove[i].doKadeObhvashta<<" stoinostta e "<<varhove[i].sumaVPoddarvo;
        cout<<" lazy stoinost "<<varhove[i].lazyStoinost<<" lqvoto dete "<<varhove[i].lqvoDete<<" dqsno dete "<<varhove[i].dqsnoDete<<endl;
    }
    cout<<endl;*/
}

void divideValues(int L, int R, int K){
    updateDelenie(korenNomer, L, R, K);
    /*for(int i = 0; i < (int)varhove.size(); i++){
        cout<<i<<" obhvashta ot "<<varhove[i].otKadeObhvashta<<" do "<<varhove[i].doKadeObhvashta<<" stoinostta e "<<varhove[i].sumaVPoddarvo;
        cout<<" lazy stoinost "<<varhove[i].lazyStoinost<<" lqvoto dete "<<varhove[i].lqvoDete<<" dqsno dete "<<varhove[i].dqsnoDete<<endl;
    }
    cout<<endl;*/
}
