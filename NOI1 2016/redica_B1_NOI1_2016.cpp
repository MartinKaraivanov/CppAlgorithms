#include<iostream>
#include<cmath>
using namespace std;

int broiElementi;
int elementi[20050];

int main(){
    cin>>broiElementi;

    int naiMalakElement = 1000010;
    int naiGolqmElement = 0;

    for(int i = 1; i <= broiElementi; i++){
        cin>>elementi[i];
        naiGolqmElement = max(naiGolqmElement, elementi[i]);
        naiMalakElement = min(naiMalakElement, elementi[i]);
    }

    int parvoSreshtaneNaNaiMalkiq = 0;
    int poslednoSreshtaneNaaiMalkiq = 0;
    int parvoSreshtaneNaNaiGolemiq = 0;
    int poslendoSreshtaneNaNaiGolemiq = 0;

    for(int i = 1; i <= broiElementi; i++){
        if(elementi[i] == naiMalakElement){
            parvoSreshtaneNaNaiMalkiq = i;
            break;
        }
    }

    for(int i = 1; i <= broiElementi; i++){
        if(elementi[i] == naiGolqmElement){
            parvoSreshtaneNaNaiGolemiq = i;
            break;
        }
    }

    for(int i = broiElementi; i >= 0; i--){
        if(elementi[i] == naiMalakElement){
            poslednoSreshtaneNaaiMalkiq = i;
            break;
        }
    }

    for(int i = broiElementi; i >= 0; i--){
        if(elementi[i] == naiGolqmElement){
            poslendoSreshtaneNaNaiGolemiq = i;
            break;
        }
    }

    //int razstoqnie = -1;
    int nachalo = -1;
    int krai = -1;

    if(abs(poslendoSreshtaneNaNaiGolemiq - parvoSreshtaneNaNaiMalkiq) + 1
        >= abs(poslednoSreshtaneNaaiMalkiq - parvoSreshtaneNaNaiGolemiq) + 1)
    {
        nachalo = parvoSreshtaneNaNaiMalkiq;
        krai = poslendoSreshtaneNaNaiGolemiq;
    }else{
        nachalo = parvoSreshtaneNaNaiGolemiq;
        krai = poslednoSreshtaneNaaiMalkiq;
    }

    cout<<nachalo<<" "<<krai<<endl;

    return 0;
}
