#include <iostream>
using namespace std;
int main(){
long long a,b,c,obem,nula=0,edno=0,dve=0,tri=0,chetiri=0,pet=0,shest=0;
cin>>a>>b>>c;
obem=a*b*c;
// kubchetata koito sa neocveteni obrazuwat paralelepped s razmeri a-2 na b-2 na c-2
// 6 ocweteni strani ima samo pri kubche 1x1x1
// kubcheta s 5 ocweteni strani ima samo pri paralelepiped s razmeri 1x1xN
//kubcheta s 1 ocwetena strana ima warhu kubcheta s 0 osweteni steni
//kubcheta s 2 boqdisani strani sa 4x(a-2) 4x(b-2) 4x(c-2)
//kubchetata s 3 boqdisani strani sa ako pralelepipedat e s razmeri pone 3x3x3
//kubcheta s 4 poqdisani strani ima pri razmer 1xPone2xPone2

if(a-2>0 && b-2>0 && c-2>0){
    nula=nula+(a-2)*(b-2)*(c-2);
}
if(a==1 && b==1 && c==1){
    shest=1;
}
if((a==1 && b==1) || (a==1 && c==1) || (b==1 && c==1) ){
    pet=2;
}
if(nula>0){
    edno=(a-2)*(b-2)*2+(a-2)*(c-2)*2+(b-2)*(c-2)*2;
}
if(a-2>0 && b-2>0 && c-2>0){
    dve=4*(a-2)+4*(b-2)+4*(c-2);
}
if((a==1 && b>2 && c>2) || (b==1 && a>2 && c>2) || (c==1 && a>2 && b>2) ){
    dve=(a-2)*(b-2)*(c-2)*-1;
}
if(a>=3 && b>=3 && c>=3){
    tri=8;
}
if((a==1 && b>2 && c>2) || (b==1 && a>2 && c>2) || (c==1 && a>2 && b>2) ){
    tri=-4*(a-2)*(b-2)*(c-2);
    if((a==1 && b==2 && c>2)||(b==1 && a==2 && c>2)){
        tri=4*2*c;
    }
    if((c==2 && b==2 && a>2)||(b==1 && c==2 && a>2)){
        tri=4*2*a;
    }
    if((a==1 && b>2 && c==2)||(c==2 && a==2 && b>2)){
        tri+4*2*b;
    }
}
if((a==1 && b==1) || (b==1 && c==1) || (c==1 && a==1) ){
    chetiri=a*b*c-2;
}
cout<<nula<<" "<<edno<<" "<<dve<<" "<<tri<<" "<<chetiri<<" "<<pet<<" "<<shest;

return 0;
}
