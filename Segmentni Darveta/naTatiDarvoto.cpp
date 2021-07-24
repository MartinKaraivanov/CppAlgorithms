#include<iostream>
using namespace std;

int broiElementi;
int elementi[100000];

int broiNuzhniVarhove;
int darvo[100010];
int nivo[100010];

int daiListo(int index){
    return index + broiNuzhniVarhove/2;
}

void praveneNaDarvoto(){
    for(int i = 1; i <= broiElementi; i++){
        int darvesenIndex = daiListo(i);
        darvo[darvesenIndex] = elementi[i];
        nivo[darvesenIndex] = 1;
    }

    for(int i = daiListo(0) - 1; i > 0; i--){
        darvo[i] += nivo[i * 2];
        darvo[i] += nivo[i * 2 + 1];
        nivo[i] = darvo[i];
    }

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
        cout<<darvo[i]<<" ";
    }

    for(int i = 0; i <= broiNuzhniVarhove; i++){
        cout<<nivo[i]<<" ";
    }

    return 0;
}
