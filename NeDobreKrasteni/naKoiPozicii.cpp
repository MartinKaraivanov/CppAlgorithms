#include<iostream>
using namespace std;
int abs(int x){
    if(x<0){
        return x*-1;
    }else{
        return x;
    }

}
int main(){
    int dyljina,stoinostZaTyrsene,drugaStoinostZaTyrsene;
    cin>>dyljina>>stoinostZaTyrsene>>drugaStoinostZaTyrsene;
    int masiv[dyljina];
    for(int i=0;i<dyljina;i++){
        cin>>masiv[i];
    }

    int naiMalko=500000;
    for(int i=0;i<dyljina;i++){
        if(stoinostZaTyrsene==masiv[i]){
            for(int j=0;j<dyljina;j++){
                if(drugaStoinostZaTyrsene==masiv[j]){
                    if(abs(i-j)<naiMalko){
                        naiMalko=abs(i-j);
                    }
                    cout<<i<<" "<<j<<" -> "<<abs(i-j)<<endl;

                }
            }
        }
    }
    cout<<naiMalko;
    cout<<endl;

    return 0;
}
