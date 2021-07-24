#include<iostream>
using namespace std;
int main(){
    long long cifraZaTyrsene;
    long long doKoeChislo;
    cin>>cifraZaTyrsene>>doKoeChislo;

    long long brPatiSreshta=0;
    long long chislo=0;
    long long chisloZaDeistviq;

    while(chislo<=doKoeChislo){
        chisloZaDeistviq=chislo;
        while(chisloZaDeistviq>0){
            if((chisloZaDeistviq%10==cifraZaTyrsene) ){
                brPatiSreshta++;
            }
            chisloZaDeistviq=chisloZaDeistviq/10;
        }
        chislo++;
    }

    if(cifraZaTyrsene==0){
        cout<<brPatiSreshta+1;
    }else{
        cout<<brPatiSreshta;
    }

    return 0;
}
