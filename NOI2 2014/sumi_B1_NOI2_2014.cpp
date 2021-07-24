#include<iostream>
using namespace std;

int broiKartoncheta;
int kartoncheta[1000010];

int main(){
    cin>>broiKartoncheta;

    for(int i = 0; i < broiKartoncheta; i++){
        cin>>kartoncheta[i];
    }

    int naiDobraSuma = -100000000;

    for(int i = 0; i < broiKartoncheta; i++){
        int segashnaSuma = kartoncheta[i];
        naiDobraSuma = max(naiDobraSuma, segashnaSuma);
        for(int j = i + 1; j < broiKartoncheta; j++){
            segashnaSuma+=kartoncheta[j];
            naiDobraSuma = max(naiDobraSuma, segashnaSuma);
        }
    }

    cout<<naiDobraSuma<<endl;

    return 0;
}
