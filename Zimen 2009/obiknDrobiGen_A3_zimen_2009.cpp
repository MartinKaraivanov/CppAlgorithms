#include<iostream>
using namespace std;

int chislitel;
int znamenatel;

int main(){

    cin>>chislitel>>znamenatel;

    if(chislitel%2 == 1 && znamenatel%2 == 1){
        cout<<0<<endl;
        return 0;
    }

    int copieChisl = chislitel;
    int copieZnam = znamenatel;

    int broi = 0;

    while(true){
        if(copieChisl % 2 == 0){
            copieChisl /= 2;
            copieZnam = copieZnam + copieChisl;
        }else{
            copieZnam /= 2;
            copieChisl = copieChisl + copieZnam;
        }
        broi++;
        if(copieChisl == chislitel || broi == chislitel + znamenatel){
            break;
        }
    }


    if(broi == chislitel + znamenatel){
        cout<<0<<endl;
    }else{
        cout<<broi<<endl;
    }

    return 0;
}
