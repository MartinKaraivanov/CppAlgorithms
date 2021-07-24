#include<iostream>
using namespace std;

unsigned long long nod(unsigned long long a, unsigned long long b){
    while(a!=0 && b!=0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0){
        return b;
    }
    return a;


}

unsigned long long nok(unsigned long long a,unsigned long long b){
    return (a*b)/nod(a,b);
}

int main(){
    int n;
    cin>>n;

    unsigned long long naiMalkoObshtoKratno=2;

    for(unsigned long long i=3;i<=n;i++){
        naiMalkoObshtoKratno=nok(naiMalkoObshtoKratno,i);
    }

    unsigned long long cqlaChast=1;

    unsigned long long znamenatel=naiMalkoObshtoKratno;

    unsigned long long sbor=0;
    for(unsigned long long i=2;i<=n;i++){
        sbor+=znamenatel/i;

        while(sbor>znamenatel){
            sbor-=znamenatel;
            cqlaChast++;
        }
    }

    unsigned long long chislitel=sbor;

    unsigned long long naiGolqmObshtDelitel=nod(chislitel,znamenatel);

    if(naiGolqmObshtDelitel>1){
        znamenatel/=naiGolqmObshtDelitel;
        chislitel/=naiGolqmObshtDelitel;
    }

    cout<<cqlaChast<<" "<<chislitel<<" "<<znamenatel<<endl;

    chislitel=sbor;


    return 0;
}
