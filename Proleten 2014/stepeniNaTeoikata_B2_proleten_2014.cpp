#include<iostream>
using namespace std;

long long maxX;
long long maxY;
long long maximalenBroiRazgovori;

long long broiVarhove;

long long start;
long long krai;

long long sasedstvo[200][200];

long long parva[200][200];
long long vtora[200][200];

char fitnes[35][35];

const long long mnogo = 1000007;

long long daiNomerche(long long x, long long y){
    return y*maxX + x;
}

void praveneNaSasedstvoto(){
    for(long long y = 0; y < maxY; y++){
        for(long long x = 0; x < maxX; x++){
            if(fitnes[x][y] == 'D'){
                start = daiNomerche(x, y);
            }
            if(fitnes[x][y] == 'F'){
                krai = daiNomerche(x, y);
            }
            if(fitnes[x][y] == 'X' || fitnes[x][y] == 'F'){
                continue;
            }

            long long nasheNomerce = daiNomerche(x, y);

            if(x > 0){
                if(fitnes[x - 1][y] == 'A' || fitnes[x - 1][y] == 'F'){
                    long long novoNomerche = daiNomerche(x - 1, y);
                    sasedstvo[nasheNomerce][novoNomerche] = 1;
                }
            }
            if(x < maxX - 1){
                if(fitnes[x + 1][y] == 'A' || fitnes[x + 1][y] == 'F'){
                    long long novoNomerche = daiNomerche(x + 1, y);
                    sasedstvo[nasheNomerce][novoNomerche] = 1;
                }
            }
            if(y > 0){
                if(fitnes[x][y - 1] == 'A' || fitnes[x][y - 1] == 'F'){
                    long long novoNomerche = daiNomerche(x, y - 1);
                    sasedstvo[nasheNomerce][novoNomerche] = 1;
                }
            }
            if(y < maxY - 1){
                if(fitnes[x][y + 1] == 'A' || fitnes[x][y + 1] == 'F'){
                    long long novoNomerche = daiNomerche(x, y + 1);
                    sasedstvo[nasheNomerce][novoNomerche] = 1;
                }
            }
        }
    }
}

long long novata[200][200];

void umnozhenieNaMatrici(long long parvata[200][200], long long vtorata[200][200], long long kade[200][200]){
    for(long long i = 0; i < broiVarhove; i++){
        for(long long j = 0; j < broiVarhove; j++){
            kade[i][j] = 0;
            for(long long m = 0; m < broiVarhove; m++){
                kade[i][j] += (parvata[i][m] * vtorata[m][j])%mnogo;
            }
        }
    }
}

void kopiraneNaMatricata(long long vTazi[200][200], long long otTazi[200][200]){
    for(long long i = 0; i < broiVarhove; i++){
        for(long long j = 0; j < broiVarhove; j++){
            vTazi[i][j] = otTazi[i][j];
        }
    }
}

long long izchisleniq(){
    if(maximalenBroiRazgovori == 0){
        return 0;
    }

    kopiraneNaMatricata(parva, sasedstvo);

    long long brNachini = sasedstvo[start][krai];

    for(long long k = 3; k <= maximalenBroiRazgovori; k *= 3){
        umnozhenieNaMatrici(parva, parva, vtora);
        umnozhenieNaMatrici(parva, vtora, novata);
        brNachini = (brNachini + novata[start][krai])%mnogo;
        kopiraneNaMatricata(parva, novata);
    }

    return brNachini;
}

int main(){
    cin>>maxY>>maxX>>maximalenBroiRazgovori;

    for(long long y = 0; y < maxY; y++){
        string red;
        cin>>red;
        for(unsigned long long x = 0; x < red.size(); x++){
            fitnes[x][y] = red[x];
        }
    }

    broiVarhove = maxX*maxY;

    praveneNaSasedstvoto();

    /*for(long long i = 0; i < broiVarhove; i++){
        for(long long j = 0; j < broiVarhove; j++){
            if(sasedstvo[i][j] > 0){
                cout<<i<<" "<<j<<" "<<sasedstvo[i][j]<<endl;
            }
        }
    }

    cout<<endl;*/

    int broiNachini = izchisleniq();

    /*for(long long i = 0; i < broiVarhove; i++){
        for(long long j = 0; j < broiVarhove; j++){
            cout<<i<<" "<<j<<" "<<imaLiPatishtaSDalzhna[i][j][1]<<endl;
        }
    }*/

    /*long long broiNachini = 0;
    long long stepenuvano = 1;
    long long patiStepen = 0;

    while(stepenuvano <= maximalenBroiRazgovori){
        broiNachini = (broiNachini + imaLiPatishtaSDalzhna[start][krai][stepenuvano])%mnogo;
        stepenuvano*=3;
        patiStepen++;
    }*/

    cout<<broiNachini%mnogo<<endl;

    return 0;
}
