#include<iostream>
using namespace std;

struct DanniZaTochka{
    long long x;
    long long y;
};

struct DanniZaKvadrata{
    DanniZaTochka varhove[4];
};

struct DanniZaPrava{
    long long a;
    long long b;
    long long c;
};

long long broiKvadrti;

DanniZaKvadrata kvadrati[12];

const long long mnogoGolqmo = 1<<30;
const long long mnogoMalko = -(1<<30);

DanniZaPrava pravataNaDveteTochki(DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka){
    long long a = parvaTochka.y - vtoraTochka.y;
    long long b = vtoraTochka.x - parvaTochka.x;
    long long c = parvaTochka.x*vtoraTochka.y - parvaTochka.y*vtoraTochka.x;

    return {a, b, c};
}

long long otKoqStranaNaPravatETochkata(DanniZaPrava prava, DanniZaTochka tochka){
    long long suma = prava.a*tochka.x + prava.b*tochka.y + prava.c;

    if(suma == 0){
        return 0;
    }
    if(suma > 0){
        return 1;
    }
    return -1;
}

long long kudeETochkataSprqmoDrugataIPravata(DanniZaTochka parvaTochka, DanniZaTochka vtoraTochka, DanniZaPrava prava){
    long long otKoqStranaEParvata = otKoqStranaNaPravatETochkata(prava, parvaTochka);
    long long otKoqStranEVtorata = otKoqStranaNaPravatETochkata(prava, vtoraTochka);

    if(otKoqStranaEParvata == otKoqStranEVtorata){
        return 1;
    }
    if(otKoqStranaEParvata != 0 && otKoqStranaEParvata != otKoqStranEVtorata){
        return -1;
    }
    return 0;
}

long long tochkataVKvadrataLiE(DanniZaTochka tochka, DanniZaKvadrata kvadrat){
    bool imaLiIzvunKvadrata = false;
    bool imaLiNaStenata = false;

    for(long long i = 0; i < 4; i++){
        DanniZaPrava prava = {0, 0, 0};
        if(i < 3){
            prava = pravataNaDveteTochki(kvadrat.varhove[i], kvadrat.varhove[i + 1]);
        }else{
            prava = pravataNaDveteTochki(kvadrat.varhove[i], kvadrat.varhove[0]);
        }

        DanniZaTochka tochkaOtKvadrata = {0, 0};

        if(i > 0){
            tochkaOtKvadrata = kvadrat.varhove[i - 1];
        }else{
            tochkaOtKvadrata = kvadrat.varhove[3];
        }

        long long kakSaTochkite = kudeETochkataSprqmoDrugataIPravata(tochka, tochkaOtKvadrata, prava);

        if(kakSaTochkite == -1){
            imaLiIzvunKvadrata = true;
        }else{
            if(kakSaTochkite == 0){
                imaLiNaStenata = true;
            }
        }
    }

    long long zaVrashtane = 1;

    if(imaLiIzvunKvadrata == true){
        zaVrashtane = -1;
    }else{
        if(imaLiNaStenata == true){
            zaVrashtane = 0;
        }
    }

    return zaVrashtane;
}

long long kvadrataVKvadrataLiE(DanniZaKvadrata vutreshen, DanniZaKvadrata vunshen){
    bool imaLiTochkaIzvunKvadrata = false;
    bool imaLiTochkaVKvadrata = false;

    for(long long i = 0; i < 4; i++){
        long long zaTuk = tochkataVKvadrataLiE(vutreshen.varhove[i], vunshen);
        if(zaTuk == -1){
            imaLiTochkaIzvunKvadrata = true;
        }else{
            if(zaTuk == 1){
                imaLiTochkaVKvadrata = true;
            }
        }
    }

    long long zaToziKvadrat;

    if(!imaLiTochkaIzvunKvadrata == true){
        zaToziKvadrat = 1;
    }else{
        if(!imaLiTochkaVKvadrata){
            zaToziKvadrat = -1;
        }else{
            zaToziKvadrat = 0;
        }
    }

    return zaToziKvadrat;
}

