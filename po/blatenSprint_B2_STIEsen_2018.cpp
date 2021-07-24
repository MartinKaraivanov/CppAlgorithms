#include<iostream>
#include<vector>
using namespace std;

int broiOstrovcheta;
int broiPatechki;

int start;
int finish;

struct Danni{
    int doOstrovche;
    long long razstoqnie;
};

vector<Danni> zaeshkoSasedstvo[10100];
vector<Danni> kostenurskoSasedstvo[10100];

long long naiKasZaehkiPat[10100];
bool imameLiNaiKasZaeshkiPatDoTova[10100];
int zaeshkiRoditel[10100];
bool minavaLiOtTukZaicheto[10100];

long long naiKasKostenurskiPat[10100];
bool imameLiNaiKaskostenurskiPatDoTova[10100];
int kostenurskiRoditel[10100];
bool minavaLiOtTukKostenurcheto[10100];

unsigned long long Mnogo = 10000000;

void zaeshkaDijkstra(){
    for(int doKoi = 1; doKoi <= broiOstrovcheta; doKoi++){
        naiKasZaehkiPat[doKoi] = Mnogo;
    }

    for(int i = 0; i < zaeshkoSasedstvo[start].size(); i++){
        int doKoi = zaeshkoSasedstvo[start][i].doOstrovche;
        int doRazstoianie = zaeshkoSasedstvo[start][i].razstoqnie;
        naiKasZaehkiPat[doKoi] = doRazstoianie;
        zaeshkiRoditel[doKoi] = start;
    }

    naiKasZaehkiPat[start] = 0;
    imameLiNaiKasZaeshkiPatDoTova[start] = true;

    bool nameriliLiSmeNeshto = true;
    while(nameriliLiSmeNeshto){
        nameriliLiSmeNeshto = false;

        long long naiMalko = Mnogo;
        int doKoiOstrovENaiMalkoto;

        for(int prezOstrovche = 1; prezOstrovche <= broiOstrovcheta; prezOstrovche++){
            if((naiKasZaehkiPat[prezOstrovche] < naiMalko) && (imameLiNaiKasZaeshkiPatDoTova[prezOstrovche] == false)){
                naiMalko = naiKasZaehkiPat[prezOstrovche];
                doKoiOstrovENaiMalkoto = prezOstrovche;
                nameriliLiSmeNeshto = true;
            }
        }

        if(nameriliLiSmeNeshto){
            imameLiNaiKasZaeshkiPatDoTova[doKoiOstrovENaiMalkoto] = true;

            for(int x = 0; x < zaeshkoSasedstvo[doKoiOstrovENaiMalkoto].size(); x++){
                int doOstrovche = zaeshkoSasedstvo[doKoiOstrovENaiMalkoto][x].doOstrovche;
                int razst = zaeshkoSasedstvo[doKoiOstrovENaiMalkoto][x].razstoqnie;
                if((imameLiNaiKasZaeshkiPatDoTova[doOstrovche] == false) &&
                   (naiKasZaehkiPat[doOstrovche] >
                        naiKasZaehkiPat[doKoiOstrovENaiMalkoto] + razst))
                {
                    naiKasZaehkiPat[doOstrovche] =
                        naiKasZaehkiPat[doKoiOstrovENaiMalkoto] + razst;

                    //cout<<1<<endl;
                    zaeshkiRoditel[doOstrovche] = doKoiOstrovENaiMalkoto;
                }
            }

        }

    }

}

