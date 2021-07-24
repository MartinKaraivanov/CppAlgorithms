#include <iostream>
using namespace std;
int main(){
long long chislo,obshto;
obshto=1;
cin>>chislo;
for( int i=1;i<=chislo;i=i+1){
    obshto *=i;
}
cout<<obshto;

return 0;
}
