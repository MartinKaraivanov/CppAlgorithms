#include<iostream>
using namespace std;

long long n;
long long proizvedenie[250][250];

void maxpro(long long sboraKolkoDaE, long long otKolkoDaePMR){

    for(long long i = 0; i <= sboraKolkoDaE; i++){
        proizvedenie[i][0] = 0;
    }

    for(long long i = 0; i <= otKolkoDaePMR; i++){
        proizvedenie[0][i] = 1;
    }

    for(long long i = 1; i <= otKolkoDaePMR; i++){
        proizvedenie[1][i] = 1;
    }

    for(long long sbor = 2; sbor <= sboraKolkoDaE; sbor++){
        proizvedenie[sbor][1] = 0;
    }

    for(long long sbora = 2; sbora <= sboraKolkoDaE; sbora++){
        for(long long chisloto = 2; chisloto <= otKolkoDaePMR; chisloto++){

            long long naiDobroto = 0;

            for(long long i = 1; i <= chisloto; i++){
                if(sbora - i >= 0 && chisloto - 1 >= 0){
                    long long potencialno = i * proizvedenie[sbora - i][min(i - 1, sbora - i)];
                    if(potencialno > naiDobroto){
                        naiDobroto = potencialno;
                    }
                }
            }

            proizvedenie[sbora][chisloto] = naiDobroto;

        }
    }
}

int main(){
    cin>>n;

    maxpro(n, n);
    cout<<proizvedenie[n][n]<<endl;

    return 0;
}
