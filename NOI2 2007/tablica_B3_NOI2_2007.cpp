#include<iostream>
using namespace std;

int tablica[1010][1010];

int sumaOtNachalotoDoTuk[1010][1010];

int main(){
    int maxY;
    int maxX;
    int nashY;
    int nashX;

    cin>>maxY>>maxX>>nashY>>nashX;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            cin>>tablica[x][y];
        }
    }

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            sumaOtNachalotoDoTuk[x][y] = tablica[x][y] + sumaOtNachalotoDoTuk[x - 1][y] +
                sumaOtNachalotoDoTuk[x][y - 1] - sumaOtNachalotoDoTuk[x - 1][y - 1];
        }
    }

    int naiGolqmaSumichka = 0;

    for(int y = 1; y <= maxY; y++){
        for(int x = 1; x <= maxX; x++){
            int vTova = sumaOtNachalotoDoTuk[x][y] - sumaOtNachalotoDoTuk[x - nashX][y] -
                sumaOtNachalotoDoTuk[x][y - nashY] + sumaOtNachalotoDoTuk[x - nashX][y - nashY];
            if(vTova > naiGolqmaSumichka){
                naiGolqmaSumichka = vTova;
            }
        }
    }

    cout<<naiGolqmaSumichka<<endl;

    return 0;
}
