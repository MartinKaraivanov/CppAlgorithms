#include<iostream>
#include<vector>
using namespace std;

struct DanniZaPaketa{
    int otKade;
    int doKade;
    int cena;
};

int broiPaketi;
DanniZaPaketa paketi[10500];

vector<int> kakviPaketiImaZaTuk[1050000];

int start;
int finaal;

int naiDbCenaPriTolkova[1050000];

int naiDobraCenaDoKraq(int spirka){
    if(spirka >= finaal){
        return 0;
    }

    if(naiDbCenaPriTolkova[spirka] > 0){
        return naiDbCenaPriTolkova[spirka];
    }

    int naiDobro = 1 + naiDobraCenaDoKraq(spirka + 1);

    for(unsigned int i = 0; i < kakviPaketiImaZaTuk[spirka].size(); i++){
        int eventualno = paketi[kakviPaketiImaZaTuk[spirka][i]].cena +
            naiDobraCenaDoKraq(paketi[kakviPaketiImaZaTuk[spirka][i]].doKade);

        if(eventualno < naiDobro){
            naiDobro = eventualno;
        }
    }

    //cout<<naiDobro<<endl;

    naiDbCenaPriTolkova[spirka] = naiDobro;

    return naiDobro;
}

int main(){
    cin>>broiPaketi>>start>>finaal;

    for(int i = 1; i <= broiPaketi; i++){
        cin>>paketi[i].otKade>>paketi[i].doKade>>paketi[i].cena;
    }

    for(int i = 1; i <= broiPaketi; i++){
        int startche = max(paketi[i].otKade, start);
        int finalche = min(paketi[i].doKade, finaal + 1);
        for(int j = startche; j < finalche; j++){
            kakviPaketiImaZaTuk[j].push_back(i);
        }
    }

    int naiDobraCenichka = naiDobraCenaDoKraq(start);

    cout<<naiDobraCenichka<<endl;

    return 0;
}
