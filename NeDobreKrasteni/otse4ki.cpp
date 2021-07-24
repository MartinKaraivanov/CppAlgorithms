#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    int d;

    cin>>a>>b>>c>>d;

    int nachaloA=min(a,b);
    int kraiA=max(a,b);
    int nachaloB=min(c,d);
    int kraiB=max(c,d);

    int zasichashtaSeChast=-1;

    int nachaloNaChastata=max(nachaloA,nachaloB);
    int kraiNaChastata=min(kraiA,kraiB);

    if(kraiNaChastata-nachaloNaChastata>=0){
        zasichashtaSeChast=kraiNaChastata-nachaloNaChastata;
    }


    cout<<zasichashtaSeChast<<endl;

    return 0;
}
