#include<iostream>
using namespace std;

int broiPredmeti;
int kapacitetParva;
int kapacitetVtora;
int kapacitetTreta;

int predmetiTeglo[505];

const int mnogo = 1000000007;

int priTolkova[2][502][502];

/*int broiNachiniZaRazpredelenie
(int doKoiPredmet, int sKapacitetNaParva, int sKapacitetNaVtora, int sKapacitetNaTreta)
{
    if(sKapacitetNaParva < 0 || sKapacitetNaVtora < 0 || sKapacitetNaTreta < 0){
        return 0;
    }
    if(doKoiPredmet == 0){
        return 1;
    }

    if(priTolkova[doKoiPredmet][sKapacitetNaParva][sKapacitetNaVtora][sKapacitetNaTreta] > -1){
        return priTolkova[doKoiPredmet][sKapacitetNaParva][sKapacitetNaVtora][sKapacitetNaTreta];
    }

    int akoGoZlozhiVParvata =
        broiNachiniZaRazpredelenie(doKoiPredmet - 1,
        sKapacitetNaParva - predmetiTeglo[doKoiPredmet],
        sKapacitetNaVtora,
        sKapacitetNaTreta)%mnogo;

    int akoGoSlozhiVavVtorata =
        broiNachiniZaRazpredelenie(doKoiPredmet - 1,
        sKapacitetNaParva,
        sKapacitetNaVtora - predmetiTeglo[doKoiPredmet],
        sKapacitetNaTreta)%mnogo;

    int akoGoSlozhiVTretata =
        broiNachiniZaRazpredelenie(doKoiPredmet - 1,
        sKapacitetNaParva,
        sKapacitetNaVtora,
        sKapacitetNaTreta - predmetiTeglo[doKoiPredmet])%mnogo;

    int segashno = (akoGoZlozhiVParvata+ akoGoSlozhiVavVtorata + akoGoSlozhiVTretata)%mnogo;

    priTolkova[doKoiPredmet][sKapacitetNaParva][sKapacitetNaVtora][sKapacitetNaTreta] = segashno;
    return segashno;
}*/

int sCycli(int zaDoKoiIndexOtranicata, int zaKapacitet1, int zaKapacitet2, int zaKapacitet3){
    priTolkova[0][0][0] = 1;
/*
    int doTuk[505];
    doTuk[0] = 0;
    for(int i = 1; i <= zaDoKoiIndexOtranicata; i++){
        doTuk[i] = predmetiTeglo[i] + doTuk[i - 1];
    }
*/

    int obshtIzpolvanKapacitet = 0;
    for(int doKoiPredmet = 1; doKoiPredmet <= zaDoKoiIndexOtranicata; doKoiPredmet++){
        obshtIzpolvanKapacitet += predmetiTeglo[doKoiPredmet];

        for(int sIzpolzvanKapacitetNaParva = 0; sIzpolzvanKapacitetNaParva <= min(zaKapacitet1, obshtIzpolvanKapacitet); sIzpolzvanKapacitetNaParva++){
            for(int sIzpolzvanKapacitetNaVtora = 0; sIzpolzvanKapacitetNaVtora <= min(zaKapacitet2, obshtIzpolvanKapacitet); sIzpolzvanKapacitetNaVtora++){
                //for(int sIzpolzvanKapacitetNaTreta = 0; sIzpolzvanKapacitetNaTreta <= zaKapacitet3; sIzpolzvanKapacitetNaTreta++){
                    int sIzpolzvanKapacitetNaTreta =
                        obshtIzpolvanKapacitet - sIzpolzvanKapacitetNaParva - sIzpolzvanKapacitetNaVtora;
                    if(sIzpolzvanKapacitetNaTreta < 0 || sIzpolzvanKapacitetNaTreta > zaKapacitet3){
                        priTolkova[doKoiPredmet % 2][sIzpolzvanKapacitetNaParva][sIzpolzvanKapacitetNaVtora] = 0;
                        continue;
                    }

                    int akoGoZlozhiVParvata = 0;
                    if(sIzpolzvanKapacitetNaParva - predmetiTeglo[doKoiPredmet] >= 0){
                        akoGoZlozhiVParvata =
                            priTolkova[(doKoiPredmet - 1) % 2][sIzpolzvanKapacitetNaParva - predmetiTeglo[doKoiPredmet]][sIzpolzvanKapacitetNaVtora]%mnogo;
                    }

                    int akoGoSlozhiVavVtorata = 0;
                    if(sIzpolzvanKapacitetNaVtora - predmetiTeglo[doKoiPredmet] >= 0){
                        akoGoSlozhiVavVtorata =
                            priTolkova[(doKoiPredmet - 1) % 2][sIzpolzvanKapacitetNaParva][sIzpolzvanKapacitetNaVtora - predmetiTeglo[doKoiPredmet]]%mnogo;
                    }

                    int akoGoSlozhiVTretata = 0;
                    if(sIzpolzvanKapacitetNaTreta - predmetiTeglo[doKoiPredmet] >= 0){
                        akoGoSlozhiVTretata =
                            priTolkova[(doKoiPredmet - 1) % 2][sIzpolzvanKapacitetNaParva][sIzpolzvanKapacitetNaVtora]%mnogo;
                    }

                    int segashno = ((akoGoZlozhiVParvata+ akoGoSlozhiVavVtorata)%mnogo + akoGoSlozhiVTretata)%mnogo;

                    priTolkova[doKoiPredmet % 2][sIzpolzvanKapacitetNaParva][sIzpolzvanKapacitetNaVtora] = segashno;
                //}
            }
        }
    }

    int zaVrasht = 0;

    for(int i = 0; i <= zaKapacitet1; i++){
        for(int j = 0; j <= zaKapacitet2; j++){
            zaVrasht = (zaVrasht + priTolkova[zaDoKoiIndexOtranicata % 2][i][j]) % mnogo;
        }
    }
    return zaVrasht;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiPredmeti>>kapacitetParva>>kapacitetVtora>>kapacitetTreta;

    for(int i = 1; i <= broiPredmeti; i++){
        cin>>predmetiTeglo[i];
    }

    int nachiniZaRazpredelqneNaBagazha = sCycli(broiPredmeti, kapacitetParva, kapacitetVtora, kapacitetTreta);
        //broiNachiniZaRazpredelenie(broiPredmeti, kapacitetParva, kapacitetVtora, kapacitetTreta)%mnogo;

    cout<<nachiniZaRazpredelqneNaBagazha<<endl;


    return 0;
}
