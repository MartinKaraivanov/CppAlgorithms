#include<iostream>
using namespace std;
int main(){
    long long redove;
    long long broiSedalki;
    long long sedalkaZaTarsene;
    cin>>redove>>broiSedalki>>sedalkaZaTarsene;

    long long red;
    long long mqsto;

    red = 1+(sedalkaZaTarsene-1)/broiSedalki;
    mqsto= 1+(sedalkaZaTarsene-1)%broiSedalki;

    cout<<red<<" "<<mqsto;

    return 0;
}
