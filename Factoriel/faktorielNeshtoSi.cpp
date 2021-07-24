#include<iostream>
using namespace std;

int priTolkova[65][1000010];

int broiKombinacii(int kolkoTrqbvaDaVzemem, int otKolko){
    if(kolkoTrqbvaDaVzemem == 1){
        return otKolko;
    }

    if(otKolko == kolkoTrqbvaDaVzemem){
        return 1;
    }

    if(otKolko < kolkoTrqbvaDaVzemem){
        return 0;
    }

    if(priTolkova[kolkoTrqbvaDaVzemem][otKolko] > -1){
        return priTolkova[kolkoTrqbvaDaVzemem][otKolko];
    }

    int bezNego = broiKombinacii(kolkoTrqbvaDaVzemem, otKolko - 1);
    int sasNego = broiKombinacii(kolkoTrqbvaDaVzemem - 1, otKolko - 1);

    priTolkova[kolkoTrqbvaDaVzemem][otKolko] = sasNego + bezNego;
    return sasNego+bezNego;
}

int main(){
    int kolkoIzbirame;
    int otKolkoIzbirame;

    cin>>kolkoIzbirame>>otKolkoIzbirame;

    for(int i = 0; i <= kolkoIzbirame; i++){
        for(int j = 0; j <= otKolkoIzbirame; j++){
            priTolkova[i][j] = -1;
        }
    }

    int brKomb = broiKombinacii(kolkoIzbirame, otKolkoIzbirame);

    cout<<brKomb<<endl;

    return 0;
}
