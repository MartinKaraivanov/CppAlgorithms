#include<iostream>
using namespace std;

int dalzhina;
int doKoeChisloMozhe;

long long brRedici[100][100];

void popalni(){

    for(int broiChlenove=1;broiChlenove<=dalzhina;broiChlenove++){
        for(int broiChisla=1;broiChisla<=doKoeChisloMozhe;broiChisla++){
            if(broiChlenove==broiChisla){
                brRedici[broiChlenove][broiChisla]=1;
            }else{
                if(broiChlenove>broiChisla){
                    brRedici[broiChlenove][broiChisla]=0;
                }else{
                    if(broiChlenove==1){
                        brRedici[broiChlenove][broiChisla]=broiChisla;
                    }else{
                        long long broiRed=0;
                        for(int chisloZaPosledenElement=1;chisloZaPosledenElement<=broiChisla;chisloZaPosledenElement++){
                            broiRed += brRedici[broiChlenove-1][chisloZaPosledenElement-1];
                        }
                        brRedici[broiChlenove][broiChisla]=broiRed;
                    }
                }
            }
        }
    }
}

int main(){
    cin>>doKoeChisloMozhe>>dalzhina;

    popalni();

    long long broiNaRedicite=brRedici[dalzhina][doKoeChisloMozhe];

    cout<<broiNaRedicite<<endl;

    return 0;
}
