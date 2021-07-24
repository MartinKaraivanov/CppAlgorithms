#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int broiChisla;
int broiGrupi;

double chisla[505];

double sborOtDo[505][505];

double srednoAritmetichnoOtDo[505][505];

double dOtDo[505][505];

void praveneNaD(){
    for(int i = 1; i <= broiChisla; i++){
        double segSbor = 0;
        for(int j = i; j <= broiChisla; j++){
            segSbor += chisla[j];
            sborOtDo[i][j] = segSbor;
        }
    }

    for(int i = 1; i <= broiChisla; i++){
        for(int j = i; j <= broiChisla; j++){
            srednoAritmetichnoOtDo[i][j] = sborOtDo[i][j]/(j - i + 1);
        }
    }

    for(int i = 1; i <= broiChisla; i++){
        for(int j = i; j <= broiChisla; j++){
            double dTuk = 0;

            for(int k = i; k <= j; k++){
                double razlikata = chisla[k] - srednoAritmetichnoOtDo[i][j];
                dTuk += razlikata*razlikata;
            }

            dOtDo[i][j] = dTuk;
        }
    }
}

double priTolkova[505][505];

double naiMalakVazmozhenSbor(int kolkoGrupi, int doKoiIndex){
    if(kolkoGrupi == 0){
        if(doKoiIndex == 0){
            return 0;
        }else{
            return 10000000;
        }
    }

    if(doKoiIndex <= 0){
        return 10000000;
    }

    if(priTolkova[kolkoGrupi][doKoiIndex] > -1){
        return priTolkova[kolkoGrupi][doKoiIndex];
    }

    int otKolkoDalga = 1;

    if(kolkoGrupi == 1){
        otKolkoDalga = doKoiIndex;
    }

    int doKolkoDalga = doKoiIndex - kolkoGrupi + 1;

    double naiMalkata = 10000000;

    for(int daljina = otKolkoDalga; daljina <= doKolkoDalga; daljina++){
        double zaTuk = dOtDo[doKoiIndex - daljina + 1][doKoiIndex] + naiMalakVazmozhenSbor(kolkoGrupi - 1, doKoiIndex - daljina);

        naiMalkata = min(naiMalkata, zaTuk);
    }

    priTolkova[kolkoGrupi][doKoiIndex] = naiMalkata;
    return naiMalkata;
}

void nuliraneNaPriTolkova(){
    for(int i = 0; i <= broiGrupi; i++){
        for(int j = 0; j <= broiChisla; j++){
            priTolkova[i][j] = -1;
        }
    }
}

double priTolkova2[2][505];

double sCycli(int zaKolkoGrupi, int zaDoKoiIndex){
    for(int kolkoGrupi = 1; kolkoGrupi <= zaKolkoGrupi; kolkoGrupi++){
        for(int doKoiIndex = 1; doKoiIndex <= zaDoKoiIndex; doKoiIndex++){
            int otKolkoDalga = 1;

            if(kolkoGrupi == 1){
                otKolkoDalga = doKoiIndex;
            }

            int doKolkoDalga = doKoiIndex - kolkoGrupi + 1;

            double naiMalkata = 10000000;

            for(int daljina = otKolkoDalga; daljina <= doKolkoDalga; daljina++){
                double zaTuk =
                    dOtDo[doKoiIndex - daljina + 1][doKoiIndex] + priTolkova2[(kolkoGrupi - 1)%2][doKoiIndex - daljina];

                naiMalkata = min(naiMalkata, zaTuk);
            }

            priTolkova2[kolkoGrupi%2][doKoiIndex] = naiMalkata;
        }
    }

    return priTolkova2[zaKolkoGrupi%2][zaDoKoiIndex];
}

int main(){
    cin>>broiChisla>>broiGrupi;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    praveneNaD();

    //nuliraneNaPriTolkova();
    //double naiMalkataSuma = naiMalakVazmozhenSbor(broiGrupi, broiChisla);
    double naiMalkataSuma = sCycli(broiGrupi, broiChisla);

    cout<<fixed<<setprecision(6)<<naiMalkataSuma<<endl;

    return 0;
}
