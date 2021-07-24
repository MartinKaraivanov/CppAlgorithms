#include <iostream>
using namespace std;
int main(){
long long M,N,chislenca=0,i=1,k=1;
cin>>M>>N;

while(i*(i+1)<M){
    i=i+1;
}
for(k=M;k<=N;k++){
        if(i*(i+1)==k){
            chislenca++;
            i++;
        }
}

/*for(int i=M;i<N;i++){
    if(i*(i+1)==M+i){
        chislenca=chislenca+1;
    }
}*/

/*while(M<=N){
    if(i*(i+1)==M){
        chislenca=chislenca+1;
        i=i+1;
    }
    M=M+1;

}*/
cout<<chislenca;

return 0;
}
