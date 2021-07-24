#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaSastezatelq{
    int kolkoMuEVremeto;
    int naKoqObikolkaE;
    int koiE;
    int zaKolkoVremeNapraviTaziObikolka;

    DanniZaSastezatelq(int kolkoMuEVremeto, int naKoqObikolkaE, int koiE, int zaKolkoVremeNapraviTaziObikolka)
        : kolkoMuEVremeto(kolkoMuEVremeto), naKoqObikolkaE(naKoqObikolkaE), koiE(koiE), zaKolkoVremeNapraviTaziObikolka(zaKolkoVremeNapraviTaziObikolka)
    {
    }
};

struct poSkoro{
    bool operator()(DanniZaSastezatelq const& a, DanniZaSastezatelq const&b)
    {
        return a.kolkoMuEVremeto > b.kolkoMuEVremeto;
    }
};

int broiSastezateli;
int broiObikolki;

int vremeVNormalnoSus[10005];
int obikolkaZaShokoladche[10005];

priority_queue<DanniZaSastezatelq, vector<DanniZaSastezatelq>, poSkoro> vremenaPresichane;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiSastezateli>>broiObikolki;

    for(int i = 0; i < broiSastezateli; i++){
        cin>>vremeVNormalnoSus[i]>>obikolkaZaShokoladche[i];
    }

    for(int i = 0; i < broiSastezateli; i++){
        vremenaPresichane.push({vremeVNormalnoSus[i], 1, i, vremeVNormalnoSus[i]});
    }

    int naiMnogoPodred = 0;
    int prednoto = -1;
    int segashnoPodred = 0;

    while(vremenaPresichane.empty() == false){
        DanniZaSastezatelq naiOtped = vremenaPresichane.top();
        vremenaPresichane.pop();

        if(naiOtped.kolkoMuEVremeto == prednoto){
            segashnoPodred++;
        }else{
            segashnoPodred = 1;
            prednoto = naiOtped.kolkoMuEVremeto;
        }
        naiMnogoPodred = max(naiMnogoPodred, segashnoPodred);

        if(naiOtped.naKoqObikolkaE <= broiObikolki){
            int novoVremeZaObik = 0;
            if(naiOtped.naKoqObikolkaE % obikolkaZaShokoladche[naiOtped.koiE] == 0){
                novoVremeZaObik = vremeVNormalnoSus[naiOtped.koiE];
            }else{
                novoVremeZaObik = naiOtped.zaKolkoVremeNapraviTaziObikolka + 1;
            }

            vremenaPresichane.push({naiOtped.kolkoMuEVremeto + novoVremeZaObik,
                                   naiOtped.naKoqObikolkaE + 1,
                                   naiOtped.koiE,
                                   novoVremeZaObik});
        }
    }

    cout<<naiMnogoPodred<<endl;

    return 0;
}
