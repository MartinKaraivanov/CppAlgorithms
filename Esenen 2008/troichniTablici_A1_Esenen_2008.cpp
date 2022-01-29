#include<iostream>
using namespace std;

int maxY;
int maxX;

int tablica[35][35];

int broiKletki;

int matricata[1050][1050];

int daiNomerche(int x, int y){
    return y*maxX + x;
}

int parviNenulevRed(int otKoiRedNatatuk, int kolona){
    for(int i = otKoiRedNatatuk; i < broiKletki; i++){
        if(matricata[i][kolona] != 0){
            return i;
        }
    }

    return -1;
}

void razmeniRedovete(int parvi, int vtori){
    for(int i = 0; i <= broiKletki; i++){
        swap(matricata[parvi][i], matricata[vtori][i]);
    }
}

void umnojiReda(int koiRed, int poKakvo){
    if(poKakvo != 1){
        for(int i = koiRed; i <= broiKletki; i++){
            matricata[koiRed][i] = (matricata[koiRed][i]*poKakvo)%3;
        }
    }
}

void dobaviKumReda(int kumRed, int otRed, int umnPoKakvo){
    if(umnPoKakvo == 0){
        return ;
    }

    for(int i = min(kumRed, otRed); i <= broiKletki; i++){
        matricata[kumRed][i] = (matricata[kumRed][i] + 6 + matricata[otRed][i]*umnPoKakvo)%3;
    }
}

int privediVEshelonnaForma(){
    /*for(int i = 0; i < broiKletki; i++){
        for(int j = 0; j <= broiKletki; j++){
            cout<<matricata[i][j];
        }
        cout<<endl;
    }
    cout<<endl;*/

    int red = 0;
    int kolona = 0;

    while(red < broiKletki && kolona <= broiKletki){
        int nenulevRed = parviNenulevRed(red, kolona);

        if(nenulevRed == -1){
            kolona++;
        }else{
            razmeniRedovete(red, nenulevRed);

            umnojiReda(red, matricata[red][kolona]);

            for(int drugiqRed = red + 1; drugiqRed < broiKletki; drugiqRed++){
                dobaviKumReda(drugiqRed, red, (3-matricata[drugiqRed][kolona])%3);
            }

            red++;
            kolona++;
        }
    }

    /*for(int i = 0; i < broiKletki; i++){
        for(int j = 0; j <= broiKletki; j++){
            cout<<matricata[i][j];
        }
        cout<<endl;
    }*/

    int broiNuleviRedove = 0;

    for(int i = 0; i < broiKletki; i++){
        bool nulevLiE = true;
        for(int j = 0; j <= broiKletki; j++){
            if(matricata[i][j] != 0){
                if(j == broiKletki){
                    broiNuleviRedove = -1;
                }
                nulevLiE = false;
                break;
            }
        }

        if(nulevLiE == true){
            broiNuleviRedove++;
        }

        if(broiNuleviRedove == -1){
            break;
        }
    }

    return broiNuleviRedove;
}


int main(){
    cin>>maxY>>maxX;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cin>>tablica[y][x];
        }
    }

    broiKletki = maxX*maxY;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int tukaNomerche = daiNomerche(x, y);

            matricata[tukaNomerche][broiKletki] = tablica[y][x];

            if(x > 0){
                int tamNomerche = daiNomerche(x - 1, y);
                matricata[tukaNomerche][tamNomerche] = 1;
            }

            if(x < maxX - 1){
                int tamNomerche = daiNomerche(x + 1, y);
                matricata[tukaNomerche][tamNomerche] = 1;
            }

            if(y > 0){
                int tamNomerche = daiNomerche(x, y - 1);
                matricata[tukaNomerche][tamNomerche] = 1;
            }

            if(y < maxY - 1){
                int tamNomerche = daiNomerche(x, y + 1);
                matricata[tukaNomerche][tamNomerche] = 1;
            }

        }
    }

    int broiNuleviRedove = privediVEshelonnaForma();

    if(broiNuleviRedove == -1){
        cout<<0<<endl;
    }else{
        const int modul = 333333;

        int otgovor = 1;

        for(int i = 0; i < broiNuleviRedove; i++){
            otgovor = (otgovor*3)%modul;
        }

        cout<<otgovor<<endl;
    }

    return 0;
}
