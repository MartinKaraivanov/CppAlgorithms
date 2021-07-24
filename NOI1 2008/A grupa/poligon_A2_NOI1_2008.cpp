#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
int p;

const double pi = 3.14159265359;

double otGradusivradiani(double gradus){
    return (gradus*(pi/180));
}

int naiGolqmObshtDelitel(int a, int b){
    while(b != 0){
        int d = b;
        b = a%b;
        a = d;
    }
    return a;
}

int nok(int a, int b){
    return (a * b)/naiGolqmObshtDelitel(a, b);
}

int main(){
    cin>>n>>p;

    int kolkoPatiDaBroimOtsechkata = nok(n, p + 1)/(p + 1);

    double dulzhinaNaOtsechkata = sin(otGradusivradiani(((double)(p + 1)/(double)(2 * n))*((double)360)))*(double)2;

    cout<<fixed<<setprecision(5)<<kolkoPatiDaBroimOtsechkata*dulzhinaNaOtsechkata<<endl;

    return 0;
}
