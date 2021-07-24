#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){

    stack<char> stackOtvarqshti;
    char simvol;
    bool pravilnaLiERedicata=true;

    while(cin>>simvol){
        if(simvol=='('){
            stackOtvarqshti.push(simvol);
        }
        if(simvol=='{'){
            stackOtvarqshti.push(simvol);
        }
        if(simvol=='['){
            stackOtvarqshti.push(simvol);
        }
        if(simvol==')'){
            if(stackOtvarqshti.empty()){
                pravilnaLiERedicata=false;
            }else{
                char poslednaOtvariashta = stackOtvarqshti.top();
                stackOtvarqshti.pop();
                if(poslednaOtvariashta!='('){
                    pravilnaLiERedicata=false;
                }
            }
        }
        if(simvol=='}'){
            if(stackOtvarqshti.empty()){
                pravilnaLiERedicata=false;
            }else{
                char poslednaOtvariashta = stackOtvarqshti.top();
                stackOtvarqshti.pop();
                if(poslednaOtvariashta!='{'){
                    pravilnaLiERedicata=false;
                }
            }
        }
        if(simvol==']'){
            if(stackOtvarqshti.empty()){
                pravilnaLiERedicata=false;
            }else{
                char poslednaOtvariashta = stackOtvarqshti.top();
                stackOtvarqshti.pop();
                if(poslednaOtvariashta!='['){
                    pravilnaLiERedicata=false;
                }
            }
        }
    }

    if(stackOtvarqshti.empty()==false){
        pravilnaLiERedicata=false;
    }

    if(pravilnaLiERedicata==true){
        cout<<"Vqrna Redica";
    }else{
        cout<<"Greshna redica";
    }


    return 0;
}
