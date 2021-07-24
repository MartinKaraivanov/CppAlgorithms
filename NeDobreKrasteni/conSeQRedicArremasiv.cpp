#include<iostream>
using namespace std;

int broiCifri;
int chisloZaTableta[1000001];

void umnojiPo(int a){
    int prenos=0;
    for(int i=0;i<broiCifri;i++){
        int proizvedenie=chisloZaTableta[i]*a + prenos;
        chisloZaTableta[i]=proizvedenie%10;
        prenos=proizvedenie/10;
    }
    while(prenos>0){
        broiCifri++;
        chisloZaTableta[broiCifri-1]=prenos%10;
        prenos/=10;
    }
}

int kolkoCifrenoEChisloto(){
    return broiCifri;
}

int koqECifrataNaTaziPoziciqOtDqsnoNalqvo(int poziciq){
    return chisloZaTableta[poziciq-1];
}


int koqECifrataNaTaziPoziciqOtLqwoNadqsno(int poziciq){
    return koqECifrataNaTaziPoziciqOtDqsnoNalqvo(kolkoCifrenoEChisloto()-(poziciq-1));
}


int main(){
    int poKolkoDaUmnozhavam;
    int koiElement;
    cin>>poKolkoDaUmnozhavam>>koiElement;

    int i=0;

    broiCifri=1;
    chisloZaTableta[0]=1;

    while(i<=koiElement){
        int brCifriNaDAdenotoChislo;
        brCifriNaDAdenotoChislo=kolkoCifrenoEChisloto();
        if(i+brCifriNaDAdenotoChislo>=koiElement){
            cout<<koqECifrataNaTaziPoziciqOtLqwoNadqsno(koiElement-i);
            break;
        }
        i=i+brCifriNaDAdenotoChislo;
        umnojiPo(poKolkoDaUmnozhavam);
    }

    return 0;
}
