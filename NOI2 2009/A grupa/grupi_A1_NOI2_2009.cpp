#include<iostream>
using namespace std;

long long broiSlujiteli;
long long broiIzlojeniq;

long long priTolkova[1024][1024];

long long kolkoVazmozhni(long long kolkoHora, long long zaKolkoIzlojeniq){
    if(zaKolkoIzlojeniq == 0){
        if(kolkoHora == 0){
            return 1;
        }else{
            return 0;
        }
    }
    if(kolkoHora < 0){
        return 0;
    }

    if(priTolkova[kolkoHora][zaKolkoIzlojeniq] > -1){
        return priTolkova[kolkoHora][zaKolkoIzlojeniq];
    }

    long long brTuka = 0;

    /*for(long long i = 0; i <= kolkoHora; i++){
        brTuka += kolkoVazmozhni(kolkoHora - i*zaKolkoIzlojeniq, zaKolkoIzlojeniq - 1);
    }*/

    brTuka += kolkoVazmozhni(kolkoHora, zaKolkoIzlojeniq - 1) + kolkoVazmozhni(kolkoHora - zaKolkoIzlojeniq, zaKolkoIzlojeniq);

    priTolkova[kolkoHora][zaKolkoIzlojeniq] = brTuka;
    return brTuka;
}

long long priTolkova2[2][1024];

long long sCycli(long long zaKolkoHora, long long zaZaKolkoIzlojeniq){
    priTolkova2[0][0] = 1;

    for(long long zaKolkoIzlojeniq = 1; zaKolkoIzlojeniq <= zaZaKolkoIzlojeniq; zaKolkoIzlojeniq++){
        for(long long kolkoHora = 0; kolkoHora <= zaKolkoHora; kolkoHora++){
            long long brTuka = priTolkova2[(zaKolkoIzlojeniq - 1)%2][kolkoHora];
            if(kolkoHora >= zaKolkoIzlojeniq){
                brTuka += priTolkova2[zaKolkoIzlojeniq%2][kolkoHora - zaKolkoIzlojeniq];
            }

            priTolkova2[zaKolkoIzlojeniq%2][kolkoHora] = brTuka;
        }
    }

    return priTolkova2[zaZaKolkoIzlojeniq%2][zaKolkoHora];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSlujiteli>>broiIzlojeniq;

    /*for(long long i = 0; i <= broiSlujiteli; i++){
        for(long long j = 0; j <= broiIzlojeniq; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    //long long broiVazmojnosti = kolkoVazmozhni(broiSlujiteli - broiIzlojeniq, broiIzlojeniq);
    long long broiVazmojnosti = sCycli(broiSlujiteli - broiIzlojeniq, broiIzlojeniq);

    cout<<broiVazmojnosti<<endl;

    return 0;
}
