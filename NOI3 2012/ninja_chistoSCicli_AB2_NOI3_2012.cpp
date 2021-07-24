#include<iostream>
using namespace std;

int maxRazmer;

bool priNechetnaSekundaSvetnatoLiE[1505][1505];

int priTolkova[1505][1505];

int zaKolkoSekundiShteStinemDoKraq(int x, int y){
    if(x == 0 && y == 0){
        return 1;
    }

    if(priTolkova[x][y] > 0){
        return priTolkova[x][y];
    }

    int nalqvo = 10000000;
    if(x > 0){
        nalqvo = 1 + zaKolkoSekundiShteStinemDoKraq(x - 1, y);
    }
    int nagore = 10000000;
    if(y > 0){
        nagore = 1 + zaKolkoSekundiShteStinemDoKraq(x, y - 1);
    }

    int naiMalkoVreme = min(nalqvo, nagore);

    if((!priNechetnaSekundaSvetnatoLiE[y][x] && naiMalkoVreme%2 == 0) ||
        (priNechetnaSekundaSvetnatoLiE[y][x] && naiMalkoVreme % 2 == 1))
    {
        naiMalkoVreme++;
    }

    priTolkova[x][y] = naiMalkoVreme;
    return naiMalkoVreme;
}

void sCycli(){
    priTolkova[0][0] = 1;

    for(int x = 0; x < maxRazmer; x++){
        for(int y = 0; y < maxRazmer; y++){
            if(x == 0 && y == 0){
                continue;
            }

            int nalqvo = 10000000;
            if(x > 0){
                nalqvo = 1 + priTolkova[x - 1][y];
            }
            int nagore = 10000000;
            if(y > 0){
                nagore = 1 + priTolkova[x][y - 1];
            }

            int naiMalkoVreme = min(nalqvo, nagore);

            if((!priNechetnaSekundaSvetnatoLiE[y][x] && naiMalkoVreme%2 == 0) ||
                (priNechetnaSekundaSvetnatoLiE[y][x] && naiMalkoVreme % 2 == 1))
            {
                naiMalkoVreme++;
            }

            priTolkova[x][y] = naiMalkoVreme;

        }
    }

}

int main(){
    cin>>maxRazmer;

    for(int y = 0; y < maxRazmer; y++){
        for(int x = 0; x < maxRazmer; x++){
            int sastoqnie;
            cin>>sastoqnie;
            if(sastoqnie == 1){
                priNechetnaSekundaSvetnatoLiE[y][x] = true;
            }else{
                priNechetnaSekundaSvetnatoLiE[y][x] = false;
            }
        }
    }

    sCycli();

    int neobhodimoVremeAkoEnechetno = priTolkova[maxRazmer - 1][maxRazmer - 1];
    if(priNechetnaSekundaSvetnatoLiE[maxRazmer - 1][maxRazmer - 1] == true){
        neobhodimoVremeAkoEnechetno++;
    }
    int neobhodimoVremeAkoEChetno = priTolkova[maxRazmer - 1][maxRazmer - 1];
    if(priNechetnaSekundaSvetnatoLiE[maxRazmer - 1][maxRazmer - 1] == false){
        neobhodimoVremeAkoEChetno++;
    }

    int neobhodimoVreme = min(neobhodimoVremeAkoEChetno, neobhodimoVremeAkoEnechetno);

    cout<<neobhodimoVreme<<endl;

    return 0;
}
