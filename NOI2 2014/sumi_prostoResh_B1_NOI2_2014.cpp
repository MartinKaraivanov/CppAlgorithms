#include<iostream>
using namespace std;

int broiKartoncheta;

int main(){
    cin>>broiKartoncheta;

    int naiDobraSuma = -10000000;
    int naiDobrotoZaTaziStupka = -10000000;

    for(int i = 0; i < broiKartoncheta; i++){
        int segashenElement;
        cin>>segashenElement;

        naiDobrotoZaTaziStupka = max(naiDobrotoZaTaziStupka + segashenElement, segashenElement);
        naiDobraSuma = max(naiDobraSuma, naiDobrotoZaTaziStupka);
    }

    cout<<naiDobraSuma<<endl;

    return 0;
}
