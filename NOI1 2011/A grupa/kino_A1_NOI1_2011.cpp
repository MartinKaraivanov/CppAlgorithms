#include<iostream>
using namespace std;

int maxY;
int maxX;

int pravoagalnikY;
int pravoagalnikX;

int broiZaetiOtNachalotoDoTuk[111][111];

int main(){
    cin>>maxY>>maxX;

    cin>>pravoagalnikY>>pravoagalnikX;

    for(int y = 1; y <= maxY; y++){
        char red[111];
        cin>>red;
        for(int x = 1; x <= maxX; x++){
            char tuka = red[x - 1];

            if(tuka == '#'){
                broiZaetiOtNachalotoDoTuk[y][x]++;
            }

            broiZaetiOtNachalotoDoTuk[y][x] +=
                broiZaetiOtNachalotoDoTuk[y][x-1] + broiZaetiOtNachalotoDoTuk[y-1][x] - broiZaetiOtNachalotoDoTuk[y - 1][x - 1];

        }
    }

    int broiOk = 0;

    for(int y = pravoagalnikY; y <= maxY; y++){
        for(int x = pravoagalnikX; x <= maxX; x++){
            int my = y - pravoagalnikY + 1;
            int mx = x - pravoagalnikX + 1;

            int broiVToziPravoagalnik =
                broiZaetiOtNachalotoDoTuk[y][x] -
                broiZaetiOtNachalotoDoTuk[my - 1][x] -
                broiZaetiOtNachalotoDoTuk[y][mx - 1] +
                broiZaetiOtNachalotoDoTuk[my - 1][mx - 1];

            //cout<<y<<" "<<x<<" "<<broiVToziPravoagalnik<<endl;

            if(broiVToziPravoagalnik == 0){
                broiOk++;
            }
        }
    }

    cout<<broiOk<<endl;

    return 0;
}
