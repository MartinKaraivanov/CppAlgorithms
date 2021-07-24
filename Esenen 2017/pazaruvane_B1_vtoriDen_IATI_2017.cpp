#include<iostream>
using namespace std;

struct DanniZaVrashtane{
    long long broiOtParviq;
    long long broiOtVtoriq;
    long long novNod;
};

long long broiTestove;
long long broiPredmeti;

long long ceni[10005];

long long cenaZaPravene;

long long otgovori[10005];

long long nod(long long a, long long b){
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

DanniZaVrashtane extended_euclid(long long a, long long b){
    long long x1;
    long long y1;
    long long d;

    long long chastno;
    long long ostatuk;
    long long t;

    x1 = 1;
    y1 = 0;
    long long x2 = 0;
    long long y2 = 1;

    while (b != 0){
        chastno = a/ b;
        ostatuk = a % b;

        a=b;
        b=ostatuk;

        t=x2;
        x2=x1-chastno*x2;
        x1=t;

        t=y2;
        y2=y1-chastno*y2;
        y1=t;
    }
    d=a;

    return {x1, y1, d};
 }

int main(){
    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>broiPredmeti;

        for(int i = 0; i < broiPredmeti; i++){
            cin>>ceni[i];
        }

        cin>>cenaZaPravene;

        DanniZaVrashtane parvoVrasht = extended_euclid(ceni[0], ceni[1]);

        long long broiEdno = parvoVrasht.broiOtParviq;
        long long broiDve = parvoVrasht.broiOtVtoriq;
        long long naiGolqmOD = parvoVrasht.novNod;

        long long x0 = broiEdno*cenaZaPravene;
        long long y0 = broiDve*cenaZaPravene;

        //long long umnozhenBroi = broiEdno*broiDve;

        //cout<<x0<<" "<<y0<<" ";

        otgovori[0] = x0;
        otgovori[1] = y0;

        for(int i = 2; i < broiPredmeti; i++){
            DanniZaVrashtane vrasht = extended_euclid(naiGolqmOD, ceni[i]);

            long long novBroi = vrasht.broiOtVtoriq;
            long long novNOD = vrasht.novNod;
            //cout<<novBroi*cenaZaPravene<<" ";

            otgovori[i] = novBroi*cenaZaPravene;
            naiGolqmOD = novNOD;
        }

        /*if(cenaZaPravene % naiGolqmOD != 0){
            cout<<"No solutions"<<endl;
            continue;
        }*/

        if(cenaZaPravene % naiGolqmOD != 0){
            cout<<"No solutions"<<endl;
            continue;
        }

        for(int i = 0; i < broiPredmeti; i++){
            cout<<otgovori[i]<<" ";
        }

        cout<<endl;

    }

    return 0;
}