void kostenurskaDijkstra(){
    for(int doKoi = 1; doKoi <= broiOstrovcheta; doKoi++){
        naiKasKostenurskiPat[doKoi] = Mnogo;
    }

    for(int i = 0; i < kostenurskoSasedstvo[start].size(); i++){
        int doKoi = kostenurskoSasedstvo[start][i].doOstrovche;
        int doRazstoianie = kostenurskoSasedstvo[start][i].razstoqnie;
        naiKasKostenurskiPat[doKoi] = doRazstoianie;
        kostenurskiRoditel[doKoi] = start;
    }

    naiKasKostenurskiPat[start] = 0;
    imameLiNaiKaskostenurskiPatDoTova[start] = true;

    bool pravimLiNeshto = true;
    while(pravimLiNeshto){
        pravimLiNeshto = false;

        long long naiMalko = Mnogo;
        int doKoeOstrovcheENaiMalkoto;

        for(int prezOstrovche = 1; prezOstrovche <= broiOstrovcheta; prezOstrovche++){
            if((naiKasKostenurskiPat[prezOstrovche] < naiMalko) && (!imameLiNaiKaskostenurskiPatDoTova[prezOstrovche])){
                naiMalko = naiKasKostenurskiPat[prezOstrovche];
                doKoeOstrovcheENaiMalkoto = prezOstrovche;
                pravimLiNeshto = true;
            }
        }

        if(pravimLiNeshto){
            imameLiNaiKaskostenurskiPatDoTova[doKoeOstrovcheENaiMalkoto] = true;

            for(int x = 0; x < kostenurskoSasedstvo[doKoeOstrovcheENaiMalkoto].size(); x++){
                int doOstrovche = kostenurskoSasedstvo[doKoeOstrovcheENaiMalkoto][x].doOstrovche;
                int razst = kostenurskoSasedstvo[doKoeOstrovcheENaiMalkoto][x].razstoqnie;
                if((imameLiNaiKaskostenurskiPatDoTova[doOstrovche] == false) &&
                   (naiKasKostenurskiPat[doOstrovche] >
                        naiKasKostenurskiPat[doKoeOstrovcheENaiMalkoto] + razst))
                {
                    naiKasKostenurskiPat[doOstrovche] =
                        naiKasKostenurskiPat[doKoeOstrovcheENaiMalkoto] + razst;

                    //cout<<2<<endl;
                    kostenurskiRoditel[doOstrovche] = doKoeOstrovcheENaiMalkoto;
                }
            }

        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOstrovcheta;
    cin>>broiPatechki;

    for(int i = 0; i < broiPatechki; i++){
        int otOst;
        int doOst;
        long long razst;
        int vid;

        cin>>otOst>>doOst>>razst>>vid;

        Danni zaDobKamOTkostenurka = {doOst, razst*2};
        Danni zaDobKamDOkostenurka = {otOst, razst*2};

        kostenurskoSasedstvo[otOst].push_back(zaDobKamOTkostenurka);
        kostenurskoSasedstvo[doOst].push_back(zaDobKamDOkostenurka);

        if(vid == 1){
            Danni otZaikovci = {doOst, razst};
            Danni doZaikovci = {otOst, razst};

            zaeshkoSasedstvo[otOst].push_back(otZaikovci);
            zaeshkoSasedstvo[doOst].push_back(doZaikovci);
        }

    }

    cin>>start>>finish;

    zaeshkaDijkstra();
    kostenurskaDijkstra();

    for(int i = finish; i != start; i = zaeshkiRoditel[i]){
        minavaLiOtTukZaicheto[i] = true;
    }

    for(int i = finish; i != start; i = kostenurskiRoditel[i]){
        minavaLiOtTukKostenurcheto[i] = true;
    }

    //cout<<"rdiadaad"<<endl;

    int broiZasichaniq = 0;

    for(int i = 1; i <= broiOstrovcheta; i++){
        if(minavaLiOtTukKostenurcheto[i] && minavaLiOtTukZaicheto[i]){
            if(naiKasZaehkiPat[i] == naiKasKostenurskiPat[i]){
                broiZasichaniq++;
            }
        }
    }

    long long zaeshkokasoVreme = naiKasZaehkiPat[finish];
    long long kostenurskoVreme = naiKasKostenurskiPat[finish];

    if(zaeshkokasoVreme < kostenurskoVreme){
        cout<<"Rabbit"<<endl;
        cout<<zaeshkokasoVreme<<endl;
    }else{
        cout<<"Tortoise"<<endl;
        cout<<kostenurskoVreme<<endl;
    }

    cout<<broiZasichaniq<<endl;

    return 0;
}
