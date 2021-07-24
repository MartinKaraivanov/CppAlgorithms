#include<iostream>
using namespace std;

int pole[3002][3002];

int main(){
    int maxY;
    int maxX;
    cin>>maxX>>maxY;

    for(int y=0;y<=maxY+1;y++){
        for(int x=0;x<=maxX+1;x++){
            if((y==0) || (x==0) || (y==maxY+1) || (x==maxX+1)){
                pole[y][x]=-1;
            }
        }
    }

    int broiVirusi;
    cin>>broiVirusi;

    for(int i=0;i<broiVirusi;i++){
        int x, y;
        cin>>x>>y;
        pole[y][x]=1;
    }

    bool zaraziliLiSme=true;
    int nomerche=1;

    while(zaraziliLiSme==true){
        zaraziliLiSme=false;
        for(int y=1;y<=maxY;y++){
            for(int x=1;x<=maxX;x++){
                if(pole[y][x]==nomerche){
                    if(pole[y][x+1]==0){
                        pole[y][x+1]=nomerche+1;
                        zaraziliLiSme=true;
                    }
                    if(pole[y+1][x]==0){
                        pole[y+1][x]=nomerche+1;
                        zaraziliLiSme=true;
                    }
                    if(pole[y][x-1]==0){
                        pole[y][x-1]=nomerche+1;
                        zaraziliLiSme=true;
                    }
                    if(pole[y-1][x]==0){
                        pole[y-1][x]=nomerche+1;
                        zaraziliLiSme=true;
                    }
                }
            }
        }
        nomerche++;
    }

    cout<<nomerche-2<<endl;

    return 0;
}
