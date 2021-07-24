#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaTochkata{
    int kadeE;
    int kakavVidE;
    int tochkovIndex;
};

int broiOtsechki;
int broiTochki;

DanniZaTochkata tochki[300010];
int broiTochkiPoPravata;

int otgovori[100010];

bool poNapredLiE(DanniZaTochkata a, DanniZaTochkata b){
    if(a.kadeE < b.kadeE){
        return true;
    }else{
        if(a.kadeE > b.kadeE){
            return false;
        }else{
            return a.kakavVidE < b.kakavVidE;
        }
    }
}

int main(){
    cin>>broiOtsechki>>broiTochki;

    for(int i = 0; i < broiOtsechki; i++){
        int nachalo;
        int krai;
        cin>>nachalo>>krai;
        if(nachalo > krai){
            swap(nachalo, krai);
        }

        /// za nachalo - 1 ; za krai - 3; za tochka - 2

        tochki[broiTochkiPoPravata].kadeE = nachalo;
        tochki[broiTochkiPoPravata].kakavVidE = 1;
        broiTochkiPoPravata++;

        tochki[broiTochkiPoPravata].kadeE = krai;
        tochki[broiTochkiPoPravata].kakavVidE = 3;
        broiTochkiPoPravata++;
    }

    for(int i = 0; i < broiTochki; i++){
        cin>>tochki[broiTochkiPoPravata].kadeE;
        tochki[broiTochkiPoPravata].kakavVidE = 2;
        tochki[broiTochkiPoPravata].tochkovIndex = i;
        broiTochkiPoPravata++;
    }

    sort(tochki, tochki + broiTochkiPoPravata, poNapredLiE);

    int vKolkoOtsechkiSme = 0;
    for(int i = 0; i < broiTochkiPoPravata; i++){
        if(tochki[i].kakavVidE == 1){
            vKolkoOtsechkiSme++;
            continue;
        }
        if(tochki[i].kakavVidE == 3){
            vKolkoOtsechkiSme--;
            continue;
        }
        otgovori[tochki[i].tochkovIndex] = vKolkoOtsechkiSme;
    }

    for(int i = 0; i < broiTochki; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
