#include <iostream>
#include <cmath>
#include <vector>
#include "hunter.cpp"
using namespace std;

void play(int n, int m, const vector<vector<char> > &table);

static int n__, m__;
static char t__[128][128];
static bool hasSkipped__ = false;
static int hunteri__ = -1, hunterj__ = -1;

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

void printTableState(){
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
    cout<<"move to ("<<i<<", "<<j<<")\n";
    if (!mov__(i, j)){
        cout<<"Your code made an invalid move.\n";
        return make_pair(-1, -1);
    }
    if (!ontable__(hunteri__-1, hunterj__) && !ontable__(hunteri__+1, hunterj__) && !ontable__(hunteri__, hunterj__-1) && !ontable__(hunteri__, hunterj__+1)){
        cout<<"You can't make a valid move so your code wins.\n";
        return make_pair(-1, -1);
    }
    printTableState();
    int posi, posj;
    cout<<"Enter coordinates of your move:\n";
    cin>>posi>>posj;
    while(!mov__(posi, posj)){
        cout<<"Your move was invalid... Try again:\n";
        cin>>posi>>posj;
    }
    return make_pair(posi, posj);
}

int main(){
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
        }
    }
    play(n__, m__, table);
    return 0;
}
