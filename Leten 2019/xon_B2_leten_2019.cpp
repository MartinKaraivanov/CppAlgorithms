#include<iostream>
using namespace std;

unsigned long long n;
unsigned long long m;

unsigned long long smqtaneNaStepeniteIVrashtane(unsigned long long chislo, unsigned long long stepen){
    unsigned long long res = 1;
    unsigned long long chislotoPovdignatoNaStepenNaDvoikata = chislo;

    for(unsigned long long stepenNaDvoikata = 1; stepenNaDvoikata <= stepen; stepenNaDvoikata = stepenNaDvoikata * 2){
        if((stepenNaDvoikata & stepen) != 0){
            res *= chislotoPovdignatoNaStepenNaDvoikata;
            res %= m;
        }
        chislotoPovdignatoNaStepenNaDvoikata *= chislotoPovdignatoNaStepenNaDvoikata;
        chislotoPovdignatoNaStepenNaDvoikata %= m;
    }

    /*for(unsigned long long i = 0; i < stepen; i++){
        s <<= 1;
        s %= m;
    }*/

    return res;
}

int main(){
    cin>>n>>m;

    unsigned long long s = smqtaneNaStepeniteIVrashtane(2, n + 1);

    s = s * 3;
    s %= m;

    unsigned long long nNaVtora = (n%m)*(n%m);
    nNaVtora %= m;

    s += m;
    s -= nNaVtora;
    s %= m;

    unsigned long long triN = (n % m)*3;
    triN %= m;

    s += m;
    s -= triN;
    s %= m;

    s += m;
    s -= 5;
    s %= m;

    cout<<s<<endl;

    return 0;
}
