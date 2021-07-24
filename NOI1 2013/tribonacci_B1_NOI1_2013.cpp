#include<iostream>
#include<cmath>
using namespace std;

int priDelenieNaKolko;

int main(){
    cin>>priDelenieNaKolko;

    int parvo = 0;
    int vtoro = 0;
    int treto = 1;

    int popredno = 0;
    int predno = 0;
    int segashno = 1;

    int stapka = 1;

    while(true){
        int sledvashto = (popredno + predno + segashno)%priDelenieNaKolko;
        if(predno == parvo && segashno == vtoro && sledvashto == treto){
            cout<<stapka<<endl;
            return 0;
        }
        stapka++;
        popredno = predno;
        predno = segashno;
        segashno = sledvashto;
    }


    return 0;
}
