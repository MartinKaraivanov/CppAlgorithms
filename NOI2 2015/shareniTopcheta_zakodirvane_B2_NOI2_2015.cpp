#include<iostream>
#include<map>
#include<vector>
using namespace std;

int broiTopcheta;
int broiDvoiki;

map<int, int> kodoviImena;
int broiZakodirani;

vector<int> sasedstvo[200010];

int otKoqKomponentaE[200010];
int broiKomponenti;
bool visited[200010];

void dfs(int vrah, int nomerche){
    if(visited[vrah] == false){
        visited[vrah] = true;
        otKoqKomponentaE[vrah] = nomerche;
        for(unsigned int tozi = 0; tozi < sasedstvo[vrah].size(); tozi++){
            dfs(sasedstvo[vrah][tozi], nomerche);
        }
    }
}

int main(){
    cin>>broiTopcheta>>broiDvoiki;

    for(int i = 0; i < broiDvoiki; i++){
        int parvo;
        int vtoro;
        cin>>parvo>>vtoro;

        int zakodiranoParvo = kodoviImena[parvo];
        int zakodiranoVtoro = kodoviImena[vtoro];

        if(zakodiranoParvo == 0){
            broiZakodirani++;
            kodoviImena[parvo] = broiZakodirani;
            zakodiranoParvo = broiZakodirani;
        }

        if(zakodiranoVtoro == 0){
            broiZakodirani++;
            kodoviImena[vtoro] = broiZakodirani;
            zakodiranoVtoro = broiZakodirani;
        }

        sasedstvo[zakodiranoParvo].push_back(zakodiranoVtoro);
        sasedstvo[zakodiranoVtoro].push_back(zakodiranoParvo);

    }

    for(int i = 1; i <= broiZakodirani; i++){
        if(otKoqKomponentaE[i] == 0){
            broiKomponenti++;
            dfs(i, broiKomponenti);
        }
    }

    int broiNuzhniCvetove = broiTopcheta - broiZakodirani + broiKomponenti;

    cout<<broiNuzhniCvetove<<endl;

    return 0;
}
