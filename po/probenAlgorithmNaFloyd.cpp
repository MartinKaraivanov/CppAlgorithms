#include<iostream>
using namespace std;

int broiVarhove;
int broiDadeni;
int sasedstvo[100][100];
int naiKasPat[100][100];
int bezkrai=100000000;

void floyd(){
    for(int i=1;i<=broiVarhove;i++){
        for(int j=1;j<=broiVarhove;j++){
            naiKasPat[i][j]=sasedstvo[i][j];
            if(sasedstvo[i][j]==0){
                naiKasPat[i][j] = bezkrai;
            }
        }
    }

    for(int m=1;m<=broiVarhove;m++){
        for(int i=1;i<=broiVarhove;i++){
            for(int j=1;j<=broiVarhove;j++){
                if(naiKasPat[i][m] + naiKasPat[m][j] < naiKasPat[i][j]){
                    naiKasPat[i][j] = naiKasPat[i][m]+naiKasPat[m][j];
                }
            }
        }
    }
}

int main(){
    cin>>broiVarhove>>broiDadeni;

    for(int i=0;i<broiDadeni;i++){
        int otv;
        int dov;
        int raz;
        cin>>otv>>dov>>raz;
        sasedstvo[otv][dov] = raz;
        sasedstvo[dov][otv] = raz;
    }

    floyd();

    for(int i=1;i<=broiVarhove;i++){
        for(int j=1;j<=broiVarhove;j++){
            cout<<i<<" "<<j<<" "<<naiKasPat[i][j]<<endl;
        }
    }

    return 0;
}
