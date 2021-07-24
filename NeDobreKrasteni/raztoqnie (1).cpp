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
    int daljina,parvoChislo,vtoroChislo,raztoqnie=0,namerihParvo=0,namerihVtoro=0,naiMalkoRazst=1000;
    cin>>daljina>>parvoChislo>>vtoroChislo;
    int masiv[daljina];
    for(int i=0;i<daljina;i++){
        cin>>masiv[i];
    }
    for(int i=0;i<daljina;i++){
        if(masiv[i]==parvoChislo){
            namerihParvo=i;
        }
        if(masiv[i]==vtoroChislo){
            namerihVtoro=i;
        }

    }
    raztoqnie=abs(namerihParvo-namerihVtoro);
    cout<<raztoqnie;

    return 0;
}
