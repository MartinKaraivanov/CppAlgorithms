#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int broiTochki;
int radius;

struct Koordinati{
    double x;
    double y;
};

vector<Koordinati> tochki;

bool koqEPoNapred(Koordinati a, Koordinati b){
    if(a.x < b.x){
        return true;
    }
    if(a.x > b.x){
        return false;
    }
    return a.y < b.y;
}

bool poChasovnikovata(Koordinati a, Koordinati b, Koordinati c){
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;
}

bool obratnoNaChsovnikovata(Koordinati a, Koordinati b, Koordinati c){
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) > 0;
}

vector<Koordinati> obvivkata;

void nameriObvivka(){

    sort(tochki.begin(), tochki.end(), &koqEPoNapred);

    Koordinati parvaTochka = tochki[0];
    Koordinati poslednaTochka = tochki.back();

    vector<Koordinati> gorni;
    vector<Koordinati> dolni;

    gorni.push_back(parvaTochka);
    dolni.push_back(parvaTochka);

    for(int i = 1; i < (int)tochki.size(); i++){
        if(i == tochki.size() - 1 || poChasovnikovata(parvaTochka, tochki[i], poslednaTochka) == true){
            while(gorni.size() >= 2 && poChasovnikovata(gorni[gorni.size() - 2], gorni[gorni.size()-1], tochki[i]) == false){
                gorni.pop_back();
            }

            gorni.push_back(tochki[i]);
        }
        if(i == tochki.size() - 1 || obratnoNaChsovnikovata(parvaTochka, tochki[i], poslednaTochka) == true){
            while(dolni.size() >= 2 &&
                    obratnoNaChsovnikovata(dolni[dolni.size() - 2], dolni[dolni.size()-1], tochki[i]) == false)
            {
                dolni.pop_back();
            }

            dolni.push_back(tochki[i]);
        }
    }

    for(int i = 0; i < (int)gorni.size(); i++){
        obvivkata.push_back(gorni[i]);
    }

    for(int i = (int)dolni.size() - 2; i > 0; i--){
        obvivkata.push_back(dolni[i]);
    }

    obvivkata.push_back(parvaTochka);
}

double razstoqnieMejduTochki(Koordinati parva, Koordinati vtora){
    return sqrt((parva.x - vtora.x)*(parva.x - vtora.x) + (parva.y - vtora.y)*(parva.y - vtora.y));
}

int main(){
    cin>>broiTochki>>radius;

    for(int i = 0; i < broiTochki; i++){
        Koordinati tuka;
        cin>>tuka.x>>tuka.y;

        tochki.push_back(tuka);
    }

    nameriObvivka();

    double razstoqnie = 0;

    for(int i = 1; i < (int)obvivkata.size(); i++){
        razstoqnie += razstoqnieMejduTochki(obvivkata[i - 1], obvivkata[i]);
    }

    razstoqnie += 3.14159265 * 2.0 * radius;

    cout<<fixed<<setprecision(3)<<razstoqnie<<endl;

    return 0;
}
