#include<iostream>
using namespace std;

int plateno;

int kolkoQbalki(int parichki){
    if(parichki == 1){
        return 1;
    }
    if(parichki == 2){
        return 2;
    }
    if(parichki%3==0){
        int kolichestvoQbalki = 1 + 3*kolkoQbalki(parichki/3);
        return kolichestvoQbalki;
    }
    if(parichki%3==1){
        int kolichestvoQbalki = 1 + kolkoQbalki(parichki - 1);
        return kolichestvoQbalki;
    }
    if(parichki%3==2){
        int kolichestvoQbalki = 2 + kolkoQbalki(parichki - 2);
        return kolichestvoQbalki;
    }
    return 0;
}

int main(){
    cin>>plateno;

    int kolkoQbalkiTrqbvaDaDadem = kolkoQbalki(plateno);

    cout<<kolkoQbalkiTrqbvaDaDadem<<endl;

    return 0;
}
