#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int broiSektori;

int broiRazdeli;

struct DanniZaTochkata{
    int x;
    int index;
};

bool KoqEPoNapred(DanniZaTochkata a, DanniZaTochkata b){
    if(a.x < b.x){
        return true;
    }
    if(a.x > b.x){
        return false;
    }
    return a.index < b.index;
}

DanniZaTochkata tochki[200010];
int broiTochki;

set<int> s;
bool pokritaLiE[100010];

int main(){

    cin>>broiSektori>>broiRazdeli;

    for(int i = 1; i <= broiRazdeli; i++){
        cin>>tochki[broiTochki].x;
        tochki[broiTochki].index = -i;
        broiTochki++;
        cin>>tochki[broiTochki].x;
        tochki[broiTochki].index = i;
        broiTochki++;
    }

    sort(tochki, tochki + broiTochki, KoqEPoNapred);

    /*
    for(int i = 0; i < broiTochki; i++){
        cout<<tochki[i].x<<" "<<tochki[i].index<<endl;
    }
    */

    s.insert(0);

    int otgovor = 0;

    for(int i = 0; i < broiTochki; i++){
        int tukaTochka = tochki[i].index;
        if(tukaTochka < 0){
            pokritaLiE[min(-tukaTochka, *s.rbegin())] = true;
            s.insert(-tukaTochka);
        }else{
            if(pokritaLiE[tukaTochka] == false){
                otgovor++;
            }
            s.erase(tukaTochka);
        }
    }

    cout<<otgovor<<endl;

    return 0;
}
