#include<iostream>
#include<queue>
using namespace std;

int broiHora;
long long minimalnaRabotnaZaplata;

vector<int> naKoiMozheDaBadeShef[5010];

vector<int> toziNaKoiEShef[5010];

bool visited[5010];

long long bfs(int naiGolemiqShef){

    /*for(int i = 1; i <= broiHora; i++){
        visited[i] = false;
    }*/

    int naKakvaDalbochina[5010];

    for(int i = 1; i <= broiHora; i++){
        naKakvaDalbochina[i] = 0;
    }

    queue<int> q;

    q.push(naiGolemiqShef);
    naKakvaDalbochina[naiGolemiqShef] = 1;
    //visited[naiGolemiqShef] = true;

    int sumichka = 0;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        /*if(visited[vrah] && vrah!=naiGolemiqShef){
            continue;
        }

        visited[vrah] = true;*/

        sumichka+=naKakvaDalbochina[vrah];

        for(unsigned int i = 0; i < naKoiMozheDaBadeShef[vrah].size(); i++){
            if(naKakvaDalbochina[naKoiMozheDaBadeShef[vrah][i]] == 0){
                q.push(naKoiMozheDaBadeShef[vrah][i]);
                //visited[naKoiMozheDaBadeShef[vrah][i]] = true;
                naKakvaDalbochina[naKoiMozheDaBadeShef[vrah][i]] = naKakvaDalbochina[vrah] + 1;
                //toziNaKoiEShef[vrah].push_back(naKoiMozheDaBadeShef[vrah][i]);
            }
        }
    }

    for(int i = 1; i <= broiHora; i++){
        if(naKakvaDalbochina[i] == 0){
            return 100000000000;
        }
    }

    return sumichka;
}

long long priTolkova[5010];

long long minimalnaZaplata(int chovek){
    if(priTolkova[chovek] > 0){
        return priTolkova[chovek];
    }

    long long sumarno = minimalnaRabotnaZaplata;

    for(unsigned int i = 0; i < toziNaKoiEShef[chovek].size(); i++){
        sumarno += minimalnaZaplata(toziNaKoiEShef[chovek][i]);
    }

    priTolkova[chovek] = sumarno;
    return sumarno;
}

void nuliranePriNovShef(){
    for(int i = 1; i <= broiHora; i++){
        priTolkova[i] = 0;
        toziNaKoiEShef[i].clear();
        visited[i] = false;
    }
}

bool vsichkiLiSaVisited(){
    bool vsichkiLiSaVis = true;
    for(int i = 1; i <= broiHora; i++){
        if(visited[i] == false){
            vsichkiLiSaVis = false;
            break;
        }
    }
    return vsichkiLiSaVis;
}

int main(){
    cin>>broiHora>>minimalnaRabotnaZaplata;

    for(int i = 1; i <= broiHora; i++){
        int broiche;
        cin>>broiche;
        for(int j = 0; j < broiche; j++){
            int chovek;
            cin>>chovek;
            naKoiMozheDaBadeShef[chovek].push_back(i);
        }
    }

    long long naiMalkaSumaNaZaplatkiNaVsichkiNaiDobro = 100000000000;

    for(int i = 1; i <= broiHora; i++){
        //nuliranePriNovShef();
        long long priToziShef = bfs(i);
        /*if(!vsichkiLiSaVisited()){
            continue;
        }
        long long segashnaSumichkaNaZaplatki = 0;
        for(int j = 1; j <= broiHora; j++){
            segashnaSumichkaNaZaplatki+=minimalnaZaplata(j);
        }*/
        naiMalkaSumaNaZaplatkiNaVsichkiNaiDobro = min(naiMalkaSumaNaZaplatkiNaVsichkiNaiDobro, priToziShef);
    }

    cout<<naiMalkaSumaNaZaplatkiNaVsichkiNaiDobro*minimalnaRabotnaZaplata<<endl;

    return 0;
}
