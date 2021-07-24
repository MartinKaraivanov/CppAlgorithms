#include<iostream>
#include<set>
#include<vector>
using namespace std;

int broiSpirki;
int broiLinii;

set<int> sasedstvo[50010];

void nameriPatDoNecheten(int otKade, vector<int>& kadePishem){
    int segashenVrah = otKade;

    while(true){
        kadePishem.push_back(segashenVrah);

        if(sasedstvo[segashenVrah].size() % 2 == 0){
            break;
        }

        int sledvashtVrah = *sasedstvo[segashenVrah].begin();
        sasedstvo[segashenVrah].erase(sledvashtVrah);
        if(segashenVrah != sledvashtVrah){
            sasedstvo[sledvashtVrah].erase(segashenVrah);
        }

        segashenVrah = sledvashtVrah;
    }
}

void nameriPatDoSebeSi(int koi, vector<int>& kadeZapisvame){
    if(sasedstvo[koi].size() == 0){
        return ;
    }

    bool parvotoLiE = true;

    int segashen = koi;

    while(true){
        if(parvotoLiE == false){
            kadeZapisvame.push_back(segashen);
        }

        if(segashen == koi && parvotoLiE == false){
            break;
        }

        int sledvasht = *sasedstvo[segashen].begin();
        sasedstvo[segashen].erase(sledvasht);
        if(sledvasht != segashen){
            sasedstvo[sledvasht].erase(segashen);
        }

        segashen = sledvasht;
        parvotoLiE = false;
    }
}

vector<int> patishta[50010];
vector<int> otgovori[50010];

void razshirqvaneNaPatishtata(int naKoiPat){
    //for(int i = 0; i < patishta[naKoiPat].size(); i++){
    while(patishta[naKoiPat].empty() == false){
        int tuka = patishta[naKoiPat].back();

        while(sasedstvo[tuka].empty() == false){
            nameriPatDoSebeSi(tuka, patishta[naKoiPat]);
        }

        patishta[naKoiPat].pop_back();
        otgovori[naKoiPat].push_back(tuka);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSpirki>>broiLinii;

    for(int i = 0; i < broiLinii; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade].insert(doKade);
        if(otKade != doKade){
            sasedstvo[doKade].insert(otKade);
        }
    }

    int broiSNechetnaStepen = 0;

    for(int i = 1; i <= broiSpirki; i++){
        if(sasedstvo[i].size() % 2 == 1){
            broiSNechetnaStepen++;
        }
    }

    if(broiSNechetnaStepen == 0){
        cout<<1<<endl;

        patishta[0].push_back(1);

        nameriPatDoSebeSi(1, patishta[0]);

        razshirqvaneNaPatishtata(0);

        cout<<otgovori[0].size()<<" ";

        for(int i = 0; i < otgovori[0].size(); i++){
            cout<<otgovori[0][i]<<" ";
        }
        cout<<endl;
    }else{
        int zapisvame = 0;

        for(int i = 1; i <= broiSpirki; i++){
            if(sasedstvo[i].size() % 2 == 1){
                nameriPatDoNecheten(i, patishta[zapisvame]);

                zapisvame++;
            }
        }

        for(int i = 0; i < zapisvame; i++){
            razshirqvaneNaPatishtata(i);
        }

        cout<<zapisvame<<endl;

        for(int i = 0; i < zapisvame; i++){
            cout<<otgovori[i].size()<<" ";

            for(int j = 0; j < otgovori[i].size(); j++){
                cout<<otgovori[i][j]<<" ";
            }

            cout<<endl;
        }
    }

    return 0;
}
