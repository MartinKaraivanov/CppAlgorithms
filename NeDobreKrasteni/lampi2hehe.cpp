#include<iostream>
using namespace std;

int nod(int a, int b){
    while(a!=0 && b!=0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0){
        return b;
    }
    return a;

}

int main(){
    long long a;
    long long b;
    long long naigolqmobshtd;
    long long nok;
    cin>>a>>b;
    naigolqmobshtd=nod(a,b);
    nok=a * b / nod( a, b );
    cout<<nok;

    return 0;
}
