#include <iostream>
using namespace std;
int main(){
    long long proverqvani[10],sbor=0;
    for(int i=0;i<10;i++){
        cin>>proverqvani[i];
    }
    for(int n=0;n<9;n++){
        if(proverqvani[n]<=proverqvani[n+1]){
            sbor++;
        }
    }
    if(sbor==9){
        cout<<endl;
        cout<<"da";
    }else{
        cout<<"ne";
    }

return 0;
}
