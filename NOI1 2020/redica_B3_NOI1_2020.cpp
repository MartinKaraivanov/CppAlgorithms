#include<iostream>
using namespace std;

long long broiChisla;
long long otKolkoDaEPoGRzl;

long long chisla[300010];

int main(){
    cin>>broiChisla>>otKolkoDaEPoGRzl;

    for(long long i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    long long broiUdovletvor = 0;

    int kadeEPrednoto = 1;

    for(long long i = 0; i < broiChisla - 1; i++){
        for(long long j = kadeEPrednoto; j < broiChisla; j++){
            if(chisla[j] - chisla[i] > otKolkoDaEPoGRzl){
                broiUdovletvor+= broiChisla - j;
                kadeEPrednoto = j;
                break;
            }
        }
    }

    cout<<broiUdovletvor<<endl;

    return 0;
}
