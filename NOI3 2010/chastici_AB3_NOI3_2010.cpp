#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int maxX;
int maxY;

int broiPati;
int broiPremestvaniq;

int startovo[105][105];
int kraino[105][105];

int nomerche;
int broiTochkiVEdinichno;
DanniZaTochka tovaNomercheKoqTochkaE[405];

int finaal;

int sasedstvo[405][405];

bool bfs(int parents[450], int rSasedstvo[450][450]){
    bool visited[450];

    for(int i = 0; i <= finaal; i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(q.empty() == false){
        int naiNapred = q.front();
        q.pop();

        if(naiNapred == finaal){
            break;
        }

        for(int i = 1; i <= finaal; i++){
            if(rSasedstvo[naiNapred][i] > 0 && visited[i] == false){
                q.push(i);
                parents[i] = naiNapred;
                visited[i] = true;
            }
        }
    }

    return visited[finaal];
}

int FordFulkersonFlow(){
    int rSasedstvo[450][450];

    for(int i = 0; i <= finaal; i++){
        for(int j = 0; j <= finaal; j++){
            rSasedstvo[i][j] = sasedstvo[i][j];
        }
    }

    int maxFlow = 0;

    while(true){
        int parents[450];
        bool stigameLi = bfs(parents, rSasedstvo);
        if(stigameLi == false){
            break;
        }

        int naiMalkoto = 1000000000;

        for(int i = finaal; i != 0; i = parents[i]){
            int roditel = parents[i];
            naiMalkoto = min(naiMalkoto, rSasedstvo[roditel][i]);
        }

        for(int i = finaal; i != 0; i = parents[i]){
            int roditel = parents[i];
            rSasedstvo[roditel][i] -= naiMalkoto;
            rSasedstvo[i][roditel] += naiMalkoto;
        }

        maxFlow += naiMalkoto;
    }

    return maxFlow;
}


int main(){
    cin>>maxX>>maxY;
    cin>>broiPati>>broiPremestvaniq;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cin>>startovo[x][y];
            if(startovo[x][y] > 0){
                nomerche++;
                broiTochkiVEdinichno += startovo[x][y];
                tovaNomercheKoqTochkaE[nomerche] = {x, y};
                sasedstvo[0][nomerche] = startovo[x][y];
            }
        }
    }

    finaal = broiTochkiVEdinichno*2 + 1;
    int broiRazlichniTochkiVParvoto = nomerche;
    int broiTochkiVVtoroto = 0;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cin>>kraino[x][y];
            if(kraino[x][y] > 0){
                nomerche++;
                broiTochkiVVtoroto += kraino[x][y];
                tovaNomercheKoqTochkaE[nomerche] = {x, y};
                sasedstvo[nomerche][finaal] = kraino[x][y];
            }
        }
    }

    if(broiTochkiVEdinichno != broiTochkiVVtoroto){
        cout<<"N"<<endl;
        return 0;
    }

    for(int i = 1; i <= broiRazlichniTochkiVParvoto; i++){
        for(int j = broiRazlichniTochkiVParvoto + 1; j <= nomerche; j++){
            int razstMezhduDvete = abs(tovaNomercheKoqTochkaE[i].x - tovaNomercheKoqTochkaE[j].x) +
                abs(tovaNomercheKoqTochkaE[i].y - tovaNomercheKoqTochkaE[j].y);
            int umnozh = broiPati*broiPremestvaniq;
            if(umnozh >= razstMezhduDvete && (umnozh % 2 == razstMezhduDvete % 2)){
                sasedstvo[i][j] = 1000000000;
            }
        }
    }

    int naiDobriqBroi = FordFulkersonFlow();

    if(naiDobriqBroi == broiTochkiVEdinichno){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }

    return 0;
}
