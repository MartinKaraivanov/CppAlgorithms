#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int broiGradove;

vector<int> sasedstvo[200010];

int parvoSelo;
int vtoroSelo;

int naKoiHod[200010];

int bfs(int start, int krai, int parents[200010]){
    for(int i = 0; i < 200010; i++){
        naKoiHod[i] = -1;
    }

    queue<int> q;
    q.push(start);
    naKoiHod[start] = 0;
    parents[start] = -1;

    while(q.empty() == false){
        int selo = q.front();
        q.pop();

        if(selo == krai){
            break;
        }

        for(unsigned int i = 0; i < sasedstvo[selo].size(); i++){
            if(naKoiHod[sasedstvo[selo][i]] == -1 && sasedstvo[selo][i] != start){
                q.push(sasedstvo[selo][i]);
                naKoiHod[sasedstvo[selo][i]] = naKoiHod[selo] + 1;
                parents[sasedstvo[selo][i]] = selo;
            }
        }
    }

    return naKoiHod[krai];
}

bool imaLiHubavPat(int start, int distanciq, bool visited[200010]){
    for(int i = 0; i < 200010; i++){
        naKoiHod[i] = 0;
    }

    queue<int> q;

    q.push(start);
    naKoiHod[start] = 0;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        if(visited[vrah] == true){
            continue;
        }

        if(naKoiHod[vrah] + 1 == distanciq){
            return true;
        }

        for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
            if(naKoiHod[sasedstvo[vrah][i]] == 0 && sasedstvo[vrah][i] != start){
                q.push(sasedstvo[vrah][i]);
                naKoiHod[sasedstvo[vrah][i]] = naKoiHod[vrah] + 1;
            }
        }
    }

    return false;
}

void nulirvane(bool visited[200010]){
    for(int i = 0; i < 200010; i++){
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove;

    for(int i = 0; i < broiGradove - 1; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;
        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    cin>>parvoSelo>>vtoroSelo;

    int naiDalagPat = 1;

    for(int i = 1; i <= broiGradove; i++){
        if(i == parvoSelo){
            continue;
        }
        int parentsParvoSelo[200010];
        int dalzhinaNaPatq = bfs(parvoSelo, i, parentsParvoSelo) + 1;
        bool visited[200010];
        nulirvane(visited);

        for(int v = i; v != -1; v = parentsParvoSelo[v]){
            visited[v] = true;
        }

        bool imaLiTakavaDalzhinka = imaLiHubavPat(vtoroSelo, dalzhinaNaPatq, visited);

        if(imaLiTakavaDalzhinka == true){
            naiDalagPat = max(naiDalagPat, dalzhinaNaPatq);
        }

        /*for(int j = 1; j <= broiGradove; j++){
            if(j == vtoroSelo){
                continue;
            }
            int parentsVtoroSelo[200010];
            int dalzhinaNaVtoriqPat = bfs(vtoroSelo, j, parentsVtoroSelo) + 1;

            if(dalzhinaNaVtoriqPat != dalzhinaNaPatq){
                continue;
            }

            bool zasichatLiSe = false;

            //cout<<vtoroSelo<<" "<<j<<endl;
            for(int v = j; v != -1; v = parentsVtoroSelo[v]){
                if(visited[v] == true){
                    zasichatLiSe = true;
                    break;
                }
                //cout<<v<<" ";
            }

            //cout<<endl;

            if(!zasichatLiSe){
                naiDalagPat = max(naiDalagPat ,dalzhinaNaPatq);
            }

        }*/
    }

    cout<<naiDalagPat<<endl;

    return 0;
}