long long kvadrataKakEPokritOtDrugiq(DanniZaKvadrata edin, DanniZaKvadrata drug){
    long long kakE;

    long long akoEdinEPoMaluk = kvadrataVKvadrataLiE(edin, drug);

    if(akoEdinEPoMaluk == -1){
        long long akoDrugiqEPoMaluk = kvadrataVKvadrataLiE(drug, edin);
        if(akoDrugiqEPoMaluk != -1){
            kakE = 0;
        }else{
            kakE = -1;
        }
    }else{
        kakE = akoEdinEPoMaluk;
    }

    return kakE;
}

DanniZaKvadrata kvadratOtCenturITochka(DanniZaTochka centur, DanniZaTochka tochka){
    DanniZaKvadrata novoKvadratche;

    novoKvadratche.varhove[0] = tochka;

    long long razlikaVX = novoKvadratche.varhove[0].x - centur.x;
    long long razlikaVY = novoKvadratche.varhove[0].y - centur.y;
    novoKvadratche.varhove[2] = {centur.x - razlikaVX, centur.y - razlikaVY};
    novoKvadratche.varhove[1] = {centur.x - razlikaVY, centur.y + razlikaVX};
    novoKvadratche.varhove[3] = {centur.x + razlikaVY, centur.y - razlikaVX};

    return novoKvadratche;
}

DanniZaKvadrata kvadratOtDveSreshtupolozhniTochki(DanniZaTochka edna, DanniZaTochka druga){
    DanniZaKvadrata novoKvadratche;
    novoKvadratche.varhove[0] = edna;
    novoKvadratche.varhove[2] = druga;

    novoKvadratche.varhove[1] = {edna.x, druga.y};
    novoKvadratche.varhove[3] = {druga.x, edna.y};

    return novoKvadratche;
}

long long kakuvViDeKvadratcheto(DanniZaKvadrata kvadratche){
    long long kakEKvadratcheto = -1;

    for(long long i = 0; i < broiKvadrti; i++){
        long long zaTuk = kvadrataKakEPokritOtDrugiq(kvadratche, kvadrati[i]);
        kakEKvadratcheto = max(kakEKvadratcheto, zaTuk);
    }

    return kakEKvadratcheto;
}

long long liceNaKvadrat(DanniZaKvadrata kvadrtche){
    /// raboti samo za kvadrati sys strani usporedni na koordinatnite osi

    long long maximalenX =
        max(max(kvadrtche.varhove[0].x, kvadrtche.varhove[1].x), max(kvadrtche.varhove[2].x, kvadrtche.varhove[3].x));
    long long minimalenX =
        min(min(kvadrtche.varhove[0].x, kvadrtche.varhove[1].x), min(kvadrtche.varhove[2].x, kvadrtche.varhove[3].x));
    long long maximalenY =
        max(max(kvadrtche.varhove[0].y, kvadrtche.varhove[1].y), max(kvadrtche.varhove[2].y, kvadrtche.varhove[3].y));
    long long minimalenY =
        min(min(kvadrtche.varhove[0].y, kvadrtche.varhove[1].y), min(kvadrtche.varhove[2].y, kvadrtche.varhove[3].y));

    return (maximalenX - minimalenX)*(maximalenY - minimalenY);
}

DanniZaTochka centuraNaKvadrat(DanniZaKvadrata kvadrtche){
    long long maximalenX =
        max(max(kvadrtche.varhove[0].x, kvadrtche.varhove[1].x), max(kvadrtche.varhove[2].x, kvadrtche.varhove[3].x));
    long long minimalenX =
        min(min(kvadrtche.varhove[0].x, kvadrtche.varhove[1].x), min(kvadrtche.varhove[2].x, kvadrtche.varhove[3].x));
    long long maximalenY =
        max(max(kvadrtche.varhove[0].y, kvadrtche.varhove[1].y), max(kvadrtche.varhove[2].y, kvadrtche.varhove[3].y));
    long long minimalenY =
        min(min(kvadrtche.varhove[0].y, kvadrtche.varhove[1].y), min(kvadrtche.varhove[2].y, kvadrtche.varhove[3].y));

    return {(maximalenX + minimalenX)/2, (maximalenY + minimalenY)/2};
}

