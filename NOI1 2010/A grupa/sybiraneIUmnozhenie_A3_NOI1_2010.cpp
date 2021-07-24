#include<iostream>
#include<cmath>
using namespace std;

int koeChislo;

int priTolkova[10010];

int naKoyaStupka(int chislo){
    if(chislo == 1){
        return 0;
    }

    if(priTolkova[chislo] > 0){
        return priTolkova[chislo];
    }

    int zaTuk = 100000;

    for(int i = 1; i < chislo; i++){
        int tekushto = 1 + max(naKoyaStupka(i), naKoyaStupka(chislo - i));

        zaTuk = min(zaTuk, tekushto);
    }

    int korenKvadratenPlus1 = sqrt(chislo) + 1;

    for(int i = 2; i < korenKvadratenPlus1; i++){
        if(chislo % i == 0){
            int tekushto = 1 + max(naKoyaStupka(chislo / i), naKoyaStupka(i));

            zaTuk = min(zaTuk, tekushto);
        }
    }

    priTolkova[chislo] = zaTuk;
    return zaTuk;
}

int sCycli(int zaChislo){
    priTolkova[1] = 0;

    for(int chislo = 2; chislo <= zaChislo; chislo++){
        int zaTuk = 100000;

        for(int i = 1; i < chislo; i++){
            int tekushto = 1 + max(priTolkova[i], priTolkova[chislo - i]);

            zaTuk = min(zaTuk, tekushto);
        }

        int korenKvadratenPlus1 = sqrt(chislo) + 1;

        for(int i = 2; i < korenKvadratenPlus1; i++){
            if(chislo % i == 0){
                int tekushto = 1 + max(priTolkova[chislo / i], priTolkova[i]);

                zaTuk = min(zaTuk, tekushto);
            }
        }

        priTolkova[chislo] = zaTuk;
    }

    return priTolkova[zaChislo];
}

int main(){
    cin>>koeChislo;

    int naKoqStapkaSheStane = sCycli(koeChislo);

    cout<<naKoqStapkaSheStane<<endl;

    return 0;
}
