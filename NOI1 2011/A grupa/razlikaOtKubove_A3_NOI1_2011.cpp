#include<iostream>
#include<cmath>
using namespace std;

long long parvoChislo;
long long vtoroChislo;

int main(){
    cin>>parvoChislo>>vtoroChislo;

    long long korenKvadratenOtParvoto = sqrt(parvoChislo);
    long long korenKvadratenOtVtoroto = sqrt(vtoroChislo);

    int a1 = -1;
    int b1 = -1;

    int a2 = -1;
    int b2 = -1;

    for(long long p = 1; p <= korenKvadratenOtParvoto + 1; p++){
        if(parvoChislo % p == 0){
            long long q = parvoChislo/p;

            long long bSPlus = (-3*p + sqrt(-3*p*p + 12*q))/6;
            long long bSMinus = (-3*p - sqrt(-3*p*p + 12*q))/6;

            long long aNabSPlus = p + bSPlus;
            long long aNabSMinus = p + bSMinus;

            if(aNabSPlus*aNabSPlus*aNabSPlus - bSPlus*bSPlus*bSPlus == parvoChislo){
                a1 = aNabSPlus;
                b1 = bSPlus;
                break;
            }

            if(aNabSMinus*aNabSMinus*aNabSMinus - bSMinus*bSMinus*bSMinus == parvoChislo){
                a1 = aNabSMinus;
                b1 = bSMinus;
                break;
            }

        }
    }

    for(long long p = 1; p <= korenKvadratenOtVtoroto + 1; p++){
        if(vtoroChislo % p == 0){
            long long q = vtoroChislo/p;

            long long bSPlus = (-3*p + sqrt(-3*p*p + 12*q))/6;
            long long bSMinus = (-3*p - sqrt(-3*p*p + 12*q))/6;

            long long aNabSPlus = p + bSPlus;
            long long aNabSMinus = p + bSMinus;

            if(aNabSPlus*aNabSPlus*aNabSPlus - bSPlus*bSPlus*bSPlus == vtoroChislo){
                a2 = aNabSPlus;
                b2 = bSPlus;
                break;
            }

            if(aNabSMinus*aNabSMinus*aNabSMinus - bSMinus*bSMinus*bSMinus == vtoroChislo){
                a2 = aNabSMinus;
                b2 = bSMinus;
                break;
            }

        }
    }

    if(a1 == -1 || b1 == -1){
        cout<<"NO"<<endl;
    }else{
        cout<<a1<<" "<<b1<<endl;
    }

    if(a2 == -1 || b2 == -1){
        cout<<"NO"<<endl;
    }else{
        cout<<a2<<" "<<b2<<endl;
    }

    return 0;
}
