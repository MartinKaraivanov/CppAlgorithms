#include<iostream>
using namespace std;

int broiElementi;
int elementi[1000000];

int indexnoDarvo[1000010];

void updatevane(int koiIndex, int sKolko){
    for(int i = koiIndex; i <= broiElementi; i += (i & -i)){
        indexnoDarvo[i] += sKolko;
    }
}

int suma(int doKade){
    int sbor = indexnoDarvo[doKade - 1];
    for(int i = doKade; i > 0; i -= (i & -i)){
        sbor+=indexnoDarvo[i];
    }

    return sbor;
}

int kolkoESumataOtDo(int otKade, int doKade){
    return suma(doKade) - suma(otKade - 1);
}

void updateNaNqkolko(int otKade, int doKade, int sKolko){
    updatevane(otKade, sKolko);
    updatevane(doKade + 1, -sKolko);
}

int main(){
    cin>>broiElementi;

    for(int i = 1; i <= broiElementi; i++){
        cin>>elementi[i];
        updatevane(i, elementi[i]);
    }

    for(int i = 1; i <= broiElementi; i++){
        cout<<indexnoDarvo[i]<<" ";
    }

    cout<<endl;

    cout<<kolkoESumataOtDo(3, 8)<<endl;

    return 0;
}
