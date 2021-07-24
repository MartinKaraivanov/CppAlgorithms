#include<iostream>
#include<vector>
using namespace std;

int broiGradove;
int broiShoseta;

vector<int> sasedstvo[1010];

bool toziImaLiTozKatoSased[1010][1010];

int toziOtKoqKomponentaE[1010];

bool visited[1010];

void ocvetqvane(int vrah, int nomerche){
    if(visited[vrah] == true){
        return ;
    }

    visited[vrah] = true;
    toziOtKoqKomponentaE[vrah] = nomerche;

    for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
        ocvetqvane(sasedstvo[vrah][i], nomerche);
    }

}

int main(){
    cin>>broiGradove>>broiShoseta;

    for(int i = 0; i < broiShoseta; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        toziImaLiTozKatoSased[otKade][doKade] = true;
        toziImaLiTozKatoSased[doKade][otKade] = true;
    }

    for(int i = 1; i <= broiGradove; i++){
        for(int j = 1; j <= broiGradove; j++){
            if(toziImaLiTozKatoSased[i][j] == false){
                sasedstvo[i].push_back(j);
            }
        }
    }

    int nomerche = 1;

    for(int i = 1; i <= broiGradove; i++){
        if(toziOtKoqKomponentaE[i] == 0){
            ocvetqvane(i, nomerche);
            nomerche++;
        }
    }

    cout<<nomerche - 2<<endl;

    return 0;
}
