#include<iostream>
using namespace std;
int main(){
    char parviChasovnik[6];
    char vtoriChasovnik[6];

    cin>>parviChasovnik>>vtoriChasovnik;

    int chasParvi=10*(parviChasovnik[0]-'0')+(parviChasovnik[1]-'0');
    int minutiParvi=10*(parviChasovnik[3]-'0')+(parviChasovnik[4]-'0');
    int chasVtori=10*(vtoriChasovnik[0]-'0')+(vtoriChasovnik[1]-'0');
    int minutiVtori=10*(vtoriChasovnik[3]-'0')+(vtoriChasovnik[4]-'0');

    int trqbvashtChas;
    int trqbvashtiMinuti;

    if(minutiVtori-minutiParvi>=0){
        trqbvashtiMinuti=minutiVtori-minutiParvi;
    }else{
        trqbvashtiMinuti=60+minutiVtori-minutiParvi;
        chasVtori--;
    }

    if(chasVtori-chasParvi>=0){
        trqbvashtChas=chasVtori-chasParvi;
    }else{
        trqbvashtChas=24+chasVtori-chasParvi;
    }

    if(trqbvashtChas<10){
        cout<<0<<trqbvashtChas<<":";
    }else{
        cout<<trqbvashtChas<<":";
    }

    if(trqbvashtiMinuti<10){
        cout<<0<<trqbvashtiMinuti<<endl;
    }else{
        cout<<trqbvashtiMinuti<<endl;
    }


    return 0;
}
