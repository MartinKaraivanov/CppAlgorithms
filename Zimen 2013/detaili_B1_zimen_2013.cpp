#include<iostream>
#include<queue>
using namespace std;

struct DanniZaZavod{
    long long vremeZaSvarshvane;
    int vremeZaObrabotkaNaEdinPredmetOtTazi;
    bool polzvanoLiE;
    DanniZaZavod(long long vremeZaSvarshvane, int vremeZaObrabotkaNaEdinPredmetOtTazi)
        : vremeZaSvarshvane(vremeZaSvarshvane), vremeZaObrabotkaNaEdinPredmetOtTazi(vremeZaObrabotkaNaEdinPredmetOtTazi), polzvanoLiE(false)
    {
    }
};

struct poMalkoLiE{
    bool operator()(DanniZaZavod const& a, DanniZaZavod const& b){
        /*if(a.vremeZaSvarshvane > b.vremeZaSvarshvane){
            return true;
        }else{
            if(a.vremeZaSvarshvane < b.vremeZaSvarshvane){
                return false;
            }else{
                return a.vremeZaObrabotkaNaEdinPredmetOtTazi > b.vremeZaObrabotkaNaEdinPredmetOtTazi;
            }
        }*/
        return a.vremeZaSvarshvane + a.vremeZaObrabotkaNaEdinPredmetOtTazi > b.vremeZaSvarshvane + b.vremeZaObrabotkaNaEdinPredmetOtTazi;;
    }
};

int broiFabriki;
int broiElementi;

//vector<DanniZaZavod> zavodi;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiFabriki>>broiElementi;

    priority_queue<DanniZaZavod, vector<DanniZaZavod>, poMalkoLiE> q;

    for(int i = 0; i < broiFabriki; i++){
        int startovoZabavqne;
        int vremeZaPraveneOtTaziFabrika;
        cin>>startovoZabavqne>>vremeZaPraveneOtTaziFabrika;
        DanniZaZavod zaDob = {vremeZaPraveneOtTaziFabrika, startovoZabavqne};
        q.push(zaDob);
    }

    for(int i = 0; i < broiElementi; i++){
        DanniZaZavod naiOtgore = q.top();
        q.pop();
        //cout<<"sega sme izbrali tozi s vreme "<<naiOtgore.vremeZaSvarshvane<<" i za "<<naiOtgore.vremeZaObrabotkaNaEdinPredmetOtTazi<<endl;
        naiOtgore.vremeZaSvarshvane += naiOtgore.vremeZaObrabotkaNaEdinPredmetOtTazi;
        naiOtgore.polzvanoLiE = true;
        //cout<<"stava na "<<naiOtgore.vremeZaSvarshvane<<" "<<naiOtgore.vremeZaObrabotkaNaEdinPredmetOtTazi<<endl;
        q.push(naiOtgore);
    }

    int r = q.size();

    long long naiGolqmo = 0;

    for(int i = 0; i < r; i++){
        //cout<<q.top().vremeZaSvarshvane<<endl;
        if(q.top().polzvanoLiE == true){
            naiGolqmo = max(naiGolqmo, q.top().vremeZaSvarshvane);
        }
        q.pop();
    }

    cout<<naiGolqmo<<endl;

    return 0;
}
