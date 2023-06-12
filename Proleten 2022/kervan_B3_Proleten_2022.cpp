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
    int nomerRebro;
    int cena;
    int capacitet;
};

vector<DanniZaSaseda> sasedstvo[500010];

int naiKasoDo[500010];

struct DanniZaBashtata{
    int koiVrah;
    int koeRebro;
};

DanniZaBashtata bashta[500010];

struct DanniZaRebroto{
    int otKade;
    int doKade;
    int razlikaCapaciteti;
};

DanniZaRebroto rebra[500010];

bool vOpashkataLiE[500010];

void naiKasPatOt(int start){

    for(int i = 1; i <= broiVarhove; i++){
        naiKasoDo[i] = mnogo;
        bashta[i] = {0, 0};
        vOpashkataLiE[i] = false;
    }
    naiKasoDo[start] = 0;

    queue<int> q;
    q.push(start);

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();
        vOpashkataLiE[naiOtpred] = false;

        for(int i = 0; i < (int)sasedstvo[naiOtpred].size(); i++){
            if(sasedstvo[naiOtpred][i].capacitet > 0 && naiKasoDo[sasedstvo[naiOtpred][i].doKoi] > naiKasoDo[naiOtpred] + sasedstvo[naiOtpred][i].cena){
                naiKasoDo[sasedstvo[naiOtpred][i].doKoi] = naiKasoDo[naiOtpred] + sasedstvo[naiOtpred][i].cena;
                bashta[sasedstvo[naiOtpred][i].doKoi] = {naiOtpred, sasedstvo[naiOtpred][i].nomerRebro};
                if(vOpashkataLiE[sasedstvo[naiOtpred][i].doKoi] == false){
                    vOpashkataLiE[sasedstvo[naiOtpred][i].doKoi] = true;
                    q.push(sasedstvo[naiOtpred][i].doKoi);
                }
            }
        }
    }
}


void dobaviPotok(int otKade, int koeRebro, int kolkoPotok){
    for(int i = 0; i < (int)sasedstvo[otKade].size(); i++){
        if(sasedstvo[otKade][i].nomerRebro == koeRebro){
            sasedstvo[otKade][i].capacitet += kolkoPotok;
            break;
        }
    }

}

void maxFlowMinPrice(int start, int krai){

    while(true){
        naiKasPatOt(start);
        //cout<<"vrashtame se "<<obshtPotok<<"viq pat"<<endl;

        if(naiKasoDo[krai] == mnogo){
            break;
        }

        int tekushtPotok = 1;

        //cout<<"obratniq pat e: "<<endl;
        for(int v = krai; v != -1; v = bashta[v].koiVrah){
            //cout<<v<<" ";
            dobaviPotok(bashta[v].koiVrah, bashta[v].koeRebro, -tekushtPotok);
            dobaviPotok(v, bashta[v].koeRebro, tekushtPotok);
        }
        //cout<<endl;
        //cout<<"cenata mu e "<<naiKasoDo[krai]<<endl;
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

        sasedstvo[otKade].push_back({doKade, i, 1, 1});
        sasedstvo[doKade].push_back({otKade, i, -1, 0});

        rebra[i] = {otKade, doKade, 0};
    }

    sasedstvo[0].push_back({1, 0, 1, 2});
    bashta[0] = {-1, -1};

    maxFlowMinPrice(0, broiVarhove);

    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 0; j < (int)sasedstvo[i].size(); j++){
            DanniZaSaseda sledvasht = sasedstvo[i][j];

            rebra[sledvasht.nomerRebro].razlikaCapaciteti += -1*sledvasht.cena*sledvasht.capacitet;
        }
    }

    for(int i = 1; i <= broiRebra; i++){
        if(rebra[i].razlikaCapaciteti > 0){
            novoSasedstvo[rebra[i].otKade].push_back({rebra[i].doKade, i});
        }
    }

    daiPatqDo(1, broiVarhove, 0, 0);
    daiPatqDo(1, broiVarhove, broiRebra + 1, 1);

    cout<<patNaobratno[0].size() - 1<<" "<<patNaobratno[1].size() - 1<<endl;

    for(int i = patNaobratno[0].size() - 2; i >= 0; i--){
        cout<<patNaobratno[0][i]<<" ";
    }
    cout<<endl;

    for(int i = patNaobratno[1].size() - 2; i >= 0; i--){
        cout<<patNaobratno[1][i]<<" ";
    }
    cout<<endl;

    return 0;
}
