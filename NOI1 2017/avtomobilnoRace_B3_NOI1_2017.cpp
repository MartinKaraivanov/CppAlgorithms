#include<iostream>
using namespace std;

int broiPunktove;
int ceni[1050];
int naiDbCena[1010][1010];

int naiDobraCena(int punkt, int broiPropuskiNaServis){
    if(punkt >= broiPunktove){
        return 0;
    }

    if(naiDbCena[punkt][broiPropuskiNaServis] > -1){
        return naiDbCena[punkt][broiPropuskiNaServis];
    }

    int naiDobroto = 10000000;

    if(broiPropuskiNaServis == 2){
        naiDobroto = ceni[punkt] + naiDobraCena(punkt + 1, 0);
    }else{

        int akoGoVzemem = ceni[punkt] + naiDobraCena(punkt + 1, 0);
        int akoNeGoVzemem = naiDobraCena(punkt + 1, broiPropuskiNaServis + 1);

        int poDobro = min(akoGoVzemem, akoNeGoVzemem);

        naiDobroto = min(naiDobroto, poDobro);
    }

    naiDbCena[punkt][broiPropuskiNaServis] = naiDobroto;
    return naiDobroto;
}

void nulirvaneNaNaiDb(){
    for(int i = 0; i < 1010; i++){
        for(int j = 0; j < 1010; j++){
            naiDbCena[i][j] = -1;
        }
    }
}

int main(){
    cin>>broiPunktove;

    for(int i = 0; i < broiPunktove; i++){
        cin>>ceni[i];
    }

    if(broiPunktove == 1){
        cout<<ceni[0]<<endl;
        return 0;
    }

    if(broiPunktove == 2){
        cout<<min(ceni[0], ceni[1])<<endl;
        return 0;
    }

    nulirvaneNaNaiDb();

    int naiDobro = naiDobraCena(0, 0);

    cout<<naiDobro<<endl;

    return 0;
}
