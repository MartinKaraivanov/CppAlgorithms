#include<iostream>
using namespace std;

long long otKadeZapochvame;
int kolkoSimvola;

int kadeSmeQSreshnali[30000000];

long long nachaloNaPovtarqne;
long long kraichence;

int main(){
    int a;
    int b;
    cin>>a>>b>>otKadeZapochvame>>kolkoSimvola;

    long long doKadeMaksimum = otKadeZapochvame + kolkoSimvola;
    int aa = a;
    for(long long i = 1; i < doKadeMaksimum; i++){
        if(kadeSmeQSreshnali[aa] != 0){
            nachaloNaPovtarqne = kadeSmeQSreshnali[aa];
            kraichence = i;
            break;
        }
        kadeSmeQSreshnali[aa] = i;

        aa = (aa*10)%b;
    }

    int dalzhinaNaPovtarqshtoto = kraichence - nachaloNaPovtarqne;

    //cout<<nachaloNaPovtarqne<<endl;

    int otKadeTrqbvaDaZapochnem;
    if(otKadeZapochvame >= nachaloNaPovtarqne){
        otKadeTrqbvaDaZapochnem = (otKadeZapochvame-(nachaloNaPovtarqne-1))%dalzhinaNaPovtarqshtoto + (nachaloNaPovtarqne - 1);
    }else{
        otKadeTrqbvaDaZapochnem = otKadeZapochvame;
    }

    int drugoDoKade = otKadeTrqbvaDaZapochnem + kolkoSimvola;
    aa = a;
    for(int i = 1; i < drugoDoKade; i++){
        if(i >= otKadeTrqbvaDaZapochnem){
            cout<<(aa*10)/b;
            //cout<<i<<endl;
        }
        aa = (aa*10)%b;
    }

    cout<<endl;

    return 0;
}
