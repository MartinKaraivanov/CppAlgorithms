#include<iostream>
#include<cmath>
using namespace std;

const long long mnogo = 1000000000000000000;

long long malakSkok;
long long golqmSkok;

long long poziciqZaek;

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

void smeniReshenieto(long long& x, long long &y, long long a, long long b, long long broi){
    x += broi*b;
    y -= broi*a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>malakSkok>>golqmSkok>>poziciqZaek;

    DanniZaVrashtaneto noda = razshirenEvklid(malakSkok, golqmSkok);

    if(poziciqZaek % noda.nod != 0){
        cout<<"Impossible"<<endl;
        return 0;
    }

    long long x0 = noda.x * (poziciqZaek/noda.nod);
    long long y0 = noda.y * (poziciqZaek/noda.nod);

    //cout<<x0<<" "<<y0<<endl;

    long long d = golqmSkok/noda.nod;
    long long e = malakSkok/noda.nod;

    x0 = x0%d;

    if(x0 < 0){
        x0 += d;
    }

    y0 = (poziciqZaek - malakSkok*x0)/golqmSkok;

    //cout<<x0<<" "<<y0<<endl;

    long long xMinus1 = x0 - d;
    long long yMinus1 = (poziciqZaek - malakSkok*xMinus1)/golqmSkok;

    //cout<<xMinus1<<" "<<yMinus1<<endl;

    long long drugY0 = y0%e;

    if(drugY0 < 0){
        drugY0 += e;
    }

    long long drugYMinus1 = drugY0 - e;
    long long drugXMinus1 = (poziciqZaek - golqmSkok*drugYMinus1)/malakSkok;

    long long otg0 = abs(x0) + abs(y0);
    long long otg1 = abs(xMinus1) + abs(yMinus1);
    long long otg2 = abs(drugXMinus1) + abs(drugYMinus1);

    cout<<min(otg0, min(otg1, otg2))<<endl;

    return 0;
}
