#include<iostream>
using namespace std;

int cifriNaChislo[1500];
int broiCifri;

int drugoChislo[1500];

void sazdavaneNaPalindrom(){
    if(broiCifri%2==0){
        for(int i=0;i<broiCifri/2;i++){
            drugoChislo[i]=cifriNaChislo[i];
            drugoChislo[broiCifri-i-1]=cifriNaChislo[i];
        }
    }else{
        for(int i=0;i<broiCifri/2+1;i++){
            drugoChislo[i]=cifriNaChislo[i];
            drugoChislo[broiCifri-i-1]=cifriNaChislo[i];
        }
    }
}

bool poGoqmoLiE(){
    for(int i=0;i<broiCifri;i++){
        if(drugoChislo[i]==cifriNaChislo[i]){
            continue;
        }else{
            if(drugoChislo[i]>cifriNaChislo[i]){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

void pravene(){
    bool napraviliLiSmePromqna=false;
    if(broiCifri%2==0){
        int indexChe=broiCifri/2-1;
        while(napraviliLiSmePromqna==false){
            if(cifriNaChislo[indexChe]<9){
                cifriNaChislo[indexChe]++;
                napraviliLiSmePromqna=true;
            }else{
                cifriNaChislo[indexChe]=0;
                if(cifriNaChislo[indexChe-1]<9){
                    cifriNaChislo[indexChe-1]++;
                    napraviliLiSmePromqna=true;
                }else{
                    indexChe--;
                }
            }
        }
    }else{
        int indexChe=broiCifri/2;
        while(napraviliLiSmePromqna==false){
            if(cifriNaChislo[indexChe]<9){
                cifriNaChislo[indexChe]++;
                napraviliLiSmePromqna=true;
            }else{
                cifriNaChislo[indexChe]=0;
                if(cifriNaChislo[indexChe-1]<9){
                    cifriNaChislo[indexChe-1]++;
                    napraviliLiSmePromqna=true;
                }else{
                    indexChe--;
                }
            }
        }
    }
}

int main(){
    char simvol;

    while(cin>>simvol){
        cifriNaChislo[broiCifri]=simvol-'0';
        broiCifri++;
    }

    bool vsichki9kiLiSa=true;
    for(int i=0;i<broiCifri;i++){
        if(cifriNaChislo[i]!=9){
            vsichki9kiLiSa=false;
            break;
        }
    }

    if(vsichki9kiLiSa==true){
        cout<<1;
        for(int i=0;i<broiCifri-1;i++){
            cout<<0;
        }
        cout<<1<<endl;
        return 0;
    }

    sazdavaneNaPalindrom();

    if(poGoqmoLiE()==false){
        pravene();
        sazdavaneNaPalindrom();
    }

    for(int i=0;i<broiCifri;i++){
        cout<<drugoChislo[i];
    }

    cout<<endl;

    return 0;
}
