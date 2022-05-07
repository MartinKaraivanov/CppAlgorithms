#include<iostream>
using namespace std;

const long long mnogo = 1000000007*2;

char nachalenPolynom[100010];

long long broiIteracii;
long long broiPravila;

long long pravila[768][2];

//////////long long broiOtTaziDvoika[768][2];

long long broiOtTaziBukva[128];

long long sasedstvo[768][768];
long long nachalenBroiOtDvoika[768];

long long nomerNa[128][128];
long long nomerche;

char originalnoNa[768][2];

long long daiNomerche(char parva, char vtora){
    if(nomerNa[parva][vtora] == 0){
        nomerche++;
        nomerNa[parva][vtora] = nomerche;

        originalnoNa[nomerche][0] = parva;
        originalnoNa[nomerche][1] = vtora;
    }

    return nomerNa[parva][vtora];
}



void kopiraiMatrica(long long (&vKoq)[768][768], long long (&otKoq)[768][768]){
    for(long long i = 0; i <= nomerche; i++){
        for(long long j = 0; j <= nomerche; j++){
            vKoq[i][j] = otKoq[i][j];
        }
    }
}

long long rezultatna[768][768];

void umnojiMatrici(long long (&parva)[768][768], long long (&vtora)[768][768]){

    for(long long i = 1; i <= nomerche; i++){
        for(long long j = 1; j <= nomerche; j++){
            rezultatna[i][j] = 0;

            for(long long k = 1; k <= nomerche; k++){
                rezultatna[i][j] = (rezultatna[i][j] + (parva[i][k]*vtora[k][j])%mnogo)%mnogo;
            }
        }
    }

    kopiraiMatrica(parva, rezultatna);
}

long long kopieMatrica[768][768];
long long zaVrasht[768][768];

void vdigniNaStepen(long long (&matricata)[768][768], long long naStepen){

    kopiraiMatrica(kopieMatrica, matricata);

    for(long long i = 1; i <= nomerche; i++){
        zaVrasht[i][i] = 1;
        // todo: vsicho ostanalo da e 0
    }

    while(naStepen > 0){
        if((naStepen & 1) == 1){
            umnojiMatrici(zaVrasht, kopieMatrica);
        }
        umnojiMatrici(kopieMatrica, kopieMatrica);

        naStepen >>= 1;
    }

    kopiraiMatrica(matricata, zaVrasht);
}

long long rezultatenVector[768];

