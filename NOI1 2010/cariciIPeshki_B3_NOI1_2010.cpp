#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaFigurata{
    char bukvichka;
    int cifrichka;
    bool nabitaLiE;
};

DanniZaFigurata peshki[1000000];
int broiPeshki;

int daska[9][9];

DanniZaFigurata parvaCarica;
DanniZaFigurata vtoraCarica;

void popalvane(int xCarica, int yCarica, int sKolkoPromenqmeX, int sKolkoPromenqmeY){
    for(int x = xCarica, y = yCarica; x > 0 && x < 9 && y > 0 && y < 9; x += sKolkoPromenqmeX, y+=sKolkoPromenqmeY){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            peshki[daska[x][y] - 1].nabitaLiE = true;
            break;
        }
        //cout<<x<<" "<<y<<endl;
    }
}

int main(){
    char figurka;

    int koga = 0;

    while(cin>>figurka){
        if(koga % 2 == 0){
            peshki[broiPeshki].bukvichka = figurka;
        }else{
            peshki[broiPeshki].cifrichka = figurka - '0';
            broiPeshki++;
        }

        koga++;
    }

    parvaCarica = peshki[broiPeshki - 2];
    vtoraCarica = peshki[broiPeshki - 1];

    broiPeshki -= 2;

    int broiUceleniPeshki = 0;

    for(int i = 0; i < broiPeshki; i++){
        daska[peshki[i].bukvichka - 96][peshki[i].cifrichka] = i + 1;
        //cout<<peshki[i].bukvichka - 96<<" "<<peshki[i].cifrichka<<endl;
        //cout<<"Daskata: "<<daska[peshki[i].bukvichka - 96][peshki[i].cifrichka]<<endl;
    }

    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, 0, 1);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, 1, 0);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, 0, -1);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, -1, 0);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, 1, 1);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, -1, 1);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, 1, -1);
    popalvane(parvaCarica.bukvichka - 96, parvaCarica.cifrichka, -1, -1);

    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, 0, 1);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, 1, 0);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, 0, -1);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, -1, 0);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, 1, 1);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, -1, 1);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, 1, -1);
    popalvane(vtoraCarica.bukvichka - 96, vtoraCarica.cifrichka, -1, -1);

    /*for(int x = parvaCarica.bukvichka - 96; x < 9; x++){
        if(daska[x][parvaCarica.cifrichka] > 0 && daska[x][parvaCarica.cifrichka] <= broiPeshki){
            if(peshki[daska[x][parvaCarica.cifrichka] - 1].nabitaLiE == false){
                peshki[daska[x][parvaCarica.cifrichka] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][parvaCarica.cifrichka]<<endl;
            }
            //daska[x][parvaCarica.cifrichka] = broiPeshki + 1;
            break;
        }
        daska[x][parvaCarica.cifrichka] = broiPeshki + 1;
    }

    for(int x = parvaCarica.bukvichka - 96; x > 0; x--){
        if(daska[x][parvaCarica.cifrichka] > 0 && daska[x][parvaCarica.cifrichka] <= broiPeshki){
            if(peshki[daska[x][parvaCarica.cifrichka] - 1].nabitaLiE == false){
                peshki[daska[x][parvaCarica.cifrichka] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][parvaCarica.cifrichka];
            }
            //daska[x][parvaCarica.cifrichka] = broiPeshki + 1;
            break;
        }
        daska[x][parvaCarica.cifrichka] = broiPeshki + 1;
    }

    for(int y = parvaCarica.cifrichka; y > 0; y--){
        if(daska[parvaCarica.bukvichka - 96][y] > 0 && daska[parvaCarica.bukvichka - 96][y] <= broiPeshki){
            if(peshki[daska[parvaCarica.bukvichka - 96][y] - 1].nabitaLiE == false){
                peshki[daska[parvaCarica.bukvichka - 96][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[parvaCarica.bukvichka - 96][y]<<endl;
            }
            //daska[parvaCarica.bukvichka - 96][y] = broiPeshki + 1;
            break;
        }
        daska[parvaCarica.bukvichka - 96][y] = broiPeshki + 1;
    }

    for(int y = parvaCarica.cifrichka; y < 9; y++){
        if(daska[parvaCarica.bukvichka - 96][y] > 0 && daska[parvaCarica.bukvichka - 96][y] <= broiPeshki){
            if(peshki[daska[parvaCarica.bukvichka - 96][y] - 1].nabitaLiE == false){
                peshki[daska[parvaCarica.bukvichka - 96][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[parvaCarica.bukvichka - 96][y]<<endl;
            }
            //daska[parvaCarica.bukvichka - 96][y] = broiPeshki + 1;
            break;
        }
        daska[parvaCarica.bukvichka - 96][y] = broiPeshki + 1;
    }

    for(int x = parvaCarica.bukvichka - 96, y = parvaCarica.cifrichka; x > 0 && y > 0; x--, y--){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            //daska[x][y] = broiPeshki + 1;
            break;
        }
        daska[x][y] = broiPeshki + 1;
    }

    for(int x = parvaCarica.bukvichka - 96, y = parvaCarica.cifrichka; x > 0 && y < 9; x--, y++){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            //daska[x][y] = broiPeshki + 1;
            break;
        }
        daska[x][y] = broiPeshki + 1;
    }

    for(int x = parvaCarica.bukvichka - 96, y = parvaCarica.cifrichka; x < 9 && y < 9; x++, y++){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            //daska[x][y] = broiPeshki + 1;
            break;
        }
        daska[x][y] = broiPeshki + 1;
    }

    for(int x = parvaCarica.bukvichka - 96, y = parvaCarica.cifrichka; x < 9 && y > 0; x++, y--){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            //daska[x][y] = broiPeshki + 1;
            break;
        }
        daska[x][y] = broiPeshki + 1;
    }


    /// VTORA CARICA NADOLU:


    for(int x = vtoraCarica.bukvichka - 96; x < 9; x++){
        if(daska[x][vtoraCarica.cifrichka] > 0 && daska[x][vtoraCarica.cifrichka] <= broiPeshki){
            if(peshki[daska[x][vtoraCarica.cifrichka] - 1].nabitaLiE == false){
                peshki[daska[x][vtoraCarica.cifrichka] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][vtoraCarica.cifrichka]<<endl;
            }
            daska[x][vtoraCarica.cifrichka] = broiPeshki + 2;
            break;
        }
        daska[x][vtoraCarica.cifrichka] = broiPeshki + 2;
    }

    for(int x = vtoraCarica.bukvichka - 96; x > 0; x--){
        if(daska[x][vtoraCarica.cifrichka] > 0 && daska[x][vtoraCarica.cifrichka] <= broiPeshki){
            if(peshki[daska[x][vtoraCarica.cifrichka] - 1].nabitaLiE == false){
                peshki[daska[x][vtoraCarica.cifrichka] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][vtoraCarica.cifrichka]<<endl;
            }
            daska[x][vtoraCarica.cifrichka] = broiPeshki + 2;
            break;
        }
        daska[x][vtoraCarica.cifrichka] = broiPeshki + 2;
    }

    for(int y = vtoraCarica.cifrichka; y > 0; y--){
        if(daska[vtoraCarica.bukvichka - 96][y] > 0 && daska[vtoraCarica.bukvichka - 96][y] <= broiPeshki){
            if(peshki[daska[vtoraCarica.bukvichka - 96][y] - 1].nabitaLiE == false){
                peshki[daska[vtoraCarica.bukvichka - 96][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[vtoraCarica.bukvichka - 96][y]<<endl;
            }
            daska[vtoraCarica.bukvichka - 96][y] = broiPeshki + 2;
            break;
        }
        daska[vtoraCarica.bukvichka - 96][y] = broiPeshki + 2;
    }

    for(int y = vtoraCarica.cifrichka; y < 9; y++){
        if(daska[vtoraCarica.bukvichka - 96][y] > 0 && daska[vtoraCarica.bukvichka - 96][y] <= broiPeshki){
            if(peshki[daska[vtoraCarica.bukvichka - 96][y] - 1].nabitaLiE == false){
                peshki[daska[vtoraCarica.bukvichka - 96][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[vtoraCarica.bukvichka - 96][y]<<endl;
            }
            daska[vtoraCarica.bukvichka - 96][y] = broiPeshki + 2;
            break;
        }
        daska[vtoraCarica.bukvichka - 96][y] = broiPeshki + 2;
    }

    for(int x = vtoraCarica.bukvichka - 96, y = vtoraCarica.cifrichka; x > 0 && y > 0; x--, y--){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            daska[x][y] = broiPeshki + 2;
            break;
        }
        daska[x][y] = broiPeshki + 2;
    }

    for(int x = vtoraCarica.bukvichka - 96, y = vtoraCarica.cifrichka; x > 0 && y < 9; x--, y++){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            daska[x][y] = broiPeshki + 2;
            break;
        }
        daska[x][y] = broiPeshki + 2;
    }

    for(int x = vtoraCarica.bukvichka - 96, y = vtoraCarica.cifrichka; x < 9 && y < 9; x++, y++){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            daska[x][y] = broiPeshki + 2;
            break;
        }
        daska[x][y] = broiPeshki + 2;
    }

    for(int x = vtoraCarica.bukvichka - 96, y = vtoraCarica.cifrichka; x < 9 && y > 0; x++, y--){
        if(daska[x][y] > 0 && daska[x][y] <= broiPeshki){
            if(peshki[daska[x][y] - 1].nabitaLiE == false){
                peshki[daska[x][y] - 1].nabitaLiE = true;
                //broiUceleniPeshki++;
                //cout<<daska[x][y]<<endl;
            }
            daska[x][y] = broiPeshki + 2;
            break;
        }
        daska[x][y] = broiPeshki + 2;
    }*/

    for(int i = 0; i < broiPeshki; i++){
        if(peshki[i].nabitaLiE == true){
            broiUceleniPeshki++;
        }
    }

    /*for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            cout<<daska[j][i]<<" ";
        }
        cout<<endl;
    }*/


    cout<<broiUceleniPeshki<<endl;

    return 0;
}
