#include<iostream>
using namespace std;

long long vavezhdane[15];

int main(){
    int agalnik;
    cin>>agalnik;

    int cifra;

    for(int i=0;i<agalnik;i++){
        cin>>cifra;
        vavezhdane[i]=cifra;
    }

    long long naiGolqmoChislo=0;


    for(int i=0;i<agalnik;i++){
        long long natrupano=0;

        for(int j=i;j<agalnik;j++){
            natrupano=10*natrupano+vavezhdane[j];
        }

        for(int j=0;j<i;j++){
            natrupano=10*natrupano+vavezhdane[j];
        }

        if(natrupano>naiGolqmoChislo){
            naiGolqmoChislo=natrupano;
        }
    }

    for(int i=0;i<agalnik;i++){
        long long natrupano=0;

        for(int j=i;j>=0;j--){
            natrupano=natrupano*10+vavezhdane[j];
        }

        for(int j=agalnik-1;j>i;j--){
            natrupano=natrupano*10+vavezhdane[j];
        }

        if(natrupano>naiGolqmoChislo){
            naiGolqmoChislo=natrupano;
        }


    }

    cout<<naiGolqmoChislo<<endl;

    return 0;
}
