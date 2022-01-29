#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;

int maxY;
int maxX;

int broiPodove;

int poda[1010][1010];

int broiNeizvestni;

bitset<1024> matricata[1010];

void nulirane(){
    for(int i = 0; i <= broiNeizvestni; i++){
        for(int j = 0; j <= broiNeizvestni + 1; j++){
            matricata[i][j] = 0;
        }
    }
}

int daiNomerche(int x, int y){
    return maxX*(y-1) + x;
}

void razmeniRedovete(int i, int j){
    /*for(int k = min(i, j); k <= broiNeizvestni; k++){
        swap(matricata[i][k], matricata[j][k]);
    }*/
    //swap(matricata[i], matricata[j]);
    bitset<1024> p = matricata[i];
    matricata[i] = matricata[j];
    matricata[j] = p;
}


void umnojiRed(int koiRed, int poKakvo){
    /*for(int i = koiRed; i <= broiNeizvestni; i++){
        matricata[koiRed][i] &= poKakvo;
    }*/

    matricata[koiRed] &= poKakvo;
}

void dobaviKumReda(int kumKoiRed, int otKoiRed, int umnPoKakvo){
    if(umnPoKakvo == 0){
        return ;
    }

    matricata[kumKoiRed] ^= matricata[otKoiRed];


    /*for(int i = min(otKoiRed, kumKoiRed); i <= broiNeizvestni; i++){
        matricata[kumKoiRed][i] ^= matricata[otKoiRed][i]&umnPoKakvo;
    }*/
}


int redSNenula(int otKoiRedNatatuk, int kolona){
    for(int i = otKoiRedNatatuk; i < broiNeizvestni; i++){
        if(matricata[i][kolona] != 0){
            return i;
        }
    }

    return -1;
}

void privediVEshalonnaForma(){

    int red = 0;
    int kolona = 0;

    while(red < broiNeizvestni && kolona <= broiNeizvestni){

        int nenuleviqRed = redSNenula(red, kolona);

        if(nenuleviqRed == -1){
            kolona++;
        }else{
            razmeniRedovete(red, nenuleviqRed);

            //umnojiRed(red, 1/matricata[red][kolona]); sega nima nujda zashtoto e edno

            for(int drugRed = red + 1; drugRed < broiNeizvestni; drugRed++){
                dobaviKumReda(drugRed, red, matricata[drugRed][kolona]);  // po minus edno triabva normalno
            }

            red++;
            kolona++;
        }
    }
}


void nameriReshenie2(){
    privediVEshalonnaForma();

    /*for(int i = 0; i < broiNeizvestni; i++){
        for(int j = 0; j <= broiNeizvestni; j++){
            cout<<matricata[i][j];
        }
        cout<<" "<<i;
        cout<<endl;
    }
    cout<<endl;*/

    int otgovori[broiNeizvestni];

    for(int i = 0; i < broiNeizvestni; i++){
        otgovori[i] = 0;
    }

    bool vazmojnoLiE = true;

    for(int i = broiNeizvestni - 1; i >= 0; i--){

        int kadeEParvataEdinica = -1;

        for(int j = i; j <= broiNeizvestni; j++){
            if(matricata[i][j] == 1){
                kadeEParvataEdinica = j;
                break;
            }
        }

        if(kadeEParvataEdinica == broiNeizvestni){
            vazmojnoLiE = false;
            break;
        }

        if(kadeEParvataEdinica != -1){
            int drugite = 0;

            for(int j = kadeEParvataEdinica + 1; j < broiNeizvestni; j++){
                drugite ^= matricata[i][j]&otgovori[j];
            }

            otgovori[kadeEParvataEdinica] = drugite^matricata[kadeEParvataEdinica][broiNeizvestni];
            //cout<<"sega slojihme otg na "<<i<<" da e "<<otgovori[i]<<endl;
        }

    }

    if(vazmojnoLiE == false){
        cout<<"Impossible"<<endl;
    }else{

        cout<<"Possible";

        for(int i = 0; i < broiNeizvestni; i++){
            if(i%maxX == 0){
                cout<<endl;
            }
            cout<<otgovori[i];
        }
    }

    cout<<endl;

}

