#include<iostream>
#include<vector>
#include<queue>
#include "hunter.h"

using namespace std;

pair<int, int> makeMove(int i, int j);

int broiVarhove;

struct DanniZaSaseda{
    int doKoi;
    int capcitet;
    int rCapacitet;
};

struct Koordinati{
    int x;
    int y;
};

vector<DanniZaSaseda> sasedstvo[10010];

int daiNomerNaVurha(int x, int y, int m, int n){
    return y*m + x;
}

Koordinati kudeENomercheto(int nomerche, int m, int n){
    return {nomerche%m, nomerche/m};
}

bool visited[10010];
int parents[10010];

void nuliraneNaVisited(){
    for(int i = 0; i <= broiVarhove + 1; i++){
        visited[i] = false;
    }
}

bool bfs(int start, int krai){
    nuliraneNaVisited();

    queue<int> q;
    q.push(start);

    parents[start] = -1;
    visited[start] = true;

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        if(naiOtpred == krai){
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred].size(); i++){
            DanniZaSaseda sledvasht = sasedstvo[naiOtpred][i];

            if(sledvasht.rCapacitet > 0 && visited[sledvasht.doKoi] == false){
                q.push(sledvasht.doKoi);
                parents[sledvasht.doKoi] = naiOtpred;
                visited[sledvasht.doKoi] = true;
            }
        }

    }

    return visited[krai];
}

int vzemiRCapacitet(int otKoi, int doKoi){
    for(int i = 0; i < (int)sasedstvo[otKoi].size(); i++){
        if(sasedstvo[otKoi][i].doKoi == doKoi){
            return sasedstvo[otKoi][i].rCapacitet;
        }
    }

    return -30000;
}

void promeniRCapacitetS(int otKoi, int doKoi, int rCapacitet){
    for(int i = 0; i < (int)sasedstvo[otKoi].size(); i++){
        if(sasedstvo[otKoi][i].doKoi == doKoi){
            sasedstvo[otKoi][i].rCapacitet += rCapacitet;
        }
    }
}

void inicializiraneNaRSasedstvoto(){
    for(int i = 0; i <= broiVarhove + 1; i++){
        for(int j = 0; j < (int)sasedstvo[i].size(); j++){
            sasedstvo[i][j].rCapacitet = sasedstvo[i][j].capcitet;
        }
    }
}

int fordFulkerson(int start, int krai){
    int maxFlow = 0;

    inicializiraneNaRSasedstvoto();

    while(true){
        bool stigameLi = bfs(start, krai);

        if(stigameLi == false){
            break;
        }

        int patishtenPotok = 0;

        for(int v = krai; v != -1; v = parents[v]){
            int u = parents[v];
            patishtenPotok = max(patishtenPotok, vzemiRCapacitet(u, v));
        }

        for(int v = krai; v != -1; v = parents[v]){
            int u = parents[v];

            promeniRCapacitetS(u, v, -patishtenPotok);
            promeniRCapacitetS(v, u, patishtenPotok);
        }

        maxFlow += patishtenPotok;
    }

    return maxFlow;
}

int broiKomponenti;
vector<int> koiEVKomponenta[10010];

int otKoqkomponentaE[10010];

void dfs(int x, int y, int m, int n, const vector<vector<char>> &table, int nomercheKomp){
    int tukaNomerche = daiNomerNaVurha(x, y, m, n);

    koiEVKomponenta[nomercheKomp].push_back(tukaNomerche);
    otKoqkomponentaE[tukaNomerche] = nomercheKomp;

    if(x < m - 1 && table[y][x+1] != '#'){
        int drugoNomerche = daiNomerNaVurha(x + 1, y, m, n);

        if(otKoqkomponentaE[drugoNomerche] == 0){
            dfs(x + 1, y, m , n, table, nomercheKomp);
        }
    }

    if(x > 0 && table[y][x - 1] != '#'){
        int drugoNomerche = daiNomerNaVurha(x - 1, y, m, n);

        if(otKoqkomponentaE[drugoNomerche] == 0){
            dfs(x - 1, y, m , n, table, nomercheKomp);
        }
    }

    if(y < n - 1 && table[y + 1][x] != '#'){
        int drugoNomerche = daiNomerNaVurha(x, y + 1, m, n);

        if(otKoqkomponentaE[drugoNomerche] == 0){
            dfs(x, y + 1, m , n, table, nomercheKomp);
        }
    }

    if(y > 0 && table[y - 1][x] != '#'){
        int drugoNomerche = daiNomerNaVurha(x, y - 1, m, n);

        if(otKoqkomponentaE[drugoNomerche] == 0){
            dfs(x, y - 1, m , n, table, nomercheKomp);
        }
    }

}

