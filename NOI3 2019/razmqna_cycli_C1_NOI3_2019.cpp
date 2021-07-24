#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


const int cmaxSbor = 10000;

int suma;
int broiMonetki;
int monetki[150];
int priTolkova[cmaxSbor][100];

void minBroiMonetkiZaTaziSuma(int sborche, int maksimalnoNomercheMoneta){
    /// granichen sluchai : kogato sbora e 0 e 0

    for(int sbor = 1; sbor < cmaxSbor; sbor++){
        if((sbor % monetki[0]) != 0){
            priTolkova[sbor][0] = -1;
        }else{
            priTolkova[sbor][0] = sbor / monetki[0];
        }
    }


    for(int maksNomerMoneta = 1; maksNomerMoneta <= maksimalnoNomercheMoneta; maksNomerMoneta++){
        for(int sbor = 1 ; sbor < cmaxSbor; sbor++){
            int naiDobro = 20000000;
            bool namerilililsme = false;

            int maksBroiEdnakvi = min(min(cmaxSbor/monetki[maksNomerMoneta], sbor), sborche);

            for(int broiPuti = -maksBroiEdnakvi; broiPuti <= maksBroiEdnakvi; broiPuti++){
                if(abs(sbor - broiPuti * monetki[maksNomerMoneta]) < cmaxSbor){
                    int p = priTolkova[abs(sbor - broiPuti * monetki[maksNomerMoneta])][maksNomerMoneta - 1];

                    if(p != -1){
                        int eventualno = abs(broiPuti) + p;

                        if(eventualno < naiDobro){
                            naiDobro = eventualno;
                            namerilililsme = true;
                        }
                    }
                }
            }

            if(namerilililsme == true){
                priTolkova[sbor][maksNomerMoneta] = naiDobro;
            }else{
                priTolkova[sbor][maksBroiEdnakvi] = -1;
            }

        }
    }

}

bool poMalkoLie(int a, int b){
    return a < b;
}

int main(){
    cin>>suma>>broiMonetki;

    for(int i = 0; i < broiMonetki; i++){
        cin>>monetki[i];
    }

    //sort(monetki, monetki + broiMonetki, poMalkoLie);

    minBroiMonetkiZaTaziSuma(suma, broiMonetki - 1);

    int naiMBroiMon = priTolkova[suma][broiMonetki - 1];

    cout<<naiMBroiMon<<endl;

    return 0;
}
