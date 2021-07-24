#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int sirene[(n-1)/2];
    for(int i=0;i<(n-1)/2;i++){
        cin>>sirene[i];
    }

    int hlqb[(n-1)/2];
    for(int i=0;i<(n-1)/2;i++){
        cin>>hlqb[i];
    }

    int i=0;
    int j=0;
    int raztoqnie=0;

    while((i<(n-1)/2) && (j<(n-1)/2)){
        if(sirene[i]==hlqb[j]){
            raztoqnie=i+1+j+1;
            break;
        }else{
            if(sirene[i]<hlqb[j]){
                i++;
            }else{
                j++;
            }
        }
    }

    cout<<raztoqnie<<endl;

    return 0;
}
