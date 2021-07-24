#include<iostream>
using namespace std;

long long brRedici[100][100];

void zapalvane(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            brRedici[i][j]=-1;
        }
    }
}

long long BroiRedici(int otKolkoDaEPoMalakVsekiChlen, int brElementi, int otKolkoDaEPoMalkoSbora){
    if(brElementi==1){
        if(otKolkoDaEPoMalakVsekiChlen<=otKolkoDaEPoMalkoSbora){
            return otKolkoDaEPoMalakVsekiChlen;
        }else{
            return otKolkoDaEPoMalkoSbora;
        }
    }

    if(brRedici[brElementi][otKolkoDaEPoMalkoSbora]!=-1){
        return brRedici[brElementi][otKolkoDaEPoMalkoSbora];
    }

    long long broRedici=0;
    for(int izbranChlen=0;izbranChlen<otKolkoDaEPoMalakVsekiChlen;izbranChlen++){
        if(izbranChlen<otKolkoDaEPoMalkoSbora){
            broRedici+=BroiRedici(otKolkoDaEPoMalakVsekiChlen, brElementi-1,otKolkoDaEPoMalkoSbora-izbranChlen);
        }
    }

    brRedici[brElementi][otKolkoDaEPoMalkoSbora]=broRedici;
    return broRedici;
}

int main(){
    zapalvane();
    int otKolkoDaEPoMalakVsekiChlen;
    int broiSabiraemi;
    int otKolkoDaEPoMalkoSbora;

    cin>>otKolkoDaEPoMalakVsekiChlen>>broiSabiraemi>>otKolkoDaEPoMalkoSbora;

    long long broiRedichki = BroiRedici(otKolkoDaEPoMalakVsekiChlen, broiSabiraemi, otKolkoDaEPoMalkoSbora);

    cout<<broiRedichki;

    return 0;
}
