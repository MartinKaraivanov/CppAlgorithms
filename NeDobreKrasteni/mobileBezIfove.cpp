#include<iostream>
#include<cstring>
using namespace std;
int main(){

    string dniOtSedmicata[7];
    dniOtSedmicata[0]="Wednesday";
    dniOtSedmicata[1]="Thursday";
    dniOtSedmicata[2]="Friday";
    dniOtSedmicata[3]="Saturday";
    dniOtSedmicata[4]="Sunday";
    dniOtSedmicata[5]="Monday";
    dniOtSedmicata[6]="Tuesday";

    string meseci[13];
    meseci[0]="";
    meseci[1]="January";
    meseci[2]="February";
    meseci[3]="March";
    meseci[4]="April";
    meseci[5]="May";
    meseci[6]="June";
    meseci[7]="July";
    meseci[8]="August";
    meseci[9]="September";
    meseci[10]="October";
    meseci[11]="November";
    meseci[12]="December";

    long long dniVToziMesec [13];
    dniVToziMesec[0]=0;
    dniVToziMesec[1]=31;
    dniVToziMesec[2]=28;
    dniVToziMesec[3]=31;
    dniVToziMesec[4]=30;
    dniVToziMesec[5]=31;
    dniVToziMesec[6]=30;
    dniVToziMesec[7]=31;
    dniVToziMesec[8]=31;
    dniVToziMesec[9]=30;
    dniVToziMesec[10]=31;
    dniVToziMesec[11]=30;
    dniVToziMesec[12]=31;

    long long dniDoToziMesec [13];

    for(int i=0;i<13;i++){
        dniDoToziMesec[i]=0;
    }

    for(int i=1;i<13;i++){
        dniDoToziMesec[i]=dniDoToziMesec[i-1]+dniVToziMesec[i-1];
    }


    long long kolkoDati;
    cin>>kolkoDati;
    long long den[kolkoDati];
    string kojMesec[kolkoDati];
    for(int i=0;i<kolkoDati;i++){
        cin>>kojMesec[i]>>den[i];
    }

    long long nomerNaMesec[kolkoDati];
    for(int i=0;i<kolkoDati;i++){
        for(int j=0;j<13;j++){
            if(kojMesec[i]==meseci[j]){
                nomerNaMesec[i]=j;
            }
        }
    }

    cout<<"2015"<<endl;


    for(int i=0;i<kolkoDati;i++){
        int nomerNaDenOtGodinata = dniDoToziMesec[nomerNaMesec[i]]+den[i];

        cout<<kojMesec[i]<<" "<<den[i]<<" "<<dniOtSedmicata[nomerNaDenOtGodinata%7]<<endl;
    }


    return 0;
}
