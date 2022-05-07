#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<set>
using namespace std;

long double maxX;
long double maxY;

long double broiZaqvki;

struct Koordinati{
    long double x;
    long double y;

    bool operator==(const Koordinati &a) const{
        //return x == a.x && y == a.y;
        return x - a.x < 0.000001 && x - a.x > -0.000001 && y - a.y < 0.000001 && y - a.y > 0.000001;
    }

    bool operator<(const Koordinati &a) const{
        if(x < a.x){
            return true;
        }
        if(x > a.x){
            return false;
        }
        return y > a.y;
    }
};

struct DanniZaPrava{
    long double a;
    long double b;
    long double c;
};

vector<Koordinati> tochki;

Koordinati dolnaLqva;
Koordinati dolnaDqsna;
Koordinati gornaLqva;
Koordinati gornaDqsna;

Koordinati zavartiTochkata(Koordinati originalni){
    return {2*(originalni.y + originalni.x), 2*(originalni.y - originalni.x)};
}

DanniZaPrava pravataNaDveTochki(Koordinati parva, Koordinati vtora){
    long double a = parva.y - vtora.y;
    long double b = vtora.x - parva.x;
    long double c = parva.x*vtora.y - parva.y*vtora.x;

    return {a, b, c};
}

Koordinati presechnataTochkaNa(DanniZaPrava parva, DanniZaPrava vtora){
    long double x = (vtora.b*parva.c - vtora.c*parva.b)/(vtora.a*parva.b - vtora.b*parva.a);
    long double y = (parva.a*vtora.c - parva.c*vtora.a)/(vtora.a*parva.b - vtora.b*parva.a);

    return {x, y};
}

long double tochkataOtPravataLiE(DanniZaPrava p, Koordinati t){
    long double suma = p.a*t.x+p.b*t.y+p.c;

    return suma;
}

void zavartiPravoagalnika(){
    dolnaLqva = zavartiTochkata({0, 0});
    dolnaDqsna = zavartiTochkata({maxX, 0});
    gornaLqva = zavartiTochkata({0, maxY});
    gornaDqsna = zavartiTochkata({maxX, maxY});
}

bool koqEPoNapred(Koordinati a, Koordinati b){
    if(a.x < b.x){
        return true;
    }
    if(a.x > b.x){
        return false;
    }
    return a.y > b.y;
}

long double daljinaNaOtsechka(Koordinati a, Koordinati b){
    return sqrt((long double)(a.x - b.x)*(a.x - b.x) + (long double)(a.y - b.y)*(a.y - b.y));
}

long double nameriLicetoNaGorniqTrapec(Koordinati parvaTochka){
    DanniZaPrava naParvataTochkaNagore = pravataNaDveTochki(parvaTochka, {parvaTochka.x, parvaTochka.y + 1});
    DanniZaPrava gornaStranaKvadrat = pravataNaDveTochki({dolnaLqva.x, gornaLqva.y}, {gornaDqsna.x, gornaLqva.y});

    if(parvaTochka.x > gornaLqva.x){
        long double ediniqTriagalnik = (long double)(gornaLqva.y - dolnaLqva.y)*(gornaLqva.x - dolnaLqva.x)/2;

        DanniZaPrava gornaStranaPravoag = pravataNaDveTochki(gornaLqva, gornaDqsna);

        Koordinati presechnaGore = presechnataTochkaNa(naParvataTochkaNagore, gornaStranaKvadrat);
        Koordinati presechnaDolo = presechnataTochkaNa(naParvataTochkaNagore, gornaStranaPravoag);

        //cout<<"presechna gore: "<<presechnaGore.x<<" "<<presechnaGore.y<<endl;
        //cout<<"presechna dolo: "<<presechnaDolo.x<<" "<<presechnaDolo.y<<endl;

        long double drugiqTriagalnik = (long double)(presechnaGore.x - gornaLqva.x)*(presechnaGore.y - presechnaDolo.y)/2;

        return ediniqTriagalnik + drugiqTriagalnik;
    }else{

        DanniZaPrava lqvaStranaPravoag = pravataNaDveTochki(dolnaLqva, gornaLqva);

        Koordinati ednataTochkaGOsnova = presechnataTochkaNa(naParvataTochkaNagore, lqvaStranaPravoag);
        Koordinati drugataTochlaGOsnova = presechnataTochkaNa(naParvataTochkaNagore, gornaStranaKvadrat);

        long double ednataOsnova = daljinaNaOtsechka(ednataTochkaGOsnova, drugataTochlaGOsnova);
        long double drugataOsnova = daljinaNaOtsechka(dolnaLqva, {dolnaLqva.x, gornaLqva.y});
        long double visochinata = daljinaNaOtsechka({dolnaLqva.x, gornaLqva.y}, drugataTochlaGOsnova);

        long double liceGorenTrapec = (ednataOsnova + drugataOsnova)*visochinata/2;

        return liceGorenTrapec;
    }
}

