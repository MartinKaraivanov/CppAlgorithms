#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    int koordinata;
    int vid;
};

int broiOtsechki;

DanniZaTochka poX[600005];
DanniZaTochka poY[600005];

int broiTochkii;

bool poMalkoLiE(DanniZaTochka a, DanniZaTochka b){
    if(a.koordinata < b.koordinata){
        return true;
    }else{
        if(a.koordinata > b.koordinata){
            return false;
        }else{
            return a.vid > b.vid;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOtsechki;

    broiTochkii = broiOtsechki*2;

    for(int i = 0; i < broiOtsechki; i++){
        int edinKraiX;
        int edinKraiY;
        int drugKraiX;
        int drugKraiY;
        cin>>edinKraiX>>edinKraiY>>drugKraiX>>drugKraiY;

        if(edinKraiX > drugKraiX){
            swap(edinKraiX, drugKraiX);
        }
        if(edinKraiY > drugKraiY){
            swap(edinKraiY, drugKraiY);
        }

        poX[2*i] = {edinKraiX, 1};
        poX[2*i + 1] = {drugKraiX, -1};

        poY[2*i] = {edinKraiY, 1};
        poY[2*i + 1] = {drugKraiY, -1};
    }

    sort(poX, poX + broiTochkii, poMalkoLiE);

    int naiGolqmot = 0;

    int zaPoX = 0;
    for(int i = 0; i < broiTochkii; i++){
        zaPoX += poX[i].vid;
        if(zaPoX > naiGolqmot){
            naiGolqmot = zaPoX;
        }
    }

    sort(poY, poY + broiTochkii, poMalkoLiE);

    int zaPoY = 0;
    for(int i = 0; i < broiTochkii; i++){
        zaPoY += poY[i].vid;
        if(zaPoY > naiGolqmot){
            naiGolqmot = zaPoY;
        }
    }

    cout<<naiGolqmot<<endl;

    return 0;
}
