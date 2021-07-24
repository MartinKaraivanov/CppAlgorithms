#include<iostream>
using namespace std;

int broiGradove;
int broiBolniciZaPostavqne;

int razstOtNachalotoDoTuk[1001];

int razstMezhduTeziDvete(int poLqv, int poDesen){
    return razstOtNachalotoDoTuk[poDesen] - razstOtNachalotoDoTuk[poLqv];
}

int broiBolnicPriTakovaD(int d){
    int broiSlozheni = 0;

    int parviBezBolnica = 0;
    int poslednaBolnica = 0;
    bool imameLiBolnica = false;
    for(int i = 0; i < broiGradove; i++){
        if(imameLiBolnica == false){
            if(razstMezhduTeziDvete(parviBezBolnica, i) > d){
                imameLiBolnica = true;
                poslednaBolnica = i - 1;
                broiSlozheni++;
            }
        }
        if(imameLiBolnica == true){
            if(razstMezhduTeziDvete(poslednaBolnica, i) > d){
                imameLiBolnica = false;
                parviBezBolnica = i;
            }
        }
    }

    if(imameLiBolnica == false){
        broiSlozheni++;
    }

    return broiSlozheni;
}

int main(){
    cin>>broiGradove>>broiBolniciZaPostavqne;

    for(int i = 1; i < broiGradove; i++){
        int doNego;
        cin>>doNego;
        razstOtNachalotoDoTuk[i] = doNego + razstOtNachalotoDoTuk[i - 1];
    }

    int celiqPat = razstOtNachalotoDoTuk[broiGradove - 1];

    int hubavoD = 0;

    /*for(int d = 0; d < celiqPat; d++){
        int broiSlozheni = broiBolnicPriTakovaD(d);
        //cout<<endl<<d<<" "<<broiSlozheni<<endl;
        if(broiSlozheni <= broiBolniciZaPostavqne){
            hubavoD = d;
            break;
        }
    }*/

    int lqvo = 0;
    int dqsno = celiqPat;

    while(lqvo < dqsno){
        int poSredata = (lqvo + dqsno)/2;

        int kolkoSheSlozhim = broiBolnicPriTakovaD(poSredata);

        if(kolkoSheSlozhim <= broiBolniciZaPostavqne){
            dqsno = poSredata;
        }else{
            lqvo = poSredata + 1;
        }
    }

    hubavoD = lqvo;

    cout<<hubavoD<<endl;

    return 0;
}
