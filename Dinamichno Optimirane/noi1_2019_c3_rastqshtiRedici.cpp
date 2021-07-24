#include<iostream>
using namespace std;

int dalzhina;
int doKoeChisloMozhe;

long long brRedici[100][100];

void zapalvane(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            brRedici[i][j]=-1;
        }
    }
}

long long BroiRedici(int broiChlenove, int minChislo){
    if(broiChlenove==1){
        if(doKoeChisloMozhe>=minChislo){
            return (doKoeChisloMozhe-minChislo)+1;
        }else{
            return 0;
        }
    }

    if(brRedici[broiChlenove][minChislo]!=-1){
        return brRedici[broiChlenove][minChislo];
    }

    long long broiRed=0;
    for(int i=minChislo;i<doKoeChisloMozhe;i++){
        broiRed+=BroiRedici(broiChlenove-1,i+1);
    }

    brRedici[broiChlenove][minChislo]=broiRed;
    return broiRed;
}

int main(){
    zapalvane();
    cin>>doKoeChisloMozhe>>dalzhina;

    long long broiNaRedicite=BroiRedici(dalzhina, 1);

    cout<<broiNaRedicite<<endl;

    return 0;
}
