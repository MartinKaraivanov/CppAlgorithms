#include <iostream>
using namespace std;
int main(){
    long long a,b,c,k,nula=0,edno=0,dve=0,tri=0,chetiri=0,pet=0,shest=0;
    cin>>a>>b>>c>>k;

    if(a-2>0 && b-2>0 && c-2>0){
        nula=nula+(a-2)*(b-2)*(c-2);
    }
    if(a==1 && b==1 && c==1){
        shest=1;
    }
    if((a==1 && b==1 && c>1) || (a==1 && c==1 && b>1) || (b==1 && c==1 && a>1) ){
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

    if(a>=2 && b>=2 && c>=2){
        tri=8;
    }

    if((a==1 && b>2 && c>2)){
        tri=2*((b-2)+(c-2));
    }

    if((b==1 && a>2 && c>2)){
        tri=2*((a-2)+(c-2));
    }
    if((c==1 && b>2 && a>2)){
        tri=2*((b-2)+(a-2));
    }

    if((a==1 && b==2 && c>2)||(b==1 && a==2 && c>2)){
        tri=4*2*c;
    }
    if((c==2 && b==2 && a>2)||(b==1 && c==2 && a>2)){
        tri=4*2*a;
    }
    if((a==1 && b>2 && c==2)||(c==2 && a==2 && b>2)){
        tri=4*2*b;
    }


    if((a==1 && b==1) || (b==1 && c==1) || (c==1 && a==1) ){
        chetiri=a*b*c-2;
    }

    if((a==1) && (b>1) && (c>1)){
        chetiri=4;
    }
    if((b==1) && (a>1) && (c>1)){
        chetiri=4;
    }
    if((c==1) && (b>1) && (a>1)){
        chetiri=4;
    }

    if(k==1){
        cout<<edno;
    }else{
        if(k==2){
            cout<<dve;
        }else{
            if(k==3){
                cout<<tri;
            }else{
                if(k==4){
                    cout<<chetiri;
                }else{
                    if(k==5){
                        cout<<pet;
                    }else{
                        if(k==6){
                            cout<<shest;
                        }else{
                            cout<<nula;
                        }
                    }
                }
            }
        }
    }

    cout<<endl;

return 0;
}
