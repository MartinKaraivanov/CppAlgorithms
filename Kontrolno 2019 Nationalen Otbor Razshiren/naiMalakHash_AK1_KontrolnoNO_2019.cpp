#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const long long mod = 1000000000000037;
const long long base = 127;

int daljinaVhodStringove;
string vhod[3];

long long basePow[32];

vector<long long> lqvaStrana;
vector<long long> dqsnaStrana;

void nameriVazmojnosti(long long hesh, int index, int doKade, vector<long long>& stoinosti){
    if(index >= doKade){
        stoinosti.push_back(hesh);
        return ;
    }

    nameriVazmojnosti((hesh + vhod[0][index]*basePow[index])%mod, index + 1, doKade, stoinosti);
    nameriVazmojnosti((hesh + vhod[1][index]*basePow[index])%mod, index + 1, doKade, stoinosti);
    nameriVazmojnosti((hesh + vhod[2][index]*basePow[index])%mod, index + 1, doKade, stoinosti);
}

int main(){

    cin>>daljinaVhodStringove;

    for(int i = 0; i < 3; i++){
        cin>>vhod[i];
    }

    basePow[daljinaVhodStringove - 1] = 1;
    for(int i = daljinaVhodStringove - 2; i >= 0; i--){
        basePow[i] = (basePow[i + 1]*base)%mod;
    }

    nameriVazmojnosti(0, 0, daljinaVhodStringove/2 + daljinaVhodStringove%2, lqvaStrana);
    nameriVazmojnosti(0, daljinaVhodStringove/2 + daljinaVhodStringove%2, daljinaVhodStringove, dqsnaStrana);

    sort(lqvaStrana.begin(), lqvaStrana.end());

    long long otgovor = mod;

    for(int i = 0; i < (int)dqsnaStrana.size(); i++){
        long long tarseno = mod - dqsnaStrana[i];

        long long lqvKrai = 0;
        long long desenKrai = lqvaStrana.size() - 1;

        while(lqvKrai <= desenKrai){
            long long sredata = (lqvKrai + desenKrai)/2;

            if(lqvaStrana[sredata] < tarseno){
                lqvKrai = sredata + 1;
            }else{
                desenKrai = sredata - 1;
            }
        }

        if(lqvaStrana[lqvKrai - 1] > tarseno){
            lqvKrai--;
        }

        long long tekushto = (lqvaStrana[lqvKrai%(int)lqvaStrana.size()] + dqsnaStrana[i])%mod;
        otgovor = min(otgovor, tekushto);
    }

    cout<<otgovor<<endl;

    return 0;
}
