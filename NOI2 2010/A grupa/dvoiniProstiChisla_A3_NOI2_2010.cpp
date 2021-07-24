#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;

int a;
int b;

bool sastavnoLiE[50000010];

vector<int> prostiChisla;

void eratosten(){
    int n = b;

    int korenKvadraten = sqrt(b);

    sastavnoLiE[0] = true;
    sastavnoLiE[1] = true;

    for(int i = 2; i <= korenKvadraten; i++){
        if(sastavnoLiE[i] == false){
            for(int j = i*i; j <= n; j+=i){
                sastavnoLiE[j] = true;
            }
        }
    }
}

void praveneNaProstiteChisla(){
    for(int i = a; i <= b; i++){
        if(sastavnoLiE[i] == false){
            prostiChisla.push_back(i);
        }
    }
}

int kolkoCifriIma(int chislo){
    int brCifri = 0;

    while(chislo > 0){
        chislo >>= 1;
        brCifri++;
    }

    return brCifri;
}

int chislotoOtKoiIndexKolkoDulgo(int chislo, int otKade, int kolkoDalgo){
    chislo >>= otKade;

    int maska = ~((~1) << (kolkoDalgo - 1));

    return maska&chislo;
}

int koqECifrataNaToziIndex(int chislo, int koiIndex){
    chislo >>= koiIndex;

    return chislo&1;
}

bool dvoinoProstoLiE(int chislo){
    //cout<<chislo<<" ";

    bool hubavoLiE = false;

    int kolkoEDalgo = kolkoCifriIma(chislo);

    //cout<<"Daljina "<<kolkoEDalgo<<" ";

    if(kolkoEDalgo % 2 == 0){
        int polovinata = kolkoEDalgo/2;
        //string parvaChast = dvoichno.substr(0, polovinata);
        int parvaChast = chislotoOtKoiIndexKolkoDulgo(chislo, polovinata, polovinata);
        //string vtoraChast = dvoichno.substr(polovinata, polovinata);
        int vtoraChast = chislotoOtKoiIndexKolkoDulgo(chislo, 0, polovinata);
        //cout<<parvaChast<<" "<<vtoraChast<<" ";
        if(koqECifrataNaToziIndex(chislo, polovinata - 1) != 0){
            if(sastavnoLiE[parvaChast] == false && sastavnoLiE[vtoraChast] == false){
                hubavoLiE = true;
            }
        }
    }else{
        int polovinata = kolkoEDalgo/2;
        //string parvaChastEdno = dvoichno.substr(0, polovinata);
        int parvaChastEdno = chislotoOtKoiIndexKolkoDulgo(chislo, polovinata, polovinata + 1);
        //string vtoraChastEdno = dvoichno.substr(polovinata, polovinata + 1);
        int vtoraChastEdno = chislotoOtKoiIndexKolkoDulgo(chislo, 0, polovinata);
        //cout<<parvaChastEdno<<" "<<vtoraChastEdno<<" ";
        if(koqECifrataNaToziIndex(chislo, polovinata - 1) != 0){
            if(sastavnoLiE[parvaChastEdno] == false && sastavnoLiE[vtoraChastEdno] == false){
                hubavoLiE = true;
            }
        }

        //string parvaChastDve = dvoichno.substr(0, polovinata + 1);
        int parvaChastDve = chislotoOtKoiIndexKolkoDulgo(chislo, polovinata + 1, polovinata);
        //string vtoraChastDve = dvoichno.substr(polovinata + 1, polovinata);
        int vtoraChastDve = chislotoOtKoiIndexKolkoDulgo(chislo, 0, polovinata + 1);

        //cout<<parvaChastDve<<" "<<vtoraChastDve<<" ";
        if(koqECifrataNaToziIndex(chislo, polovinata) != 0){
            if(sastavnoLiE[parvaChastDve] == false && sastavnoLiE[vtoraChastDve] == false){
                hubavoLiE = true;
            }
        }
    }

    return hubavoLiE;
}

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/

    cin>>a>>b;

    eratosten();
    praveneNaProstiteChisla();

    int broiDvoinoProsti = 0;

    for(unsigned int i = 0; i < prostiChisla.size(); i++){
        if(dvoinoProstoLiE(prostiChisla[i]) == true){
            broiDvoinoProsti++;
        }
    }

    cout<<broiDvoinoProsti<<endl;

    return 0;
}
