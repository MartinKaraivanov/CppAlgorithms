#include<iostream>
using namespace std;

int fibonacci[100000];

int main(){
    int broiCisla;

    cin>>broiCisla;

    for(int i = 0; i < broiCisla; i++){
        if(i == 0){
            fibonacci[i] = 0;
            continue;
        }

        if(i == 1){
            fibonacci[i] = 1;
            continue;
        }

        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];

    }

    for(int i = 0; i < broiCisla; i++){
        cout<<fibonacci[i]<<" ";
    }

    return 0;
}
