#include<iostream>
#include<cmath>
using namespace std;

struct danniZaTochka{
    double x;
    double y;
};

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
    danniZaTochka a;
    danniZaTochka b;
    danniZaTochka c;

    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;

    double otgovor = licesTeziTochki(a, b, c);

    cout<<otgovor<<endl;

    return 0;
}
