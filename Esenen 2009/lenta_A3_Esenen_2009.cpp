#include<iostream>
#include<cmath>
using namespace std;

long long nachalnaDaljina;

long long broiPreguvaniq;

long long preguvaniq[10010];

long long naKoqPoziciqE(long long kadeSgavame, long long kadeEKoe){
    if(kadeEKoe <= kadeSgavame){
        return kadeSgavame - kadeEKoe;
    }else{
        return kadeEKoe - kadeSgavame;
    }
}

int main(){
    cin>>nachalnaDaljina>>broiPreguvaniq;

    for(int i = 0; i < broiPreguvaniq; i++){
        cin>>preguvaniq[i];
    }

    long long segashnaDaljina = nachalnaDaljina;

    for(int i = 0; i < broiPreguvaniq; i++){
        long long kadePregavame = preguvaniq[i];
        for(int j = i + 1; j < broiPreguvaniq; j++){
            preguvaniq[j] = naKoqPoziciqE(kadePregavame, preguvaniq[j]);
        }

        segashnaDaljina = max(kadePregavame, segashnaDaljina - kadePregavame);
    }

    cout<<segashnaDaljina<<endl;

    return 0;
}
