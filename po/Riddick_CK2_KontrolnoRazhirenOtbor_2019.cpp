#include<iostream>
using namespace std;
int broiChudovishta;
int kolkoMozhedaVzeme;
int kolkoNavika;

int kolkoMuENaiGolqmataMosht(int kolkoHodaDoTuk, int broiRazlichniN, bool nav[kolkoNavika], bool vzeliLiSmeGo[broiChudovishta]){
    if(kolkoHodaDoTuk==kolkoMozhedaVzeme){
        return 0;
    }

    int maxBroi=0;

    for(int m=0;m<broiChudovishta;m++){
        if(vzeliLiSmeGo[m]==false){

        }
    }

}

int main(){
    cin>>broiChudovishta>>kolkoMozhedaVzeme>>kolkoNavika;

    int navici[broiChudovishta][kolkoNavika];

    for(int i=0;i<broiChudovishta;i++){
        for(int j=0;j<kolkoNavika;j++){
            cin>>navici[i][j];
        }
    }

    bool prazno[kolkoNavika];

    for(int i=0;i<kolkoNavika;i++){
        prazno[i]=false;
    }

    int mosht=kolkoMuENaiGolqmataMosht(0, 0, prazno);


    return 0;
}
