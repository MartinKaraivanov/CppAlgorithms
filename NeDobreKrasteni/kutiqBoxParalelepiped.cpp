#include<iostream>
using namespace std;

int broiOtChisloto[12000];

int main(){
    int parviRazmer[6];
    int vtoriRazmer[6];

    int naiGolqmoChislo=0;
    int naiMalkoChislo=15000;

    for(int i=0;i<6;i++){
        cin>>parviRazmer[i]>>vtoriRazmer[i];
        int parvo=parviRazmer[i];
        int vtoro=vtoriRazmer[i];

        broiOtChisloto[parvo]++;
        broiOtChisloto[vtoro]++;

        if(parviRazmer[i]>naiGolqmoChislo){
            naiGolqmoChislo=parvo;
        }
        if(vtoriRazmer[i]>naiGolqmoChislo){
            naiGolqmoChislo=vtoro;
        }
        if(parvo<naiMalkoChislo){
            naiMalkoChislo=parvo;
        }
        if(vtoro<naiMalkoChislo){
            naiMalkoChislo=vtoro;
        }
    }

    for(int i=naiMalkoChislo;i<=naiGolqmoChislo;i++){
        if(((broiOtChisloto[i]!=4) && (broiOtChisloto[i]>0)) && ((broiOtChisloto[i]!=8) && (broiOtChisloto[i]>0)) && ((broiOtChisloto[i]!=12) && (broiOtChisloto[i]>0))){
            cout<<0<<endl;
            return 0;
        }

    }


    unsigned long long chisla[3];
    int p=0;
    for(int i=naiMalkoChislo;i<=naiGolqmoChislo;i++){
        if(broiOtChisloto[i]==4){
            chisla[p]=i;
            p++;
        }
        if(broiOtChisloto[i]==8){
            chisla[p]=i;
            chisla[p+1]=i;
            p+=2;
        }
        if(broiOtChisloto[i]==12){
            chisla[0]=i;
            chisla[1]=i;
            chisla[2]=i;
            break;
        }
        if(p==3){
            break;
        }
    }

    unsigned long long obem=chisla[0]*chisla[1]*chisla[2];


    cout<<obem<<endl;


    return 0;
}