long long stranaNaKvadratcheto(DanniZaKvadrata kvadrtche){
    /// i tva raboti samo za usporedni na koordinatnite osi

    long long maximalenX =
        max(max(kvadrtche.varhove[0].x, kvadrtche.varhove[1].x), max(kvadrtche.varhove[2].x, kvadrtche.varhove[3].x));
    long long minimalenX =
        min(min(kvadrtche.varhove[0].x, kvadrtche.varhove[1].x), min(kvadrtche.varhove[2].x, kvadrtche.varhove[3].x));

    return maximalenX - minimalenX;
}

long long lichice(){
    long long naiMalakX = mnogoGolqmo;
    long long naiMalakY = mnogoGolqmo;
    long long naiGolqmX = mnogoMalko;
    long long naiGolqmY = mnogoMalko;

    for(long long i = 0; i < broiKvadrti; i++){
        for(long long j = 0; j < 4; j++){
            if(kvadrati[i].varhove[j].x > naiGolqmX){
                naiGolqmX = kvadrati[i].varhove[j].x;
            }
            if(kvadrati[i].varhove[j].x < naiMalakX){
                naiMalakX = kvadrati[i].varhove[j].x;
            }
            if(kvadrati[i].varhove[j].y > naiGolqmY){
                naiGolqmY = kvadrati[i].varhove[j].y;
            }
            if(kvadrati[i].varhove[j].y < naiMalakY){
                naiMalakY = kvadrati[i].varhove[j].y;
            }
        }
    }

    long long stapka = 1;

    long long lice = 0;

    for(long long x = naiMalakX - stapka; x <= naiGolqmX + stapka; x+=stapka){
        for(long long y = naiMalakY - stapka; y <= naiGolqmY + stapka; y+=stapka){

            DanniZaTochka gornaLqva = {x, y};
            DanniZaTochka dolnaDqsna = {x + stapka, y + stapka};

            DanniZaKvadrata novoKvadratche = kvadratOtDveSreshtupolozhniTochki(gornaLqva, dolnaDqsna);

            long long kakEKvadratcheto = kakuvViDeKvadratcheto(novoKvadratche);

            if(kakEKvadratcheto == 1){
                lice += 2*(stapka*stapka);
            }else{
                if(kakEKvadratcheto == 0){
                    lice += stapka*stapka;
                }
            }

        }
    }

    return lice;
}

long long pokritoLice(DanniZaKvadrata kvadratche){
    long long kakEKvadratcheto = kakuvViDeKvadratcheto(kvadratche);

    if(kakEKvadratcheto == -1){
        return 0;
    }

    if(kakEKvadratcheto == 1){
        return liceNaKvadrat(kvadratche)*2;
    }

    if(stranaNaKvadratcheto(kvadratche) == 1){
        return 1;
    }

    DanniZaTochka centura = centuraNaKvadrat(kvadratche);

    long long tukLice =
        pokritoLice(kvadratOtDveSreshtupolozhniTochki(centura, kvadratche.varhove[0])) +
        pokritoLice(kvadratOtDveSreshtupolozhniTochki(centura, kvadratche.varhove[1])) +
        pokritoLice(kvadratOtDveSreshtupolozhniTochki(centura, kvadratche.varhove[2])) +
        pokritoLice(kvadratOtDveSreshtupolozhniTochki(centura, kvadratche.varhove[3]));

    return tukLice;
}

int main(){
    const long long skalirane = 64;

    cin>>broiKvadrti;

    for(long long i = 0; i < broiKvadrti; i++){
        DanniZaTochka centarat;
        DanniZaTochka ediniqtOtVarhovete;
        cin>>centarat.x>>centarat.y;
        cin>>ediniqtOtVarhovete.x>>ediniqtOtVarhovete.y;
        centarat.x *= skalirane;
        centarat.y *= skalirane;
        ediniqtOtVarhovete.x *= skalirane;
        ediniqtOtVarhovete.y *= skalirane;
        kvadrati[i] = kvadratOtCenturITochka(centarat, ediniqtOtVarhovete);
    }

    DanniZaKvadrata palnoKvadratche =
        kvadratOtDveSreshtupolozhniTochki({-256*skalirane, -256*skalirane}, {256*skalirane, 256*skalirane});

    long long lice = pokritoLice(palnoKvadratche);

    cout<<lice/(2*skalirane*skalirane)<<endl;

    return 0;
}
