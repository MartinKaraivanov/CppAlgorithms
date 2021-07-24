#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int chisla[100];
int broiChisla;

int main(){
    int chislo;

    while(cin>>chislo){
        chisla[broiChisla] = chislo;
        broiChisla++;
    }

    sort(chisla, chisla + broiChisla);

    for(int i = 0; i < broiChisla; i++){
        cout<<chisla[i]<<" ";
    }

    return 0;
}
