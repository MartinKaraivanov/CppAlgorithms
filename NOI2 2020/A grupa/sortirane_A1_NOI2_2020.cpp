#include<iostream>
using namespace std;

int broiChisla;

int chisla[100010];

int naiGolqmotoChislo;

int priTolkova[1024][10024];

int naiMalakBroiPrilaganiq(int doKoeChislo, int maximalnoChislo){
    if(doKoeChislo == 0){
        return 0;
    }

    if(priTolkova[doKoeChislo][maximalnoChislo] > -1){
        return priTolkova[doKoeChislo][maximalnoChislo];
    }

    int tukaNaiMalko = 1000000007;

    if(chisla[doKoeChislo] >= maximalnoChislo){
        tukaNaiMalko = chisla[doKoeChislo] - maximalnoChislo + naiMalakBroiPrilaganiq(doKoeChislo - 1, maximalnoChislo);
    }else{
        for(int i = chisla[doKoeChislo]; i <= maximalnoChislo; i++){
            int tekushto = i - chisla[doKoeChislo] + naiMalakBroiPrilaganiq(doKoeChislo - 1, i);

            tukaNaiMalko = min(tukaNaiMalko, tekushto);
        }
    }

    priTolkova[doKoeChislo][maximalnoChislo] = tukaNaiMalko;
    return tukaNaiMalko;
}

int priTolkova2[10010];

int sCycli(int zaDoKoeChislo, int zaMaximalnoChislo){

    for(int doKoeChislo = 1; doKoeChislo <= zaDoKoeChislo; doKoeChislo++){

        for(int maximalnoChislo = 0; maximalnoChislo <= zaMaximalnoChislo; maximalnoChislo++){
            int tukaNaiMalko = 1000000007;

            if(chisla[doKoeChislo] > maximalnoChislo){
                tukaNaiMalko = chisla[doKoeChislo] - maximalnoChislo + priTolkova2[maximalnoChislo];
            }else{
                int tekushto = maximalnoChislo - chisla[doKoeChislo] + priTolkova2[maximalnoChislo];

                tukaNaiMalko = min(priTolkova2[maximalnoChislo - 1], tekushto);
            }

            priTolkova2[maximalnoChislo] = tukaNaiMalko;
        }
    }

    return priTolkova2[zaMaximalnoChislo];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiChisla;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
        naiGolqmotoChislo = max(naiGolqmotoChislo, chisla[i]);
    }

    /*for(int i = 0; i <= broiChisla; i++){
        for(int j = 0; j <= naiGolqmotoChislo; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    //int otgovor = naiMalakBroiPrilaganiq(broiChisla, naiGolqmotoChislo);
    int otgovor = sCycli(broiChisla, naiGolqmotoChislo);

    cout<<otgovor<<endl;

    return 0;
}
