#include<iostream>
using namespace std;

int takivaChislaKakvitoTrqbva[10000];
int broiTakivaChisla;

int main(){
    int chislo;
    cin>>chislo;

    for(int i=10000;i<100000;i++){
        int chislence=i;
        int edinici=chislence%10;
        chislence/=10;
        int desitici=chislence%10;
        chislence/=10;
        int stotici=chislence%10;
        chislence/=10;
        int hilqdni=chislence%10;
        chislence/=10;
        int desetohilqdni=chislence%10;

        if((desetohilqdni+stotici==hilqdni) && (stotici+edinici==desitici) ){
            takivaChislaKakvitoTrqbva[broiTakivaChisla]=i;
            broiTakivaChisla++;
        }

    }

    for(int i=0;i<broiTakivaChisla;i++){
        if(takivaChislaKakvitoTrqbva[i]==chislo){
            cout<<i+1<<endl;
            return 0;
        }
    }

    cout<<0<<endl;


    return 0;
}
