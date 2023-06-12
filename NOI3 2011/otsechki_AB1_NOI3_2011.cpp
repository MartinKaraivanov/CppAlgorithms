#include<iostream>
using namespace std;

struct Tochka{
    int x;
    int y;
};

Tochka edinKrai[128];
Tochka drugKrai[128];

int broiOtsechki;

struct Prava{
    int a;
    int b;
    int c;
};

Prava pravataNaDveteTochki(Tochka parva, Tochka vtora){
    return {parva.y - vtora.y, vtora.x - parva.x, parva.x*vtora.y - parva.y*vtora.x};
}

double presechenX(Prava parva, Prava vtora){
    double a1 = parva.a;
    double a2 = vtora.a;
    double b1 = parva.b;
    double b2 = vtora.b;
    double c1 = parva.c;
    double c2 = vtora.c;

    return (b2*c1 - b1*c2)/(b1*a2 - b2*a1);
}

double presechenY(Prava parva, Prava vtora){
    double a1 = parva.a;
    double a2 = vtora.a;
    double b1 = parva.b;
    double b2 = vtora.b;
    double c1 = parva.c;
    double c2 = vtora.c;

    return (a1*c2 - a2*c1)/(b1*a2 - b2*a1);
}

int sTiqDvete(Tochka parva, Tochka vtora){

    Prava pravata = pravataNaDveteTochki(parva, vtora);

    //cout<<"pravata na "<<parva.x<<" "<<parva.y<<" i "<<vtora.x<<" "<<vtora.y<<" s: "<<endl;

    int broiPres = 0;

    for(int i = 0; i < broiOtsechki; i++){
        Prava pravataNaOts = pravataNaDveteTochki(edinKrai[i], drugKrai[i]);

        //cout<<"otsechakata "<<edinKrai[i].x<<" "<<edinKrai[i].y<<"  "<<drugKrai[i].x<<" "<<drugKrai[i].y<<": ";

        double presX = presechenX(pravata, pravataNaOts);
        double presY = presechenY(pravata, pravataNaOts);

        //cout<<presX<<" "<<presY<<endl;

        if((presX >= min(edinKrai[i].x, drugKrai[i].x)) &&
            (presX <= max(edinKrai[i].x ,drugKrai[i].x)) &&
            (presY >= min(edinKrai[i].y, drugKrai[i].y)) &&
            (presY <= max(edinKrai[i].y , drugKrai[i].y)))
        {
            broiPres++;
        }
    }
    //cout<<endl;

    return broiPres;
}

int main(){

    cin>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        cin>>edinKrai[i].x>>edinKrai[i].y>>drugKrai[i].x>>drugKrai[i].y;
    }

    int maksOtsechki = 0;

    for(int i = 0; i < broiOtsechki - 1; i++){
        for(int j = i + 1; j < broiOtsechki; j++){
            int tuka1 = sTiqDvete(edinKrai[i], edinKrai[j]);
            int tuka2 = sTiqDvete(edinKrai[i], drugKrai[j]);
            int tuka3 = sTiqDvete(drugKrai[i], edinKrai[j]);
            int tuka4 = sTiqDvete(drugKrai[i], drugKrai[j]);

            int tukaMaks = max(max(tuka1, tuka2), max(tuka3, tuka4));

            maksOtsechki = max(maksOtsechki, tukaMaks);
        }
    }

    cout<<maksOtsechki<<endl;

    return 0;
}
