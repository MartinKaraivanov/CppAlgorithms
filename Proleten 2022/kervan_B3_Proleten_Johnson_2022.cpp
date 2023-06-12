#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int mnogo = 1000000007;

int broiVarhove;
int broiRebra;

struct DanniZaSaseda{
    int doKoi;
    int razstoqnie;
    int nomerRebro;
};

vector<DanniZaSaseda> sasedstvo[500010];

int naiKasoDo[500010];

struct DanniZaRebroto{
    int otKade;
    int doKade;
    int daljina;
    int izpolzvane;
};

DanniZaRebroto rebra[500010];

int naiKasPatDo[500010];

void bellmanFord(int start){

    for(int i = 1; i <= broiVarhove; i++){
        sasedstvo[start].push_back({i, 0, 0});
    }

    for(int i = 0; i <= broiVarhove; i++){
        naiKasPatDo[i] = mnogo;
    }
    naiKasPatDo[start] = 0;

    for(int i = 1; i <= broiVarhove - 1; i++){
        for(int j = 1; j <= broiRebra; j++){
            int otKade = rebra[j].otKade;
            int doKade = rebra[j].doKade;
            int daljina = rebra[j].daljina;

            if(naiKasPatDo[doKade] > naiKasPatDo[otKade] + daljina){
                naiKasPatDo[doKade] = naiKasPatDo[otKade] + daljina;
            }
        }
    }

    while(sasedstvo[start].empty() == false){
        sasedstvo[start].pop_back();
    }

    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 0; j < (int)sasedstvo[i].size(); j++){
            int doKade = sasedstvo[i][j].doKoi;

            int novaDaljina = sasedstvo[i][j].razstoqnie + naiKasPatDo[i] - naiKasPatDo[doKade];

            sasedstvo[i][j].razstoqnie = novaDaljina;
        }
    }
}

struct DanniZaBashtata{
    int koiVrah;
    int koeRebro;
};

DanniZaBashtata bashta[500010];
bool inQueue[500010];

void bfsParviPat(int start, int krai){

    queue<int> q;
    q.push(start);

    inQueue[start] = true;
    bashta[start] = {0, 0};

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        if(naiOtpred == krai){
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred].size(); i++){
            int sledvasht = sasedstvo[naiOtpred][i].doKoi;
            if(inQueue[sledvasht] == false){
                inQueue[sledvasht] = true;
                q.push(sledvasht);
                bashta[sledvasht] = {naiOtpred, sasedstvo[naiOtpred][i].nomerRebro};
            }
        }
    }
}

void mahniRebro(int otKade, int koeRebro){

    for(int i = 0; i < (int)sasedstvo[otKade].size(); i++){
        if(sasedstvo[otKade][i].nomerRebro == koeRebro){
            swap(sasedstvo[otKade][i], sasedstvo[otKade].back());
            break;
        }
    }

    sasedstvo[otKade].pop_back();
}

struct DanniZaOpashkata{
    int vrah;
    int razstoqnieDo;
    int bashta;
    int rebroStignato;

    DanniZaOpashkata(int vrah, int razstoqnieDo, int bashta, int rebroStignato)
        : vrah(vrah), razstoqnieDo(razstoqnieDo), bashta(bashta), rebroStignato(rebroStignato)
    {

    }
};

struct koiEPoNapred{

    bool operator()(DanniZaOpashkata const& a, DanniZaOpashkata const& b)
    {
        return a.razstoqnieDo > b.razstoqnieDo;
    }

};

void deikstraPQ(int start, int krai){

    for(int i = 1; i <= broiVarhove; i++){
        bashta[i] = {0, 0};
        inQueue[i] = false;
    }

    priority_queue<DanniZaOpashkata, vector<DanniZaOpashkata>, koiEPoNapred> q;

    q.push({start, 0, 0, 0});

    while(q.empty() == false){
        DanniZaOpashkata naiOtpred = q.top();
        q.pop();

        if(inQueue[naiOtpred.vrah] == true){
            continue;
        }

        inQueue[naiOtpred.vrah] = true;
        bashta[naiOtpred.vrah] = {naiOtpred.bashta, naiOtpred.rebroStignato};

        if(naiOtpred.vrah == krai){
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred.vrah].size(); i++){
            int sledvasht = sasedstvo[naiOtpred.vrah][i].doKoi;

            if(inQueue[sledvasht] == false){
                q.push({sledvasht, naiOtpred.razstoqnieDo + sasedstvo[naiOtpred.vrah][i].razstoqnie, naiOtpred.vrah, sasedstvo[naiOtpred.vrah][i].nomerRebro});
            }
        }
    }
}


struct DanniZaNovoSasedstvo{
    int doKade;
    int nomerRebro;
};

vector<DanniZaNovoSasedstvo> novoSasedstvo[500010];

bool visitedRebro[500010];

vector<int> patNaobratno[2];

bool daiPatqDo(int segahshen, int krai, int rebroDoTuk, int kadePishem){
    //cout<<"sega izpolzvahme rebro "<<rebroDoTuk<<endl;
    if(visitedRebro[rebroDoTuk] == true){
        return false;
    }
    visitedRebro[rebroDoTuk] = true;

    if(segahshen == krai){
        patNaobratno[kadePishem].push_back(rebroDoTuk);
        return true;
    }

    bool imameLi = false;

    for(int i = 0; i < (int)novoSasedstvo[segahshen].size(); i++){
        imameLi = imameLi | daiPatqDo(novoSasedstvo[segahshen][i].doKade, krai, novoSasedstvo[segahshen][i].nomerRebro, kadePishem);
        if(imameLi == true){
            break;
        }
    }

    if(imameLi == true){
        patNaobratno[kadePishem].push_back(rebroDoTuk);
    }

    return imameLi;
}

int main(){

    cin>>broiVarhove>>broiRebra;

    for(int i = 1; i <= broiRebra; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back({doKade, 1, i});

        rebra[i] = {otKade, doKade, 1, 0};
    }


    bfsParviPat(1, broiVarhove);

    for(int i = broiVarhove; i != 1; i = bashta[i].koiVrah){
        rebra[bashta[i].koeRebro].izpolzvane++;
        sasedstvo[i].push_back({bashta[i].koiVrah, -1, bashta[i].koeRebro});
        mahniRebro(bashta[i].koiVrah, bashta[i].koeRebro);
    }

    //bellmanFord(0);

    deikstraPQ(1, broiVarhove);

    for(int i = broiVarhove; i != 1; i = bashta[i].koiVrah){
        rebra[bashta[i].koeRebro].izpolzvane++;
    }

    for(int i = 1; i <= broiRebra; i++){
        if(rebra[i].izpolzvane == 1){
            novoSasedstvo[rebra[i].otKade].push_back({rebra[i].doKade, i});
        }
    }

    daiPatqDo(1, broiVarhove, 0, 0);
    daiPatqDo(1, broiVarhove, broiRebra + 1, 1);

    cout<<patNaobratno[0].size() - 1<<" "<<patNaobratno[1].size() - 1<<endl;

    for(int j = 0; j < 2; j++){
        for(int i = patNaobratno[j].size() - 2; i >= 0; i--){
            cout<<patNaobratno[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
