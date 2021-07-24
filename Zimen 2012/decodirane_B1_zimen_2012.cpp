#include<iostream>
using namespace std;

string zakodirano;

unsigned long long cifri[100];

unsigned long long priTolkova[100];

unsigned long long broiZakodirvaniqSPoslednaCifra(unsigned long long poslednaCifra){
    if(poslednaCifra == 0 || poslednaCifra == 1){
        return 1;
    }

    if(priTolkova[poslednaCifra] > 0){
        return priTolkova[poslednaCifra];
    }

    unsigned long long akoESamostoqtelen = 0;

    if(cifri[poslednaCifra] != 0){
        akoESamostoqtelen = 1 * broiZakodirvaniqSPoslednaCifra(poslednaCifra - 1);
    }

    unsigned long long akoEVtori = 0;

    if(10*cifri[poslednaCifra - 1] + cifri[poslednaCifra] <= 26 && cifri[poslednaCifra- 1] != 0){
        akoEVtori = 1 * broiZakodirvaniqSPoslednaCifra(poslednaCifra - 2);
    }

    unsigned long long broiZaTozi = akoESamostoqtelen + akoEVtori;

    priTolkova[poslednaCifra] = broiZaTozi;
    return broiZaTozi;
}

int main(){
    cin>>zakodirano;

    for(unsigned long long i = 1; i <= zakodirano.size(); i++){
        if(zakodirano[i - 1] == '0' && cifri[i - 1] == 0){
            cout<<0<<endl;
            return 0;
        }
        cifri[i] = zakodirano[i - 1] - '0';
    }

    unsigned long long broiVazmozhniZakodirvaniq = broiZakodirvaniqSPoslednaCifra(zakodirano.size());

    cout<<broiVazmozhniZakodirvaniq<<endl;

    return 0;
}
