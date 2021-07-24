#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    long long broiGrupi;
    cin>>broiGrupi;

    string vlizane[broiGrupi];
    string izlizane[broiGrupi];

    for(int i=0;i<broiGrupi;i++){
        cin>>vlizane[i]>>izlizane[i];
    }

    sort(vlizane,vlizane+broiGrupi);
    sort(izlizane,izlizane+broiGrupi);

    long long horaNavednazhVatre=0;
    long long naiMnogoHora=0;
    long long i=0;
    long long j=0;

    while((i<broiGrupi)||(j<broiGrupi)){
        if(vlizane[i]<=izlizane[j]){
            horaNavednazhVatre++;
            i++;
        }else{
            horaNavednazhVatre--;
            j++;
        }

        if(horaNavednazhVatre>naiMnogoHora){
            naiMnogoHora=horaNavednazhVatre;
        }
    }

    cout<<naiMnogoHora;

    return 0;
}
