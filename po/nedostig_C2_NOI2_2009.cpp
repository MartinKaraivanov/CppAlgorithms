#include<iostream>
#include<cstring>
using namespace std;

string duma;

bool palindromLiE(int otKade, int doKade){
    for(int k=otKade;k<=doKade;k++){
        if(duma[k]!=duma[doKade-(k-otKade)]){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>duma;

    if(palindromLiE(0, duma.size()-1)==true){
        cout<<0<<endl;;
        return 0;
    }

    int naiDalagPalindrom=0;

    int krai=duma.size()-1;
    for(int j=0;j<duma.size();j++){
        if(palindromLiE(j, krai)==true){
            naiDalagPalindrom=krai-j+1;
            cout<<duma.size()-naiDalagPalindrom<<endl;
            return 0;
        }
    }

    return 0;
}
