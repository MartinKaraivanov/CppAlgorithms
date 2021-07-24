#include<iostream>
#include<cmath>
using namespace std;

long long dvoichnoChislo[2000];
long long broiCifriNaDvoichnotoChislo;

int main(){
    char cifra;

    while(cin>>cifra){
        dvoichnoChislo[broiCifriNaDvoichnotoChislo]=cifra-'0';
        broiCifriNaDvoichnotoChislo++;
    }

    long long desetichnoChislo=0;

    long long j=0;

    for(long long i=broiCifriNaDvoichnotoChislo-1;i>=0;i--){
        desetichnoChislo+=dvoichnoChislo[i]*pow(2,j);
        j++;
    }

    if(desetichnoChislo%7==0){
        cout<<"YES"<<endl;
    }else{
        cout<<7-desetichnoChislo%7<<endl;
    }

    return 0;
}
