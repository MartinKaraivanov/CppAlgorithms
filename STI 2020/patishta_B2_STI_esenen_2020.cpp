#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int broiGradove;
int broiEkskurzii;

vector<int> sasedstvo[50010];

int broiPutiPreminatoPrezNego[50010];

int dalbochina[50010];
vector<int> pow2ancestors[50010];


bool visited[50010];

int broiPutiToziELCA[50010];
int broiPutiToziENachalen[50010];

void dfsZaNamiraneNaDalbochinaIParents(int segashen, int otKadeIdvame, int dalb){
    dalbochina[segashen] = dalb;
    pow2ancestors[segashen].push_back(segashen);
    if(otKadeIdvame != -1){
        pow2ancestors[segashen].push_back(otKadeIdvame);
    }

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            dfsZaNamiraneNaDalbochinaIParents(sasedstvo[segashen][i], segashen, dalb + 1);
        }
    }
}

void praveneNaDrugiteAncestori(){
    bool pravimLiNeshto = true;

    for(int pow2rastoqnie = 2; pravimLiNeshto == true; pow2rastoqnie++){
        pravimLiNeshto = false;
        for(int grad = 1; grad <= broiGradove; grad++){
            if(pow2ancestors[grad].size() > pow2rastoqnie-1){
                int mnogoPradqdo = pow2ancestors[grad][pow2rastoqnie - 1];
                if(mnogoPradqdo != -1 && pow2ancestors[mnogoPradqdo].size() > pow2rastoqnie - 1){
                    pow2ancestors[grad].push_back(pow2ancestors[mnogoPradqdo][pow2rastoqnie - 1]);
                    pravimLiNeshto = true;
                }
            }
        }
    }
}

/*
void dfsSasStack(int start){
    stack<int> s;

    s.push(start);
    parents[start] = -1;
    dalbochina[start] = 1;

    while(s.empty() == false){
        int naiOtgore = s.top();
        s.pop();

        if(visited[naiOtgore] == true){
            continue;
        }
        visited[naiOtgore] = true;

        for(unsigned int i = 0; i < sasedstvo[naiOtgore].size(); i++){
            if(visited[sasedstvo[naiOtgore][i]] == false){
                parents[sasedstvo[naiOtgore][i]] = naiOtgore;
                dalbochina[sasedstvo[naiOtgore][i]] = dalbochina[naiOtgore] + 1;
                s.push(sasedstvo[naiOtgore][i]);
            }
        }

    }

}

void bfs(int start){
    queue<int> q;

    q.push(start);
    parents[start] = -1;
    dalbochina[start] = 1;

    while(q.empty() == false){
        int naiOtgore = q.front();
        q.pop();

        if(visited[naiOtgore] == true){
            continue;
        }
        visited[naiOtgore] = true;

        for(unsigned int i = 0; i < sasedstvo[naiOtgore].size(); i++){
            if(visited[sasedstvo[naiOtgore][i]] == false){
                parents[sasedstvo[naiOtgore][i]] = naiOtgore;
                dalbochina[sasedstvo[naiOtgore][i]] = dalbochina[naiOtgore] + 1;
                q.push(sasedstvo[naiOtgore][i]);
            }
        }
    }

}
*/
int lca(int naParvi, int naVtori){
    int segashnoOtKade = naParvi;
    int segashnoDoKade = naVtori;

    if(dalbochina[segashnoOtKade] < dalbochina[segashnoDoKade]){
        swap(segashnoOtKade, segashnoDoKade);
    }

    int razlikaVNivata = dalbochina[segashnoOtKade] - dalbochina[segashnoDoKade];

    for(int i = 1; razlikaVNivata > 0; i++){
        if(razlikaVNivata % 2 == 1){
            segashnoOtKade = pow2ancestors[segashnoOtKade][i];
        }
        razlikaVNivata /= 2;
    }

    if(segashnoOtKade == segashnoDoKade){
        return segashnoOtKade;
    }

    int i = pow2ancestors[segashnoOtKade].size() - 1;
    while(i > 0){
        if(pow2ancestors[segashnoOtKade][i] != pow2ancestors[segashnoDoKade][i]){
            segashnoOtKade = pow2ancestors[segashnoOtKade][i];
            segashnoDoKade = pow2ancestors[segashnoDoKade][i];
            i = min((int)pow2ancestors[segashnoOtKade].size() - 1, i - 1);
        }else{
            i--;
        }
    }

    int lowestCommonAncestor = pow2ancestors[segashnoOtKade][1];

    return lowestCommonAncestor;
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

    dfsZaNamiraneNaDalbochinaIParents(1, -1, 1);
    praveneNaDrugiteAncestori();
    //dfsSasStack(1);
    //bfs(1);

    for(int i = 0; i < broiEkskurzii; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        int lowestCANaTezi = lca(otKade, doKade);

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
