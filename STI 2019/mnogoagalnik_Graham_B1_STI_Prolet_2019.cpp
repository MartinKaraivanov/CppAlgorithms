#include<iostream>
#include<iomanip>
#include<cmath>
#include<stack>
#include<stdlib.h>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiTochki;

DanniZaTochka tochki[1000005];

DanniZaTochka nachalnataTochka;

int broiVzeti;
DanniZaTochka vzetiTochki[1000005];

DanniZaTochka vtorataVStacka(stack<DanniZaTochka> &s){
    DanniZaTochka naiOtgore = s.top();
    s.pop();
    DanniZaTochka vtorataNaiOtgore = s.top();
    s.push(naiOtgore);

    return vtorataNaiOtgore;
}

int distanciqnaKvadrat(DanniZaTochka parva, DanniZaTochka vtora){
    return (parva.x - vtora.x)*(parva.x - vtora.x) + (parva.y - vtora.y)*(parva.y - vtora.y);
}

int orientaciq(DanniZaTochka p, DanniZaTochka q, DanniZaTochka r){
    int stoinost = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if(stoinost == 0){
        return 0;
    }

    if(stoinost > 0){
        return 1;
    }

    return 2;
}

int sravnqvaneNaTochki(const void *vParva, const void *vVtora){

    DanniZaTochka *parva = (DanniZaTochka *)vParva;
    DanniZaTochka *vtora = (DanniZaTochka *)vVtora;

    int ornt = orientaciq(nachalnataTochka, *parva, *vtora);
    if(ornt == 0){
        if(distanciqnaKvadrat(nachalnataTochka, *vtora) >= distanciqnaKvadrat(nachalnataTochka, *parva)){
            return -1;
        }else{
            return 1;
        }
    }

    if(ornt == 2){
        return -1;
    }

    return 1;
}

void praveneNaMnogoagalnika(){
    int startovaTochka = -1;

    DanniZaTochka naiLqvaTochka = {10001, 10001};

    for(int i = 0; i < broiTochki; i++){
        if(tochki[i].x < naiLqvaTochka.x || (tochki[i].x == naiLqvaTochka.x && tochki[i].y < naiLqvaTochka.y)){
            startovaTochka = i;
            naiLqvaTochka = tochki[i];
        }
    }

    swap(tochki[startovaTochka], tochki[0]);

    nachalnataTochka = tochki[0];

    qsort(&tochki[1], broiTochki - 1, sizeof(DanniZaTochka), sravnqvaneNaTochki);

    int novRazmer = 1;

    for(int i = 1; i < broiTochki; i++){
        while(i < broiTochki - 1 && orientaciq(nachalnataTochka, tochki[i], tochki[i + 1]) == 0){
            i++;
        }

        tochki[novRazmer] = tochki[i];
        novRazmer++;
    }

    stack<DanniZaTochka> s;
    s.push(tochki[0]);
    s.push(tochki[1]);
    s.push(tochki[2]);

    for(int i = 3; i < novRazmer; i++){
        while(s.size() > 1 && orientaciq(vtorataVStacka(s), s.top(), tochki[i]) != 2){
            s.pop();
        }

        s.push(tochki[i]);
    }

    stack<DanniZaTochka> obratnoTochki;

    while(s.empty() == false){
        obratnoTochki.push(s.top());
        s.pop();
    }

    while(obratnoTochki.empty() == false){
        vzetiTochki[broiVzeti] = obratnoTochki.top();
        broiVzeti++;
        obratnoTochki.pop();
    }
}

int liceNaTrapecSTeziTochki(DanniZaTochka parva, DanniZaTochka vtora){
    int lice = (parva.y + vtora.y)*(parva.x - vtora.x);

    return lice;
}

double izchislqvaneNaLice(){
    int parvaTochka = 0;
    int vtoraTochka = 1;

    long long lice = 0;

    while(parvaTochka < broiVzeti){
        int segashnoLice =
            liceNaTrapecSTeziTochki(vzetiTochki[parvaTochka], vzetiTochki[vtoraTochka]);
        lice += segashnoLice;
        parvaTochka++;
        vtoraTochka++;
        if(vtoraTochka >= broiVzeti){
            vtoraTochka = 0;
        }
    }

    double liceZaIzvezhdane = (double)abs(lice);

    return liceZaIzvezhdane / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vavezhdashtX;
    while(cin>>vavezhdashtX){
        int vavezhdashtY;
        cin>>vavezhdashtY;

        tochki[broiTochki] = {vavezhdashtX, vavezhdashtY};
        broiTochki++;
    }

    praveneNaMnogoagalnika();

    double liceto = izchislqvaneNaLice();

    if(abs(round(liceto) - liceto) < 0.000001){
        cout<<fixed<<setprecision(0);
    }else{
        cout<<fixed<<setprecision(1);
    }

    cout<<liceto<<endl;

    return 0;
}
