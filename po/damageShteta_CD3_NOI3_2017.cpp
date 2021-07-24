#include<iostream>
#include<cmath>
using namespace std;

int broiPlochkiV1Kolonka;
int broiKolonki;
long long visochiniPoKolonki[1500][1500];

int broiPlochki;
int nomercheNaPlochkata[1500][1500];

long long sasedstvo[1500][1500];
long long naiBezopasenPat[1500][1500];
bool imameLiNaiBezopasenPat[1500][1500];

int start;
int finish;

const long long mnogoGoliaoChislo = 1000000000000000;


void dijkstra(){
    for(int i=1;i<=broiPlochki;i++){
        if(i!=start){
            if(sasedstvo[start][i]>-1){
                naiBezopasenPat[start][i]=sasedstvo[start][i];
            }else{
                naiBezopasenPat[start][i]=mnogoGoliaoChislo;
            }
        }else{
            naiBezopasenPat[start][i]=0;
        }
    }

    bool nameriliLiSmeNeshto=true;
    while(nameriliLiSmeNeshto==true){
        nameriliLiSmeNeshto=false;

        long long naiMalko = mnogoGoliaoChislo;
        int naKoqPlochkaENaiMalkoto;
        for(int prezPlochka=1;prezPlochka<=broiPlochki;prezPlochka++){
            if((naiBezopasenPat[start][prezPlochka]<naiMalko) &&
               (imameLiNaiBezopasenPat[start][prezPlochka]==false))
            {
                naiMalko=naiBezopasenPat[start][prezPlochka];
                naKoqPlochkaENaiMalkoto=prezPlochka;
                nameriliLiSmeNeshto=true;
            }
        }

        if(nameriliLiSmeNeshto==true){
            imameLiNaiBezopasenPat[start][naKoqPlochkaENaiMalkoto]=true;

            for(int krainaPlochka=1;krainaPlochka<=broiPlochki;krainaPlochka++){
                if((imameLiNaiBezopasenPat[start][krainaPlochka]==false) &&
                    (sasedstvo[naKoqPlochkaENaiMalkoto][krainaPlochka]>-1) &&
                    (naiBezopasenPat[start][krainaPlochka] >
                        naiBezopasenPat[start][naKoqPlochkaENaiMalkoto]+sasedstvo[naKoqPlochkaENaiMalkoto][krainaPlochka]))
                {
                    naiBezopasenPat[start][krainaPlochka]=
                        naiBezopasenPat[start][naKoqPlochkaENaiMalkoto]+sasedstvo[naKoqPlochkaENaiMalkoto][krainaPlochka];
                }
            }
        }
    }
}

int main(){
    cin>>broiPlochkiV1Kolonka>>broiKolonki;

    for(int i = 0; i < broiKolonki; i++){
        if(i % 2 == 0){
            for(int j = 0; j < broiPlochkiV1Kolonka; j++){
                int visochinaNaPlochka;
                cin>>visochinaNaPlochka;
                visochiniPoKolonki[i][j] = visochinaNaPlochka;
                broiPlochki++;broiPlochki;
                nomercheNaPlochkata[i][j] = broiPlochki;
            }
        }else{
            for(int j = 0; j <= broiPlochkiV1Kolonka; j++){
                int visochinaNaPlochka;
                cin>>visochinaNaPlochka;
                visochiniPoKolonki[i][j] = visochinaNaPlochka;
                broiPlochki++;
                nomercheNaPlochkata[i][j] = broiPlochki;
            }
        }
    }

    broiPlochki++;
    finish = broiPlochki;

    for(int i = 0; i <= broiPlochki; i++){
        for(int j = 0; j <= broiPlochki; j++){
            sasedstvo[i][j] = -1;
        }
    }

    for(int i = 0; i < broiKolonki; i++){
        sasedstvo[0][nomercheNaPlochkata[i][0]] = visochiniPoKolonki[i][0];
    }

    for(int i = 0; i < broiKolonki; i++){
        if(i % 2 == 0){
            sasedstvo[nomercheNaPlochkata[i][broiPlochkiV1Kolonka - 1]][finish] =
                abs(visochiniPoKolonki[i][broiPlochkiV1Kolonka - 1]);
        }else{
            sasedstvo[nomercheNaPlochkata[i][broiPlochkiV1Kolonka]][finish] = abs(visochiniPoKolonki[i][broiPlochkiV1Kolonka]);
        }
    }

    for(int i = 0; i < broiKolonki; i++){
        if(i % 2 ==0){
            for(int j = 0; j < broiPlochkiV1Kolonka; j++){
                if(j != broiPlochkiV1Kolonka - 1){
                    sasedstvo[nomercheNaPlochkata[i][j]][nomercheNaPlochkata[i][j+1]] =
                        abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i][j+1]);
                }
                if(i != 0){
                    sasedstvo[nomercheNaPlochkata[i][j]][nomercheNaPlochkata[i - 1][j + 1]] =
                        abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i - 1][j + 1]);
                }
                if(i != broiKolonki - 1){
                    sasedstvo[nomercheNaPlochkata[i][j]][nomercheNaPlochkata[i + 1][j + 1]] =
                        abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i + 1][j + 1]);
                }
            }
        }else{
            for(int j = 0; j <= broiPlochkiV1Kolonka; j++){
                if(j != broiPlochkiV1Kolonka){
                    sasedstvo[nomercheNaPlochkata[i][j]][nomercheNaPlochkata[i][j+1]] =
                        abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i][j+1]);
                }
                if((i != 0) && (j != broiPlochkiV1Kolonka)){
                    sasedstvo[nomercheNaPlochkata[i][j]][nomercheNaPlochkata[i - 1][j]] =
                        abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i - 1][j]);
                }
                if((i != broiKolonki - 1) && (j != broiPlochkiV1Kolonka)){
                    sasedstvo[nomercheNaPlochkata[i][j]][nomercheNaPlochkata[i + 1][j]] =
                        abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i + 1][j]);
                }
            }
        }
    }

    dijkstra();

    long long otgovor = naiBezopasenPat[start][finish];

    cout<<otgovor<<endl;

    return 0;
}
