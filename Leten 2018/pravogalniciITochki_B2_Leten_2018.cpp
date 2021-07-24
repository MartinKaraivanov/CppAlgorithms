#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
    int vidNaTochkata;
    /// 0 - svoodna, 1 - dolnaLqva, 2 - dolna dqsna, 3 - gorna lqva, 4 - gorna dqsna;
    int nomerNaPravoag;
};

vector<DanniZaTochka> tochki;

int broiPravoagalnici;
int otgovori[100010];


//DanniZaPravoag pravoagalnici[100010];

//bool tukImaLiTochka[10000][10000];
//int broiTochkiOtNachalotoDoTuk[10000][10000];

int broiTochkiVToziY[2500010];

int neobhodimiVarhoveZaDarvoto = 2500000;

inline int daiListo(int index){
    return index + (neobhodimiVarhoveZaDarvoto >> 1);
}

inline void updatevane(int koiIndex){
    int segashenIndex = daiListo(koiIndex);
    while(segashenIndex > 0){
        broiTochkiVToziY[segashenIndex]++;
        segashenIndex >>= 1;
    }
}

inline int kolkoESumataOtDo(int otKade, int doKade){
    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(lqvIndex == desenIndex){
        return broiTochkiVToziY[lqvIndex];
    }

    int sbor = broiTochkiVToziY[lqvIndex] + broiTochkiVToziY[desenIndex];

    while(lqvIndex + 1 != desenIndex){
        if((lqvIndex & 1) == 0){
            sbor += broiTochkiVToziY[lqvIndex + 1];
        }
        if((desenIndex & 1) == 1){
            sbor += broiTochkiVToziY[desenIndex - 1];
        }

        lqvIndex >>= 1;
        desenIndex >>= 1;
    }

    return sbor;
}

bool poMalkaLiE(DanniZaTochka a, DanniZaTochka b){
    if(a.x < b.x){
        return true;
    }
    if(a.x > b.x){
        return false;
    }
    if(a.y < b.y){
        return true;
    }
    if(a.y > b.y){
        return false;
    }
    return a.vidNaTochkata < b.vidNaTochkata;
}

inline void uvelichavaneNaToziYigrek(int y){
    updatevane(y);
}

inline int smqtaneNaDoToziY(int doKoiY){
    return kolkoESumataOtDo(0, doKoiY);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int broiTochki;
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        int x;
        int y;
        cin>>x>>y;

        x++;
        y++;

        tochki.push_back({x, y, 0, -1});
    }

    cin>>broiPravoagalnici;

    for(int i = 0; i < broiPravoagalnici; i++){
        int malakX;
        int malakY;
        int golqmX;
        int golqmY;

        cin>>malakX>>malakY>>golqmX>>golqmY;

        malakX++;
        malakY++;
        golqmX++;
        golqmY++;

        if(malakX > golqmX){
            swap(malakX, golqmX);
        }
        if(malakY > golqmY){
            swap(malakY, golqmY);
        }

        tochki.push_back({malakX - 1, malakY - 1, 1, i});
        tochki.push_back({golqmX, malakY - 1, 2, i});
        tochki.push_back({malakX - 1, golqmY, 3, i});
        tochki.push_back({golqmX, golqmY, 4, i});
    }

    sort(tochki.begin(), tochki.end(), poMalkaLiE);

    for(unsigned int i = 0; i < tochki.size(); i++){
        //cout<<i<<" "<<tochki[i].x<<" "<<tochki[i].y<<" "<<tochki[i].vidNaTochkata<<" "<<tochki[i].nomerNaPravoag<<endl;

        if(tochki[i].vidNaTochkata == 0){
            uvelichavaneNaToziYigrek(tochki[i].y);
        }else{
            int broiDoTaziTochka = smqtaneNaDoToziY(tochki[i].y);

            //cout<<"do tochka s indexi "<<tochki[i].x - 1<<" "<<tochki[i].y - 1<<" ima "<<broiDoTaziTochka<<endl;

            if(tochki[i].vidNaTochkata == 1 || tochki[i].vidNaTochkata == 4){
                otgovori[tochki[i].nomerNaPravoag] += broiDoTaziTochka;
            }else{
                otgovori[tochki[i].nomerNaPravoag] -= broiDoTaziTochka;
            }

        }
    }

    for(int i = 0; i < broiPravoagalnici; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
