#include<iostream>
using namespace std;

int maxX;
int maxY;
int maxZ;

int broiDiamantiTuk[105][105][105];

int broiOtNulaNulaNulaDoTuk[105][105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxX>>maxY>>maxZ;

    for(int z = 1; z <= maxZ; z++){
        for(int y = 1 ; y <= maxY; y++){
            for(int x = 1; x <= maxX; x++){
                cin>>broiDiamantiTuk[z][y][x];
            }
        }
    }

    for(int z = 1; z <= maxZ; z++){
        for(int y = 1; y <= maxY; y++){
            for(int x = 1; x <= maxX; x++){
                broiOtNulaNulaNulaDoTuk[z][y][x] = broiDiamantiTuk[z][y][x] + broiOtNulaNulaNulaDoTuk[z - 1][y][x] +
                    broiOtNulaNulaNulaDoTuk[z][y - 1][x] + broiOtNulaNulaNulaDoTuk[z][y][x - 1] -
                    broiOtNulaNulaNulaDoTuk[z - 1][y - 1][x] - broiOtNulaNulaNulaDoTuk[z - 1][y][x - 1] -
                    broiOtNulaNulaNulaDoTuk[z][y - 1][x - 1] + broiOtNulaNulaNulaDoTuk[z - 1][y - 1][x - 1];
            }
        }
    }

    /*for(int z = 1; z <= maxZ; z++){
        for(int y = 1; y <= maxY; y++){
            for(int x = 1; x <= maxX; x++){
                cout<<broiOtNulaNulaNulaDoTuk[z][y][x]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }*/

    int nachalenX;
    int nachalenY;
    int nachalenZ;
    int kraenX;
    int kraenY;
    int kraenZ;

    while(cin>>nachalenX){
        cin>>nachalenY>>nachalenZ>>kraenX>>kraenY>>kraenZ;

        nachalenX++;
        nachalenY++;
        nachalenZ++;

        int otgovor = broiOtNulaNulaNulaDoTuk[kraenZ][kraenY][kraenX] -
                        broiOtNulaNulaNulaDoTuk[nachalenZ - 1][kraenY][kraenX] -
                        broiOtNulaNulaNulaDoTuk[kraenZ][nachalenY - 1][kraenX] -
                        broiOtNulaNulaNulaDoTuk[kraenZ][kraenY][nachalenX - 1] +
                        broiOtNulaNulaNulaDoTuk[nachalenZ - 1][nachalenY - 1][kraenX] +
                        broiOtNulaNulaNulaDoTuk[nachalenZ - 1][kraenY][nachalenX - 1] +
                        broiOtNulaNulaNulaDoTuk[kraenZ][nachalenY - 1][nachalenX - 1] -
                        broiOtNulaNulaNulaDoTuk[nachalenZ - 1][nachalenY - 1][nachalenX - 1];


        cout<<otgovor<<endl;
    }

    return 0;
}
