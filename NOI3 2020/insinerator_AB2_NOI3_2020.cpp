#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct DanniZaTochka{
    double x;
    double y;
};

struct DanniZaOkrazhnost{
    DanniZaTochka centur;
    double radius;
};

struct OtgovoriNaKvadratnoUravnenie{
    double purvi;
    double vtori;
};

int broiOkrazhnosti;

DanniZaOkrazhnost okrazshnosti[105];

DanniZaOkrazhnost okrazhnostOtTakavaKrainaTochkaIDrugaOkr(double x, double y, DanniZaOkrazhnost okrazhnost){
    double razlikaVX = x - okrazhnost.centur.x;
    double razlikaVY = y - okrazhnost.centur.y;

    double edniqPlusDrugiqRadius = sqrt(razlikaVX*razlikaVX + razlikaVY*razlikaVY);

    double nashiqRadius = edniqPlusDrugiqRadius - okrazhnost.radius;

    DanniZaOkrazhnost novataNiOkrazhnost = {{x, y}, nashiqRadius};

    return novataNiOkrazhnost;
}

bool tochkataVOkrazhnosttaLiE(DanniZaTochka tochka, DanniZaOkrazhnost okr){
    double naVtoraStepen =
        (tochka.x - okr.centur.x)*(tochka.x - okr.centur.x) + (tochka.y - okr.centur.y)*(tochka.y - okr.centur.y);

    double radiusaNaVtora = okr.radius * okr.radius;

    if(radiusaNaVtora - naVtoraStepen > 0.0000001){
        return true;
    }
    return false;
}

bool dveteOkrazhnostiPresichatLiSe(DanniZaOkrazhnost parva, DanniZaOkrazhnost vtora){
    if(tochkataVOkrazhnosttaLiE(parva.centur, vtora) || tochkataVOkrazhnosttaLiE(vtora.centur, parva)){
        return true;
    }

    double razstoqnieto =
        sqrt((parva.centur.x - vtora.centur.x)*(parva.centur.x - vtora.centur.x) +
            (parva.centur.y - vtora.centur.y)*(parva.centur.y - vtora.centur.y));

    double sborRadiusi = parva.radius + vtora.radius;

    if(razstoqnieto - sborRadiusi > -0.000001){
        return false;
    }

    return true;
}

OtgovoriNaKvadratnoUravnenie reshavaneNaKvadratnoUravnenie(double a, double b, double c){
    double discriminanta = b*b - 4*a*c;

    if(discriminanta < 0 || (a > -0.000001 && a < 0.000001)){
        return {-1, -1};
    }

    double purviKoren = (-b + sqrt(discriminanta))/(2*a);
    double vtoriKoren = (-b - sqrt(discriminanta))/(2*a);

    return {purviKoren, vtoriKoren};
}

double priTkivaDveOkrIConstY(double y, DanniZaOkrazhnost parva, DanniZaOkrazhnost vtora){
    double r1Minusr2 = parva.radius - vtora.radius;
    if(r1Minusr2 < 0.0000001 && r1Minusr2 > -0.0000001){
        double razlikaVXovete = parva.centur.x - vtora.centur.x;
        if(razlikaVXovete < 0.0000001 && razlikaVXovete > -0.0000001){
            return -1;
        }
        double k =
            parva.centur.x*parva.centur.x -
            vtora.centur.x*vtora.centur.x -
            2*parva.centur.y*y +
            2*vtora.centur.y*y +
            parva.centur.y*parva.centur.y -
            vtora.centur.y*vtora.centur.y;

        double c = 2*(vtora.centur.x - parva.centur.x);

        double novX = (-k)/c;

        return novX;
    }else{
        double p = -(parva.centur.x - vtora.centur.x)/(r1Minusr2);
        double q =
            (parva.centur.x*parva.centur.x -
                vtora.centur.x*vtora.centur.x +
                parva.centur.y*parva.centur.y -
                vtora.centur.y*vtora.centur.y -
                parva.radius*parva.radius +
                vtora.radius*vtora.radius)
            /(2*(r1Minusr2))
            - y*((parva.centur.y - vtora.centur.y)/(r1Minusr2));
        double s =
            parva.centur.x*parva.centur.x + parva.centur.y*parva.centur.y - 2*y*parva.centur.y + y*y - parva.radius*parva.radius;

        double e = 1 - p*p;
        double f = -2*(parva.centur.x + p*q + parva.radius*p);
        double g = s - q*q - 2*parva.radius*q;

        OtgovoriNaKvadratnoUravnenie koreni = reshavaneNaKvadratnoUravnenie(e, f, g);

        //cout<<koreni.purvi<<" "<<koreni.vtori<<endl;

        if((koreni.purvi < 0 && koreni.vtori < 0)){
            //cout<<"ne sa hubavi"<<endl;
            return -1;
        }

        if(koreni.purvi > koreni.vtori){
            swap(koreni.purvi, koreni.vtori);
        }

        double polozhitelenKoren;

        if(koreni.purvi > 0){
            polozhitelenKoren = koreni.purvi;
        }else{
            polozhitelenKoren = koreni.vtori;
        }

        double xNaNovatOkr = polozhitelenKoren;

        return xNaNovatOkr;
    }
}

