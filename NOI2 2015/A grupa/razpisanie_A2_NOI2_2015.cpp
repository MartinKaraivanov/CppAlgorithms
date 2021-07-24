#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaOperaciqta{
    int nomer;
    int dalbochina;

    DanniZaOperaciqta(int nomer, int dalbochina)
        : nomer(nomer), dalbochina(dalbochina)
    {

    }
};

struct KoiEPoNazad{
    bool operator()(DanniZaOperaciqta const& a, DanniZaOperaciqta const& b)
    {
        return a.dalbochina < b.dalbochina;
    }
};

int broiOperacii;
int broiMashini;

int bashtaNaTozi[100010];

vector<int> decaNaTozi[100010];

int koren;

int dalbochini[100010];

int naiGolqmataDalbochina;

void praveneNaDalbochinite(int segashen, int dalb){
    dalbochini[segashen] = dalb;

    naiGolqmataDalbochina = max(naiGolqmataDalbochina, dalb);

    for(unsigned int i = 0; i < decaNaTozi[segashen].size(); i++){
        praveneNaDalbochinite(decaNaTozi[segashen][i], dalb + 1);
    }
}

int broiOtDecataMuGotovi[100010];

int broiTaktove(){
    priority_queue<DanniZaOperaciqta, vector<DanniZaOperaciqta>, KoiEPoNazad> q;

    for(int i = 1; i <= broiOperacii; i++){
        if(decaNaTozi[i].size() == 0){
            q.push({i, dalbochini[i]});
        }
    }

    int brTaktove = 0;

    bool gotoviLiSme = false;

    while(q.empty() == false){
        brTaktove++;

        vector<DanniZaOperaciqta> zaPushvane;

        for(int k = 0; k < broiMashini; k++){
            if(q.empty() == false){
                DanniZaOperaciqta naiOtgore = q.top();
                q.pop();

                //cout<<brTaktove<<" "<<naiOtgore.nomer<<" "<<naiOtgore.dalbochina<<endl;

                if(naiOtgore.nomer == koren){
                    gotoviLiSme = true;
                    break;
                }

                broiOtDecataMuGotovi[bashtaNaTozi[naiOtgore.nomer]]++;

                if(broiOtDecataMuGotovi[bashtaNaTozi[naiOtgore.nomer]] == decaNaTozi[bashtaNaTozi[naiOtgore.nomer]].size()){
                    //q.push({bashtaNaTozi[naiOtgore.nomer], naiOtgore.dalbochina - 1});
                    zaPushvane.push_back({bashtaNaTozi[naiOtgore.nomer], naiOtgore.dalbochina - 1});
                }
            }else{
                break;
            }
        }

        if(gotoviLiSme == true){
            break;
        }

        //cout<<"na takt "<<brTaktove<<" "<<zaPushvane.size()<<endl;

        for(unsigned int i = 0; i < zaPushvane.size(); i++){
            //cout<<zaPushvane[i].nomer<<" "<<zaPushvane[i].dalbochina<<endl;
            q.push(zaPushvane[i]);
        }
    }

    return brTaktove;
}

int main(){
    cin>>broiOperacii>>broiMashini;

    for(int i = 0; i < broiOperacii - 1; i++){
        int dete;
        int bashta;

        cin>>dete>>bashta;

        bashtaNaTozi[dete] = bashta;
        decaNaTozi[bashta].push_back(dete);
    }

    for(int i = 1; i <= broiOperacii; i++){
        if(bashtaNaTozi[i] == 0){
            koren = i;
            break;
        }
    }

    praveneNaDalbochinite(koren, 1);

    int kolkoTakta = broiTaktove();

    cout<<kolkoTakta<<endl;

    return 0;
}
