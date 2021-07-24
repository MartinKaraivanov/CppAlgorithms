#include<stdio.h>
#include<string.h>
using namespace std;

const long long BASE = 257;
const int MOD = 1000000007;

char chisloZatarsene[10000010];
int razmer;

int basePow[10000010];
int prefixHash[10000010];

void rabinKarpPrecalc(){
    basePow[0] = 1;

    for(int i = 1; i < razmer; i++){
        basePow[i] = (BASE * basePow[i - 1]) % MOD;
    }

    prefixHash[0] = chisloZatarsene[0] - '0';

    for(int i = 1; i < razmer; i++){
        prefixHash[i] = (BASE * prefixHash[i - 1] + (chisloZatarsene[i] - '0')) % MOD;
    }
}

int daiHash(int otKade, int doKade){
    long long h1 = prefixHash[doKade];
    long long h2 = 0;

    if(otKade > 0){
        h2 = prefixHash[otKade - 1];
    }

    h2 = (h2 * basePow[doKade - otKade + 1])%MOD;

    return (h1 - h2 + MOD) % MOD;
}

int kadeZaPravPatSeSreshtaSled(int kakvoTarsim, int otKadeNatam, int daljina){
    int kadeSresht = -1;

    int doKade = razmer - daljina;

    for(int i = otKadeNatam; i <= doKade; i++){
        int hashTuk = daiHash(i, i + daljina - 1);

        if(hashTuk == kakvoTarsim){
            kadeSresht = i;
            break;
        }
    }

    return kadeSresht;
}


int main(){
    scanf("%s", chisloZatarsene);
    razmer = strlen(chisloZatarsene);

    rabinKarpPrecalc();

    int naiDalgoto = 0;
    int kolonaOtKoqtoZapochva = 1;

    /*for(unsigned int dal = 1; dal <= chisloZatarsene.size(); dal++){
        int zaOtkrivane = daiHash(0, dal - 1);
        int parvoSreshtaneSledNas = kadeZaPravPatSeSreshtaSled(zaOtkrivane, dal, dal);
        if(parvoSreshtaneSledNas != -1){
            naiDalgoto = dal;
            kolonaOtKoqtoZapochva = parvoSreshtaneSledNas + 1;
        }else{
            break;
        }
    }*/

    int lqvKrai = 1;
    int desenKrai = razmer/2 + 1;

    while(lqvKrai < desenKrai){
        int dal = (lqvKrai + desenKrai)/2;

        int zaOtkrivane = daiHash(0, dal - 1);
        int parvoSreshtaneSledNas = kadeZaPravPatSeSreshtaSled(zaOtkrivane, dal, dal);

        if(parvoSreshtaneSledNas == -1){
            desenKrai = dal;
        }else{
            lqvKrai = dal + 1;
            naiDalgoto = dal;
            kolonaOtKoqtoZapochva = parvoSreshtaneSledNas + 1;
        }
    }

    //cout<<naiDalgoto<<" "<<kolonaOtKoqtoZapochva<<endl;
    printf("%d ", naiDalgoto);
    printf("%d\n", kolonaOtKoqtoZapochva);

    return 0;
}
