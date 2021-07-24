#include<iostream>
#include<algorithm>
using namespace std;

struct Resolution {int horizontal; int vertical;};

bool poMalkoVert (Resolution a, Resolution b){
    return a.vertical < b.vertical;
}

int main(){
    long long broiMonitori,naiGolqmaRezoluciq,ednakvi;
    cin>>broiMonitori;
    Resolution res[broiMonitori];

    for(int i=0;i<broiMonitori;i++){
        /////cin>>horizontalna[i]>>vertikalna[i];
        cin>>res[i].horizontal>>res[i].vertical;
    }

    sort(res, res+broiMonitori,poMalkoVert);

    long long naiGolqmaHoriontalnaSuma=0;
    long long vertikalnaNaGrupata = 0;
    long long sumHorizontalnaNaGrupata = 0;
    for(int i=0;i<broiMonitori;i++){
        if(res[i].vertical!=vertikalnaNaGrupata){
            vertikalnaNaGrupata=res[i].vertical;
            sumHorizontalnaNaGrupata=res[i].horizontal;
        }else{
            sumHorizontalnaNaGrupata=sumHorizontalnaNaGrupata+res[i].horizontal;
        }
        if(sumHorizontalnaNaGrupata>naiGolqmaHoriontalnaSuma){
                naiGolqmaHoriontalnaSuma=sumHorizontalnaNaGrupata;
        }
    }
    cout<<naiGolqmaHoriontalnaSuma;
    cout<<endl;

    return 0;
}
