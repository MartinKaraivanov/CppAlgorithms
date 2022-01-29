#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int broiKvadrati;

struct Koordinati{
    int x;
    int y;
};

struct DanniZaPrava{
    int a;
    int b;
    int c;
};

struct DanniZaOtsechka{
    Koordinati edinKrai;
    Koordinati vtoriKrai;
};

struct DanniZaKvadrat{
    Koordinati parvaTochka;
    Koordinati vtoraTochka;
    Koordinati tretaTochka;
    Koordinati chetvartaTochka;
};

DanniZaKvadrat kvadrati[1024];

DanniZaPrava pravataNaDveTochki(Koordinati parva, Koordinati vtora){
    int a = parva.y - vtora.y;
    int b = vtora.x - parva.x;
    int c = parva.x*vtora.y - vtora.x*parva.y;

    return {a, b, c};
}

int tochkataKadeSprqmoPravataE(DanniZaPrava prava, Koordinati tochka){

    int sborche = prava.a*tochka.x + prava.b*tochka.y + prava.c;

    if(sborche == 0){
        return 0;
    }
    if(sborche > 0){
        return 1;
    }
    return -1;
}

Koordinati obratnataTochkaSprqmoCentura(Koordinati centur, Koordinati tochka){
    int razlikaVX = centur.x - tochka.x;
    int razlikavY = centur.y - tochka.y;

    Koordinati drugataTochka = {centur.x + razlikaVX, centur.y + razlikavY};

    return drugataTochka;
}

DanniZaKvadrat napraviKvadrat(Koordinati centar, Koordinati vrah){

    int razlikaVX = centar.x - vrah.x;
    int razlikaVY = centar.y - vrah.y;

    Koordinati parva = vrah;
    Koordinati vtoraTochka = {centar.x - razlikaVY, centar.y + razlikaVX};
    Koordinati tretaTochka = obratnataTochkaSprqmoCentura(centar, vrah);
    //Koordinati chetvartaTochka = {centar.x - razlikaVY, centar.y - razlikaVX};
    Koordinati chetvartaTochka = obratnataTochkaSprqmoCentura(centar, vtoraTochka);

    return {parva, vtoraTochka, tretaTochka, chetvartaTochka};
}

bool sprqmoPravataRazdelniLiSa(DanniZaPrava prava, Koordinati ednaNasha, Koordinati drugaNasha, DanniZaKvadrat kvadr){
    int nashtaParvaOtKade = tochkataKadeSprqmoPravataE(prava, ednaNasha);
    int nashtaVtoraOtKade = tochkataKadeSprqmoPravataE(prava, drugaNasha);

    int otKadeEParva = tochkataKadeSprqmoPravataE(prava, kvadr.parvaTochka);
    int otKadeEVtora = tochkataKadeSprqmoPravataE(prava, kvadr.vtoraTochka);
    int otKadeETreta = tochkataKadeSprqmoPravataE(prava, kvadr.tretaTochka);
    int otKadeEChetv = tochkataKadeSprqmoPravataE(prava, kvadr.chetvartaTochka);

    if(nashtaParvaOtKade == otKadeEParva || nashtaParvaOtKade == otKadeEVtora || nashtaParvaOtKade == otKadeETreta || nashtaParvaOtKade == otKadeEChetv ||
        nashtaVtoraOtKade == otKadeEParva || nashtaVtoraOtKade == otKadeEVtora || nashtaVtoraOtKade == otKadeETreta || nashtaVtoraOtKade == otKadeEChetv)
    {
        return false;
    }

    return true;
}

