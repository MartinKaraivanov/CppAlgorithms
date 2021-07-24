#include<iostream>
#include<vector>
#include<cmath>
#include "absent.h"
using namespace std;

bool get_bit(int i, int j);

void submit_absent(int x);

bool daiBit(int i, int j){
    return get_bit(i, 10 - j);
}

int kakuvEBitaNaPoziciq(int chislo, int poziciq){
    chislo >>= poziciq;
    return chislo & 1;
}

void play(int n){
    vector<int> nomeraVSpisukaNaGospojata;

    for(int i = 1; i < n; i++){
        nomeraVSpisukaNaGospojata.push_back(i);
    }

    vector<int> vazmozhniOtPulniqSpisak;

    for(int i = 1; i <= n; i++){
        vazmozhniOtPulniqSpisak.push_back(i);
    }

   int naKoiBitSme = 0;

    while(nomeraVSpisukaNaGospojata.size() > 0){
        vector<int> sKrainaEdinica;
        vector<int> sKrainaNula;

        vector<int> vazmozhniSNula;
        vector<int> vazmozhniSEdno;

        for(unsigned int i = 0; i < nomeraVSpisukaNaGospojata.size(); i++){
            bool kakvoE = daiBit(nomeraVSpisukaNaGospojata[i], naKoiBitSme);
            if(kakvoE == false){
                sKrainaNula.push_back(nomeraVSpisukaNaGospojata[i]);
            }else{
                sKrainaEdinica.push_back(nomeraVSpisukaNaGospojata[i]);
            }
        }

        for(unsigned int i = 0; i < vazmozhniOtPulniqSpisak.size(); i++){
            if(kakuvEBitaNaPoziciq(vazmozhniOtPulniqSpisak[i], naKoiBitSme) == 0){
                vazmozhniSNula.push_back(vazmozhniOtPulniqSpisak[i]);
            }else{
                vazmozhniSEdno.push_back(vazmozhniOtPulniqSpisak[i]);
            }
        }

        int razlikaVNulite = vazmozhniSNula.size() - sKrainaNula.size();
        int razlikaVEdinicite = vazmozhniSEdno.size() - sKrainaEdinica.size();

        //cout<<sNulaNaTakavaPoziciq<<" "<<sEdnoNaTakavaPoziciq<<endl<<sKrainaNula.size()<<" "<<sKrainaEdinica.size()<<endl;

        if(razlikaVNulite > razlikaVEdinicite){
            nomeraVSpisukaNaGospojata = sKrainaNula;
            vazmozhniOtPulniqSpisak = vazmozhniSNula;
        }else{
            nomeraVSpisukaNaGospojata = sKrainaEdinica;
            vazmozhniOtPulniqSpisak = vazmozhniSEdno;
        }
        naKoiBitSme++;
    }

    int otsustvasht = vazmozhniOtPulniqSpisak[0];

    submit_absent(otsustvasht);
}
