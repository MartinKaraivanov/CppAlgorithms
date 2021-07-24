#include<iostream>
using namespace std;

int broiChasti;
int tezhestNaChasta[1500];
int kolkoTeji[1500][1500];

void popalni(){
    for(int i=0;i<broiChasti;i++){
        for(int j=i;j<broiChasti;j++){
            if(j==0){
                kolkoTeji[i][j]=tezhestNaChasta[j];
            }else{
                kolkoTeji[i][j]=(kolkoTeji[i][j-1]+tezhestNaChasta[j]);
            }
        }
    }
}

void zapalni(){
    for(int i=0;i<1500;i++){
        for(int j=0;j<1500;j++){
            tablica[i][j]=-1;
        }
    }
}

int naiMalkoTeglo(int nachalno, int kraino){
    if(nachalno==kraino){
        return 0;
    }

    if(tablica[nachalno][kraino]!=-1){
        return tablica[nachalno][kraino];
    }

    int minTegloSledTova=99999990;

    for(int i=nachalno;i<kraino;i++){
        int lqvo = naiMalkoTeglo(nachalno,i);
        int dqsno = naiMalkoTeglo(i+1,kraino);

        if(lqvo+dqsno<minTegloSledTova){
            minTegloSledTova=lqvo+dqsno;
        }
    }

    tablica[nachalno][kraino]=kolkoTeji[nachalno][kraino] + minTegloSledTova;
    return tablica[nachalno][kraino];
}

int main(){
    zapalni();
    cin>>broiChasti;

    for(int i=0;i<broiChasti;i++){
        cin>>tezhestNaChasta[i];
    }

    popalni();

    int naiMalkoZaVtigane=naiMalkoTeglo(0,broiChasti-1);

    cout<<naiMalkoZaVtigane<<endl;

    return 0;
}
