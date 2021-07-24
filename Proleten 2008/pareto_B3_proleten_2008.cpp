#include<iostream>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

int broiTochki;

DanniZaTochka tochki[500010];

bool taziOptimalnaLiE[500010];

bool taziPoDobrLiEOtDrugata(int parva, int vtora){
    if(tochki[parva].x >= tochki[vtora].x && tochki[parva].y >= tochki[vtora].y){
        return true;
    }else{
        return false;
    }
}

bool poGolqmoLiE(DanniZaTochka a, DanniZaTochka b){
    /*if(a.x > b.x){
        return true;
    }
    if(a.x < b.x){
        return false;
    }
    return a.y > b.y;*/
    return a.x + a.y > b.x + b.y;
}

int main(){
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        int x;
        int y;
        cin>>x>>y;
        tochki[i] = {x, y};
    }

    sort(tochki, tochki + broiTochki, poGolqmoLiE);

    int broiOptimalni = 0;
    int broiSuboptimalni = 0;

    int kadeEParviqtNeoptimalen = 0;

    for(int i = 0; i < broiTochki; i++){
        bool optimalnaLiE = true;
        for(int j = 0; j < i; j++){
            if(taziPoDobrLiEOtDrugata(j, i) == true){
                optimalnaLiE = false;
                break;
            }
        }

        if(optimalnaLiE == true){
            broiOptimalni++;
            taziOptimalnaLiE[i] = true;
        }else{
            kadeEParviqtNeoptimalen = i;
            break;
        }
    }

    for(int i = kadeEParviqtNeoptimalen; i < broiTochki; i++){
        bool suboptimalenliE = true;
        for(int j = kadeEParviqtNeoptimalen; j < i; j++){
            if(taziPoDobrLiEOtDrugata(j, i) == true){
                suboptimalenliE = false;
                break;
            }
        }

        if(suboptimalenliE == true){
            broiSuboptimalni++;
        }else{
            break;
        }

    }

    cout<<broiOptimalni<<" "<<broiSuboptimalni<<endl;

    return 0;
}
