#include<iostream>
using namespace std;

int broiGradove;
int broiBolnici;

int otNachalotoDoTuk[1010];

int razstoqnietoMezhdu(int otKade, int doKade){
    return otNachalotoDoTuk[doKade] - otNachalotoDoTuk[otKade];
}

int dPriTolkova[1010][1010];

int dTuka(int parvaB, int vtoraB){
    if(dPriTolkova[parvaB][vtoraB] > -1){
        return dPriTolkova[parvaB][vtoraB];
    }

    int maximalnoto = 0;
    for(int i = parvaB + 1; i < vtoraB; i++){
        int doParvata = razstoqnietoMezhdu(parvaB, i);
        int doVtorata = razstoqnietoMezhdu(i, vtoraB);
        maximalnoto = max(maximalnoto, min(doParvata, doVtorata));
    }

    dPriTolkova[parvaB][vtoraB] = maximalnoto;
    return maximalnoto;
}

int naiKasPriTolkova[1010][1010];

int naiKasichkoto(int brGradcheta, int broiBlniciZaSlagane, bool imameLiBolnicaTochnoVdqsno){
    if(brGradcheta == 0){
        return 0;
    }
    if(broiBlniciZaSlagane == 0 && !imameLiBolnicaTochnoVdqsno){
        return 3000000;
    }
    if(broiBlniciZaSlagane == 0 && imameLiBolnicaTochnoVdqsno){
        return otNachalotoDoTuk[brGradcheta];
    }
    if(broiBlniciZaSlagane > brGradcheta){
        return 3000000;
    }
    if(broiBlniciZaSlagane == brGradcheta){
        return 0;
    }

    if(naiKasPriTolkova[brGradcheta][broiBlniciZaSlagane] > -1 && imameLiBolnicaTochnoVdqsno == true){
        return naiKasPriTolkova[brGradcheta][broiBlniciZaSlagane];
    }

    int minimalnichkoo = 353000000;

    for(int i = 0; i < brGradcheta; i++){
        if(imameLiBolnicaTochnoVdqsno == true){
            int otTukaNaDqsno = dTuka(i, brGradcheta);
            int akoTukaEBolnicata = naiKasichkoto(i, broiBlniciZaSlagane - 1, true);
            int zaTuka = max(otTukaNaDqsno, akoTukaEBolnicata);
            minimalnichkoo = min(minimalnichkoo, zaTuka);
        }else{
            int akoTukEBolnicata = naiKasichkoto(i, broiBlniciZaSlagane - 1, true);
            int akoIdvatTuka = razstoqnietoMezhdu(i, broiGradove - 1);
            int zaTuk = max(akoTukEBolnicata, akoIdvatTuka);
            minimalnichkoo = min(minimalnichkoo, zaTuk);
        }
    }

    if(imameLiBolnicaTochnoVdqsno == true){
        naiKasPriTolkova[brGradcheta][broiBlniciZaSlagane] = minimalnichkoo;
    }
    return minimalnichkoo;
}

int main(){
    cin>>broiGradove>>broiBolnici;

    otNachalotoDoTuk[0] = 0;

    for(int i = 1; i < broiGradove; i++){
        int doNego;
        cin>>doNego;
        otNachalotoDoTuk[i] = doNego + otNachalotoDoTuk[i - 1];
    }

    for(int i = 0; i < broiGradove; i++){
        for(int j = 0; j < broiBolnici; j++){
            naiKasPriTolkova[i][j] = -1;
        }
    }

    for(int i = 0; i < broiGradove; i++){
        for(int j = 0; j < broiGradove; j++){
            dPriTolkova[i][j] = -1;
        }
    }

    int minimalnichko = naiKasichkoto(broiGradove, broiBolnici, false);

    cout<<minimalnichko<<endl;

    return 0;
}
