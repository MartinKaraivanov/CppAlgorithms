#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int broiVarhove;
vector<int> sasedstvo[55];

bool toziliNeMozhemDaGoVzimame[55];

bool bfs(){
    bool visited[55];

    for(int i = 0; i < broiVarhove; i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(q.empty() == false){
        int vrah = q.front();
        q.pop();

        if(vrah == broiVarhove - 1){
            break;
        }

        if(toziliNeMozhemDaGoVzimame[vrah] == true){
            continue;
        }

        for(unsigned int i = 0; i < sasedstvo[vrah].size(); i++){
            if(visited[sasedstvo[vrah][i]] == false){
                q.push(sasedstvo[vrah][i]);
                visited[sasedstvo[vrah][i]] = true;
            }
        }

    }

    return visited[broiVarhove - 1];
}

vector<int> neizbezhni;

int main(){
    int chislo;

    while(cin>>chislo){
        if(chislo == -1){
            broiVarhove++;
            break;
        }
        sasedstvo[broiVarhove].push_back(chislo);
        int vrahDoKoitoHodi;
        while(cin>>vrahDoKoitoHodi){
            if(vrahDoKoitoHodi == -2){
                break;
            }
            sasedstvo[broiVarhove].push_back(vrahDoKoitoHodi);
        }
        broiVarhove++;
    }

    for(int i = 1; i < broiVarhove; i++){
        toziliNeMozhemDaGoVzimame[i] = true;

        bool stigameLi = bfs();

        if(stigameLi == false){
            neizbezhni.push_back(i);
        }

        toziliNeMozhemDaGoVzimame[i] = false;
    }

    cout<<neizbezhni.size()<<" ";

    for(unsigned int i = 0; i < neizbezhni.size(); i++){
        cout<<neizbezhni[i]<<" ";
    }

    cout<<endl;

    return 0;
}
