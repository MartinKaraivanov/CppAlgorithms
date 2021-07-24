#include<iostream>
#include<map>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaPravoagalnika{
    DanniZaTochka goreVlqvo;
    DanniZaTochka doluVdqsno;
};

int broiPravoagalnici;

bool tukImaLi[20010][20010];

int pravene(int minimalenX, int minimalenY, int maximalenX, int maximalenY){
    int lichice = 0;

    for(int y = minimalenY + 10001; y < maximalenY + 10001; y++){
        for(int x = minimalenX + 10001; x < maximalenX + 10001; x++){
            if(tukImaLi[x][y] == false){
                tukImaLi[x][y] = true;
                lichice++;
            }
        }
    }

    return lichice;
}

int main(){
    cin>>broiPravoagalnici;

    int lice = 0;

    for(int i = 0; i < broiPravoagalnici; i++){
        DanniZaTochka nqkoiSi;
        DanniZaTochka drugSi;
        cin>>nqkoiSi.x>>nqkoiSi.y>>drugSi.x>>drugSi.y;
        int minimalenX = min(nqkoiSi.x, drugSi.x);
        int maximalenX = max(nqkoiSi.x, drugSi.x);
        int minimalenY = min(nqkoiSi.y, drugSi.y);
        int maximalenY = max(nqkoiSi.y, drugSi.y);

        lice += pravene(minimalenX, minimalenY, maximalenX, maximalenY);
    }

    cout<<lice<<endl;

    return 0;
}
