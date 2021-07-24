#include<iostream>
using namespace std;
int main(){
    int maxX;
    int maxY;
    cin>>maxX>>maxY;

    bool pole[maxY][maxX];

    for(int y=0;y<maxY;y++){
        for(int x=0;x<maxX;x++){
            pole[y][x]=false;
        }
    }

    int broiListcheta;
    cin>>broiListcheta;

    int minimalniXove[broiListcheta];
    int maximalniYci[broiListcheta];
    int shirochini[broiListcheta];
    int visochini[broiListcheta];

    for(int i=0;i<broiListcheta;i++){
        cin>>minimalniXove[i]>>maximalniYci[i]>>shirochini[i]>>visochini[i];
    }
    for(int i=0;i<broiListcheta;i++){
        for(int y=maximalniYci[i];y<maximalniYci[i]+visochini[i];y++){
            for(int x=minimalniXove[i];x<minimalniXove[i]+shirochini[i];x++){
                pole[y][x]=true;
            }
        }
    }

    int novaShirochina;
    int novaVisochina;
    cin>>novaShirochina>>novaVisochina;

    int broiNachini=0;
    for(int y=0;y<maxY-novaVisochina+1;y++){
        for(int x=0;x<maxX-novaShirochina+1;x++){
            bool mozheLi=true;

            for(int yDve=y;yDve<=y+novaVisochina-1;yDve++){
                for(int xDve=x;xDve<=x+novaShirochina-1;xDve++){
                    if(pole[yDve][xDve]==true){
                        mozheLi=false;
                        break;
                    }
                }
                if(mozheLi==false){
                    break;
                }
            }

            if(mozheLi==true){
                broiNachini++;
            }
        }
    }

    cout<<broiNachini<<endl;


    return 0;
}
