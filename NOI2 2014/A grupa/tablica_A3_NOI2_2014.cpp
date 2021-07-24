#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n;

int naKoiRed;
int naKoqKolonka;

bool sastavnoLiE[1000010];

vector<int> prostiChisla;

int broiProstiDeliteliNaTovaChislo[1000010];

vector<int> chislaSTolkovaNaBroiProstiDel[100000];

void eratosten(){
    int doKade = n*n;
    int korenKvadraten = sqrt(doKade);

    sastavnoLiE[0] = true;
    sastavnoLiE[1] = true;

    for(int i = 2; i <= doKade; i++){
        if(sastavnoLiE[i] == false){
            for(int x = i+i; x <= doKade; x+=i){
                sastavnoLiE[x] = true;
                broiProstiDeliteliNaTovaChislo[x]++;
            }
        }
    }
}

void praveneNaProstiteChisla(){
    int doKade = n*n;

    for(int i = 2; i <= doKade; i++){
        if(sastavnoLiE[i] == false){
            prostiChisla.push_back(i);
        }
    }
}

void praveneNaTolkovaNaBroiProstiDeliteli(){
    /*for(unsigned int i = 0; i < prostiChisla.size(); i++){
        int chislotoTuka = prostiChisla[i];
        broiProstiDeliteliNaTovaChislo[chislotoTuka]++;
        for(int j = chislotoTuka+chislotoTuka; j <= n*n; j+=chislotoTuka){
            broiProstiDeliteliNaTovaChislo[j]++;
        }
    }*/

    for(int i = 1; i <= n*n; i++){
       chislaSTolkovaNaBroiProstiDel[broiProstiDeliteliNaTovaChislo[i]].push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>naKoiRed>>naKoqKolonka;

    eratosten();
    praveneNaProstiteChisla();

    praveneNaTolkovaNaBroiProstiDeliteli();

    int koeChisloVTablicataTarsim = (naKoiRed - 1)*n + naKoqKolonka;
    int sKolkoProstiDelitelqE = 0;

    for(int i = 0; true; i++){
        if(chislaSTolkovaNaBroiProstiDel[i].size() < koeChisloVTablicataTarsim){
            koeChisloVTablicataTarsim -= chislaSTolkovaNaBroiProstiDel[i].size();
        }else{
            sKolkoProstiDelitelqE = i;
            break;
        }
    }

    int koeNiEChisloto = chislaSTolkovaNaBroiProstiDel[sKolkoProstiDelitelqE][koeChisloVTablicataTarsim - 1];

    cout<<koeNiEChisloto<<endl;

    return 0;
}
