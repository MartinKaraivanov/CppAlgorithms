#include<iostream>
using namespace std;

long long nachalenBroiEd;
long long maksimalnoChislo;

long long priTakuvBroiRedici[60];

long long broiRedicic(long long sbor){
    if(sbor == 0){
        return 1;
    }

    if(sbor < 0){
        return 0;
    }

    if(priTakuvBroiRedici[sbor] > -1){
        return priTakuvBroiRedici[sbor];
    }

    long long broiche = 0;

    for(long long i = 1; i <= maksimalnoChislo; i++){
        broiche += broiRedicic(sbor - i);
    }

    priTakuvBroiRedici[sbor] = broiche;
    return broiche;
}

int main(){
    cin>>nachalenBroiEd>>maksimalnoChislo;

    for(long long i = 0; i < 60; i++){
        priTakuvBroiRedici[i] = -1;
    }

    long long broiKompresii = broiRedicic(nachalenBroiEd);

    cout<<broiKompresii<<endl;

    return 0;
}
