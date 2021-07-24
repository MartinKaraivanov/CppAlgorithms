#include<iostream>
using namespace std;
int main(){
    int koqCifra;
    unsigned long long doKoe;

    cin>>koqCifra>>doKoe;

    unsigned long long kolkoPatiSeSreshta=0;
    for(unsigned long long i=0;i<=doKoe;i++){
        unsigned long long kopieNaI=i;

        while(kopieNaI>0){
            if(kopieNaI%10==koqCifra){
                kolkoPatiSeSreshta++;
            }
            kopieNaI/=10;
        }

    }

    if(koqCifra!=0){
        cout<<kolkoPatiSeSreshta<<endl;
    }else{
        cout<<kolkoPatiSeSreshta+1<<endl;
    }


    return 0;
}
