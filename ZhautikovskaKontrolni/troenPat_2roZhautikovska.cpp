#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int broiTestove;
int broiVarhove;
int broiPatishta;

int sasedstvo[1000][1000];

int rSasedstvo[1000][1000];

void nulirane(){
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            sasedstvo[i][j] = 0;
            rSasedstvo[i][j] = 0;
        }
    }
}

void nuliraneNaRSasedstvoto(){
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            rSasedstvo[i][j] = 0;
        }
    }
}

bool bfs(int start, int krai, int parents[1000]){
    bool visited[1000];

    for(int i = 0; i < 1000; i++){
        visited[i] = false;
    }

    queue<int> q;

    q.push(start);
    parents[start] = 0;
    visited[start] = true;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        for(int i = 1; i <= broiVarhove; i++){
            if(rSasedstvo[vrah][i] == 1 && visited[i] == false){
                q.push(i);
                parents[i] = vrah;
                visited[i] = true;
            }
        }

    }

    return visited[krai];
}

int FordFulkersonFLow(int start, int krai){
    //cout<<"vlqzoh"<<endl;
    int maksFlow = 0;

    for(int i = 1; i <= broiVarhove; i++){
        for(int j = 1; j <= broiVarhove; j++){
            rSasedstvo[i][j] = sasedstvo[i][j];
        }
    }

    //cout<<"vlqzal sum";

    while(true){
        int parents[1000];
        bool stigameLi = bfs(start, krai, parents);
        if(stigameLi == false){
            break;
        }

        int patishtenPotok = 0;

        for(int v = krai; v != start; v = parents[v]){
            int u = parents[v];
            patishtenPotok = max(patishtenPotok, rSasedstvo[u][v]);
        }

        for(int v = krai; v != start; v = parents[v]){
            int u = parents[v];
            rSasedstvo[u][v] -= patishtenPotok;
            rSasedstvo[v][u] += patishtenPotok;
        }

        maksFlow += patishtenPotok;
    }

    return maksFlow;
}

int main(){
    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        nulirane();
        cin>>broiVarhove>>broiPatishta;

        for(int j = 0; j < broiPatishta; j++){
            int otKoi;
            int doKoi;

            doKoi += 10;

            cin>>otKoi>>doKoi;

            sasedstvo[otKoi][doKoi] = 1;
            sasedstvo[doKoi][otKoi] = 1;
        }

        if(broiPatishta < 5){
            cout<<-1<<endl;
            continue;
        }

        int imaLi = false;

        for(int i = 1; i <= broiVarhove; i++){
            for(int j = i + 1; j <= broiVarhove; j++){
                nuliraneNaRSasedstvoto();
                int a = i;
                int b = j;
                //cout<<"predi da vlqza"<<endl;
                int rezultat = FordFulkersonFLow(a, b);
                if(rezultat >= 3){
                    imaLi = true;
                    cout<<i<<" "<<j<<endl;

                    int br = 0;
                    for(int g = 1; g <= broiVarhove && br < 3; g++){
                        if(rSasedstvo[a][g] == 0 && sasedstvo[a][g] == 1){
                            br++;

                            queue<int> q;
                            q.push(a);
                            int segashenVrah = g;
                            while(segashenVrah != b){
                                q.push(segashenVrah);
                                for(int l = 1; l <= broiVarhove; l++){
                                    if(rSasedstvo[segashenVrah][l] == 0 && sasedstvo[segashenVrah][l] == 1){
                                        segashenVrah = l;
                                        break;
                                    }
                                }
                            }
                            q.push(b);

                            cout<<q.size()<<" ";
                            while(q.size() > 1){
                                int naiNapred = q.front();
                                q.pop();
                                cout<<naiNapred<<" ";
                            }
                            cout<<q.front()<<endl;
                            q.pop();
                        }
                    }

                    break;
                }

            }
            if(imaLi == true){
                break;
            }
        }

        if(!imaLi){
            cout<<-1<<endl;
        }
    }

    return 0;
}
