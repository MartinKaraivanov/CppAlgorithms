#include<iostream>
#include<queue>
#include<cmath>
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

    long long sbor=0;

    int robotenX=otNomerKamKoordinati(r).x;
    int robotenY=otNomerKamKoordinati(r).y;

    for(int y=1;y<=maxY;y++){
        for(int x=1;x<=maxX;x++){
            int dx=abs(x-robotenX);
            int dy=abs(y-robotenY);
            int p=dy+dx;
            if((p<=k) && (p%2 == k%2)){
                sbor+=otKoordinatiKamNomer(y,x);
            }
        }
    }


    cout<<sbor<<endl;

    return 0;
}
