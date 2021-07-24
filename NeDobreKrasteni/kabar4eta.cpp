#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char puskane;
    char naVarha='-';
    long long broiNeshta=0;
    long long brMehurcheta=0;
    long long poredniBalonchetaNaVarha=0;

    while(cin>>puskane){
        char novoNaVarha;

        if(naVarha=='-'){
            if(puskane=='O'){
                novoNaVarha=puskane;
                broiNeshta++;
                brMehurcheta++;
                poredniBalonchetaNaVarha++;
            }
            if(puskane=='L'){
                novoNaVarha=puskane;
                broiNeshta++;
                brMehurcheta=brMehurcheta;
                poredniBalonchetaNaVarha=0;
            }
            if(puskane=='T'){
                novoNaVarha=puskane;
                broiNeshta++;
                brMehurcheta=brMehurcheta;
                poredniBalonchetaNaVarha=0;
            }
        }
        if((naVarha=='O') && (puskane=='O') ){
            poredniBalonchetaNaVarha++;
            broiNeshta++;
            brMehurcheta++;
            novoNaVarha=puskane;
        }
        if((naVarha=='O') && (puskane=='L') ){
            broiNeshta++;
            novoNaVarha=puskane;
            poredniBalonchetaNaVarha=0;
            brMehurcheta=brMehurcheta;
        }
        if((naVarha=='O') && (puskane=='T') ){
            brMehurcheta=brMehurcheta-poredniBalonchetaNaVarha;
            broiNeshta=broiNeshta+1-poredniBalonchetaNaVarha;
            poredniBalonchetaNaVarha=0;
            novoNaVarha=puskane;
        }
        if((naVarha=='T') && (puskane=='O') ){
            broiNeshta++;
            brMehurcheta++;
            novoNaVarha=puskane;
            poredniBalonchetaNaVarha++;
        }
        if((naVarha=='T') && (puskane=='T') ){
            broiNeshta++;
            novoNaVarha=puskane;
            brMehurcheta=brMehurcheta;
            poredniBalonchetaNaVarha=0;
        }
        if((naVarha=='T') && (puskane=='L') ){
            broiNeshta++;
            novoNaVarha=puskane;
            brMehurcheta=brMehurcheta;
            poredniBalonchetaNaVarha=0;
        }
        if((naVarha=='L') && (puskane=='O') ){
            novoNaVarha=naVarha;
            brMehurcheta=brMehurcheta;
            broiNeshta=broiNeshta;
            poredniBalonchetaNaVarha=0;
        }
        if((naVarha=='L') && (puskane=='L') ){
            broiNeshta++;
            novoNaVarha=puskane;
            brMehurcheta=brMehurcheta;
            poredniBalonchetaNaVarha=0;
        }
        if((naVarha=='L') && (puskane=='T') ){
            broiNeshta++;
            novoNaVarha=puskane;
            brMehurcheta=brMehurcheta;
            poredniBalonchetaNaVarha=0;
        }

        naVarha= novoNaVarha;
    }

    cout<<broiNeshta<<" "<<brMehurcheta;

    return 0;
}
