#include<iostream>
#include<queue>
using namespace std;

int broiGradove;
int broiOtsechki;
int broiDopalnitelnoPostroeni;

int pat[150][150];
int otgovori[50005];
int rPatishta[150][150];
int maksimalenPotok;

unsigned int MnogoGolqmoChislo = 1000000000;

bool Bfs(int start, int target, int parents[150]){
    bool visited[150];

    for(int i = 1; i <= 150; i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(start);

    visited[start] = true;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        for(int i = 1; i <= broiGradove; i++){
            if((visited[i] == false) && (rPatishta[vrah][i] > 0)){
                q.push(i);
                visited[i] = true;
                parents[i] = vrah;
            }
        }

    }

    return visited[target];
}

void iniacializaciq(int patishta[150][150]){
    for(int i = 1; i <= broiGradove; i++){
        for(int j = 1; j <= broiGradove; j++){
            rPatishta[i][j] = patishta[i][j];
        }
    }
}

void FordFulkersonFlow(int patishta[150][150], int start, int krai){
    while(true){
        int parents[150];
        bool stigameLi = Bfs(start, krai, parents);
        if(stigameLi == false){
            break;
        }
        int patishtenPotok = MnogoGolqmoChislo;

        for(int vrah = krai; vrah != start; vrah = parents[vrah]){
            int u = parents[vrah];
            patishtenPotok = min(patishtenPotok, rPatishta[u][vrah]);
        }

        for(int vrah = krai; vrah != start; vrah = parents[vrah]){
            int u = parents[vrah];
            rPatishta[u][vrah] -= patishtenPotok;
            rPatishta[vrah][u] += patishtenPotok;
        }

        maksimalenPotok += patishtenPotok;

    }
}

int main(){
    cin>>broiGradove>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        int otGrad;
        int doGrad;
        cin>>otGrad>>doGrad;
        pat[otGrad][doGrad] = 1;
        pat[doGrad][otGrad] = 1;
    }

    iniacializaciq(pat);
    FordFulkersonFlow(pat, 1, broiGradove);
    otgovori[0] = maksimalenPotok;

    cin>>broiDopalnitelnoPostroeni;

    for(int i = 1; i <= broiDopalnitelnoPostroeni; i++){
        int otGrad;
        int doGrad;
        cin>>otGrad>>doGrad;
        pat[otGrad][doGrad]++;
        pat[doGrad][otGrad]++;
        rPatishta[otGrad][doGrad] ++;
        rPatishta[doGrad][otGrad] ++;

        FordFulkersonFlow(pat, 1, broiGradove);
        otgovori[i] = maksimalenPotok;
    }

    for(int i = 0; i <= broiDopalnitelnoPostroeni; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
