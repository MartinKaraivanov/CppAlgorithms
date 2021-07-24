#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaPrava{
    int a;
    int b;
    int c;
};

int broiTochki;

DanniZaTochka tochki[1000005];

int broiVzeti;
int vzetiTochki[1000005];

DanniZaPrava pravataNaDveteTochki(DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka){
    int a = parvaTochka.y - vtoraTochka.y;
    int b = vtoraTochka.x - parvaTochka.x;
    int c = parvaTochka.x*vtoraTochka.y - parvaTochka.y*vtoraTochka.x;

    return {a, b, c};
}

int otKoqStranaNaPravatETochkata(DanniZaPrava prava, DanniZaTochka tochka){
    int suma = prava.a*tochka.x + prava.b*tochka.y + prava.c;

    if(suma == 0){
        return 0;
    }
    if(suma > 0){
        return 1;
    }
    return -1;
}

bool vsichkiTochkiOtEdnaStranaNaPravatliSa(DanniZaPrava prava){
    bool vsichkiOtEdnaStranaLiSa = true;

    int predishno = 0;

    for(int i = 0; i < broiTochki; i++){
        int otKoqStrana = otKoqStranaNaPravatETochkata(prava, tochki[i]);
        //cout<<i<<" "<<otKoqStrana<<endl;
        if(otKoqStrana != predishno && predishno != 0 && otKoqStrana != 0){
            vsichkiOtEdnaStranaLiSa = false;
            break;
        }
        if(otKoqStrana != 0){
            predishno = otKoqStrana;
        }
    }
    //cout<<endl;

    return vsichkiOtEdnaStranaLiSa;
}

bool toziVzetLiE[1000005];

void praveneNaMnogoagalnika(){
    int startovaTochka = -1;

    DanniZaTochka naiLqvaTochka = {10001, 10001};

    for(int i = 0; i < broiTochki; i++){
        if(tochki[i].x < naiLqvaTochka.x || (tochki[i].x == naiLqvaTochka.x && tochki[i].y < naiLqvaTochka.y)){
            startovaTochka = i;
            naiLqvaTochka = tochki[i];
        }
    }

    int segashen = startovaTochka;
    int predishen = -1;

    while(segashen != startovaTochka || predishen == -1){
        //cout<<segashen<<" "<<predishen<<endl;
        toziVzetLiE[segashen] = true;
        vzetiTochki[broiVzeti] = segashen;
        broiVzeti++;

        bool imaLi = false;
        int sledvasht = -1;

        double naiGolqmTangens = 0;
        int doKoiENaiGolemiq = -1;

        double naiMalakTangens = 2;
        int doKoiENaiMalkiq = -1;

        for(int i = 0; i < broiTochki; i++){
            if(i != segashen && toziVzetLiE[i] == false){
                double segashenTangens = (double)(tochki[i].y - tochki[segashen].y)/(tochki[i].x - tochki[segashen].x);

                cout<<segashenTangens<<endl;

                if(naiGolqmTangens - segashenTangens < 0.000001){
                    naiGolqmTangens = segashenTangens;
                    doKoiENaiGolemiq = i;
                }
                if(segashenTangens - naiMalakTangens < 0.000001){
                    naiMalakTangens = segashenTangens;
                    doKoiENaiMalkiq = i;
                }
            }
        }

        DanniZaPrava pravataSNaiGolemiq = pravataNaDveteTochki(tochki[segashen], tochki[doKoiENaiGolemiq]);
        DanniZaPrava pravataSNaiMalkiq = pravataNaDveteTochki(tochki[segashen], tochki[doKoiENaiMalkiq]);

        if(vsichkiTochkiOtEdnaStranaNaPravatliSa(pravataSNaiGolemiq) == true){
            imaLi = true;
            sledvasht = doKoiENaiGolemiq;
        }else{
            if(vsichkiTochkiOtEdnaStranaNaPravatliSa(pravataSNaiMalkiq) == true){
                imaLi = true;
                sledvasht = doKoiENaiMalkiq;
            }
        }

        if(imaLi == false){
            break;
        }else{
            predishen = segashen;
            segashen = sledvasht;
        }

        //cout<<sledvasht<<endl;
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
            liceNaTrapecSTeziTochki(tochki[vzetiTochki[parvaTochka]], tochki[vzetiTochki[vtoraTochka]]);
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

    /*for(int i = 0; i < broiVzeti; i++){
        cout<<vzetiTochki[i]<<endl;
    }*/

    double liceto = izchislqvaneNaLice();

    if(abs(round(liceto) - liceto) < 0.000001){
        cout<<fixed<<setprecision(0);
    }else{
        cout<<fixed<<setprecision(1);
    }

    cout<<liceto<<endl;

    return 0;
}
