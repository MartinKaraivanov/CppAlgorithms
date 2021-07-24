#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaSaseda{
    int koiSased;
    int razstoqnie;
};

struct DanniZaKvartala{
    int nomerNaKvartala;
    int razstoqnieDoNego;

    DanniZaKvartala(int nomerNaKvartala, int razstoqnieDoNego)
        : nomerNaKvartala(nomerNaKvartala), razstoqnieDoNego(razstoqnieDoNego)
    {

    }
};

struct DanniZaKvartalaNaPetuk13{
    int nomerNaKvartala;
    int razstoqnieDoNego;
    int priOstatuci;

    DanniZaKvartalaNaPetuk13(int nomerNaKvartala, int razstoqnieDoNego, int priOstatuci)
        : nomerNaKvartala(nomerNaKvartala), razstoqnieDoNego(razstoqnieDoNego), priOstatuci(priOstatuci)
    {

    }
};

struct sravnenie{
    bool operator()(DanniZaKvartala const& a, DanniZaKvartala const& b){
        return a.razstoqnieDoNego > b.razstoqnieDoNego;
    }
};

struct sravnenieZaPetuk13{
    bool operator()(DanniZaKvartalaNaPetuk13 const& a, DanniZaKvartalaNaPetuk13 const& b){
        return a.razstoqnieDoNego > b.razstoqnieDoNego;
    }
};

int broiPatuvaniq;

int broiKvartali;
int broiTransporti;

vector<DanniZaSaseda> sasedstvo[55];

string petuk13LiE;

int bfs(){
    bool visited[55];

    for(int i = 0; i <= broiKvartali; i++){
        visited[i] = false;
    }

    priority_queue<DanniZaKvartala, vector<DanniZaKvartala>, sravnenie> q;

    DanniZaKvartala startovo = {1, 0};
    q.push(startovo);

    int iskanoRazstoqnie = -1;

    while(q.empty() == false){
        DanniZaKvartala naiOtgorno = q.top();
        q.pop();

        if(visited[naiOtgorno.nomerNaKvartala] == true){
            continue;
        }

        visited[naiOtgorno.nomerNaKvartala] = true;

        if(naiOtgorno.nomerNaKvartala == broiKvartali && naiOtgorno.razstoqnieDoNego > 0){
            iskanoRazstoqnie = naiOtgorno.razstoqnieDoNego;
            break;
        }

        for(unsigned int i = 0; i < sasedstvo[naiOtgorno.nomerNaKvartala].size(); i++){
            if(visited[sasedstvo[naiOtgorno.nomerNaKvartala][i].koiSased] == false){
                q.push({sasedstvo[naiOtgorno.nomerNaKvartala][i].koiSased,
                       sasedstvo[naiOtgorno.nomerNaKvartala][i].razstoqnie + naiOtgorno.razstoqnieDoNego});
            }
        }

    }

    if(visited[broiKvartali] == true){
        return iskanoRazstoqnie;
    }else{
        return -1;
    }
}

int kakuvEBitaNaPoziciq(int chislo, int poziciq){
    return (chislo >> poziciq) & 1;
}

int slozhiNaTovaNaPoziciq(int chislo, int poziciq){
    return chislo | (1 << poziciq);
}

bool visited[55][8201];

int bfsZaPetuk13(){

    for(int i = 0; i <= broiKvartali; i++){
        for(int j = 0; j <= 8200; j++){
            visited[i][j] = false;
        }
    }

    priority_queue<DanniZaKvartalaNaPetuk13, vector<DanniZaKvartalaNaPetuk13>, sravnenieZaPetuk13> q;

    DanniZaKvartalaNaPetuk13 startovo = {1, 0, 1};

    q.push(startovo);

    int razstonie = -1;

    while(q.empty() == false){
        DanniZaKvartalaNaPetuk13 naiOtgore = q.top();
        q.pop();

        cout<<naiOtgore.nomerNaKvartala<<" "<<naiOtgore.razstoqnieDoNego<<" "<<naiOtgore.priOstatuci<<endl;

        if(visited[naiOtgore.nomerNaKvartala][naiOtgore.priOstatuci] == true){
            cout<<"Tova sum go poseshtaval!"<<endl;
            //continue;
        }

        visited[naiOtgore.nomerNaKvartala][naiOtgore.priOstatuci] = true;

        if((naiOtgore.nomerNaKvartala == broiKvartali) && naiOtgore.razstoqnieDoNego > 0){
            razstonie = naiOtgore.razstoqnieDoNego;
            break;
        }


        for(unsigned int i = 0; i < sasedstvo[naiOtgore.nomerNaKvartala].size(); i++){
            int novoRazstoqnie = naiOtgore.razstoqnieDoNego + sasedstvo[naiOtgore.nomerNaKvartala][i].razstoqnie;

            if(kakuvEBitaNaPoziciq(naiOtgore.priOstatuci, novoRazstoqnie%13) == 0){
                int noviOstatuci = slozhiNaTovaNaPoziciq(naiOtgore.priOstatuci, novoRazstoqnie%13);
                //if(visited[sasedstvo[naiOtgore.nomerNaKvartala][i].koiSased][noviOstatuci] == false){
                    q.push({sasedstvo[naiOtgore.nomerNaKvartala][i].koiSased,
                            novoRazstoqnie,
                            noviOstatuci});
                //}
           }
        }
    }

    return razstonie;
}

void nulirane(){
    for(int i = 1; i <= broiKvartali; i++){
        sasedstvo[i].clear();
    }
    for(int i = 0; i <= broiKvartali; i++){
        for(int j = 0; j <= 8200; j++){
            visited[i][j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiPatuvaniq;

    for(int p = 0; p < broiPatuvaniq; p++){
        cin>>broiKvartali>>broiTransporti;

        for(int i = 0; i < broiTransporti; i++){
            int otKade;
            int doKade;
            int kolkoEDalgo;
            cin>>otKade>>doKade>>kolkoEDalgo;
            sasedstvo[otKade].push_back({doKade, kolkoEDalgo});
        }

        cin>>petuk13LiE;

        if(petuk13LiE == "True"){
            cout<<bfsZaPetuk13()<<endl;
        }else{
            cout<<bfs()<<endl;
        }

        nulirane();
    }

    return 0;
}
