#include<iostream>
#include<cstring>
using namespace std;

int kolkoKartiNaStrana;
string mrezha[150][150];
int tochki[150][150];
int nGRezultat[150][150];

int kolkoTochkiNosi(char simvol){
    if(simvol=='A'){
        return 1;
    }
    if(simvol=='2'){
        return 2;
    }
    if(simvol=='3'){
        return 3;
    }
    if(simvol=='4'){
        return 4;
    }
    if(simvol=='5'){
        return 5;
    }
    if(simvol=='6'){
        return 6;
    }
    if(simvol=='7'){
        return 7;
    }
    if(simvol=='8'){
        return 8;
    }
    if(simvol=='9'){
        return 9;
    }
    if(simvol=='T'){
        return 10;
    }
    if(simvol=='J'){
        return 11;
    }
    if(simvol=='Q'){
        return 12;
    }
    if(simvol=='K'){
        return 13;
    }
}

void transformers(){
    for(int y=0;y<150;y++){
        for(int x=0;x<150;x++){
            tochki[y][x]=kolkoTochkiNosi(mrezha[y][x][0]);
        }
    }
}

void popalni(){
    for(int y=0;y<150;y++){
        for(int x=0;x<150;x++){
            nGRezultat[y][x]=-1;
        }
    }
}

int naiGolqmResult(int y, int x){
    if((y==0) && (x==kolkoKartiNaStrana-1)){
        return tochki[y][x];
    }

    if(nGRezultat[y][x]!=-1){
        return nGRezultat[y][x];
    }

    int sborNaDqsno=0;
    int sborNaGore=0;

    if(x+1<kolkoKartiNaStrana){
        sborNaDqsno=tochki[y][x]+naiGolqmResult(y, x+1);
    }
    if(y-1>=0){
        sborNaGore=tochki[y][x]+naiGolqmResult(y-1, x);
    }

    int maxSbor=max(sborNaDqsno, sborNaGore);

    nGRezultat[y][x]=maxSbor;
    return maxSbor;
}

int main(){
    popalni();
    cin>>kolkoKartiNaStrana;

    for(int y=0;y<kolkoKartiNaStrana;y++){
        for(int x=0;x<kolkoKartiNaStrana;x++){
            cin>> mrezha[y][x];
        }
    }

    transformers();

    int naiGolqmRezultat=naiGolqmResult(kolkoKartiNaStrana-1,0);

    cout<<naiGolqmRezultat<<endl;

    return 0;
}
