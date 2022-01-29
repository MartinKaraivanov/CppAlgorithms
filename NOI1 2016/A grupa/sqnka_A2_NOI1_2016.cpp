#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
using namespace std;

double ednaStrana;
double vtoraStrana;

struct DanniZaPrava{
    double a;
    double b;
    double c;
};

struct Koordinati{
    double x;
    double y;
};

Koordinati gornaDqsna;
Koordinati dolnaDqsna;
Koordinati dolnaLqva;
Koordinati gornaLqva;

DanniZaPrava dqsnaStrana;
DanniZaPrava dolnaStrana;
DanniZaPrava lqvaStrana;
DanniZaPrava gornaStrana;

double daiRadiani(double gradusi){
    double pi = 3.141592653589793238462643383279;
    return gradusi * (pi/180.0);
}

Koordinati zavartiNa(double kolkoGradusa, Koordinati originalni){
    double novX = originalni.x*cos(daiRadiani(kolkoGradusa)) - originalni.y*sin(daiRadiani(kolkoGradusa));
    double novY = originalni.x*sin(daiRadiani(kolkoGradusa)) + originalni.y*cos(daiRadiani(kolkoGradusa));

    return {novX, novY};
}

DanniZaPrava pravataNaDveTochki(Koordinati parva, Koordinati vtora){
    double a = parva.y - vtora.y;
    double b = vtora.x - parva.x;
    double c = parva.x*vtora.y - parva.y*vtora.x;

    return {a, b, c};
}

Koordinati presechnataTochkaNa(DanniZaPrava parva, DanniZaPrava vtora){
    double x = (vtora.b*parva.c - vtora.c*parva.b)/(vtora.a*parva.b - vtora.b*parva.a);
    double y = (parva.a*vtora.c - parva.c*vtora.a)/(vtora.a*parva.b - vtora.b*parva.a);

    return {x, y};
}

double daljinaNaOtsechka(Koordinati a, Koordinati b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double dopalnitelnoLicePriZav(double gradusi){

    Koordinati C1 = zavartiNa(gradusi, gornaDqsna);
    Koordinati B1 = zavartiNa(gradusi, dolnaDqsna);
    Koordinati A1 = zavartiNa(gradusi, dolnaLqva);
    Koordinati D1 = zavartiNa(gradusi, gornaLqva);

    //cout<<gradusi<<" "<<D1.x<<" "<<gornaDqsna.x<<endl;

    if(D1.x > gornaDqsna.x){
        return -1;
    }

    DanniZaPrava tekushtaGornaPrava = pravataNaDveTochki(D1, C1);
    DanniZaPrava tekushtaDqsnaPrava = pravataNaDveTochki(C1, B1);
    DanniZaPrava tekushtaLqvaPrava = pravataNaDveTochki(A1, D1);

    Koordinati M = presechnataTochkaNa(gornaStrana, tekushtaLqvaPrava);
    Koordinati N = presechnataTochkaNa(gornaStrana, tekushtaGornaPrava);
    Koordinati P = presechnataTochkaNa(dqsnaStrana, tekushtaGornaPrava);
    Koordinati Q = presechnataTochkaNa(dqsnaStrana, tekushtaDqsnaPrava);

    double liceGornoTriag = daljinaNaOtsechka(D1, M)*daljinaNaOtsechka(D1, N);
    double liceDqsnotriag = daljinaNaOtsechka(C1, P)*daljinaNaOtsechka(C1, Q);

    //cout<<"dopalnitelnoto lice e "<<liceGornoTriag+liceDqsnotriag<<endl;

    return liceGornoTriag+liceDqsnotriag;
}

void postroiZastoporenite(){
    gornaDqsna = {ednaStrana/2, vtoraStrana/2};
    dolnaDqsna = {ednaStrana/2, -vtoraStrana/2};
    dolnaLqva = {-ednaStrana/2, -vtoraStrana/2};
    gornaLqva = {-ednaStrana/2, vtoraStrana/2};

    dqsnaStrana = pravataNaDveTochki(gornaDqsna, dolnaDqsna);
    dolnaStrana = pravataNaDveTochki(dolnaDqsna, dolnaLqva);
    lqvaStrana = pravataNaDveTochki(dolnaLqva, gornaLqva);
    gornaStrana = pravataNaDveTochki(gornaLqva, gornaDqsna);
}

int main(){

    cin>>ednaStrana>>vtoraStrana;

    postroiZastoporenite();

    double naiGolqmoDopLice = 0;

    double prednoto = 0;

    double stapka = 1;
    double znak = 1;
    double gradusi = 0;

    while(true){
        double tuka = dopalnitelnoLicePriZav(-gradusi);

        if(abs(prednoto - tuka) < 0.0001){
            break;
        }

        if(tuka < prednoto){
            znak *= -1;
            stapka /= 10;
        }

        naiGolqmoDopLice = max(naiGolqmoDopLice, tuka);
        prednoto = tuka;

        gradusi += znak*stapka;
    }

    double lice = ednaStrana*vtoraStrana + naiGolqmoDopLice;

    double perpendikularnoLice = ednaStrana*vtoraStrana + ednaStrana*(vtoraStrana - ednaStrana);

    cout<<fixed<<setprecision(3)<<max(lice, perpendikularnoLice)<<endl;

    return 0;
}
