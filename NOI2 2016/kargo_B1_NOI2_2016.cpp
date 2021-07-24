#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaPorachkata{
    int nachalo;
    int krai;
};

int broiPlaniraniDni;
int broiPorachki;
int broiPiloti;

int broiEkipazhi;

DanniZaPorachkata porachki[1000010];

int sledvashtDen(int den, bool susSabotaINedelqLi){
    if(susSabotaINedelqLi == false){
        if(den%7 == 5){
            return den+3;
        }
        if(den%7 == 6){
            return den+2;
        }
    }
    return den+1;
}

bool mozheLiTaka(bool susSabotaINedelqLi){
    int den = 1;
    int broiIzpolzvaniEkipazhiToziDen = 0;
    int naKoqPorachkaSme = 0;

    while(den <= porachki[naKoqPorachkaSme].krai){
        if(den >= porachki[naKoqPorachkaSme].nachalo){
            broiIzpolzvaniEkipazhiToziDen++;
            naKoqPorachkaSme++;
        }else{
            den = sledvashtDen(den, susSabotaINedelqLi);
            broiIzpolzvaniEkipazhiToziDen = 0;
        }
        if(broiIzpolzvaniEkipazhiToziDen == broiEkipazhi){
            den = sledvashtDen(den, susSabotaINedelqLi);
            broiIzpolzvaniEkipazhiToziDen = 0;
        }
    }

    if(naKoqPorachkaSme == broiPorachki){
        return true;
    }
    return false;
}

bool mozheLiTakDve2(bool susSabotaINedelqLi){
    int den = 1;
    int broiSvobodniEkipazhi = broiEkipazhi;

    for(int i = 0; i < broiPorachki; i++){
        if(porachki[i].nachalo > den){
            den = sledvashtDen(porachki[i].nachalo - 1, susSabotaINedelqLi);
            broiSvobodniEkipazhi = broiEkipazhi;
        }

        if(broiSvobodniEkipazhi == 0){
            den = sledvashtDen(den, susSabotaINedelqLi);
            broiSvobodniEkipazhi = broiEkipazhi;
        }

        if(den <= porachki[i].krai){
            broiSvobodniEkipazhi--;
        }else{
            return false;
        }
    }

    return true;
}

bool poMalkoLiE(DanniZaPorachkata a, DanniZaPorachkata b){
    if(a.nachalo < b.nachalo){
        return true;
    }else{
        if(a.nachalo > b.nachalo){
            return false;
        }else{
            return a.krai < b.krai;
        }
    }
}

int main(){
    cin>>broiPlaniraniDni>>broiPorachki>>broiPiloti;

    for(int i = 0; i < broiPorachki; i++){
        cin>>porachki[i].nachalo>>porachki[i].krai;
    }

    sort(porachki, porachki + broiPorachki, poMalkoLiE);

    broiEkipazhi = broiPiloti/2;

    bool mozheLiBezSabotaINedelq = mozheLiTakDve2(false);

    if(mozheLiBezSabotaINedelq == true){
        cout<<"OK"<<endl;
        return 0;
    }

    bool mozheLiSus = mozheLiTakDve2(true);

    if(mozheLiSus == true){
        cout<<"MIXED"<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
