#include<iostream>
using namespace std;

int xStart;
int yStart;
int xKrai;
int yKrai;
int broiTeleporti;

int start;
int finish;

int broiPlaneti = 1;
int NomercheNaTaziPlaneta[11000][11000];

int sasedstvo[2500][2500];
long long naiKasPat[2500][2500];
bool imameLiNaiKasPat[2500][2500];

int Bezkrai = 10000000;

int daiNomerche(int x, int y){
    if(NomercheNaTaziPlaneta[x][y] > 0){
        return NomercheNaTaziPlaneta[x][y];
    }

    broiPlaneti++;
    NomercheNaTaziPlaneta[x][y] = broiPlaneti-1;

    return broiPlaneti-1;
}

void dijkstra(){
    for(int i=1;i<=broiPlaneti;i++){
        if(i!=start){
            if(sasedstvo[start][i]>0){
                naiKasPat[start][i]=sasedstvo[start][i];
            }else{
                naiKasPat[start][i]=Bezkrai;
            }
        }else{
            naiKasPat[start][i]=0;
        }
    }

    imameLiNaiKasPat[start][start]=true;

    bool nameriliLiSmeNeshto=true;
    while(nameriliLiSmeNeshto==true){
        nameriliLiSmeNeshto=false;

        int naiMalko=Bezkrai;
        int koqPlanetaENaiMalkoto;
        for(int prezPlaneta=1;prezPlaneta<=broiPlaneti;prezPlaneta++){
            if((naiKasPat[start][prezPlaneta]<naiMalko) &&
               (imameLiNaiKasPat[start][prezPlaneta]==false))
            {
                naiMalko=naiKasPat[start][prezPlaneta];
                koqPlanetaENaiMalkoto=prezPlaneta;
                nameriliLiSmeNeshto=true;
            }
        }

        if(nameriliLiSmeNeshto==true){
            imameLiNaiKasPat[start][koqPlanetaENaiMalkoto]=true;

            for(int doPlaneta=1;doPlaneta<=broiPlaneti;doPlaneta++){
                if((imameLiNaiKasPat[start][doPlaneta]==false) &&
                    (sasedstvo[koqPlanetaENaiMalkoto][doPlaneta]>0) &&
                    (naiKasPat[start][doPlaneta] >
                        naiKasPat[start][koqPlanetaENaiMalkoto]+sasedstvo[koqPlanetaENaiMalkoto][doPlaneta]))
                {
                    naiKasPat[start][doPlaneta]=
                        naiKasPat[start][koqPlanetaENaiMalkoto]+sasedstvo[koqPlanetaENaiMalkoto][doPlaneta];
                }
            }
        }
    }
}

int main(){
    cin>>xStart>>yStart;
    cin>>xKrai>>yKrai;
    cin>>broiTeleporti;

    start = daiNomerche(xStart, yStart);
    finish = daiNomerche(xKrai, yKrai);

    //cout<<start<<" "<<finish<<endl;

    for(int i = 0; i < broiTeleporti; i++){
        int x1;
        int y1;
        int x2;
        int y2;

        cin>>x1>>y1>>x2>>y2;

        int parvaPlanetka = daiNomerche(x1, y1);
        int vtoraPlanetka = daiNomerche(x2, y2);

        sasedstvo[parvaPlanetka][vtoraPlanetka] = 10;
        sasedstvo[vtoraPlanetka][parvaPlanetka] = 10;

        //cout<<parvaPlanetka<<" "<<vtoraPlanetka<<endl;
    }

    dijkstra();

    for(int i = 0; i < broiPlaneti; i++){
        for(int j = 0; j < broiPlaneti; j++){
            if(naiKasPat[i][j] == 0){
                naiKasPat[i][j] = Bezkrai;
            }
        }
    }

    if(naiKasPat[start][finish] != Bezkrai){
        cout<<naiKasPat[start][finish]<<endl;
    }else{
        cout<<"no solution"<<endl;
    }

    return 0;
}
