#include<iostream>
using namespace std;
int main(){
    long long broiRedove;
    long long broiKoloni;
    long long red;
    long long kolona;
    cin>>broiRedove>>broiKoloni>>red>>kolona;
    if(red%2==1){
        cout<<(red-1)*broiKoloni+kolona-1;
    }else{
        cout<<red*broiKoloni-kolona;
    }

    cout<<endl;

    return 0;
}
