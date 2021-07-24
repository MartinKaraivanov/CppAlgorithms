#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct GradIPat{
    int doGrad;
    long long razstoqnie;
};

struct Zaqvleniq{
    int otGrad;
    int doGrad;
    long long otgovor;
    int nachalenIndex;
};

int broiGradove;

vector<GradIPat> sasedstvo[5001];

int broiZaqvki;
Zaqvleniq zaqvklenca[200001];

long long naiKasPat[5001];
bool visited[5001];

void DFS(int vrah, long long razstDoTuk){
    visited[vrah] = true;
    naiKasPat[vrah] = razstDoTuk;

    for (int i = 0; i < sasedstvo[vrah].size(); i++){
        if (!visited[sasedstvo[vrah][i].doGrad]){
            DFS(sasedstvo[vrah][i].doGrad, razstDoTuk + sasedstvo[vrah][i].razstoqnie);
        }
    }
}

void nulirane(){
    for(int i = 0; i <= broiGradove ; i++){
        naiKasPat[i] = 0;
    }
    for(int i = 0; i <= broiGradove; i++){
        visited[i] = false;
    }
}

bool poMalkoLiE(Zaqvleniq a, Zaqvleniq b){
    return a.otGrad < b.otGrad;
}

bool poNomercaPoMalkoLiE(Zaqvleniq a, Zaqvleniq b){
    return a.nachalenIndex < b.nachalenIndex;
}

int main(){
    cin>>broiGradove>>broiZaqvki;

    int broiSasedstva = broiGradove-1;

    for(int i = 0; i < broiSasedstva; i++){
        int parviGrad;
        int vtoriGrad;
        long long razst;
        cin>>parviGrad>>vtoriGrad>>razst;

        GradIPat x = {vtoriGrad, razst};
        sasedstvo[parviGrad].push_back(x);

        GradIPat x2 = {parviGrad, razst};
        sasedstvo[vtoriGrad].push_back(x2);
    }

    for(int i = 0; i < broiZaqvki; i++){
        int oGrad;
        int dGrad;

        cin>>oGrad>>dGrad;

        zaqvklenca[i].otGrad = oGrad;
        zaqvklenca[i].doGrad = dGrad;
        zaqvklenca[i].nachalenIndex = i;

    }

    sort(zaqvklenca, zaqvklenca + broiZaqvki, poMalkoLiE);

    int predenOtGrad = 0;

    for(int i = 0; i < broiZaqvki; i++){
        if(predenOtGrad == zaqvklenca[i].otGrad){
            /// nqma nuzhda da pravim nishto
        }else{
            nulirane();
            DFS(zaqvklenca[i].otGrad, 0);
        }
        zaqvklenca[i].otgovor = naiKasPat[zaqvklenca[i].doGrad];
        predenOtGrad = zaqvklenca[i].otGrad;
    }

    sort(zaqvklenca, zaqvklenca + broiZaqvki, poNomercaPoMalkoLiE);

    for(int i = 0; i < broiZaqvki; i++){
        cout<< zaqvklenca[i].otgovor<<endl;
    }

    return 0;
}
