#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaSased{
    int doKoi;
    int capacitet;
    int obratenCapacitet;
};

const int MAX_X = 25;///koloni
const int MAX_Y = 1005;///redove
const int MAX_VARHOVE = MAX_X*MAX_Y;

int maxX;
int maxY;

bool tukaStolaHubavLiE[MAX_X][MAX_Y];

int kolkoOkStolaImaDoToziY[MAX_Y];

DanniZaTochka tovaNomercheKoqTochkaE[MAX_VARHOVE];
int naTovaMqstoKoeNomercheE[MAX_X][MAX_Y];

vector<DanniZaSased> sasedstvo[MAX_VARHOVE];

bool visited[MAX_VARHOVE];
int parents[MAX_VARHOVE];

bool bfs(int start, int krai, int naiGolqmo){

    for(int i = 0; i <= naiGolqmo; i++){
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
            if(visited[sledvasht.doKoi] == false && sledvasht.obratenCapacitet > 0 && sledvasht.doKoi <= naiGolqmo){
                q.push(sledvasht.doKoi);
                visited[sledvasht.doKoi] = true;
                parents[sledvasht.doKoi] = vrah;
            }
        }
    }

    return visited[krai];
}

void promeniRCapacitetS(int otKoi, int doKoi, int rCapacitet){
    for(unsigned int a = 0; a < sasedstvo[otKoi].size(); a++){
        if(doKoi == sasedstvo[otKoi][a].doKoi){
            sasedstvo[otKoi][a].obratenCapacitet += rCapacitet;
            return;
        }
    }
    cout<<"Ne go namerih "<<endl;
}

void praveneNaRSasedstvoto(int naiGolqmo){
    //cout<<"v praveneto na rsasedstvoto "<<naiGolqmo<<endl;
    for(int i = 0; i <= naiGolqmo; i++){
        for(unsigned int j = 0; j < sasedstvo[i].size(); j++){
            sasedstvo[i][j].obratenCapacitet = sasedstvo[i][j].capacitet;
        }
    }
}

int FordFulkersonFlow(int start, int krai, int naiGolqmo){
    //cout<<"viknata e funkciqta s paametri "<<start<<" "<<krai<<" i nai golqmo "<<naiGolqmo<<endl;
    //praveneNaRSasedstvoto(naiGolqmo);

    int maxFlow = 0;

    while(true){
        bool stigameLi = bfs(start, krai, naiGolqmo);
        if(stigameLi == false){
            break;
        }

        int minimalenPotok = 1;

        for(int v = krai; v != start; v = parents[v]){
            int u = parents[v];
            promeniRCapacitetS(u, v, -minimalenPotok);
            promeniRCapacitetS(v, u, minimalenPotok);
        }

        maxFlow+=minimalenPotok;
    }

    //cout<<"i vrashta "<<maxFlow<<endl;
    return maxFlow;
}

