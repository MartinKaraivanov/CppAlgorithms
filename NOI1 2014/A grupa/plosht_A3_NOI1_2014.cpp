#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double a;
double b;

int main(){
    cin>>a>>b;

    if(3*a - b < -0.000001){
        cout<<"0.00"<<endl;
        return 0;
    }

    double h = sqrt(a*a - ((a - b)/2)*((a - b)/2));

    double lice = ((a + b)*h)/2;

    cout<<fixed<<setprecision(2)<<lice<<endl;

    return 0;
}
