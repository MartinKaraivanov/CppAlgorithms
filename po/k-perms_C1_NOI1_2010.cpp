#include<iostream>
#include<cmath>
using namespace std;

int doKolko;
int k;

int brKPerm;

int chislo[200];
bool polzvaliLiSmeGi[200];

void otpechatvane(int n){
    for(int i=0;i<n;i++){
        cout<<chislo[i];
    }
    cout<<endl;
}

void nCifreniChisla(int n, int doKoiElementSmeStignali){
    if(doKoiElementSmeStignali==n){
        brKPerm++;
    }else{
        for(int i=1;i<=doKolko;i++){
            if(polzvaliLiSmeGi[i]==false){
                if(abs(chislo[max(0, doKoiElementSmeStignali-1)]-i)<=k){
                    chislo[doKoiElementSmeStignali]=i;
                    polzvaliLiSmeGi[i]=true;
                    nCifreniChisla(n, doKoiElementSmeStignali+1);
                    polzvaliLiSmeGi[i]=false;
                }
            }
        }
    }
}

int main(){
    cin>>doKolko>>k;

    nCifreniChisla(doKolko, 0);

    cout<<brKPerm<<endl;

    return 0;
}
