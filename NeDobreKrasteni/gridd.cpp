#include<iostream>
#include<queue>
using namespace std;

int maxX;
int maxY;

int pole[1001][1001];
int cvetove[1001][1001];

struct Coordinati {
    int y;
    int x;
};

void OcvetiSOpshka(int y_nachalno, int x_nachalno, int cvqt) {
    // obhojdane v shirina
    queue<Coordinati> q;

    Coordinati nachalniCoordinati = {y_nachalno, x_nachalno};
    q.push(nachalniCoordinati);

    while (!q.empty()){
        Coordinati c = q.front();
        q.pop();

        if ((cvetove[c.y][c.x] == 0) && (pole[c.y][c.x] == 0)){
            cvetove[c.y][c.x] = cvqt;

            if(c.y>0){
                Coordinati c_novo = {c.y-1, c.x};
                q.push(c_novo);
            }
            if(c.y+1<maxY){
                Coordinati c_novo = {c.y+1, c.x};
                q.push(c_novo);
            }
            if(c.x>0){
                Coordinati c_novo = {c.y, c.x-1};
                q.push(c_novo);
            }
            if(c.x+1<maxX){
                Coordinati c_novo = {c.y, c.x+1};
                q.push(c_novo);
            }
        }
    }
}


int main(){
    cin>>maxY>>maxX;

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            cin>>pole[y][x];
        }
    }

    int broiCvetove=0;

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            if((cvetove[y][x]==0) && (pole[y][x]==0)){
                broiCvetove++;
                OcvetiSOpshka(y,x,broiCvetove);
            }
        }
    }

    cout<<broiCvetove<<endl;



    return 0;
}
