#include<iostream>
using namespace std;

bool samoSNuliIEdiniciLiE (int chislo, int broiSistema){
    bool samo01liIma=true;
    int kopiranoChislo=chislo;
    while(kopiranoChislo>0){
        int ostatak=kopiranoChislo%broiSistema;
        if((ostatak!=0) && (ostatak!=1) ){
            samo01liIma=false;
            break;
        }
        kopiranoChislo/=broiSistema;
    }

    if(samo01liIma==true){
        return true;
    }else{
        return false;
    }
}

int main(){
    int doKoeChislo;
    int koqBroinaSistema;

    cin>>doKoeChislo>>koqBroinaSistema;

    for(int i=1;i<=doKoeChislo;i++){
        if(samoSNuliIEdiniciLiE(i, koqBroinaSistema)==true){
            cout<<i<<endl;
        }
    }

    return 0;
}
