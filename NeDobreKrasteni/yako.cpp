#include<iostream>
#include<cmath>
using namespace std;

bool composite[1005];
const int n=1005;

void eratosten (){
    int sqrt_n=sqrt(n);
    for(int i=2; i < sqrt_n ; i++){
        if(!composite[i]){
            for(int x=i*i;x<n;x+=i){
                composite[x]=true;
            }
        }
    }

}

int sborNaCifri(int chislo){
    int sborNaCifri=0;
    int kloningNAChislo=chislo;
    while(kloningNAChislo>0){
        sborNaCifri+=kloningNAChislo%10;
        kloningNAChislo/=10;
    }
    return sborNaCifri;
}

int main(){
    int a;
    int b;

    cin>>a>>b;

    eratosten();

    bool imaLiYakiChisla=false;
    for(int i=a;i<=b;i++){
        if(composite[i]==false){
            int sbor=sborNaCifri(i);
            if(sbor>9){
                if(composite[sbor]==false){
                    cout<<i<<" ";
                    imaLiYakiChisla=true;
                }
            }
        }
    }

    if(imaLiYakiChisla==false){
        cout<<0;
    }

    return 0;
}
