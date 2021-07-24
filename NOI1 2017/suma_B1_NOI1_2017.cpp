#include<iostream>
using namespace std;

int broiChisla;
int chisla[200500];

int main(){
    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    int naiMnogotoChisla = 0;

    int i = 0;
    int j = broiChisla - 1;

    int lqvaSumaNaI = chisla[i];
    int dqsnaSumaNaJ = chisla[j];

    while(i != j){
        if(lqvaSumaNaI == dqsnaSumaNaJ){
            int segashenBroiChisla = i + 1 + broiChisla - j;
            naiMnogotoChisla = max(naiMnogotoChisla, segashenBroiChisla);
            i++;
            lqvaSumaNaI += chisla[i];
            continue;
        }

        if(lqvaSumaNaI > dqsnaSumaNaJ){
            j--;
            dqsnaSumaNaJ += chisla[j];
            continue;
        }

        i++;
        lqvaSumaNaI+=chisla[i];
    }

    cout<<naiMnogotoChisla<<endl;

    return 0;
}
