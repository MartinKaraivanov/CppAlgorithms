#include<iostream>
#include<cmath>
#include<map>
using namespace std;

struct DanniZaTochkata{
    int x;
    int y;
};

struct DanniZaPrava{
    int a;
    int b;
    int c;

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

int broiTochki;

DanniZaTochkata tochki[1010];

//map<DanniZaPrava, int> pravatKolkoPatiQIma;

bool ravniLiSa(int a, int b){
    if(abs(a - b) < 0.00001){
        return true;
    }
    return false;
}

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

    int nodNaAiB = naiGolqmObshtDelitel(a, b);
    int nodNaVsichki = naiGolqmObshtDelitel(nodNaAiB, c);

    a/=nodNaVsichki;
    b/=nodNaVsichki;
    c/=nodNaVsichki;

    DanniZaPrava zaVrasht = {a, b, c};

    return zaVrasht;
}

///tochka i prava dali tochkata e

bool tochkataOtPravataLiE(DanniZaPrava p, DanniZaTochkata t){
    int suma = p.a*t.x+p.b*t.y+p.c;
    if(suma == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    int naiMnogoNaEdnaPrava = 0;

    for(int i = 0; i < broiTochki; i++){
        map<DanniZaPrava, int> pravatKolkoPatiQIma;


        for(int j = i + 1; j < broiTochki; j++){
            DanniZaPrava prava = pravataNaDveteTochki(tochki[i], tochki[j]);

            pravatKolkoPatiQIma[prava]++;
        }

        int naiMnogoVMapa = 0;
        for(map<DanniZaPrava, int>::iterator mivka = pravatKolkoPatiQIma.begin(); mivka != pravatKolkoPatiQIma.end(); mivka++){
            if(mivka->second > naiMnogoVMapa){
                naiMnogoVMapa = mivka->second;
            }
        }

        if(naiMnogoVMapa > naiMnogoNaEdnaPrava){
            naiMnogoNaEdnaPrava = naiMnogoVMapa;
        }
    }

    cout<<naiMnogoNaEdnaPrava + 1<<endl;


    return 0;
}
