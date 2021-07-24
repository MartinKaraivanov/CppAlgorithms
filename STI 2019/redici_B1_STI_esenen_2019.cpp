#include<iostream>
using namespace std;

int dalzhinaNaRedicata;
int maximalnaDalzhinaNaPodredica;

const int mnogo = 1000000007;

int priTolkova[2005][2005];

int maximalenBroiHubaviRedici(int segashnaPoziciq, int otKakuvPravim){
    if(segashnaPoziciq == 1 && (otKakuvPravim == 0 || otKakuvPravim == 1)){
        return 1;
    }

    if(priTolkova[segashnaPoziciq][otKakuvPravim] > -1){
        return priTolkova[segashnaPoziciq][otKakuvPravim];
    }

    int zaTuk = 0;

    if(otKakuvPravim > 0){
        zaTuk = (zaTuk + maximalenBroiHubaviRedici(segashnaPoziciq - 1, otKakuvPravim - 1))%mnogo;
    }else{
        for(int i = 0; i < min(maximalnaDalzhinaNaPodredica, segashnaPoziciq - 1); i++){
            zaTuk = (zaTuk + maximalenBroiHubaviRedici(segashnaPoziciq - 1, i)) % mnogo;
        }
    }

    int zaVrasht = zaTuk%mnogo;

    priTolkova[segashnaPoziciq][otKakuvPravim] = zaVrasht;
    return zaVrasht;
}

int sCycli(int zaKoqPoziciq, int zaOtKudeIdvame){
    priTolkova[1][0] = 1;
    priTolkova[1][1] = 1;

    for(int segashnaPoziciq = 2; segashnaPoziciq <= zaKoqPoziciq; segashnaPoziciq++){
        for(int otKakuvPravim = 0; otKakuvPravim <= maximalnaDalzhinaNaPodredica; otKakuvPravim++){
            int zaTuk = 0;

            if(otKakuvPravim > 0){
                zaTuk = (zaTuk + priTolkova[segashnaPoziciq - 1][otKakuvPravim - 1])%mnogo;
            }else{
                for(int i = 0; i < min(maximalnaDalzhinaNaPodredica, segashnaPoziciq - 1); i++){
                    zaTuk = (zaTuk + priTolkova[segashnaPoziciq - 1][i]) % mnogo;
                }
            }

            int zaVrasht = zaTuk%mnogo;

            priTolkova[segashnaPoziciq][otKakuvPravim] = zaVrasht;
        }
    }

    return priTolkova[zaKoqPoziciq][zaOtKudeIdvame];
}

int priTolkova2[2][2000005];

int sCycli2(int zaKoqPoziciq, int zaOtKudeIdvame){
    priTolkova2[1][0] = 1;
    priTolkova2[1][1] = 1;

    for(int segashnaPoziciq = 2; segashnaPoziciq <= (dalzhinaNaRedicata + 1); segashnaPoziciq++){
        for(int otKakuvPravim = 0; otKakuvPravim <= maximalnaDalzhinaNaPodredica; otKakuvPravim++){
            int zaTuk = 0;

            if(otKakuvPravim > 0){
                zaTuk = (zaTuk + priTolkova2[(segashnaPoziciq - 1)%2][otKakuvPravim - 1])%mnogo;
            }else{
                for(int i = 0; i < min(maximalnaDalzhinaNaPodredica, segashnaPoziciq - 1); i++){
                    zaTuk = (zaTuk + priTolkova2[(segashnaPoziciq - 1)%2][i]) % mnogo;
                }
            }

            int zaVrasht = zaTuk%mnogo;

            priTolkova2[segashnaPoziciq%2][otKakuvPravim] = zaVrasht;
        }
    }

    return priTolkova2[zaKoqPoziciq%2][zaOtKudeIdvame];
}

int main(){
    cin>>dalzhinaNaRedicata>>maximalnaDalzhinaNaPodredica;

    /*for(int i = 0; i <= dalzhinaNaRedicata + 1; i++){
        for(int j = 0; j <= maximalnaDalzhinaNaPodredica; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    //int broiVazmozhni = maximalenBroiHubaviRedici(dalzhinaNaRedicata + 1, 0)%mnogo;
    //int broiVazmozhni = sCycli(dalzhinaNaRedicata + 1, 0)%mnogo;
    int broiVazmozhni = sCycli2(dalzhinaNaRedicata + 1, 0);

    cout<<broiVazmozhni<<endl;

    return 0;
}
