#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int broiEzera;
int broiKanali;
int broiPitaniq;

struct DanniZaSaseda{
    int otKade;
    int koiE;
    int shirochina;

    DanniZaSaseda(int otKade, int koiE, int shirochina)
        : otKade(otKade), koiE(koiE), shirochina(shirochina)
    {

    }
};

struct koiEPoNapred{
    bool operator()(DanniZaSaseda const& a, DanniZaSaseda const& b)
    {
        return a.shirochina < b.shirochina;
    }
};

vector<DanniZaSaseda> sasedstvo[1010];

bool otDarvotoLiE[1010];

struct DanniZaNoviqSased{
    int doKoi;
    int shirochina;
};

vector<DanniZaNoviqSased> novoSasedstvo[1010];

priority_queue<DanniZaSaseda, vector<DanniZaSaseda>, koiEPoNapred> q;

int dalbochina[1010];

struct DanniZaAncestora{
    int koieE;
    int shirochina;
};
vector<DanniZaAncestora> pow2ancestors[1010];

void dfsAncestori(int segashen, int otKadeIdvame, int dalb, int shir){
    pow2ancestors[segashen].push_back({segashen, 0});

    if(otKadeIdvame != -1){
        pow2ancestors[segashen].push_back({otKadeIdvame, shir});
    }

    dalbochina[segashen] = dalb;

    for(int i = 0; i < (int)novoSasedstvo[segashen].size(); i++){
        if(novoSasedstvo[segashen][i].doKoi != otKadeIdvame){
            dfsAncestori(novoSasedstvo[segashen][i].doKoi, segashen, dalb + 1, novoSasedstvo[segashen][i].shirochina);
        }
    }

}

void praveneNaDrugiteAncestori(){
    bool pravimLiNeshto = true;

    for(int pow2rastoqnie = 2; pravimLiNeshto == true; pow2rastoqnie++){
        pravimLiNeshto = false;
        for(int ezero = 1; ezero <= broiEzera; ezero++){
            if((long long)pow2ancestors[ezero].size() > pow2rastoqnie-1){
                int mnogoPradqdo = pow2ancestors[ezero][pow2rastoqnie - 1].koieE;
                if(mnogoPradqdo != -1 && (long long)pow2ancestors[mnogoPradqdo].size() > pow2rastoqnie - 1){
                    pow2ancestors[ezero].push_back(pow2ancestors[mnogoPradqdo][pow2rastoqnie - 1]);
                    int razm = pow2ancestors[ezero].size();
                    pow2ancestors[ezero][razm - 1].shirochina =
                        min(pow2ancestors[ezero][razm - 1].shirochina, pow2ancestors[ezero][razm - 2].shirochina);
                    pravimLiNeshto = true;
                }
            }
        }
    }
}

void praveneNaDarvoto(){
    otDarvotoLiE[1] = true;

    for(int i = 0; i < (int)sasedstvo[1].size(); i++){
        q.push(sasedstvo[1][i]);
    }

    int broiVDarvoto = 1;

    while(broiVDarvoto < broiEzera){
        DanniZaSaseda naiOtpred = q.top();
        q.pop();

        if(otDarvotoLiE[naiOtpred.koiE] == false){
            otDarvotoLiE[naiOtpred.koiE] = true;
            broiVDarvoto++;

            novoSasedstvo[naiOtpred.otKade].push_back({naiOtpred.koiE, naiOtpred.shirochina});

            for(int i = 0; i < (int)sasedstvo[naiOtpred.koiE].size(); i++){
                if(otDarvotoLiE[sasedstvo[naiOtpred.koiE][i].koiE] == false){
                    q.push(sasedstvo[naiOtpred.koiE][i]);
                }
            }
        }
    }

    dfsAncestori(1, -1, 1, 0);
    praveneNaDrugiteAncestori();
}

