#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> chislo;
    int chislence;
    cin>>chislence;

    while(chislence>0){
        cout<<chislence%10;
        chislence/=10;
    }

    /*while(chislo.empty()==false){
        cout<<chislo.top();
        chislo.pop();
    }*/

    return 0;
}
