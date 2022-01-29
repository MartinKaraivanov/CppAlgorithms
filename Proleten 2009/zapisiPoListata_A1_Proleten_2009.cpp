#include<iostream>
#include<queue>
#include<vector>
using namespace std;

long long broiZapisi;

long long zapisi[100010];

struct DanniZaVarha{
    long long nomer;
    long long stoinost;
    long long lqvoDete;
    long long dqsnoDete;

    DanniZaVarha(long long nomer, long long stoinost, long long lqvoDete, long long dqsnoDete)
        : nomer(nomer), stoinost(stoinost), lqvoDete(lqvoDete), dqsnoDete(dqsnoDete)
    {

    }
};

struct KoiEPoMaluk{
    bool operator()(DanniZaVarha const& a, DanniZaVarha const& b)
    {
        return a.stoinost > b.stoinost;
    }
};

priority_queue<DanniZaVarha, vector<DanniZaVarha>, KoiEPoMaluk> q;

long long nomerche;
vector<DanniZaVarha> varhove;

long long dfs(long long segashenVrah, long long dalbochina){
    if(varhove[segashenVrah].lqvoDete == -1 && varhove[segashenVrah].dqsnoDete == -1){
        return dalbochina*varhove[segashenVrah].stoinost;
    }

    long long tuka = dfs(varhove[segashenVrah].lqvoDete, dalbochina + 1) + dfs(varhove[segashenVrah].dqsnoDete, dalbochina + 1);

    return tuka;
}

int main(){

    cin>>broiZapisi;

    for(long long i = 0; i < broiZapisi; i++){
        cin>>zapisi[i];
    }

    for(long long i = 0; i < broiZapisi; i++){
        q.push({nomerche, zapisi[i], -1, -1});
        varhove.push_back({nomerche, zapisi[i], -1, -1});
        nomerche++;
    }

    while(q.size() > 1){
        DanniZaVarha naiMalkoto = q.top();
        q.pop();
        DanniZaVarha vtorotoNaiM = q.top();
        q.pop();

        //cout<<"sega nai malkite sa "<<naiMalkoto.stoinost<<" "<<vtorotoNaiM.stoinost<<endl;

        DanniZaVarha novVrah = {nomerche, naiMalkoto.stoinost + vtorotoNaiM.stoinost, naiMalkoto.nomer, vtorotoNaiM.nomer};
        varhove.push_back({nomerche, naiMalkoto.stoinost + vtorotoNaiM.stoinost, naiMalkoto.nomer, vtorotoNaiM.nomer});
        nomerche++;
        q.push(novVrah);
    }

    long long koren = q.top().nomer;
    q.pop();


    long long otgovor = dfs(koren, 0);

    cout<<otgovor<<endl;

    return 0;
}
