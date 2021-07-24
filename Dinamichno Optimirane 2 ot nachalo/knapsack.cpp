#include<iostream>
using namespace std;

struct DanniZaPredmeta{
    int kolkoTezhi;
    int kakvaMuECenata;
};

int broiPredmeti;
DanniZaPredmeta predmeti[1000];

int maksimalnaCena[1000][1000];
bool vzeliLiSmeGo[1000][1000];

int capacitet;


int main(){
    cin>>capacitet>>broiPredmeti;

    for(int i = 1; i <= broiPredmeti; i++){
        int tezhina;
        int cena;
        cin>>tezhina>>cena;
        predmeti[i].kolkoTezhi = tezhina;
        predmeti[i].kakvaMuECenata = cena;
    }

    for(int c = 0; c <= capacitet; c++){
        maksimalnaCena[0][c] = 0;
    }

    for(int i = 1; i <= broiPredmeti; i++){
        for(int c = 0; c <= capacitet; c++){
            if(predmeti[i].kolkoTezhi > c){
                continue;
            }
            int bezNego = maksimalnaCena[i - 1][c];
            int sNego = predmeti[i].kakvaMuECenata + maksimalnaCena[i - 1][c - predmeti[i].kolkoTezhi];

            maksimalnaCena[i][c] = max(bezNego, sNego);
        }
    }


    cout<<maksimalnaCena[broiPredmeti][capacitet]<<endl;

    return 0;
}
