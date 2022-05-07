#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int broiGradove;
int broiEkskurzii;

vector<int> sasedstvo[50010];

int broiPutiPreminatoPrezNego[50010];

int broiPutiToziELCA[50010];
int broiPutiToziENachalen[50010];

int dalbochina[50010];
bool visited[50010];
int parvoPoseshtenie[50010];

vector<int> eulerovoPoseshtenie;

int darvo[500010];

void dfs(int segashenVrah, int dalb){
    visited[segashenVrah] = true;
    dalbochina[segashenVrah] = dalb;
    parvoPoseshtenie[segashenVrah] = eulerovoPoseshtenie.size();
    eulerovoPoseshtenie.push_back(segashenVrah);

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        int sledvasht = sasedstvo[segashenVrah][i];
        if(visited[sledvasht] == false){
            dfs(sledvasht, dalb + 1);
            eulerovoPoseshtenie.push_back(segashenVrah);
        }
    }
}

void postroiDarvoto(int segashenVrah, int otKade, int doKade){
    if(otKade == doKade){
        darvo[segashenVrah] = eulerovoPoseshtenie[otKade];
        return ;
    }

    int sredata = (otKade + doKade)/2;

    postroiDarvoto(segashenVrah*2, otKade, sredata);
    postroiDarvoto(segashenVrah*2 + 1, sredata + 1, doKade);

    int lqvo = darvo[segashenVrah*2];
    int dqsno = darvo[segashenVrah*2 + 1];

    if(dalbochina[lqvo] < dalbochina[dqsno]){
        darvo[segashenVrah] = lqvo;
    }else{
        darvo[segashenVrah] = dqsno;
    }
}

int query(int segashenVrah, int otKadeObhv, int doKadeObhv, int otKadeUpdate, int doKadeUpdate){
    if(otKadeObhv > doKadeUpdate || doKadeObhv < otKadeUpdate){
        return -1;
    }
    if(otKadeObhv >= otKadeUpdate && doKadeObhv <= doKadeUpdate){
        return darvo[segashenVrah];
    }

    int sredata = (otKadeObhv + doKadeObhv)/2;

    int lqvo = query(segashenVrah*2, otKadeObhv, sredata, otKadeUpdate, doKadeUpdate);
    int dqsno = query(segashenVrah*2 + 1, sredata + 1, doKadeObhv, otKadeUpdate, doKadeUpdate);

    if(lqvo == -1){
        return dqsno;
    }
    if(dqsno == -1){
        return lqvo;
    }

    if(dalbochina[lqvo] < dalbochina[dqsno]){
        return lqvo;
    }
    return dqsno;
}

int lca(int naParvi, int naVtori){

    int lqvo = parvoPoseshtenie[naParvi];
    int dqsno = parvoPoseshtenie[naVtori];

    if(lqvo > dqsno){
        swap(lqvo, dqsno);
    }

    return query(1, 0, eulerovoPoseshtenie.size(), lqvo, dqsno);
}

int dfsZaNamiraneNaBroqVKoitoUchastva(int segashen, int otKadeIdvame){

    int broiZaTuk = 0;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            broiZaTuk += dfsZaNamiraneNaBroqVKoitoUchastva(sasedstvo[segashen][i], segashen);
        }
    }

    broiZaTuk = broiZaTuk + broiPutiToziENachalen[segashen] - broiPutiToziELCA[segashen];

    broiPutiPreminatoPrezNego[segashen] = broiZaTuk;

    broiZaTuk -= broiPutiToziELCA[segashen];
    return broiZaTuk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove>>broiEkskurzii;

    for(int i = 0; i < broiGradove - 1; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    dfs(1, 0);
    postroiDarvoto(1, 0, eulerovoPoseshtenie.size() - 1);

    for(int i = 0; i < broiEkskurzii; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        int lowestCANaTezi = lca(otKade, doKade);

        //cout<<otKade<<" "<<doKade<<" "<<lowestCANaTezi<<endl;

        broiPutiToziELCA[lowestCANaTezi]++;
        broiPutiToziENachalen[otKade]++;
        broiPutiToziENachalen[doKade]++;
    }

    dfsZaNamiraneNaBroqVKoitoUchastva(1, -1);

    int naiPoseshtaemost = 0;

    for(int i = 1; i <= broiGradove; i++){
        naiPoseshtaemost = max(naiPoseshtaemost, broiPutiPreminatoPrezNego[i]);
    }

    cout<<naiPoseshtaemost<<endl;

    return 0;
}
