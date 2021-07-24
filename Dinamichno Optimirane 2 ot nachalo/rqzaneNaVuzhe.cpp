#include<iostream>
using namespace std;

int broiCeni;
int cenaZaDalzhina[100000];

int nachalnaDalzhina;

int naiDobraCenaKoqtoDaVzemem[100000];

int main(){
    cin>>broiCeni;

    for(int i = 1; i <= broiCeni; i++){
        int cenichka;
        cin>>cenichka;
        cenaZaDalzhina[i] = cenichka;
    }

    cin>>nachalnaDalzhina;

    for(int i = 1; i <= nachalnaDalzhina; i++){
        int segashnaNaiDobra = naiDobraCenaKoqtoDaVzemem[i];
        for(int j = 1; j <= i; j++){
            segashnaNaiDobra = max(naiDobraCenaKoqtoDaVzemem[i], cenaZaDalzhina[j] + naiDobraCenaKoqtoDaVzemem[i - j]);
            if(segashnaNaiDobra > naiDobraCenaKoqtoDaVzemem[i]){
                naiDobraCenaKoqtoDaVzemem[i] = segashnaNaiDobra;
            }
        }
    }

    cout<<naiDobraCenaKoqtoDaVzemem[nachalnaDalzhina];

    return 0;
}
