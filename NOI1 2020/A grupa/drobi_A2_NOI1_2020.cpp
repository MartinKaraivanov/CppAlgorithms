#include<iostream>
using namespace std;

long long phiPriTolkova[1000010];

int naiGolqmObshtDelitel(int a, int b){
    while(b != 0){
        int p = b;
        b = a%b;
        a = p;
    }
    return a;
}

void praveneNaPhiPriTolkova(int doKolko){
    for(int i = 1; i <= doKolko; i++){
        phiPriTolkova[i] = i;
    }

    for(int p = 2; p <= doKolko; p++){
        if(phiPriTolkova[p] == p){
            phiPriTolkova[p] = p - 1;

            for(int k = 2*p; k <= doKolko; k += p){
                phiPriTolkova[k] = (phiPriTolkova[k]/p) * (p - 1);
            }
        }
    }
}

long long izchislqvaneNaBroiPravilniDrobi(int doKolkoZnamenatel){
    praveneNaPhiPriTolkova(doKolkoZnamenatel);

    long long broiPravilniDrobi = 0;

    /*for(int znamenatel = 1; znamenatel <= doKolkoZnamenatel; znamenatel++){
        for(int chislitel = 1; chislitel <= znamenatel; chislitel++){
            if(naiGolqmObshtDelitel(chislitel, znamenatel) == 1){
                broiPravilniDrobi++;
            }
        }
    }*/

    for(int i = 1; i <= doKolkoZnamenatel; i++){
        broiPravilniDrobi += phiPriTolkova[i];
    }

    return broiPravilniDrobi;
}

int main(){
    int doKolkoZnamenatel;

    cin>>doKolkoZnamenatel;

    long long broiPravilniDrobi = izchislqvaneNaBroiPravilniDrobi(doKolkoZnamenatel);

    cout<<broiPravilniDrobi<<endl;

    return 0;
}
