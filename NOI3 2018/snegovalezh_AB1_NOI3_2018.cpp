#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int broiGradove;
int broiPatishta;
int broiNuzhniOpasniGradove;

struct DanniZaPatq{
    int doKoi;
    int nuzhenSnqg;
};

vector<DanniZaPatq> nachalniPatishta[50010];

vector<int> sasedstvo[50010];

bool visited[50010];
int roditel[50010];
int kogaOtkrit[50010];
int low[50010];

vector<int> tukArticulatonPointove;
bool toziAPLiE[50010];

void praveneNaSasedstvoto(int priSnqg){
    for(int i = 1; i <= broiGradove; i++){
        visited[i] = false;
        roditel[i] = 0;
        kogaOtkrit[i] = 0;
        low[i] = 0;
        sasedstvo[i].clear();
        toziAPLiE[i] = false;
    }
    tukArticulatonPointove.clear();

    for(int i = 1; i <= broiGradove; i++){
        for(int j = 0; j < (int)nachalniPatishta[i].size(); j++){
            if(nachalniPatishta[i][j].nuzhenSnqg > priSnqg){
                sasedstvo[i].push_back(nachalniPatishta[i][j].doKoi);
            }
        }
    }
}

void nameriArticulPtove(int segashen, int vreme){
    visited[segashen] = true;
    kogaOtkrit[segashen] = vreme;
    low[segashen] = vreme;


    int broiDeca = 0;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        int sledvasht = sasedstvo[segashen][i];

        if(visited[sledvasht] == false){
            broiDeca++;
            roditel[sledvasht] = segashen;

            nameriArticulPtove(sledvasht, vreme + 1);

            low[segashen] = min(low[segashen], low[sledvasht]);

            if(roditel[segashen] != 0 && low[sledvasht] >= kogaOtkrit[segashen] && toziAPLiE[segashen] == false){
                tukArticulatonPointove.push_back(segashen);
                toziAPLiE[segashen] = true;
            }else{

                if(roditel[segashen] == 0 && broiDeca > 1 && toziAPLiE[segashen] == false){
                    tukArticulatonPointove.push_back(segashen);
                    toziAPLiE[segashen] = true;
                }
            }

        }else{
            if(sledvasht != roditel[segashen]){
                low[segashen] = min(low[segashen], kogaOtkrit[sledvasht]);
            }
        }
    }

}

void articulatonPointovePriSnqg(int kolkoSnqg){
    praveneNaSasedstvoto(kolkoSnqg);

    /*cout<<"pri snqg "<<kolkoSnqg<<endl;

    for(int i = 1; i <= broiGradove; i++){
        cout<<i<<":"<<endl;

        for(int j = 0; j < (int)sasedstvo[i].size(); j++){
            cout<<sasedstvo[i][j]<<" ";
        }
        cout<<endl;
    }*/

    nameriArticulPtove(1, 1);

    bool imaLiNeposeten = false;

    for(int i = 1; i <= broiGradove; i++){
        if(visited[i] == false){
            //cout<<i<<" e neposeten"<<endl;
            imaLiNeposeten = true;
        }
    }

    if(imaLiNeposeten == true){
        for(int i = 1; i <= broiGradove; i++){
            tukArticulatonPointove.push_back(1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove>>broiPatishta>>broiNuzhniOpasniGradove;

    int maxSnqg = 0;

    for(int i = 0; i < broiPatishta; i++){
        int otKade;
        int doKade;
        int poneSnqg;
        cin>>otKade>>doKade>>poneSnqg;

        nachalniPatishta[otKade].push_back({doKade, poneSnqg});
        nachalniPatishta[doKade].push_back({otKade, poneSnqg});

        maxSnqg = max(maxSnqg, poneSnqg);
    }

    /*int otgovor = -1;

    for(int snqg = 0; snqg <= maxSnqg; snqg++){

        articulatonPointovePriSnqg(snqg);

        //cout<<snqg<<" "<<tukArticulatonPointove.size()<<endl;

        if((int)tukArticulatonPointove.size() >= broiNuzhniOpasniGradove){
            otgovor = snqg;
            break;
        }
    }*/

    int lqvKrai = 0;
    int desenKrai = maxSnqg;

    while(lqvKrai < desenKrai){
        int sredata = (lqvKrai + desenKrai)/2;

        articulatonPointovePriSnqg(sredata);

        if((int)tukArticulatonPointove.size() >= broiNuzhniOpasniGradove){
            desenKrai = sredata;
            //cout<<sredata<<" stava"<<endl;
        }else{
            //cout<<sredata<<" ne stava"<<endl;
            lqvKrai = sredata + 1;
        }
    }

    //cout<<lqvKrai<<endl;

    articulatonPointovePriSnqg(lqvKrai);

    if((int)tukArticulatonPointove.size() < broiNuzhniOpasniGradove){
        lqvKrai++;
        articulatonPointovePriSnqg(lqvKrai);
    }

    if(lqvKrai >= maxSnqg){
        lqvKrai = -1;
    }

    for(int i = 1; i < (int)tukArticulatonPointove.size(); i++){
        if(tukArticulatonPointove[i] == tukArticulatonPointove[i - 1]){
            lqvKrai = -1;
            break;
        }
    }

    int otgovor = lqvKrai;

    if(otgovor == -1){
        cout<<-1<<" "<<0<<endl;
    }else{
        cout<<otgovor<<" "<<tukArticulatonPointove.size()<<endl;

        sort(tukArticulatonPointove.begin(), tukArticulatonPointove.end());

        for(int i = 0; i < (int)tukArticulatonPointove.size(); i++){
            cout<<tukArticulatonPointove[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
