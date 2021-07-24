#include<iostream>
#include<cmath>
using namespace std;

bool composite[100000];
int n,sqrt_n;

int broiProsti;
int prime[1000000];

long long poKolkoPatiSeSreshtaCifrata[1000000];

int main(){
    n=1000000;
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


    int doKoiFaktoriel;
    cin>>doKoiFaktoriel;

    for(int i=2;i<=doKoiFaktoriel;i++){
        int kopiranoI=i;
        int j=0;
        while(kopiranoI>1){
            if(kopiranoI%prime[j]==0){
                poKolkoPatiSeSreshtaCifrata[prime[j]]++;
                kopiranoI/=prime[j];
            }else{
                j++;
            }
        }
    }

    long long sbor=0;

    for(int i=0;i<broiProsti;i++){
        sbor+=poKolkoPatiSeSreshtaCifrata[i];
    }

    cout<<sbor<<endl;

    return 0;
}
