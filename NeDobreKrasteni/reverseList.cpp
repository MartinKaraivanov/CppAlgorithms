#include <iostream>
using namespace std;
int main(){
long long vhod[10],i,n;
for(i=0;i<10;i++){
    cin>>vhod[i];
}
for(i=9;i>=0;i=i-1){
    cout<<vhod[i]<<" ";
}

return 0;
}
