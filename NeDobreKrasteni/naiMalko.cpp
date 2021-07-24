#include <iostream>
using namespace std;
int main(){
    int n,naiMalko,naKoqPoziciq=0;
    cin>>n;
    int masiv[n];
    for(int b=0;b<n;b++){
        cin>>masiv[b];
    }
    naiMalko=masiv[0];
    for(int b=0;b<n;b++){
        if(masiv[b]<naiMalko){
            naiMalko=masiv[b];
            naKoqPoziciq=b;
        }
    }
    cout<<naiMalko<<" "<<naKoqPoziciq;

    return 0;
}
