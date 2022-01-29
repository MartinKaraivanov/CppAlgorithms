#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

const double kraenX = 100;

struct Koordinati{
    double x;
    double y;
};

double daljinaNaOtsechka(Koordinati a, Koordinati b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Koordinati parvaTochka;
Koordinati vtoraTochka;
Koordinati tretaTochka;

bool koqEPoNapred(Koordinati a, Koordinati b){
    return a.y > b.y;
}

void opraviTochkite(){

    Koordinati tochkite[3];
    tochkite[0] = parvaTochka;
    tochkite[1] = vtoraTochka;
    tochkite[2] = tretaTochka;

    sort(tochkite, tochkite + 3, koqEPoNapred);

    parvaTochka = tochkite[0];
    vtoraTochka = tochkite[1];
    tretaTochka = tochkite[2];
}

double daljinaDoNeopredleenata(Koordinati otKoq, double visochina){
    return visochina + (kraenX - otKoq.x);
}


int main(){

    cin>>parvaTochka.x>>parvaTochka.y;
    cin>>vtoraTochka.x>>vtoraTochka.y;
    cin>>tretaTochka.x>>tretaTochka.y;

    double ednaStrana = daljinaNaOtsechka(parvaTochka, vtoraTochka);
    double vtoraStrana = daljinaNaOtsechka(vtoraTochka, tretaTochka);
    double tretaStrana = daljinaNaOtsechka(tretaTochka, parvaTochka);

    double poluperimetar = (ednaStrana + vtoraStrana + tretaStrana)/2;

    double lice = sqrt(poluperimetar*(poluperimetar - ednaStrana)*(poluperimetar - vtoraStrana)*(poluperimetar - tretaStrana));

    double okoloKoyY1 = 0;
    double okoloKoyY2 = 0;

    double naiMalkotoRazst = 1000000007;

    Koordinati priNaiMalkParva;
    Koordinati priNaiMalkVtora;
    Koordinati priNaiMalkTreta;

    for(double y1 = 100; y1 > 0; y1 -= 0.1){
        for(double y2 = y1; y2 > 0; y2 -= 0.1){
            double tukaStranata = daljinaNaOtsechka({kraenX, y1}, {kraenX, y2});

            Koordinati gornaTochka = {kraenX, y1};
            Koordinati dolnaTochka = {kraenX, y2};

            double visochina = 2*lice/tukaStranata;

            double parviVariant = daljinaNaOtsechka(parvaTochka, gornaTochka) + daljinaNaOtsechka(tretaTochka, dolnaTochka) + daljinaDoNeopredleenata(vtoraTochka, visochina);

            if(parviVariant < naiMalkotoRazst){
                naiMalkotoRazst = parviVariant;
                priNaiMalkParva = gornaTochka;
                priNaiMalkVtora = {kraenX + visochina, vtoraTochka.y};
                priNaiMalkTreta = dolnaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double vtoriVariant = daljinaNaOtsechka(parvaTochka, gornaTochka) + daljinaNaOtsechka(vtoraTochka, dolnaTochka) + daljinaDoNeopredleenata(tretaTochka, visochina);

            if(vtoriVariant < naiMalkotoRazst){
                naiMalkotoRazst = vtoriVariant;
                priNaiMalkParva = gornaTochka;
                priNaiMalkVtora = dolnaTochka;
                priNaiMalkTreta = {kraenX + visochina, tretaTochka.y};
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double tretiVariant = daljinaNaOtsechka(vtoraTochka, gornaTochka) + daljinaNaOtsechka(parvaTochka, dolnaTochka) + daljinaDoNeopredleenata(tretaTochka, visochina);

            if(tretiVariant < naiMalkotoRazst){
                naiMalkotoRazst = tretiVariant;
                priNaiMalkParva = dolnaTochka;
                priNaiMalkVtora = gornaTochka;
                priNaiMalkTreta = {kraenX + visochina, tretaTochka.y};
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double chetvartiVariant = daljinaNaOtsechka(vtoraTochka, gornaTochka) + daljinaNaOtsechka(tretaTochka, dolnaTochka) + daljinaDoNeopredleenata(parvaTochka, visochina);

            if(chetvartiVariant < naiMalkotoRazst){
                naiMalkotoRazst = chetvartiVariant;
                priNaiMalkParva = {kraenX + visochina, parvaTochka.y};
                priNaiMalkVtora = gornaTochka;
                priNaiMalkTreta = dolnaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double petiVariant = daljinaNaOtsechka(tretaTochka, gornaTochka) + daljinaNaOtsechka(parvaTochka, dolnaTochka) + daljinaDoNeopredleenata(vtoraTochka, visochina);

            if(petiVariant < naiMalkotoRazst){
                naiMalkotoRazst = petiVariant;
                priNaiMalkParva = dolnaTochka;
                priNaiMalkVtora = {kraenX + visochina, vtoraTochka.y};
                priNaiMalkTreta = gornaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double shestiVariant = daljinaNaOtsechka(tretaTochka, gornaTochka) + daljinaNaOtsechka(vtoraTochka, dolnaTochka) + daljinaDoNeopredleenata(parvaTochka, visochina);

            if(shestiVariant < naiMalkotoRazst){
                naiMalkotoRazst = shestiVariant;
                priNaiMalkParva = {kraenX + visochina, parvaTochka.y};
                priNaiMalkVtora = dolnaTochka;
                priNaiMalkTreta = gornaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

        }
    }





    for(double y1 = min(100.0, okoloKoyY1 + 1); y1 > max(0.0, okoloKoyY1 - 1); y1 -= 0.01){
        for(double y2 = min(100.0, okoloKoyY2 + 1); y2 > max(0.0, okoloKoyY2 - 1); y2 -= 0.01){
            double tukaStranata = daljinaNaOtsechka({kraenX, y1}, {kraenX, y2});

            Koordinati gornaTochka = {kraenX, y1};
            Koordinati dolnaTochka = {kraenX, y2};

            double visochina = 2*lice/tukaStranata;

            double parviVariant = daljinaNaOtsechka(parvaTochka, gornaTochka) + daljinaNaOtsechka(tretaTochka, dolnaTochka) + daljinaDoNeopredleenata(vtoraTochka, visochina);

            if(parviVariant < naiMalkotoRazst){
                naiMalkotoRazst = parviVariant;
                priNaiMalkParva = gornaTochka;
                priNaiMalkVtora = {kraenX + visochina, vtoraTochka.y};
                priNaiMalkTreta = dolnaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double vtoriVariant = daljinaNaOtsechka(parvaTochka, gornaTochka) + daljinaNaOtsechka(vtoraTochka, dolnaTochka) + daljinaDoNeopredleenata(tretaTochka, visochina);

            if(vtoriVariant < naiMalkotoRazst){
                naiMalkotoRazst = vtoriVariant;
                priNaiMalkParva = gornaTochka;
                priNaiMalkVtora = dolnaTochka;
                priNaiMalkTreta = {kraenX + visochina, tretaTochka.y};
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double tretiVariant = daljinaNaOtsechka(vtoraTochka, gornaTochka) + daljinaNaOtsechka(parvaTochka, dolnaTochka) + daljinaDoNeopredleenata(tretaTochka, visochina);

            if(tretiVariant < naiMalkotoRazst){
                naiMalkotoRazst = tretiVariant;
                priNaiMalkParva = dolnaTochka;
                priNaiMalkVtora = gornaTochka;
                priNaiMalkTreta = {kraenX + visochina, tretaTochka.y};
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double chetvartiVariant = daljinaNaOtsechka(vtoraTochka, gornaTochka) + daljinaNaOtsechka(tretaTochka, dolnaTochka) + daljinaDoNeopredleenata(parvaTochka, visochina);

            if(chetvartiVariant < naiMalkotoRazst){
                naiMalkotoRazst = chetvartiVariant;
                priNaiMalkParva = {kraenX + visochina, parvaTochka.y};
                priNaiMalkVtora = gornaTochka;
                priNaiMalkTreta = dolnaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double petiVariant = daljinaNaOtsechka(tretaTochka, gornaTochka) + daljinaNaOtsechka(parvaTochka, dolnaTochka) + daljinaDoNeopredleenata(vtoraTochka, visochina);

            if(petiVariant < naiMalkotoRazst){
                naiMalkotoRazst = petiVariant;
                priNaiMalkParva = dolnaTochka;
                priNaiMalkVtora = {kraenX + visochina, vtoraTochka.y};
                priNaiMalkTreta = gornaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

            double shestiVariant = daljinaNaOtsechka(tretaTochka, gornaTochka) + daljinaNaOtsechka(vtoraTochka, dolnaTochka) + daljinaDoNeopredleenata(parvaTochka, visochina);

            if(shestiVariant < naiMalkotoRazst){
                naiMalkotoRazst = shestiVariant;
                priNaiMalkParva = {kraenX + visochina, parvaTochka.y};
                priNaiMalkVtora = dolnaTochka;
                priNaiMalkTreta = gornaTochka;
                okoloKoyY1 = y1;
                okoloKoyY2 = y2;
            }

        }
    }


    cout<<fixed<<setprecision(3)<<priNaiMalkParva.x<<" "<<priNaiMalkParva.y<<endl;
    cout<<fixed<<setprecision(3)<<priNaiMalkVtora.x<<" "<<priNaiMalkVtora.y<<endl;
    cout<<fixed<<setprecision(3)<<priNaiMalkTreta.x<<" "<<priNaiMalkTreta.y<<endl;

    return 0;
}
