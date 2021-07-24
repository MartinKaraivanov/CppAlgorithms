#include<iostream>
using namespace std;

int chislotoZaZamestvane;
int priDelenieNaKolko;
int zaPribEdno;
int zaPribDve;
int ostatakZaPoluch;

int main(){
    cin>>chislotoZaZamestvane>>priDelenieNaKolko>>zaPribEdno>>zaPribDve>>ostatakZaPoluch;

    int naKolkoDaER = (priDelenieNaKolko + ostatakZaPoluch - (chislotoZaZamestvane % priDelenieNaKolko)) % priDelenieNaKolko;

    //cout<<naKolkoDaER<<endl;

    for(int s = 1; s <= 1000; s++){
        for(int x = 0; x <= s; x++){
            int y = s - x;

            if(((x*zaPribEdno)% priDelenieNaKolko) + ((y*zaPribDve)%priDelenieNaKolko) == naKolkoDaER)
            {
                cout<<s<<endl;
                return 0;
            }
        }
    }

    cout<<-1<<endl;

    return 0;
}
