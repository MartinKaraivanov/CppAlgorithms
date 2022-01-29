#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int maxX;
int maxY;

int broiZaqvki;

struct Koordinati{
    int x;
    int y;
};

struct DanniZaPrava{
    int a;
    int b;
    int c;
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
    int a = parva.y - vtora.y;
    int b = vtora.x - parva.x;
    int c = parva.x*vtora.y - parva.y*vtora.x;

    return {a, b, c};
}

Koordinati presechnataTochkaNa(DanniZaPrava parva, DanniZaPrava vtora){
    int x = (vtora.b*parva.c - vtora.c*parva.b)/(vtora.a*parva.b - vtora.b*parva.a);
    int y = (parva.a*vtora.c - parva.c*vtora.a)/(vtora.a*parva.b - vtora.b*parva.a);

    return {x, y};
}

int tochkataOtPravataLiE(DanniZaPrava p, Koordinati t){
    int suma = p.a*t.x+p.b*t.y+p.c;

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

int daljinaNaOtsechka(Koordinati a, Koordinati b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int nameriLicetoNaGorniqTrapec(Koordinati parvaTochka){
    DanniZaPrava lqvaStranaPravoag = pravataNaDveTochki(dolnaLqva, gornaLqva);
    DanniZaPrava gornaStranaKvadrat = pravataNaDveTochki({dolnaLqva.x, gornaLqva.y}, {gornaDqsna.x, gornaLqva.y});
    DanniZaPrava naParvataTochkaNagore = pravataNaDveTochki(parvaTochka, {parvaTochka.x, parvaTochka.y + 1});

    Koordinati ednataTochkaGOsnova = presechnataTochkaNa(naParvataTochkaNagore, lqvaStranaPravoag);
    Koordinati drugataTochlaGOsnova = presechnataTochkaNa(naParvataTochkaNagore, gornaStranaKvadrat);

    int ednataOsnova = daljinaNaOtsechka(ednataTochkaGOsnova, drugataTochlaGOsnova);
    int drugataOsnova = daljinaNaOtsechka(dolnaLqva, {dolnaLqva.x, gornaLqva.y});
    int visochinata = daljinaNaOtsechka({dolnaLqva.x, gornaLqva.y}, drugataTochlaGOsnova);

    int liceGorenTrapec = (ednataOsnova + drugataOsnova)*visochinata/2;

    return liceGorenTrapec;
}

int nameriLicetoNaDolniqTrapec(Koordinati poslednaTochka){
    DanniZaPrava dqsnaStranaPravoag = pravataNaDveTochki(dolnaDqsna, gornaDqsna);
    DanniZaPrava dqsnaStranaKvadrat = pravataNaDveTochki({gornaDqsna.x, gornaLqva.y}, {gornaDqsna.x, dolnaDqsna.y});
    DanniZaPrava naPoslednataTochkaNastrani = pravataNaDveTochki(poslednaTochka, {poslednaTochka.x + 1, poslednaTochka.y});

    Koordinati ednataTochkaDOsnova = presechnataTochkaNa(naPoslednataTochkaNastrani, dqsnaStranaPravoag);
    Koordinati drugataTochkaDOsnova = presechnataTochkaNa(naPoslednataTochkaNastrani, dqsnaStranaKvadrat);

    int ednataOsnova = daljinaNaOtsechka(ednataTochkaDOsnova, drugataTochkaDOsnova);
    int drugataOsnova = daljinaNaOtsechka(dolnaDqsna, {gornaDqsna.x, dolnaDqsna.y});
    int visochinata = daljinaNaOtsechka({gornaDqsna.x, dolnaDqsna.y}, drugataTochkaDOsnova);

    int liceDolenTrapec = (ednataOsnova + drugataOsnova)*visochinata/2;

    return liceDolenTrapec;
}

int dopalnitelnoLiceMejduTochki(Koordinati lqva, Koordinati dqsna){
    DanniZaPrava nadqsnoOtGornata = pravataNaDveTochki(lqva, {lqva.x + 1, lqva.y});
    DanniZaPrava nagoreOtDolnata = pravataNaDveTochki(dqsna, {dqsna.x, dqsna.y + 1});

    Koordinati chervenaTochka = presechnataTochkaNa(nadqsnoOtGornata, nagoreOtDolnata);

    DanniZaPrava stranaNaPravoag = pravataNaDveTochki(gornaLqva, gornaDqsna);

    int kadeETochkata = tochkataOtPravataLiE(stranaNaPravoag, chervenaTochka);

    if(kadeETochkata <= 0){
        return 0;
    }

    Koordinati ednataPresechnaT = presechnataTochkaNa(stranaNaPravoag, nadqsnoOtGornata);
    Koordinati drugataPresechnaT = presechnataTochkaNa(stranaNaPravoag, nagoreOtDolnata);

    int ednataStranaNaTriag = daljinaNaOtsechka(ednataPresechnaT, chervenaTochka);
    int drugataStranaNaTriag = daljinaNaOtsechka(drugataPresechnaT, chervenaTochka);

    int liceto = ednataStranaNaTriag*drugataStranaNaTriag/2;

    return liceto;
}

int nameriSegaLiceto(){

    int liceDolenTriagalnik = dolnaDqsna.x*dolnaLqva.y/2;

    sort(tochki.begin(), tochki.end(), koqEPoNapred);

    vector<Koordinati> neobhodimiTochki;

    neobhodimiTochki.push_back(tochki[0]);

    Koordinati prednata = neobhodimiTochki[0];

    for(int i = 1; i < (int)tochki.size(); i++){
        if(tochki[i].y < prednata.y){
            neobhodimiTochki.push_back(tochki[i]);
            prednata = tochki[i];
        }
    }

    int liceGorenTrapec = nameriLicetoNaGorniqTrapec(neobhodimiTochki[0]);
    int liceDolenTrapec = nameriLicetoNaDolniqTrapec(neobhodimiTochki.back());

    int dopalnitelnoLice = 0;
    int cqloLice = 0;

    for(int i = 1; i < (int)neobhodimiTochki.size(); i++){
        dopalnitelnoLice += dopalnitelnoLiceMejduTochki(neobhodimiTochki[i - 1], neobhodimiTochki[i]);

        cqloLice += (neobhodimiTochki[i].x - neobhodimiTochki[i - 1].x)*(neobhodimiTochki[i - 1].y - dolnaDqsna.y);
    }

    cqloLice += neobhodimiTochki[0].x*(gornaLqva.y - dolnaDqsna.y);
    cqloLice += (gornaDqsna.x - neobhodimiTochki.back().x)*(neobhodimiTochki.back().y - dolnaDqsna.y);

    int liceTarseno = cqloLice - (liceDolenTriagalnik + liceDolenTrapec + liceGorenTrapec + dopalnitelnoLice);

    return liceTarseno;
}

int main(){

    cin>>maxX>>maxY;

    zavartiPravoagalnika();

    //cout<<dolnaLqva.x<<" "<<dolnaLqva.y<<"  "<<gornaLqva.x<<" "<<gornaLqva.y<<"  "<<gornaDqsna.x<<" "<<gornaDqsna.y<<"  "<<dolnaDqsna.x<<" "<<dolnaDqsna.y<<endl;

    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        int x;
        int y;
        cin>>x>>y;

        tochki.push_back(zavartiTochkata({x, y}));
    }

    int liceto = nameriSegaLiceto();

    cout<<liceto<<endl;

    return 0;
}
