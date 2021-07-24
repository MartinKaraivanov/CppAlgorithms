#include<iostream>
using namespace std;

int faktoriel(int n){
    if(n==1){
        return 1;
    }else{
        return n*faktoriel(n-1);
    }
}

int main(){

    int n;
    cin>>n;

    cout<<faktoriel(n);

    return 0;
}
