#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int broiVarhove;

struct DanniZaSaseda{
    int doKoi;
    long long daljina;
};

vector<DanniZaSaseda> sasedstvo[100010];

int broiVPoddarvotoNa[100010];

long long daljinaNadoluSToziNach[100010];

long long daljinaNadoluToziSreden[100010];

long long daljinaNagoreKraen[100010];

long long daljinaNagoreSreden[100010];

long long dfsBroiVPoddarv(int segashenVrah, int otKadeIdvame){

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i].doKoi != otKadeIdvame){
            broiVPoddarvotoNa[segashenVrah] += dfsBroiVPoddarv(sasedstvo[segashenVrah][i].doKoi, segashenVrah);
        }
    }

    broiVPoddarvotoNa[segashenVrah]++;

    return broiVPoddarvotoNa[segashenVrah];
}

long long dfsNadoluNach(int segashenVrah, int otKadeIdvame){

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i].doKoi != otKadeIdvame){
            daljinaNadoluSToziNach[segashenVrah] +=
                sasedstvo[segashenVrah][i].daljina*broiVPoddarvotoNa[sasedstvo[segashenVrah][i].doKoi] + dfsNadoluNach(sasedstvo[segashenVrah][i].doKoi, segashenVrah);
            daljinaNadoluToziSreden[segashenVrah] +=
                (daljinaNadoluSToziNach[sasedstvo[segashenVrah][i].doKoi] + sasedstvo[segashenVrah][i].daljina*broiVPoddarvotoNa[sasedstvo[segashenVrah][i].doKoi])*
                (broiVPoddarvotoNa[segashenVrah] - broiVPoddarvotoNa[sasedstvo[segashenVrah][i].doKoi] - 1);
        }
    }

    return daljinaNadoluSToziNach[segashenVrah];
}

void dfsNadoluSred(int segashenVrah, int otKadeIdvame){

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i].doKoi != otKadeIdvame){
            daljinaNadoluToziSreden[segashenVrah] +=
                (daljinaNadoluSToziNach[sasedstvo[segashenVrah][i].doKoi] + sasedstvo[segashenVrah][i].daljina*broiVPoddarvotoNa[sasedstvo[segashenVrah][i].doKoi])*
                (broiVPoddarvotoNa[segashenVrah] - broiVPoddarvotoNa[sasedstvo[segashenVrah][i].doKoi] - 1);
            dfsNadoluSred(sasedstvo[segashenVrah][i].doKoi, segashenVrah);
        }
    }
}

void dfsNagoreKrai(int segashenVrah, int otKadeIdvame, long long rebroto){

    if(segashenVrah != 1){
        daljinaNagoreKraen[segashenVrah] =
            daljinaNagoreKraen[otKadeIdvame] +
            (broiVPoddarvotoNa[otKadeIdvame] - broiVPoddarvotoNa[segashenVrah] - 1)*rebroto +
            (broiVarhove - broiVPoddarvotoNa[otKadeIdvame])*rebroto +
            daljinaNadoluSToziNach[otKadeIdvame] -
            broiVPoddarvotoNa[segashenVrah]*rebroto -
            daljinaNadoluSToziNach[segashenVrah] +
            rebroto;
    }

    daljinaNagoreSreden[segashenVrah] =
        daljinaNadoluSToziNach[segashenVrah]*(broiVarhove - broiVPoddarvotoNa[segashenVrah]) +
        daljinaNagoreKraen[segashenVrah]*(broiVPoddarvotoNa[segashenVrah] - 1);

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i].doKoi != otKadeIdvame){
            dfsNagoreKrai(sasedstvo[segashenVrah][i].doKoi, segashenVrah, sasedstvo[segashenVrah][i].daljina);
        }
    }

}

void dfsNagoreSreda(int segashenVrah, int otKadeIdvame){

    daljinaNagoreSreden[segashenVrah] =
        daljinaNadoluSToziNach[segashenVrah]*(broiVarhove - broiVPoddarvotoNa[segashenVrah]) +
        daljinaNagoreKraen[segashenVrah]*(broiVPoddarvotoNa[segashenVrah] - 1);

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i].doKoi != otKadeIdvame){
            dfsNagoreSreda(sasedstvo[segashenVrah][i].doKoi, segashenVrah);
        }
    }

}

int main(){

    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove;*/

    scanf("%i", &broiVarhove);

    for(int i = 0; i < broiVarhove - 1; i++){
        int otKade;
        int doKade;
        long long daljinaRebro;

        //cin>>otKade>>doKade>>daljinaRebro;

        scanf("%i %i %ld", &otKade, &doKade, &daljinaRebro);

        sasedstvo[otKade].push_back({doKade, daljinaRebro});
        sasedstvo[doKade].push_back({otKade, daljinaRebro});
    }

    dfsBroiVPoddarv(1, 0);

    dfsNadoluNach(1, 0);

    //dfsNadoluSred(1, 0);

    dfsNagoreKrai(1, 0, 0);

    //dfsNagoreSreda(1, 0);

    for(int i = 1; i <= broiVarhove; i++){
        //cout<<i<<" "<<daljinaNadoluSToziNach[i]<<" i sreden "<<daljinaNadoluToziSreden[i]<<" ako e krai "<<daljinaNagoreKraen[i]<<" ako e nagore sreda ";
        //cout<<daljinaNagoreSreden[i]<<endl;
        //cout<<daljinaNadoluSToziNach[i] + daljinaNadoluToziSreden[i] + daljinaNagoreKraen[i] + daljinaNagoreSreden[i]<<endl;
        printf("%ld \n", daljinaNadoluSToziNach[i] + daljinaNadoluToziSreden[i] + daljinaNagoreKraen[i] + daljinaNagoreSreden[i]);
    }

    return 0;
}
