#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiTochki;

DanniZaTochka tochki[20];

int broiVzeti;
DanniZaTochka tochkiZaIzpolzvane[20];

bool sravnqvane(DanniZaTochka a, DanniZaTochka b){
    if(a.x < b.x){
        return true;
    }
    if(a.x > b.x){
        return false;
    }

    return a.y < b.y;
}

bool poChasovnikovataStrelkaLiE(DanniZaTochka a, DanniZaTochka b, DanniZaTochka c){
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;
}

bool obratnoNaChasovnikovataStrelkaLiE(DanniZaTochka a, DanniZaTochka b, DanniZaTochka c){
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) > 0;
}

void praveneNaMnogoagalnika(){
    sort(tochki, tochki + broiTochki, sravnqvane);

    DanniZaTochka nachalna = tochki[0];
    DanniZaTochka posledna = tochki[broiTochki - 1];

    vector<DanniZaTochka> gorni;
    vector<DanniZaTochka> dolni;

    gorni.push_back(nachalna);
    dolni.push_back(nachalna);

    for(int i = 1; i < broiTochki; i++){
        if(i == broiTochki - 1 || poChasovnikovataStrelkaLiE(nachalna, tochki[i], posledna) == true){
            while(gorni.size() >= 2 &&
                poChasovnikovataStrelkaLiE(gorni[gorni.size() - 2], gorni[gorni.size() - 1], tochki[i]) == false)
            {
                gorni.pop_back();
            }

            gorni.push_back(tochki[i]);
        }
        if(i == broiTochki - 1 || obratnoNaChasovnikovataStrelkaLiE(nachalna, tochki[i], posledna) == true){
            while(dolni.size() >= 2 &&
                obratnoNaChasovnikovataStrelkaLiE(dolni[dolni.size() - 2], dolni[dolni.size() - 1], tochki[i]) == false)
            {
                dolni.pop_back();
            }

            dolni.push_back(tochki[i]);
        }
    }

    for(unsigned int i = 0; i < gorni.size(); i++){
        tochkiZaIzpolzvane[broiVzeti] = gorni[i];
        broiVzeti++;
    }

    for(unsigned int i = dolni.size() - 2; i > 0; i--){
        tochkiZaIzpolzvane[broiVzeti] = dolni[i];
        broiVzeti++;
    }
}

int liceNaTrapecSTeziTochki(DanniZaTochka parva, DanniZaTochka vtora){
    int lice = ((int)parva.y + vtora.y)*(parva.x - vtora.x);

    return lice;
}

int licesTeziTochki(DanniZaTochka a, DanniZaTochka b, DanniZaTochka c){
    int x1 = a.x;
    int y1 = a.y;

    int x2 = b.x;
    int y2 = b.y;

    int x3 = c.x;
    int y3 = c.y;

    int lice1 = abs(x1 - x2) * abs(y1 - y2);
    int lice2 = abs(x1 - x3) * abs(y1 - y3);
    int lice3 = abs(x2 - x3) * abs(y2 - y3);

    int pravoagalnoLice = abs(max(max(x1, x2), x3) - min(min(x1, x2), x3)) * abs(max(max(y1, y2), y3) - min(min(y1, y2), y3));

    int sborNaTriteLica = lice1+lice2+lice3;

    int otgovor = pravoagalnoLice - sborNaTriteLica;

    return otgovor;
}

double liceSTriagalnici(){
    double lichice = 0;

    int zabuchena = 0;

    int parvaTochka = 1;
    int vtoraTochka = 2;

    while(vtoraTochka != broiTochki){
        lichice +=
            licesTeziTochki(tochkiZaIzpolzvane[zabuchena], tochkiZaIzpolzvane[parvaTochka], tochkiZaIzpolzvane[vtoraTochka]);
        parvaTochka++;
        vtoraTochka++;
    }

    return lichice/2;
}

double liceSTrapci(){
    int parvaTochka = 0;
    int vtoraTochka = 1;

    int lice = 0;

    while(parvaTochka < broiVzeti){
        int segashnoLice =
            liceNaTrapecSTeziTochki(tochkiZaIzpolzvane[parvaTochka], tochkiZaIzpolzvane[vtoraTochka]);
        //cout<<tochkiZaIzpolzvane[parvaTochka]<<" "<<tochkiZaIzpolzvane[vtoraTochka]<<" "<<segashnoLice<<endl;
        lice += segashnoLice;
        parvaTochka++;
        vtoraTochka++;
        if(vtoraTochka >= broiVzeti){
            vtoraTochka = 0;
        }
    }

    //cout<<lice<<endl;

    double liceZaIzvezhdane = (double)abs(lice);

    return liceZaIzvezhdane / 2;
}

int main(){
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    praveneNaMnogoagalnika();

    if(broiVzeti < broiTochki){
        cout<<0<<endl;
        return 0;
    }

    double lice = liceSTrapci();

    if(abs(round(lice) - lice) < 0.000001){
        cout<<fixed<<setprecision(0);
    }else{
        cout<<fixed<<setprecision(1);
    }

    cout<<lice<<endl;

    return 0;
}
