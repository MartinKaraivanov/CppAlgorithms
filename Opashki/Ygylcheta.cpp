#include<iostream>
#include<queue>
using namespace std;

int kolkoChislaNaStrana;
int kolkoSasedniKletki_K;
int kartoncheta[1100][1100];
int sboroveOtAgalchetataPoX[1100][1100];
int sboroveOtAgalchetataPoY[1100][1100];
int sboroveOtAgalchetata[1100][1100];

int main(){
    cin>>kolkoChislaNaStrana>>kolkoSasedniKletki_K;

    for(int y=1;y<=kolkoChislaNaStrana;y++){
        for(int x=1;x<=kolkoChislaNaStrana;x++){
            cin>>kartoncheta[y][x];
        }
    }

    for(int y=1;y<=kolkoChislaNaStrana;y++){
        for(int x=kolkoChislaNaStrana;x>=1;x--){
            if(x==kolkoChislaNaStrana){
                sboroveOtAgalchetataPoX[y][x]=kartoncheta[y][x];
            }else{
                sboroveOtAgalchetataPoX[y][x]=sboroveOtAgalchetataPoX[y][x+1]+kartoncheta[y][x];
            }
        }
    }

    for(int x=1;x<=kolkoChislaNaStrana;x++){
        for(int y=kolkoChislaNaStrana;y>=1;y--){
            if(y==kolkoChislaNaStrana){
                sboroveOtAgalchetataPoY[y][x]=kartoncheta[y][x];
            }else{
                sboroveOtAgalchetataPoY[y][x]=sboroveOtAgalchetataPoY[y+1][x]+kartoncheta[y][x];
            }
        }
    }

    for(int y=1;y<=kolkoChislaNaStrana;y++){
        for(int x=1;x<=kolkoChislaNaStrana;x++){
            if(x+kolkoSasedniKletki_K<kolkoChislaNaStrana){
                sboroveOtAgalchetataPoX[y][x]-=sboroveOtAgalchetataPoX[y][x+kolkoSasedniKletki_K+1];
            }
        }
    }

    for(int x=1;x<=kolkoChislaNaStrana;x++){
        for(int y=1;y<=kolkoChislaNaStrana;y++){
            if(y+kolkoSasedniKletki_K<kolkoChislaNaStrana){
                sboroveOtAgalchetataPoY[y][x]-=sboroveOtAgalchetataPoY[y+kolkoSasedniKletki_K+1][x];
            }
        }
    }

    for(int y=1;y<=kolkoChislaNaStrana;y++){
        for(int x=1;x<=kolkoChislaNaStrana;x++){
            sboroveOtAgalchetata[y][x]=sboroveOtAgalchetataPoX[y][x]+sboroveOtAgalchetataPoY[y][x]-kartoncheta[y][x];
        }
    }

    int naiGolqmoChislo=0;

    int yNaNAiGolqmoto=0;
    int xNaNAiGolqmoto=0;

    for(int y=1;y<=kolkoChislaNaStrana;y++){
        for(int x=1;x<=kolkoChislaNaStrana;x++){
            if(sboroveOtAgalchetata[y][x]>naiGolqmoChislo){
                naiGolqmoChislo=sboroveOtAgalchetata[y][x];
                yNaNAiGolqmoto=y;
                xNaNAiGolqmoto=x;
            }
        }
    }

    cout<<yNaNAiGolqmoto<<" "<<xNaNAiGolqmoto<<endl;

    return 0;
}
