#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const long long base = 257;
const long long mod = 1000000007;

string vhod;

long long broiDumi;

string dumi[100010];

long long basePowVhod[100010];
long long prefixHashVhod[100010];

long long basePowDumi[100010];
long long prefixHashDumi[100010];

long long basePowOtg[100010];
long long prefixHashOtg[100010];

long long hashoveDumi[100010];

map<long long, set<long long>> sTakavaDaljina;

void rabinKarpPrecalc(long long (&basePow)[100010], long long (&prefixHash)[100010], string s){
    basePow[0] = 1;
    for(long long i = 1; i < (long long)s.size(); i++){
        basePow[i] = (basePow[i - 1]*base)%mod;
    }
    prefixHash[0] = s[0];
    for(long long i = 1; i < (long long)s.size(); i++){
        prefixHash[i] = (prefixHash[i - 1]*base + s[i])%mod;
    }
}

long long daiHash(long long lqvo, long long dqsno, long long (&basePow)[100010], long long (&prefixHash)[100010]){
    long long h1 = prefixHash[dqsno];
    long long h2 = 0;
    if(lqvo > 0){
        h2 = prefixHash[lqvo - 1];
    }

    h2 = ((long long)h2 * basePow[dqsno - lqvo + 1])%mod;
    return (h1 - h2 + mod)%mod;
}

vector<char> otgovor;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>vhod;

    cin>>broiDumi;

    for(long long i = 0; i < broiDumi; i++){
        string tukaDuma;
        cin>>tukaDuma;
        dumi[i] = tukaDuma;
    }

    rabinKarpPrecalc(basePowVhod, prefixHashVhod, vhod);

    for(long long i = 0; i < broiDumi; i++){
        rabinKarpPrecalc(basePowDumi, prefixHashDumi, dumi[i]);
        hashoveDumi[i] = daiHash(0, dumi[i].size() - 1, basePowDumi, prefixHashDumi);
    }

    /*for(long long i = 0; i < broiDumi; i++){
        cout<<dumi[i]<<" "<<hashoveDumi[i]<<endl;
    }*/

    for(long long i = 0; i < broiDumi; i++){
        sTakavaDaljina[dumi[i].size()].insert(hashoveDumi[i]);
    }

    long long index = 0;

    while(index < (long long)vhod.size()){
        otgovor.push_back(vhod[index]);
        long long broiV = otgovor.size() - 1;
        if(broiV == 0){
            basePowOtg[broiV] = 1;
            prefixHashOtg[broiV] = otgovor.back();
        }else{
            basePowOtg[broiV] = (basePowOtg[broiV - 1]*base)%mod;
            prefixHashOtg[broiV] = (prefixHashOtg[broiV - 1]*base + otgovor.back())%mod;
        }

        /*cout<<"zasega otgovora izglejda taka:"<<endl;
        for(long long i = 0; i < (long long)otgovor.size(); i++){
            cout<<otgovor[i];
        }
        cout<<endl;*/

        for(map<long long, set<long long>>::iterator i = sTakavaDaljina.begin(); i != sTakavaDaljina.end(); i++){
            if((long long)otgovor.size() >= i->first){
                long long posledniteNqkolko = daiHash(otgovor.size() - i->first, otgovor.size() - 1, basePowOtg, prefixHashOtg);

                //cout<<"hasha na poslednite "<<i->first<<" e "<<posledniteNqkolko<<endl;

                if(i->second.find(posledniteNqkolko) != i->second.end()){
                    //cout<<"she mahame poslednite "<<i->first<<endl;
                    for(long long j = 0; j < i->first; j++){
                        otgovor.pop_back();
                    }
                    break;
                }
            }
        }

        index++;
    }

    for(long long i = 0; i < (long long)otgovor.size(); i++){
        cout<<otgovor[i];
    }
    cout<<endl;

    return 0;
}

