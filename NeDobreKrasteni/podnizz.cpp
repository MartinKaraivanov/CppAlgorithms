#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char nizA[1001];
    char nizB[1001];
    cin>>nizA>>nizB;
    long long broeveNaBukviOtA[256];
    long long broeveNaBukviOtB[256];
    long long daljinaA;
    long long daljinaB;

    daljinaA=strlen(nizA);
    daljinaB=strlen(nizB);

    for(int i=0;i<256;i++){
        broeveNaBukviOtA[i]=0;
        broeveNaBukviOtB[i]=0;
    }

    for(int i=0;i<daljinaA;i++){
        broeveNaBukviOtA[nizA[i]]++;
    }
    for(int i=0;i<daljinaB;i++){
        broeveNaBukviOtB[nizB[i]]++;
    }

    for(char bukva='a';bukva<='z';bukva++){
        int broiZaPechataneOtTaziBukva = 0;

        if(broeveNaBukviOtA[bukva]>broeveNaBukviOtB[bukva]){
            broiZaPechataneOtTaziBukva=broeveNaBukviOtB[bukva];
        }else{
            broiZaPechataneOtTaziBukva=broeveNaBukviOtA[bukva];
        }

        for(int j=0;j<broiZaPechataneOtTaziBukva;j++){
            cout<<bukva;
        }
    }
    cout<<endl;

    return 0;
}
