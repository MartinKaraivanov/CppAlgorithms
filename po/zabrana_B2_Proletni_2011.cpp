#include<iostream>
#include<vector>
using namespace std;

int broiGradove;
int broiDirektniPatishta;

vector<int> sasedstvo[650];
bool visited[650];

void nulirane(){
    for(int i = 1; i <= broiGradove; i++){
        visited[i] = false;
    }
}

void dfs(int vrah){
    if(!visited[vrah]){
        visited[vrah] = true;
        for(int i = 0; i < sasedstvo[vrah].size(); i++){
            dfs(sasedstvo[vrah][i]);
        }
    }
}

int naKoqPoziciqE(int otgrad, int dograd){
    for(int i=0;i<sasedstvo[otgrad].size();i++){
        if(sasedstvo[otgrad][i]==dograd){
            return i;
        }
    }
    return -1;
}

int main(){
    cin>>broiGradove>>broiDirektniPatishta;

    for(int i=0;i<broiDirektniPatishta;i++){
        int parviGrad;
        int vtoriGrad;
        cin>>parviGrad>>vtoriGrad;
        sasedstvo[parviGrad].push_back(vtoriGrad);
        sasedstvo[vtoriGrad].push_back(parviGrad);
    }

    int zabraneniBroi = 0;

    for(int otgrad=1;otgrad<=broiGradove;otgrad++){
        for(int j=0;j<sasedstvo[otgrad].size();j++){
            int dograd = sasedstvo[otgrad][j];

            sasedstvo[otgrad].erase(sasedstvo[otgrad].begin() + j);

            int zaMahOtGrad = naKoqPoziciqE(dograd, otgrad);
            sasedstvo[dograd].erase(sasedstvo[dograd].begin() + zaMahOtGrad);

            dfs(otgrad);

            if(visited[dograd]){
                ///nishto ne pravim
            }else{
                zabraneniBroi++;
            }

            nulirane();

            sasedstvo[otgrad].insert(sasedstvo[otgrad].begin() + j, dograd);
            sasedstvo[dograd].insert(sasedstvo[dograd].begin() + zaMahOtGrad ,otgrad);

        }
    }

    cout<<zabraneniBroi/2<<endl;

    return 0;
}
