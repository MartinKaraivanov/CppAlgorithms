#include<iostream>
#include<queue>
using namespace std;

bool dostignatoaKhoda[150][150];

int maxY;
int maxX;


struct CoordinatiiHod{
    int y;
    int x;
    int hod;
};

CoordinatiiHod otNomerKamKoordinati(int nomer){
    CoordinatiiHod result = { ((nomer - 1) / maxX) + 1 , ((nomer - 1) % maxX) + 1, 0};
    return result;
}

int otKoordinatiKamNomer(int y, int x){
    return (y-1)*maxX + x;
}

int main(){
    int r;
    int k;
    cin>>maxY>>maxX>>r>>k;

    queue<CoordinatiiHod> q;


    q.push(otNomerKamKoordinati(r));

    long long sbor=0;

    while(q.empty()==false){
        CoordinatiiHod c=q.front();
        q.pop();
        if(c.hod==k){
            if(dostignatoaKhoda[c.y][c.x]==false){
                dostignatoaKhoda[c.y][c.x]=true;
                sbor+=otKoordinatiKamNomer(c.y,c.x);
            }

        }else{
            if(c.hod<k){
                if(c.y<maxY){
                    CoordinatiiHod c_novo={c.y+1,c.x,c.hod+1};
                    q.push(c_novo);
                }

                if(c.y>1){
                    CoordinatiiHod c_novo={c.y-1,c.x,c.hod+1};
                    q.push(c_novo);
                }

                if(c.x<maxX){
                    CoordinatiiHod c_novo={c.y,c.x+1,c.hod+1};
                    q.push(c_novo);
                }

                if(c.x>1){
                    CoordinatiiHod c_novo={c.y,c.x-1,c.hod+1};
                    q.push(c_novo);
                }
            }
        }
    }

    cout<<sbor<<endl;

    return 0;
}
