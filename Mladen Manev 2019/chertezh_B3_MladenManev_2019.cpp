#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct DanniZaTochka{
    double x;
    double y;
};

DanniZaTochka startova;
DanniZaTochka finalna;

int broiOtsechki;

double dalzhiniNaOtsechki[1010];

double razstoqnieMzhduTochki(DanniZaTochka parva, DanniZaTochka vtora){
    double poX = abs(parva.x - vtora.x);
    double poY = abs(parva.y - vtora.y);

    double aNaVtora = poX * poX;
    double bNaVtora = poY * poY;

    double cNaVtora = aNaVtora + bNaVtora;

    double c = sqrt(cNaVtora);

    return c;
}

int main(){
    cin>>startova.x>>startova.y>>finalna.x>>finalna.y;

    cin>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        cin>>dalzhiniNaOtsechki[i];
    }



    cout<<"NO"<<endl;

    return 0;
}
