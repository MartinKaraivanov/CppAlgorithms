#include<iostream>
using namespace std;

int broiTestove;
int daljinaText;
int daljinaSaobsht;
int poneKolkoBukvi;

string text;
string saobshtenie;

bool otgovori[16];

int main(){

    cin>>broiTestove;

    for(int t = 0; t < broiTestove; t++){
        cin>>daljinaText>>daljinaSaobsht>>poneKolkoBukvi;
        cin>>text;
        cin>>saobshtenie;

        text += ".";
        saobshtenie += ".";
        daljinaText++;
        daljinaSaobsht++;

        if(text[0] != saobshtenie[0]){
            otgovori[t] = false;
            //cout<<"No"<<endl;
            continue;
        }

        int indexSaobsht = 1;
        int indexText = 1;
        int prednoNamerenoIdx = 0;

        while(indexText < daljinaText && indexSaobsht < daljinaSaobsht){
            if(text[indexText] == saobshtenie[indexSaobsht] && indexText - prednoNamerenoIdx >= poneKolkoBukvi){
                indexSaobsht++;
                prednoNamerenoIdx = indexText;
            }
            indexText++;
        }

        if(indexSaobsht >= daljinaSaobsht){
            otgovori[t] = true;
            //cout<<"Yes"<<endl;
        }else{
            otgovori[t] = false;
            //cout<<"No"<<endl;
        }

    }

    for(int i = 0; i < broiTestove; i++){
        if(otgovori[i] == true){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
