#include <iostream>
using namespace std;
int main(){
long long vuvedeni[10],naiMalkoDosega,i;
for(i=0;i<10;i++){
    cin>>vuvedeni[i];
}
naiMalkoDosega=vuvedeni[1];
for(i=0;i<10;i++){
    if(vuvedeni[i]<naiMalkoDosega){
        naiMalkoDosega=vuvedeni[i];
    }
}
cout<<"nai malkoto e "<<naiMalkoDosega;

return 0;
}
