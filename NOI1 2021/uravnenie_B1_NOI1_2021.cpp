#include<iostream>
#include<algorithm>
using namespace std;

long long razshirenEvklid(long long a, long long b, long long& x, long long& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    long long x1;
    long long y1;

    long long d = razshirenEvklid(b, a%b, x1, y1);

    x = y1;
    y = x1 - y1*(a/b);

    return d;
}

long long broiTestove;

struct DanniZaRazlikata{
    long long razlika;
    long long originalenX;
};

bool koeEPoNapred(DanniZaRazlikata a, DanniZaRazlikata b){
    if(a.razlika < b.razlika){
        return true;
    }
    if(a.razlika > b.razlika){
        return false;
    }
    return a.originalenX > b.originalenX;
}

long long naiBlizkiqX(long long edin, long long vtori, long long treti, long long p){

    long long razlikataSParviq = abs(p - edin);
    long long razlikataSVtoriq = abs(p - vtori);
    long long razlikataSTretiq = abs(p - treti);

    DanniZaRazlikata razlikite[3];

    razlikite[0] = {razlikataSParviq, edin};
    razlikite[1] = {razlikataSVtoriq, vtori};
    razlikite[2] = {razlikataSTretiq, treti};

    sort(razlikite, razlikite + 3, koeEPoNapred);

    return razlikite[0].originalenX;
}

int main(){

    cin>>broiTestove;

    for(long long t = 0; t < broiTestove; t++){
        long long a;
        long long b;
        long long c;
        long long p;

        cin>>a>>b>>c>>p;

        long long x0;
        long long y0;

        long long nod = razshirenEvklid(a, b, x0, y0);

        if(c%nod != 0){
            cout<<0<<" "<<0<<endl;
            continue;
        }

        x0 *= c/nod;
        y0 *= c/nod;

        long long nqkvoH = (p - x0)/(b/nod);

        long long ediniqX = x0 + nqkvoH*(b/nod);
        long long drugiqX = x0 + (nqkvoH + 1)*(b/nod);
        long long tretiqX = x0 + (nqkvoH - 1)*(b/nod);

        long long xOtg = naiBlizkiqX(ediniqX, drugiqX, tretiqX, p);
        long long yOtg = (c - a*xOtg)/b;

        cout<<xOtg<<" "<<yOtg<<endl;
    }


    return 0;
}
