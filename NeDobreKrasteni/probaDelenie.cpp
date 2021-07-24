#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double a;
    double b;

    cin>>a>>b;

    double c = a/b;

    cout<<fixed<<setprecision(50)<<c<<endl;

    return 0;
}
