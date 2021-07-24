#include<iostream>
#include<cmath>
using namespace std;

bool composite[100000];
int n,sqrt_n;

int main(){

    n=100000;
    ///cin>>n;
    sqrt_n=sqrt(n);
    for(int i=2; i < sqrt_n ; i++){
        if(!composite[i]){
            for(int x=i*i;x<n;x+=i){
                composite[x]=true;
            }
        }
    }

    /*for(int i=2;i<n;i++){
        if(!composite[i]){
            cout<<i<<" ";
        }
    }*/

    long long broi;
    cin>>broi;
    long long chisla[broi];
    for(int i=0;i<broi;i++){
        cin>>chisla[i];
    }
    long long broiProsti=0;
    for(int i=0;i<broi;i++){
        if(composite[chisla[i]]==false){
            broiProsti++;
        }
    }

/*
    int x = 15679;
    bool xESlojno = false;
    if(composite[x]==true){
        xESlojno=true;
    }
*/

    cout<<broiProsti;

    return 0;
}
