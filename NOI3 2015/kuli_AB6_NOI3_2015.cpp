#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

struct DanniZaKulata{
    int nomerNaKula;
    int kolkoImaPrediNego;
};

int broiKuli;

int kolkoPokriva[1000010];

int koiImaTolkovaKubcheta[1000010];

int main(){
    cin>>broiKuli;

    for(int i = 0; i < broiKuli; i++){
        cin>>kolkoPokriva[i];
    }

    stack<DanniZaKulata> s;
    vector<int> v;
    DanniZaKulata nachalno = {0, 0};
    s.push(nachalno);
    v.push_back(0);

    for(int i = 1; i < broiKuli; i++){
        int pokrivani = kolkoPokriva[i];;
        int poGolqmaOt = pokrivani;

        for(int j = 0; j < pokrivani; j++){
            poGolqmaOt += kolkoPokriva[s.top().nomerNaKula];
            s.pop();
        }

        int poziciqZaSlaganeVavVektora = 0;

        if(s.size() > 0){
            int naiGoren = s.top().nomerNaKula;
            poGolqmaOt += s.top().kolkoImaPrediNego;
            for(unsigned int j = poGolqmaOt; j < v.size(); j++){
                if(v[j] == naiGoren){
                    poziciqZaSlaganeVavVektora = j;
                    break;
                }
            }
            v.insert(v.begin() + poziciqZaSlaganeVavVektora, i);
        }else{
            poziciqZaSlaganeVavVektora = v.size();
            v.push_back(i);
        }
        DanniZaKulata zaDob = {i, poziciqZaSlaganeVavVektora};
        s.push(zaDob);
    }

    for(unsigned int i = 0; i < v.size(); i++){
        koiImaTolkovaKubcheta[v[i]] = i;
    }

    for(int i = 0; i < broiKuli; i++){
        cout<<koiImaTolkovaKubcheta[i] + 1<<endl;
    }

    return 0;
}
