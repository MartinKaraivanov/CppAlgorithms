#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Danni{
    long long stranici;
    double cena;
};

long long broiRazkazi;
long long dopustimBroiStranici;

Danni razkazi[1100];

double NaiDobroPriTolkova[1100][1100];

double maksimalnaCena(long long broiStranici, long long indexNaiGolqm){
    if(broiStranici == 0){
        return 0;
    }
    if(broiStranici < 0){
        return -300000000;
    }

    if(indexNaiGolqm < 0){
        return 0;
    }

    if(NaiDobroPriTolkova[broiStranici][indexNaiGolqm] > -1){
        return NaiDobroPriTolkova[broiStranici][indexNaiGolqm];
    }

    double naiDobroto = 0;

    double susTazi = razkazi[indexNaiGolqm].cena +
        maksimalnaCena(broiStranici-razkazi[indexNaiGolqm].stranici, indexNaiGolqm-1);
    double bezTazi = maksimalnaCena(broiStranici, indexNaiGolqm-1);

    naiDobroto = max(susTazi, bezTazi);

    NaiDobroPriTolkova[broiStranici][indexNaiGolqm] = naiDobroto;
    return naiDobroto;
}

bool poMalkoLiE(Danni a, Danni b){
    if(a.stranici < b.stranici){
        return true;
    }else{
        if(a.stranici > b.stranici){
            return false;
        }else{
            return a.cena<b.cena;
        }
    }
}

int main(){
    cin>>broiRazkazi>>dopustimBroiStranici;

    for(long long i = 0; i < broiRazkazi; i++){
        cin>>razkazi[i].stranici>>razkazi[i].cena;
    }

    sort(razkazi, razkazi + broiRazkazi, poMalkoLiE);

    for(int i = 0; i < 1100; i++){
        for(int j = 0; j < 1100; j++){
            NaiDobroPriTolkova[i][j] = -1;
        }
    }

    double naiDobraPechalba = maksimalnaCena(dopustimBroiStranici, broiRazkazi - 1);

    cout<<fixed<<setprecision(2);

    cout<<naiDobraPechalba<<endl;

    return 0;
}