long double nameriLicetoNaDolniqTrapec(Koordinati poslednaTochka){
    DanniZaPrava naPoslednataTochkaNastrani = pravataNaDveTochki(poslednaTochka, {poslednaTochka.x + 1, poslednaTochka.y});
    DanniZaPrava dqsnaStranaKvadrat = pravataNaDveTochki({gornaDqsna.x, gornaLqva.y}, {gornaDqsna.x, dolnaDqsna.y});

    if(poslednaTochka.y > gornaDqsna.y){
        long double ediniqTriagalnik = (long double)(gornaDqsna.x - dolnaDqsna.x)*(gornaDqsna.y - dolnaDqsna.y)/2;

        DanniZaPrava gornaStranaPravoag = pravataNaDveTochki(gornaLqva, gornaDqsna);

        Koordinati presechnaDqsno = presechnataTochkaNa(naPoslednataTochkaNastrani, dqsnaStranaKvadrat);
        Koordinati presechnaLqvo = presechnataTochkaNa(naPoslednataTochkaNastrani, gornaStranaPravoag);

        //cout<<"presechna dqsno: "<<presechnaDqsno.x<<" "<<presechnaDqsno.y<<endl;
        //cout<<"presechna lqvo: "<<presechnaLqvo.x<<" "<<presechnaLqvo.y<<endl;

        long double drugiqTriagalnik = (long double)(presechnaDqsno.x - presechnaLqvo.x)*(presechnaDqsno.y - gornaDqsna.y)/2;

        //cout<<"liceto ediniq: "<<ediniqTriagalnik<<" liceto drugiq "<<drugiqTriagalnik<<endl;

        return ediniqTriagalnik + drugiqTriagalnik;
    }else{

        DanniZaPrava dqsnaStranaPravoag = pravataNaDveTochki(dolnaDqsna, gornaDqsna);

        Koordinati ednataTochkaDOsnova = presechnataTochkaNa(naPoslednataTochkaNastrani, dqsnaStranaPravoag);
        Koordinati drugataTochkaDOsnova = presechnataTochkaNa(naPoslednataTochkaNastrani, dqsnaStranaKvadrat);

        long double ednataOsnova = daljinaNaOtsechka(ednataTochkaDOsnova, drugataTochkaDOsnova);
        long double drugataOsnova = daljinaNaOtsechka(dolnaDqsna, {gornaDqsna.x, dolnaDqsna.y});
        long double visochinata = daljinaNaOtsechka({gornaDqsna.x, dolnaDqsna.y}, drugataTochkaDOsnova);

        long double liceDolenTrapec = (ednataOsnova + drugataOsnova)*visochinata/2;

        return liceDolenTrapec;
    }
}

