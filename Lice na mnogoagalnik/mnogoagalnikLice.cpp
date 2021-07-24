#include<iostream>
#include<cmath>
using namespace std;

struct danniZaTochka{
    double x;
    double y;
};

int broiVarhove;

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

int main(){
    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove; i++){
        danniZaTochka a;
        cin>>a.x>>a.y;
        varhove[i].x = a.x;
        varhove[i].y = a.y;
    }

    int zabuchen = 0;

    int parvaTochka = 1;
    int vtoraTchka = 2;

    double lichice = 0.0;

    while(vtoraTchka != broiVarhove){
        lichice += licesTeziTochki(varhove[zabuchen], varhove[parvaTochka], varhove[vtoraTchka]);
        parvaTochka++;
        vtoraTchka++;
    }

    cout<<lichice<<endl;

    return 0;
}
