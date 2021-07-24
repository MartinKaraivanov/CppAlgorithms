#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <stdlib.h>
#include "hunter.cpp"

using namespace std;

void play(int n1, int m1, const vector<vector<char> > &table);

static int n__, m__, succ__=0;
static char t__[128][128];
static bool hasSkipped__ = false;
static int hunteri__ = -1, hunterj__ = -1;

// matching finding
static pair<int, int> neigh__[128][128];
static int d__[128][128];

static bool valid__(int i, int j){
    return i>=0 && i<n__ && j>=0 && j<m__ && t__[i][j]!='#';
}

static int bfs__(){
    queue<pair<int, int> > q__;
    for (int i=0; i<n__; ++i){
        for (int j=0; j<m__; ++j){
            d__[i][j] = 0;
            if ((i+j)&1 && t__[i][j]!='#' && neigh__[i][j].first==-1){
                //cout<<i+j<<endl;
                q__.push(make_pair(i, j));
                d__[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while (!q__.empty()){
        pair<int, int> curr = q__.front();
        q__.pop();
        int i = curr.first, j = curr.second;
        //cout<<"bfs__ "<<i<<" "<<j<<"\n";
        if (d__[i][j] >= ans && ans!=0){return ans;}
        if ((i+j)&1){
            if (valid__(i+1, j) && !d__[i+1][j]){
                d__[i+1][j] = d__[i][j]+1;
                q__.push(make_pair(i+1, j));
            }
            if (valid__(i-1, j) && !d__[i-1][j]){
                d__[i-1][j] = d__[i][j]+1;
                q__.push(make_pair(i-1, j));
            }
            if (valid__(i, j+1) && !d__[i][j+1]){
                d__[i][j+1] = d__[i][j]+1;
                q__.push(make_pair(i, j+1));
            }
            if (valid__(i, j-1) && !d__[i][j-1]){
                d__[i][j-1] = d__[i][j]+1;
                q__.push(make_pair(i, j-1));
            }
        }
        else{
            if (neigh__[i][j].first == -1){ans = d__[i][j]+1;}
            else if (!d__[neigh__[i][j].first][neigh__[i][j].second]){
                d__[neigh__[i][j].first][neigh__[i][j].second] = d__[i][j] + 1;
                q__.push(neigh__[i][j]);
            }
        }
    }
    return ans;
}

static bool used__[128][128];
static bool dfs__(int i, int j){
    //cout<<"dfs__ "<<i<<" "<<j<<"\n";
    used__[i][j] = 1;
    if ((i+j)&1){
        if (neigh__[i][j].first == -1){return true;}
        return dfs__(neigh__[i][j].first, neigh__[i][j].second);
    }else{
        if (valid__(i+1, j) && !used__[i+1][j] && d__[i][j] == d__[i+1][j]+1){
            if (dfs__(i+1, j)){
                neigh__[i][j] = make_pair(i+1, j);
                neigh__[i+1][j] = make_pair(i, j);
                return true;
            }
        }
        if (valid__(i-1, j) && !used__[i-1][j] && d__[i][j] == d__[i-1][j]+1){
            if (dfs__(i-1, j)){
                neigh__[i][j] = make_pair(i-1, j);
                neigh__[i-1][j] = make_pair(i, j);
                return true;
            }
        }
        if (valid__(i, j+1) && !used__[i][j+1] && d__[i][j] == d__[i][j+1]+1){
            if (dfs__(i, j+1)){
                neigh__[i][j] = make_pair(i, j+1);
                neigh__[i][j+1] = make_pair(i, j);
                return true;
            }
        }
        if (valid__(i, j-1) && !used__[i][j-1] && d__[i][j] == d__[i][j-1]+1){
            if (dfs__(i, j-1)){
                neigh__[i][j] = make_pair(i, j-1);
                neigh__[i][j-1] = make_pair(i, j);
                return true;
            }
        }
    }
    return false;
}

bool optimize1__(int i, int j, int pri, int prj, int beg){
    //cout<<"opt "<<i<<" "<<j<<"\n";
    used__[i][j] = 1;
    if (((i+j)&1) != beg){
        //cout<<"b\n";
        if (neigh__[i][j].first == -1){
            //cout<<"a\n";
            neigh__[i][j] = make_pair(pri, prj);
            return true;
        }
        if (used__[neigh__[i][j].first][neigh__[i][j].second]) return false;
        bool ans = optimize1__(neigh__[i][j].first, neigh__[i][j].second, i, j, beg);
        if (ans) neigh__[i][j] = make_pair(pri, prj);
        return ans;
    }
    else{
        if (valid__(i+1, j) && !used__[i+1][j]){
            bool ans = optimize1__(i+1, j, i, j, beg);
            if (ans){neigh__[i][j] = make_pair(i+1, j); return true;}
        }
        if (valid__(i-1, j) && !used__[i-1][j]){
            bool ans = optimize1__(i-1, j, i, j, beg);
            if (ans){neigh__[i][j] = make_pair(i-1, j); return true;}
        }
        if (valid__(i, j+1) && !used__[i][j+1]){
            bool ans = optimize1__(i, j+1, i, j, beg);
            if (ans){neigh__[i][j] = make_pair(i, j+1); return true;}
        }
        if (valid__(i, j-1) && !used__[i][j-1]){
            bool ans = optimize1__(i, j-1, i, j, beg);
            if (ans){neigh__[i][j] = make_pair(i, j-1); return true;}
        }
        return false;
    }
}
// end of matching finding

static bool ontable__(int i, int j){
    return i>=0 && i<n__ && j>=0 && j<m__ && t__[i][j]=='.';
}

static bool mov__(int i, int j){
    if (i==-1 && j==-1 && !hasSkipped__ && hunteri__ == -1 && hunterj__ == -1) {
        hasSkipped__ = 1;
        return true;
    }
    if (hunteri__ == -1 && hunterj__ == -1 && ontable__(i, j)){
        hunteri__ = i;
        hunterj__ = j;
        t__[i][j] = '#';
        return true;
    }
    if (hunteri__!=-1 && ontable__(i, j)){
        if (hunteri__ == i && abs(hunterj__ - j) == 1){
            hunteri__ = i;
            hunterj__ = j;
            t__[i][j] = '#';
            return true;
        }
        if (hunterj__ == j && abs(hunteri__ - i) == 1){
            hunteri__ = i;
            hunterj__ = j;
            t__[i][j] = '#';
            return true;
        }
    }
    return false;
}

void viz__(){
    int v[128][128], num = 1;
    for (int i=0; i<n__; ++i){
        for (int j=0; j<m__; ++j){
            v[i][j] = -2;
        }
    }
    for (int i=0; i<n__; ++i){
        for (int j=0; j<m__; ++j){
            if (v[i][j]>-2){continue;}
            if (t__[i][j]=='#'){
                v[i][j] = -1;
                continue;
            }
            if (neigh__[i][j].first == -1){
                v[i][j] = 0;
                continue;
            }
            v[neigh__[i][j].first][neigh__[i][j].second] = v[i][j] = num++;
        }
    }
    for (int i=0; i<n__; ++i){
        for (int j=0; j<m__; ++j){
            if (v[i][j]==-1){cout<<"# ";}
            else if (v[i][j]==0){cout<<". ";}
            else{cout<<v[i][j]<<" ";}
        }
        cout<<endl;
    }
}
void printTableState__(){
    cout<<"Current table:\n";
    for (int i=0; i<n__; ++i){
        for (int j=0; j<m__; ++j){
            if (i==hunteri__ && j==hunterj__){
                cout<<"*";
            }else{
                cout<<t__[i][j];
            }
        }
        cout<<endl;
    }
}

pair<int, int> makeMove(int i, int j){
    //cout<<i<<" "<<j<<"\n";
    //printTableState__();
    //viz__();
    if (!mov__(i, j)){
        cout<<"0\n";
        exit(0);
    }
    //printTableState__();
    //viz__();
    if (i==-1){
        bool haveMove = 0;
        for (int i=0; i<n__; ++i){
            for (int j=0; j<m__; ++j){
                if (t__[i][j]!='#' && neigh__[i][j].first==-1){
                    cout<<"0\n"; // I can make winning first move to i, j
                    exit(0);
                }
                if (t__[i][j]!='#'){
                    haveMove = 1;
                }
            }
        }
        if (!haveMove){
            succ__ = 1;
            return make_pair(-1, -1); // i have nowhere to move
        }
        int posi, posj;
        do{
            posi = rand()%n__;
            posj = rand()%m__;
        }while(t__[posi][posj]=='#');
        neigh__[neigh__[posi][posj].first][neigh__[posi][posj].second] = make_pair(-1, -1);
        neigh__[posi][posj] = make_pair(-1, -1);
        mov__(posi, posj);
        return make_pair(posi, posj);
    }
    else{
        if (neigh__[i][j].first != -1){
            int posi = neigh__[i][j].first, posj = neigh__[i][j].second;
            neigh__[posi][posj] = make_pair(-1, -1);
            neigh__[i][j] = make_pair(-1, -1);
            for (int i=0; i<n__; ++i){
                for (int j=0; j<m__; ++j){
                    used__[i][j]=0;
                }
            }
            if (!optimize1__(posi, posj, -1, -1, (posi+posj)&1)){
                cout<<"0\n"; //i can make winning move to posi, posj.
                exit(0);
            }
        }
        int numval = 0;
        if (valid__(i-1, j)) ++numval;
        if (valid__(i+1, j)) ++numval;
        if (valid__(i, j-1)) ++numval;
        if (valid__(i, j+1)) ++numval;
        if (numval == 0){
            succ__ = 1;
            return make_pair(-1, -1); //i have nowhere to move
        }
        int posi, posj;
        int myMove = rand()%numval;
        if (valid__(i-1, j)){
            if (myMove == 0){posi = i-1; posj = j;}
            --myMove;
        }
        if (valid__(i+1, j)){
            if (myMove == 0){posi = i+1; posj = j;}
            --myMove;
        }
        if (valid__(i, j-1)){
            if (myMove == 0){posi = i; posj = j-1;}
            --myMove;
        }
        if (valid__(i, j+1)){
            if (myMove == 0){posi = i; posj = j+1;}
            --myMove;
        }
        neigh__[neigh__[posi][posj].first][neigh__[posi][posj].second] = make_pair(-1, -1);
        neigh__[posi][posj] = make_pair(-1, -1);
        mov__(posi, posj);
        return make_pair(posi, posj);
    }
}

static long long calcHash__(int n, int m, const vector<vector<char> > &table){
    long long ans = n*m, mod = 1000000007, a=945741440, b=479699241;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            ans = ( ans*2 + (table[i][j]=='#') )%mod;
        }
    }
    return ((ans * a) + b) % mod + 1;
}

int main(){
    srand(42);
    cin>>n__>>m__;
    for (int i=0; i<n__; ++i){
        cin>>t__[i];
    }
    vector<vector<char> > table;
    table.resize(n__);
    for (int i=0; i<n__; ++i){
        table[i].resize(m__);
        for (int j=0; j<m__; ++j){
            table[i][j] = t__[i][j];
            neigh__[i][j] = make_pair(-1, -1);
        }
    }

    while (int x = bfs__()){
        for (int i=0; i<n__; ++i){
            for (int j=0; j<m__; ++j){
                used__[i][j] = 0;
            }
        }
        for (int i=0; i<n__; ++i){
            for (int j=0; j<m__; ++j){
                if (d__[i][j] == x-1 && neigh__[i][j].first == -1){
                    dfs__(i, j);
                }
            }
        }
        //viz__();
    }
    //cout<<"grader match"<<endl;
    play(n__, m__, table);
    if (succ__){
        cout<<calcHash__(n__, m__, table)<<"\n";
    }else{
        cout<<0<<"\n";
    }
    return 0;
}
