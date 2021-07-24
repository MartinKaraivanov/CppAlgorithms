#include<iostream>
using namespace std;

int maxX;
int maxY;
int tablicaSDalzhini[105][105];
int sasedstvo[105][105];
bool biliLiSmeTuk[105];
bool imameLiNaiKasPat[105][105];

int main(){
    cin>>maxY>>maxX;

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            cin>>tablicaSDalzhini[y][x];
        }
    }

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            if(y<maxY-1){
                int segashnaKletka=y*maxY+x;
                int dolnoPriqtelche=(y+1)*maxY+x;
                sasedstvo[segashnaKletka][dolnoPriqtelche]=tablicaSDalzhini[y+1][x];
            }
            if(x<maxX-1){
                int segashnaKletka=y*maxY+x;
                int dqsnoPriqtelche=y*maxY+x+1;
                sasedstvo[segashnaKletka][dqsnoPriqtelche]=tablicaSDalzhini[y][x+1];
            }
            if(x>0){
                int segashnaKletka=y*maxY+x;
                int lqvoPriqtelche=y*maxY+x+1;
                sasedstvo[segashnaKletka][lqvoPriqtelche]=tablicaSDalzhini[y][x-1];
            }
            if(y>0){
                int segashnaKletka=y*maxY+x;
                int gornoPriqtelche=y*maxY+x+1;
                sasedstvo[segashnaKletka][gornoPriqtelche]=tablicaSDalzhini[y-1][x];
            }
        }
    }


    int start=0;
    int finish=maxX*maxY-1;
    int broiVarhove=maxX*maxY;

    for(int i=0;i<broiVarhove;i++){
        if(i!=start){
            if(sasedstvo[start][i]>0){
                sasedstvo[start][i]=sasedstvo[start][i];
            }else{
                sasedstvo[start][i]=100000;
            }
        }else{
            sasedstvo[start][i]=0;
        }
    }

    imameLiNaiKasPat[start][start]=true;

    bool nameriliLiSmeNeshto=true;
    while(nameriliLiSmeNeshto==true){
        nameriliLiSmeNeshto=false;

        int naiMalko=100000;
        int koqKletkaENaiMalkoto;

        for(int mezhdinenVrah=0;mezhdinenVrah<broiVarhove;mezhdinenVrah++){
            if( (sasedstvo[start][mezhdinenVrah]<naiMalko) &&
                (imameLiNaiKasPat[start][mezhdinenVrah]==false))
            {
                naiMalko=sasedstvo[start][mezhdinenVrah];
                koqKletkaENaiMalkoto=mezhdinenVrah;
                nameriliLiSmeNeshto=true;
            }

            if(nameriliLiSmeNeshto==true){
                imameLiNaiKasPat[start][koqKletkaENaiMalkoto]=true;

                for(int doKletka=0;doKletka<broiVarhove;doKletka++){
                    if((imameLiNaiKasPat[start][doKletka]==false) &&
                       (sasedstvo[koqKletkaENaiMalkoto][doKletka]>0) &&
                       (sasedstvo[start][doKletka] >
                            sasedstvo[start][koqKletkaENaiMalkoto] + sasedstvo[koqKletkaENaiMalkoto][doKletka]))
                    {
                        sasedstvo[start][doKletka] =
                            sasedstvo[start][koqKletkaENaiMalkoto] + sasedstvo[koqKletkaENaiMalkoto][doKletka];
                    }

                }

            }

        }

    }

    int naiKasPat=sasedstvo[start][finish];

    cout<<naiKasPat<<endl;


    return 0;
}
