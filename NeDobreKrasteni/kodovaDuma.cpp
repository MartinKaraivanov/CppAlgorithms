#include<iostream>
#include<cstring>
using namespace std;
int main(){
    long long broeve[256];

    for(int i=0;i<256;i++){
        broeve[i]=0;
    }

    char bukva=0;
    while(bukva!='#'){
        cin>>bukva;
        if((bukva>='A' && bukva<='Z') || (bukva>='a' && bukva<='z') ){
            if(bukva>='a' && bukva<='z'){
                bukva=toupper(bukva);
            }
            broeve[bukva]++;
        }
    }


    char resultat[6];
    for(int i=0;i<6;i++){
        resultat[i]=0;
    }
    for(int j=0;j<6;j++){
        long long naiMnogoPati=0;
        char naiMnogoPatiBukva=0;
        for(char ch='A';ch<'Z';ch++){
            if(naiMnogoPati<broeve[ch]){
                naiMnogoPati=broeve[ch];
                naiMnogoPatiBukva=ch;
            }
        }
        resultat[j]=naiMnogoPatiBukva;
        broeve[naiMnogoPatiBukva]=0;
    }

    for(int i=0;i<6;i++){
        if(resultat[i]!=0){
            cout<<resultat[i];
        }
    }

    return 0;
}
