#include<iostream>
using namespace std;

long long k;
long long n;

long long nod(long long a, long long b){
    while(b != 0){
        long long p = b;
        b = a%b;
        a = p;
    }
    return a;
}

long long nok(long long a, long long b, long long nodaIm){
    return (a * b)/nodaIm;
}

int main(){
    cin>>k>>n;

    long long sborNaChisliteli = 0;
    long long znamenatelNaVsicki = 1;

    for(long long chislitel = k; chislitel < n; chislitel++){
        for(long long znamenatel = chislitel + 1; znamenatel <= n; znamenatel++){
            long long nodaIm = nod(chislitel, znamenatel);
            if(nodaIm == 1){

                long long nokNaZnamenatelite = nok(znamenatel, znamenatelNaVsicki, nod(znamenatel, znamenatelNaVsicki));

                long long poKolkoTrqbvaDaUmnozhimObshtiqZnamenatel = nokNaZnamenatelite/znamenatelNaVsicki;
                long long poKolkoTrqbvaDaUmnozhimNashiqZnamenatel = nokNaZnamenatelite/znamenatel;

                znamenatelNaVsicki = nokNaZnamenatelite;
                sborNaChisliteli *= poKolkoTrqbvaDaUmnozhimObshtiqZnamenatel;

                sborNaChisliteli += (chislitel * poKolkoTrqbvaDaUmnozhimNashiqZnamenatel);

            }
        }
    }

    long long nodNaKrainite = nod(sborNaChisliteli, znamenatelNaVsicki);

    sborNaChisliteli /= nodNaKrainite;
    znamenatelNaVsicki /= nodNaKrainite;

    cout<<sborNaChisliteli<<"/"<<znamenatelNaVsicki<<endl;

    return 0;
}
