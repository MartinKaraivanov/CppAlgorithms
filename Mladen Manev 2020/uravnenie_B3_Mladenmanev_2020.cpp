#include<iostream>
#include<cmath>
using namespace std;

int broiChisla;
int kakvaSuma;

int chisla[1010];

const int mnogo = 1000000007;


int sumaOtNachalotoDoTuk[1010];

int minimalnaSumaOtNachDoTuk[1010];
int maximalnaSumaOtNachDoTuk[1010];

int priTolkova[2000050];

int prefixPriTolkova[2000050];

int otDoSuma(int index, int otKade, int doKade){
   return (prefixPriTolkova[doKade - minimalnaSumaOtNachDoTuk[index]+1] -
        prefixPriTolkova[otKade - 1 - minimalnaSumaOtNachDoTuk[index]+1]) % mnogo;
}

void natrupai(int index){

    prefixPriTolkova[0] = priTolkova[0];

    int doKadeVartim = maximalnaSumaOtNachDoTuk[index] - minimalnaSumaOtNachDoTuk[index] + 1;

    for(int i = 1; i <= doKadeVartim; i++){
        prefixPriTolkova[i] = (prefixPriTolkova[i - 1] + priTolkova[i]) % mnogo;
    }
}

int daiPriTolkova(int index, int sbor){
    if(sbor < minimalnaSumaOtNachDoTuk[index] || sbor > maximalnaSumaOtNachDoTuk[index]){
        return 0;
    }
    return priTolkova[sbor - minimalnaSumaOtNachDoTuk[index]+1];
}

void slojiTamDaETakova(int index, int sbor, int kolko){
    priTolkova[sbor - minimalnaSumaOtNachDoTuk[index]+1] = kolko;
}

/*void inicializiraneNaPriTolkova(){
    for(int i = 0; i <= broiChisla; i++){
        for(int j = 0; j < 200005; j++){
            priTolkova[i][j] = -1;
        }
    }
}*/

/*int broiNachiniZaReshenie(int doKoiIndex, int suma){
    if(doKoiIndex == 0){
        if(suma == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(daiPriTolkova(doKoiIndex, suma) > -1){
        return daiPriTolkova(doKoiIndex, suma);
    }

    int brNachini = 0;

    int doKadeVartim = min(maximalnaSumaOtNachDoTuk[doKoiIndex - 1], suma - chisla[doKoiIndex]);

    for(int s = minimalnaSumaOtNachDoTuk[doKoiIndex - 1]; s <= doKadeVartim; s++){
        brNachini = (brNachini + broiNachiniZaReshenie(doKoiIndex - 1, s)) % mnogo;
    }

    int zaVrasht = brNachini%mnogo;

    slojiTamDaETakova(doKoiIndex, suma, zaVrasht);
    return zaVrasht;
}*/

int sCycli(int zaDoKoiIndex, int zaSuma){
    slojiTamDaETakova(0, 0, 1);
    natrupai(0);

    for(int doKoiIndex = 1; doKoiIndex <= zaDoKoiIndex; doKoiIndex++){

        for(int suma = minimalnaSumaOtNachDoTuk[doKoiIndex]; suma <= maximalnaSumaOtNachDoTuk[doKoiIndex]; suma++){
            int brNachini = 0;

            int doKadeVartim = min(maximalnaSumaOtNachDoTuk[doKoiIndex - 1], suma - chisla[doKoiIndex]);
            //int doKadeVartim = maximalnaSumaOtNachDoTuk[doKoiIndex - 1];

            /*for(int s = minimalnaSumaOtNachDoTuk[doKoiIndex - 1]; s <= doKadeVartim; s++){
                brNachini = (brNachini + daiPriTolkova(doKoiIndex - 1, s)) % mnogo;
            }*/

            brNachini = otDoSuma(doKoiIndex - 1,  minimalnaSumaOtNachDoTuk[doKoiIndex - 1], doKadeVartim);

            slojiTamDaETakova(doKoiIndex, suma, brNachini);
        }

        natrupai(doKoiIndex);

    }

    return daiPriTolkova(zaDoKoiIndex, zaSuma);
}

int main(){
    cin>>broiChisla;
    cin>>kakvaSuma;

    kakvaSuma += broiChisla * 1000;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
        chisla[i] += 1000;
        sumaOtNachalotoDoTuk[i] = sumaOtNachalotoDoTuk[i - 1] + chisla[i];
    }

    for(int i = 1; i <= broiChisla; i++){
        minimalnaSumaOtNachDoTuk[i] = sumaOtNachalotoDoTuk[i];
        maximalnaSumaOtNachDoTuk[i] = kakvaSuma - (sumaOtNachalotoDoTuk[broiChisla] - sumaOtNachalotoDoTuk[i]);
    }

    //inicializiraneNaPriTolkova();

    int brNaciniZaSumata = sCycli(broiChisla, kakvaSuma)%mnogo;

    cout<<brNaciniZaSumata<<endl;

    return 0;
}
