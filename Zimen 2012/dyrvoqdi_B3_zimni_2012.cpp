#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct DanniZaDaskata{
    double zaKolkoMinavaParviq;
    double zaKolkoMinavaVtoriq;
};

int broiDaski;
DanniZaDaskata daskite[275];

bool sortirane(DanniZaDaskata a, DanniZaDaskata b){
    double parvoto = a.zaKolkoMinavaParviq/a.zaKolkoMinavaVtoriq;
    double vtoroto = b.zaKolkoMinavaParviq/b.zaKolkoMinavaVtoriq;
    return (parvoto) > (vtoroto);
}

int main(){
    cin>>broiDaski;

    for(int i = 1; i <= broiDaski; i++){
        cin>>daskite[i].zaKolkoMinavaParviq>>daskite[i].zaKolkoMinavaVtoriq;
    }

    sort(daskite, daskite + broiDaski + 1, sortirane);

    double vremeNaParviq = 0;
    double vremeNaVtoriq = 0;

    int prediKoqDaskaEParviq = 0;
    int prediKoqDaskaEVtoriq = broiDaski;

    while(true){
        if(prediKoqDaskaEParviq == prediKoqDaskaEVtoriq){
            break;
        }

        if((vremeNaParviq + daskite[prediKoqDaskaEParviq].zaKolkoMinavaParviq) -
            (vremeNaVtoriq + daskite[prediKoqDaskaEVtoriq].zaKolkoMinavaVtoriq) > 0.000001)
        {
            vremeNaVtoriq += daskite[prediKoqDaskaEVtoriq].zaKolkoMinavaVtoriq;
            prediKoqDaskaEVtoriq--;
        }else{
            vremeNaParviq += daskite[prediKoqDaskaEParviq].zaKolkoMinavaParviq;
            prediKoqDaskaEParviq++;
        }
    }

    //cout<<prediKoqDaskaEParviq<<" "<<prediKoqDaskaEVtoriq<<endl;
    //cout<<vremeNaParviq<<" "<<vremeNaVtoriq<<endl;

    double nuzhnoVremeNaParviq = daskite[prediKoqDaskaEParviq].zaKolkoMinavaParviq;
    double nuzhnoVremeNaVtoriq = daskite[prediKoqDaskaEVtoriq].zaKolkoMinavaVtoriq;

    //cout<<nuzhnoVremeNaParviq<<" "<<nuzhnoVremeNaVtoriq<<endl;

    double razlikaVavVremenata = vremeNaParviq - vremeNaVtoriq;

    if(razlikaVavVremenata > 0.000001){
        double novoVremeNaVtoriq = nuzhnoVremeNaVtoriq - razlikaVavVremenata;
        double kakvaChastE = novoVremeNaVtoriq/nuzhnoVremeNaVtoriq;
        double novoVremeNaParviq = nuzhnoVremeNaParviq*kakvaChastE;

        nuzhnoVremeNaParviq = novoVremeNaParviq;
        nuzhnoVremeNaVtoriq = novoVremeNaVtoriq;
    }else{
        if(razlikaVavVremenata < -0.000001){
            double novoVremeNaParviq = nuzhnoVremeNaParviq + razlikaVavVremenata;
            double kakvaChastE = novoVremeNaParviq/nuzhnoVremeNaParviq;
            double novoVremeNaVtoriq = nuzhnoVremeNaVtoriq*kakvaChastE;

            nuzhnoVremeNaParviq = novoVremeNaParviq;
            nuzhnoVremeNaVtoriq = novoVremeNaVtoriq;
        }
    }

    //cout<<nuzhnoVremeNaParviq<<" "<<nuzhnoVremeNaVtoriq<<endl;

    double kogatoShePochnatIDvamata = max(vremeNaParviq, vremeNaVtoriq);

    double nuzhnoVremeZaSreshtane = (nuzhnoVremeNaParviq*nuzhnoVremeNaVtoriq)/(nuzhnoVremeNaParviq+nuzhnoVremeNaVtoriq);

    cout<<fixed<<setprecision(3)<<kogatoShePochnatIDvamata+nuzhnoVremeZaSreshtane<<endl;

    return 0;
}
