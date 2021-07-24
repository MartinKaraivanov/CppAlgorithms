#include<iostream>
using namespace std;
int main(){
    unsigned long long kolkoNaiMnogo;
    cin>>kolkoNaiMnogo;

    if(kolkoNaiMnogo%2 == 0){
        unsigned long long start = kolkoNaiMnogo+3;
        unsigned long long segashnoChislo = start;
        for(int i = 0; i < 10; i++){
            cout<<segashnoChislo;
            if(i < 9){
                cout<<" ";
            }
            segashnoChislo += kolkoNaiMnogo+2;
        }
        cout<<endl;
    }else{
        unsigned long long start = 2*kolkoNaiMnogo + 3;
        unsigned long long segashnoChislo = start;
        for(int i = 0; i < 10; i++){
            cout<<segashnoChislo;
            if(i < 9){
                cout<<" ";
            }
            segashnoChislo += 2*kolkoNaiMnogo + 2;
        }
        cout<<endl;
    }

    return 0;
}
