#include <iostream>
using namespace std;
int main(){
long long stepen,chislo;
chislo=1;
cin>>stepen;
for(int i=1;i<=stepen;i++){
    if(i==1){
        cout<<"2";
        cout<<endl;
    }
    chislo=chislo*2;
    if(i%2==0){
        cout<<chislo<<" ";
        cout<<endl;
    }
}

return 0;
}
