#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int broiKasichki;

vector<int> taziKoiKluchoveSadarzha[100010];

int cvqtNaTozi[100010];

bool visited[100010];


void dfs(int vrah, int cvqt){
    if(visited[vrah] == false){
        visited[vrah] = true;
        cvqtNaTozi[vrah] = cvqt;
        for(unsigned int i = 0; i < taziKoiKluchoveSadarzha[vrah].size(); i++){
            if(visited[taziKoiKluchoveSadarzha[vrah][i]] == false){
                dfs(taziKoiKluchoveSadarzha[vrah][i], cvqt);
            }
        }
    }
}

void nulirne(){
    for(int i = 1; i <= broiKasichki; i++){
        visited[i] = false;
        cvqtNaTozi[i] = 0;
        taziKoiKluchoveSadarzha[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int d = 0; d < 2; d++){
        nulirne();
        cin>>broiKasichki;

        for(int i = 1; i <= broiKasichki; i++){
            int naTaziKadeIEklucha;
            cin>>naTaziKadeIEklucha;
            taziKoiKluchoveSadarzha[naTaziKadeIEklucha].push_back(i);
            taziKoiKluchoveSadarzha[i].push_back(naTaziKadeIEklucha);
        }

        int nomerche = 0;

        for(int i = 1; i <= broiKasichki; i++){
            if(cvqtNaTozi[i] == 0){
                nomerche++;
                dfs(i, nomerche);
            }
        }

        cout<<nomerche<<" ";
    }

    cout<<endl;

    return 0;
}
