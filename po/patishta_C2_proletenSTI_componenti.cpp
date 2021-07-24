#include<iostream>
#include<vector>
using namespace std;

int broiGradove;
int broiOtsechki;
int broiObazhdaniq;

vector<int> sasedstvo[15500];

bool otgovori[105000];
int broiOtgovori;
bool visited[11000];

int otKoqKomponentaE[11000];
int broiComponenti;


void nulirane(){
    for(int i=1;i<=broiGradove;i++){
        otKoqKomponentaE[i]=0;
    }
}

void nuliraneNaVisited(){
    for(int i=1;i<=broiGradove;i++){
        visited[i]=false;
    }
}

/*void DFS(int vrah){
    if(visited[vrah]==false){
        visited[vrah] = true;
        for(int i=1; i<=broiGradove;i++){
            if(sasedstvo[vrah][i]==true){
                DFS(i);
            }
        }
    }
}*/

void namiraneNaComponenti(int grad, int nomerche){
    if(!visited[grad]){
        otKoqKomponentaE[grad] = nomerche;
        visited[grad]=true;
        for(int i=0; i<sasedstvo[grad].size();i++){
            namiraneNaComponenti(sasedstvo[grad][i], nomerche);
        }
    }
}

int naKoqPoziciqE(int otGrad, int doGrad){
    for(int i=0;i<sasedstvo[otGrad].size();i++){
        if(sasedstvo[otGrad][i]==doGrad){
            return i;
        }
    }
    return -1;
}

int main(){
    cin>>broiGradove>>broiOtsechki;

    for(int i=0;i<broiOtsechki;i++){
        int otgrad;
        int dograd;

        cin>>otgrad>>dograd;

        sasedstvo[otgrad].push_back(dograd);
        sasedstvo[dograd].push_back(otgrad);
    }

    for(int i=1;i<=broiGradove;i++){
        if(otKoqKomponentaE[i]==0){
            namiraneNaComponenti(i,broiComponenti+1);
            broiComponenti++;
        }
    }

    cin>>broiObazhdaniq;

    for(int i =0;i<broiObazhdaniq;i++){
        int vidObazhdane;
        int otgrad;
        int dograd;

        cin>>vidObazhdane>>otgrad>>dograd;

        if(vidObazhdane==1){
            if(otKoqKomponentaE[otgrad]==otKoqKomponentaE[dograd]){
                otgovori[broiOtgovori]=true;
            }else{
                otgovori[broiOtgovori]=false;
            }
            broiOtgovori++;
        }else{
            if(vidObazhdane==2){
                int zaMahDoGgrad = naKoqPoziciqE(otgrad, dograd);
                if(zaMahDoGgrad!=-1){
                    sasedstvo[otgrad].erase(sasedstvo[otgrad].begin() + zaMahDoGgrad);
                }

                int zaMahOtGrad = naKoqPoziciqE(dograd, otgrad);
                if(zaMahOtGrad!=-1){
                    sasedstvo[dograd].erase(sasedstvo[dograd].begin() + zaMahOtGrad);
                }

                int num = otKoqKomponentaE[otgrad];

                nuliraneNaVisited();

                namiraneNaComponenti(dograd, broiComponenti+1);
                broiComponenti++;

            }else{
                if(vidObazhdane==3){
                    int v = naKoqPoziciqE(otgrad, dograd);
                    if(v==-1){
                        sasedstvo[otgrad].push_back(dograd);
                        sasedstvo[dograd].push_back(otgrad);
                        if(otKoqKomponentaE[dograd]!=otKoqKomponentaE[otgrad]){
                            int nomerche = otKoqKomponentaE[dograd];
                            for(int j=1;j<=broiGradove;j++){
                                if(otKoqKomponentaE[j]==nomerche){
                                    otKoqKomponentaE[j]=otKoqKomponentaE[otgrad];
                                }
                            }
                        }
                    }

                }
            }
        }
    }

    for(int i =0;i<broiOtgovori;i++){
        cout<<otgovori[i];
    }

    cout<<endl;

    return 0;
}
