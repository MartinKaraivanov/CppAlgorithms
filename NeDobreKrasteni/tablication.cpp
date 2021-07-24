#include<iostream>
using namespace std;
int main(){
    int m;
    int n;
    int k;

    cin>>m>>n>>k;

    int sbor=0;
    int chislo;
    int p=1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>chislo;
            if(p%k==0){
                sbor+=chislo;
            }
            p++;
        }
    }

    cout<<sbor<<endl;

    return 0;
}