DanniZaAncestora lca(int naParvi, int naVtori){
    int segashnoOtKade = naParvi;
    int segashnoDoKade = naVtori;

    if(dalbochina[segashnoOtKade] < dalbochina[segashnoDoKade]){
        swap(segashnoOtKade, segashnoDoKade);
    }

    int razlikaVNivata = dalbochina[segashnoOtKade] - dalbochina[segashnoDoKade];

    int minShiroch = 222;

    for(int i = 1; razlikaVNivata > 0; i++){
        if(razlikaVNivata % 2 == 1){
            minShiroch = min(minShiroch, pow2ancestors[segashnoOtKade][i].shirochina);
            segashnoOtKade = pow2ancestors[segashnoOtKade][i].koieE;
            //cout<<"po vreme na izravnqvaneto: "<<minShiroch<<" "<<pow2ancestors[segashnoOtKade][i].shirochina<<endl;
        }
        razlikaVNivata /= 2;
    }

    if(segashnoOtKade == segashnoDoKade){
        return {segashnoOtKade, minShiroch};
    }

    int i = pow2ancestors[segashnoOtKade].size() - 1;

    //cout<<"predi sledvashtoto "<<minShiroch<<endl;

    while(i > 0){

        if(pow2ancestors[segashnoOtKade][i].koieE != pow2ancestors[segashnoDoKade][i].koieE){
            minShiroch =
                min(minShiroch, min(pow2ancestors[segashnoOtKade][i].shirochina, pow2ancestors[segashnoDoKade][i].shirochina));

            //cout<<"po vreme na cikula "<<minShiroch<<" "<<pow2ancestors[segashnoOtKade][i].shirochina;
            //cout<<" "<<pow2ancestors[segashnoDoKade][i].shirochina<<endl;

            segashnoOtKade = pow2ancestors[segashnoOtKade][i].koieE;
            segashnoDoKade = pow2ancestors[segashnoDoKade][i].koieE;

            i = min((int)pow2ancestors[segashnoOtKade].size() - 1, i - 1);
        }else{
            i--;
        }
    }

    int lowestCommonAncestor = pow2ancestors[segashnoOtKade][1].koieE;
    minShiroch =
        min(minShiroch, min(pow2ancestors[segashnoOtKade][1].shirochina, pow2ancestors[segashnoDoKade][1].shirochina));

    return {lowestCommonAncestor, minShiroch};
}

int naiMalakOtDo(int segashen, int koiTarsim){
    if(segashen == koiTarsim){
        return 222;
    }

    int naiMalkoto = 222;

    int segEzero = segashen;

    //cout<<"tarsim ot "<<segashen<<" do "<<koiTarsim<<endl;

    while(segEzero != koiTarsim){
        DanniZaAncestora sledvasht = pow2ancestors[segEzero][1];

        //cout<<"sega sum na "<<segEzero<<" sledvashtiq e "<<sledvasht.koieE<<" s shir "<<sledvasht.shirochina<<endl;

        naiMalkoto = min(naiMalkoto, sledvasht.shirochina);
        segEzero = sledvasht.koieE;
    }

    return naiMalkoto;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiEzera>>broiKanali>>broiPitaniq;

    for(int i = 0; i < broiKanali; i++){
        int otKade;
        int doKade;
        int shiroch;

        cin>>otKade>>doKade>>shiroch;

        sasedstvo[otKade].push_back({otKade, doKade, shiroch});
        sasedstvo[doKade].push_back({doKade, otKade, shiroch});
    }

    praveneNaDarvoto();

    /*for(int i = 1; i <= broiEzera; i++){
        cout<<i<<": "<<endl;
        for(DanniZaAncestora j : pow2ancestors[i]){
            cout<<j.koieE<<" "<<j.shirochina<<endl;
        }
    }*/

    for(int i = 0; i < broiPitaniq; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        DanniZaAncestora lowestCA = lca(otKade, doKade);

        cout<<lowestCA.shirochina<<endl;

        /*int ednotoNaiMalko = naiMalakOtDo(otKade, lowestCA);
        int drugotoNaiMalko = naiMalakOtDo(doKade, lowestCA);

        cout<<min(ednotoNaiMalko, drugotoNaiMalko)<<endl;*/
    }

    return 0;
}
