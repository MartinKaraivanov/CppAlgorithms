#include<iostream>
using namespace std;

int broiGradove;
int broiDirektniOtsechki;

int broiPitanki;
int otPitanka[400000];
int doPitanka[400000];
unsigned long long otgovori[400000];

int sasedstvo[650][650];

int naiKasPat[650][650];
unsigned long long broiNaiKasPat[650][650];

int Bezkrai = 1000000;
unsigned long long mnogo = 1000000021;

void floyd(){
    for(int i=1;i<=broiGradove;i++){
        for(int j=1;j<=broiGradove;j++){
            if(sasedstvo[i][j]==0){
                naiKasPat[i][j] = Bezkrai;
            }else{
                naiKasPat[i][j]=sasedstvo[i][j];
                broiNaiKasPat[i][j]=1%mnogo;
            }
        }
    }

    for(int m=1;m<=broiGradove;m++){
        for(int i=1;i<=broiGradove;i++){
            for(int j=1;j<=broiGradove;j++){
                if(naiKasPat[i][m] + naiKasPat[m][j] < naiKasPat[i][j]){
                    naiKasPat[i][j] = naiKasPat[i][m]+naiKasPat[m][j];
                    broiNaiKasPat[i][j] = (broiNaiKasPat[i][m]*broiNaiKasPat[m][j])%mnogo;
                }else{
                    if(naiKasPat[i][m] + naiKasPat[m][j] == naiKasPat[i][j]){
                        broiNaiKasPat[i][j]=(broiNaiKasPat[i][j]+broiNaiKasPat[i][m]*broiNaiKasPat[m][j])%mnogo;
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
        int razs;
        cin>>otgrad>>dograd>>razs;

        sasedstvo[otgrad][dograd] = razs;
        sasedstvo[dograd][otgrad] = razs;
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
