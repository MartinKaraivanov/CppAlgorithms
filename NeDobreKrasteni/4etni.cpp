#include<iostream>
using namespace std;
int main(){
    long long broi;
    cin>>broi;
    long long chisla[broi];
    for(int i=0;i<broi;i++){
        cin>>chisla[i];
    }
    long long broiChetni=0;
    for(int i=0;i<broi;i++){
        if(chisla[i]%2==0){
            broiChetni++;
        }
    }

    cout<<broiChetni;

    return 0;
}
