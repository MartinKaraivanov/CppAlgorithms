#include<iostream>
using namespace std;

struct DanniZaTochka{
    double x;
    double y;
};

struct DanniZaTriagalnik{
    DanniZaTochka vrahA;
    DanniZaTochka vrahB;
    DanniZaTochka vrahC;
};

struct DanniZaPrava{
    double a;
    double b;
    double c;
};

struct DanniZaOtsechkata{
    DanniZaTochka parvaTochka;
    DanniZaTochka vtoraTochka;
};

DanniZaTriagalnik abc;
DanniZaTriagalnik triagalnici[4];
bool otgovori[5];

DanniZaPrava pravataNaDveteTochki(DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka){
    double a = parvaTochka.y - vtoraTochka.y;
    double b = vtoraTochka.x - parvaTochka.x;
    double c = parvaTochka.x*vtoraTochka.y - parvaTochka.y*vtoraTochka.x;

    return {a, b, c};
}

int otKoqStranaNaPrvataETochkata(DanniZaPrava prava, DanniZaTochka tochka){
    int suma = prava.a*tochka.x + prava.b*tochka.y + prava.c;

    if(suma == 0){
        return 0;
    }
    if(suma < 0){
        return -1;
    }
    return 1;
}

bool otEdnaStranaNaPravataLiSaTeziDveteTochki(DanniZaPrava prava, DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka){
    int stranaOtKoqtoEParvata = otKoqStranaNaPrvataETochkata(prava, parvaTochka);
    int stranaOtKoqtoEVtorata = otKoqStranaNaPrvataETochkata(prava, vtoraTochka);

    if(stranaOtKoqtoEParvata == stranaOtKoqtoEVtorata || stranaOtKoqtoEVtorata == 0 || stranaOtKoqtoEParvata == 0){
        return true;
    }
    return false;
}

bool tochkataVTriagalnikaLiE(DanniZaTochka tochka, DanniZaTriagalnik triagalnik){
    DanniZaPrava pravatNaAB = pravataNaDveteTochki(triagalnik.vrahA, triagalnik.vrahB);
    bool zaTochkaC = otEdnaStranaNaPravataLiSaTeziDveteTochki(pravatNaAB, triagalnik.vrahC, tochka);

    DanniZaPrava pravataNaBC = pravataNaDveteTochki(triagalnik.vrahB, triagalnik.vrahC);
    bool zaTochkaA = otEdnaStranaNaPravataLiSaTeziDveteTochki(pravataNaBC, triagalnik.vrahA, tochka);

    DanniZaPrava pravataNaAC = pravataNaDveteTochki(triagalnik.vrahA, triagalnik.vrahC);
    bool zaTochkaB = otEdnaStranaNaPravataLiSaTeziDveteTochki(pravataNaAC, triagalnik.vrahB, tochka);

    if(zaTochkaA && zaTochkaB && zaTochkaC){
        return true;
    }
    return false;
}

bool dvePraviPresichatLiSe(DanniZaPrava parva, DanniZaPrava vtora){
    int sumichka = vtora.a*parva.b - parva.a*vtora.b;

    return sumichka != 0;
}

DanniZaTochka presechnaTochkaNaPravi(DanniZaPrava parva, DanniZaPrava vtora){
    double a1 = parva.a;
    double b1 = parva.b;
    double c1 = parva.c;
    double a2 = vtora.a;
    double b2 = vtora.b;
    double c2 = vtora.c;

    double x = (b2*c1 - b1*c2)/(a2*b1 - a1*b2);
    double y = (a1*c2 - a2*c1)/(a2*b1 - a1*b2);

    DanniZaTochka zaVrashtane = {x, y};

    return zaVrashtane;
}

