#include<iostream>
using namespace std;
int main(){
    long long godini;
    cin>>godini;
    long long broiOfce[godini];

    for(int i=0;i<godini;i++){
        broiOfce[i]=0;
    }

    broiOfce[0]=3;
    broiOfce[1]=4;
    broiOfce[2]=6;

    for(int i=3;i<godini;i++){
        broiOfce[i]=broiOfce[i-1]+broiOfce[i-3];
    }

    cout<<broiOfce[godini-1];

    return 0;
}
