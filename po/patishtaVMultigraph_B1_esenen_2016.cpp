#include<iostream>
#include<queue>
using namespace std;

int broiVarhove;
int broiRebra;

int sasedstvo[150][150];

int mnogoGoliamoChislo = 1000000000;

bool bfs(int start, int krai, int parents[150], int rPatishta[150][150]){
    bool visited[150];

    for(int i = 1; i <= 140; i++){
        visited[i] = false;
    }

    queue<int> q;

    q.push(start);

    visited[start] = true;

    while(q.empty() == false){
        int vr = q.front();
        q.pop();

        for(int i = 1; i <= broiVarhove; i++){
            if((visited[i] == false) && (rPatishta[vr][i] > 0)){
                q.push(i);
                visited[i] = true;
                parents[i] = vr;
            }
        }
    }

    return visited[krai];
}

int FordFulkersonPotok(int start, int krai){
    int maxPotok = 0;

    int rSasedstvo[150][150];

    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 1; j <= broiVarhove; j++){
            rSasedstvo[i][j] = sasedstvo[i][j];
        }
    }

    while(true){
        int parents[150];
        bool stigameLi = bfs(start, krai, parents, rSasedstvo);
        if(stigameLi == false){
            break;
        }

        int sabranPotok = mnogoGoliamoChislo;

        for(int vrah = krai; vrah != start; vrah = parents[vrah]){
            int u = parents[vrah];
            sabranPotok = min(sabranPotok, rSasedstvo[u][vrah]);
        }

        for(int vrah = krai; vrah != start; vrah = parents[vrah]){
            int u = parents[vrah];
            rSasedstvo[u][vrah] -= sabranPotok;
            rSasedstvo[vrah][u] += sabranPotok;
        }

        maxPotok += sabranPotok;

    }

    return maxPotok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiVarhove>>broiRebra;

    for(int i = 0; i< broiRebra; i++){
        int otGrad;
        int doGrad;
        cin>>otGrad>>doGrad;
        sasedstvo[otGrad][doGrad]++;
        sasedstvo[doGrad][otGrad]++;
    }

    int minimalenMaksimalenPotok = mnogoGoliamoChislo;


    for(int j = 2; j <= broiVarhove; j++){
        int mPotokZaTezi = FordFulkersonPotok(1, j);
        if(mPotokZaTezi < minimalenMaksimalenPotok){
            minimalenMaksimalenPotok = mPotokZaTezi;
        }
    }


    cout<<minimalenMaksimalenPotok<<endl;

    return 0;
}
