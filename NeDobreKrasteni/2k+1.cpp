#include <iostream>
using namespace std;
int main(){
long long n,k;
k=1;
cin>>n;
cout<<"1"<<" ";
for(int i=1;i<=n;i++){
    k=k+k+1;
    cout<<k<<" ";
}

return 0;
}
