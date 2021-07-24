#include<iostream>
using namespace std;

int maxY;
int maxX;
int kolkoEStranataNaPokrivaloto;
long long roziVKvadratche[1200][1200];
long long ot00DoKletkata[1200][1200];

long long sborVToziPravoagalnik(long long y, int x, int a, int b){
    return ot00DoKletkata[y+a-1][x+b-1]-(ot00DoKletkata[y-1][x+b-1]+ot00DoKletkata[y+a-1][x-1]-ot00DoKletkata[y-1][x-1]);
}

void zapalvane(int sborNaToziRed, int y, int x){
    if(y==0){
        ot00DoKletkata[y][x]=sborNaToziRed;
    }else{
        ot00DoKletkata[y][x]=sborNaToziRed+ot00DoKletkata[y-1][x];
    }
}

int main(){
    cin>>maxY>>maxX>>kolkoEStranataNaPokrivaloto;

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            cin>>roziVKvadratche[y][x];
        }
    }

    for(int y=0;y<maxY;y++){
        long long sborNaToziRedDoTuk=0;
        for(int x=0;x<maxX;x++){
            sborNaToziRedDoTuk+=roziVKvadratche[y][x];
            zapalvane( sborNaToziRedDoTuk, y, x);
        }
    }

    long long naiMnogoPokrivane=0;
    int YnaNaiMnogotoPokrivane;
    int XnaNaiMnogotoPokrivane;

    for(int y=0;y<maxY-kolkoEStranataNaPokrivaloto+1;y++){
        for(int x=0;x<maxX-kolkoEStranataNaPokrivaloto+1;x++){
            long long sborVPravoag=sborVToziPravoagalnik(y, x, kolkoEStranataNaPokrivaloto, kolkoEStranataNaPokrivaloto);
            if(sborVPravoag>naiMnogoPokrivane){
                naiMnogoPokrivane=sborVPravoag;
                YnaNaiMnogotoPokrivane=y;
                XnaNaiMnogotoPokrivane=x;
            }
        }
    }

    long long neoceleliRozi=ot00DoKletkata[maxY-1][maxX-1]-naiMnogoPokrivane;

    cout<<neoceleliRozi<<endl;

    return 0;
}
