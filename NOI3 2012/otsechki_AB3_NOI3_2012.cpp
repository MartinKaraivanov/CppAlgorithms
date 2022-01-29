#include<iostream>
using namespace std;

long long a;
long long b;
long long c;
long long m;
long long n;

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
    cin>>a>>b>>c>>m>>n;

    long long purvotoIzvestno = b - a;
    long long vtorotoIzvestno = c - a;
    long long rezultat = n - a*m;

    DanniZaVrashtaneto noda = razshirenEvklid(purvotoIzvestno, vtorotoIzvestno);

    if(rezultat%(noda.nod) != 0){
        cout<<0<<endl;
        return 0;
    }

    long long y0 = noda.x * (rezultat/noda.nod);
    long long z0 = noda.y * (rezultat/noda.nod);

    long long d = vtorotoIzvestno/noda.nod;
    long long e = purvotoIzvestno/noda.nod;

    //cout<<"ot evklida: x "<<noda.nod<<" y "<<noda.y<<" nod "<<noda.nod<<endl;

    //cout<<purvotoIzvestno<<" "<<vtorotoIzvestno<<" "<<rezultat<<endl;

    y0 = y0%d;

    if(y0 < 0){
        y0 += d;
    }

    z0 = (rezultat - purvotoIzvestno*y0)/vtorotoIzvestno;

    long long parvotoK = (m - y0 - z0)/(d - e);

    //cout<<"d: "<<d<<" e: "<<e<<endl;

    //cout<<y0<<" "<<z0<<endl;

    //cout<<"nai malkiq y:  x "<<m - y0 - z0<<" y "<<y0<<" z "<<z0<<endl;

    long long zDrug = z0%e;

    if(zDrug < 0){
        zDrug += e;
    }

    long long yDrug = (rezultat - vtorotoIzvestno*zDrug)/purvotoIzvestno;

    //cout<<"nai malkiq z:  x "<<m - yDrug - zDrug<<" y "<<yDrug<<" z "<<zDrug<<endl;

    long long vtorotoK = (yDrug - y0)/(d);

    //cout<<parvotoK<<" "<<vtorotoK<<endl;

    long long broiNachini = min(parvotoK, vtorotoK) + 1;

    cout<<broiNachini<<endl;

    return 0;
}
