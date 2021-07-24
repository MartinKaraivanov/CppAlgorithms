#include<iostream>
using namespace std;

struct DanniZaPrava{
    int a;
    int b;
    int c;
};

struct DanniZaTochka{
    int x;
    int y;
};

DanniZaTochka ediniqKraiNaNachalnata;
DanniZaTochka drugiqKraiNaNachalnata;

DanniZaPrava pravaNaNachalnata;

int aKoordinatno;
int bKoordinatno;

bool imameLiSTakavaDulzhina[5010];
int broiRazlichniDalzhini;
int broiPerpendikuliarni;

DanniZaPrava pravataNaDveteTochki(DanniZaTochka tochka1, DanniZaTochka tochka2){
    int a = tochka1.y - tochka2.y;
    int b = tochka2.x - tochka1.x;
    int c = tochka1.x*tochka2.y - tochka2.x*tochka1.y;

    DanniZaPrava zaVrasht = {a, b, c};

    return zaVrasht;
}

int dalzhinataNaVtoraStepen(DanniZaTochka tochka1, DanniZaTochka tochka2){
    return (tochka1.x - tochka2.x)*(tochka1.x - tochka2.x) + (tochka1.y - tochka2.y)*(tochka1.y - tochka2.y);
}

bool dvetePraviPerpendikuliarniLiSa(DanniZaPrava parva, DanniZaPrava vtora){
    return parva.a*vtora.a == -parva.b*vtora.b;
}

int main(){
    cin>>ediniqKraiNaNachalnata.x>>ediniqKraiNaNachalnata.y>>drugiqKraiNaNachalnata.x>>drugiqKraiNaNachalnata.y;
    cin>>aKoordinatno>>bKoordinatno;

    pravaNaNachalnata = pravataNaDveteTochki(ediniqKraiNaNachalnata, drugiqKraiNaNachalnata);

    for(int x1 = 1; x1 < aKoordinatno; x1++){
        for(int y1 = 1; y1 < bKoordinatno; y1++){
            for(int x2 = 1; x2 < aKoordinatno; x2++){
                for(int y2 = 1; y2 < bKoordinatno; y2++){
                    if(x1 != x2 || y1 != y2){
                        DanniZaPrava dopalnitenaPrava = pravataNaDveteTochki({x1, y1}, {x2, y2});

                        if(dvetePraviPerpendikuliarniLiSa(pravaNaNachalnata, dopalnitenaPrava) == true){
                            broiPerpendikuliarni++;
                            int dalzhina = dalzhinataNaVtoraStepen({x1, y1}, {x2, y2});
                            if(imameLiSTakavaDulzhina[dalzhina] == false){
                                imameLiSTakavaDulzhina[dalzhina] = true;
                                broiRazlichniDalzhini++;
                            }
                        }

                    }
                }
            }
        }
    }

    cout<<broiPerpendikuliarni/2<<" "<<broiRazlichniDalzhini<<endl;

    return 0;
}
