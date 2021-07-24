#include<iostream>
#include<vector>
using namespace std;

int broiHora;
int koiMuEShef[201000];

vector<int> otgovori;

void reshenie(int rabotnik){
    otgovori.push_back(rabotnik);
    for(int i = 1; i <= broiHora; i++){
        if(koiMuEShef[i] == rabotnik){
            reshenie(i);
        }
    }
}

int main(){
    cin>>broiHora;

    for(int i = 1; i < broiHora; i++){
        int shef;
        int podchinen;
        cin>>shef>>podchinen;
        koiMuEShef[podchinen] = shef;
    }

    reshenie(1);

    for(int i = 0; i < otgovori.size(); i++){
        cout<<otgovori[i]<<" ";
    }


    return 0;
}