bool teziZastapvatLiSe(DanniZaKvadrat parvi, DanniZaKvadrat vtori){

    DanniZaPrava p1 = pravataNaDveTochki(parvi.parvaTochka, parvi.vtoraTochka);
    DanniZaPrava p2 = pravataNaDveTochki(parvi.vtoraTochka, parvi.tretaTochka);
    DanniZaPrava p3 = pravataNaDveTochki(parvi.tretaTochka, parvi.chetvartaTochka);
    DanniZaPrava p4 = pravataNaDveTochki(parvi.chetvartaTochka, parvi.parvaTochka);

    DanniZaPrava v1 = pravataNaDveTochki(vtori.parvaTochka, vtori.vtoraTochka);
    DanniZaPrava v2 = pravataNaDveTochki(vtori.vtoraTochka, vtori.tretaTochka);
    DanniZaPrava v3 = pravataNaDveTochki(vtori.tretaTochka, vtori.chetvartaTochka);
    DanniZaPrava v4 = pravataNaDveTochki(vtori.chetvartaTochka, vtori.parvaTochka);

    if(sprqmoPravataRazdelniLiSa(p1, parvi.tretaTochka, parvi.chetvartaTochka, vtori) ||
        sprqmoPravataRazdelniLiSa(p2, parvi.chetvartaTochka, parvi.parvaTochka, vtori) ||
        sprqmoPravataRazdelniLiSa(p3, parvi.parvaTochka, parvi.vtoraTochka, vtori) ||
        sprqmoPravataRazdelniLiSa(p4, parvi.vtoraTochka, parvi.tretaTochka, vtori) ||
        sprqmoPravataRazdelniLiSa(v1, vtori.tretaTochka, vtori.chetvartaTochka, parvi) ||
        sprqmoPravataRazdelniLiSa(v2, vtori.chetvartaTochka, vtori.parvaTochka, parvi) ||
        sprqmoPravataRazdelniLiSa(v3, vtori.parvaTochka, vtori.vtoraTochka, parvi) ||
        sprqmoPravataRazdelniLiSa(v4, vtori.vtoraTochka, vtori.tretaTochka, parvi))
    {
        return false;
    }

    return true;
}

vector<int> sasedstvo[1024];

int dalbochina[1024];

void bfs(){

    for(int i = 0; i < broiKvadrati; i++){
        dalbochina[i] = -1;
    }

    queue<int> q;

    q.push(0);
    dalbochina[0] = 0;

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        if(naiOtpred == broiKvadrati - 1){
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred].size(); i++){
            int sledvasht = sasedstvo[naiOtpred][i];
            if(dalbochina[sledvasht] == -1){
                q.push(sledvasht);
                dalbochina[sledvasht] = dalbochina[naiOtpred] + 1;
            }
        }
    }

}

int main(){

    cin>>broiKvadrati;

    for(int i = 0; i < broiKvadrati; i++){
        Koordinati centar;
        Koordinati nqkakvaTochka;

        cin>>centar.x>>centar.y>>nqkakvaTochka.x>>nqkakvaTochka.y;

        kvadrati[i] = napraviKvadrat(centar, nqkakvaTochka);
    }

    /*for(int i = 0; i < broiKvadrati; i++){
        cout<<i<<": "<<kvadrati[i].gornaLqva.x<<" "<<kvadrati[i].gornaLqva.y<<"   "<<kvadrati[i].dolnaDqsna.x<<" "<<kvadrati[i].dolnaDqsna.y<<endl;
    }*/

    /*cout<<kvadrati[0].parvaTochka.x<<" "<<kvadrati[0].parvaTochka.y<<endl;
    cout<<kvadrati[0].vtoraTochka.x<<" "<<kvadrati[0].vtoraTochka.y<<endl;
    cout<<kvadrati[0].tretaTochka.x<<" "<<kvadrati[0].tretaTochka.y<<endl;
    cout<<kvadrati[0].chetvartaTochka.x<<" "<<kvadrati[0].chetvartaTochka.y<<endl<<endl;

    cout<<kvadrati[1].parvaTochka.x<<" "<<kvadrati[1].parvaTochka.y<<endl;
    cout<<kvadrati[1].vtoraTochka.x<<" "<<kvadrati[1].vtoraTochka.y<<endl;
    cout<<kvadrati[1].tretaTochka.x<<" "<<kvadrati[1].tretaTochka.y<<endl;
    cout<<kvadrati[1].chetvartaTochka.x<<" "<<kvadrati[1].chetvartaTochka.y<<endl<<endl;

    cout<<kvadrati[2].parvaTochka.x<<" "<<kvadrati[2].parvaTochka.y<<endl;
    cout<<kvadrati[2].vtoraTochka.x<<" "<<kvadrati[2].vtoraTochka.y<<endl;
    cout<<kvadrati[2].tretaTochka.x<<" "<<kvadrati[2].tretaTochka.y<<endl;
    cout<<kvadrati[2].chetvartaTochka.x<<" "<<kvadrati[2].chetvartaTochka.y<<endl<<endl;

    cout<<teziZastapvatLiSe(kvadrati[0], kvadrati[1])<<endl;*/

    for(int i = 0; i < broiKvadrati; i++){
        for(int j = i + 1; j < broiKvadrati; j++){
            if(teziZastapvatLiSe(kvadrati[i], kvadrati[j])){
                sasedstvo[i].push_back(j);
                sasedstvo[j].push_back(i);
            }
        }
    }

    bfs();

    cout<<dalbochina[broiKvadrati - 1]<<endl;

    return 0;
}

