#include<iostream>
using namespace std;
int main(){
    char skoba;
    long long broiOtvarqshti=0;
    long long broiZatvarqshti=0;
    bool pravilnaLiERedicata=true;

    while(cin>>skoba){
        if(skoba=='('){
            broiOtvarqshti++;
        }
        if(skoba==')'){
            broiZatvarqshti++;
        }
        if(broiZatvarqshti>broiOtvarqshti){
            pravilnaLiERedicata=false;
        }
    }

    if(pravilnaLiERedicata==true){
        if(broiOtvarqshti!=broiZatvarqshti){
            pravilnaLiERedicata=false;
        }
    }

    if(pravilnaLiERedicata==false){
        cout<<"Greshna Redica";
    }else{
        cout<<"Vqrna Redica";
    }

    return 0;
}
