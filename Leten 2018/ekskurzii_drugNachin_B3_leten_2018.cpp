#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaUchenika{
    int tqlo;
    int ruce;
};

int broiUchenici;
int visochinaNaTrapa;

DanniZaUchenika uchenici[2010];

bool poGolqmo(DanniZaUchenika a, DanniZaUchenika b){
    return a.tqlo > b.tqlo;
}

int main(){
    cin>>broiUchenici;

    for(int i = 0; i < broiUchenici; i++){
        cin>>uchenici[i].tqlo>>uchenici[i].ruce;
    }

    cin>>visochinaNaTrapa;

    sort(uchenici, uchenici + broiUchenici, poGolqmo);

    int broiIzlizashti = 0;

    int visochinaNaNeizlizashtite = 0;
    int koiEPurviqDetoIzliza = broiUchenici;

    for(int i = 0; i < broiUchenici; i++){
        if(visochinaNaNeizlizashtite + uchenici[i].tqlo >= visochinaNaTrapa){
            koiEPurviqDetoIzliza = i;
            broiIzlizashti = broiUchenici - i;
            break;
        }
        visochinaNaNeizlizashtite += uchenici[i].tqlo;
    }

    for(int i = koiEPurviqDetoIzliza - 1; i >= 0; i--){
        if(visochinaNaNeizlizashtite + uchenici[i].ruce >= visochinaNaTrapa){
            broiIzlizashti++;
            visochinaNaNeizlizashtite -= uchenici[i].tqlo;
        }
    }

    cout<<broiIzlizashti<<endl;

    return 0;
}
