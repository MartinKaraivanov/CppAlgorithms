#include<iostream>
using namespace std;

struct DanniZaUchenika{
    int tqlo;
    int ruce;
};

int broiUchenici;
int visochinaNaTrapa;

DanniZaUchenika uchenici[2010];

int priTolkova[2010][100010];

int broiIzlezliUchenici(int naKoiSme, int visochinaNaKulata){
    //cout<<naKoiSme<<" "<<visochinaNaKulata<<endl;
    if(naKoiSme == 0){
        return 0;
    }

    if(priTolkova[naKoiSme][visochinaNaKulata] > -1){
        return priTolkova[naKoiSme][visochinaNaKulata];
    }

    int akoGoVzemem = 0;
    int akoNeoVzemem = 0;

    if(visochinaNaKulata + uchenici[naKoiSme].ruce >= visochinaNaTrapa){
        akoGoVzemem = 1 + broiIzlezliUchenici(naKoiSme - 1, visochinaNaKulata - uchenici[naKoiSme].tqlo);
    }

    akoNeoVzemem = broiIzlezliUchenici(naKoiSme - 1, visochinaNaKulata);

    int zaTuk = max(akoGoVzemem, akoNeoVzemem);

    priTolkova[naKoiSme][visochinaNaKulata] = zaTuk;
    return zaTuk;
}

int main(){
    cin>>broiUchenici;

    for(int i = 1; i <= broiUchenici; i++){
        cin>>uchenici[i].tqlo>>uchenici[i].ruce;
    }

    cin>>visochinaNaTrapa;

    int visochinaNaVsichkiZaedno = 0;

    for(int i = 1; i <= broiUchenici; i++){
        visochinaNaVsichkiZaedno += uchenici[i].tqlo;
    }

    for(int i = 0; i <= broiUchenici; i++){
        for(int j = 0; j <= visochinaNaVsichkiZaedno; j++){
            priTolkova[i][j] = -1;
        }
    }

    int naiDoburBroiUcheniciIzlezli = broiIzlezliUchenici(broiUchenici, visochinaNaVsichkiZaedno);

    cout<<naiDoburBroiUcheniciIzlezli<<endl;

    return 0;
}
