#include <iostream>
using namespace std;
int main(){
long long a,b,c,x,y,z,kubcheSega,boqdisano[7];
cin>>a>>b>>c;
for(int i=0;i<=6;i++){
    boqdisano[i]=0;
}
for(x=1;x<=a;x++){
    for(y=1;y<=b;y++){
        for(z=1;z<=c;z++){
            int br = 0;
            if(x==1){
                br++;
            }
            if(x==a){
                br++;
            }
            if(y==1){
                br++;
            }
            if(y==b){
                br++;
            }
            if(z==1){
                br++;
            }
            if(z==c){
                br++;
            }
            boqdisano[br]=boqdisano[br]+1;

        }
    }
}
for(int i=0;i<=6;i++){
    cout<<boqdisano[i]<<" ";
}

return 0;
}