bool presichatLiSeDveteOtsechki(DanniZaOtsechkata parva, DanniZaOtsechkata vtora){
    DanniZaPrava pravatNaParvataOtsechka = pravataNaDveteTochki(parva.parvaTochka, parva.vtoraTochka);
    DanniZaPrava pravatNaVtorataOtsechka = pravataNaDveteTochki(vtora.parvaTochka, vtora.vtoraTochka);

    if(dvePraviPresichatLiSe(pravatNaParvataOtsechka, pravatNaVtorataOtsechka) == false){
        return false;
    }

    DanniZaTochka presTochkaNaDvetePravi = presechnaTochkaNaPravi(pravatNaParvataOtsechka, pravatNaVtorataOtsechka);

    bool otParvataOtsechkaLiE = false;
    bool otVtorataOtsechkaLiE = false;

    if((presTochkaNaDvetePravi.x >= min(parva.parvaTochka.x, parva.vtoraTochka.x) &&
        (presTochkaNaDvetePravi.x <= max(parva.parvaTochka.x, parva.vtoraTochka.x)) &&
        (presTochkaNaDvetePravi.y >= min(parva.parvaTochka.y, parva.vtoraTochka.y)) &&
        (presTochkaNaDvetePravi.y <= max(parva.parvaTochka.y, parva.vtoraTochka.y))))
    {
        otParvataOtsechkaLiE = true;
    }

    if((presTochkaNaDvetePravi.x >= min(vtora.parvaTochka.x, vtora.vtoraTochka.x) &&
        (presTochkaNaDvetePravi.x <= max(vtora.parvaTochka.x, vtora.vtoraTochka.x)) &&
        (presTochkaNaDvetePravi.y >= min(vtora.parvaTochka.y, vtora.vtoraTochka.y)) &&
        (presTochkaNaDvetePravi.y <= max(vtora.parvaTochka.y, vtora.vtoraTochka.y))))
    {
        otVtorataOtsechkaLiE = true;
    }

    if(otParvataOtsechkaLiE && otVtorataOtsechkaLiE){
        return true;
    }
    return false;
}

bool dvataTriagalnikaZastapvatLiSe(DanniZaTriagalnik parvi, DanniZaTriagalnik vtori){
    if(tochkataVTriagalnikaLiE(parvi.vrahA, vtori) ||
       tochkataVTriagalnikaLiE(parvi.vrahB, vtori) ||
       tochkataVTriagalnikaLiE(parvi.vrahC, vtori) ||
       tochkataVTriagalnikaLiE(vtori.vrahA, parvi) ||
       tochkataVTriagalnikaLiE(vtori.vrahB, parvi) ||
       tochkataVTriagalnikaLiE(vtori.vrahC, parvi))
    {
        return true;
    }

    if(presichatLiSeDveteOtsechki({parvi.vrahA, parvi.vrahB}, {vtori.vrahA, vtori.vrahB}) ||
       presichatLiSeDveteOtsechki({parvi.vrahA, parvi.vrahC}, {vtori.vrahA, vtori.vrahB}) ||
       presichatLiSeDveteOtsechki({parvi.vrahB, parvi.vrahC}, {vtori.vrahA, vtori.vrahB}) ||
       presichatLiSeDveteOtsechki({parvi.vrahA, parvi.vrahB}, {vtori.vrahA, vtori.vrahC}) ||
       presichatLiSeDveteOtsechki({parvi.vrahA, parvi.vrahC}, {vtori.vrahA, vtori.vrahC}) ||
       presichatLiSeDveteOtsechki({parvi.vrahB, parvi.vrahC}, {vtori.vrahA, vtori.vrahC}) ||
       presichatLiSeDveteOtsechki({parvi.vrahA, parvi.vrahB}, {vtori.vrahB, vtori.vrahC}) ||
       presichatLiSeDveteOtsechki({parvi.vrahA, parvi.vrahC}, {vtori.vrahB, vtori.vrahC}) ||
       presichatLiSeDveteOtsechki({parvi.vrahB, parvi.vrahC}, {vtori.vrahB, vtori.vrahC}))
    {
        return true;
    }

    return false;
}

int main(){
    cin>>abc.vrahA.x>>abc.vrahA.y>>abc.vrahB.x>>abc.vrahB.y>>abc.vrahC.x>>abc.vrahC.y;
    for(int i = 0; i < 4; i++){
        cin>>triagalnici[i].vrahA.x>>triagalnici[i].vrahA.y>>triagalnici[i].vrahB.x>>triagalnici[i].vrahB.y;
        cin>>triagalnici[i].vrahC.x>>triagalnici[i].vrahC.y;
    }

    for(int i = 0; i < 4; i++){
        otgovori[i] = dvataTriagalnikaZastapvatLiSe(abc, triagalnici[i]);
    }

    for(int i = 0; i < 4; i++){
        if(otgovori[i]){
            cout<<1;
        }else{
            cout<<0;
        }
        //cout<<otgovori[i];
    }

    cout<<endl;

    return 0;
}
