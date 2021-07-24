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

int orientaciq(DanniZaTochka p, DanniZaTochka q, DanniZaTochka r){
    int stoinost = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if(stoinost == 0){
        return 0;
    }

    if(stoinost > 0){
        return 1;
    }

    return 2;
}

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
    int sledvasht = -1;

    while(segashen != startovaTochka || sledvasht == -1){
        //cout<<segashen<<" "<<predishen<<endl;
        vzetiTochki[broiVzeti] = segashen;
        broiVzeti++;

        sledvasht = (segashen + 1)%broiTochki;
        for(int i = 0; i < broiTochki; i++){
            if(orientaciq(tochki[segashen], tochki[i], tochki[sledvasht]) == 2){
                sledvasht = i;
            }
        }

        //cout<<sledvasht<<endl;
        segashen = sledvasht;
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

    double liceto = izchislqvaneNaLice();

    if(abs(round(liceto) - liceto) < 0.000001){
        cout<<fixed<<setprecision(0);
    }else{
        cout<<fixed<<setprecision(1);
    }

    cout<<liceto<<endl;

    return 0;
}
