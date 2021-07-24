#include<iostream>
#include<cmath>
using namespace std;

const int mnogoMalko = -10000000;

int broiChisla;

int naiMalkoKolko;
int naiMnogoKolko;

int naiMnogoRazlika;

int chisla[100010];

int priTolkova[100010][10];

int maximalnaSuma(int doKoeChislo, int sKakvoPredno){
    if(doKoeChislo == 0){
        return 0;
    }

    if(priTolkova[doKoeChislo][sKakvoPredno] > mnogoMalko){
        return priTolkova[doKoeChislo][sKakvoPredno];
    }

    int zaTuk = mnogoMalko;

    for(int i = naiMalkoKolko; i <= naiMnogoKolko; i++){
        if(sKakvoPredno == 0 || abs(sKakvoPredno - i) <= naiMnogoRazlika){
            int tekushto = chisla[doKoeChislo]*i + maximalnaSuma(doKoeChislo - 1, i);

            zaTuk = max(zaTuk, tekushto);
        }
    }

    priTolkova[doKoeChislo][sKakvoPredno] = zaTuk;
    return zaTuk;
}

int sCycli(int zaDoKoeChislo, int zaSKakvoPredno){

    for(int doKoeChislo = 1; doKoeChislo <= zaDoKoeChislo; doKoeChislo++){
        for(int sKakvoPredno = 0; sKakvoPredno <= 9; sKakvoPredno++){
            int zaTuk = mnogoMalko;

            for(int i = naiMalkoKolko; i <= naiMnogoKolko; i++){
                if(sKakvoPredno == 0 || abs(sKakvoPredno - i) <= naiMnogoRazlika){
                    int tekushto = chisla[doKoeChislo]*i + priTolkova[doKoeChislo - 1][i];

                    zaTuk = max(zaTuk, tekushto);
                }
            }

            priTolkova[doKoeChislo][sKakvoPredno] = zaTuk;
        }
    }

    return priTolkova[zaDoKoeChislo][zaSKakvoPredno];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiChisla>>naiMalkoKolko>>naiMnogoKolko>>naiMnogoRazlika;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    /*for(int i = 0; i <= broiChisla; i++){
        for(int j = 0; j < 10; j++){
            priTolkova[i][j] = mnogoMalko;
        }
    }

    int naiGolqmaSuma = maximalnaSuma(broiChisla, 0);*/
    int naiGolqmaSuma = sCycli(broiChisla, 0);

    cout<<naiGolqmaSuma<<endl;

    return 0;
}
