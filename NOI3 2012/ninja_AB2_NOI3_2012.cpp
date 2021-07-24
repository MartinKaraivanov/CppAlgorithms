#include<iostream>
using namespace std;

short maxRazmer;

bool tekushtaKletkaPriNechetnaSekundaSvetnataLiE;

short priTolkova[1505];

/*short zaKolkoSekundiShteStinemDoKraq(short x, short y){
    if(x == 0 && y == 0){
        return 1;
    }

    if(priTolkova[x][y] > 0){
        return priTolkova[x][y];
    }

    short nalqvo = 10000000;
    if(x > 0){
        nalqvo = 1 + zaKolkoSekundiShteStinemDoKraq(x - 1, y);
    }
    short nagore = 10000000;
    if(y > 0){
        nagore = 1 + zaKolkoSekundiShteStinemDoKraq(x, y - 1);
    }

    short naiMalkoVreme = min(nalqvo, nagore);

    if((!priNechetnaSekundaSvetnatoLiE[y][x] && naiMalkoVreme%2 == 0) ||
        (priNechetnaSekundaSvetnatoLiE[y][x] && naiMalkoVreme % 2 == 1))
    {
        naiMalkoVreme++;
    }

    priTolkova[x][y] = naiMalkoVreme;
    return naiMalkoVreme;
}*/

void sCycli(){
    priTolkova[0] = 1;

    for(short y = 0; y < maxRazmer; y++){
        for(short x = 0; x < maxRazmer; x++){
            short sastoqnie;
            cin>>sastoqnie;

            if(sastoqnie == 1){
                tekushtaKletkaPriNechetnaSekundaSvetnataLiE = true;
            }else{
                tekushtaKletkaPriNechetnaSekundaSvetnataLiE = false;
            }

            if(x == 0 && y == 0){
                continue;
            }

            short nalqvo = 32000;
            if(x > 0){
                nalqvo = 1 + priTolkova[x - 1];
            }

            short nagore = 32000;
            if(y > 0){
                nagore = 1 + priTolkova[x];
            }

            short naiMalkoVreme = min(nalqvo, nagore);

            if((!tekushtaKletkaPriNechetnaSekundaSvetnataLiE && (naiMalkoVreme % 2) == 0) ||
                (tekushtaKletkaPriNechetnaSekundaSvetnataLiE && (naiMalkoVreme % 2) == 1))
            {
                naiMalkoVreme++;
            }

            priTolkova[x] = naiMalkoVreme;

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>maxRazmer;

    sCycli();

    short neobhodimoVremeAkoEnechetno = priTolkova[maxRazmer - 1];
    if(tekushtaKletkaPriNechetnaSekundaSvetnataLiE == true){
        neobhodimoVremeAkoEnechetno++;
    }
    short neobhodimoVremeAkoEChetno = priTolkova[maxRazmer - 1];
    if(tekushtaKletkaPriNechetnaSekundaSvetnataLiE == false){
        neobhodimoVremeAkoEChetno++;
    }

    short neobhodimoVreme = min(neobhodimoVremeAkoEChetno, neobhodimoVremeAkoEnechetno);

    cout<<neobhodimoVreme<<endl;

    return 0;
}
