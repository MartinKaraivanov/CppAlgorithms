#include<iostream>
using namespace std;

struct DanniZaTochka{
    long long x;
    long long y;
};

struct DanniZaOtsechka{
    DanniZaTochka nachalo;
    DanniZaTochka krai;
};

long long maxX;
long long maxY;

int broiAgli;

DanniZaOtsechka otsechki[100000];
int broiVertikalniOtsechki = 0;

int main(){
    cin>>maxX>>maxY;

    cin>>broiAgli;

    DanniZaTochka predishnaTochka;

    cin>>predishnaTochka.x>>predishnaTochka.y;

    for(int i = 0; i < broiAgli - 1; i++){
        DanniZaTochka segashnaTochka;
        cin>>segashnaTochka.x>>segashnaTochka.y;

        if(predishnaTochka.x == segashnaTochka.x){
            otsechki[broiVertikalniOtsechki].nachalo = predishnaTochka;
            otsechki[broiVertikalniOtsechki].krai = segashnaTochka;
            broiVertikalniOtsechki++;
        }

        predishnaTochka = segashnaTochka;
    }

    long long nepochistenko = 0;

    for(long long y = 0; y < maxY; y++){
        long long maksimalnoXcheZaTovaYche = 0;
        for(int i = 0; i < broiVertikalniOtsechki; i++){
            if(otsechki[i].nachalo.y <= y && otsechki[i].krai.y > y){
                if(otsechki[i].nachalo.x > maksimalnoXcheZaTovaYche){
                    maksimalnoXcheZaTovaYche = otsechki[i].nachalo.x;
                }
            }
        }

        nepochistenko += maxX - maksimalnoXcheZaTovaYche;
    }


    cout<<nepochistenko<<endl;

    return 0;
}
