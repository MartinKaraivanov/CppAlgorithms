#include<iostream>
using namespace std;

int lenta[100];
int broiCifri;

unsigned long long chisloOtDo(int nachIdx, int kraenIdx){
    unsigned long long chislo=0;

    if(nachIdx<=kraenIdx){
        for(int i=nachIdx;i<=kraenIdx;i++){
            chislo=chislo*10+lenta[i];
        }
    }else{
        for(int i=nachIdx+1;i<broiCifri;i++){
            chislo=chislo*10+lenta[i];
        }
        for(int i=0;i<kraenIdx;i++){
            chislo=chislo*10+lenta[i];
        }
    }
    return chislo;
}

unsigned long long chisloOtDoDve(int nachIdx, int kraenIdx){
    unsigned long long chislo=0;

    if(nachIdx<kraenIdx){
        for(int i=nachIdx;i<=kraenIdx;i++){
            chislo=chislo*10+lenta[i];
        }
    }else{
        for(int i=nachIdx+1;i<broiCifri;i++){
            chislo=chislo*10+lenta[i];
        }
        for(int i=0;i<kraenIdx;i++){
            chislo=chislo*10+lenta[i];
        }
    }
    return chislo;
}

int main(){
    char simvol;

    while(cin>>simvol){
        if((simvol>='0') && (simvol<='9')){
            lenta[broiCifri]=simvol-'0';
            broiCifri++;
        }
    }

    unsigned long long naiGolqmResultat=0;
    unsigned long long naiGolqmoParvo=0;
    unsigned long long naiGolqmoVtoro=0;

    for(int parviIndex=0;parviIndex<broiCifri;parviIndex++){
        for(int kraenIndex=parviIndex;kraenIndex<broiCifri;kraenIndex++){
            unsigned long long parvoChislo=chisloOtDo(parviIndex, kraenIndex);
            unsigned long long vtoroChislo=chisloOtDoDve(kraenIndex, parviIndex);
            unsigned long long proizvedenie=parvoChislo*vtoroChislo;
            if(proizvedenie>naiGolqmResultat){
                naiGolqmResultat=proizvedenie;
                naiGolqmoParvo=parvoChislo;
                naiGolqmoVtoro=vtoroChislo;
            }
        }
    }

    cout<<naiGolqmResultat<<endl;

    return 0;
}
