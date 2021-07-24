#include<iostream>
#include<algorithm>
using namespace std;

long long broiUchenici;
long long kolkoNaiMngoMozhemPrehEdnovremenno;
long long kolkoTraeTocheneto;
long long vremetraeneNaFilma;

long long kolkoPatiShteiGledame[1000010];
long long broiRazlichniFilmi;

bool poMalkoLiE(long long a, long long b){
    return a > b;
}

int main(){
    cin>>broiUchenici>>kolkoNaiMngoMozhemPrehEdnovremenno>>kolkoTraeTocheneto>>vremetraeneNaFilma;

    for(long long i = 0; i < broiUchenici; i++){
        long long koiFilm;
        cin>>koiFilm;
        kolkoPatiShteiGledame[koiFilm]++;
        if(kolkoPatiShteiGledame[koiFilm] == 1){
            broiRazlichniFilmi++;
        }
    }

    sort(kolkoPatiShteiGledame, kolkoPatiShteiGledame + broiUchenici, poMalkoLiE);

    long long naiGolqmoVreme = 0;
    long long nachalo = 0;

    for(long long i = 0; i < broiRazlichniFilmi; i+=kolkoNaiMngoMozhemPrehEdnovremenno){
        long long segashnoVreme = nachalo + kolkoPatiShteiGledame[i]*(kolkoTraeTocheneto + vremetraeneNaFilma);
        if(segashnoVreme > naiGolqmoVreme){
            naiGolqmoVreme = segashnoVreme;
        }
        nachalo+=kolkoTraeTocheneto;
    }

    cout<<naiGolqmoVreme<<endl;

    return 0;
}
