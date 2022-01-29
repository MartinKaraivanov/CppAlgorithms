#include<iostream>
#include<vector>
using namespace std;

int broiPlochki;

struct DanniZaPlochkata{
    int parviKrai;
    int vtoriKrai;
};

DanniZaPlochkata plochki[30];

int naiDalgoto = 0;

bool vzimameLiQ[30];

vector<int> sasedstvo[11];

bool visited[11];

void dfs(int segashen, int otKadeIdvame){
    if(visited[segashen] == true){
        return ;
    }
    visited[segashen] = true;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            dfs(sasedstvo[segashen][i], segashen);
        }
    }
}

void izchisliKraenSluchai(){
    int stepenNaVarha[11];

    for(int i = 0; i <= 6; i++){
        stepenNaVarha[i] = 0;
        sasedstvo[i].clear();
        visited[i] = false;
    }

    int kolkoPlochkiSaSega = 0;

    for(int i = 0; i < broiPlochki; i++){
        if(vzimameLiQ[i] == true){
            stepenNaVarha[plochki[i].parviKrai]++;
            stepenNaVarha[plochki[i].vtoriKrai]++;
            sasedstvo[plochki[i].parviKrai].push_back(plochki[i].vtoriKrai);
            sasedstvo[plochki[i].vtoriKrai].push_back(plochki[i].parviKrai);
            kolkoPlochkiSaSega++;
        }
    }

    //cout<<"sega vzimame "<<kolkoPlochkiSaSega<<endl;

    for(int i = 0; i <= 6; i++){
        if(stepenNaVarha[i] != 0){
            dfs(i, -1);
            break;
        }
    }

    /*cout<<"sled dfs sa visited: ";
    for(int i = 0; i <= 6; i++){
        if(visited[i] == true){
            cout<<i<<" ";
        }
    }
    cout<<endl;*/

    bool okLiE = true;

    for(int i = 0; i <= 6; i++){
        if((stepenNaVarha[i] != 0 && visited[i] == false) || stepenNaVarha[i]%2 == 1){
            //cout<<"sega otkrivame che "<<i<<" ne e visitnat"<<endl;
            okLiE = false;
            break;
        }
    }

    if(okLiE == true){
        naiDalgoto = kolkoPlochkiSaSega;
    }

}

void obrazuvaiKragche(int naKoqPlochkaSme, int sKolkoPlochki){
    if(sKolkoPlochki == 0){
        izchisliKraenSluchai();
        return ;
    }
    if(naKoqPlochkaSme == broiPlochki){
        return ;
    }

    vzimameLiQ[naKoqPlochkaSme] = true;
    obrazuvaiKragche(naKoqPlochkaSme + 1, sKolkoPlochki - 1);
    vzimameLiQ[naKoqPlochkaSme] = false;

    obrazuvaiKragche(naKoqPlochkaSme + 1, sKolkoPlochki);
}

int main(){

    cin>>broiPlochki;

    for(int i = 0; i < broiPlochki; i++){
        int edinKrai;
        int drugKrai;

        cin>>edinKrai>>drugKrai;

        plochki[i] = {edinKrai, drugKrai};
    }

    for(int i = broiPlochki; i >= 3; i--){
        obrazuvaiKragche(0, i);
        if(naiDalgoto > 0){
            break;
        }
    }

    cout<<naiDalgoto<<endl;

    return 0;
}
