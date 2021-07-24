#include<iostream>
using namespace std;

int chisloTuka[9][9];

int main(){

    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            cin>>chisloTuka[y][x];
        }
    }

    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            if(chisloTuka[y][x] == 0){
                //cout<<x<<" "<<y<<endl;

                bool koiGiImaNagoreNadolu[10];
                bool koiGiImaNastrani[10];
                bool koiGiImaVTovaKvadratche[10];

                for(int i = 0; i < 10; i++){
                    koiGiImaNagoreNadolu[i] = false;
                    koiGiImaNastrani[i] = false;
                    koiGiImaVTovaKvadratche[i] = false;
                }

                //cout<<"v tazi kolona ima ";
                for(int i = 0; i < 9; i++){
                    //cout<<chisloTuka[i][x]<<" ";
                    koiGiImaNagoreNadolu[chisloTuka[i][x]] = true;
                }
                //cout<<endl;

                //cout<<"v tozi red ima ";
                for(int i = 0; i < 9; i++){
                    //cout<<chisloTuka[y][i]<<" ";
                    koiGiImaNastrani[chisloTuka[y][i]] = true;
                }
                //cout<<endl;

                int nachaloNaKvadratchetoPoX = (x/3)*3;
                int nachaloNaKvadratchetoPoY = (y/3)*3;

                //cout<<"v tova kvadratche ima ";
                for(int ky = nachaloNaKvadratchetoPoY; ky < nachaloNaKvadratchetoPoY + 3; ky++){
                    for(int kx = nachaloNaKvadratchetoPoX; kx < nachaloNaKvadratchetoPoX + 3; kx++){
                        //cout<<chisloTuka[ky][kx]<<" ";
                        koiGiImaVTovaKvadratche[chisloTuka[ky][kx]] = true;
                    }
                }

                //cout<<endl<<endl;

                for(int i = 1; i < 10; i++){
                    if(koiGiImaNagoreNadolu[i] == false &&
                       koiGiImaNastrani[i] == false &&
                       koiGiImaVTovaKvadratche[i] == false)
                    {
                        chisloTuka[y][x] = i;
                        break;
                    }
                }
            }
        }
    }

    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            cout<<chisloTuka[y][x]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
