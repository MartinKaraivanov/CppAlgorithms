#include<iostream>
#include<cmath>
using namespace std;

int chisla[10000000];
int broiChisla;

int main(){
    int dadenoChislo;
    int p;

    cin>>dadenoChislo>>p;

    cout<<1<<endl;
    chisla[broiChisla]=1;
    broiChisla++;

    for(int i=1;true;i++){
        int chisloto=pow(p, i);

        if(chisloto<=dadenoChislo){
            cout<<chisloto<<endl;
            chisla[broiChisla]=chisloto;
        }else{
            break;
        }

        int brChisla=broiChisla;
        broiChisla++;
        bool daSeMahnaLi=false;

        for(int j=0;j<brChisla;j++){
            int novoCh=chisloto+chisla[j];
            if(novoCh<=dadenoChislo){
                cout<<novoCh<<endl;
                chisla[broiChisla]=novoCh;
                broiChisla++;
            }else{
                daSeMahnaLi=true;
                break;
            }
        }
        if(daSeMahnaLi==true){
            break;
        }
    }


    return 0;
}
