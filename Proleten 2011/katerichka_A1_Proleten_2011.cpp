#include<iostream>
#include<cmath>
using namespace std;

int broiKupchinki;

int orehiVKupch[100010];

int kolkoTrDaSePoluchi;

int smetniPremestvaniq(int start, int posoka){

    int index = start;

    bool parvotoLiE = true;

    int tekushtPrenos = 0;

    int obshtPrenos = 0;

    while(index != start || parvotoLiE == true){
        parvotoLiE = false;

        int tuka = orehiVKupch[index] + tekushtPrenos;

        int kolkoNiTrqbvat = kolkoTrDaSePoluchi - tuka;

        //cout<<index<<" tekushtiq prenos e "<<tekushtPrenos<<" i tuka se poluchava "<<tuka<<" sledovatelno veche ni trqbvat "<<kolkoNiTrqbvat<<" i she prenesem na sledvashtiq ";
        //cout<<-kolkoNiTrqbvat<<endl;

        obshtPrenos += abs(kolkoNiTrqbvat);
        tekushtPrenos = -kolkoNiTrqbvat;

        index += posoka;

        if(index < 0){
            index = broiKupchinki - 1;
        }
        if(index >= broiKupchinki){
            index = 0;
        }
    }

    return obshtPrenos;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiKupchinki;

    int sbor = 0;

    for(int i = 0; i < broiKupchinki; i++){
        cin>>orehiVKupch[i];
        sbor += orehiVKupch[i];
    }

    kolkoTrDaSePoluchi = sbor/broiKupchinki;

    int naiMalkiqSbor = 1000000000;

    for(int i = 0; i < broiKupchinki; i++){
        int tukaNadqsno = smetniPremestvaniq(i, 1);

        cout<<i<<" "<<tukaNadqsno<<endl;

        naiMalkiqSbor = min(naiMalkiqSbor, tukaNadqsno);
    }

    cout<<naiMalkiqSbor<<endl;

    return 0;
}