int main(){
    cin>>maxY>>maxX;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            char tuk;
            cin>>tuk;
            if(tuk == '.'){
                tukaStolaHubavLiE[x][y] = true;
            }else{
                tukaStolaHubavLiE[x][y] = false;
            }
        }
    }

    for(int y = 0; y < maxY; y++){
        if(y == 0){
            kolkoOkStolaImaDoToziY[y] = 0;
        }else{
            kolkoOkStolaImaDoToziY[y] = kolkoOkStolaImaDoToziY[y-1];
        }
        for(int x = 0; x < maxX; x++){
            if(tukaStolaHubavLiE[x][y] == true){
                kolkoOkStolaImaDoToziY[y]++;
            }
        }
    }

    int nomerche = 1;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            if(tukaStolaHubavLiE[x][y] == true){
                nomerche++;
                tovaNomercheKoqTochkaE[nomerche] = {x, y};
                naTovaMqstoKoeNomercheE[x][y] = nomerche;
            }
        }
    }

    for(int y = 0; y < maxY; y++){
        int x;
        if(y%2==0){
            x = 0;
        }else{
            x = 1;
        }
        for( ; x < maxX; x+=2){
            if(tukaStolaHubavLiE[x][y] == true){
                DanniZaSased zaDob = {naTovaMqstoKoeNomercheE[x][y], 1, 0};
                sasedstvo[0].push_back(zaDob);
                zaDob = {0, 0, 0};
                sasedstvo[naTovaMqstoKoeNomercheE[x][y]].push_back(zaDob);
            }
        }
    }

    for(int y = 0; y < maxY; y++){
        int x;
        if(y % 2 == 0){
            x = 1;
        }else{
            x = 0;
        }
        for( ; x < maxX; x+=2){
            if(tukaStolaHubavLiE[x][y] == true){
                DanniZaSased zaDob = {1, 1, 0};
                sasedstvo[naTovaMqstoKoeNomercheE[x][y]].push_back(zaDob);
                zaDob = {naTovaMqstoKoeNomercheE[x][y], 0, 0};
                sasedstvo[1].push_back(zaDob);
            }
        }
    }

    for(int y = 0; y < maxY; y++){
        int x;
        if(y%2==0){
            x = 0;
        }else{
            x = 1;
        }
        for( ; x < maxX; x += 2){
            if(tukaStolaHubavLiE[x][y] == true){
                if(x > 0){
                    if(tukaStolaHubavLiE[x - 1][y] == true){
                        DanniZaSased zaDob = {naTovaMqstoKoeNomercheE[x - 1][y], 1, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x][y]].push_back(zaDob);
                        zaDob = {naTovaMqstoKoeNomercheE[x][y], 0, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x - 1][y]].push_back(zaDob);
                    }
                }
                if(x < maxX - 1){
                    if(tukaStolaHubavLiE[x + 1][y] == true){
                        DanniZaSased zaDob = {naTovaMqstoKoeNomercheE[x + 1][y], 1, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x][y]].push_back(zaDob);
                        zaDob = {naTovaMqstoKoeNomercheE[x][y], 0, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x + 1][y]].push_back(zaDob);
                    }
                }
                if(y > 0){
                    if(tukaStolaHubavLiE[x][y - 1] == true){
                        DanniZaSased zaDob = {naTovaMqstoKoeNomercheE[x][y - 1], 1, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x][y]].push_back(zaDob);
                        zaDob = {naTovaMqstoKoeNomercheE[x][y], 0, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x][y - 1]].push_back(zaDob);
                    }
                }
                if(y < maxY - 1){
                    if(tukaStolaHubavLiE[x][y + 1] == true){
                        DanniZaSased zaDob = {naTovaMqstoKoeNomercheE[x][y + 1], 1, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x][y]].push_back(zaDob);
                        zaDob = {naTovaMqstoKoeNomercheE[x][y], 0, 0};
                        sasedstvo[naTovaMqstoKoeNomercheE[x][y + 1]].push_back(zaDob);
                    }
                }
            }
        }
    }

    praveneNaRSasedstvoto(nomerche);

    int broiDobri = 0;
    int dobri[20005];

    int sumarenPotok = 0;

    for(int i = 0; i < maxY; i++){
        if(kolkoOkStolaImaDoToziY[i]%2 == 0){
            int potoche = FordFulkersonFlow(0, 1, kolkoOkStolaImaDoToziY[i] + 1);
            sumarenPotok += potoche;
            if(sumarenPotok == kolkoOkStolaImaDoToziY[i]/2){
                dobri[broiDobri] = i + 1;
                broiDobri++;
            }
        }
    }

    cout<<broiDobri<<endl;

    if(broiDobri > 0){
        for(int i = 0; i < broiDobri - 1; i++){
            cout<<dobri[i]<<" ";
        }

        cout<<dobri[broiDobri - 1];

        cout<<endl;
    }

    return 0;
}
