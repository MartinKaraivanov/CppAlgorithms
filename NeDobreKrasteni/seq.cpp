#include<iostream>
#include<math.h>
using namespace std;


long long kolkoCifrenoEChisloto(long double a){
    long long brCifri=0;
    while(a>0){
        a= trunc(a/10);
        brCifri++;
    }

    //cout<<brCifri<<" ";

    return brCifri;

    //return trunc(log10(a))+1;
}

long long koqECifrataNaTaziPoziciqOtDqsnoNalqvo(long double chisloto,  long long poziciq){
    long long i=1;
    while(i<poziciq){
        chisloto=trunc(chisloto/10);
        i++;
    }
    return fmod(chisloto, 10);
}


long long koqECifrataNaTaziPoziciqOtLqwoNadqsno(long double chislo, long long poziciq){
    return koqECifrataNaTaziPoziciqOtDqsnoNalqvo(chislo, kolkoCifrenoEChisloto(chislo)-(poziciq-1) );
}


int main(){
    long long poKolkoDaUmnozhavam;
    long long koiElement;
    cin>>poKolkoDaUmnozhavam>>koiElement;

    long long i=0;
    long double chisloZaTaziStepen=1;
    while(i<=koiElement){
        long long brCifriNaDAdenotoChislo;
        brCifriNaDAdenotoChislo=kolkoCifrenoEChisloto(chisloZaTaziStepen);
        if(i+brCifriNaDAdenotoChislo>=koiElement){
            cout<<koqECifrataNaTaziPoziciqOtLqwoNadqsno(chisloZaTaziStepen,koiElement-i);
            break;
        }
        i=i+brCifriNaDAdenotoChislo;
        chisloZaTaziStepen=chisloZaTaziStepen*poKolkoDaUmnozhavam;
    }

    return 0;
}
