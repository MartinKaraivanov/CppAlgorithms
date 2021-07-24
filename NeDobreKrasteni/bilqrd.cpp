#include<iostream>
using namespace std;

int main(){
    long long m,n,momentiNaOtblyskvane,pozition,x,y,posokanaX,posokanaY;
    bool stenaLiE=false,vDupkaLiE=false;
    cin>>m>>n;


    x = 1;
    y = 1;
    posokanaX=1;
    posokanaY=1;
    vDupkaLiE=false;
    momentiNaOtblyskvane=0;
    while(vDupkaLiE==false){
        x=x+posokanaX;
        y=y+posokanaY;
        if((x==1 && y==1) || (x==1 && y==n) || (x==m && y==1) || (x==m && y==n)){
            vDupkaLiE=true;
            momentiNaOtblyskvane++;
        }else{
            if(x==m || x==1){
                posokanaX=posokanaX*(-1);
                momentiNaOtblyskvane++;
            }
            if(y==1 || y==n){
                posokanaY=posokanaY*(-1);
                momentiNaOtblyskvane++;
            }
        }
    }
    cout<<momentiNaOtblyskvane;


    return 0;
}
