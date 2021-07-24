#include <iostream>
using namespace std;
int main(){
    int n = 20;
    int mehurchenca[n],zaPromqna=0;
    for(int i=0;i<n;i++){
        cin>>mehurchenca[i];
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n-1;i++){
            if(mehurchenca[i]>mehurchenca[i+1]){
                zaPromqna=mehurchenca[i];
                mehurchenca[i]=mehurchenca[i+1];
                mehurchenca[i+1]=zaPromqna;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<mehurchenca[i]<<" ";
    }

return 0;
}
