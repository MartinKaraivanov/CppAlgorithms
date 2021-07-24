#include<iostream>
#include<queue>
using namespace std;

struct DanniZaTochkata{
    int x;
    int y;
};

struct DanniDoubleTochka{
    double x;
    double y;
};

struct DanniZaOtsechkata{
    DanniZaTochkata parvaTochka;
    DanniZaTochkata vtoraTochka;
};

struct DanniZaPrava{
    int a;
    int b;
    int c;

    // ako ni triabva map<prava>
    bool operator<(const DanniZaPrava& rhs) const
    {
        if (a < rhs.a)
        {
           return true;
        }
        else if (a == rhs.a)
        {
            if (b < rhs.b)
            {
                return true;
            }
            else if (b == rhs.b)
            {
                return c < rhs.c;
            }
        }

        return false;
    }
};

int naiGolqmObshtDelitel(int a, int b){
    while(b != 0){
        int p = b;
        b = a%b;
        a = p;
    }
    return a;
}

/// dve tochki da vrashta prava

DanniZaPrava pravataNaDveteTochki(DanniZaTochkata tochka1, DanniZaTochkata tochka2){
    int a = tochka1.y - tochka2.y;
    int b = tochka2.x - tochka1.x;
    int c = tochka1.x*tochka2.y - tochka2.x*tochka1.y;

    // ako shte polzvame map<prava>
    int nodNaAiB = naiGolqmObshtDelitel(a, b);
    int nodNaVsichki = naiGolqmObshtDelitel(nodNaAiB, c);

    a/=nodNaVsichki;
    b/=nodNaVsichki;
    c/=nodNaVsichki;

    DanniZaPrava zaVrasht = {a, b, c};

    return zaVrasht;
}

//tochka i prava dali tochkata e

bool tochkataOtPravataLiE(DanniZaPrava p, DanniZaTochkata t){
    int suma = p.a*t.x+p.b*t.y+p.c;
    if(suma == 0){
        return true;
    }else{
        return false;
    }
}

bool dvePraviPresichatLiSe(DanniZaPrava parva, DanniZaPrava vtora){
    int sumichka = vtora.a*parva.b - parva.a*vtora.b;

    return sumichka != 0;
}

DanniDoubleTochka presechnaTochkaNaPravi(DanniZaPrava parva, DanniZaPrava vtora){
    double a1 = parva.a;
    double b1 = parva.b;
    double c1 = parva.c;
    double a2 = vtora.a;
    double b2 = vtora.b;
    double c2 = vtora.c;

    double x = (b2*c1 - b1*c2)/(a2*b1 - a1*b2);
    double y = (a1*c2 - a2*c1)/(a2*b1 - a1*b2);

    DanniDoubleTochka zaVrashtane = {x, y};

    return zaVrashtane;
}

bool imatLiContact(DanniZaOtsechkata parva, DanniZaOtsechkata vtora){

    DanniZaPrava pravatNaParvataOtsechka = pravataNaDveteTochki(parva.parvaTochka, parva.vtoraTochka);
    DanniZaPrava pravatNaVtorataOtsechka = pravataNaDveteTochki(vtora.parvaTochka, vtora.vtoraTochka);

    if(dvePraviPresichatLiSe(pravatNaParvataOtsechka, pravatNaVtorataOtsechka) == false){
        return false;
    }

    DanniDoubleTochka presTochkaNaDvetePravi = presechnaTochkaNaPravi(pravatNaParvataOtsechka, pravatNaVtorataOtsechka);

    bool otParvataOtsechkaLiE = false;
    bool otVtorataOtsechkaLiE = false;

    if((presTochkaNaDvetePravi.x >= min(parva.parvaTochka.x, parva.vtoraTochka.x) &&
        (presTochkaNaDvetePravi.x <= max(parva.parvaTochka.x, parva.vtoraTochka.x)) &&
        (presTochkaNaDvetePravi.y >= min(parva.parvaTochka.y, parva.vtoraTochka.y)) &&
        (presTochkaNaDvetePravi.y <= max(parva.parvaTochka.y, parva.vtoraTochka.y))))
    {
        otParvataOtsechkaLiE = true;
    }

    if((presTochkaNaDvetePravi.x >= min(vtora.parvaTochka.x, vtora.vtoraTochka.x) &&
        (presTochkaNaDvetePravi.x <= max(vtora.parvaTochka.x, vtora.vtoraTochka.x)) &&
        (presTochkaNaDvetePravi.y >= min(vtora.parvaTochka.y, vtora.vtoraTochka.y)) &&
        (presTochkaNaDvetePravi.y <= max(vtora.parvaTochka.y, vtora.vtoraTochka.y))))
    {
        otVtorataOtsechkaLiE = true;
    }

    return otParvataOtsechkaLiE && otVtorataOtsechkaLiE;
}


DanniZaOtsechkata otsechki[1050];
int broiOtsechki;

bool visited[1050];
int broiPoseteni;

int main(){
    int chi;

    while(cin>>chi){
        otsechki[broiOtsechki].parvaTochka.x = chi;
        cin>>otsechki[broiOtsechki].parvaTochka.y;
        cin>>otsechki[broiOtsechki].vtoraTochka.x;
        cin>>otsechki[broiOtsechki].vtoraTochka.y;
        broiOtsechki++;

    }

    queue<int> q;

    q.push(broiOtsechki - 1);

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        if(visited[naiOtpred] == false){
            visited[naiOtpred] = true;
            broiPoseteni++;
        }else{
            continue;
        }

        for(int i = 0; i < broiOtsechki; i++){
            if(i == naiOtpred){
                continue;
            }
            if(visited[i] == false){
                if(imatLiContact(otsechki[naiOtpred], otsechki[i]) == true){
                    q.push(i);
                }
            }
        }
    }

    cout<<broiOtsechki - broiPoseteni<<endl;

    return 0;
}
