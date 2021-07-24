#include<iostream>
using namespace std;

int garazhA;
int garazhB;

int nachalo;

int priTolkova[20][20];

int broiNachiniZaParkirane(int poziciqNaA, int poziciqNaB){
    if(poziciqNaA == garazhA && poziciqNaB == garazhB){
        return 1;
    }
    if(poziciqNaB <= poziciqNaA){
        return 0;
    }
    if(poziciqNaA <= 0 || poziciqNaB <= 0){
        return 0;
    }

    if(priTolkova[poziciqNaA][poziciqNaB] > 1){
        return priTolkova[poziciqNaA][poziciqNaB];
    }

    int akoPremestimA = broiNachiniZaParkirane(poziciqNaA - 1, poziciqNaB);
    int akoPremestimB = broiNachiniZaParkirane(poziciqNaA, poziciqNaB - 1);

    int sborche = akoPremestimA + akoPremestimB;

    priTolkova[poziciqNaA][poziciqNaB] = sborche;
    return sborche;
}

int main(){
    cin>>garazhA>>garazhB>>nachalo;

    int razlichniNachini = broiNachiniZaParkirane(nachalo - 1, nachalo);

    cout<<razlichniNachini<<endl;

    return 0;
}
