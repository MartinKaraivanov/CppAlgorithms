#include<iostream>
using namespace std;

const int modul = 30011;

int daljinaEkran;
int broiOtpecTam[2048];
int daljinaPin;

int poKolkoNachPrednoLqvo(int kolkoSimvola, int koqKolona);
int poKolkoNachPrednoDqsno(int kolkoSimvola, int koqKolona);

int priTolkovaPDqsno[2][2010];
int priTolkovaPLqvo[2][2010];

/*
int poKolkoNachPrednoDqsno(int kolkoSimvola, int koqKolona){
    if(kolkoSimvola == 1){
        return broiOtpecTam[koqKolona];
        //return 1;
    }

    if(priTolkovaPDqsno[kolkoSimvola][koqKolona] > 0){
        return priTolkovaPDqsno[kolkoSimvola][koqKolona];
    }

    int zaTuka = 0;

    for(int i = 0; i < koqKolona; i++){
        zaTuka = (zaTuka + poKolkoNachPrednoLqvo(kolkoSimvola - 1, i))%modul;
    }

    zaTuka = (zaTuka * broiOtpecTam[koqKolona])%modul;

    priTolkovaPDqsno[kolkoSimvola][koqKolona] = zaTuka;
    return zaTuka;
}

int poKolkoNachPrednoLqvo(int kolkoSimvola, int koqKolona){
    if(kolkoSimvola == 1){
        return broiOtpecTam[koqKolona];
        //return 1;
    }

    if(priTolkovaPLqvo[kolkoSimvola][koqKolona] > 0){
        return priTolkovaPLqvo[kolkoSimvola][koqKolona];
    }

    int zaTuka = 0;

    for(int i = koqKolona + 1; i < daljinaEkran; i++){
        zaTuka = (zaTuka + poKolkoNachPrednoDqsno(kolkoSimvola - 1, i))%modul;
    }

    zaTuka = (zaTuka * broiOtpecTam[koqKolona])%modul;

    priTolkovaPLqvo[kolkoSimvola][koqKolona] = zaTuka;
    return zaTuka;
}
*/

void sCikli(int zaKolkoSimvola, int zaKoqKolona){
    for(int i = 0; i <= zaKoqKolona; i++){
        priTolkovaPDqsno[1%2][i] = broiOtpecTam[i];
        priTolkovaPLqvo[1%2][i] = broiOtpecTam[i];
    }

    for(int kolkoSimvola = 2; kolkoSimvola <= zaKolkoSimvola; kolkoSimvola++){

        int sumaDqsno = 0;
        int sumaLqvo = 0;

        for(int i = 0; i <= zaKoqKolona; i++){
            sumaLqvo = (sumaLqvo + priTolkovaPDqsno[(kolkoSimvola - 1)%2][i])%modul;
        }

        for(int koqKolona = 0; koqKolona <= zaKoqKolona; koqKolona++){

            /*for(int i = 0; i < koqKolona; i++){
                zaTukaDqsno = (zaTukaDqsno + priTolkovaPLqvo[(kolkoSimvola - 1)%2][i])%modul;
            }*/

            int zaTukaDqsno = sumaDqsno;

            zaTukaDqsno = (zaTukaDqsno * broiOtpecTam[koqKolona])%modul;

            sumaDqsno = (sumaDqsno + priTolkovaPLqvo[(kolkoSimvola - 1)%2][koqKolona])%modul;

            //int zaTukaLqvo = 0;

            /*for(int i = koqKolona + 1; i < daljinaEkran; i++){
                zaTukaLqvo = (zaTukaLqvo + priTolkovaPDqsno[(kolkoSimvola - 1)%2][i])%modul;
            }*/

            sumaLqvo = (sumaLqvo + modul - priTolkovaPDqsno[(kolkoSimvola - 1)%2][koqKolona])%modul;

            int zaTukaLqvo = sumaLqvo;

            zaTukaLqvo = (zaTukaLqvo * broiOtpecTam[koqKolona])%modul;

            priTolkovaPDqsno[kolkoSimvola%2][koqKolona] = zaTukaDqsno;
            priTolkovaPLqvo[kolkoSimvola%2][koqKolona] = zaTukaLqvo;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>daljinaEkran;

    for(int y = 0; y < daljinaEkran; y++){
        string toziRed;
        cin>>toziRed;
        for(int x = 0; x < daljinaEkran; x++){
            int tuka = toziRed[x] - '0';
            broiOtpecTam[x] += tuka;
        }
    }

    cin>>daljinaPin;

    sCikli(daljinaPin, daljinaEkran - 1);

    int otgovor = 0;

    for(int i = 0; i < daljinaEkran; i++){
        //otgovor = (otgovor + poKolkoNachPrednoDqsno(daljinaPin, i))%modul;
        //otgovor = (otgovor + poKolkoNachPrednoLqvo(daljinaPin, i))%modul;
        otgovor = (otgovor + priTolkovaPDqsno[daljinaPin%2][i])%modul;
        otgovor = (otgovor + priTolkovaPLqvo[daljinaPin%2][i])%modul;
    }

    if(daljinaPin > 1){
        cout<<otgovor<<endl;
    }else{
        cout<<otgovor/2<<endl;
    }

    //cout<<"lqvoto: "<<poKolkoNachPrednoDqsno(daljinaPin - 1, 0)<<" dqsnoto: "<<poKolkoNachPrednoLqvo(daljinaPin - 1, 0)<<endl;

    return 0;
}
