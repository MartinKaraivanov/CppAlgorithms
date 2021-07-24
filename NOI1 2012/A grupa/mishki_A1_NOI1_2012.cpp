#include<iostream>
#include<map>
using namespace std;

struct DanniZaSlagane{
    int x;
    int y;
    int kolkoMishki;
};

int broiPutiPostavq;

map<int, map<int, int>> broiMishkiTuka;
map<int, map<int, int>> broiMishkiSasedniNaTuka;

DanniZaSlagane slaganiq[2010];

int main(){
    cin>>broiPutiPostavq;

    int kolkoENaiMnogotoMishkiV1Kletka = 0;

    for(int i = 0; i < broiPutiPostavq; i++){
        int y;
        int x;
        int brMishoci;

        cin>>y>>x>>brMishoci;

        slaganiq[i] = {x, y, brMishoci};
        broiMishkiTuka[x][y] += brMishoci;
    }

    for(int i = 0; i < broiPutiPostavq; i++){
        int y = slaganiq[i].y;
        int x = slaganiq[i].x;
        int brMishoci = slaganiq[i].kolkoMishki;

        broiMishkiSasedniNaTuka[x][y + 1] += brMishoci;
        broiMishkiSasedniNaTuka[x][y - 1] += brMishoci;
        broiMishkiSasedniNaTuka[x + 1][y] += brMishoci;
        broiMishkiSasedniNaTuka[x - 1][y] += brMishoci;

        broiMishkiTuka[x][y] += brMishoci;

        if(broiMishkiTuka[x][y + 1] == 0 && broiMishkiSasedniNaTuka[x][y + 1] > kolkoENaiMnogotoMishkiV1Kletka){
            kolkoENaiMnogotoMishkiV1Kletka = broiMishkiSasedniNaTuka[x][y + 1];
        }
        if(broiMishkiTuka[x][y - 1] == 0 && broiMishkiSasedniNaTuka[x][y - 1] > kolkoENaiMnogotoMishkiV1Kletka && y - 1 > 0){
            kolkoENaiMnogotoMishkiV1Kletka = broiMishkiSasedniNaTuka[x][y - 1];
        }
        if(broiMishkiTuka[x + 1][y] == 0 && broiMishkiSasedniNaTuka[x + 1][y] > kolkoENaiMnogotoMishkiV1Kletka){
            kolkoENaiMnogotoMishkiV1Kletka = broiMishkiSasedniNaTuka[x + 1][y];
        }
        if(broiMishkiTuka[x - 1][y] == 0 && broiMishkiSasedniNaTuka[x - 1][y] > kolkoENaiMnogotoMishkiV1Kletka && x - 1 > 0){
            kolkoENaiMnogotoMishkiV1Kletka = broiMishkiSasedniNaTuka[x - 1][y];
        }
    }

    cout<<kolkoENaiMnogotoMishkiV1Kletka<<endl;

    return 0;
}