void napraviSasedstvoto(int n, int m, const vector<vector<char>> &table, int nachalenNomer, int kraenNomer, int vKoiKomponent){
    for(int y = 0; y < n; y++){
        int start = 0;
        if(y % 2 == 0){
            start++;
        }

        for(int x = start; x < m; x += 2){
            if(table[y][x] == '#'){
                continue;
            }

            int tukaNomerche = daiNomerNaVurha(x, y, m, n);

            if(otKoqkomponentaE[tukaNomerche] != vKoiKomponent){
                continue;
            }

            sasedstvo[nachalenNomer].push_back({tukaNomerche, 1, 0});
            sasedstvo[tukaNomerche].push_back({nachalenNomer, 0, 0});
        }
    }

    for(int y = 0; y < n; y++){
        int start = 0;
        if(y % 2 == 0){
            start++;
        }

        for(int x = start; x < m; x += 2){
            if(table[y][x] == '#'){
                continue;
            }

            int tukaNomerce = daiNomerNaVurha(x, y, m, n);

            if(otKoqkomponentaE[tukaNomerce] != vKoiKomponent){
                continue;
            }

            if(x < m - 1 && table[y][x+1] != '#'){
                int drugoNomerche = daiNomerNaVurha(x + 1, y, m, n);

                sasedstvo[tukaNomerce].push_back({drugoNomerche, 1, 0});
                sasedstvo[drugoNomerche].push_back({tukaNomerce, 0, 0});
            }

            if(x > 0 && table[y][x - 1] != '#'){
                int drugoNomerche = daiNomerNaVurha(x - 1, y, m, n);

                sasedstvo[tukaNomerce].push_back({drugoNomerche, 1, 0});
                sasedstvo[drugoNomerche].push_back({tukaNomerce, 0, 0});
            }

            if(y < n - 1 && table[y + 1][x] != '#'){
                int drugoNomerche = daiNomerNaVurha(x, y + 1, m, n);

                sasedstvo[tukaNomerce].push_back({drugoNomerche, 1, 0});
                sasedstvo[drugoNomerche].push_back({tukaNomerce, 0, 0});
            }

            if(y > 0 && table[y - 1][x] != '#'){
                int drugoNomerche = daiNomerNaVurha(x, y - 1, m, n);

                sasedstvo[tukaNomerce].push_back({drugoNomerche, 1, 0});
                sasedstvo[drugoNomerche].push_back({tukaNomerce, 0, 0});
            }
        }
    }

    for(int y = 0; y < n; y++){
        int start = 0;

        if(y%2 == 1){
            start++;
        }

        for(int x = start; x < m; x += 2){
            if(table[y][x] == '#'){
                continue;
            }

            int tukaNomerche = daiNomerNaVurha(x, y, m, n);

            if(otKoqkomponentaE[tukaNomerche] != vKoiKomponent){
                continue;
            }

            sasedstvo[tukaNomerche].push_back({kraenNomer, 1, 0});
            sasedstvo[kraenNomer].push_back({tukaNomerche, 0, 0});
        }
    }
}

bool izpolzvanLiE[110][110];

