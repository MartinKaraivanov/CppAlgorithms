#include <iostream>
using namespace std;
int main(){
long long a,b,c,d,k;
cin>>a>>b>>c>>d>>k;
for(int i=0;i<k;i++){
    a=a*b;
    if(a-c>0){
        a=a-c;
    }else{
        cout<<"0";
        return 0;
    }
    if(a>d){
        a=d;
    }else{
        a=a;
    }
}
cout<<a;

return 0;
}
