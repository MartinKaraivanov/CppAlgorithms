#include<iostream>
using namespace std;

int razmerNaPoleto;
int sumaPoneKolko;

int pole[5005][5005];

int otNulaNulaDoTuk[5005][5005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>razmerNaPoleto>>sumaPoneKolko;

    for(int x = 1; x <= razmerNaPoleto; x++){
        for(int y = 1; y <= razmerNaPoleto; y++){
            cin>>pole[x][y];
        }
    }

    for(int x = 1; x <= razmerNaPoleto; x++){
        for(int y = 1; y <= razmerNaPoleto; y++){
            otNulaNulaDoTuk[x][y] =
                otNulaNulaDoTuk[x - 1][y] + otNulaNulaDoTuk[x][y - 1] - otNulaNulaDoTuk[x - 1][y - 1] + pole[x][y];
        }
    }

    if(otNulaNulaDoTuk[razmerNaPoleto][razmerNaPoleto] < sumaPoneKolko){
        cout<<-1<<endl;
        return 0;
    }

    int sreda = 1;

    for(int x = 1; x <= razmerNaPoleto - sreda + 1; x++){
        for(int y = 1; y <= razmerNaPoleto - sreda + 1; y++){
            while((x <= razmerNaPoleto - sreda + 1 &&
                y <= razmerNaPoleto - sreda + 1) &&
                (otNulaNulaDoTuk[x + sreda - 1][y + sreda - 1] -
                otNulaNulaDoTuk[x + sreda - 1][y - 1] -
                otNulaNulaDoTuk[x - 1][y + sreda - 1] +
                otNulaNulaDoTuk[x - 1][y - 1] < sumaPoneKolko))
            {
                sreda++;
            }
        }
    }

    if(sreda <= razmerNaPoleto){
        cout<<sreda<<endl;
    }

    return 0;
}
