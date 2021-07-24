#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


const int cmaxSbor = 10000;

int suma;
int broiMonetki;
int monetki[150];
int priTolkova[cmaxSbor][100];

int minBroiMonetkiZaTaziSuma(int sbor, int maksNomerMoneta){
    if(sbor < 0){
        return minBroiMonetkiZaTaziSuma(-sbor, maksNomerMoneta);
    }

    if(sbor == 0){
        ///cout<<"kraen sluchai"<<endl;
        return 0;
    }

    if(sbor >= cmaxSbor){
        return 200000;
    }

    if(maksNomerMoneta < 0){
        return 200000;
    }

    if(maksNomerMoneta == 0){
        if ((sbor % monetki[0]) == 0)
            return sbor / monetki[0];
        else
            return 200000;
    }

    if(priTolkova[sbor][maksNomerMoneta] > 0){
        return priTolkova[sbor][maksNomerMoneta];
    }

    int naiDobro = 100000;

    int maksBroiEdnakvi = min(min(cmaxSbor/monetki[maksNomerMoneta], sbor), suma);

    for(int broiPuti = -maksBroiEdnakvi; broiPuti <= maksBroiEdnakvi; broiPuti++){
        int eventualno =
            abs(broiPuti) +
            minBroiMonetkiZaTaziSuma(sbor - broiPuti * monetki[maksNomerMoneta], maksNomerMoneta - 1);

        if(eventualno < naiDobro){
            naiDobro = eventualno;
        }
    }

    priTolkova[sbor][maksNomerMoneta] = naiDobro;
    return naiDobro;
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

    int naiMBroiMon = minBroiMonetkiZaTaziSuma(suma, broiMonetki - 1);

    cout<<naiMBroiMon<<endl;

    return 0;
}
