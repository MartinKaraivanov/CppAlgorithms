#include<iostream>
using namespace std;
int main(){
    int n;
    int an;
    int anPlus1;

    cin>>n>>an>>anPlus1;

    for(int i=n;i>1;i--){
        int anMinus1=anPlus1-an;
        anPlus1=an;
        an=anMinus1;
    }

    cout<<an<<" "<<anPlus1<<endl;

    return 0;
}
