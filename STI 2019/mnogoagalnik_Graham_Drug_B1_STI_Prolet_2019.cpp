#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiTochki;

DanniZaTochka tochki[1000005];

DanniZaTochka nachalnataTochka;

int broiVzeti;
DanniZaTochka vzetiTochki[1000005];

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
        vzetiTochki[broiVzeti] = gorni[i];
        broiVzeti++;
    }

    for(unsigned int i = dolni.size() - 2; i > 0; i--){
        vzetiTochki[broiVzeti] = dolni[i];
        broiVzeti++;
    }
}

int liceNaTrapecSTeziTochki(DanniZaTochka parva, DanniZaTochka vtora){
    int lice = (parva.y + vtora.y)*(parva.x - vtora.x);

    return lice;
}

double izchislqvaneNaLice(){
    int parvaTochka = 0;
    int vtoraTochka = 1;

    long long lice = 0;

    while(parvaTochka < broiVzeti){
        int segashnoLice =
            liceNaTrapecSTeziTochki(vzetiTochki[parvaTochka], vzetiTochki[vtoraTochka]);
        lice += segashnoLice;
        parvaTochka++;
        vtoraTochka++;
        if(vtoraTochka >= broiVzeti){
            vtoraTochka = 0;
        }
    }

    double liceZaIzvezhdane = (double)abs(lice);

    return liceZaIzvezhdane / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vavezhdashtX;
    while(cin>>vavezhdashtX){
        int vavezhdashtY;
        cin>>vavezhdashtY;

        tochki[broiTochki] = {vavezhdashtX, vavezhdashtY};
        broiTochki++;
    }

    praveneNaMnogoagalnika();

    double liceto = izchislqvaneNaLice();

    if(abs(round(liceto) - liceto) < 0.000001){
        cout<<fixed<<setprecision(0);
    }else{
        cout<<fixed<<setprecision(1);
    }

    cout<<liceto<<endl;

    return 0;
}
