#include<iostream>
#include<stdio.h>
using namespace std;

int broiKubchetaNaStrana;
int broiVaprosi;
int kubche[250][250][250];
int ot000doTuk[250][250][250];

struct coordinatiNaMiniKubchetata{
    int plast;
    int y;
    int x;
};

int otgovori [300000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKubchetaNaStrana>>broiVaprosi;

    for(int z=1;z<=broiKubchetaNaStrana;z++){
        for(int y=1;y<=broiKubchetaNaStrana;y++){
            for(int x=1;x<=broiKubchetaNaStrana;x++){
                char material;
                cin>>material;
                if(material=='G'){
                    kubche[z][y][x]=1;
                }
            }
        }
    }

    for(int z=1;z<=broiKubchetaNaStrana;z++){
        for(int y=1;y<=broiKubchetaNaStrana;y++){
            for(int x=1;x<=broiKubchetaNaStrana;x++){
                ot000doTuk[z][y][x]=
                    ot000doTuk[z][y][x-1]+ot000doTuk[z-1][y][x]+ot000doTuk[z][y-1][x]
                    -ot000doTuk[z][y-1][x-1]-ot000doTuk[z-1][y-1][x]-ot000doTuk[z-1][y][x-1]
                    +ot000doTuk[z-1][y-1][x-1]
                    +kubche[z][y][x];
            }
        }
    }

    for(int i=0;i<broiVaprosi;i++){
        int nbtPlast;
        int nbtY;
        int nbtX;
        int ndtPlast;
        int ndtY;
        int ndtX;

        cin>>nbtPlast>>nbtY>>nbtX>>ndtPlast>>ndtY>>ndtX;

        otgovori[i]=ot000doTuk[ndtPlast][ndtY][ndtX]
            -ot000doTuk[ndtPlast][nbtY-1][ndtX]
            -ot000doTuk[ndtPlast][ndtY][nbtX-1]
            -ot000doTuk[nbtPlast-1][ndtY][ndtX]
            +ot000doTuk[nbtPlast-1][nbtY-1][ndtX]
            +ot000doTuk[ndtPlast][nbtY-1][nbtX-1]
            +ot000doTuk[nbtPlast-1][ndtY][nbtX-1]
            -ot000doTuk[nbtPlast-1][nbtY-1][nbtX-1];
    }

    for(int i=0;i<broiVaprosi;i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
