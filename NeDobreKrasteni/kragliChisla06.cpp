#include<iostream>
#include<stack>
using namespace std;
int main(){
    long long koiChlenNaRedicata;
    cin>>koiChlenNaRedicata;

    long long chislo=koiChlenNaRedicata-1;

    stack <long long> dvoichnoChislo;

    if(chislo==0){
        cout<<0;
    }else{

        while(chislo>=1){
            int ostatak=chislo%2;
            dvoichnoChislo.push(ostatak);
            chislo/=2;
        }

        while(dvoichnoChislo.empty()==false){
            int chisloZaOtpechatvane=dvoichnoChislo.top();
            dvoichnoChislo.pop();
            if(chisloZaOtpechatvane==0){
                cout<<0;
            }else{
                cout<<6;
            }
        }
    }

    cout<<endl;

    return 0;
}
