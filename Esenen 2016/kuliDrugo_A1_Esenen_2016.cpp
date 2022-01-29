#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int broiSgradi;
int visochini[1000010];

int broiKuli;
int visochiniKuli[100010];

int naiMnogotoZa[1100010];

int otgovori[100010];

int vsichkite[1100010];
int broiNaVsichkite;

inline int daiNovaStoinost(int staraStoinost){
    int lqvKrai = 1;
    int desenkrai = broiNaVsichkite;

    while(lqvKrai < desenkrai){
        int sredata = (lqvKrai + desenkrai)/2;

        if(vsichkite[sredata] > staraStoinost){
            desenkrai = sredata;
        }else{
            lqvKrai = sredata + 1;
        }
    }

    if(vsichkite[lqvKrai] == staraStoinost){
        return lqvKrai;
    }

    if(vsichkite[lqvKrai - 1] == staraStoinost){
        return lqvKrai - 1;
    }

    return lqvKrai + 1;
}

void preobrazuvaiVisochini(){

    vsichkite[broiNaVsichkite] = 0;
    broiNaVsichkite++;

    for(int i = 0; i < broiSgradi; i++){
        //vsichkite.push_back(visochini[i]);
        vsichkite[broiNaVsichkite] = visochini[i];
        broiNaVsichkite++;
    }

    for(int i = 0; i < broiKuli; i++){
        //vsichkite.push_back(visochiniKuli[i]);
        vsichkite[broiNaVsichkite] = visochiniKuli[i];
        broiNaVsichkite++;
    }

    sort(vsichkite, vsichkite + broiNaVsichkite);

    for(int i = 0; i < broiSgradi; i++){
        visochini[i] = daiNovaStoinost(visochini[i]);
    }

    for(int i = 0; i < broiKuli; i++){
        visochiniKuli[i] = daiNovaStoinost(visochiniKuli[i]);
    }

}

vector<int> deca[1100010];
vector<int> koreni;

inline void nameriNaiMnogotata(int segashen){
    int naiMnogot = 0;

    for(int i = 0; i < (int)deca[segashen].size(); i++){
        nameriNaiMnogotata(deca[segashen][i]);
        naiMnogot = max(naiMnogot, naiMnogotoZa[deca[segashen][i]]);
    }

    naiMnogotoZa[segashen] = naiMnogot + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSgradi>>broiKuli;

    for(int i = 0; i < broiSgradi; i++){
        cin>>visochini[i];
    }

    for(int i = 0; i < broiKuli; i++){
        cin>>visochiniKuli[i];
    }

    preobrazuvaiVisochini();

    vector<int> s;

    for(int i = 0; i < broiSgradi; i++){

        while(s.empty() == false){
            if(s.back() < visochini[i]){
                s.pop_back();
            }else{
                break;
            }
        }

        if(s.empty() == false){
            deca[s.back()].push_back(visochini[i]);
        }else{
            koreni.push_back(visochini[i]);
        }

        s.push_back(visochini[i]);
    }

    for(int i = 0; i < (int)koreni.size(); i++){
        nameriNaiMnogotata(koreni[i]);
    }

    for(int i = 1; i <= broiSgradi + broiKuli; i++){
        naiMnogotoZa[i] = max(naiMnogotoZa[i - 1], naiMnogotoZa[i]);
    }

    for(int i = 0; i < broiKuli; i++){
        otgovori[i] = naiMnogotoZa[visochiniKuli[i]];
    }

    for(int i = 0; i < broiKuli; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
