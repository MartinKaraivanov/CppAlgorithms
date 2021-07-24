#include<iostream>
using namespace std;

int broiKanali;
int broiPuskaniqNaTelevizora;

string redica;
int nachalnataRedichka[600000];
int broiDeistviq;

int segmentnoDarvo[600050];
int broiNuzhniVarhove;

void izchislqvaneNaBroiNuzhniVarhove(){
    for(int i = 1; true; i *= 2){
        if(i >= broiDeistviq){
            broiNuzhniVarhove = 2*i;
            break;
        }
    }
}

int daiListo(int index){
    return index + broiNuzhniVarhove/2;
}

void praveneNaSegmentnotoDarvo(){
    for(int i = 0; i < broiDeistviq; i++){
        segmentnoDarvo[daiListo(i)] = nachalnataRedichka[i];
    }

    for(int i = daiListo(0) - 1; i > 0; i--){
        segmentnoDarvo[i] = segmentnoDarvo[2*i] + segmentnoDarvo[2*i + 1];
    }

}

void update(int otKade, int doKade, int kakuv){
    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(lqvIndex == desenIndex){
        segmentnoDarvo[lqvIndex] *= kakuv;
        return;
    }

    segmentnoDarvo[lqvIndex] *= kakuv;
    segmentnoDarvo[desenIndex] *= kakuv;

    while(lqvIndex + 1 != desenIndex){
        if(lqvIndex % 2 == 0){
            segmentnoDarvo[lqvIndex + 1] *= kakuv;
        }
        if(desenIndex % 2 == 1){
            segmentnoDarvo[desenIndex - 1] *= kakuv;
        }
        lqvIndex /= 2;
        desenIndex /= 2;
    }

}

int query(int naKoiVrah){
    int index = daiListo(naKoiVrah);
    int suma = 0;
    while(index > 0){
        suma += segmentnoDarvo[index];
        index /= 2;
    }

    return suma;
}

int main(){
    cin>>broiKanali>>broiPuskaniqNaTelevizora;

    cin>>redica;

    for(int i = 0; i < redica.size(); i++){
        if(redica[i] == '+'){
            nachalnataRedichka[i] = 1;
        }else{
            if(redica[i] == '-'){
                nachalnataRedichka[i] = -1;
            }else{
                nachalnataRedichka[i] = 0;
            }
        }
    }

    broiDeistviq = redica.size();

    izchislqvaneNaBroiNuzhniVarhove();
    praveneNaSegmentnotoDarvo();

    for(int i = 0; i < broiPuskaniqNaTelevizora; i++){
        int otKadeSmenq;
        int doKadeSmenq;

        cin>>otKadeSmenq>>doKadeSmenq;

        update(otKadeSmenq, doKadeSmenq, -1);

    }

    return 0;
}
