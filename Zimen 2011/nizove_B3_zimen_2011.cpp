#include<iostream>
using namespace std;

int broiBukvichki;

long long priTolkova[30];

const long long mnogo = ((long long)1 << 53) - 1;

/*
long long broiKombinaciiSPoslednoVzeto(long long poslednoVzeto){
    if(poslednoVzeto == 0){
        return 0;
    }

    if(priTolkova[poslednoVzeto] > 0){
        return priTolkova[poslednoVzeto]%mnogo;
    }

    long long zaTuk = 1;

    for(int i = 0; i <= 26; i++){

    }

    priTolkova[poslednoVzeto] = zaTuk%mnogo;
    return zaTuk;
}
*/

long long suma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char simvol;
    while(cin>>simvol){

        long long zaTuk = (1 + suma)%mnogo;

        suma = ((mnogo + suma - priTolkova[simvol - 96]) % mnogo + zaTuk)%mnogo;

        priTolkova[simvol - 96] = zaTuk;

    }

    long long broiNachini = suma;

    cout<<broiNachini<<endl;

    return 0;
}
