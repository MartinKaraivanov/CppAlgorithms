#include<iostream>
#include<vector>
using namespace std;

int broiGradove;
int broiPatishta;
int broiPitaniq;

vector<int> sasedstvo[1100];

int otKoqKomponentaSa[1100];
bool visited[1100];

int otgovori[1000000];
int broiOtg;

void dfs(int vrah, int nomerche){
    if(visited[vrah] == false){
        visited[vrah] = true;
        otKoqKomponentaSa[vrah] = nomerche;
        for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
            dfs(sasedstvo[vrah][i], nomerche);
        }
    }
}

void stroeneNaKomponenti(){
    int nomerche = 1;
    for(int i = 0; i < broiGradove; i++){
        if(otKoqKomponentaSa[i] == 0){
            dfs(i, nomerche);
            nomerche++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove>>broiPatishta;

    for(int i = 0; i < broiPatishta; i++){
        int otGrad;
        int doGrad;
        cin>>otGrad>>doGrad;
        sasedstvo[otGrad].push_back(doGrad);
        sasedstvo[doGrad].push_back(otGrad);
    }

    cin>>broiPitaniq;

    stroeneNaKomponenti();

    for(int i = 0; i < broiPitaniq; i++){
        int tip;
        int otGrad;
        int doGrad;
        cin>>tip>>otGrad>>doGrad;

        if(tip == 1){
            //cout<<otGrad<<" "<<doGrad<<endl;
            if(otKoqKomponentaSa[otGrad] == otKoqKomponentaSa[doGrad]){
                otgovori[broiOtg] = 1;
                broiOtg++;
                //cout<<"ot edna sa";
            }else{
                otgovori[broiOtg] = 0;
                broiOtg++;
            }
        }else{
            sasedstvo[otGrad].push_back(doGrad);
            sasedstvo[doGrad].push_back(otGrad);
            if(otKoqKomponentaSa[otGrad] != otKoqKomponentaSa[doGrad]){
                int nomerchetoNaVtoriqtGrad = otKoqKomponentaSa[doGrad];
                for(int j = 1; j <= broiGradove; j++){
                    if(otKoqKomponentaSa[j] == nomerchetoNaVtoriqtGrad){
                        otKoqKomponentaSa[j] = otKoqKomponentaSa[otGrad];
                    }
                }
            }
        }
    }

    for(int i = 0; i < broiOtg; i++){
        cout<<otgovori[i];
    }

    cout<<endl;

    return 0;
}
