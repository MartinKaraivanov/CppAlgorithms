#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct PlochkiIRazlika{
    int doPlochka;
    long long razl;
};

int broiPlochkiV1Kolonka;
int broiKolonki;
long long visochiniPoKolonki[1010][1010];

int nomercheNaPlochkata[1010][1010];

int broiPlochki;
vector<PlochkiIRazlika> sasedstvo[1000010];

long long naiBezopasenPat[1000010];
bool imameLiNaiBezopasenPat[1000010];

int start;
int finish;

const long long mnogoGoliaoChislo = 1000000000000000;


void dijkstra(){
    for(int i=1;i<broiPlochki;i++){
        naiBezopasenPat[i] = mnogoGoliaoChislo;
    }

    for(int i = 0; i < sasedstvo[start].size(); i++){
        naiBezopasenPat[sasedstvo[start][i].doPlochka] = sasedstvo[start][i].razl;
    }

    bool nameriliLiSmeNeshto=true;
    while(nameriliLiSmeNeshto==true){
        nameriliLiSmeNeshto=false;

        long long naiMalko = mnogoGoliaoChislo;
        int naKoqPlochkaENaiMalkoto;
        for(int prezPlochka=1;prezPlochka<broiPlochki;prezPlochka++){
            if((naiBezopasenPat[prezPlochka]<naiMalko) &&
               (imameLiNaiBezopasenPat[prezPlochka]==false))
            {
                naiMalko=naiBezopasenPat[prezPlochka];
                naKoqPlochkaENaiMalkoto=prezPlochka;
                nameriliLiSmeNeshto=true;
            }
        }

        if(nameriliLiSmeNeshto==true){
            imameLiNaiBezopasenPat[naKoqPlochkaENaiMalkoto]=true;

            if (naKoqPlochkaENaiMalkoto == finish){  ////// niama nujda da prodaljavame
                break;
            }

            for(int j=0;j<sasedstvo[naKoqPlochkaENaiMalkoto].size();j++){
                int krainaPlochka = sasedstvo[naKoqPlochkaENaiMalkoto][j].doPlochka;
                if((imameLiNaiBezopasenPat[krainaPlochka]==false) &&
                (naiBezopasenPat[krainaPlochka] >
                    naiBezopasenPat[naKoqPlochkaENaiMalkoto]+sasedstvo[naKoqPlochkaENaiMalkoto][j].razl))
                {
                    naiBezopasenPat[krainaPlochka]=
                        naiBezopasenPat[naKoqPlochkaENaiMalkoto]+sasedstvo[naKoqPlochkaENaiMalkoto][j].razl;
                }
            }
        }
    }
}

void dobavqne(int otK, int doK, long long razs){
    PlochkiIRazlika z = {doK, abs(razs)};
    sasedstvo[otK].push_back(z);
}

void dobavqne2(int otK, int doK, long long razs){
    dobavqne(otK, doK, razs);
    dobavqne(doK, otK, razs);
}


int main(){
    cin>>broiPlochkiV1Kolonka>>broiKolonki;

    broiPlochki = 0;

    start = 0;
    broiPlochki++;

    for(int i = 0; i < broiKolonki; i++){
        if(i % 2 == 0){
            for(int j = 0; j < broiPlochkiV1Kolonka; j++){
                int visochinaNaPlochka;
                cin>>visochinaNaPlochka;
                visochiniPoKolonki[i][j] = visochinaNaPlochka;
                nomercheNaPlochkata[i][j] = broiPlochki;
                broiPlochki++;
            }
        }else{
            for(int j = 0; j <= broiPlochkiV1Kolonka; j++){
                int visochinaNaPlochka;
                cin>>visochinaNaPlochka;
                visochiniPoKolonki[i][j] = visochinaNaPlochka;
                nomercheNaPlochkata[i][j] = broiPlochki;
                broiPlochki++;
            }
        }
    }

    finish = broiPlochki;
    broiPlochki++;

    for(int i = 0; i < broiKolonki; i++){
        dobavqne(0, nomercheNaPlochkata[i][0], abs(visochiniPoKolonki[i][0]));
    }

    for(int i = 0; i < broiKolonki; i++){
        if(i % 2 == 0){
            dobavqne(nomercheNaPlochkata[i][broiPlochkiV1Kolonka-1],finish, abs(visochiniPoKolonki[i][broiPlochkiV1Kolonka - 1]));
        }else{
            dobavqne(nomercheNaPlochkata[i][broiPlochkiV1Kolonka],finish, abs(visochiniPoKolonki[i][broiPlochkiV1Kolonka]));
        }
    }

    for(int i = 0; i < broiKolonki; i++){
        if(i % 2 ==0){
            for(int j = 0; j < broiPlochkiV1Kolonka; j++){
                if(j != broiPlochkiV1Kolonka - 1){
                    dobavqne2(nomercheNaPlochkata[i][j],nomercheNaPlochkata[i][j+1],
                            abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i][j+1]));
                }
                if(i != 0){
                    dobavqne2(nomercheNaPlochkata[i][j],nomercheNaPlochkata[i-1][j+1],
                            abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i-1][j+1]));
                }
                if(i != broiKolonki - 1){
                    dobavqne2(nomercheNaPlochkata[i][j],nomercheNaPlochkata[i+1][j+1],
                             abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i+1][j+1]));
                }
            }
        }else{
            for(int j = 0; j <= broiPlochkiV1Kolonka; j++){
                if(j != broiPlochkiV1Kolonka){
                    dobavqne2(nomercheNaPlochkata[i][j],nomercheNaPlochkata[i][j+1],
                             abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i][j+1]));
                }
                if((i != 0) && (j != broiPlochkiV1Kolonka)){
                    dobavqne2(nomercheNaPlochkata[i][j],nomercheNaPlochkata[i-1][j],
                             abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i-1][j]));
                }
                if((i != broiKolonki - 1) && (j != broiPlochkiV1Kolonka)){
                    dobavqne2(nomercheNaPlochkata[i][j],nomercheNaPlochkata[i+1][j],
                             abs(visochiniPoKolonki[i][j] - visochiniPoKolonki[i+1][j]));
                }
            }
        }
    }

    /*
    cout<<endl;
    for (int i = 0; i<broiPlochki; i++)
    {
        cout<<i<<" -> ";
        for (int j = 0; j<sasedstvo[i].size(); j++)
        {
            cout<< sasedstvo[i][j].doPlochka << " ";
        }

        cout<<endl;
    }

    */

    dijkstra();

    long long otgovor = naiBezopasenPat[finish];

    cout<<otgovor<<endl;

    return 0;
}
