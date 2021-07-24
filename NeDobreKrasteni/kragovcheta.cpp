#include <iostream>
using namespace std;
int main(){
long long a,b,kragcheta=0,rezultat,poslednaCifra=0,i=0,novoChislo=0;
char znak;
cin>>a>>b>>znak;
if(znak=='+'){
    rezultat=a+b;
}
if(znak=='-'){
    rezultat=a-b;
}
if(znak=='*'){
    rezultat=a*b;
}
poslednaCifra=rezultat%10;
if(poslednaCifra==8){
    kragcheta=kragcheta+2;
}
if(poslednaCifra==0 || poslednaCifra==6 || poslednaCifra==9){
    kragcheta++;
}
novoChislo=rezultat/10;
while(novoChislo>0){
    poslednaCifra=novoChislo%10;
    if(poslednaCifra==8){
        kragcheta=kragcheta+2;
    }
    if(poslednaCifra==0 || poslednaCifra==6 || poslednaCifra==9){
        kragcheta++;
    }
    novoChislo=novoChislo/10;
}
cout<<kragcheta;

return 0;
}
