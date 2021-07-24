#include<iostream>
using namespace std;

int broiMostove;

int most[60];

int nivoNaOtgornost[60];

int plusKolko(int a, int b){
    if(a < b){
        return 1;
    }

    return -1;
}

bool presichatLiSe(int parvoNachalo, int parvoKrai,int vtoroNachalo, int vtoroKrai){
    if(parvoNachalo > parvoKrai){
        swap(parvoKrai, parvoNachalo);
    }
    if(vtoroNachalo > vtoroKrai){
        swap(vtoroNachalo, vtoroKrai);
    }

    if((parvoNachalo > vtoroNachalo && parvoNachalo < vtoroKrai && parvoKrai > vtoroKrai) ||
       (vtoroNachalo > parvoNachalo && vtoroNachalo < parvoKrai && vtoroKrai > parvoKrai))
    {
        return true;
    }

    return false;
}

int main(){
    cin>>broiMostove;

    for(int i = 0; i < broiMostove; i++){
        cin>>most[i];
    }

    bool okLie = true;

    for(int i = 1; i < broiMostove; i++){
        int uvelichenie = plusKolko(most[i - 1], most[i]);
        bool presechniLiSa = false;

        for(int j = 1; j < i; j++){
            if(j % 2 == i % 2){
                if(presichatLiSe(most[i - 1], most[i], most[j - 1], most[j]) == true){
                    presechniLiSa = true;
                    break;
                }
            }
        }

        if(presechniLiSa == true){
            okLie = false;
            break;
        }

        if(i % 2 == 1){
            for(int j = most[i - 1]; j != most[i]; j += uvelichenie){
                nivoNaOtgornost[j]++;
            }
        }
    }



    if(nivoNaOtgornost[most[broiMostove - 1]] == 0 && okLie == true){
        okLie = true;
    }else{
        okLie = false;
    }

    if(okLie == true){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}
