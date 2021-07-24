#include<iostream>
#include<iomanip>
using namespace std;

int a;
int b;

int main(){
    cin>>a>>b;

    double lice = 0;

    if(a != b){
        lice = (double)2*a*b - (double)a*a;
    }else{
        lice = (double)a*a + (double)a*a/5.82842712468;
    }

    cout<<fixed<<setprecision(3)<<lice<<endl;

    return 0;
}
