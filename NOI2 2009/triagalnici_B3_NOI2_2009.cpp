#include<iostream>
using namespace std;

struct DanniZaTochka{
    long long x;
    long long y;
};

struct DanniZaTriagalnik{
    DanniZaTochka tochkaA;
    DanniZaTochka tochkaB;
    DanniZaTochka tochkaC;
};

struct DanniZaPrava{
    long long a;
    long long b;
    long long c;
};

DanniZaPrava pravataNaDveTochki(DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka){
    long long a = parvaTochka.y - vtoraTochka.y;
    long long b = vtoraTochka.x - parvaTochka.x;
    long long c = parvaTochka.x*vtoraTochka.y - parvaTochka.y*vtoraTochka.x;

    DanniZaPrava zaVrasht = {a, b, c};

    return zaVrasht;
}

long long kadeETochkataSprqmoPravata(DanniZaPrava p, DanniZaTochka t){
    long long kadeE = p.a*t.x + p.b*t.y + p.c;

    if(kadeE == 0){
        return 0;
    }
    if(kadeE > 0){
        return 1;
    }
    return -1;
}

bool dveteTochkiOtEdnaISashtaStranaLiSa(DanniZaPrava prava, DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka){
    long long stranataNaParvaTochka = kadeETochkataSprqmoPravata(prava, parvaTochka);
    long long stranataNaVtoraTochka = kadeETochkataSprqmoPravata(prava, vtoraTochka);

    return stranataNaParvaTochka == stranataNaVtoraTochka;
}

bool tochkataVTriagalnikaLiE(DanniZaTriagalnik triagalnik, DanniZaTochka tochka){
    DanniZaPrava stranataAB = pravataNaDveTochki(triagalnik.tochkaA, triagalnik.tochkaB);
    DanniZaPrava stranataBC = pravataNaDveTochki(triagalnik.tochkaB, triagalnik.tochkaC);
    DanniZaPrava stranataAC = pravataNaDveTochki(triagalnik.tochkaA, triagalnik.tochkaC);
    bool otEdnaStranaLiESTochkaC = dveteTochkiOtEdnaISashtaStranaLiSa(stranataAB, triagalnik.tochkaC, tochka);
    bool otEdnaStranaLiESTochkaA = dveteTochkiOtEdnaISashtaStranaLiSa(stranataBC, triagalnik.tochkaA, tochka);
    bool otEdnaStranaLiESTochkaB = dveteTochkiOtEdnaISashtaStranaLiSa(stranataAC, triagalnik.tochkaB, tochka);

    return otEdnaStranaLiESTochkaA && otEdnaStranaLiESTochkaB && otEdnaStranaLiESTochkaC;
}

bool triagalnikaVatreVTriagalnikaLiE(DanniZaTriagalnik vanshen, DanniZaTriagalnik vatreshen){
    bool tochkaANaVatreshniqVatreLiE = tochkataVTriagalnikaLiE(vanshen, vatreshen.tochkaA);
    bool tochkaBNaVatreshniqVatreLiE = tochkataVTriagalnikaLiE(vanshen, vatreshen.tochkaB);
    bool tochkaCNaVatreshniqVatreLiE = tochkataVTriagalnikaLiE(vanshen, vatreshen.tochkaC);

    return tochkaANaVatreshniqVatreLiE && tochkaBNaVatreshniqVatreLiE && tochkaCNaVatreshniqVatreLiE;
}

long long broiTriagalnici;

DanniZaTriagalnik triagalnici[1010];

long long priToziKolkoNaiMnogoEdinVdrug[1010];

long long naiMnogoEdinVDrug(long long indexNaTriagalnik){
    if(priToziKolkoNaiMnogoEdinVdrug[indexNaTriagalnik] >= 0){
        return priToziKolkoNaiMnogoEdinVdrug[indexNaTriagalnik];
    }

    long long naiMnogo = 0;

    for(long long i = 0; i < broiTriagalnici; i++){
        if(triagalnikaVatreVTriagalnikaLiE(triagalnici[indexNaTriagalnik], triagalnici[i])){
            long long sega = 1 + naiMnogoEdinVDrug(i);
            naiMnogo = max(naiMnogo, sega);
        }
    }

    priToziKolkoNaiMnogoEdinVdrug[indexNaTriagalnik] = naiMnogo;
    return naiMnogo;
}

int main(){
    cin>>broiTriagalnici;

    for(long long i = 0; i < broiTriagalnici; i++){
        long long ax;
        long long ay;
        long long bx;
        long long by;
        long long cx;
        long long cy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;

        DanniZaTochka tochkataA = {ax, ay};
        DanniZaTochka tochkataB = {bx, by};
        DanniZaTochka tochkataC = {cx, cy};

        DanniZaTriagalnik novTriagalnik = {tochkataA, tochkataB, tochkataC};

        triagalnici[i] = novTriagalnik;
    }

    for(int i = 0; i < 1001; i++){
        priToziKolkoNaiMnogoEdinVdrug[i] = -1;
    }

    long long naiMnogoEVDrug = 0;

    for(long long i = 0; i < broiTriagalnici; i++){
        long long priToziNachalen = 1 + naiMnogoEdinVDrug(i);
        naiMnogoEVDrug = max(naiMnogoEVDrug, priToziNachalen);
    }

    cout<<naiMnogoEVDrug<<endl;

    /*for(int i = 0; i < broiTriagalnici; i++){
        for(int j = 0; j < broiTriagalnici; j++){
            if(triagalnikaVatreVTriagalnikaLiE(triagalnici[i], triagalnici[j])){
                cout<<"Triagalnik "<<j<<" e vatre v triagalnik "<<i<<endl;
            }
        }
    }*/

    return 0;
}
