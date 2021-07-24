#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct danniZaTochka{
    double x;
    double y;
};

int broiVarhove;

int broiTestove;

int otgovori[100000];

danniZaTochka varhove[100000];

double licesTeziTochki(danniZaTochka a, danniZaTochka b, danniZaTochka c){
    double x1 = a.x;
    double y1 = a.y;

    double x2 = b.x;
    double y2 = b.y;

    double x3 = c.x;
    double y3 = c.y;

    double lice1 = abs(x1 - x2) * abs(y1 - y2) / 2;
    double lice2 = abs(x1 - x3) * abs(y1 - y3) / 2;
    double lice3 = abs(x2 - x3) * abs(y2 - y3) / 2;

    double pravoagalnoLice = abs(max(max(x1, x2), x3) - min(min(x1, x2), x3)) * abs(max(max(y1, y2), y3) - min(min(y1, y2), y3));

    double sborNaTriteLica = lice1+lice2+lice3;

    double otgovor = pravoagalnoLice - sborNaTriteLica;

    return otgovor;
}

double liceNaMnogoagalnik(int nachalnaTochka, int poslednaTochka){
    int zabuchen = nachalnaTochka;

    int parvaTochka = nachalnaTochka+1;
    int vtoraTchka = nachalnaTochka+2;

    double lichice = 0.0;

    while(vtoraTchka <= poslednaTochka){
        lichice += licesTeziTochki(varhove[zabuchen], varhove[parvaTochka], varhove[vtoraTchka]);
        parvaTochka++;
        vtoraTchka++;
    }

    return lichice;
}

int main(){
    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>broiVarhove;

        for(int i = 0; i < broiVarhove; i++){
            danniZaTochka a;
            cin>>a.x>>a.y;
            varhove[i].x = a.x;
            varhove[i].y = a.y;
        }

        double liceNaCeliq = liceNaMnogoagalnik(0, broiVarhove - 1);

        int cqlaChasta = liceNaCeliq;

        if(liceNaCeliq - cqlaChasta > 0.0000001){
            otgovori[t] = 0;
            continue;
        }

        int broiDiagRazdCC = 0;

        for(int parvaTochka = 0; parvaTochka < broiVarhove; parvaTochka++){
            for(int vtoraTochka = parvaTochka + 2; vtoraTochka < broiVarhove; vtoraTochka++){
                if(parvaTochka + vtoraTochka + 1 == broiVarhove){
                    continue;
                }
                double lichice = liceNaMnogoagalnik(parvaTochka, vtoraTochka);
                int cqloLichice = lichice;
                if(lichice - cqloLichice < 0.0000001){
                    broiDiagRazdCC++;
                    //cout<<parvaTochka<<" "<<vtoraTochka<<endl;
                }
            }
        }

        otgovori[t] = broiDiagRazdCC;
    }

    for(int i = 0; i < broiTestove; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
