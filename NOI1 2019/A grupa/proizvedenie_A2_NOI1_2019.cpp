#include<iostream>
#include<cmath>
using namespace std;

long long broiTochki;

long long yNaTochkata[500010];

int main(){
    cin>>broiTochki;

    for(long long i = 1; i <= broiTochki; i++){
        cin>>yNaTochkata[i];
    }

    long long naiGolqmoto = 0;

    long long i = 1;
    long long j = broiTochki;

    while(i < j){
        long long zaTuk = (j - i)*min(yNaTochkata[i], yNaTochkata[j]);
        naiGolqmoto = max(naiGolqmoto, zaTuk);

        if(yNaTochkata[i] < yNaTochkata[j]){
            i++;
        }else{
            j--;
        }
    }

    cout<<naiGolqmoto<<endl;

    return 0;
}
