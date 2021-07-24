#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaSased{
    int doKoi;
    int capacitet;
    int rCapacitet;
};

int maxY;
int maxX;

char vavedeno[905];

int naTovaMqstoVlizashtVrah[35][35];
int naTovaMqstoIzlizashtVrah[35][35];
int nomerche;

vector<DanniZaSased> sasedstvo[2000];

bool tukImaLiKotka[35][35];

int bfs(int start, int finaal, int parents[2000]){
    bool visited[2000];

    for(int i = start; i <= nomerche; i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        if(vrah == finaal){
            break;
        }

        for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
            DanniZaSased sledvasht = sasedstvo[vrah][i];
            if(visited[sledvasht.doKoi] == false && sledvasht.rCapacitet > 0){
                q.push(sledvasht.doKoi);
                parents[sledvasht.doKoi] = vrah;
                visited[sledvasht.doKoi] = true;
            }
        }
    }

    //cout<<visited[finaal]<<endl;
    return visited[finaal];
}

void promeniRCapacitetS(int otKoi, int doKoi, int rCapacitet){
    for(unsigned int a = 0; a < sasedstvo[otKoi].size(); a++){
        if(doKoi == sasedstvo[otKoi][a].doKoi){
            sasedstvo[otKoi][a].rCapacitet += rCapacitet;
            return;
        }
    }
}

void inicializiraneNaRsasedstvo(){
    for(int i = 0; i <= nomerche; i++){
        for(unsigned int j = 0; j < sasedstvo[i].size(); j++){
            sasedstvo[i][j].rCapacitet = sasedstvo[i][j].capacitet;
        }
    }
}

int FordFulkersonFlow(int start, int finaal){

    int maxFlow = 0;

    while(true){
        int parents[2000];
        bool stigameLi = bfs(start, finaal, parents);

        if(stigameLi == false){
            break;
        }

        int minimalenFlow = 1;

        for(int v = finaal; v != start; v = parents[v]){
            int u = parents[v];
            promeniRCapacitetS(u, v, -minimalenFlow);
            promeniRCapacitetS(v, u, minimalenFlow);
        }

        maxFlow += minimalenFlow;
    }

    return maxFlow;
}

void dobavqneNaDaga(int parviVrah, int vtoriVrah){
    DanniZaSased zaDob = {vtoriVrah, 1, 0};
    sasedstvo[parviVrah].push_back(zaDob);
    zaDob = {parviVrah, 0, 0};
    sasedstvo[vtoriVrah].push_back(zaDob);
}

int main(){
    cin>>maxY;

    char tuka;
    int broiVavedeniPolet = 0;

    while(cin>>tuka){
        if(tuka == '0' || tuka == '1'){
            vavedeno[broiVavedeniPolet] = tuka;
            broiVavedeniPolet++;
        }
    }

    maxX = broiVavedeniPolet/maxY;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            if(vavedeno[y*maxX + x] - '0' == 1){
                tukImaLiKotka[x][y] = true;
            }
        }
    }

    int startov = 0;
    int finaalen = 1;

    nomerche = 1;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            nomerche++;
            naTovaMqstoVlizashtVrah[x][y] = nomerche;
            nomerche++;
            naTovaMqstoIzlizashtVrah[x][y] = nomerche;
        }
    }

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            if(tukImaLiKotka[x][y] == true){
                dobavqneNaDaga(startov, naTovaMqstoVlizashtVrah[x][y]);
            }
        }
    }

    for(int x = 1; x < maxX - 1; x++){
        dobavqneNaDaga(naTovaMqstoIzlizashtVrah[x][0], finaalen);
        dobavqneNaDaga(naTovaMqstoIzlizashtVrah[x][maxY - 1], finaalen);
    }

    for(int y = 0; y < maxY; y++){
        dobavqneNaDaga(naTovaMqstoIzlizashtVrah[0][y], finaalen);
        dobavqneNaDaga(naTovaMqstoIzlizashtVrah[maxX - 1][y], finaalen);
    }

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int nachalnoto = naTovaMqstoVlizashtVrah[x][y];
            int krainoto = naTovaMqstoIzlizashtVrah[x][y];
            dobavqneNaDaga(nachalnoto, krainoto);
        }
    }

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int nomerNaIzlizahtotoTuk = naTovaMqstoIzlizashtVrah[x][y];
            if(x > 0){
                int nomerNaVlizashtoto = naTovaMqstoVlizashtVrah[x-1][y];
                dobavqneNaDaga(nomerNaIzlizahtotoTuk, nomerNaVlizashtoto);
            }
            if(x < maxX - 1){
                int nomerNaVlizashtoto = naTovaMqstoVlizashtVrah[x+1][y];
                dobavqneNaDaga(nomerNaIzlizahtotoTuk, nomerNaVlizashtoto);
            }
            if(y > 0){
                int nomerNaVlizashtoto = naTovaMqstoVlizashtVrah[x][y-1];
                dobavqneNaDaga(nomerNaIzlizahtotoTuk, nomerNaVlizashtoto);
            }
            if(y < maxY - 1){
                int nomerNaVlizashtoto = naTovaMqstoVlizashtVrah[x][y+1];
                dobavqneNaDaga(nomerNaIzlizahtotoTuk, nomerNaVlizashtoto);
            }
        }
    }

    /*for(int i = 0; i <= nomerche; i++){
        for(DanniZaSased j : sasedstvo[i]){
            cout<<i<<" "<<j.doKoi<<" "<<j.capacitet<<endl;
        }
    }*/

    inicializiraneNaRsasedstvo();

    int broiIzlizashtiKoteta = FordFulkersonFlow(startov, finaalen);

    cout<<broiIzlizashtiKoteta<<endl;

    return 0;
}
