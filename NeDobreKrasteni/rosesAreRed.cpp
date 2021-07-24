#include<iostream>
using namespace std;

int pole[1200][1200];

int main(){
    int maxX;
    int maxY;
    int k;
    cin>>maxY>>maxX>>k;

    int obshtBroiRosi=0;
    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            cin>>pole[y][x];
            obshtBroiRosi+=pole[y][x];
        }
    }

    int naiGolqmSbor=0;
    for(int y=0;y<=maxY-k;y++){
        for(int x=0;x<=maxX-k;x++){
            int tekushtSbor=0;
            for(int tY=y;tY<(y+k);tY++){
                for(int tX=x;tX<(x+k);tX++){
                    tekushtSbor+=pole[tY][tX];
                }
            }
            if(tekushtSbor>naiGolqmSbor){
                naiGolqmSbor=tekushtSbor;
            }
        }
    }

    cout<<obshtBroiRosi-naiGolqmSbor<<endl;

    return 0;
}
