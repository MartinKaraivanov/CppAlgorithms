#include<iostream>
using namespace std;

int broiTestove;

int otgovori[110];

int priTolkova[1000010];

void pechelivshaLiE(int ostavashtBroiKamani){
    for(int i = 3; i <= ostavashtBroiKamani; i++){
        priTolkova[i] = 0;
    }

    priTolkova[0] = -1;
    priTolkova[1] = 1;
    priTolkova[2] = 1;

    for(int i = 3; i <= ostavashtBroiKamani; i++){
        //cout<<i<<" ";
        if(i%3==0){
            int parvo = priTolkova[i - 1];
            int vtoro = priTolkova[i - 2];
            //cout<<parvo<<" "<<vtoro<<endl;
            if(parvo == -1 || vtoro == -1){
                priTolkova[i] = 1;
            }else{
                priTolkova[i] = -1;
            }
        }
        if(i%3==1){
            int parvo = priTolkova[i - 1];
            int vtoro = priTolkova[i - 3];
            //cout<<parvo<<" "<<vtoro<<endl;
            if(parvo == -1 || vtoro == -1){
                priTolkova[i] = 1;
            }else{
                priTolkova[i] = -1;
            }
        }
        if(i%3==2){
            int parvo = priTolkova[i - 1];
            int vtoro = priTolkova[i - 2];
            int treto = priTolkova[i - 3];
            //cout<<parvo<<" "<<vtoro<<" "<<treto<<endl;
            if(parvo == -1 || vtoro == -1 || treto == -1){
                priTolkova[i] = 1;
            }else{
                priTolkova[i] = -1;
            }
        }
    }
}

int main(){
    cin>>broiTestove;

    pechelivshaLiE(1000001);

    for(int i = 0; i < broiTestove; i++){
        int broiKamani;
        cin>>broiKamani;
        if(priTolkova[broiKamani] == 1){
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
