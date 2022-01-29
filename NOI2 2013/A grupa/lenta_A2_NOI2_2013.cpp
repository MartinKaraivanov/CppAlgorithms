#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
using namespace std;


struct Koordinati{
    double x;
    double y;
};

struct DanniZaPrava{
    double a;
    double b;
    double c;
};

inline DanniZaPrava pravataNaDveTochki(Koordinati parva, Koordinati vtora){
    double a = parva.y - vtora.y;
    double b = vtora.x - parva.x;
    double c = parva.x*vtora.y - parva.y*vtora.x;

    return {a, b, c};
}

inline Koordinati presechnataTochkaNa(DanniZaPrava parva, DanniZaPrava vtora){
    double x = (vtora.b*parva.c - vtora.c*parva.b)/(vtora.a*parva.b - vtora.b*parva.a);
    double y = (parva.a*vtora.c - parva.c*vtora.a)/(vtora.a*parva.b - vtora.b*parva.a);

    return {x, y};
}

inline double daljinaNaOtsechka(Koordinati a, Koordinati b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

struct DanniZaVrasht{
    double kolkoEDalj;
    double priKakavX;
};

DanniZaVrasht napraviTarseneMejdu(double start, double krai, double stapka, double a, double b, double c){

    double naiGolqmataDaljina = 0;
    double priKoiX = 0;

    for(double x = start; x < krai; x += stapka){
        double y = sqrt(c*c - x*x);

        DanniZaPrava zakovanataPrava = pravataNaDveTochki({x, 0}, {0, y});

        DanniZaPrava perpendikularnaParva = {zakovanataPrava.b, -zakovanataPrava.a, 0};
        DanniZaPrava perpendikularnaVtora = {zakovanataPrava.b, -zakovanataPrava.a, 0};

        perpendikularnaParva.c = 0 - perpendikularnaParva.b*y;
        perpendikularnaVtora.c = 0 - perpendikularnaVtora.a*x;

        DanniZaPrava gornaStrana = pravataNaDveTochki({0, b}, {a, b});
        DanniZaPrava dqsnaStrana = pravataNaDveTochki({a, b}, {a, 0});

        Koordinati gornaPresechnaT = presechnataTochkaNa(perpendikularnaParva, gornaStrana);
        Koordinati srednaPresechna = presechnataTochkaNa(perpendikularnaVtora, gornaStrana);
        Koordinati poslednaPresech = presechnataTochkaNa(perpendikularnaVtora, dqsnaStrana);

        double parvaDaljina = daljinaNaOtsechka({0, y}, gornaPresechnaT);
        double vtoraDaljina = daljinaNaOtsechka({x, 0}, srednaPresechna);
        double tretaDaljina = daljinaNaOtsechka({x, 0}, poslednaPresech);

        double tukaDalj = min(min(parvaDaljina, vtoraDaljina), tretaDaljina);

        //cout<<x<<" "<<tukaDalj<<endl;

        if(tukaDalj > naiGolqmataDaljina){
            priKoiX = x;
        }
        naiGolqmataDaljina = max(naiGolqmataDaljina, tukaDalj);
    }

    return {naiGolqmataDaljina, priKoiX};
}

int main(){

    double a;
    double b;
    double c;

    cin>>a>>b>>c;

    double naiGolqmaDaljina = 0;

    DanniZaVrasht parvonachalno = napraviTarseneMejdu(0, c, 1, a, b, c);

    naiGolqmaDaljina = napraviTarseneMejdu(max(0.0, parvonachalno.priKakavX - 1.1), min(c, parvonachalno.priKakavX + 1.1), 0.00001, a, b, c).kolkoEDalj;

    cout<<fixed<<setprecision(2)<<naiGolqmaDaljina<<endl;

    return 0;
}
