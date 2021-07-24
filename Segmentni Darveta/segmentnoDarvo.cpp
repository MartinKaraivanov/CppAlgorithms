#include<iostream>
using namespace std;

int broiElementi;
int elementi[100000];

int broiNuzhniVarhove;

int segmentnoDarvo[100000];

int daiListo(int index){
    return index + broiNuzhniVarhove/2;
}

void praveneNaDarvoto(){
    for(int i = 1; i <= broiElementi; i++){
        int darvesenIndex = daiListo(i);
        segmentnoDarvo[darvesenIndex] = elementi[i];
    }
    for(int vrah = daiListo(0) - 1; vrah > 0; vrah--){
        segmentnoDarvo[vrah] = segmentnoDarvo[2*vrah] + segmentnoDarvo[2*vrah + 1];
    }
}

void promenqne(int koeListo, int sKolko){
    int i = daiListo(koeListo);
    while(i > 0){
        segmentnoDarvo[i] += sKolko;
        i/=2;
    }
}

int kolkoESumataOtDo(int otKade, int doKade){
    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(lqvIndex == desenIndex){
        return segmentnoDarvo[lqvIndex];
    }

    int sborche = segmentnoDarvo[lqvIndex] + segmentnoDarvo[desenIndex];

    while(lqvIndex + 1 != desenIndex){
        if(lqvIndex % 2 == 0){
            sborche += segmentnoDarvo[lqvIndex + 1];
        }
        if(desenIndex % 2 == 1){
            sborche += segmentnoDarvo[desenIndex - 1];
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return sborche;
}

int main(){
    cin>>broiElementi;

    for(int i = 1; i <= broiElementi; i++){
        cin>>elementi[i];
    }

    for(int i = 1; true; i*=2){
        if(i > broiElementi){
            broiNuzhniVarhove = i * 2;
            break;
        }
    }

    praveneNaDarvoto();

    for(int i = 0; i <= broiNuzhniVarhove; i++){
        cout<<segmentnoDarvo[i]<<" ";
    }

    cout<<endl;

    cout<<kolkoESumataOtDo(1, 10)<<endl;

    return 0;
}
