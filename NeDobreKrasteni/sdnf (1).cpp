#include <iostream>
using namespace std;
int main(){
long long vhod,rezultat=1,novoChislo=0,poslednaCifra=0,suma=0;
cin>>vhod;
for(int i=1;i<=vhod;i++){
    rezultat=rezultat*i;
}
//cout<<rezultat;
poslednaCifra=rezultat%10;
suma=suma+poslednaCifra;
novoChislo=rezultat/10;
while(novoChislo>0){
    poslednaCifra=novoChislo%10;
    suma=suma+poslednaCifra;
    novoChislo=novoChislo/10;
    cout<<suma<<" "<<novoChislo<<" ";
}
cout<<suma;

return 0;
}
