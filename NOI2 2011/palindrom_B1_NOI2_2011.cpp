#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct DanniZaKasaneto{
    short int broiParcheta;
    short int nachaloNaPoslednoParche;
};

short int broiChisla;
char redichka[10010];

vector<short int> otKadeDoTukImaParche[10010];

void pravene(){
    for(short int i = 0; i < broiChisla; i++){
        short int otDalechenie = 1;

        while(i - otDalechenie >= 0 && i+otDalechenie<broiChisla && redichka[i + otDalechenie] == redichka[i - otDalechenie]){
            otKadeDoTukImaParche[i + otDalechenie].push_back(i - otDalechenie);
            //cout<<"Tuko shto slozhih do "<<i + otDalechenie<<" se stiga ot "<<i - otDalechenie<<endl;
            otDalechenie++;
        }

        otDalechenie = 0;
        while(i - otDalechenie>=0 && i+otDalechenie+1<broiChisla && redichka[i+otDalechenie+1] == redichka[i-otDalechenie]){
            otKadeDoTukImaParche[i + otDalechenie + 1].push_back(i - otDalechenie);
            //cout<<"Tuko shto slozhih do "<<i + otDalechenie + 1<<" da se stiga ot "<<i - otDalechenie<<endl;
            otDalechenie++;
        }
    }
}

DanniZaKasaneto priTolkova[10010];

/// dava na kolko naj-malko parcheta moje da se razdeliat pyrvite broiElementi ot masiva
DanniZaKasaneto naKolkoParchetaShteSeRazdeli(short int broiElementi){

    if(broiElementi == 0){
        return {0, -1};
    }

    if(priTolkova[broiElementi].broiParcheta > -1){
        return priTolkova[broiElementi];
    }

    short int kadeENaiMalkoto = -1;
    short int naiMalkoto = 1 + naKolkoParchetaShteSeRazdeli(broiElementi - 1).broiParcheta;
    kadeENaiMalkoto = broiElementi - 1;

    for(unsigned short int i = 0; i < otKadeDoTukImaParche[broiElementi - 1].size(); i++){
        short int priTakova = 1 + naKolkoParchetaShteSeRazdeli(otKadeDoTukImaParche[broiElementi - 1][i]).broiParcheta;
        /// broia elementi naliavo ot edin indeks e raven na samiq indeks

        if(priTakova < naiMalkoto){
            naiMalkoto = priTakova;
            kadeENaiMalkoto = otKadeDoTukImaParche[broiElementi - 1][i];
        }
    }

    DanniZaKasaneto zaVrasht = {naiMalkoto, kadeENaiMalkoto};

    priTolkova[broiElementi] = zaVrasht;
    return zaVrasht;
}

int main(){
    cin>>broiChisla;

    for(short int i = 0; i < broiChisla; i++){
        cin>>redichka[i];
    }

    pravene();

    for(short int i = 0; i <= broiChisla; i++){
        priTolkova[i].broiParcheta = -1;
        priTolkova[i].nachaloNaPoslednoParche = -1;
    }

    DanniZaKasaneto varnato = naKolkoParchetaShteSeRazdeli(broiChisla);

    cout<<varnato.broiParcheta<<endl;

    short int segashenElelemt = varnato.nachaloNaPoslednoParche;

    stack<short int> s;

    while(segashenElelemt > 0){
        s.push(segashenElelemt);
        segashenElelemt = naKolkoParchetaShteSeRazdeli(segashenElelemt).nachaloNaPoslednoParche;
        /// broia elementi naliavo ot edin indeks e raven na samiq indeks
    }

    while(s.empty() == false){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
