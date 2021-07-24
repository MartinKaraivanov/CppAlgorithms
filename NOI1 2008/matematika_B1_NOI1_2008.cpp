#include<iostream>
#include<algorithm>
using namespace std;

int broiMinuscheta;
int broiChisla;

int sumichka;

int chisla[1000000];

int main(){
    cin>>broiChisla>>broiMinuscheta>>sumichka;

    for(int i = 0; i < broiChisla - 1; i++){
        cin>>chisla[i];
    }

    sort(chisla, chisla + broiChisla - 1);

    for(int i = 0; i < broiChisla - 1; i++){
        if(broiMinuscheta > 0){
            sumichka -= chisla[i];
            broiMinuscheta--;
        }else{
            sumichka += chisla[i];
        }
    }

    cout<<sumichka<<endl;

    return 0;
}