double priTkivaDveOkrIConstX(double x, DanniZaOkrazhnost parva, DanniZaOkrazhnost vtora){
    double r1Minusr2 = parva.radius - vtora.radius;

    if(r1Minusr2 > -0.0000001 && r1Minusr2 < 0.0000001){
        double razlikaVYcite = parva.centur.y - vtora.centur.y;
        if(razlikaVYcite < 0.0000001 && razlikaVYcite > -0.0000001){
            return -1;
        }
        double k =
            parva.centur.y*parva.centur.y -
            vtora.centur.y*vtora.centur.y -
            2*parva.centur.x*x +
            2*vtora.centur.x*x +
            parva.centur.x*parva.centur.x -
            vtora.centur.x*vtora.centur.x;

        double c = 2*(vtora.centur.y - parva.centur.y);

        double novY = (-k)/c;

        return novY;
    }else{
        double p = -(parva.centur.y - vtora.centur.y)/(r1Minusr2);
        double q =
            (parva.centur.y*parva.centur.y -
                vtora.centur.y*vtora.centur.y +
                parva.centur.x*parva.centur.x -
                vtora.centur.x*vtora.centur.x -
                parva.radius*parva.radius +
                vtora.radius*vtora.radius)
            /(2*(r1Minusr2))
            - x*((parva.centur.x - vtora.centur.x)/(r1Minusr2));
        double s =
            parva.centur.y*parva.centur.y + parva.centur.x*parva.centur.x - 2*x*parva.centur.x + x*x - parva.radius*parva.radius;

        double e = 1 - p*p;
        double f = -2*(parva.centur.y + p*q + parva.radius*p);
        double g = s - q*q - 2*parva.radius*q;

        OtgovoriNaKvadratnoUravnenie koreni = reshavaneNaKvadratnoUravnenie(e, f, g);

        //cout<<koreni.purvi<<" "<<koreni.vtori<<endl;

        if((koreni.purvi < 0 && koreni.vtori < 0)){
            //cout<<"ne sa hubavi"<<endl;
            return 1;
        }

        if(koreni.purvi > koreni.vtori){
            swap(koreni.purvi, koreni.vtori);
        }

        double polozhitelenKoren;

        if(koreni.purvi > 0){
            polozhitelenKoren = koreni.purvi;
        }else{
            polozhitelenKoren = koreni.vtori;
        }

        double yNaNovatOkr = polozhitelenKoren;

        return yNaNovatOkr;
    }
}

