#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

int broiTestove;
int broiChashki;

//int pqsakVChaska[128];
vector<int> pqsakVChaska;

bool kraqtLiE(){

    bool imaLiVazmozhnost = false;

    for(int i = 0; i < broiChashki; i++){
        bool tukaMojeLi = false;

        if(i > 0){
            if(pqsakVChaska[i - 1] != -1 && pqsakVChaska[i - 1] + pqsakVChaska[i] <= 250){
                tukaMojeLi = true;
            }
        }

        if(i < broiChashki - 1){
            if(pqsakVChaska[i + 1] != -1 && pqsakVChaska[i + 1] + pqsakVChaska[i] <= 250){
                tukaMojeLi = true;
            }
        }

        if(tukaMojeLi == true){
            imaLiVazmozhnost = true;
            break;
        }
    }

    return !imaLiVazmozhnost;
}

map<vector<int>, int>  priTolkova;

bool pechelivshaLiEPoziciqta(){
    /*cout<<"sega e "<<endl;

    for(int i = 0; i < broiChashki; i++){
        cout<<pqsakVChaska[i]<<" ";
    }
    cout<<endl;*/

    if(kraqtLiE() == true){
        return false;
    }

    if(priTolkova[pqsakVChaska] == 1){
        return true;
    }
    if(priTolkova[pqsakVChaska] == 2){
        return false;
    }

    bool imaLiPechelivshaVazm = false;

    for(int i = 0; i < broiChashki; i++){
        if(i > 0 && pqsakVChaska[i] != -1 && pqsakVChaska[i - 1] != -1 && pqsakVChaska[i - 1] + pqsakVChaska[i] <= 250){
            int originalnoTaqChaska = pqsakVChaska[i];

            pqsakVChaska[i - 1] += pqsakVChaska[i];
            pqsakVChaska[i] = -1;

            bool tekushto = pechelivshaLiEPoziciqta();

            pqsakVChaska[i] = originalnoTaqChaska;
            pqsakVChaska[i - 1] -= originalnoTaqChaska;

            if(tekushto == false){
                imaLiPechelivshaVazm = true;
                break;
            }
        }

        if(i < broiChashki - 1 && pqsakVChaska[i] != -1 && pqsakVChaska[i + 1] != -1 && pqsakVChaska[i + 1] + pqsakVChaska[i] <= 250){
            int originalnoTaqChaska = pqsakVChaska[i];

            pqsakVChaska[i + 1] += pqsakVChaska[i];
            pqsakVChaska[i] = -1;

            bool tekushto = pechelivshaLiEPoziciqta();

            pqsakVChaska[i] = originalnoTaqChaska;
            pqsakVChaska[i + 1] -= originalnoTaqChaska;

            if(tekushto == false){
                imaLiPechelivshaVazm = true;
                break;
            }
        }
    }

    if(imaLiPechelivshaVazm == true){
        priTolkova[pqsakVChaska] = 1;
    }else{
        priTolkova[pqsakVChaska] = 2;
    }

    return imaLiPechelivshaVazm;
}

bool otgovori[16];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>broiChashki;

        pqsakVChaska.clear();

        for(int i = 0; i < broiChashki; i++){
            //cin>>pqsakVChaska[i];
            int tuka;
            cin>>tuka;
            pqsakVChaska.push_back(tuka);
        }

        otgovori[t] = pechelivshaLiEPoziciqta();
    }

    for(int i = 0; i < broiTestove; i++){
        if(otgovori[i] == true){
            cout<<"Elly"<<endl;
        }else{
            cout<<"Kriss"<<endl;
        }
    }

    return 0;
}
