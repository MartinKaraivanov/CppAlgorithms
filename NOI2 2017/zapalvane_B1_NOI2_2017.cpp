#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct DanniZaTochkata{
    int x;
    int y;
};

struct DanniZaPrevlagalnika{
    DanniZaTochkata gornaLqvaTochka;
    int dalzhina;
    int shirina;
};

int maxX;
int maxY;

int broiPrevlagalnici;
int broiPitaniq;

DanniZaPrevlagalnika prevlagalnici[11010];

vector<int> sasedstvo[11010];

bool tochkataVPravoagalnikaLiE(DanniZaTochkata tochka, DanniZaPrevlagalnika pravoagalnik){
    if(pravoagalnik.gornaLqvaTochka.x < tochka.x &&
       pravoagalnik.gornaLqvaTochka.x + pravoagalnik.dalzhina > tochka.x &&
       pravoagalnik.gornaLqvaTochka.y < tochka.y &&
       pravoagalnik.gornaLqvaTochka.y + pravoagalnik.shirina > tochka.y)
    {
        return true;
    }else{
        return false;
    }
}

bool pravoagalnikaVDrugiqLiE(DanniZaPrevlagalnika vatreshen, DanniZaPrevlagalnika vanshen){
    return tochkataVPravoagalnikaLiE(vatreshen.gornaLqvaTochka, vanshen);
}

int vKoiTochnoPravoagalnikSeNamiraTochkata(DanniZaTochkata tochica){
    int segashenPrevlagalnikVKoitoE = 0;
    bool nameriliLSme = true;

    while(nameriliLSme){
        nameriliLSme = false;

        for(unsigned int j = 0; j < sasedstvo[segashenPrevlagalnikVKoitoE].size(); j++){
            if(tochkataVPravoagalnikaLiE(tochica, prevlagalnici[sasedstvo[segashenPrevlagalnikVKoitoE][j]])){
                nameriliLSme = true;
                segashenPrevlagalnikVKoitoE = sasedstvo[segashenPrevlagalnikVKoitoE][j];
                break;
            }
        }
    }

    return segashenPrevlagalnikVKoitoE;
}

int liceNaTeziVatreVNego(int koiPrevlagalnik){
    int lichiceNaVatreshniteVNego = 0;

    for(unsigned int j = 0; j < sasedstvo[koiPrevlagalnik].size(); j++){
        lichiceNaVatreshniteVNego += prevlagalnici[sasedstvo[koiPrevlagalnik][j]].dalzhina*
            prevlagalnici[sasedstvo[koiPrevlagalnik][j]].shirina;
    }

    return lichiceNaVatreshniteVNego;
}

void praveneNaSasedstvoto(){
    for(int i = 1; i <= broiPrevlagalnici; i++){
        int razstoqnie = 1000000;
        int vKoiTochnoE = -1;
        for(int j = 0; j <= broiPrevlagalnici; j++){
            if(pravoagalnikaVDrugiqLiE(prevlagalnici[i], prevlagalnici[j])){
                int segashnoRazstoqnie = abs(prevlagalnici[i].gornaLqvaTochka.x -  prevlagalnici[j].gornaLqvaTochka.x) +
                    abs(prevlagalnici[i].gornaLqvaTochka.y - prevlagalnici[j].gornaLqvaTochka.y);
                if(segashnoRazstoqnie < razstoqnie){
                    razstoqnie = segashnoRazstoqnie;
                    vKoiTochnoE = j;
                }
            }
        }

        sasedstvo[vKoiTochnoE].push_back(i);
    }
}

void barzoPraveneNaSasedstvo(){
    for(int i = 1; i <= broiPrevlagalnici; i++){
        int vKoiTrqbvaDaSeSlozhi = vKoiTochnoPravoagalnikSeNamiraTochkata(prevlagalnici[i].gornaLqvaTochka);
        unsigned int j = 0;
        while(j < sasedstvo[vKoiTrqbvaDaSeSlozhi].size()){
            if(pravoagalnikaVDrugiqLiE(prevlagalnici[sasedstvo[vKoiTrqbvaDaSeSlozhi][j]], prevlagalnici[i])){
                int zaMahane = sasedstvo[vKoiTrqbvaDaSeSlozhi][j];

                /// Barzo iztrivane:
                sasedstvo[vKoiTrqbvaDaSeSlozhi][j] = sasedstvo[vKoiTrqbvaDaSeSlozhi][sasedstvo[vKoiTrqbvaDaSeSlozhi].size() - 1];
                sasedstvo[vKoiTrqbvaDaSeSlozhi].pop_back();

                sasedstvo[i].push_back(zaMahane);
            }else{
                j++;
            }
        }

        sasedstvo[vKoiTrqbvaDaSeSlozhi].push_back(i);
    }
}

int main(){
    cin>>maxX>>maxY;

    cin>>broiPrevlagalnici;

    DanniZaTochkata nulaNula = {0, 0};
    DanniZaPrevlagalnika golemiq = {nulaNula, maxX, maxY};
    prevlagalnici[0] = golemiq;

    for(int i = 1; i <= broiPrevlagalnici; i++){
        int gorenLqvX;
        int gorenLqvY;
        int dalzhina;
        int shirina;
        cin>>gorenLqvX>>gorenLqvY>>dalzhina>>shirina;

        DanniZaTochkata tochica = {gorenLqvX, gorenLqvY};
        DanniZaPrevlagalnika zaDob = {tochica, dalzhina, shirina};

        prevlagalnici[i] = zaDob;
    }

    barzoPraveneNaSasedstvo();

    cin>>broiPitaniq;

    int otgovori[11010];

    for(int i = 0; i < broiPitaniq; i++){
        int xche;
        int yche;
        cin>>xche>>yche;
        DanniZaTochkata tochica = {xche, yche};

        int vKoiTochnoE = vKoiTochnoPravoagalnikSeNamiraTochkata(tochica);

        int lichiceNaTeziVatreVNego = liceNaTeziVatreVNego(vKoiTochnoE);

        int sobstvenoLichice = prevlagalnici[vKoiTochnoE].dalzhina *
            prevlagalnici[vKoiTochnoE].shirina;

        int lichiceNaTamKadetoETochkata = sobstvenoLichice - lichiceNaTeziVatreVNego;

        otgovori[i] = lichiceNaTamKadetoETochkata;
    }

    for(int i = 0; i < broiPitaniq; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
