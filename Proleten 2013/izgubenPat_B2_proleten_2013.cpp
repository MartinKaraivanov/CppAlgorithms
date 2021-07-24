#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

string start;
string finaal;

vector<int> sasedstvo[1000010];

map<string, int> toziGradSKoiNomerE;

string tovaNomercheKoiGradE[1000010];

int nomercheZaGrad = 0;

int daiNomercheZaGrad(string grad){
    int kakvoPishe = toziGradSKoiNomerE[grad];
    if(kakvoPishe > 0){
        return kakvoPishe;
    }

    nomercheZaGrad++;
    toziGradSKoiNomerE[grad] = nomercheZaGrad;
    tovaNomercheKoiGradE[nomercheZaGrad] = grad;

    return nomercheZaGrad;
}

int nomercheNaStarta;
int nomercheNaFinaala;

bool visited[1000010];
int masivZaPechatne[1000010];

int main(){
    int broiGradove;

    cin>>broiGradove;

    cin>>start>>finaal;

    nomercheNaStarta = daiNomercheZaGrad(start);
    nomercheNaFinaala = daiNomercheZaGrad(finaal);

    for(int i = 0; i < broiGradove - 1; i++){
        string parvi;
        string vtori;
        cin>>parvi>>vtori;

        int nomercheNaParvi = daiNomercheZaGrad(parvi);
        int nomercheNaVtori = daiNomercheZaGrad(vtori);

        sasedstvo[nomercheNaParvi].push_back(nomercheNaVtori);
        sasedstvo[nomercheNaVtori].push_back(nomercheNaParvi);
    }

    int grad = nomercheNaStarta;

    int nomerchence = 0;

    while(true){
        //cout<<grad<<endl;
        visited[grad] = true;
        masivZaPechatne[nomerchence] = grad;
        nomerchence++;

        if(sasedstvo[grad].size() == 0 || (sasedstvo[grad].size() == 1 && grad != nomercheNaStarta)){
            break;
        }

        int nomercheNaRazlichnoto;

        if(visited[sasedstvo[grad][0]] == false){
            nomercheNaRazlichnoto = sasedstvo[grad][0];
        }else{
            nomercheNaRazlichnoto = sasedstvo[grad][1];
        }

        grad = nomercheNaRazlichnoto;
    }

    grad = nomercheNaFinaala;

    nomerchence = broiGradove;

    while(true){
        //cout<<grad<<endl;
        visited[grad] = true;
        masivZaPechatne[nomerchence] = grad;
        nomerchence--;

        if(sasedstvo[grad].size() == 0 || (sasedstvo[grad].size() == 1 && grad != nomercheNaFinaala)){
            break;
        }

        int nomercheNaRazlichnoto;

        if(visited[sasedstvo[grad][0]] == false){
            nomercheNaRazlichnoto = sasedstvo[grad][0];
        }else{
            nomercheNaRazlichnoto = sasedstvo[grad][1];
        }

        grad = nomercheNaRazlichnoto;
    }

    for(int i = 0; i <= broiGradove; i++){
        cout<<tovaNomercheKoiGradE[masivZaPechatne[i]]<<endl;
    }

    return 0;
}
