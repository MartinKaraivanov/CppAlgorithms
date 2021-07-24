#include<iostream>
using namespace std;

int stoinostNaCifrata(char cifra){
    if(cifra == 'I'){
        return 1;
    }
    if(cifra == 'V'){
        return 5;
    }
    if(cifra == 'X'){
        return 10;
    }
    if(cifra == 'L'){
        return 50;
    }
    if(cifra == 'C'){
        return 100;
    }
    if(cifra == 'D'){
        return 500;
    }
    if(cifra == 'M'){
        return 1000;
    }

    return -1;
}

int vDesetichna(string rimsko){

    int resultat = 0;

    for(int i = 0; i < (int)rimsko.size(); i++){
        int parvo = stoinostNaCifrata(rimsko[i]);

        if(i + 1 < (int)rimsko.size()){
            int vtoro = stoinostNaCifrata(rimsko[i + 1]);

            if(parvo >= vtoro){
                resultat +=  parvo;
            }else{
                resultat += vtoro - parvo;
                i++;
            }

        }else{
            resultat += parvo;
        }
    }

    return resultat;
}

int main(){
    string rimskoChislo;

    cin>>rimskoChislo;

    int arabsko = vDesetichna(rimskoChislo);

    cout<<arabsko<<endl;

    return 0;
}
