#include<iostream>
#include<iomanip>
#include<cmath>
#include<math.h>
using namespace std;

double naiVatreshno;
double naiVanshno;

const double pi = 3.14159265359;

int main(){
    cin>>naiVatreshno>>naiVanshno;

    double znamenatel = 2*7*pi;

    cout<<fixed<<setprecision(3)<<(naiVanshno - naiVatreshno)/znamenatel<<endl;

    return 0;
}