void nameriReshenie(){

    int h = 0;
    int k = 0;

    while(h < broiNeizvestni && k <= broiNeizvestni){
        int indexaNaMax = -1;
        int naiGolqmoto = 0;

        for(int i = h; i < broiNeizvestni; i++){
            if(matricata[i][k] > naiGolqmoto){
                naiGolqmoto = matricata[i][k];
                indexaNaMax = i;
            }
        }

        if(matricata[indexaNaMax][k] == 0){
            k++;
        }else{
            razmeniRedovete(h, indexaNaMax);

            for(int i = h+1; i < broiNeizvestni; i++){
                int poKakvoUmn = matricata[i][k]; // /matricata[h][k], koeto e 1

                matricata[i][k] = 0;

                /*for(int j = k + 1; j <= broiNeizvestni; j++){
                    matricata[i][j] ^= matricata[h][j]&poKakvoUmn;
                }*/

                dobaviKumReda(i, h, poKakvoUmn);
            }

            h++;
            k++;
        }
    }


    /*for(int i = 0; i < broiNeizvestni; i++){
        for(int j = 0; j <= broiNeizvestni; j++){
            cout<<matricata[i][j];
        }
        cout<<" "<<i;
        cout<<endl;
    }
    cout<<endl;*/

    int otgovori[broiNeizvestni];

    for(int i = 0; i < broiNeizvestni; i++){
        otgovori[i] = -1;
    }

    bool vasmojnoLiE = true;

    if(matricata[broiNeizvestni - 1][broiNeizvestni] == 1){
        if(matricata[broiNeizvestni - 1][broiNeizvestni - 1] == 0){
            vasmojnoLiE = false;
        }else{
            otgovori[broiNeizvestni - 1] = 1;
        }
    }else{
        otgovori[broiNeizvestni - 1] = 0;
    }

    if(vasmojnoLiE == false){
        cout<<"Impossible"<<endl;
    }else{

        for(int i = broiNeizvestni - 2; i >= 0; i--){

            int sborNaOstanalite = 0;

            for(int j = i + 1; j < broiNeizvestni; j++){
                sborNaOstanalite ^= matricata[i][j]&otgovori[j];
            }

            otgovori[i] = matricata[i][broiNeizvestni]^sborNaOstanalite;

            //cout<<"slojihme "<<i<<" da e "<<otgovori[i]<<endl;
        }

        cout<<"Possible";

        for(int i = 0; i < broiNeizvestni; i++){
            if(i%maxX == 0){
                cout<<endl;
            }
            cout<<otgovori[i];
        }

    }

    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxY>>maxX;

    cin>>broiPodove;

    broiNeizvestni = maxX*maxY;

    for(int t = 0; t < broiPodove; t++){
        for(int y = 1; y <= maxY; y++){
            string tuka;
            cin>>tuka;
            for(int x = 1; x <= maxX; x++){
                poda[x][y] = tuka[x - 1] - '0';
            }
        }

        nulirane();

        for(int y = 1; y <= maxY; y++){
            for(int x = 1; x <= maxX; x++){
                int tukaNomerche = daiNomerche(x, y) - 1;

                matricata[tukaNomerche][broiNeizvestni] = poda[x][y];

                matricata[tukaNomerche][tukaNomerche] = 1;

                if(y > 1){
                    int tamNomerche = daiNomerche(x, y - 1);
                    matricata[tukaNomerche][tamNomerche - 1] = 1;
                }

                if(y < maxY){
                    int tamNomerche = daiNomerche(x, y + 1);
                    matricata[tukaNomerche][tamNomerche - 1] = 1;
                }

                if(x > 1){
                    int tamNomerche = daiNomerche(x - 1, y);
                    matricata[tukaNomerche][tamNomerche - 1] = 1;
                }

                if(x < maxX){
                    int tamNomerche = daiNomerche(x + 1, y);
                    matricata[tukaNomerche][tamNomerche - 1] = 1;
                }

            }
        }


        /*cout<<endl;

        for(int i = 0; i < broiNeizvestni; i++){
            for(int j = 0; j <= broiNeizvestni; j++){
                cout<<matricata[i][j];
            }
            cout<<endl;
        }

        cout<<endl;*/

        nameriReshenie2();

    }

    return 0;
}
