#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int broiKvadratchetaStr;
int broiNachalniCherni;
int broiZaqvki;
int parviteKolkoCherni;

struct Koordinati{
    int y;
    int x;

    bool operator==(const Koordinati &a) const
    {
        return y == a.y && x == a.x;
    }

    bool operator<(const Koordinati &a) const
    {
        if(y < a.y){
            return true;
        }
        if(y > a.y){
            return false;
        }
        return x < a.x;
    }
};

set<Koordinati> cherniTochki;
set<Koordinati> cherniTochkiMatr;

bool koqEPoNapred(Koordinati a, Koordinati b){
    if(a.y < b.y){
        return true;
    }
    if(a.y > b.y){
        return false;
    }
    return a.x < b.x;
}

/// 1- R; 2- L; 3- Q; 4- H; 5-V; 6- RH/LV; 7- RV/LH

int daiNovoSastoqnie(int sastoqnie, char novaOperaciq){
    if(sastoqnie == 0){
        if(novaOperaciq == 'R'){
            return 1;
        }
        if(novaOperaciq == 'L'){
            return 2;
        }
        if(novaOperaciq == 'Q'){
            return 3;
        }
        if(novaOperaciq == 'H'){
            return 4;
        }
        return 5; /// V
    }
    if(sastoqnie == 1){
        if(novaOperaciq == 'R'){
            return 3;
        }
        if(novaOperaciq == 'L'){
            return 0;
        }
        if(novaOperaciq == 'Q'){
            return 2;
        }
        if(novaOperaciq == 'H'){
            return 6;
        }
        return 7; /// V
    }
    if(sastoqnie == 2){
        if(novaOperaciq == 'R'){
            return 0;
        }
        if(novaOperaciq == 'L'){
            return 3;
        }
        if(novaOperaciq == 'Q'){
            return 1;
        }
        if(novaOperaciq == 'H'){
            return 7;
        }
        return 6; /// V
    }
    if(sastoqnie == 3){
        if(novaOperaciq == 'R'){
            return 2;
        }
        if(novaOperaciq == 'L'){
            return 1;
        }
        if(novaOperaciq == 'Q'){
            return 0;
        }
        if(novaOperaciq == 'H'){
            return 5;
        }
        return 4; /// V
    }
    if(sastoqnie == 4){
        if(novaOperaciq == 'R'){
            return 7;
        }
        if(novaOperaciq == 'L'){
            return 6;
        }
        if(novaOperaciq == 'Q'){
            return 5;
        }
        if(novaOperaciq == 'H'){
            return 0;
        }
        return 3; /// V
    }
    if(sastoqnie == 5){
        if(novaOperaciq == 'R'){
            return 6;
        }
        if(novaOperaciq == 'L'){
            return 7;
        }
        if(novaOperaciq == 'Q'){
            return 4;
        }
        if(novaOperaciq == 'H'){
            return 3;
        }
        return 0; /// V
    }
    if(sastoqnie == 6){
        if(novaOperaciq == 'R'){
            return 4;
        }
        if(novaOperaciq == 'L'){
            return 5;
        }
        if(novaOperaciq == 'Q'){
            return 7;
        }
        if(novaOperaciq == 'H'){
            return 1;
        }
        return 2; /// V
    }
    if(sastoqnie == 7){
        if(novaOperaciq == 'R'){
            return 5;
        }
        if(novaOperaciq == 'L'){
            return 4;
        }
        if(novaOperaciq == 'Q'){
            return 6;
        }
        if(novaOperaciq == 'H'){
            return 2;
        }
        return 1; /// V
    }

    return -1;
}

Koordinati originalniKoordinati(Koordinati segashniKoord, int sastoqnie){
    if(sastoqnie == 0){
        return segashniKoord;
    }
    if(sastoqnie == 1){
        return {broiKvadratchetaStr+1 - segashniKoord.x, segashniKoord.y};
    }
    if(sastoqnie == 2){
        return {segashniKoord.x, broiKvadratchetaStr+1 - segashniKoord.y};
    }
    if(sastoqnie == 3){
        return {broiKvadratchetaStr+1 - segashniKoord.y, broiKvadratchetaStr+1 - segashniKoord.x};
    }
    if(sastoqnie == 4){
        return {segashniKoord.y, broiKvadratchetaStr+1 - segashniKoord.x};
    }
    if(sastoqnie == 5){
        return {broiKvadratchetaStr+1 - segashniKoord.y, segashniKoord.x};
    }
    if(sastoqnie == 6){
        return originalniKoordinati(originalniKoordinati(segashniKoord, 4), 1);
    }
    return originalniKoordinati(originalniKoordinati(segashniKoord, 5), 1);
}

Koordinati zavarti(Koordinati originalni, int sastoqnie){
    if(sastoqnie == 0){
        return originalni;
    }
    if(sastoqnie == 1){
        return {originalni.x, broiKvadratchetaStr+1 - originalni.y};
    }
    if(sastoqnie == 2){
        return {broiKvadratchetaStr+1 - originalni.x, originalni.y};
    }
    if(sastoqnie == 3){
        return {broiKvadratchetaStr+1 - originalni.y, broiKvadratchetaStr+1 - originalni.x};
    }
    if(sastoqnie == 4){
        return {originalni.y, broiKvadratchetaStr+1 - originalni.x};
    }
    if(sastoqnie == 5){
        return {broiKvadratchetaStr+1 - originalni.y, originalni.x};
    }
    if(sastoqnie == 6){
        return zavarti(zavarti(originalni, 1), 4);
    }
    return zavarti(zavarti(originalni, 1), 5);
}

int main(){

    cin>>broiKvadratchetaStr>>broiNachalniCherni>>broiZaqvki;

    for(int i = 0; i < broiNachalniCherni; i++){
        int y;
        int x;
        cin>>y>>x;

        cherniTochki.insert({y, x});
        cherniTochkiMatr.insert({y, x});
    }

    int tekushtoNaslagvane = 0;

    for(int i = 0; i < broiZaqvki; i++){
        int tip;

        cin>>tip;

        if(tip == 1){
            char koqOperaciq;

            cin>>koqOperaciq;

            tekushtoNaslagvane = daiNovoSastoqnie(tekushtoNaslagvane, koqOperaciq);
        }else{
            int y;
            int x;

            cin>>y>>x;

            Koordinati originalnaTochka = originalniKoordinati({y, x}, tekushtoNaslagvane);

            if(cherniTochki.find(originalnaTochka) != cherniTochki.end()){
                cherniTochki.erase(originalnaTochka);
                //cout<<"imashe q i q iztrihme "<<endl;
            }else{
                cherniTochki.insert(originalnaTochka);
                //cout<<"nqmashe q i q dobavihme "<<endl;
            }
        }

    }

    cin>>parviteKolkoCherni;

    vector<Koordinati> kraini;

    for(set<Koordinati>::iterator a = cherniTochki.begin(); a != cherniTochki.end(); a++){
        kraini.push_back(zavarti(*a, tekushtoNaslagvane));
    }

    sort(kraini.begin(), kraini.end(), koqEPoNapred);

    for(int i = 0; i < parviteKolkoCherni; i++){
        cout<<kraini[i].y<<" "<<kraini[i].x<<endl;
    }

    return 0;
}
