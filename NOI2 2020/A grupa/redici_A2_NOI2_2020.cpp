#include<iostream>
#include<map>
using namespace std;

const long long BASE = 257;
const long long MOD = 1000000007;

int tip;
int daljinaNaPodredica;

int daljinaParva;
long long parvaRedica[100010];

int daljinaVtora;
long long vtoraRedica[100010];

map<long long, long long> broiSTakuvHash;

long long basePowParva[100010];
long long prefixHashParva[100010];

long long basePowVtora[100010];
long long prefixHashVtora[100010];

void rabinKarpPrecalc(long long redica[100010],
                      long long daljina,
                      long long (&basePow)[100010],
                      long long (&prefixHash)[100010]){
    basePow[0] = 1;

    for(int i = 1; i < daljina; i++){
        basePow[i] = (basePow[i - 1] * BASE)%MOD;
    }

    prefixHash[0] = redica[0];

    for(int i = 1; i < daljina; i++){
        prefixHash[i] = (prefixHash[i - 1] * BASE + redica[i])%MOD;
    }
}

long long daiHash(long long otKade, long long doKade, long long prefixHash[100010], long long basePow[100010]){
    long long h1 = prefixHash[doKade];
    long long h2 = -1;

    if(otKade > 0){
        h2 = prefixHash[otKade - 1];
    }else{
        h2 = 0;
    }

    h2 = (h2 * basePow[doKade - otKade + 1])%MOD;

    return (h1 - h2 + MOD)%MOD;
}

int main(){
    cin>>tip>>daljinaNaPodredica;

    cin>>daljinaParva;

    for(int i = 0; i < daljinaParva; i++){
        cin>>parvaRedica[i];
    }

    cin>>daljinaVtora;

    for(int i = 0; i < daljinaVtora; i++){
        cin>>vtoraRedica[i];
    }

    rabinKarpPrecalc(parvaRedica, daljinaParva, basePowParva, prefixHashParva);
    rabinKarpPrecalc(vtoraRedica, daljinaVtora, basePowVtora, prefixHashVtora);

    long long tekushtaDaljina = 0;
    long long predishnoChislo = -1;

    for(int i = 0; i < daljinaParva; i++){
        long long tekushtHash = 0;

        if(i >= daljinaNaPodredica - 1){
            tekushtHash = daiHash(i - daljinaNaPodredica + 1, i, prefixHashParva, basePowParva);
        }

        if(tip == 1){
            if(parvaRedica[i] > predishnoChislo && predishnoChislo > -1){
                tekushtaDaljina++;
            }else{
                tekushtaDaljina = 1;
            }
        }else{
            if(parvaRedica[i] == predishnoChislo){
                tekushtaDaljina++;
            }else{
                tekushtaDaljina = 1;
            }
        }

        if(tekushtaDaljina >= daljinaNaPodredica){
            broiSTakuvHash[tekushtHash]++;
        }

        predishnoChislo = parvaRedica[i];
    }

    tekushtaDaljina = 0;
    predishnoChislo = -1;

    long long koeficientNaPrilika = 0;

    for(int i = 0; i < daljinaVtora; i++){
        long long tekushtHash = 0;

        if(i >= daljinaNaPodredica - 1){
            tekushtHash = daiHash(i - daljinaNaPodredica + 1, i, prefixHashVtora, basePowVtora);
        }

        if(tip == 1){
            if(vtoraRedica[i] > predishnoChislo && predishnoChislo > -1){
                tekushtaDaljina++;
            }else{
                tekushtaDaljina = 1;
            }
        }else{
            if(vtoraRedica[i] == predishnoChislo){
                tekushtaDaljina++;
            }else{
                tekushtaDaljina = 1;
            }
        }

        if(tekushtaDaljina >= daljinaNaPodredica){
            koeficientNaPrilika += broiSTakuvHash[tekushtHash];
        }

        predishnoChislo = vtoraRedica[i];
    }

    cout<<koeficientNaPrilika<<endl;

    return 0;
}
