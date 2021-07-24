#include<iostream>
using namespace std;

const int chislotoZaModul = 1001027;

int broiOtvarqshtiSkobi;

int broiZadalzhitelnoSOtvarqshta;

bool tukTrqbvaLiDaImaOtvarqshta[2010];

int priTolkova[1001][1001];

int broiKombinacii(int broiOtvarqshti, int broiZatvarqshti){
    if(broiOtvarqshti + broiZatvarqshti == 0){
        return 1%chislotoZaModul;
    }

    if(priTolkova[broiOtvarqshti][broiZatvarqshti] > -1){
        return priTolkova[broiOtvarqshti][broiZatvarqshti]%chislotoZaModul;
    }

    int kombinaciiOtTuk = 0;

    if(broiOtvarqshti > 0){
        kombinaciiOtTuk = (kombinaciiOtTuk + broiKombinacii((broiOtvarqshti - 1), broiZatvarqshti))%chislotoZaModul;
    }

    if(broiZatvarqshti > broiOtvarqshti &&
        tukTrqbvaLiDaImaOtvarqshta[broiOtvarqshtiSkobi * 2 - (broiOtvarqshti + broiZatvarqshti) + 1] == false)
    {
        kombinaciiOtTuk = (kombinaciiOtTuk + broiKombinacii(broiOtvarqshti, broiZatvarqshti - 1))%chislotoZaModul;
    }

    int zaVrashtane = kombinaciiOtTuk%chislotoZaModul;

    priTolkova[broiOtvarqshti][broiZatvarqshti] = zaVrashtane;
    return kombinaciiOtTuk;
}

int sCycli(int priBroiOtvarqshti, int priBroiZatvarqshti){
    priTolkova[0][0] = 1;

    for(int broiOtvarqshti = 0; broiOtvarqshti <= priBroiOtvarqshti; broiOtvarqshti++){
        for(int broiZatvarqshti = broiOtvarqshti; broiZatvarqshti <= priBroiZatvarqshti; broiZatvarqshti++){
            if(broiOtvarqshti + broiZatvarqshti == 0){
                continue;
            }
            int kombinaciiOtTuk = 0;

            if(broiOtvarqshti > 0){
                kombinaciiOtTuk = (kombinaciiOtTuk + priTolkova[broiOtvarqshti - 1][broiZatvarqshti])%chislotoZaModul;
            }

            if(broiZatvarqshti > broiOtvarqshti &&
                tukTrqbvaLiDaImaOtvarqshta[broiOtvarqshtiSkobi * 2 - (broiOtvarqshti + broiZatvarqshti) + 1] == false)
            {
                kombinaciiOtTuk = (kombinaciiOtTuk + priTolkova[broiOtvarqshti][broiZatvarqshti - 1])%chislotoZaModul;
            }

            int zaVrashtane = kombinaciiOtTuk%chislotoZaModul;

            priTolkova[broiOtvarqshti][broiZatvarqshti] = zaVrashtane;
        }
    }

    return priTolkova[priBroiOtvarqshti][priBroiZatvarqshti];
}

int main(){
    cin>>broiOtvarqshtiSkobi>>broiZadalzhitelnoSOtvarqshta;

    for(int i = 0; i < broiZadalzhitelnoSOtvarqshta; i++){
        int kade;
        cin>>kade;
        tukTrqbvaLiDaImaOtvarqshta[kade] = true;
    }

    /*for(int i = 0; i <= broiOtvarqshtiSkobi; i++){
        for(int j = i; j <= broiOtvarqshtiSkobi; j++){
            priTolkova[i][j] = -1;
            priTolkova[j][i] = -1;
        }
    }*/

    int broiVazmozhniKombinacii = sCycli(broiOtvarqshtiSkobi, broiOtvarqshtiSkobi)%chislotoZaModul;

    cout<<broiVazmozhniKombinacii%chislotoZaModul<<endl;

    return 0;
}
