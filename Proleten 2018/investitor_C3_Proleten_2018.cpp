#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaVnoskata{
    long long putiA;
    long long putiB;
};

long long nomerNaVnoskata;
long long pariNaVnoskata;


struct DanniZaVrashtaneto{
    long long nod;
    long long x;
    long long y;
};

DanniZaVrashtaneto razshirenEvklid(long long a, long long b){
    if(a == 0){
        return {b, 0, 1};
    }

    DanniZaVrashtaneto tuka = razshirenEvklid(b%a, a);

    long long xVrashtane = tuka.y - (b/a)*tuka.x;
    long long yVrashtane = tuka.x;

    return {tuka.nod, xVrashtane, yVrashtane};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>nomerNaVnoskata;
    cin>>pariNaVnoskata;

    DanniZaVnoskata poprednata = {1, 0};
    DanniZaVnoskata prednata = {0, 1};

    for(long long i = 3; i <= nomerNaVnoskata; i++){
        DanniZaVnoskata segashnata;
        segashnata.putiA = prednata.putiA + poprednata.putiA;
        segashnata.putiB = prednata.putiB + poprednata.putiB;

        poprednata = prednata;
        prednata = segashnata;
    }

    DanniZaVrashtaneto noda = razshirenEvklid(prednata.putiA, prednata.putiB);

    if(pariNaVnoskata % noda.nod != 0){
        cout<<0<<endl;
        return 0;
    }

    long long x0 = noda.x * (pariNaVnoskata/noda.nod);
    long long y0 = noda.y * (pariNaVnoskata/noda.nod);

    //cout<<x0<<" "<<y0<<endl;

    long long d = prednata.putiB/noda.nod;
    long long e = prednata.putiA/noda.nod;

    //cout<<d<<" "<<e<<endl;

    x0 = x0%d;

    if(x0 <= 0){
        x0 += d;
    }

    y0 = (pariNaVnoskata - prednata.putiA*x0)/prednata.putiB;

    //cout<<"predi "<<x0<<" "<<y0<<endl;

    /*if(x0 <= 0 || y0 <= 0){
        x0 += d;
        y0 -= e;
    }*/

    //cout<<x0<<" "<<y0<<endl;

    long long yDrug = y0%e;

    if(yDrug <= 0){
        yDrug += e;
    }

    long long xDrug = (pariNaVnoskata - prednata.putiB*yDrug)/prednata.putiA;

    //cout<<"predi "<<xDrug<<" "<<yDrug<<endl;

    /*if(yDrug <= 0 || xDrug <= 0){
        yDrug += e;
        xDrug -= d;
    }*/

    //cout<<xDrug<<" "<<yDrug<<endl;

    long long broi = (xDrug - x0)/d + 1;

    cout<<broi<<endl;

    return 0;
}
