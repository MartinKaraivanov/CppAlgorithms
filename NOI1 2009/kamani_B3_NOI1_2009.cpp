#include<iostream>
using namespace std;

int broiTestove;

int otgovori[110];

int pechelivshaLiE(int ostavashtBroiKamani){
    if(ostavashtBroiKamani == 0){
        return -1;
    }
    if(ostavashtBroiKamani == 1 || ostavashtBroiKamani == 2){
        return 1;
    }

    if(ostavashtBroiKamani%3==0){
        int parvo = pechelivshaLiE(ostavashtBroiKamani - 1);
        int vtoro = pechelivshaLiE(ostavashtBroiKamani - 2);
        if(parvo == -1 || vtoro == -1){
            return 1;
        }else{
            return -1;
        }
    }

    if(ostavashtBroiKamani%3==1){
        int parvo = pechelivshaLiE(ostavashtBroiKamani - 1);
        int vtoro = pechelivshaLiE(ostavashtBroiKamani - 3);
        if(parvo == -1 || vtoro == -1){
            return 1;
        }else{
            return -1;
        }
    }

    if(ostavashtBroiKamani%3==2){
        int parvo = pechelivshaLiE(ostavashtBroiKamani - 1);
        int vtoro = pechelivshaLiE(ostavashtBroiKamani - 2);
        int treto = pechelivshaLiE(ostavashtBroiKamani - 3);
        if(parvo == -1 || vtoro == -1 || treto == -1){
            return 1;
        }else{
            return -1;
        }
    }

    return 0;
}

int main(){
    cin>>broiTestove;

    for(int i = 0; i < broiTestove; i++){
        int broiKamani;
        cin>>broiKamani;
        if(pechelivshaLiE(broiKamani) == 1){
            otgovori[i] = 1;
        }else{
            otgovori[i] = 2;
        }
    }

    for(int i = 0; i < broiTestove; i++){
        cout<<otgovori[i];
    }

    cout<<endl;

    return 0;
}
