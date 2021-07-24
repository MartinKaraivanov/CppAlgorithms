#include<iostream>
using namespace std;

int broiGradove;
int broiDirektniOtsechki;

int broiPitanki;
int otPitanka[400000];
int doPitanka[400000];
long long otgovori[400000];

int sasedstvo[650][650];

int naiKasPat[650][650];
long long broiNaiKasPat[650][650];

int Bezkrai = 1000000;

void floyd(){
    for(int i=1;i<=broiGradove;i++){
        for(int j=1;j<=broiGradove;j++){
            if(sasedstvo[i][j]==0){
                naiKasPat[i][j] = Bezkrai;
            }else{
                naiKasPat[i][j]=sasedstvo[i][j];
                broiNaiKasPat[i][j]++;
            }
        }
    }

    for(int m=1;m<=broiGradove;m++){
        for(int i=1;i<=broiGradove;i++){
            for(int j=1;j<=broiGradove;j++){
                if(naiKasPat[i][m] + naiKasPat[m][j] < naiKasPat[i][j]){
                    naiKasPat[i][j] = naiKasPat[i][m]+naiKasPat[m][j];
                    broiNaiKasPat[i][j] = broiNaiKasPat[i][m]*broiNaiKasPat[m][j];
                }else{
                    if(naiKasPat[i][m] + naiKasPat[m][j] == naiKasPat[i][j]){
                        broiNaiKasPat[i][j]+=broiNaiKasPat[i][m]*broiNaiKasPat[m][j];
                    }
                }
            }
        }
    }
}

int main(){

    cin>>broiGradove>>broiDirektniOtsechki;

    for(int i = 0; i < broiDirektniOtsechki; i++){
        int otgrad;
        int dograd;
        cin>>otgrad>>dograd;

        sasedstvo[otgrad][dograd] = 1;
        sasedstvo[dograd][otgrad] = 1;
    }

    cin>>broiPitanki;

    for(int i = 0; i < broiPitanki; i++){
        int otpgrad;
        int dopgrad;

        cin>>otpgrad>>dopgrad;

        otPitanka[i] = otpgrad;
        doPitanka[i] = dopgrad;
    }

    floyd();

    for(int i=0;i<broiPitanki;i++){
        int start=otPitanka[i];
        int finish=doPitanka[i];

        otgovori[i]=broiNaiKasPat[start][finish];
    }

    for(int i=0;i<broiPitanki;i++){
        cout<<otgovori[i]<<" ";
    }

    return 0;
}
