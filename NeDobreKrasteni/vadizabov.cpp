#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaPacient{
    int MomentNaIdvane;
    int VremeZaPregled;
    int MomentNaPriemane;
    int MomentNaIzlizane;
};

bool poGolqmoLiE(DanniZaPacient a, DanniZaPacient b){
    return a.MomentNaIdvane<b.MomentNaIdvane;
}


int main(){
    long long izminaloVreme;
    long long vremeZaPacienta;
    long long broi=0;
    DanniZaPacient pacienti[10000];

    while(cin>>izminaloVreme){
        cin>>vremeZaPacienta;
        pacienti[broi].MomentNaIdvane = izminaloVreme;
        pacienti[broi].VremeZaPregled = vremeZaPacienta;
        pacienti[broi].MomentNaPriemane = 0;
        pacienti[broi].MomentNaIzlizane = 0;
        broi++;
    }


    sort(pacienti,pacienti+broi,poGolqmoLiE);

    /*for(int i=0;i<broi;i++){
        cout<<pacienti[i].MomentNaIdvane<<" "<<pacienti[i].VremeZaPregled<<endl;
    }*/

    /*if(pacienti[broi-1].MomentNaIdvane-pacienti[broi].MomentNaIdvane>pacienti[broi-1].VremeZaPregled){
        cout<<pacienti[broi].VremeZaPregled;
    }*/

    int momentNaIzlizaneNaPredniq = 0;
    for(int i=0;i<broi;i++){
        if(pacienti[i].MomentNaIdvane>momentNaIzlizaneNaPredniq){
            pacienti[i].MomentNaPriemane=pacienti[i].MomentNaIdvane;
            pacienti[i].MomentNaIzlizane=pacienti[i].MomentNaPriemane+pacienti[i].VremeZaPregled;
        }else{
            pacienti[i].MomentNaPriemane=momentNaIzlizaneNaPredniq;
            pacienti[i].MomentNaIzlizane=pacienti[i].MomentNaPriemane+pacienti[i].VremeZaPregled;
        }

        momentNaIzlizaneNaPredniq = pacienti[i].MomentNaIzlizane;
    }
    cout<<pacienti[broi-1].MomentNaIzlizane-pacienti[broi-1].MomentNaIdvane;

    return 0;
}
