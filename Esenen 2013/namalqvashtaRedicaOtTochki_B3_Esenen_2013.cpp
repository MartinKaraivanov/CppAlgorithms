#include<iostream>
#include<map>
#include<vector>
using namespace std;

const long long priKolkoOstatuk = 123456789;

int broiTochki;

int sborNaKoordinati[10010];

long long priTolkova[10005];

/*long long broiRedici(int doKoqTochka, int doKolkoY){
    if(doKoqTochka == 0){
        return 1;
    }

    if(priTolkova[doKoqTochka][doKolkoY] > -1){
        return priTolkova[doKoqTochka][doKolkoY];
    }

    long long zaTuk = 0;

    for(int sledvashtY = 0; sledvashtY <= min(doKolkoY, sborNaKoordinati[doKoqTochka]); sledvashtY++){
        int sledvashtX = sborNaKoordinati[doKoqTochka] - sledvashtY;

        int predenX = sborNaKoordinati[doKoqTochka + 1] - doKolkoY;

        if(sledvashtX >= predenX && sledvashtY <= doKolkoY){
            zaTuk = (zaTuk + broiRedici(doKoqTochka - 1, sledvashtY))%priKolkoOstatuk;
        }
    }

    priTolkova[doKoqTochka][doKolkoY] = zaTuk;
    return zaTuk;
}*/

long long sborOtNachalotoDoTuk[10005];

long long sCycli(int zaDoKoqTochka, int zaDoKolkoX){
    for(int x = 0; x <= sborNaKoordinati[1]; x++){
        priTolkova[x] = 1;
        sborOtNachalotoDoTuk[x] = (x+1);
    }

    for(int doKoqTochka = 2; doKoqTochka <= zaDoKoqTochka; doKoqTochka++){

        for(int zaKoiX = 0; zaKoiX <= sborNaKoordinati[doKoqTochka]; zaKoiX++){
            int zaKoiY = sborNaKoordinati[doKoqTochka] - zaKoiX;

            if(sborNaKoordinati[doKoqTochka - 1] - zaKoiY < 0){
                priTolkova[zaKoiX] = 0;
            }else{

                long long doKoiPredishenX =
                    min(zaKoiX, min(sborNaKoordinati[doKoqTochka - 1], sborNaKoordinati[doKoqTochka - 1] - zaKoiY));

                priTolkova[zaKoiX] = sborOtNachalotoDoTuk[doKoiPredishenX];
            }
        }

        for(int i = sborNaKoordinati[doKoqTochka] + 1; i <= zaDoKolkoX; i++){
            priTolkova[i] = 0;
        }

        sborOtNachalotoDoTuk[0] = priTolkova[0];

        for(int i = 1; i <= zaDoKolkoX; i++){
            sborOtNachalotoDoTuk[i] = (sborOtNachalotoDoTuk[i - 1] + priTolkova[i])%priKolkoOstatuk;
        }

    }

    return sborOtNachalotoDoTuk[zaDoKolkoX];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiTochki;

    for(int i = 1; i <= broiTochki; i++){
        cin>>sborNaKoordinati[i];
    }

    /*for(int i = 0; i <= broiTochki; i++){
        for(int j = 0; j <= 10001; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    long long broiNamalqvashtiRedici = sCycli(broiTochki, 10000)%priKolkoOstatuk;
    //long long broiNamalqvashtiRedici = broiRedici(broiTochki, 10001)%priKolkoOstatuk;

    cout<<broiNamalqvashtiRedici<<endl;

    return 0;
}
