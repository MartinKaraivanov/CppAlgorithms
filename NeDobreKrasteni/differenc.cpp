#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool poGolqmoChislo(long long a, long long b){
    if(a>b){
        return true;
    }else{
        return false;
    }
}
bool poMalkoChislo(long long a, long long b){
    if(a<b){
        return true;
    }else{
        return false;
    }
}

int main(){
    char chislo[20];
    cin>>chislo;

    long long razlika,daljina;
    daljina=strlen(chislo);
    long long parvo[daljina],vtoro[daljina];

    for(int i=0;i<daljina;i++){
        parvo[i]=chislo[i]-'0';
    }
    for(int i=0;i<daljina;i++){
        vtoro[i]=chislo[i]-'0';
    }


    sort(parvo,parvo+daljina,poGolqmoChislo);
    sort(vtoro,vtoro+daljina,poMalkoChislo);

    if(vtoro[0]==0){
        for(int i=0;i<daljina;i++){
            if(vtoro[i]!=0){
                swap(vtoro[0],vtoro[i]);
                break;
            }
        }
    }

    long long parvoChislo=0;
    for(int i=0;i<daljina;i++){
        parvoChislo=10*parvoChislo+parvo[i];
    }

    long long vtoroChislo=0;
    for(int i=0;i<daljina;i++){
        vtoroChislo=10*vtoroChislo+vtoro[i];
    }

    razlika=parvoChislo-vtoroChislo;
    cout<<razlika;

    return 0;
}
