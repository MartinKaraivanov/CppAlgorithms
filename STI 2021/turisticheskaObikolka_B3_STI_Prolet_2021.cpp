#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int broiGradove;
int broiRebra;

struct DanniZaRebro{
    int doKoi;
    int nomer;
};

vector<DanniZaRebro> sasedstvo[300010];

int broiPitaniq;
int pitaniq[300010];

int otgovori[300010];

int kogaEPoseten[300010];
int low[300010];

bool otStackaLiE[300010];

int koiVrahGleda[300010];
int broiDopalnitelni;

int zaKolkoVaraSeBroi[300010];

bool vComponentLiE[300010];

stack<int> s;

int vreme;

vector<int> segashenComponent;

void praveneNaKadeGleda(){
    for(int i = 1; i <= broiGradove; i++){
        koiVrahGleda[i] = i;
        zaKolkoVaraSeBroi[i] = 1;
    }
}

void dfs(int segashen, int poRebro){

    vreme++;
    kogaEPoseten[segashen] = vreme;
    low[segashen] = vreme;

    s.push(segashen);
    otStackaLiE[segashen] = true;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        int sledvasht = sasedstvo[segashen][i].doKoi;

        if(sasedstvo[segashen][i].nomer != poRebro){
            if(kogaEPoseten[sledvasht] == 0){
                dfs(sledvasht, sasedstvo[segashen][i].nomer);

                low[segashen] = min(low[segashen], low[sledvasht]);
            }else{
                if(otStackaLiE[sledvasht] == true){
                    low[segashen] = min(low[segashen], kogaEPoseten[sledvasht]);
                }
            }
        }
    }

    if(low[segashen] == kogaEPoseten[segashen]){
        bool a = false;
        while(s.top() != segashen){
            //cout<<"sega slojihme vutre "<<s.top()<<endl;
            a = true;
            segashenComponent.push_back(s.top());
            otStackaLiE[s.top()] = false;
            s.pop();
        }
        if(a == true){
            //cout<<"sega sme na "<<s.top()<<" i slojihme i nego "<<endl;
            segashenComponent.push_back(s.top());

            broiDopalnitelni++;

            for(unsigned int j = 0; j < segashenComponent.size(); j++){
                //cout<<segashenComponent[j]<<" ";
                koiVrahGleda[segashenComponent[j]] = broiDopalnitelni + broiGradove;
                vComponentLiE[segashenComponent[j]] = true;
            }

            for(unsigned int j = 0; j < segashenComponent.size(); j++){
                //cout<<segashenComponent[j]<<" ";
                //cout<<"sega sme v "<<segashenComponent[j]<<endl;
                for(unsigned int k = 0; k < sasedstvo[segashenComponent[j]].size(); k++){
                    //if(vComponentLiE[sasedstvo[segashenComponent[j]][k]] == false){
                        //cout<<"toi ima sased "<<sasedstvo[segashenComponent[j]][k]<<" koito gleda kam ";
                        //cout<<koiVrahGleda[sasedstvo[segashenComponent[j]][k]]<<endl;
                        sasedstvo[koiVrahGleda[segashenComponent[j]]].push_back(
                                                                        sasedstvo[segashenComponent[j]][k]);
                    //}
                }
            }
            //cout<<endl;
            zaKolkoVaraSeBroi[broiDopalnitelni + broiGradove] = segashenComponent.size();
            segashenComponent.clear();
        }
        otStackaLiE[s.top()] = false;
        s.pop();
    }
}

void namiraneNaKomp(){
    for(int i = 1; i <= broiGradove; i++){
        if(kogaEPoseten[i] == 0){
            dfs(i, 0);
        }
    }
}

struct DanniZaNaiDalgiqPat{
    int daljina;
    int prezKoiE;
};

DanniZaNaiDalgiqPat naiDalagNadolu[300010];
DanniZaNaiDalgiqPat vtoriNaiDalaNdlu[300010];

bool visitedNadolu[300010];

