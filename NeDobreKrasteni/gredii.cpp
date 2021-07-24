#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int n;
int m;

long long visochini[1001][1001];
long long cvetove[1001][1001];

void OcvetiSRekursia(int i, int j, int cvqt) {
    // backtracking
    if (cvetove[i][j] == cvqt){
        return;
    } else {
        if (cvetove[i][j] != 0){
            cout<<"imame greshka. tova ne trqba da e razichno ot nula";
        } else{
            cvetove[i][j] = cvqt;

            if((i>0)&&(visochini[i-1][j]==visochini[i][j]) ){
                OcvetiSRekursia(i-1, j, cvqt);
            }
            if( (i+1<n) && (visochini[i+1][j]==visochini[i][j]) ){
                OcvetiSRekursia(i+1, j, cvqt);
            }
            if((j>0)&& (visochini[i][j-1]==visochini[i][j]) ){
                OcvetiSRekursia(i, j-1, cvqt);
            }
            if( (j+1<m) && (visochini[i][j+1]==visochini[i][j]) ){
                OcvetiSRekursia(i, j+1, cvqt);
            }
        }
    }
}


struct Coordinati {
    int i;
    int j;
};


void OcvetiSasStack(int i_nachalno, int j_nachalno, int cvqt) {
    // obhojdane v dalbochina
    stack<Coordinati> s;

    Coordinati nachalniCoordinati = {i_nachalno, j_nachalno};
    s.push(nachalniCoordinati);

    while (!s.empty()){
        Coordinati c = s.top();
        s.pop();

        if (cvetove[c.i][c.j] == 0) {
            cvetove[c.i][c.j] = cvqt;

            if((c.i>0)&&(visochini[c.i-1][c.j]==visochini[c.i][c.j])){
                Coordinati c_novo = {c.i-1, c.j};
                s.push(c_novo);
            }
            if( (c.i+1<n) && (visochini[c.i+1][c.j]==visochini[c.i][c.j]) ){
                Coordinati c_novo = {c.i+1, c.j};
                s.push(c_novo);
            }
            if((c.j>0)&& (visochini[c.i][c.j-1]==visochini[c.i][c.j]) ){
                Coordinati c_novo = {c.i, c.j-1};
                s.push(c_novo);
            }
            if( (c.j+1<m) && (visochini[c.i][c.j+1]==visochini[c.i][c.j]) ){
                Coordinati c_novo = {c.i, c.j+1};
                s.push(c_novo);
            }
        }
    }
}


void OcvetiSOpshka(int i_nachalno, int j_nachalno, int cvqt) {
    // obhojdane v shirina
    queue<Coordinati> q;

    Coordinati nachalniCoordinati = {i_nachalno, j_nachalno};
    q.push(nachalniCoordinati);

    while (!q.empty()){
        Coordinati c = q.front();
        q.pop();

        if (cvetove[c.i][c.j] == 0) {
            cvetove[c.i][c.j] = cvqt;

            if((c.i>0)&&(visochini[c.i-1][c.j]==visochini[c.i][c.j])){
                Coordinati c_novo = {c.i-1, c.j};
                q.push(c_novo);
            }
            if( (c.i+1<n) && (visochini[c.i+1][c.j]==visochini[c.i][c.j]) ){
                Coordinati c_novo = {c.i+1, c.j};
                q.push(c_novo);
            }
            if((c.j>0)&& (visochini[c.i][c.j-1]==visochini[c.i][c.j]) ){
                Coordinati c_novo = {c.i, c.j-1};
                q.push(c_novo);
            }
            if( (c.j+1<m) && (visochini[c.i][c.j+1]==visochini[c.i][c.j]) ){
                Coordinati c_novo = {c.i, c.j+1};
                q.push(c_novo);
            }
        }
    }
}


int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>visochini[i][j];
        }
    }

    long long brCvetove=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( cvetove[i][j]==0){
                brCvetove++;
                OcvetiSOpshka(i, j, brCvetove);
            }
        }
    }

    cout<<brCvetove;

    return 0;
}
