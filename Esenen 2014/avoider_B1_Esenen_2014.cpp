#include<iostream>
using namespace std;

int otKolkoDalag;
int doKolkoDalag;

bool posetenaLiE[35][35];

long long broiMarshruti;

long long broiZaTakavaDalzhina[] = {0, 1, 2, 5, 12, 30, 73, 183, 456, 1151, 2900, 7361, 18684, 47652, 121584, 311259, 797311,
 2047384, 5260692, 13542718, 34884239, 89991344, 232282110, 600281932, 1552096361, 4017128206, 10401997092, 26957667445,
 69892976538};

void izchislqvane(int dalzhinaDosega, int x, int y){
    //cout<<dalzhinaDosega<<" "<<x<<" "<<y<<endl;
    if(dalzhinaDosega >= otKolkoDalag && dalzhinaDosega <= doKolkoDalag){
        broiMarshruti++;
        //cout<<"Tuk dobavih"<<endl;
        if(dalzhinaDosega == doKolkoDalag){
            return ;
        }
    }

    if(posetenaLiE[x + 1][y] == false){
        posetenaLiE[x + 1][y] = true;
        izchislqvane(dalzhinaDosega + 1, x + 1, y);
        posetenaLiE[x + 1][y] = false;
    }

    if(posetenaLiE[x][y + 1] == false){
        posetenaLiE[x][y + 1] = true;
        izchislqvane(dalzhinaDosega + 1, x, y + 1);
        posetenaLiE[x][y + 1] = false;
    }

    if(x > 0 && posetenaLiE[x - 1][y] == false){
        posetenaLiE[x - 1][y] = true;
        izchislqvane(dalzhinaDosega + 1, x - 1, y);
        posetenaLiE[x - 1][y] = false;
    }

    if(y > 0 && posetenaLiE[x][y - 1] == false){
        posetenaLiE[x][y - 1] = true;
        izchislqvane(dalzhinaDosega + 1, x, y - 1);
        posetenaLiE[x][y - 1] = false;
    }

}

int main(){
    cin>>otKolkoDalag>>doKolkoDalag;

    /*posetenaLiE[0][0] = true;
    posetenaLiE[1][0] = true;
    izchislqvane(1, 1, 0);*/

    for(int i = otKolkoDalag; i <= doKolkoDalag; i++){
        broiMarshruti += broiZaTakavaDalzhina[i];
    }

    cout<<broiMarshruti<<endl;

    return 0;
}
