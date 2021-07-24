#include<iostream>
using namespace std;

int sborove[1000];
int broiSborove;

int main(){
    int kolkoChislaImaVRedicata;
    int k;

    cin>>kolkoChislaImaVRedicata>>k;

    int chislaOtRedicata[kolkoChislaImaVRedicata];

    for(int i=0;i<kolkoChislaImaVRedicata;i++){
        cin>>chislaOtRedicata[i];
    }

    for(int i=0;i<kolkoChislaImaVRedicata+1-k;i++){
        int j=i;
        while(j<i+k){
            sborove[broiSborove]+=chislaOtRedicata[j];
            j++;
        }
        broiSborove++;
    }

    int naiGolqmSbor=0;

    for(int i=0;i<broiSborove;i++){
        if(sborove[i]>naiGolqmSbor){
            naiGolqmSbor=sborove[i];
        }
    }

    cout<<naiGolqmSbor<<endl;


    return 0;
}