long double dopalnitelnoLiceMejduTochki(Koordinati lqva, Koordinati dqsna){
    DanniZaPrava nadqsnoOtGornata = pravataNaDveTochki(lqva, {lqva.x + 1, lqva.y});
    DanniZaPrava nagoreOtDolnata = pravataNaDveTochki(dqsna, {dqsna.x, dqsna.y + 1});

    Koordinati chervenaTochka = presechnataTochkaNa(nadqsnoOtGornata, nagoreOtDolnata);

    DanniZaPrava stranaNaPravoag = pravataNaDveTochki(gornaLqva, gornaDqsna);

    long double kadeETochkata = tochkataOtPravataLiE(stranaNaPravoag, chervenaTochka);

    if(kadeETochkata <= 0){
        return 0;
    }

    Koordinati ednataPresechnaT = presechnataTochkaNa(stranaNaPravoag, nadqsnoOtGornata);
    Koordinati drugataPresechnaT = presechnataTochkaNa(stranaNaPravoag, nagoreOtDolnata);

    long double ednataStranaNaTriag = daljinaNaOtsechka(ednataPresechnaT, chervenaTochka);
    long double drugataStranaNaTriag = daljinaNaOtsechka(drugataPresechnaT, chervenaTochka);

    long double liceto = ednataStranaNaTriag*drugataStranaNaTriag/2;

    return liceto;
}

set<Koordinati> slojeniTochki;
//map<Koordinati> slojeniTochki;
long double segaLice;

long double nameriSegaLiceto(){

    long double liceDolenTriagalnik = (dolnaLqva.y - dolnaDqsna.y)*(dolnaDqsna.x - dolnaLqva.x)/2;

    //cout<<"liceto na dolniq triagalnik e: "<<liceDolenTriagalnik<<endl;

    //sort(tochki.begin(), tochki.end(), koqEPoNapred);

    vector<Koordinati> neobhodimiTochki;

    neobhodimiTochki.push_back(*slojeniTochki.begin());

    Koordinati prednata = neobhodimiTochki[0];

    /*for(long double i = 1; i < (long double)tochki.size(); i++){
        if(tochki[i].y < prednata.y){
            neobhodimiTochki.push_back(tochki[i]);
            prednata = tochki[i];
        }
    }*/

    for(set<Koordinati>::iterator i = slojeniTochki.begin(); i != slojeniTochki.end(); i++){
        Koordinati tukaTochka = *i;
        if(tukaTochka.y < prednata.y){
            neobhodimiTochki.push_back(tukaTochka);
            prednata = tukaTochka;
        }
    }


    long double liceGorenTrapec = nameriLicetoNaGorniqTrapec(neobhodimiTochki[0]);
    long double liceDolenTrapec = nameriLicetoNaDolniqTrapec(neobhodimiTochki.back());

    //cout<<"liceto na gorniq trapec e "<<liceGorenTrapec<<endl;
    //cout<<"liceto na dolniq trapec e "<<liceDolenTrapec<<endl;

    long double dopalnitelnoLice = 0;
    long double cqloLice = 0;

    for(long double i = 1; i < (long double)neobhodimiTochki.size(); i++){
        dopalnitelnoLice += dopalnitelnoLiceMejduTochki(neobhodimiTochki[i - 1], neobhodimiTochki[i]);

        cqloLice += (neobhodimiTochki[i].x - neobhodimiTochki[i - 1].x)*(neobhodimiTochki[i - 1].y - dolnaDqsna.y);
    }

    cqloLice += (neobhodimiTochki[0].x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y);
    cqloLice += (gornaDqsna.x - neobhodimiTochki.back().x)*(neobhodimiTochki.back().y - dolnaDqsna.y);

    //cout<<"cqloto lice e "<<cqloLice<<endl;

    long double liceTarseno = cqloLice - (liceDolenTriagalnik + liceDolenTrapec + liceGorenTrapec + dopalnitelnoLice);

    return liceTarseno/8;
}

void dobaviKamSegaLice(long double kolko){
    segaLice += kolko/8;
}

