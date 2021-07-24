#include<iostream>
using namespace std;
int main(){
    long long broiCh;
    cin>>broiCh;
    long long chislenca[broiCh];
    bool isItPrime[broiCh];
    for(int i=0;i<broiCh;i++){
        cin>>chislenca[i];
        isItPrime[i]=true;
    }
    for(int i=0;i<broiCh;i++){
        if(chislenca[i] % i==0 && isItPrime[i]==true){
            isItPrime[i]=false;
        }
    }
    long long broiProsti=0;
    for(int i=0;i<broiCh;i++){
        if(isItPrime[i]==true){
            broiProsti++;
        }
    }
    cout<<broiProsti;

    return 0;
}
