#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaSased{
    int doKoi;
    int capacitet;
    int rCapacitet;
};

struct DanniZaDelta{
    int poX;
    int poY;
};

int broiTestove;

int broiPolencaVPosoka;

int nomerche;
char tablica[55][55];
int naTovaMqstoSKoeNomercheE[55][55];

vector<DanniZaSased> sasedstvo[2505];

int parents[2505];

int otgovori[100];

DanniZaDelta delti[8];

void nulirane(){
    for(int i = 0; i <= nomerche; i++){
        sasedstvo[i].clear();
    }
    for(int i = 0; i < broiPolencaVPosoka; i++){
        for(int j = 0; j < broiPolencaVPosoka; j++){
            tablica[i][j] = '0';
            naTovaMqstoSKoeNomercheE[i][j] = -1;
        }
    }
    nomerche = 0;
}

bool bfs(int start, int krai){
    bool visited[2505];

    for(int i = 0; i <= nomerche; i++){
        visited[i] = false;
        parents[i] = -1;
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        if(vrah == krai){
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

    return visited[krai];
}

void promeniRCapacitetS(int otKoi, int doKoi, int rCapacitet){
    for(unsigned int a = 0; a < sasedstvo[otKoi].size(); a++){
        if(doKoi == sasedstvo[otKoi][a].doKoi){
            sasedstvo[otKoi][a].rCapacitet += rCapacitet;
            return;
        }
    }
}

int FordFulkersonFlow(int start, int krai){

    for(int i = 0; i <= nomerche; i++){
        for(unsigned int j = 0; j < sasedstvo[i].size(); j++){
            sasedstvo[i][j].rCapacitet = sasedstvo[i][j].capacitet;
        }
    }

    int maxFlow = 0;

    while(true){
        bool stigameLi = bfs(start, krai);
        if(!stigameLi){
            break;
        }

        int minimalenFlow = 1;

        for(int v = krai; v != start; v= parents[v]){
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

void praveneNaDeltite(){
    delti[0] = {-1, -2};
    delti[1] = {1, -2};
    delti[2] = {2, -1};
    delti[3] = {2, 1};
    delti[4] = {1, 2};
    delti[5] = {-1, 2};
    delti[6] = {-2, 1};
    delti[7] = {-2, -1};
}

int main(){
    cin>>broiTestove;

    praveneNaDeltite();

    for(int i = 0; i < broiTestove; i++){
        nulirane();
        cin>>broiPolencaVPosoka;

        for(int y = 0; y < broiPolencaVPosoka; y++){
            for(int x = 0; x < broiPolencaVPosoka; x++){
                cin>>tablica[x][y];
            }
        }

        int start = 0;
        int krai = 1;

        nomerche++;

        for(int y = 0; y < broiPolencaVPosoka; y++){
            for(int x = 0; x < broiPolencaVPosoka; x++){
                if(tablica[x][y] == 'K'){
                    nomerche++;
                    naTovaMqstoSKoeNomercheE[x][y] = nomerche;
                }
            }
        }

        for(int y = 0; y < broiPolencaVPosoka; y++){
            for(int x = 0; x < broiPolencaVPosoka; x++){
                if(tablica[x][y] == 'K'){
                    if((x + y) % 2 == 0){
                        dobavqneNaDaga(start, naTovaMqstoSKoeNomercheE[x][y]);
                    }else{
                        dobavqneNaDaga(naTovaMqstoSKoeNomercheE[x][y], krai);
                    }
                }
            }
        }

        for(int y = 0; y < broiPolencaVPosoka; y++){
            for(int x = 0; x < broiPolencaVPosoka; x++){
                if(tablica[x][y] == 'K'){
                    int nomerNaNashiqKon = naTovaMqstoSKoeNomercheE[x][y];
                    if((x + y) % 2 == 0){
                        for(int d = 0; d < 8; d++){
                            if(y + delti[d].poY < broiPolencaVPosoka && y + delti[d].poY >= 0 &&
                               x + delti[d].poX < broiPolencaVPosoka && x + delti[d].poX >= 0)
                            {
                                if(tablica[x + delti[d].poX][y + delti[d].poY] == 'K'){
                                    dobavqneNaDaga(nomerNaNashiqKon, naTovaMqstoSKoeNomercheE[x+delti[d].poX][y+delti[d].poY]);
                                }
                            }
                        }
                    }
                }
            }
        }

        /*for(int y = 0; y < broiPolencaVPosoka; y++){
            for(int x = 0; x < broiPolencaVPosoka; x++){
                if(tablica[x][y] == 'K'){
                    int nomercheNaNashiqKon = naTovaMqstoSKoeNomercheE[x][y];
                    if(y % 2 == 0){
                        if(x % 2 == 0){
                            if(x - 2 >= 0){
                                if(y - 1 >= 0){
                                    if(tablica[x - 2][y - 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 2][y - 1]);
                                    }
                                }
                                if(y + 1 < broiPolencaVPosoka){
                                    if(tablica[x - 2][y + 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 2][y + 1]);
                                    }
                                }
                            }
                            if(x + 2 < broiPolencaVPosoka){
                                if(y - 1 >= 0){
                                    if(tablica[x + 2][y - 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 2][y - 1]);
                                    }
                                }
                                if(y + 1 < broiPolencaVPosoka){
                                    if(tablica[x + 2][y + 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 2][y + 1]);
                                    }
                                }
                            }
                            if(y - 2 >= 0){
                                if(x - 1 >= 0){
                                    if(tablica[x - 1][y - 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 1][y - 2]);
                                    }
                                }
                                if(x + 1 < broiPolencaVPosoka){
                                    if(tablica[x + 1][y - 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 1][y - 2]);
                                    }
                                }
                            }
                            if(y + 2 < broiPolencaVPosoka){
                                if(x - 1 >= 0){
                                    if(tablica[x - 1][y + 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 1][y + 2]);
                                    }
                                }
                                if(x + 1 < broiPolencaVPosoka){
                                    if(tablica[x + 1][y + 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 1][y + 2]);
                                    }
                                }
                            }
                        }
                    }else{
                        if(x % 2 == 1){
                            if(x - 2 >= 0){
                                if(y - 1 >= 0){
                                    if(tablica[x - 2][y - 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 2][y - 1]);
                                    }
                                }
                                if(y + 1 < broiPolencaVPosoka){
                                    if(tablica[x - 2][y + 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 2][y + 1]);
                                    }
                                }
                            }
                            if(x + 2 < broiPolencaVPosoka){
                                if(y - 1 >= 0){
                                    if(tablica[x + 2][y - 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 2][y - 1]);
                                    }
                                }
                                if(y + 1 < broiPolencaVPosoka){
                                    if(tablica[x + 2][y + 1] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 2][y + 1]);
                                    }
                                }
                            }
                            if(y - 2 >= 0){
                                if(x - 1 >= 0){
                                    if(tablica[x - 1][y - 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 1][y - 2]);
                                    }
                                }
                                if(x + 1 < broiPolencaVPosoka){
                                    if(tablica[x + 1][y - 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 1][y - 2]);
                                    }
                                }
                            }
                            if(y + 2 < broiPolencaVPosoka){
                                if(x - 1 >= 0){
                                    if(tablica[x - 1][y + 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x - 1][y + 2]);
                                    }
                                }
                                if(x + 1 < broiPolencaVPosoka){
                                    if(tablica[x + 1][y + 2] == 'K'){
                                        dobavqneNaDaga(nomercheNaNashiqKon, naTovaMqstoSKoeNomercheE[x + 1][y + 2]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }*/

        /*for(int k = 0; k <= nomerche; k++){
            for(DanniZaSased j : sasedstvo[k]){
                if(j.capacitet > 0){
                    cout<<k<<" "<<j.doKoi<<endl;
                }
            }
        }

        cout<<endl<<endl<<endl<<endl;*/

        int potokTuk = FordFulkersonFlow(start, krai);

        otgovori[i] = potokTuk;
    }

    for(int i = 0; i < broiTestove; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