void play(int n, int m, const vector<vector<char>> &table){
    broiVarhove = m*n;

    int nachalenNomer = broiVarhove;
    int kraenNomer = broiVarhove + 1;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(table[y][x] == '#'){
                izpolzvanLiE[y][x] = true;
            }

            int nomerche = daiNomerNaVurha(x, y, m, n);

            if(otKoqkomponentaE[nomerche] == 0 && table[y][x] == '.'){
                broiKomponenti++;
                dfs(x, y, m, n, table, broiKomponenti);
            }
        }
    }

    int vKoiKomponentPuskame = 0;

    for(int i = 1; i <= broiKomponenti; i++){
        if(koiEVKomponenta[i].size() % 2 == 1){
            vKoiKomponentPuskame = i;
            break;
        }
    }

    if(vKoiKomponentPuskame == 0){
        pair<int, int> segashno = makeMove(-1, -1);

        while(true){
            if(segashno.first == -1 && segashno.second == -1){
                break;
            }

            int x = segashno.second;
            int y = segashno.first;

            izpolzvanLiE[y][x] = true;

            if(x < m - 1 && izpolzvanLiE[y][x + 1] == false){
                segashno = makeMove(y, x + 1);
                izpolzvanLiE[y][x + 1] = true;
            }else{
                if(x > 0 && izpolzvanLiE[y][x - 1] == false){
                    segashno = makeMove(y, x - 1);
                    izpolzvanLiE[y][x - 1] = true;
                }else{
                    if(y < n - 1 && izpolzvanLiE[y + 1][x] == false){
                        segashno = makeMove(y + 1, x);
                        izpolzvanLiE[y + 1][x] = true;
                    }else{
                        if(y > 0 && izpolzvanLiE[y - 1][x] == false){
                            segashno = makeMove(y - 1, x);
                            izpolzvanLiE[y - 1][x] = true;
                        }
                    }
                }
            }
        }

    }else{
        napraviSasedstvoto(n, m, table, nachalenNomer, kraenNomer, vKoiKomponentPuskame);

        int potok = fordFulkerson(nachalenNomer, kraenNomer);

        int toziOtKoitoPochvame = -1;

        for(int i = 0; i < (int)sasedstvo[broiVarhove].size(); i++){
            if(sasedstvo[broiVarhove][i].rCapacitet > 0){
                toziOtKoitoPochvame = sasedstvo[broiVarhove][i].doKoi;
                break;
            }
        }

        if(toziOtKoitoPochvame == -1){
            for(int y = 0; y < n; y++){
                int start = 0;
                if(y%2 == 1){
                    start++;
                }

                for(int x = start; x < m; x+=2){
                    if(table[x][y] == '#'){
                        continue;
                    }

                    int nomercheTuka = daiNomerNaVurha(x, y, m, n);

                    if(sasedstvo[nomercheTuka][0].rCapacitet > 0){
                        toziOtKoitoPochvame = nomercheTuka;
                        break;
                    }
                }

                if(toziOtKoitoPochvame > -1){
                    break;
                }
            }
        }

        Koordinati puskameKoordinati = kudeENomercheto(toziOtKoitoPochvame, m, n);

        //cout<<"pochvame ot "<<toziOtKoitoPochvame<<" s koordinati "<<puskameKoordinati.y<<" "<<puskameKoordinati.x<<endl;

        pair<int, int> segashno = makeMove(puskameKoordinati.y, puskameKoordinati.x);
        izpolzvanLiE[puskameKoordinati.y][puskameKoordinati.x] = true;

        while(true){
            if(segashno.first == -1 && segashno.second == -1){
                break;
            }

            int x = segashno.second;
            int y = segashno.first;

            izpolzvanLiE[y][x] = true;

            if(x < m - 1 && izpolzvanLiE[y][x + 1] == false){
                segashno = makeMove(y, x + 1);
                izpolzvanLiE[y][x + 1] = true;
            }else{
                if(x > 0 && izpolzvanLiE[y][x - 1] == false){
                    segashno = makeMove(y, x - 1);
                    izpolzvanLiE[y][x - 1] = true;
                }else{
                    if(y < n - 1 && izpolzvanLiE[y + 1][x] == false){
                        segashno = makeMove(y + 1, x);
                        izpolzvanLiE[y + 1][x] = true;
                    }else{
                        if(y > 0 && izpolzvanLiE[y - 1][x] == false){
                            segashno = makeMove(y - 1, x);
                            izpolzvanLiE[y - 1][x] = true;
                        }
                    }
                }
            }
        }

    }

}
