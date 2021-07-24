#include<iostream>
#include<vector>
using namespace std;

struct DanniZaNaiDalagPat{
    int kolkoDalag;
    int prezKoi;
};

int broiVarhove;

vector<int> sasedstvo[100010];

DanniZaNaiDalagPat naiDalgiqPatNadolu[100010];
DanniZaNaiDalagPat vtoriqNaiDalagPatNadolu[100010];

int naiDalgiqtNagore[100010];

int naiDalagPatIzobshto[100010];

vector<int> otgovori[100010];

int nadolu(int segashen, int otKadeIdvame){

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int zaTuk = nadolu(sasedstvo[segashen][i], segashen);
            if(zaTuk > naiDalgiqPatNadolu[segashen].kolkoDalag){
                vtoriqNaiDalagPatNadolu[segashen] = naiDalgiqPatNadolu[segashen];
                naiDalgiqPatNadolu[segashen] = {zaTuk, sasedstvo[segashen][i]};
            }else{
                if(zaTuk > vtoriqNaiDalagPatNadolu[segashen].kolkoDalag){
                    vtoriqNaiDalagPatNadolu[segashen] = {zaTuk, sasedstvo[segashen][i]};
                }
            }
        }
    }

    return naiDalgiqPatNadolu[segashen].kolkoDalag + 1;
}

void nagore(int segashen, int otKadeIdvame, int naiGolqmotoOtgore){
    naiDalgiqtNagore[segashen] = naiGolqmotoOtgore;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int ednotoVazmozhno = naiGolqmotoOtgore;
            int drugotoVazmozhno = -1;

            if(naiDalgiqPatNadolu[segashen].prezKoi != sasedstvo[segashen][i]){
                drugotoVazmozhno = naiDalgiqPatNadolu[segashen].kolkoDalag;
            }else{
                drugotoVazmozhno = vtoriqNaiDalagPatNadolu[segashen].kolkoDalag;
            }

            nagore(sasedstvo[segashen][i], segashen, max(ednotoVazmozhno, drugotoVazmozhno) + 1);
        }
     }
}

void praveneNaIzobshtoNaiGolqmoto(){
    for(int i = 1; i <= broiVarhove; i++){
        naiDalagPatIzobshto[i] = max(naiDalgiqPatNadolu[i].kolkoDalag, naiDalgiqtNagore[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove;

    for(int i = 1; i < broiVarhove; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    nadolu(1, -1);
    nagore(1, -1, 0);

    praveneNaIzobshtoNaiGolqmoto();

    int naiKasoto = 100010;

    for(int i = 1; i <= broiVarhove; i++){
        otgovori[naiDalagPatIzobshto[i]].push_back(i);
        if(naiDalagPatIzobshto[i] < naiKasoto){
            naiKasoto = naiDalagPatIzobshto[i];
        }
    }

    cout<<otgovori[naiKasoto].size()<<endl;

    for(unsigned int i = 0; i < otgovori[naiKasoto].size(); i++){
        cout<<otgovori[naiKasoto][i]<<" ";
    }

    cout<<endl;

    return 0;
}
