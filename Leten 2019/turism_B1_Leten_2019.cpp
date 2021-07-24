#include<iostream>
#include<vector>
using namespace std;

int broiGradove;

vector<int> sasedstvo[200010];

int broiSasStoinosti;
int stoinosti[200010];

int broiPitaniq;
int pitaniq[200010];

bool visited[200010];

int maximalnaStoinostZaTozi[200010];

int otgovori[200010];

/*void obhozhdane(int start, int grad, int natrupanaStoinost){
    if(visited[grad] == false){
        visited[grad] = true;

        bool listoLiE = true;

        for(unsigned int i = 0; i < sasedstvo[grad].size(); i++){
            if(visited[sasedstvo[grad][i]] == false){
                listoLiE = false;
                obhozhdane(start, sasedstvo[grad][i], natrupanaStoinost + stoinosti[sasedstvo[grad][i]]);
            }
        }

        if(listoLiE == true){
            maximalnaStoinostZaTozi[start] = max(maximalnaStoinostZaTozi[start], natrupanaStoinost);
        }

    }
}*/

int naiGolqmtotoNadolu[200010];
int vtorotNaiGolqmoNadolu[200010];

int namiraneNaRastoqniqNadolu(int grad){
    if(visited[grad]){
        return -1000000000;
    }

    visited[grad] = true;

    int naiMnogoto = 0;
    int vtorotoNaiMnogo = 0;

    for(unsigned int i = 0; i < sasedstvo[grad].size(); i++){
        int segashno = namiraneNaRastoqniqNadolu(sasedstvo[grad][i]) + stoinosti[sasedstvo[grad][i]];

        if(segashno > naiMnogoto){
            vtorotoNaiMnogo = naiMnogoto;
            naiMnogoto = segashno;
        }else{
            if(segashno > vtorotoNaiMnogo){
                vtorotoNaiMnogo = segashno;
            }
        }
    }

    naiGolqmtotoNadolu[grad] = naiMnogoto;
    vtorotNaiGolqmoNadolu[grad] = vtorotoNaiMnogo;

    return naiMnogoto;
}

int naiGolqmtotoNagore[200010];

void namiraneNaRazstoqniqNagore(int grad, int kolkoBihmePostignaliakoTragnemNagore){
    if(visited[grad]){
        return;
    }

    visited[grad] = true;

    naiGolqmtotoNagore[grad] = kolkoBihmePostignaliakoTragnemNagore;

    for(unsigned int i = 0; i < sasedstvo[grad].size(); i++){
        int poDoborot;

        if(naiGolqmtotoNadolu[grad] == naiGolqmtotoNadolu[sasedstvo[grad][i]] + stoinosti[sasedstvo[grad][i]]){
            poDoborot = max(kolkoBihmePostignaliakoTragnemNagore, vtorotNaiGolqmoNadolu[grad]);
        }else{
            poDoborot = max(kolkoBihmePostignaliakoTragnemNagore, naiGolqmtotoNadolu[grad]);
        }

        namiraneNaRazstoqniqNagore(sasedstvo[grad][i], poDoborot + stoinosti[grad]);
    }
}

void nulirane(){
    for(int i = 0; i <= broiGradove; i++){
        visited[i] = false;
    }
}

int main(){
    cin>>broiGradove;

    for(int i = 0; i < broiGradove - 1; i++){
        int otkade;
        int doKade;
        cin>>otkade>>doKade;

        sasedstvo[otkade].push_back(doKade);
        sasedstvo[doKade].push_back(otkade);
    }

    cin>>broiSasStoinosti;

    for(int i = 0; i < broiSasStoinosti; i++){
        int koiGrad;
        int stoinost;
        cin>>koiGrad>>stoinost;
        stoinosti[koiGrad] = stoinost;
    }

    cin>>broiPitaniq;

    for(int i = 0; i < broiPitaniq; i++){
        cin>>pitaniq[i];
    }

    namiraneNaRastoqniqNadolu(1);
    nulirane();
    namiraneNaRazstoqniqNagore(1, 0);

    //cout<<naiGolqmtotoNadolu[3]<<" "<<vtorotNaiGolqmoNadolu[3]<<endl;

    for(int i = 0; i < broiPitaniq; i++){
        otgovori[i] = max(naiGolqmtotoNadolu[pitaniq[i]], naiGolqmtotoNagore[pitaniq[i]]);
    }

    for(int i = 0; i < broiPitaniq; i++){
        cout<<otgovori[i]<<" ";
    }

    cout<<endl;

    return 0;
}
