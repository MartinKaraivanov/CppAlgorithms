#include<iostream>
#include<queue>
using namespace std;

char park[700][700];
bool mozheLiDaSeMine[700][700];
bool biliLiSmeTam[700][700];
int maxX;
int maxY;


int tochki[700][700];

int kolkoVremeOtnemaNaPoleto(char simvol){
    if(simvol=='A'){
        return 1;
    }
    if(simvol=='B'){
        return 2;
    }
    if(simvol=='C'){
        return 3;
    }
    if(simvol=='D'){
        return 4;
    }
    if(simvol=='E'){
        return 5;
    }
    if(simvol=='F'){
        return 6;
    }
    if(simvol=='G'){
        return 7;
    }
    if(simvol=='H'){
        return 8;
    }
    if(simvol=='I'){
        return 9;
    }
    if(simvol=='J'){
        return 10;
    }
    if(simvol=='K'){
        return 11;
    }
    if(simvol=='L'){
        return 12;
    }
    if(simvol=='M'){
        return 13;
    }
    if(simvol=='N'){
        return 14;
    }
    if(simvol=='O'){
        return 15;
    }
    if(simvol=='P'){
        return 16;
    }
    if(simvol=='Q'){
        return 17;
    }
    if(simvol=='R'){
        return 18;
    }
    if(simvol=='S'){
        return 19;
    }
    if(simvol=='T'){
        return 20;
    }
    if(simvol=='U'){
        return 21;
    }
    if(simvol=='V'){
        return 22;
    }
    if(simvol=='W'){
        return 23;
    }
    if(simvol=='X'){
        return 24;
    }
    if(simvol=='Y'){
        return 25;
    }
    if(simvol=='Z'){
        return 26;
    }
    if(simvol=='*'){
        return -1;
    }
    if(simvol=='#'){
        return 0;
    }
}


void transformers(){
    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            tochki[y][x]=kolkoVremeOtnemaNaPoleto(park[y][x]);
        }
    }
}

struct CoordinatiiHod{
    int y;
    int x;
    int vreme;
    bool operator <(const CoordinatiiHod& b) const {
        return (vreme > b.vreme);
    }
};

long long naiKasPat(int startovX, int startovY){
    int naiKasPat;

    CoordinatiiHod start={startovY, startovX, 0};

    priority_queue<CoordinatiiHod> q;

    q.push(start);

    while(q.empty()==false){
        CoordinatiiHod c=q.top();
        q.pop();

        if((c.y==0) || (c.y==maxY-1) || (c.x==0) || (c.x==maxX-1)){
            naiKasPat=c.vreme;
            break;
        }else{
            if((c.y-1>=0) && (mozheLiDaSeMine[c.y-1][c.x]==true)){
                if(biliLiSmeTam[c.y-1][c.x]==false){
                    CoordinatiiHod c_novo = {c.y-1, c.x, c.vreme+tochki[c.y-1][c.x]};
                    q.push(c_novo);
                    biliLiSmeTam[c.y-1][c.x]=true;
                }
            }
            if((c.y+1<maxY) && (mozheLiDaSeMine[c.y+1][c.x]==true)){
                if(biliLiSmeTam[c.y+1][c.x]==false){
                    CoordinatiiHod c_novo = {c.y+1, c.x, c.vreme+tochki[c.y+1][c.x]};
                    q.push(c_novo);
                    biliLiSmeTam[c.y+1][c.x]=true;
                }
            }
            if((c.x-1>=0) && (mozheLiDaSeMine[c.y][c.x-1]==true)){
                if(biliLiSmeTam[c.y][c.x-1]==false){
                    CoordinatiiHod c_novo = {c.y, c.x-1, c.vreme+tochki[c.y][c.x-1]};
                    q.push(c_novo);
                    biliLiSmeTam[c.y][c.x-1]=true;
                }
            }
            if((c.x+1<maxX) && (mozheLiDaSeMine[c.y][c.x+1]==true)){
                if(biliLiSmeTam[c.y][c.x+1]==false){
                    CoordinatiiHod c_novo = {c.y, c.x+1, c.vreme+tochki[c.y][c.x+1]};
                    q.push(c_novo);
                    biliLiSmeTam[c.y][c.x+1]=true;
                }
            }

        }
    }

    return naiKasPat;
}

int main(){
    int startovX;
    int startovY;

    cin>>maxY>>maxX;

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            cin>>park[y][x];
            if(park[y][x]=='#'){
                startovX=x;
                startovY=y;
            }
        }
    }

    transformers();

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            if((park[y][x]=='*') || (park[y][x]=='#')){
                mozheLiDaSeMine[y][x]=false;
            }else{
                mozheLiDaSeMine[y][x]=true;
            }
        }
    }

    int nKPat=naiKasPat(startovX, startovY);

    cout<<nKPat<<endl;

    return 0;
}
