#include<iostream>
#include<queue>
using namespace std;

int pole[150][150];
int stignaliLiSmeKletkata[150][150]; //0-ne sme stignali; 1-s bomba sme stignali; 2-bez bomba sme stignli;

int maxY;
int maxX;

struct CoordinatiiHod{
    int y;
    int x;
    int hod;
    int Bombaaa; //0-nishto; 1-postavena;2-garmi; 3- veche e izpolzvana;
};


int main(){
    char simvol;
    cin>>maxY>>maxX;

    int nachalenX;
    int nachalenY;
    int kraenX;
    int kraenY;

    for(int y=1;y<=maxY;y++){
        for(int x=1;x<=maxX;x++){
            cin>>simvol;
            if(simvol=='B'){
                nachalenY=y;
                nachalenX=x;
            }else{
                if(simvol=='#'){
                    pole[y][x]=-1;
                }else{
                    if(simvol=='E'){
                        kraenY=y;
                        kraenX=x;
                    }
                }
            }
        }
    }


    queue<CoordinatiiHod> q;

    CoordinatiiHod nachalo = {nachalenY,nachalenX,0,0};
    q.push(nachalo);

    int daljina=-1;

    while(q.empty()==false){
        CoordinatiiHod c=q.front();
        q.pop();

        if(c.y==kraenY && c.x==kraenX){
            daljina=c.hod;
            break;
        }

        if(stignaliLiSmeKletkata[c.y][c.x]==2){
            continue;
        }

        if((stignaliLiSmeKletkata[c.y][c.x]==1) && (c.Bombaaa>0)){
            continue;
        }

        if ((c.Bombaaa == 1) || (c.Bombaaa == 2)){
            CoordinatiiHod c_novo={c.y,c.x,c.hod+1,c.Bombaaa+1};
            q.push(c_novo);
        }else{

            if(c.Bombaaa==0){
                stignaliLiSmeKletkata[c.y][c.x]=2;
            }else{
                stignaliLiSmeKletkata[c.y][c.x]=1;
            }

            if((c.y<maxY) && (pole[c.y+1][c.x]==0)){
                CoordinatiiHod c_novo={c.y+1,c.x,c.hod+1,c.Bombaaa};
                q.push(c_novo);
            }

            if((c.y>1) && (pole[c.y-1][c.x]==0)){
                CoordinatiiHod c_novo={c.y-1,c.x,c.hod+1,c.Bombaaa};
                q.push(c_novo);
            }

            if((c.x<maxX) && (pole[c.y][c.x+1]==0)){
                CoordinatiiHod c_novo={c.y,c.x+1,c.hod+1,c.Bombaaa};
                q.push(c_novo);
            }

            if((c.x>1) && (pole[c.y][c.x-1]==0)){
                CoordinatiiHod c_novo={c.y,c.x-1,c.hod+1,c.Bombaaa};
                q.push(c_novo);
            }

            if (c.Bombaaa==0){
                if((c.y<maxY) && (pole[c.y+1][c.x]==-1)){
                    CoordinatiiHod c_novo={c.y+1,c.x,c.hod+1,1};
                    q.push(c_novo);
                }

                if((c.y>1) && (pole[c.y-1][c.x]==-1)){
                    CoordinatiiHod c_novo={c.y-1,c.x,c.hod+1,1};
                    q.push(c_novo);
                }

                if((c.x<maxX) && (pole[c.y][c.x+1]==-1)){
                    CoordinatiiHod c_novo={c.y,c.x+1,c.hod+1,1};
                    q.push(c_novo);
                }

                if((c.x>1) && (pole[c.y][c.x-1]==-1)){
                    CoordinatiiHod c_novo={c.y,c.x-1,c.hod+1,1};
                    q.push(c_novo);
                }
            }
        }
    }



    cout<<daljina<<endl;


    return 0;
}
