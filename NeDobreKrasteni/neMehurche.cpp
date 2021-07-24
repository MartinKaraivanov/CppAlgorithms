#include <iostream>
using namespace std;
int main(){
    int n = 20;
    int masiv[n];
    for(int i=0;i<n;i++){
        cin>>masiv[i];
    }

    for(int i=0;i<n;i++){
        int indexNaNaiMalko = i;
        int zapomnqne;
        for(int j=i+1;j<n;j++){
            if(masiv[j] < masiv[indexNaNaiMalko]){
                indexNaNaiMalko = j;
            }
        }
        zapomnqne=masiv[indexNaNaiMalko];
        masiv[indexNaNaiMalko]=masiv[i];
        masiv[i]=zapomnqne;

    }
    for(int i=0;i<n;i++){
        cout<<masiv[i]<<" ";
    }

return 0;
}
