#include<iostream>
using namespace std;

int broiElementi;
int redica[100000];

int naiDalgaPodredica[100000];

int main(){
    cin>>broiElementi;

    for(int i = 0; i < broiElementi; i++){
        int element;
        cin>>element;

        redica[i] = element;
    }

    for(int i = 0; i < broiElementi; i++){

        int u = 0;
        for(int j = 0; j < i; j++){
            if(redica[i] > redica[j]){
                if(naiDalgaPodredica[j] > u){
                    u = naiDalgaPodredica[j];
                }
            }
        }

        naiDalgaPodredica[i] = u + 1;
    }

    int naiDPodredica = 0;

    for(int i = 0; i < broiElementi; i++){
        if(naiDalgaPodredica[i] > naiDPodredica){
            naiDPodredica = naiDalgaPodredica[i];
        }
    }

    cout<<naiDPodredica<<endl;

    return 0;
}