int nadolu(int segashen, int otKadeIdvame){
    if(visitedNadolu[segashen] == true){
        return 0;
    }
    visitedNadolu[segashen] = true;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        int sledvasht = koiVrahGleda[sasedstvo[segashen][i].doKoi];
        if(sledvasht != otKadeIdvame){
            int tekushto = nadolu(sledvasht, segashen);
            //cout<<"sega sme v "<<segashen<<" doidohme ot "<<otKadeIdvame;
            //cout<<" bqhme pusnali kum "<<sledvasht<<" i rezultatyt e "<<tekushto<<endl;

            if(tekushto > naiDalagNadolu[segashen].daljina){
                vtoriNaiDalaNdlu[segashen] = naiDalagNadolu[segashen];
                naiDalagNadolu[segashen] = {tekushto, sledvasht};
            }else{
                if(tekushto > vtoriNaiDalaNdlu[segashen].daljina){
                    vtoriNaiDalaNdlu[segashen] = {tekushto, sledvasht};
                }
            }
        }
    }

    return naiDalagNadolu[segashen].daljina + zaKolkoVaraSeBroi[segashen];
}

int naiDalagNagore[300010];

bool visitedNagore[300010];

void nagore(int segashen, int otKadeIdvame, int naiDobrotoOtgore){
    if(visitedNagore[segashen] == true){
        return ;
    }

    visitedNagore[segashen] = true;

    naiDalagNagore[segashen] = naiDobrotoOtgore;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        int sledvasht = koiVrahGleda[sasedstvo[segashen][i].doKoi];
        if(sledvasht != otKadeIdvame){
            int naiDobrotoSledvasht = -1;

            if(naiDalagNadolu[segashen].prezKoiE != sledvasht){
                naiDobrotoSledvasht = naiDalagNadolu[segashen].daljina;
            }else{
                naiDobrotoSledvasht = vtoriNaiDalaNdlu[segashen].daljina;
            }

            nagore(sledvasht, segashen, max(naiDobrotoOtgore, naiDobrotoSledvasht) + zaKolkoVaraSeBroi[segashen]);
        }
    }
}

void praveneNaCentroidnite(){
    for(int i = 1; i <= broiGradove; i++){
        if(visitedNadolu[koiVrahGleda[i]] == false){
            nadolu(koiVrahGleda[i], -1);
            nagore(koiVrahGleda[i], -1, 0);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back({doKade, i + 1});
        sasedstvo[doKade].push_back({otKade, i + 1});
    }

    cin>>broiPitaniq;

    for(int i = 0; i < broiPitaniq; i++){
        cin>>pitaniq[i];
    }

    praveneNaKadeGleda();
    namiraneNaKomp();

    /*for(int i = 1; i <= broiGradove; i++){
        cout<<"vrah sega::::::"<<i<<" "<<koiVrahGleda[i]<<" "<<zaKolkoVaraSeBroi[koiVrahGleda[i]]<<endl;
        for(auto k : sasedstvo[koiVrahGleda[i]]){
            cout<<koiVrahGleda[k]<<" ";
        }
        cout<<endl;
    }*/

    /*for(int i = 1; i <= broiGradove; i++){
        cout<<i<<": ";
        for(auto j : sasedstvo[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/

    praveneNaCentroidnite();

    for(int i = 1; i <= broiGradove; i++){
        naiDalagNadolu[koiVrahGleda[i]].daljina++;
        naiDalagNagore[koiVrahGleda[i]]++;
        /*cout<<koiVrahGleda[i]<<": "<<endl;
        cout<<"nai dalag nadolu "<<naiDalagNadolu[i].daljina<<" i e prez "<<naiDalagNadolu[i].prezKoiE<<endl;
        cout<<"vtori nai dalag nadolu "<<vtoriNaiDalaNdlu[i].daljina<<" i e prez "<<vtoriNaiDalaNdlu[i].prezKoiE<<endl;
        cout<<"nai dalag nagore "<<naiDalagNagore[i]<<endl;*/
    }

    for(int i = 0; i < broiPitaniq; i++){
        int pitane = koiVrahGleda[pitaniq[i]];
        //cout<<pitane<<" ";
        otgovori[i] = max(naiDalagNadolu[pitane].daljina, naiDalagNagore[pitane]);
    }

    for(int i = 0; i < broiPitaniq; i++){
        if(otgovori[i] != 0){
            cout<<otgovori[i]<<" ";
        }
    }

    cout<<endl;

    return 0;
}
