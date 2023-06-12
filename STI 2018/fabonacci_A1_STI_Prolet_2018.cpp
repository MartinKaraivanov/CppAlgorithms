#include<iostream>
using namespace std;

const long long mnogo = 1000000007;

int koiElement;
string koqDuma;
int dumaDaljina;

string nachalo[10010];
string krai[10010];

int daljina[10010];

long long priTolkova[10010];

long long broiSreshtaniq(int doKade){
    if(daljina[doKade] < dumaDaljina){
        return 0;
    }
    if(doKade == 0){
        return koqDuma == "a";
    }
    if(doKade == 1){
        return koqDuma == "b";
    }
    if(priTolkova[doKade] > -1){
        return priTolkova[doKade];
    }

    long long zaTuka = (broiSreshtaniq(doKade-2) + broiSreshtaniq(doKade-1))%mnogo;

    string kraino = krai[doKade - 2];
    string nachalno = nachalo[doKade - 1];

    if(kraino.size() > dumaDaljina-1){
        kraino = kraino.substr(kraino.size()-dumaDaljina+1, dumaDaljina-1);
    }
    if(nachalno.size() > dumaDaljina-1){
        nachalno = nachalno.substr(0, dumaDaljina-1);
    }

    string vazmojno = kraino + nachalno;

    for(int i = 0; i < vazmojno.size()-dumaDaljina+1; i++){
        bool stavaLi = true;
        for(int j = 0; j < dumaDaljina; j++){
            if(vazmojno[i + j] != koqDuma[j]){
                stavaLi = false;
                break;
            }
        }

        if(stavaLi == true){
            zaTuka = (zaTuka + 1)%mnogo;
        }
    }

    priTolkova[doKade] = zaTuka;
    return zaTuka;
}

int main(){

    cin>>koiElement;
    cin>>koqDuma;

    dumaDaljina = koqDuma.size();

    nachalo[0] = "a";
    krai[0] = "a";
    daljina[0] = 1;
    priTolkova[0] = -1;

    nachalo[1] = "b";
    krai[1] = "b";
    daljina[1] = 1;
    priTolkova[1] = -1;

    for(int i = 2; i <= koiElement; i++){
        daljina[i] = daljina[i - 2] + daljina[i - 1];
        if(daljina[i] > 100){
            daljina[i] = 100;
        }
        priTolkova[i] = -1;
        nachalo[i] = (nachalo[i - 2] + nachalo[i - 1]).substr(0, daljina[i]);
        krai[i] = (krai[i - 2] + krai[i - 1]).substr(daljina[i-2] + daljina[i-1] - daljina[i], daljina[i]);
    }

    long long otgovor = broiSreshtaniq(koiElement);

    cout<<otgovor<<endl;

    return 0;
}