void umnojiVectorPoMatrica( long long (&vectorat)[768], long long (&matrica)[768][768]){

    /*cout<<"umnojavame vectorat ";
    for(long long i = 1; i <= nomerche; i++){
        cout<<vectorat[i]<<" ";
    }
    cout<<endl;

    cout<<"po matricata "<<endl;

    for(long long i = 1; i <= nomerche; i++){
        for(long long j = 1; j <= nomerche; j++){
            cout<<matrica[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    for(long long i = 1; i <= nomerche; i++){

        rezultatenVector[i] = 0;
    }

    for(long long j = 1; j <= nomerche; j++){
        for(long long i = 1; i <= nomerche; i++){

            rezultatenVector[i] = (rezultatenVector[i] + (vectorat[j]*matrica[j][i])%mnogo)%mnogo;  // todo: obratno indeksirane - bavno
        }
    }

    /*cout<<"poluchava se ";
    for(long long i = 1; i <= nomerche; i++){
        cout<<rezultatenVector[i]<<" ";
    }
    cout<<endl;*/

    for(long long i = 1; i <= nomerche; i++){
        vectorat[i] = rezultatenVector[i];
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>nachalenPolynom;

    long long nachalenPolynomSize = 0;
    while (nachalenPolynom[nachalenPolynomSize] != 0){
        nachalenPolynomSize++;
    }

    cin>>broiIteracii>>broiPravila;

    for(long long i = 0; i < broiPravila; i++){
        string mejduKakvo;
        char kakvoSlagame;

        cin>>mejduKakvo>>kakvoSlagame;

        pravila[daiNomerche(mejduKakvo[0], mejduKakvo[1])][0] = daiNomerche(mejduKakvo[0], kakvoSlagame);
        pravila[daiNomerche(mejduKakvo[0], mejduKakvo[1])][1] = daiNomerche(kakvoSlagame, mejduKakvo[1]);

        sasedstvo[daiNomerche(mejduKakvo[0], mejduKakvo[1])][daiNomerche(mejduKakvo[0], kakvoSlagame)]++;
        sasedstvo[daiNomerche(mejduKakvo[0], mejduKakvo[1])][daiNomerche(kakvoSlagame, mejduKakvo[1])]++;
    }

    for(long long i = 1; i <= nomerche; i++){
        if(pravila[i][0] == 0){
            sasedstvo[i][i] = 1;
        }
    }

    long long nomercheOtPravila = nomerche;

    for(long long i = 1; i < nachalenPolynomSize; i++){

        long long tukaNomerche = daiNomerche(nachalenPolynom[i - 1], nachalenPolynom[i]);
        if(pravila[tukaNomerche][0] == 0){
            sasedstvo[tukaNomerche][tukaNomerche] = 1;
        }
    }

    long long nomercheOtVsichki = nomerche;

    nomerche = nomercheOtPravila;


    if (nomercheOtPravila > 50){
        cout<<"nom "<<nomercheOtPravila<<" "<<nomercheOtVsichki;
        return 0;
    }



    /*cout<<"v nachaloto:"<<endl;
    for(long long i = 1; i <= nomerche; i++){
        for(long long j = 1; j <= nomerche; j++){
            if(sasedstvo[i][j] > 0){
                cout<<originalnoNa[i]<<" "<<originalnoNa[j]<<endl;
            }
        }
    }
    cout<<endl;*/

    for(long long i = 1; i < nachalenPolynomSize; i++){

        long long tukaNomerche = daiNomerche(nachalenPolynom[i - 1], nachalenPolynom[i]);

        ///////        broiOtTaziDvoika[tukaNomerche][0] = (broiOtTaziDvoika[tukaNomerche][0] + 1)%mnogo;
        nachalenBroiOtDvoika[tukaNomerche] = (nachalenBroiOtDvoika[tukaNomerche] + 1)%mnogo;
    }
//-----------------------
    /*for(long long t = 1; t <= broiIteracii; t++){
        for(long long k = 1; k <= nomerche; k++){

            //cout<<"imame ot "<<i<<" "<<j<<" po "<<broiOtTaziDvoika[i][j][(t+1)%2]<<endl;

            if(pravila[k][0] != 0){

                broiOtTaziDvoika[pravila[k][0]][t%2] =
                    (broiOtTaziDvoika[pravila[k][0]][t%2] + broiOtTaziDvoika[k][(t+1)%2])%mnogo;
                broiOtTaziDvoika[pravila[k][1]][t%2] =
                    (broiOtTaziDvoika[pravila[k][1]][t%2] + broiOtTaziDvoika[k][(t+1)%2])%mnogo;
            }else{
                broiOtTaziDvoika[k][t%2] =
                    (broiOtTaziDvoika[k][t%2] + broiOtTaziDvoika[k][(t+1)%2])%mnogo;
            }

            broiOtTaziDvoika[k][(t+1)%2] = 0;

        }
        //cout<<endl<<endl;
    }*/
//---------------------------------

    vdigniNaStepen(sasedstvo, broiIteracii);

    /*cout<<"sled vdiganeto:"<<endl;
    for(long long i = 1; i <= nomerche; i++){
        for(long long j = 1; j <= nomerche; j++){
            if(sasedstvo[i][j] > 0){
                cout<<originalnoNa[i]<<" "<<originalnoNa[j]<<endl;
            }
        }
    }
    cout<<endl;*/

    umnojiVectorPoMatrica(nachalenBroiOtDvoika, sasedstvo);

    /*cout<<"sled umnijenieto po vector: "<<endl;
    for(long long i = 1; i <= nomerche; i++){
        if(nachalenBroiOtDvoika[i] > 1){
            cout<<originalnoNa[i]<<endl;
        }
    }
    cout<<endl;*/

    /*for(long long i = 1; i <= nomerche; i++){
        broiOtTaziDvoika[nomerche][broiIteracii%2] = (broiOtTaziDvoika[nomerche][broiIteracii%2] + 1)%mnogo;
    }*/





    //-----------------------


    nomerche = nomercheOtVsichki;


    for(long long k = 1; k <= nomerche; k++){
        char i = originalnoNa[k][0];
        char j = originalnoNa[k][1];
        broiOtTaziBukva[i] = (broiOtTaziBukva[i] + nachalenBroiOtDvoika[k])%mnogo;
        broiOtTaziBukva[j] = (broiOtTaziBukva[j] + nachalenBroiOtDvoika[k])%mnogo;
    }

    for(char i = 'A'; i <= 'Z'; i++){
        broiOtTaziBukva[i] = ((broiOtTaziBukva[i] + 1))/2;
    }

    if(nachalenPolynom[0] == nachalenPolynom[nachalenPolynomSize - 1]){
        broiOtTaziBukva[nachalenPolynom[0]]++;
    }

    for(char i = 'A'; i <= 'Z'; i++){
        //if(broiOtTaziBukva[i] > 0){
        cout<<i<<" "<<broiOtTaziBukva[i]<<endl;
        //}
    }

    return 0;
}
