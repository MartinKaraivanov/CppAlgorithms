#include<iostream>
using namespace std;

long long chisla[100001];
long long akoParvotoEPoDVE[100001];
long long akoParvotoEPoTRI[100001];

int main(){
    long long reicinka;
    int i=0;
    while(cin>>reicinka){
        chisla[i]=reicinka;
        i++;
    }

    long long sborAkoParvotoETRI=0;

    for(int b=0;b<i;b++){
        if(b%2==0){
            akoParvotoEPoTRI[b]=chisla[b]*3;
        }else{
            akoParvotoEPoTRI[b]=chisla[b]*2;
        }
        sborAkoParvotoETRI=sborAkoParvotoETRI+akoParvotoEPoTRI[b];
    }

    long long sborAkoParvotoEDVE=0;

    for(int b=0;b<i;b++){
        if(b%2==0){
            akoParvotoEPoDVE[b]=chisla[b]*2;
        }else{
            akoParvotoEPoDVE[b]=chisla[b]*3;
        }
        sborAkoParvotoEDVE=sborAkoParvotoEDVE+akoParvotoEPoDVE[b];
    }

    if(sborAkoParvotoEDVE>sborAkoParvotoETRI){
        cout<<sborAkoParvotoEDVE;
    }else{
        cout<<sborAkoParvotoETRI;
    }

    return 0;
}
