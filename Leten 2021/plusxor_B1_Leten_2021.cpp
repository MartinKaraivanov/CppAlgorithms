#include<iostream>
using namespace std;

unsigned long long sborKolko;
unsigned long long xorKolko;

int main(){
    cin>>sborKolko>>xorKolko;

    unsigned long long parvoChislo = (sborKolko - xorKolko)/2;

    unsigned long long vtoroChislo = parvoChislo + xorKolko;

    unsigned long long novXor = parvoChislo^vtoroChislo;

    if(novXor != xorKolko){
        cout<<-1<<endl;
        return 0;
    }

    cout<<parvoChislo<<" "<<vtoroChislo<<endl;

    return 0;
}
