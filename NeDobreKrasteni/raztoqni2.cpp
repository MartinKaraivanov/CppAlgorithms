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
    long long daljina,parvoChislo,vtoroChislo,raztoqnie,namerihParvo,namerihVtoro;
    cin>>daljina>>parvoChislo>>vtoroChislo;
    long long masiv[daljina];
    for(int i=0;i<daljina;i++){
        cin>>masiv[i];
    }
    raztoqnie=1000000;
    namerihParvo=-2*500000;
    namerihVtoro=2*500000;
    for(int i=0;i<daljina;i++){
        if(masiv[i]==parvoChislo){
            namerihParvo=i;
        }
        if(masiv[i]==vtoroChislo){
            namerihVtoro=i;
        }
        int novoRazstoqnie=abs(namerihParvo-namerihVtoro);
        if(novoRazstoqnie<raztoqnie){
            raztoqnie=novoRazstoqnie;
        }
    }
    cout<<raztoqnie;

    return 0;
}
