#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

const int MaxMax = 100010;

int broiTestove;
int broiVarhove;
int broiPatishta;

int parents[MaxMax];
bool visited[MaxMax];

struct Danni{
    int doKoi;
    int capacitet;
    int rCapacitet;
};

vector<Danni> sasedstvo[MaxMax];  // triabva vector<map<danni>>

int dalbochina[MaxMax];
int lowLink[MaxMax];
int otKoqKomponentaE[MaxMax];
bool vStekaLiE[MaxMax];
stack<int> st;
int nomerche = 1;
int dlb = 0;

void nuliraneVisited(){
    fill(visited, visited + broiVarhove + 1, false);
}

void pravenennaKomponenti(int vrah){
    dalbochina[vrah] = dlb;
    lowLink[vrah] = dlb;
    dlb++;
    st.push(vrah);
    vStekaLiE[vrah] = true;

    for(Danni sldVr: sasedstvo[vrah]){
        int sledvasht = sldVr.doKoi;
        if(dalbochina[sledvasht] == -1){
            pravenennaKomponenti(sledvasht);
            lowLink[vrah] = min(lowLink[vrah], lowLink[sledvasht]);
        }else if(vStekaLiE[sledvasht] == true){
            lowLink[vrah] = min(lowLink[vrah], lowLink[sledvasht]);
        }
    }

    if(dalbochina[vrah] == lowLink[vrah]){
        while(st.top() != vrah){
            int naiOtgore = st.top();
            st.pop();

            vStekaLiE[naiOtgore] = false;
            otKoqKomponentaE[naiOtgore] = nomerche;
        }
        int vrahche = st.top();
        st.top();
        vStekaLiE[vrahche] = false;
        otKoqKomponentaE[vrahche] = nomerche;

        nomerche++;
    }

}

void nuliraneNaKomponenti(){
    fill(vStekaLiE, vStekaLiE + broiVarhove + 1, false);
    fill(otKoqKomponentaE, otKoqKomponentaE + broiVarhove + 1, 0);
    fill(dalbochina, dalbochina + broiVarhove + 1, -1);
    fill(lowLink, lowLink + broiVarhove + 1, -1);
}

int vzemiRCapacitet(int otKoi, int doKoi){
    for(Danni a : sasedstvo[otKoi]){
        if(a.doKoi == doKoi){
            return a.rCapacitet;
        }
    }
    return -35000000;
}

void promeniRCapacitetS(int otKoi, int doKoi, int rCapacitet){
    for(unsigned int a = 0; a < sasedstvo[otKoi].size(); a++){
        if(doKoi == sasedstvo[otKoi][a].doKoi){
            sasedstvo[otKoi][a].rCapacitet += rCapacitet;
            return;
        }
    }
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

        for(Danni k : sasedstvo[vrah]){
            if(k.rCapacitet == 1 && visited[k.doKoi] == false){
                q.push(k.doKoi);
                parents[k.doKoi] = vrah;
                visited[k.doKoi] = true;
            }
        }

    }

    return visited[krai];
}

void inicializirneNaRSasedstvo(){
    for(int h = 1; h <= broiVarhove; h++){
        for(unsigned int i = 0; i < sasedstvo[h].size(); i++){
            sasedstvo[h][i].rCapacitet = sasedstvo[h][i].capacitet;
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

            sasedstvo[otKoi].push_back(zaDob);

            zaDob = {otKoi, 1, 1};

            sasedstvo[doKoi].push_back(zaDob);
        }

        nuliraneNaKomponenti();

        for(int i = 1; i < broiVarhove; i++){
            if(dalbochina[i] == -1){
                pravenennaKomponenti(i);
            }
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

                if(otKoqKomponentaE[a] != otKoqKomponentaE[b]){
                    continue;
                }

                int rezultat = FordFulkersonFLow(a, b);
                if(rezultat >= 3){
                    imaLi = true;
                    cout<<i<<" "<<j<<endl;

                    int br = 0;

                    for(auto s : sasedstvo[a]){
                        if(br >= 3){
                            break;
                        }
                        if(s.rCapacitet == 0 && s.capacitet == 1){
                            int g = s.doKoi;
                            br++;

                            queue<int> q;
                            q.push(a);
                            int segashenVrah = g;
                            while(segashenVrah != b){
                                q.push(segashenVrah);

                                for(auto k : sasedstvo[segashenVrah]){
                                    if(k.rCapacitet ==  0 && k.capacitet == 1){
                                        segashenVrah = k.doKoi;
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
