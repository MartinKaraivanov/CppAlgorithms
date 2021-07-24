#include<iostream>
#include<vector>
using namespace std;

int kolkoDaEdalga;
int doKoeChislo;

const int mnogo = 1000000007;

vector<int> deliteliIUmnozhiteliNaTozi[1010];

int priTolkova[1010][1010];

void smqtaneNaDeliteli(){
    for(int i = 1; i <= doKoeChislo; i++){
        for(int j = 1; j <= max(i/2, 1); j++){
            if(i % j == 0){
                deliteliIUmnozhiteliNaTozi[i].push_back(j);
            }
        }
        for(int j = 1; j <= doKoeChislo; j++){
            if(j == i){
                continue;
            }
            if(j % i == 0){
                deliteliIUmnozhiteliNaTozi[i].push_back(j);
            }
        }
    }
}

int maximalenBroRedici(int indexNaRedicata, int chislo){
    if(indexNaRedicata == 0){
        return 1;
    }

    if(priTolkova[indexNaRedicata][chislo] > 0){
        return priTolkova[indexNaRedicata][chislo]%mnogo;
    }

    int zaTuk = 0;

    /*for(int i = 1; i <= doKoeChislo; i++){
        if(i != chislo){
            if(i % chislo == 0 || chislo % i == 0){
                int segashno = maximalenBroRedici(indexNaRedicata - 1, i) % mnogo;

                zaTuk = (zaTuk + segashno)%mnogo;
            }
        }
    }*/

    for(unsigned int i = 0; i < deliteliIUmnozhiteliNaTozi[chislo].size(); i++){
        if(deliteliIUmnozhiteliNaTozi[chislo][i] == chislo){
            continue;
        }
        int segashno = maximalenBroRedici(indexNaRedicata - 1, deliteliIUmnozhiteliNaTozi[chislo][i]);
        zaTuk = (zaTuk + segashno)%mnogo;
    }

    int zaVrasht = zaTuk%mnogo;

    priTolkova[indexNaRedicata][chislo] = zaVrasht;
    return zaVrasht;
}


void sCycli(){
    for(int i = 1; i <= doKoeChislo; i++){
        priTolkova[0][i] = 1;
    }

    for(int indexNaRedicata = 1; indexNaRedicata < kolkoDaEdalga; indexNaRedicata++){
        for(int chislo = 1; chislo <= doKoeChislo; chislo++){
            int zaTuk = 0;

            for(unsigned int i = 0; i < deliteliIUmnozhiteliNaTozi[chislo].size(); i++){
                if(deliteliIUmnozhiteliNaTozi[chislo][i] == chislo){
                    continue;
                }
                int segashno = priTolkova[indexNaRedicata - 1][deliteliIUmnozhiteliNaTozi[chislo][i]];
                zaTuk = (zaTuk + segashno)%mnogo;
            }

            int zaVrasht = zaTuk%mnogo;

            priTolkova[indexNaRedicata][chislo] = zaVrasht;
        }
    }
}

int main(){
    cin>>kolkoDaEdalga>>doKoeChislo;

    smqtaneNaDeliteli();

    sCycli();

    int broiRediciZaObrazuvane = 0;

    for(int i = 1; i <= doKoeChislo; i++){
        broiRediciZaObrazuvane = (broiRediciZaObrazuvane + priTolkova[kolkoDaEdalga - 1][i])%mnogo;
    }

    cout<<broiRediciZaObrazuvane<<endl;

    return 0;
}
