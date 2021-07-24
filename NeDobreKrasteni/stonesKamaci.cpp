#include<iostream>
using namespace std;

int broiOtTovaKamache[20000];

int main(){
    int n;
    cin>>n;

    int tegla[n];

    for(int i=0;i<n;i++){
        cin>>tegla[i];
        broiOtTovaKamache[tegla[i]]++;
    }

    int kolkoVzimame=0;
    for(int i=0;i<10001;i++){
        if(broiOtTovaKamache[i]>=1){
            kolkoVzimame++;
        }
    }

    cout<<kolkoVzimame<<endl;


    return 0;
}
