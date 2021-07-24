#include<iostream>
#include<cmath>
using namespace std;

int pPredstavqne[3000];
int broiCifriNaPPredstavqne;

bool composite[100000];
int n,sqrt_n;

int broiProsti;
int prime[100000];


int main(){
    n=100000;
    sqrt_n=sqrt(n);
    for(int i=2; i < sqrt_n ; i++){
        if(!composite[i]){
            for(int x=i*i;x<n;x+=i){
                composite[x]=true;
            }
        }
    }


    for(int i=2;i<100000;i++){
        if(composite[i]==false){
            prime[broiProsti]=i;
            broiProsti++;
        }
    }


    char cifra;

    while(cin>>cifra){
        pPredstavqne[broiCifriNaPPredstavqne]=cifra-'0';
        broiCifriNaPPredstavqne++;
    }

    long long desetichnoChislo=0;

    for(int i=0;i<broiCifriNaPPredstavqne;i++){
        desetichnoChislo=desetichnoChislo+pPredstavqne[i]*prime[i];
    }

    cout<<desetichnoChislo;


    return 0;
}
