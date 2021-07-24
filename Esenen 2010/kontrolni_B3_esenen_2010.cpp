#include<iostream>
#include<algorithm>
using namespace std;

int broiKontrolni;
long long tochkiZaPravene;

long long tochkiOtKontrolni[40];

long long broiTochkiDoTuk[40];

long long broiVazmozhnostiZaVzemane(int naKoeKontrolnoSme, long long broiTochkiZaPravene){
    if(naKoeKontrolnoSme == 0){
        if(broiTochkiZaPravene <= 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(broiTochkiZaPravene <= 0){
        return (long long)1 << naKoeKontrolnoSme;
    }

    if(broiTochkiDoTuk[naKoeKontrolnoSme] < broiTochkiZaPravene){
        return 0;
    }

    long long zaTuk = broiVazmozhnostiZaVzemane(naKoeKontrolnoSme - 1, broiTochkiZaPravene);

    zaTuk += broiVazmozhnostiZaVzemane(naKoeKontrolnoSme - 1, broiTochkiZaPravene - tochkiOtKontrolni[naKoeKontrolnoSme]);

    return zaTuk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiKontrolni>>tochkiZaPravene;

    for(int i = 1; i <= broiKontrolni; i++){
        cin>>tochkiOtKontrolni[i];
    }

    sort(tochkiOtKontrolni, tochkiOtKontrolni + broiKontrolni);

    for(int i = 1; i <= broiKontrolni; i++){
        broiTochkiDoTuk[i] = broiTochkiDoTuk[i - 1] + tochkiOtKontrolni[i];
    }

    long long broiNachiniZaVzimane = broiVazmozhnostiZaVzemane(broiKontrolni, tochkiZaPravene);

    cout<<broiNachiniZaVzimane<<endl;

    return 0;
}
