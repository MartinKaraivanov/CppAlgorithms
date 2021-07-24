#include<iostream>
#include<cstring>
using namespace std;

bool saglasnaLiEbukvata (char a){
    if((toupper(a)=='A') ||
        (toupper(a)=='I') ||
        (toupper(a)=='O') ||
        (toupper(a)=='U') ||
        (toupper(a)=='E') ||
        (toupper(a)=='Y') ||
        (a==' ') ||
        (a=='.')){
            return false;
        }else{
            return true;
        }
}

int main(){
    int broiSaobshteniq;
    cin>>broiSaobshteniq;

    char simvol;

    int broiOtParvotoPleme=0;
    int broiOtVtorotoPleme=0;

    bool otSaglasnotoPlemeLiE=false;
    int broiPosedovatelniSagalsni=0;

    while(cin>>simvol){
        if(simvol=='.'){
            if(otSaglasnotoPlemeLiE==false){
                broiOtVtorotoPleme++;
            }else{
                broiOtParvotoPleme++;
            }
            otSaglasnotoPlemeLiE=false;
            broiPosedovatelniSagalsni=0;
        }else{
            if(saglasnaLiEbukvata(simvol)==true){
                broiPosedovatelniSagalsni++;
            }else{
                broiPosedovatelniSagalsni=0;
            }
            if(broiPosedovatelniSagalsni==4){
                otSaglasnotoPlemeLiE=true;
            }
        }
    }

    cout<<broiOtVtorotoPleme<<" "<<broiOtParvotoPleme<<endl;

    return 0;
}