void izchisliNovotoLice(Koordinati novaTochka){

    set<Koordinati>::iterator sledvashtata = slojeniTochki.lower_bound(novaTochka);
    set<Koordinati>::iterator predishnata = sledvashtata;

    bool imaLiPredishna = false;
    if(predishnata != slojeniTochki.begin()){
        imaLiPredishna = true;
        predishnata--;
    }
    bool imaLiSledvashta = (sledvashtata != slojeniTochki.end());

    /*if(imaLiSledvashta){
        cout<<"sledvashtata: "<<sledvashtata->x<<" "<<sledvashtata->y<<endl;
    }else{
        cout<<"nqma sledvashta"<<endl;
    }

    if(imaLiPredishna){
        cout<<"predishnata: "<<predishnata->x<<" "<<predishnata->y<<endl;
    }else{
        cout<<"nqma predishna"<<endl;
    }*/

    if(imaLiPredishna == true && predishnata->y < novaTochka.y){
        //cout<<"ne q gledame vuobshte"<<endl;
        return ;
    }

    //cout<<"vikat ni sas sega lice "<<segaLice<<endl;

    while(sledvashtata != slojeniTochki.end() && sledvashtata->y >= novaTochka.y){
        //cout<<"mahame "<<sledvashtata->x<<" "<<sledvashtata->y<<endl;
        set<Koordinati>::iterator novaSledvashta = next(sledvashtata);

        if(imaLiPredishna == true && novaSledvashta != slojeniTochki.end()){
            //cout<<"mahane tip 1 "<<endl;
            dobaviKamSegaLice(-dopalnitelnoLiceMejduTochki(*predishnata, *novaSledvashta));
            dobaviKamSegaLice((predishnata->y - sledvashtata->y)*(novaSledvashta->x - sledvashtata->x));
            dobaviKamSegaLice(dopalnitelnoLiceMejduTochki(*predishnata, *sledvashtata));
            dobaviKamSegaLice(dopalnitelnoLiceMejduTochki(*sledvashtata, *novaSledvashta));
        }else{
            if(imaLiPredishna == false && novaSledvashta != slojeniTochki.end()){
                //cout<<"mahane tip 2 "<<endl;
                dobaviKamSegaLice(-nameriLicetoNaGorniqTrapec(*novaSledvashta));
                dobaviKamSegaLice((novaSledvashta->x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y));
                dobaviKamSegaLice(nameriLicetoNaGorniqTrapec(*sledvashtata));
                dobaviKamSegaLice(-(sledvashtata->x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y));
                dobaviKamSegaLice(-(novaSledvashta->x - sledvashtata->x)*(sledvashtata->y - dolnaDqsna.y));
                dobaviKamSegaLice(dopalnitelnoLiceMejduTochki(*sledvashtata, *novaSledvashta));
            }else{
                if(imaLiPredishna == true && novaSledvashta == slojeniTochki.end()){
                    //cout<<"mahane tip 3 "<<endl;
                    dobaviKamSegaLice(-nameriLicetoNaDolniqTrapec(*predishnata));
                    dobaviKamSegaLice(((gornaDqsna.x - predishnata->x)*(predishnata->y - dolnaDqsna.y)));
                    dobaviKamSegaLice(nameriLicetoNaDolniqTrapec(*sledvashtata));
                    dobaviKamSegaLice(-(sledvashtata->x - predishnata->x)*(predishnata->y - dolnaDqsna.y));
                    dobaviKamSegaLice(-(gornaDqsna.x - sledvashtata->x)*(sledvashtata->y - dolnaDqsna.y));
                    dobaviKamSegaLice(dopalnitelnoLiceMejduTochki(*predishnata, *sledvashtata));
                }else{
                    //cout<<"mahane tip 4 "<<endl;
                    dobaviKamSegaLice(nameriLicetoNaGorniqTrapec(*sledvashtata));
                    dobaviKamSegaLice(nameriLicetoNaDolniqTrapec(*sledvashtata));
                    dobaviKamSegaLice(-(sledvashtata->x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y));
                    dobaviKamSegaLice(-(gornaDqsna.x - sledvashtata->x)*(sledvashtata->y - dolnaDqsna.y));
                }
            }
        }

        slojeniTochki.erase(sledvashtata);
        sledvashtata = novaSledvashta;
    }

    //cout<<"sled kato mahnahme tochki liceto e "<<segaLice<<endl;

    imaLiSledvashta = (sledvashtata != slojeniTochki.end());
    /*if(imaLiSledvashta == true){
        cout<<"sled mahaniqta se okazva che sledvashtata e "<<sledvashtata->x<<" "<<sledvashtata->y<<endl;
    }else{
        cout<<"sled mahanqita nqma sledvashta"<<endl;
    }*/

    if(imaLiPredishna == true && imaLiSledvashta == true){
        dobaviKamSegaLice(dopalnitelnoLiceMejduTochki(*predishnata, *sledvashtata));
        dobaviKamSegaLice(-(predishnata->y - novaTochka.y)*(sledvashtata->x - novaTochka.x));
        dobaviKamSegaLice(-dopalnitelnoLiceMejduTochki(*predishnata, novaTochka));
        dobaviKamSegaLice(-dopalnitelnoLiceMejduTochki(novaTochka, *sledvashtata));
    }else{
        if(imaLiPredishna == false && imaLiSledvashta == true){
            dobaviKamSegaLice(nameriLicetoNaGorniqTrapec(*sledvashtata));
            dobaviKamSegaLice(-(sledvashtata->x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y));
            dobaviKamSegaLice(-nameriLicetoNaGorniqTrapec(novaTochka));
            dobaviKamSegaLice((novaTochka.x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y));
            dobaviKamSegaLice((sledvashtata->x - novaTochka.x)*(novaTochka.y - dolnaDqsna.y));
            dobaviKamSegaLice(-dopalnitelnoLiceMejduTochki(novaTochka, *sledvashtata));
        }else{
            if(imaLiPredishna == true && imaLiSledvashta == false){
                dobaviKamSegaLice(nameriLicetoNaDolniqTrapec(*predishnata));
                dobaviKamSegaLice(-((gornaDqsna.x - predishnata->x)*(predishnata->y - dolnaDqsna.y)));
                dobaviKamSegaLice(-nameriLicetoNaDolniqTrapec(novaTochka));
                dobaviKamSegaLice((novaTochka.x - predishnata->x)*(predishnata->y - dolnaDqsna.y));
                dobaviKamSegaLice((gornaDqsna.x - novaTochka.x)*(novaTochka.y - dolnaDqsna.y));
                dobaviKamSegaLice(-dopalnitelnoLiceMejduTochki(*predishnata, novaTochka));
            }else{
                dobaviKamSegaLice(-nameriLicetoNaGorniqTrapec(novaTochka));
                dobaviKamSegaLice(-nameriLicetoNaDolniqTrapec(novaTochka));
                dobaviKamSegaLice((novaTochka.x - dolnaLqva.x)*(gornaLqva.y - dolnaDqsna.y));
                dobaviKamSegaLice((gornaDqsna.x - novaTochka.x)*(novaTochka.y - dolnaDqsna.y));
            }
        }
    }

    //cout<<"sega lice stava "<<segaLice<<endl;
    slojeniTochki.insert(novaTochka);
}


vector<long double> otgovori;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxX>>maxY;

    zavartiPravoagalnika();

    cin>>broiZaqvki;

    for(long double i = 0; i < broiZaqvki; i++){
        long double x;
        long double y;
        cin>>x>>y;

        tochki.push_back(zavartiTochkata({x, y}));
    }

    slojeniTochki.insert(tochki[0]);
    segaLice = nameriSegaLiceto();
    otgovori.push_back(segaLice);

    for(long double i = 1; i < broiZaqvki; i++){
        //cout<<"slagame "<<tochki[i].x<<" "<<tochki[i].y<<endl;
        izchisliNovotoLice(tochki[i]);
        //cout<<endl;
        //otgovori.push_back(nameriSegaLiceto());
        otgovori.push_back(segaLice);
    }

    cout<<fixed<<setprecision(2);

    for(long double i = 0; i < (long double)otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
