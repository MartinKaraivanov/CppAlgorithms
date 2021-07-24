#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int broiTochki;
int tochki[15];

int naiKaso = 10000000;

void slagane(){
    int dalzhina = 0;
    int chi = tochki[0];
    int segashenY = chi%10;
    chi/=10;
    int segashenX = chi;

    for(int i = 1; i < broiTochki; i++){
        int sledvChislo = tochki[i];
        int sledvY = sledvChislo%10;
        sledvChislo/=10;
        int sledvX = sledvChislo;
        dalzhina += abs(sledvX - segashenX) + abs(sledvY - segashenY);
        segashenX = sledvX;
        segashenY = sledvY;
    }
    if(dalzhina < naiKaso){
        naiKaso = dalzhina;
    }
}

int main(){
    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        int x;
        int y;
        cin>>x>>y;
        tochki[i] = 10*x + y;
    }

    sort(tochki, tochki + broiTochki);

    do{
        slagane();
    }while(next_permutation(tochki, tochki + broiTochki));

    cout<<naiKaso<<endl;

    return 0;
}
