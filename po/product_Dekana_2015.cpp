#include<iostream>
using namespace std;

const int broiProsti=8;
int prosti[broiProsti]={2, 3, 5, 7 , 11, 13, 17, 19};

bool haresvaLiNiTovaChislo(unsigned long long chi){
    int i=0;

    while(chi>1){
        if(i==broiProsti){
            return false;
        }
        if(chi%prosti[i]==0){
            chi/=prosti[i];
        }else{
            i++;
        }
    }

    return true;
}

int main(){
    unsigned long long chislo;

    cin>>chislo;

    unsigned long long m=chislo;
    unsigned long long g=chislo;

    while(true){
        if(haresvaLiNiTovaChislo(m)==true){
            cout<<m<<endl;
            break;
        }
        if(haresvaLiNiTovaChislo(g)==true){
            cout<<g<<endl;
            break;
        }
        m--;
        g++;
    }

    return 0;
}
