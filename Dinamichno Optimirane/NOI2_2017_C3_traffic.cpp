#include<iostream>
using namespace std;

const long long ogromno = 1000000000;

char park[700][700];
int maxY;
int maxX;
int petarNachalenY;
int petarNachalenX;
int tochki[700][700];
bool kadeNeMozhemDaHodim[700][700];


int kolkoVremeOtnemaNaPoleto(char simvol){
    if(simvol=='A'){
        return 1;
    }
    if(simvol=='B'){
        return 2;
    }
    if(simvol=='C'){
        return 3;
    }
    if(simvol=='D'){
        return 4;
    }
    if(simvol=='E'){
        return 5;
    }
    if(simvol=='F'){
        return 6;
    }
    if(simvol=='G'){
        return 7;
    }
    if(simvol=='H'){
        return 8;
    }
    if(simvol=='I'){
        return 9;
    }
    if(simvol=='J'){
        return 10;
    }
    if(simvol=='K'){
        return 11;
    }
    if(simvol=='L'){
        return 12;
    }
    if(simvol=='M'){
        return 13;
    }
    if(simvol=='N'){
        return 14;
    }
    if(simvol=='O'){
        return 15;
    }
    if(simvol=='P'){
        return 16;
    }
    if(simvol=='Q'){
        return 17;
    }
    if(simvol=='R'){
        return 18;
    }
    if(simvol=='S'){
        return 19;
    }
    if(simvol=='T'){
        return 20;
    }
    if(simvol=='U'){
        return 21;
    }
    if(simvol=='V'){
        return 22;
    }
    if(simvol=='W'){
        return 23;
    }
    if(simvol=='X'){
        return 24;
    }
    if(simvol=='Y'){
        return 25;
    }
    if(simvol=='Z'){
        return 26;
    }
    if(simvol=='*'){
        return -1;
    }
    if(simvol=='#'){
        return 0;
    }
}


void transformers(){
    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            tochki[y][x]=kolkoVremeOtnemaNaPoleto(park[y][x]);
        }
    }
}

long long minimalnoVreme(int y, int x){
    if((y==0) || (y==maxY-1) || (x==0) || (x==maxX-1)){
        return tochki[y][x];
    }


    kadeNeMozhemDaHodim[y][x]=true;

    long long sborNaDqsno=ogromno;
    long long sborNaLqvo=ogromno;
    long long sborNaGore=ogromno;
    long long sborNaDolu=ogromno;

    if((y+1<maxY) && (park[y+1][x]!='*')){
        if(kadeNeMozhemDaHodim[y+1][x]==false){
            sborNaDolu=minimalnoVreme(y+1, x);
        }
    }
    if((y-1>=0) && (park[y-1][x]!='*')){
        if(kadeNeMozhemDaHodim[y-1][x]==false){
            sborNaGore=minimalnoVreme(y-1, x);
        }
    }
    if((x+1<maxX) && (park[y][x+1]!='*')){
        if(kadeNeMozhemDaHodim[y][x+1]==false){
            sborNaDqsno=minimalnoVreme(y, x+1);
        }
    }
    if((x-1>=0) && (park[y][x-1]!='*')){
        if(kadeNeMozhemDaHodim[y][x-1]==false){
            sborNaLqvo=minimalnoVreme(y, x-1);
        }
    }

    long long minVertical=min(sborNaDolu, sborNaGore);
    long long minHorizontal=min(sborNaLqvo, sborNaDqsno);

    long long minSbor=min(minHorizontal, minVertical);

    long long rezulat;

    if(minSbor==ogromno){
        rezulat = ogromno;
    }else{
        rezulat = tochki[y][x] + minSbor;
    }

    kadeNeMozhemDaHodim[y][x]=false;

    return rezulat;
}

int main(){
    cin>>maxY>>maxX;

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            cin>>park[y][x];
            if(park[y][x]=='#'){
                petarNachalenY=y;
                petarNachalenX=x;
            }
        }
    }

    transformers();

    long long minVreme=minimalnoVreme(petarNachalenY, petarNachalenX);

    cout<<minVreme<<endl;



    return 0;
}
