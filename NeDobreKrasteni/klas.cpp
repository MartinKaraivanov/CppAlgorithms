#include <iostream>
using namespace std;
int main(){
long long momi,momche,zdravei=0,rakostis=0;
cin>>momche>>momi;
if(momche>1){
    rakostis=momche-1;
}
if(momi>0){
    zdravei=zdravei+momi*(momi-1);
}
if(momi>0 && momche>0){
    zdravei=zdravei+momi*2;
}
cout<<rakostis<<" "<<zdravei;

return 0;
}
