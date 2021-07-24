#include <iostream>
using namespace std;
int main(){
long long vhod[5],i,n,vuvedeni,ednakvoLiE,koiNomer;
for(i=0;i<5;i++){
    cin>>vhod[i];
}
ednakvoLiE=vhod[0];
koiNomer=vhod[0];
for(i=1;i<5;i++){
    if(vhod[i]==ednakvoLiE){
        //cout<<vhod[i]+ednakvoLiE<<" ";
        ednakvoLiE=vhod[i]+ednakvoLiE;
        koiNomer=vhod[i+1];
    }
}
cout<<ednakvoLiE<<" "<<koiNomer;

return 0;
}
