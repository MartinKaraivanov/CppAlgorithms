#include<iostream>
using namespace std;

int chislo[2000];
int broiCifri;

bool endaklviLiSaCifriteNaToziIndexOtZadNapredIOtpPredNazad(int index){
    if(chislo[index]==chislo[(broiCifri-index)+1]){
        return true;
    }else{
        return false;
    }
}

int main(){
    char cifra;

    while(cin>>cifra){
        chislo[broiCifri]=cifra-'0';
        broiCifri++;
    }




    return 0;
}
