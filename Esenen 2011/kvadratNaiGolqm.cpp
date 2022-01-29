#include<iostream>
using namespace std;

int maxY;
int maxX;

int tablica[1010][1010];

int broiNuliDo[1010][1010];

int naiGolqmKvadratZavarsV[1010][1010];

void nameriNaiGolemiqtKvadrDo(int doX, int doY){
    if(doX < 1 || doY < 1){
        return ;
    }

    nameriNaiGolemiqtKvadrDo(doX, doY - 1);
    nameriNaiGolemiqtKvadrDo(doX - 1, doY);
    nameriNaiGolemiqtKvadrDo(doX - 1, doY - 1);

    if(tablica[doY][doX] == 0){
        naiGolqmKvadratZavarsV[doY][doX] = 0;
    }else{
        naiGolqmKvadratZavarsV[doY][doX] = 1 + min(naiGolqmKvadratZavarsV[doY - 1][doX - 1], min(naiGolqmKvadratZavarsV[doY - 1][doX], naiGolqmKvadratZavarsV[doY][doX - 1]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxY>>maxX;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            cin>>tablica[y][x];
        }
    }

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            broiNuliDo[y][x] = broiNuliDo[y][x - 1] + broiNuliDo[y - 1][x] - broiNuliDo[y - 1][x - 1];
            if(tablica[y][x] == 0){
                broiNuliDo[y][x]++;
            }
        }
    }

    nameriNaiGolemiqtKvadrDo(maxX, maxY);

    int otg = 0;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            otg = max(otg, naiGolqmKvadratZavarsV[y][x]);
        }
    }

    cout<<otg<<endl;

    return 0;
}
