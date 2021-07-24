#include<iostream>
using namespace std;

char kubche[80][80][80];
int snimkiBroeve[100];

int main(){
    int broiKubchetaRazmeri;

    cin>>broiKubchetaRazmeri;

    for(int y=0;y<broiKubchetaRazmeri;y++){
        int z=0;

        for(int xche=0;xche<broiKubchetaRazmeri*broiKubchetaRazmeri+broiKubchetaRazmeri-1;xche++){
            char bukvichka;
            cin>>bukvichka;

            if(bukvichka!='|'){
                int x=xche;

                if(x>broiKubchetaRazmeri){
                    while(x>broiKubchetaRazmeri){
                        x-=broiKubchetaRazmeri+1;
                    }
                }

                kubche[x][y][z]=bukvichka;
            }else{
                z++;
            }
        }
    }

    if(broiKubchetaRazmeri<3){
        cout<<0<<endl;
        return 0;
    }

    /*for(int z=0;z<broiKubchetaRazmeri;z++){
        for(int y=0;y<broiKubchetaRazmeri;y++){
            for(int x=0;x<broiKubchetaRazmeri;x++){
                cout<<kubche[x][y][z]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }*/

    string zvezdichkiVKubcheto;

    int broiZvezdichki=0;

    for(int z=1;z<broiKubchetaRazmeri-1;z++){
        for(int y=1;y<broiKubchetaRazmeri-1;y++){
            for(int x=1;x<broiKubchetaRazmeri-1;x++){
                if((kubche[x][y][z]==kubche[x+1][y][z]) &&
                   (kubche[x][y][z]==kubche[x-1][y][z]) &&
                   (kubche[x][y][z]==kubche[x][y+1][z]) &&
                   (kubche[x][y][z]==kubche[x][y-1][z]) &&
                   (kubche[x][y][z]==kubche[x][y][z+1]) &&
                   (kubche[x][y][z]==kubche[x][y][z-1]))
                {
                    snimkiBroeve[kubche[x][y][z]]++;
                    zvezdichkiVKubcheto+=kubche[x][y][z];
                    broiZvezdichki++;
                }
            }
        }
    }

    cout<<broiZvezdichki<<endl;

    for(int i=90;i<130;i++){
        if(snimkiBroeve[i]>0){
            char b=i;
            cout<<b<<" -> "<<snimkiBroeve[i]<<endl;
        }
    }

    return 0;
}
