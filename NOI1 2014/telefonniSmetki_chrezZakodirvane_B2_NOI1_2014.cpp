#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int broiSmetki;
int broiPlateni;

int nePlateni[403000];

int main(){
    cin>>broiSmetki>>broiPlateni;

    for(int i = 0; i < broiSmetki; i++){
        double cenichka;
        cin>>cenichka;
        //cout<<"cenichkata: "<<cenichka;
        int kodovoIme = round(cenichka*100);
        //cout<<" kodovoto ime: "<<kodovoIme<<" a trqbva da e "<<cenichka*100<<endl;
        nePlateni[kodovoIme]++;
    }

    //cout<<endl<<"----------------"<<endl;

    for(int i = 0; i < broiPlateni; i++){
        double platena;
        cin>>platena;
        int kodovoIme = round(platena*100);
        nePlateni[kodovoIme]--;
        //cout<<kodovoIme<<" ";
    }

    //cout<<endl<<"----------------"<<endl;

    cout<<fixed<<setprecision(2);

    for(int sm = 40000; sm >= 0; sm--){
        int broi = nePlateni[sm];
        if (broi > 0){
            double zaPechatane = sm / 100.00;
            for(int i = broi; i > 0; i--){
                cout<<zaPechatane<<" ";
            }
        }
    }

    cout<<endl;

    return 0;
}
