#include<iostream>
using namespace std;
int main(){
    int broiDaski;
    cin>>broiDaski;

    int parvaSekciq[broiDaski];
    int vtoraSekciq[broiDaski];

    for(int i=0;i<broiDaski;i++){
        cin>>parvaSekciq[i];
    }

    for(int i=0;i<broiDaski;i++){
        cin>>vtoraSekciq[i];
    }

    int g=broiDaski-1;
    int d=0;
    int parvoNaiMalko=1000;

    while(d<broiDaski){
        if(vtoraSekciq[g]+parvaSekciq[d]<parvoNaiMalko){
            parvoNaiMalko=vtoraSekciq[g]+parvaSekciq[d];
        }
        g--;
        d++;
    }

    int l=0;
    int k=0;
    int vtoroNaiMalko=1000;

    while(l<broiDaski){
        if(vtoraSekciq[k]+parvaSekciq[l]<vtoroNaiMalko){
            vtoroNaiMalko=vtoraSekciq[k]+parvaSekciq[l];
        }
        l++;
        k++;
    }

    int pravilnoto=max(parvoNaiMalko,vtoroNaiMalko);

    cout<<pravilnoto<<endl;

    return 0;
}