int main(){
    cin>>broiOkrazhnosti;

    for(int i = 0; i < broiOkrazhnosti; i++){
        cin>>okrazshnosti[i].centur.x>>okrazshnosti[i].centur.y>>okrazshnosti[i].radius;
    }

    double naiGolmqRadius = 0;
    DanniZaTochka centuraMu;

    for(int i = 0; i < broiOkrazhnosti; i++){
        for(int k = 0; k < 4; k++){
            DanniZaOkrazhnost novaOkrazhnostEventualna =
                okrazhnostOtTakavaKrainaTochkaIDrugaOkr(k/2 * 1000, k%2 * 1000, okrazshnosti[i]);

            cout<<novaOkrazhnostEventualna.radius<<" ";
            cout<<novaOkrazhnostEventualna.centur.x<<" "<<novaOkrazhnostEventualna.centur.y<<endl;
            if(novaOkrazhnostEventualna.radius - naiGolmqRadius > 0.0000001){
                bool presichaLiSeSDrugi = false;

                for(int j = 0; j < broiOkrazhnosti; j++){
                    if(dveteOkrazhnostiPresichatLiSe(okrazshnosti[j], novaOkrazhnostEventualna) == true){
                        presichaLiSeSDrugi = true;
                        break;
                    }
                }

                if(presichaLiSeSDrugi == false){
                    naiGolmqRadius = novaOkrazhnostEventualna.radius;
                    centuraMu = novaOkrazhnostEventualna.centur;
                }
            }
        }
    }

    for(int i = 0; i < broiOkrazhnosti; i++){
        for(int k = 0; k < broiOkrazhnosti; k++){
            if(k == i){
                continue;
            }

            double novY = priTkivaDveOkrIConstX(0, okrazshnosti[i], okrazshnosti[k]);
            DanniZaOkrazhnost novaOkrazhnostEventualna = okrazhnostOtTakavaKrainaTochkaIDrugaOkr(0, novY, okrazshnosti[i]);
            cout<<novaOkrazhnostEventualna.radius<<" ";
            cout<<novaOkrazhnostEventualna.centur.x<<" "<<novaOkrazhnostEventualna.centur.y<<endl;
            if(novaOkrazhnostEventualna.radius - naiGolmqRadius > 0.0000001 &&
                novaOkrazhnostEventualna.centur.x - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.y - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.x > -0.0000001 &&
                novaOkrazhnostEventualna.centur.y > -0.0000001){
                bool presichaLiSeSDrugi = false;

                for(int j = 0; j < broiOkrazhnosti; j++){
                    if(dveteOkrazhnostiPresichatLiSe(okrazshnosti[j], novaOkrazhnostEventualna) == true){
                        presichaLiSeSDrugi = true;
                        break;
                    }
                }

                if(presichaLiSeSDrugi == false){
                    naiGolmqRadius = novaOkrazhnostEventualna.radius;
                    centuraMu = novaOkrazhnostEventualna.centur;
                }
            }

            novY = priTkivaDveOkrIConstX(1000, okrazshnosti[i], okrazshnosti[k]);
            novaOkrazhnostEventualna = okrazhnostOtTakavaKrainaTochkaIDrugaOkr(1000, novY, okrazshnosti[i]);
            cout<<novaOkrazhnostEventualna.radius<<" ";
            cout<<novaOkrazhnostEventualna.centur.x<<" "<<novaOkrazhnostEventualna.centur.y<<endl;
            if(novaOkrazhnostEventualna.radius - naiGolmqRadius > 0.0000001 &&
                novaOkrazhnostEventualna.centur.x - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.y - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.x > -0.0000001 &&
                novaOkrazhnostEventualna.centur.y > -0.0000001){
                bool presichaLiSeSDrugi = false;

                for(int j = 0; j < broiOkrazhnosti; j++){
                    if(dveteOkrazhnostiPresichatLiSe(okrazshnosti[j], novaOkrazhnostEventualna) == true){
                        presichaLiSeSDrugi = true;
                        break;
                    }
                }

                if(presichaLiSeSDrugi == false){
                    naiGolmqRadius = novaOkrazhnostEventualna.radius;
                    centuraMu = novaOkrazhnostEventualna.centur;
                }
            }

            double novX = priTkivaDveOkrIConstY(0, okrazshnosti[i], okrazshnosti[k]);
            novaOkrazhnostEventualna = okrazhnostOtTakavaKrainaTochkaIDrugaOkr(novX, 0, okrazshnosti[i]);
            cout<<novaOkrazhnostEventualna.radius<<" ";
            cout<<novaOkrazhnostEventualna.centur.x<<" "<<novaOkrazhnostEventualna.centur.y<<endl;
            if(novaOkrazhnostEventualna.radius - naiGolmqRadius > 0.0000001 &&
                novaOkrazhnostEventualna.centur.x - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.y - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.x > -0.0000001 &&
                novaOkrazhnostEventualna.centur.y > -0.0000001){
                bool presichaLiSeSDrugi = false;

                for(int j = 0; j < broiOkrazhnosti; j++){
                    if(dveteOkrazhnostiPresichatLiSe(okrazshnosti[j], novaOkrazhnostEventualna) == true){
                        presichaLiSeSDrugi = true;
                        break;
                    }
                }

                if(presichaLiSeSDrugi == false){
                    naiGolmqRadius = novaOkrazhnostEventualna.radius;
                    centuraMu = novaOkrazhnostEventualna.centur;
                }
            }

            novX = priTkivaDveOkrIConstY(1000, okrazshnosti[i], okrazshnosti[k]);
            novaOkrazhnostEventualna = okrazhnostOtTakavaKrainaTochkaIDrugaOkr(novX, 1000, okrazshnosti[i]);
            cout<<novaOkrazhnostEventualna.radius<<" ";
            cout<<novaOkrazhnostEventualna.centur.x<<" "<<novaOkrazhnostEventualna.centur.y<<endl;
            if(novaOkrazhnostEventualna.radius - naiGolmqRadius > 0.0000001 &&
                novaOkrazhnostEventualna.centur.x - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.y - 1000 < 0.0000001 &&
                novaOkrazhnostEventualna.centur.x > -0.0000001 &&
                novaOkrazhnostEventualna.centur.y > -0.0000001){
                bool presichaLiSeSDrugi = false;

                for(int j = 0; j < broiOkrazhnosti; j++){
                    if(dveteOkrazhnostiPresichatLiSe(okrazshnosti[j], novaOkrazhnostEventualna) == true){
                        presichaLiSeSDrugi = true;
                        break;
                    }
                }

                if(presichaLiSeSDrugi == false){
                    naiGolmqRadius = novaOkrazhnostEventualna.radius;
                    centuraMu = novaOkrazhnostEventualna.centur;
                }
            }

        }
    }


    //double novY = priTkivaDveOkrIConstX(0, okrazshnosti[0], okrazshnosti[1]);

    //cout<<0<<" "<<novY<<endl;

    //DanniZaOkrazhnost novaOkr = okrazhnostOtTakavaKrainaTochkaIDrugaOkr(0, 500, okrazshnosti[0]);

    //cout<<novaOkr.centur.x<<" "<<novaOkr.centur.y<<" "<<novaOkr.radius<<endl;

    cout<<fixed<<setprecision(9)<<naiGolmqRadius<<endl;

    return 0;
}
