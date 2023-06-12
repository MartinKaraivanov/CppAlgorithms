#include<iostream>
#include<vector>
using namespace std;

int broiPloshtadi;
int broiUlici;

struct DanniZaSaseda{
    int doKade;
    int nomerRebro;
};

vector<DanniZaSaseda> sasedi[50010];

struct DanniZaRebro{
    int otKade;
    int doKade;
};

DanniZaRebro rebra[100010];

int stepenNaPloshtad[50010];

bool visitedRebra[100010];

vector<DanniZaRebro> redObhojdanerebra;

void dfs(int segashenPloshtad, int otKadeIdvame, int rebroIdvane){

    visitedRebra[rebroIdvane] = true;

    redObhojdanerebra.push_back({otKadeIdvame, segashenPloshtad});

    for(int i = 0; i < (int)sasedi[segashenPloshtad].size(); i++){
        if(visitedRebra){
            dfs(sasedi[segashenPloshtad][i].doKade, sasedi[segashenPloshtad][i].nomerRebro);
        }
    }

}

int main(){

    cin>>broiPloshtadi>>broiUlici;

    for(int i = 1; i <= broiUlici; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedi[otKade].push_back({doKade, i});
        sasedi[doKade].push_back({otKade, i});

        rebra[i] = {otKade, doKade};

        stepenNaPloshtad[otKade]++;
        stepenNaPloshtad[doKade]++;
    }

    bool mojeLiEdnoposochni = true;

    for(int i = 1; i <= broiPloshtadi; i++){
        if(stepenNaPloshtad[i] < 2){
            mojeLiEdnoposochni = false;
        }
    }

    if(mojeLiEdnoposochni == false){
        cout<<0<<endl;
        return 0;
    }

    cout<<1<<endl;

    return 0;
}
