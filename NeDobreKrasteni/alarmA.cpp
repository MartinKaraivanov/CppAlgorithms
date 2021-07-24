#include<iostream>
using namespace std;
int main(){
    int m;
    int n;
    cin>>m>>n;

    int kx;
    int ky;
    cin>>kx>>ky;

    int kolkoKoli;
    cin>>kolkoKoli;

    int xove[kolkoKoli];
    int yci[kolkoKoli];

    int naiGolqmX=0;
    int naiMalakX=1000;
    int naiGolqmY=0;
    int naiMalakY=1000;

    for(int i=0;i<kolkoKoli;i++){
        cin>>xove[i]>>yci[i];
        if(xove[i]>naiGolqmX){
            naiGolqmX=xove[i];
        }
        if(xove[i]<naiMalakX){
            naiMalakX=xove[i];
        }
        if(yci[i]>naiGolqmY){
            naiGolqmY=yci[i];
        }
        if(yci[i]<naiMalakY){
            naiMalakY=yci[i];
        }

    }

    if(kx<naiMalakX){
        naiMalakX=kx;
    }
    if(kx>naiGolqmX){
        naiGolqmX=kx;
    }
    if(ky<naiMalakY){
        naiMalakY=ky;
    }
    if(ky>naiGolqmY){
        naiGolqmY=ky;
    }

    int raztoqnie=0;

    raztoqnie=2*((naiGolqmX-naiMalakX)+(naiGolqmY-naiMalakY));

    cout<<raztoqnie<<endl;

    return 0;
}
