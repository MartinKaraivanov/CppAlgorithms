#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaMosta{
    long long otKade;
    long long doKade;
};

long long broiVarhove;
long long broiRebra;

vector<long long> sasedstvo[100010];

bool visited[100010];

long long low[100010];
long long kogaVlizame[100010];

long long vreme;

vector<DanniZaMosta> mostove;

void dfs(long long segashen, long long otKadeIdvame){
    visited[segashen] = true;

    vreme++;
    kogaVlizame[segashen] = vreme;
    low[segashen] = vreme;

    for(unsigned long long i = 0; i < sasedstvo[segashen].size(); i++){
        long long sledvasht = sasedstvo[segashen][i];
        if(sledvasht != otKadeIdvame){
            if(visited[sledvasht] == true){
                low[segashen] = min(low[segashen], low[sledvasht]);
            }else{
                dfs(sledvasht, segashen);

                low[segashen] = min(low[segashen], low[sledvasht]);

                if(low[sledvasht] > low[segashen]){
                    mostove.push_back({segashen, sledvasht});
                }
            }
        }
    }
}

void namiraneNaMostove(){
    for(long long i = 1; i <= broiVarhove; i++){
        if(visited[i] == false){
            dfs(i, -1);
        }
    }
}

void mahniRebro(long long otKade, long long doKade){
    for(unsigned long long i = 0; i < sasedstvo[otKade].size(); i++){
        if(sasedstvo[otKade][i] == doKade){
            swap(sasedstvo[otKade][i], sasedstvo[otKade][sasedstvo[otKade].size() - 1]);
            sasedstvo[otKade].pop_back();
            break;
        }
    }

    for(unsigned long long i = 0; i < sasedstvo[doKade].size(); i++){
        if(sasedstvo[doKade][i] == otKade){
            swap(sasedstvo[doKade][i], sasedstvo[doKade][sasedstvo[doKade].size() - 1]);
            sasedstvo[doKade].pop_back();
            break;
        }
    }
}

void mahaneNaMostove(){
    for(unsigned long long i = 0; i < mostove.size(); i++){
        mahniRebro(mostove[i].otKade, mostove[i].doKade);
    }
}

bool nomerirane[100010];

long long broiVTaziKomp(long long vrah){
    long long broi = 0;

    queue<long long> q;

    q.push(vrah);

    while(q.empty() == false){
        long long naiOtpred = q.front();
        q.pop();

        if(nomerirane[naiOtpred] == true){
            continue;
        }

        nomerirane[naiOtpred] = true;
        broi++;

        for(unsigned long long i = 0; i < sasedstvo[naiOtpred].size(); i++){
            if(nomerirane[sasedstvo[naiOtpred][i]] == false){
                q.push(sasedstvo[naiOtpred][i]);
            }
        }
    }

    return broi;
}

long long broiDvoikiMesta(){
    long long broi = 0;

    for(long long i = 1; i <= broiVarhove; i++){
        if(nomerirane[i] == false){
            long long br = broiVTaziKomp(i);
            broi += (br)*(br-1)/2;
        }
    }

    return broi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiVarhove>>broiRebra;

    for(long long i = 0; i < broiRebra; i++){
        long long otKade;
        long long doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    namiraneNaMostove();

    mahaneNaMostove();

    long long otg = broiDvoikiMesta();

    cout<<otg<<endl;

    return 0;
}
