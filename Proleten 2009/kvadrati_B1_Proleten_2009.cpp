#include<iostream>
#include<algorithm>
using namespace std;

struct masiv{
    int sastoqnie[4][4];
};

int nuzhniPuloveX[4];
int nuzhniPuloveY[4];

bool okLiE(int permutaciq[8]){
    bool hubavaLiE = true;

    for(int i = 1; i < 4; i++){
        if(permutaciq[i] < permutaciq[i - 1]){
            hubavaLiE = false;
        }
    }

    for(int i = 5; i < 8; i++){
        if(permutaciq[i] < permutaciq[i - 1]){
            hubavaLiE = false;
        }
    }

    if(permutaciq[4] < permutaciq[0]){
        hubavaLiE = false;
    }

    return hubavaLiE;
}

masiv segashnoSastoqnie;

masiv otgovori[1000];
int broiOtgovori;

void praveneNaVazmozhnostite(int x, int y){
    if(y == 4){
        otgovori[broiOtgovori] = segashnoSastoqnie;
        broiOtgovori++;

        return ;
    }

    int nuzhnoNaX = nuzhniPuloveX[x];
    int nuzhnoNaY = nuzhniPuloveY[y];

    int otKade = 0;
    int doKade = min(nuzhnoNaX, nuzhnoNaY);

    if(x == 3){
        otKade = nuzhnoNaY;
    }

    if(y == 3){
        otKade = max(otKade, nuzhnoNaX);
        doKade = min(otKade, doKade);
    }


    for(int tukaPulove = otKade; tukaPulove <= doKade; tukaPulove++){
        nuzhniPuloveX[x] -= tukaPulove;
        nuzhniPuloveY[y] -= tukaPulove;
        segashnoSastoqnie.sastoqnie[x][y] += tukaPulove;

        if(x < 3){
            praveneNaVazmozhnostite(x + 1, y);
        }else{
            praveneNaVazmozhnostite(0, y + 1);
        }

        segashnoSastoqnie.sastoqnie[x][y] -= tukaPulove;
        nuzhniPuloveX[x] += tukaPulove;
        nuzhniPuloveY[y] += tukaPulove;
    }

}

int main(){
    int permutaciqta[8];

    for(int i = 0; i < 8; i++){
        permutaciqta[i] = i;
    }

    do{
        if(okLiE(permutaciqta) == true){
            for(int i = 0; i < 4; i++){
                nuzhniPuloveX[i] = permutaciqta[i];
            }
            for(int i = 4; i < 8; i++){
                nuzhniPuloveY[i - 4] = permutaciqta[i];
            }

            praveneNaVazmozhnostite(0, 0);
        }
    }while(next_permutation(permutaciqta, permutaciqta + 8));

    cout<<broiOtgovori<<endl;

    for(int i = 0; i < broiOtgovori; i++){
        for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++){
                cout<<otgovori[i].sastoqnie[x][y]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
