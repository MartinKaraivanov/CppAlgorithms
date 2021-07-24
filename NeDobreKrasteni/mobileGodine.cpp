#include<iostream>
#include<cstring>
using namespace std;
int main(){
    long long kolkoDati;
    cin>>kolkoDati;
    string mesec[kolkoDati];
    long long den[kolkoDati];
    long long novDen[kolkoDati];

    for(int i=0;i<kolkoDati;i++){
        cin>>mesec[i]>>den[i];
    }

    for(int i=0;i<kolkoDati;i++){
        novDen[i]=den[i];
    }

    for(int i=0;i<kolkoDati;i++){
        while(novDen[i]>7){
            novDen[i]=novDen[i]-7;
        }
    }
    cout<<2015<<endl;

    long long denOtSedmicata[kolkoDati];
    long long dniVMeseca[kolkoDati];
    for(int i=0;i<kolkoDati;i++){
        if(mesec[i] == "January" ){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
        }
        if(mesec[i] == "February"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
        }
        if(mesec[i]=="March"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
        }
        if(mesec[i]=="April"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
        }
        if(mesec[i]=="May"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
        }
        if(mesec[i]=="June"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
        }
        if(mesec[i]=="July"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
        }
        if(mesec[i]=="August"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
        }
        if(mesec[i]=="September"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
        }
        if(mesec[i]=="October"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
        }
        if(mesec[i]=="November"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
        }
        if(mesec[i]=="December"){
            if(novDen[i]==1){
                cout<<mesec[i]<<" "<<den[i]<<" Tuesday"<<endl;
            }
            if(novDen[i]==2){
                cout<<mesec[i]<<" "<<den[i]<<" Wednesday"<<endl;
            }
            if(novDen[i]==3){
                cout<<mesec[i]<<" "<<den[i]<<" Thursday"<<endl;
            }
            if(novDen[i]==4){
                cout<<mesec[i]<<" "<<den[i]<<" Friday"<<endl;
            }
            if(novDen[i]==5){
                cout<<mesec[i]<<" "<<den[i]<<" Saturday"<<endl;
            }
            if(novDen[i]==6){
                cout<<mesec[i]<<" "<<den[i]<<" Sunday"<<endl;
            }
            if(novDen[i]==7){
                cout<<mesec[i]<<" "<<den[i]<<" Monday"<<endl;
            }
        }
    }
    cout<<endl;

    return 0;
}
