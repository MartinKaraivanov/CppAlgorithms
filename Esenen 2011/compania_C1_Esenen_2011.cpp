#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaShefa{
    int koiE;
    DanniZaShefa(int koiE)
        :koiE(koiE)
    {

    }
};

struct PoMalukNomer{
    bool operator()(DanniZaShefa const& a, DanniZaShefa const& b)
    {
        return a.koiE > b.koiE;
    }
};

int broiRabotnici;
priority_queue<DanniZaShefa, vector<DanniZaShefa>, PoMalukNomer> direktnoPodchineni[200005];

vector<int> otgovori;

void podrezhdane(int segashen){
    otgovori.push_back(segashen);
    while(direktnoPodchineni[segashen].empty() == false){
        DanniZaShefa naiOtpred = direktnoPodchineni[segashen].top();
        direktnoPodchineni[segashen].pop();
        podrezhdane(naiOtpred.koiE);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiRabotnici;

    for(int i = 0; i < broiRabotnici - 1; i++){
        int koiEShefche;
        int naKoiEShefche;
        cin>>koiEShefche>>naKoiEShefche;
        direktnoPodchineni[koiEShefche].push(naKoiEShefche);
    }

    podrezhdane(1);

    for(unsigned int i = 0; i < otgovori.size(); i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
