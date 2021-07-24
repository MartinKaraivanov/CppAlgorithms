#include<iostream>
using namespace std;

long long slepeno[50];
int broiCifri;

int main(){
    char cifrichka;

    while(cin>>cifrichka){
        if(cifrichka>='0' && cifrichka<='9'){
            slepeno[broiCifri]=cifrichka-'0';
        }
    }




    return 0;
}
