#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaOts{
    int nachalo;
    int krai;
};

struct DanniT{
    int kadeE;
    int nachalenIndex;
};

int broiOtsechki;
int broiTochki;

DanniZaOts otsechki[100010];
DanniT tochki[100010];

int otgovori[100010];


int indexaNaParviqElementPoGolqmIliRavenNaTova(int kakvoTarsim){
    int lqvo = 0;
    int dqsno = broiTochki - 1;

    while(lqvo < dqsno){
        int sreda = lqvo + (dqsno - lqvo) / 2;

        if(tochki[sreda].kadeE == kakvoTarsim){
            while(sreda > 0 && tochki[sreda - 1].kadeE == kakvoTarsim){
                sreda--;
            }
            return sreda;
        }

        if(tochki[sreda].kadeE < kakvoTarsim){
            lqvo = sreda;
        }

        if(tochki[sreda].kadeE > kakvoTarsim){
            dqsno = sreda;
        }
    }

    if(tochki[dqsno].kadeE >= kakvoTarsim){
        return dqsno;
    }else{
        return dqsno + 1;
    }
}


bool poNapredLiE(DanniT a, DanniT b){
    return a.kadeE < b.kadeE;
}

int main(){
    cin>>broiOtsechki>>broiTochki;

    for(int i = 0; i < broiOtsechki; i++){
        int nachalo;
        int krai;
        cin>>nachalo>>krai;
        otsechki[i].nachalo = min(nachalo, krai);
        otsechki[i].krai = max(nachalo, krai);
    }

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[i].kadeE;
        tochki[i].nachalenIndex = i;
    }

    sort(tochki, tochki+broiTochki, poNapredLiE);

    for(int j = 0; j < broiOtsechki; j++){
        int otKoiIndexDaPOchnem = indexaNaParviqElementPoGolqmIliRavenNaTova(otsechki[j].nachalo);
        for(int i = otKoiIndexDaPOchnem; i < broiTochki; i++){
            if(tochki[i].kadeE > otsechki[j].krai){
                break;
            }
            otgovori[tochki[i].nachalenIndex] ++ ;
        }
    }

    for(int i = 0; i < broiTochki; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
