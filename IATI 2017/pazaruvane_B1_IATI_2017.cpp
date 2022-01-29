#include<iostream>
#include<vector>
using namespace std;

int broiTestove;

int broiStoki;
vector<long long> ceni;

long long sumaZaPravene;

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

struct DanniZaReshenieto{
    vector<long long> x;
    vector<long long> y;
};

DanniZaReshenieto nameriReshenie(long long a, long long b, long long c){
    DanniZaVrashtaneto noda = razshirenEvklid(a, b);

    return {{noda.x, (c/noda.nod)}, {noda.y, (c/noda.nod)}};
}

int main(){
    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>broiStoki;

        for(int i = 0; i < broiStoki; i++){
            long long tuka;
            cin>>tuka;

            ceni.push_back(tuka);
        }

        cin>>sumaZaPravene;

        vector<long long> nodove;

        long long predno = ceni[0];

        for(int i = 0; i < broiStoki; i++){
            nodove.push_back(razshirenEvklid(predno, ceni[i]).nod);
            predno = nodove[i];
        }

        if(sumaZaPravene%nodove[broiStoki - 1] != 0){
            cout<<"No solutions"<<endl;
        }else{

            vector<vector<long long>> otgovori;

            long long naKolkoERavno = sumaZaPravene;

            for(int i = broiStoki - 1; i >= 1; i--){
                long long noda = nodove[i - 1];
                long long tukCena = ceni[i];

                DanniZaReshenieto tukReshenie = nameriReshenie(noda, tukCena, naKolkoERavno);

                otgovori.push_back(tukReshenie.y);

                naKolkoERavno = noda*tukReshenie.x[0]*tukReshenie.x[1];
                if(i == 1){
                    otgovori.push_back(tukReshenie.x);
                }
            }

            while(otgovori.size() > 0){
                vector<long long> otgTuk = otgovori.back();
                otgovori.pop_back();

                for(int i = 0; i < (int)otgTuk.size() - 1; i++){
                    cout<<otgTuk[i]<<"*";
                }
                cout<<otgTuk.back()<<" ";
            }

            cout<<endl;
        }

        ceni.clear();
    }

    return 0;
}
