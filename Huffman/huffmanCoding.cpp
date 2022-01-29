#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

string vhodenString;

int kolkoPatiSeSresht[256];

struct DanniZaStringa{
    int nomerNaVarha;
    int kolkoPati;
    int lqvoDete;
    int dqsnoDete;
    int originalnaStoinost;

    DanniZaStringa(int nomerNaVarha, int kolkoPati, int lqvoDete, int dqsnoDete, int originalnaStoinost)
        : nomerNaVarha(nomerNaVarha), kolkoPati(kolkoPati), lqvoDete(lqvoDete), dqsnoDete(dqsnoDete), originalnaStoinost(originalnaStoinost)
    {

    }
};

struct KoiEPoMaluk{
    bool operator()(DanniZaStringa const& a, DanniZaStringa const& b)
    {
        return a.kolkoPati > b.kolkoPati;
    }
};

priority_queue<DanniZaStringa, vector<DanniZaStringa>, KoiEPoMaluk> q;

vector<DanniZaStringa> varhove;

vector<int> noviqKodNa[1024];

void obhojdane(int segashenVrah, vector<int> novKod){
    if(varhove[segashenVrah].lqvoDete == -1 && varhove[segashenVrah].dqsnoDete == -1){
        noviqKodNa[varhove[segashenVrah].originalnaStoinost] = novKod;
        return ;
    }

    novKod.push_back(0);
    obhojdane(varhove[segashenVrah].lqvoDete, novKod);
    novKod.pop_back();
    novKod.push_back(1);
    obhojdane(varhove[segashenVrah].dqsnoDete, novKod);
    novKod.pop_back();
}

vector<int> otCharKamBitove(char a){
    vector<int> rezultat;

    for(int i = 0; i < 8; i++){
        rezultat.push_back(a&1);
        a >>= 1;
    }

    reverse(rezultat.begin(), rezultat.end());

    return rezultat;
}

int main(){

    cin>>vhodenString;

    for(int i = 0; i < (int)vhodenString.size(); i++){
        kolkoPatiSeSresht[vhodenString[i]]++;
    }

    for(int i = 0; i < 256; i++){
        if(kolkoPatiSeSresht[i] > 0){
            DanniZaStringa zaDob = {(int)varhove.size(), kolkoPatiSeSresht[i], -1, -1, i};
            q.push(zaDob);
            varhove.push_back(zaDob);
        }
    }

    while(q.size() > 1){
        DanniZaStringa naiMalkoto = q.top();
        q.pop();
        DanniZaStringa vtorotoNaiM = q.top();
        q.pop();

        //cout<<"v momenta nai gornite 2 sa: "<<endl;
        //cout<<naiMalkoto.nomerNaVarha<<" "<<naiMalkoto.kolkoPati<<" i "<<vtorotoNaiM.nomerNaVarha<<" "<<vtorotoNaiM.kolkoPati<<endl;

        DanniZaStringa novVrah = {(int)varhove.size(), naiMalkoto.kolkoPati + vtorotoNaiM.kolkoPati, naiMalkoto.nomerNaVarha, vtorotoNaiM.nomerNaVarha, -1};
        q.push(novVrah);
        varhove.push_back(novVrah);
    }

    DanniZaStringa koren = q.top();
    q.pop();

    obhojdane(koren.nomerNaVarha, {});

    for(int i = 0; i < 256; i++){
        if(kolkoPatiSeSresht[i] > 0){
            char a = i;
            //cout<<i<<" "<<a<<" ";
            cout<<a<<" ";
            for(int j : noviqKodNa[i]){
                cout<<j;
            }
            cout<<endl;
        }
    }

    for(int i = 0; i < (int)vhodenString.size(); i++){
        vector<int> bitoveteMu = otCharKamBitove(vhodenString[i]);
        for(int j : bitoveteMu){
            cout<<j;
        }
    }
    cout<<endl<<endl;

    for(int i = 0; i < (int)vhodenString.size(); i++){
        for(int j : noviqKodNa[vhodenString[i]]){
            cout<<j;
        }
    }

    cout<<endl;

    return 0;
}
