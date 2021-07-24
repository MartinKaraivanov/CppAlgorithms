#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int BroiCifri(int x) {
    long long broiCifriDaljina=0;
    while(x>0){
        x=x/10;
        broiCifriDaljina++;
    }
    return broiCifriDaljina;

}


bool poNapred(long long a, long long b){
    if(BroiCifri(a)>BroiCifri(b)){
        return true;
    }
    if(BroiCifri(a)<BroiCifri(b)){
        return false;
    }
    if(BroiCifri(a)==BroiCifri(b)){
        if(a>b){
            return false;
        }else{
            return true;
        }
    }
}

int main(){
    long long dyljina;
    cin>>dyljina;
    long long chisla[dyljina];
    for(int i=0;i<dyljina;i++){
        cin>>chisla[i];
    }
    sort(chisla,chisla+dyljina,poNapred);
    for(int i=0;i<dyljina;i++){
        cout<<chisla[i]<<" ";
    }

    return 0;
}
