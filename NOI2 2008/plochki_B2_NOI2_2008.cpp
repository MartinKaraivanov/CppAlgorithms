#include<iostream>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiPlochki;
int n;

int plochki[1010][35][35];

int kakvoPisheTuk(int plochka, DanniZaTochka t){
    return plochki[plochka][t.x][t.y];
}

DanniZaTochka kakviSaNovitePri(DanniZaTochka t, int kakvoZavartane){
    /// 0 - sashtoto, 1 - nalqvoZavartqno, 2 - 2 patiNa dolu, 3 - nadqsno

    int novX;
    int novY;

    if(kakvoZavartane == 0){
        novX = t.x;
        novY = t.y;
    }else{
        if(kakvoZavartane == 1){
            novX = t.y;
            novY = n - t.x + 1;
        }else{
            if(kakvoZavartane == 2){
                novX = n - t.x + 1;
                novY = n - t.y + 1;
            }else{
                novX = n - t.y + 1;
                novY = t.x;
            }
        }
    }

    return {novX, novY};
}

DanniZaTochka kakviSaNovitePriObrashtane(int obrashtane, DanniZaTochka t){
    if(obrashtane == 0){
        return t;
    }

    int novX = n - t.x + 1;
    int novY = t.y;

    return {novX, novY};
}

bool dvetePlochkiEdnakviLiSa(int parva, int vtora){

    for(int obr = 0; obr < 2; obr++){
        for(int zav = 0; zav < 4; zav++){
            bool tukEdnakviLiSa = true;
            for(int y = 1; y <= n; y++){
                for(int x = 1; x <= n; x++){
                    DanniZaTochka t = {x, y};
                    t = kakviSaNovitePri(t, zav);
                    t = kakviSaNovitePriObrashtane(obr, t);
                    //cout<<parva<<" "<<vtora<<" "
                    //<<obr<<" "<<zav<<" "<<x<<" "<<y<<" "<<plochki[parva][x][y]<<" "<<plochki[vtora][t.x][t.y]<<endl;
                    if(plochki[vtora][t.x][t.y] != plochki[parva][x][y]){
                        tukEdnakviLiSa = false;
                        break;
                    }
                }
                if(!tukEdnakviLiSa){
                    break;
                }
            }
            if(tukEdnakviLiSa){
                return true;
            }
        }
    }

    return false;
}

int main(){
    cin>>broiPlochki>>n;

    for(int p = 1; p <= broiPlochki; p++){
        for(int y = 1; y <= n; y++){
            string red;
            cin>>red;
            for(int x = 1; x <= n; x++){
                plochki[p][x][y] = red[x - 1] - '0';
            }
        }
    }

    /*for(int i = 1; i <= broiPlochki; i++){
        for(int j = 1; j <= n; j++){
            for(int x = 1; x <= n; x++){
                cout<<plochki[i][x][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }*/

    //cout<<dvetePlochkiEdnakviLiSa(1,2)<<" "<<dvetePlochkiEdnakviLiSa(1, 3)<<" "<<dvetePlochkiEdnakviLiSa(2, 3)<<endl;

    int broiRazlichni = 0;

    for(int i = 1; i <= broiPlochki; i++){
        bool taziRazlichnaLiE = true;
        for(int j = 1; j < i; j++){
            if(dvetePlochkiEdnakviLiSa(i, j) == true){
                taziRazlichnaLiE = false;
                break;
            }
        }
        if(taziRazlichnaLiE == true){
            broiRazlichni++;
        }
    }

    cout<<broiRazlichni<<endl;

    return 0;
}
