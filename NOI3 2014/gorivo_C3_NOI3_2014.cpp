#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long broiGradove;
long long broiPitaniq;

struct DanniZaSaseda{
    long long koiE;
    long long razstDoNego;
};

vector<DanniZaSaseda> sasedstvo[5010];

struct DanniZaPitaneto{
    long long otKoi;
    long long doKoi;
    long long originalnaPoziciq;
};

DanniZaPitaneto pitaniq[200010];

long long razstDoTozi[5010];

long long dalbochina[5010];
vector<long long> pow2ancestors[5010];

void dfs(long long segasen, long long otKadeIdvame){
    pow2ancestors[segasen].push_back(segasen);

    if(otKadeIdvame != -1){
        pow2ancestors[segasen].push_back(otKadeIdvame);
    }


    for(long long i = 0; i < (long long)sasedstvo[segasen].size(); i++){
        if(sasedstvo[segasen][i].koiE != otKadeIdvame){
            razstDoTozi[sasedstvo[segasen][i].koiE] = razstDoTozi[segasen] + sasedstvo[segasen][i].razstDoNego;
            dalbochina[sasedstvo[segasen][i].koiE] = dalbochina[segasen] + 1;

            dfs(sasedstvo[segasen][i].koiE, segasen);
        }
    }
}

void praveneNaDrugiteAncestori(){
    bool pravimLiNeshto = true;

    for(int pow2rastoqnie = 2; pravimLiNeshto == true; pow2rastoqnie++){
        pravimLiNeshto = false;
        for(int grad = 1; grad <= broiGradove; grad++){
            if((long long)pow2ancestors[grad].size() > pow2rastoqnie-1){
                int mnogoPradqdo = pow2ancestors[grad][pow2rastoqnie - 1];
                if(mnogoPradqdo != -1 && (long long)pow2ancestors[mnogoPradqdo].size() > pow2rastoqnie - 1){
                    pow2ancestors[grad].push_back(pow2ancestors[mnogoPradqdo][pow2rastoqnie - 1]);
                    pravimLiNeshto = true;
                }
            }
        }
    }
}

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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove>>broiPitaniq;

    for(long long i = 0; i < broiGradove - 1; i++){
        long long otKoi;
        long long doKoi;
        long long razst;

        cin>>otKoi>>doKoi>>razst;

        sasedstvo[otKoi].push_back({doKoi, razst});
        sasedstvo[doKoi].push_back({otKoi, razst});
    }

    for(long long i = 0; i < broiPitaniq; i++){
        long long otKade;
        long long doKade;

        cin>>otKade>>doKade;

        pitaniq[i] = {otKade, doKade, i};
    }

    dalbochina[1] = 1;
    dfs(1, -1);
    praveneNaDrugiteAncestori();

    for(long long i = 0; i < broiPitaniq; i++){
        long long lowestCA = lca(pitaniq[i].otKoi, pitaniq[i].doKoi);
        long long otgovor =
            razstDoTozi[pitaniq[i].otKoi] + razstDoTozi[pitaniq[i].doKoi] - 2 * razstDoTozi[lowestCA];

        cout<<otgovor<<endl;
    }

    return 0;
}
