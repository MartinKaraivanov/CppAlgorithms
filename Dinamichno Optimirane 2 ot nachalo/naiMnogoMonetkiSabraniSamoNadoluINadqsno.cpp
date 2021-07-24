#include<iostream>
using namespace std;

int maxX;
int maxY;
int tablicaStoinosti[10000][10000];

int dp[10000][10000];

int main(){
    cin>>maxX>>maxY;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int stoinost;
            cin>> stoinost;

            tablicaStoinosti[x][y] = stoinost;

        }
    }

    for(int y = maxY - 1; y >= 0; y--){
        for(int x = maxX - 1; x >= 0; x--){
            if(y == maxY - 1 && x == maxX - 1){
                dp[x][y] = tablicaStoinosti[x][y];
                continue;
            }

            int zaNadolu = 0;
            if(y < maxY - 1){
                zaNadolu = dp[x][y + 1];
            }

            int zaNadqsno = 0;
            if(x < maxX - 1){
                zaNadqsno = dp[x + 1][y];
            }

            dp[x][y] = tablicaStoinosti[x][y] + max(zaNadolu, zaNadqsno);

        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}
