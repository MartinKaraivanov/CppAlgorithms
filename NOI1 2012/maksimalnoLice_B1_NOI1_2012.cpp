#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

double radius;

int main(){
    cin>>radius;

    double maksLice = radius*radius;

    cout<<fixed<<setprecision(3)<<maksLice<<endl;

    return 0;
}
