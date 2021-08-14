#include<iostream>
#include<queue>
using namespace std;

unsigned int mnogo = 1000000000;

int broiGradove;
int broiOtsechki;

int broiZaqvki;

int capacitet[150][150];
int rCapacitet[150][150];

int parents[150];

bool bfs(int start, int krai){
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
            if((visited[i] == false) && (rCapacitet[vrah][i] > 0)){
                q.push(i);
                visited[i] = true;
                parents[i] = vrah;
            }
        }

    }

    return visited[krai];
}

void inicializiraneNaRCapacitet(){
    for(int i = 1; i <= broiGradove; i++){
        for(int j = 1; j <= broiGradove; j++){
            rCapacitet[i][j] = capacitet[i][j];
        }
    }
}

int maksimalenPotok = 0;

void FordFulkersonFlow(int start, int krai){
    while(true){
        bool stigameLi = bfs(start, krai);

        if(stigameLi == false){
            break;
        }

        int tekushtPotok = mnogo;

        for(int vrah = krai; vrah != start; vrah = parents[vrah]){
            int u = parents[vrah];
            tekushtPotok = min(tekushtPotok, rCapacitet[u][vrah]);
        }

        for(int vrah = krai; vrah != start; vrah = parents[vrah]){
            int u = parents[vrah];
            rCapacitet[u][vrah] -= tekushtPotok;
            rCapacitet[vrah][u] += tekushtPotok;
        }

        maksimalenPotok += tekushtPotok;
    }
}

int otgovori[50005];

int main(){
    cin>>broiGradove>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        int otGrad;
        int doGrad;
        cin>>otGrad>>doGrad;
        capacitet[otGrad][doGrad] = 1;
        capacitet[doGrad][otGrad] = 1;
    }

    inicializiraneNaRCapacitet();

    FordFulkersonFlow(1, broiGradove);
    otgovori[0] = maksimalenPotok;

    cin>>broiZaqvki;

    for(int i = 1; i <= broiZaqvki; i++){
        int otGrad;
        int doGrad;
        cin>>otGrad>>doGrad;

        capacitet[otGrad][doGrad]++;
        capacitet[doGrad][otGrad]++;

        rCapacitet[otGrad][doGrad] ++;
        rCapacitet[doGrad][otGrad] ++;

        FordFulkersonFlow(1, broiGradove);
        otgovori[i] = maksimalenPotok;
    }

    for(int i = 0; i <= broiZaqvki; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
