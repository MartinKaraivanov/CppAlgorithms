#include<iostream>
#include<vector>
using namespace std;

int koiVrah;

int kolkoOstavat;
int koeSiEVReda;
int naKoiRedE;

int koiNaRedaIskame[40];

int main(){

    cin>>koiVrah;

    kolkoOstavat = koiVrah + 1;

    for(int i = 1; true; i = i*2){
        if(i >= kolkoOstavat){
            koeSiEVReda = kolkoOstavat;
            break;
        }
        kolkoOstavat -= i;
        naKoiRedE++;
    }

    koeSiEVReda--;

    //cout<<koeSiEVReda<<" na red "<<naKoiRedE<<endl;

    int kopieNaKoiRedE = naKoiRedE;

    while(kopieNaKoiRedE >= 0){
        koiNaRedaIskame[kopieNaKoiRedE] = koeSiEVReda;
        koeSiEVReda /= 2;
        kopieNaKoiRedE--;
    }

    int chislitel = 1;
    int znamenatel = 1;

    for(int i = 1; i <= naKoiRedE; i++){
        int novChislitel = -1;
        int novZnamenatel = -1;

        if(koiNaRedaIskame[i]%2 == 0){
            novChislitel = chislitel;
            novZnamenatel = chislitel + znamenatel;
        }else{
            novChislitel = chislitel + znamenatel;
            novZnamenatel = znamenatel;
        }

        chislitel = novChislitel;
        znamenatel = novZnamenatel;
    }

    cout<<chislitel<<" "<<znamenatel<<endl;

    return 0;
}
