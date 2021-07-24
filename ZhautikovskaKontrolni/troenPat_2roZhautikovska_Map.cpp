#include<iostream>
#include<queue>
#include<map>

using namespace std;

int broiTestove;
int broiVarhove;
int broiPatishta;

int parents[100010];
bool visited[100010];

struct Danni{
    int doKoi;
    int capacitet;
    int rCapacitet;
};

map<int, Danni> sasedstvo[100010];

void nuliraneVisited(){
    fill(visited, visited + broiVarhove + 1, false);
}


int vzemiRCapacitet(int otKoi, int doKoi){
    return sasedstvo[otKoi][doKoi].rCapacitet;
}

void promeniRCapacitetS(int otKoi, int doKoi, int rCapacitet){
    sasedstvo[otKoi][doKoi].rCapacitet += rCapacitet;
}


bool bfs(int start, int krai){
    queue<int> q;
    q.push(start);

    parents[start] = 0;

    nuliraneVisited();
    visited[start] = true;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        for(auto k : sasedstvo[vrah]){
            if(k.second.rCapacitet == 1 && visited[k.second.doKoi] == false){
                q.push(k.second.doKoi);
                parents[k.second.doKoi] = vrah;
                visited[k.second.doKoi] = true;
            }
        }

    }

    return visited[krai];
}

void inicializirneNaRSasedstvo(){
    for(int h = 1; h <= broiVarhove; h++){
        for(auto element : sasedstvo[h]){
            sasedstvo[h][element.first].rCapacitet = element.second.capacitet;
        }
    }
}

int FordFulkersonFLow(int start, int krai){
    int maksFlow = 0;

    inicializirneNaRSasedstvo();

    while(true){
        if(maksFlow >= 3){
            break;
        }
        bool stigameLi = bfs(start, krai);
        if(stigameLi == false){
            break;
        }

        int patishtenPotok = 0;

        for(int v = krai; v != start; v = parents[v]){
            int u = parents[v];
            patishtenPotok = max(patishtenPotok, vzemiRCapacitet(u, v));
        }

        for(int v = krai; v != start; v = parents[v]){
            int u = parents[v];
            promeniRCapacitetS(u, v, -patishtenPotok);
            promeniRCapacitetS(v, u, patishtenPotok);
        }

        maksFlow += patishtenPotok;
    }

    return maksFlow;
}

void nulirane(){
    for(int i = 1; i <= broiVarhove; i++){
        sasedstvo[i].clear();
    }
}

int main(){
    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>broiVarhove>>broiPatishta;

        nulirane();

        for(int j = 0; j < broiPatishta; j++){
            int otKoi;
            int doKoi;

            cin>>otKoi>>doKoi;

            Danni zaDob = {doKoi, 1, 1};

            sasedstvo[otKoi][doKoi] = zaDob;

            zaDob = {otKoi, 1, 1};

            sasedstvo[doKoi][otKoi] = zaDob;
        }

        if(broiPatishta < 5){
            cout<<-1<<endl;
            continue;
        }

        int imaLi = false;

        for(int i = 1; i <= broiVarhove; i++){
            for(int j = i + 1; j <= broiVarhove; j++){
                int a = i;
                int b = j;
                //cout<<"predi da vlqza"<<endl;
                int rezultat = FordFulkersonFLow(a, b);
                if(rezultat >= 3){
                    imaLi = true;
                    cout<<i<<" "<<j<<endl;

                    int br = 0;

                    for(auto s : sasedstvo[a]){
                        if(br >= 3){
                            break;
                        }
                        if(s.second.rCapacitet == 0 && s.second.capacitet == 1){
                            int g = s.second.doKoi;
                            br++;

                            queue<int> q;
                            q.push(a);
                            int segashenVrah = g;
                            while(segashenVrah != b){
                                q.push(segashenVrah);

                                for(auto k : sasedstvo[segashenVrah]){
                                    if(k.second.rCapacitet ==  0 && k.second.capacitet == 1){
                                        segashenVrah = k.second.doKoi;
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
