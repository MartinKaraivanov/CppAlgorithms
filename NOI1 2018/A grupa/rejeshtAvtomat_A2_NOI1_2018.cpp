#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct DanniZaTochka{
    long long x;
    long long y;
};

struct DanniZaPosokata{
    long long deltaX;
    long long deltaY;
};

vector<DanniZaTochka> tochki;

DanniZaPosokata novaPromenenaPosoka(DanniZaPosokata dosegashna, char znak){
    DanniZaPosokata novaPosoka;

    if(znak == '+'){
        if(dosegashna.deltaX == 1 && dosegashna.deltaY == 0){
            novaPosoka = {0, 1};
        }else{
            if(dosegashna.deltaX == -1 && dosegashna.deltaY == 0){
                novaPosoka = {0, -1};
            }else{
                if(dosegashna.deltaX == 0 && dosegashna.deltaY == 1){
                    novaPosoka = {-1, 0};
                }else{
                    novaPosoka = {1, 0};
                }
            }
        }
    }else{
        if(dosegashna.deltaX == 1 && dosegashna.deltaY == 0){
            novaPosoka = {0, -1};
        }else{
            if(dosegashna.deltaX == -1 && dosegashna.deltaY == 0){
                novaPosoka = {0, 1};
            }else{
                if(dosegashna.deltaX == 0 && dosegashna.deltaY == 1){
                    novaPosoka = {1, 0};
                }else{
                    novaPosoka = {-1, 0};
                }
            }
        }
    }

    return novaPosoka;
}

long long liceto(){
    long long lice = 0;

    long long broiTochki = tochki.size();

    long long segTochka = broiTochki - 1;

    for(long long i = 0; i < broiTochki; i++){
        lice += (tochki[segTochka].x - tochki[i].x)*(tochki[segTochka].y);
        segTochka = i;
    }

    return lice;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string vhod;

    cin>>vhod;

    long long tekushtX = 0;
    long long tekushtY = 0;

    tochki.push_back({0, 0});

    DanniZaPosokata tekushtaPosoka = {1, 0};

    long long chisloto = 0;

    for(unsigned int i = 0; i < vhod.size(); i++){
        if(vhod[i] == '+' || vhod[i] == '-'){
            tekushtX = tekushtX + tekushtaPosoka.deltaX*chisloto;
            tekushtY = tekushtY + tekushtaPosoka.deltaY*chisloto;
            tochki.push_back({tekushtX, tekushtY});
            chisloto = 0;
            tekushtaPosoka = novaPromenenaPosoka(tekushtaPosoka, vhod[i]);
        }else{
            chisloto = 10*chisloto + (vhod[i] - '0');
        }
    }

    long long liceNaMnogoagalnika = liceto();

    cout<<abs(liceNaMnogoagalnika)<<endl;

    return 0;
}
