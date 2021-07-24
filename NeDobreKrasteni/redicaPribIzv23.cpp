#include<iostream>
using namespace std;
int main(){
    int broiChisla;
    cin>>broiChisla;

    int chisla[broiChisla];
    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    int redicataAkoParvotoGoUmnozhavamePo2[broiChisla];
    int redicataAkoParvotoGoUmnozhavamePo3[broiChisla];

    for(int i=0;i<broiChisla;i++){
        if((i%2==0) || (i==0) ){
            redicataAkoParvotoGoUmnozhavamePo2[i]=chisla[i]*2;
        }else{
            redicataAkoParvotoGoUmnozhavamePo2[i]=chisla[i]*3;
        }
    }

    for(int i=0;i<broiChisla;i++){
        if((i%2==0) || (i==0) ){
            redicataAkoParvotoGoUmnozhavamePo3[i]=chisla[i]*3;
        }else{
            redicataAkoParvotoGoUmnozhavamePo3[i]=chisla[i]*2;
        }
    }

    int sboraNaRedicataAkoParvotoGoUmnozhavamePo2=0;
    int sboraNaRedicataAkoParvotoGoUmnozhavamePo3=0;

    for(int i=0;i<broiChisla;i++){
        sboraNaRedicataAkoParvotoGoUmnozhavamePo2+=redicataAkoParvotoGoUmnozhavamePo2[i];
    }

    for(int i=0;i<broiChisla;i++){
        sboraNaRedicataAkoParvotoGoUmnozhavamePo3+=redicataAkoParvotoGoUmnozhavamePo3[i];
    }

    if(sboraNaRedicataAkoParvotoGoUmnozhavamePo2>sboraNaRedicataAkoParvotoGoUmnozhavamePo3){
        cout<<sboraNaRedicataAkoParvotoGoUmnozhavamePo2;
    }else{
        cout<<sboraNaRedicataAkoParvotoGoUmnozhavamePo3;
    }

    return 0;
}
