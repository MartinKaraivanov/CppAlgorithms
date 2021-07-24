#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char vhod[31],hiks,plyus,ravno;
    long long sabiraemo,sbor,daljina,cifri,poziciqNaPlus,poziciqNaRavno,hiksat;
    bool daliEparvoX=false;
    cin>>vhod;
    hiks='X';
    plyus='+';
    ravno='=';
    daljina=strlen(vhod);
    for(int i=0;i<daljina;i++){
        if(vhod[0]==hiks){
            daliEparvoX=true;
        }
        if(vhod[i]==plyus){
            poziciqNaPlus=i;
        }
        if(vhod[i]==ravno){
            poziciqNaRavno=i;
        }
    }

    sbor=0;
    for(int i=poziciqNaRavno+1;i<daljina;i++){
        sbor=10*sbor+(vhod[i]-'0');
    }
    sabiraemo=0;
    if(vhod[0]=='X'){
        for(int i=2;i<poziciqNaRavno;i++){
            sabiraemo=10*sabiraemo+(vhod[i]-'0');
        }
    }else{
        for(int i=0;i<poziciqNaPlus;i++){
            sabiraemo=10*sabiraemo+(vhod[i]-'0');
        }

    }


    cout<<sbor-sabiraemo;

    //cout<<daliEparvoX<<" "<<poziciqNaPlus<<" "<<poziciqNaRavno;


    return 0;
}
