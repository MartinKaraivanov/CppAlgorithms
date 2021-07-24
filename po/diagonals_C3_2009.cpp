#include<iostream>
using namespace std;

int dalzhinaNaStrana;
int procenti;
int tablica[150][150];
int nomera[150][150];

int main(){
    cin>>dalzhinaNaStrana>>procenti;

    for(int y=0;y<dalzhinaNaStrana;y++){
        for(int x=0;x<dalzhinaNaStrana;x++){
            cin>>tablica[y][x];
        }
    }

    int nomerche=1;

    for(int x=0;x<dalzhinaNaStrana;x++){
        int yChe=0;
        for(int copyX=x;copyX>=0;copyX--){
            nomera[yChe][copyX]=nomerche;
            nomerche++;
            yChe++;
        }
    }


    for(int y=1;y<dalzhinaNaStrana;y++){
        int xChe=dalzhinaNaStrana-1;
        for(int copyY=y;copyY<dalzhinaNaStrana;copyY++){
            nomera[copyY][xChe]=nomerche;
            nomerche++;
            xChe--;
        }
    }


    return 0;
}
