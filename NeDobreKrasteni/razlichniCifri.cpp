#include<iostream>
using namespace std;

bool sRazlichniCifriLiE(int n){
    bool sRazlCifriLiE=true;
    bool polzvaliLiSmeCifrata[10];

    for(int i=0;i<10;i++){
        polzvaliLiSmeCifrata[i]=false;
    }

    while(n>0){
        int cifra=n%10;

        if(polzvaliLiSmeCifrata[cifra]==true){
            sRazlCifriLiE=false;
            break;
        }else{
            polzvaliLiSmeCifrata[cifra]=true;
        }

        n/=10;
    }

    return sRazlCifriLiE;

    }

int main(){
    int parvo;
    int kraino;
    cin>>parvo>>kraino;

    int broi=0;
    for(int i=parvo;i<=kraino;i++){
        int kloningNaI=i;
        if(sRazlichniCifriLiE(kloningNaI)==true){
            broi++;
        }
    }

    cout<<broi<<endl;

    return 0;
}
