#include<iostream>
#include<vector>
using namespace std;

int broiKanali;
int broiPuskaniq;

string redica;

vector<int> prevkluchvania;

int otgovori[500010];

int darvo[1500000];
int broiNuzhniVarhove;

int daiListo(int index){
    return index + broiNuzhniVarhove/2;
}

void praveneNaBroiNuzhniVarhove(){
    int brNuzhni;

    for(unsigned int i = 1; true; i *= 2){
        if(i >= redica.size()){
            brNuzhni = 2*i;
            break;
        }
    }

    broiNuzhniVarhove = brNuzhni;
}

void praveneNaDarvoto(){
    praveneNaBroiNuzhniVarhove();

    for(unsigned int i = 0; i < redica.size(); i++){
        darvo[daiListo(i)] = prevkluchvania[i];
    }

    for(int i = daiListo(0) - 1; i > 0; i--){
        darvo[i] = darvo[i * 2] + darvo[i * 2 + 1];
    }

}

/*void updatevane(int otKade, int doKade){
    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(lqvIndex == desenIndex){
        darvo[lqvIndex] *= -1;
        return;
    }

    darvo[lqvIndex] *= -1;
    darvo[desenIndex] *= -1;

    while(lqvIndex + 1 != desenIndex){
        if(lqvIndex % 2 == 0){
            darvo[lqvIndex + 1] *= -1;
        }
        if(desenIndex % 2 == 1){
            darvo[desenIndex - 1] *= -1;
        }
        lqvIndex /= 2;
        desenIndex /= 2;
    }

}*/

void updatevane(int index, int sKolko){
    int i = daiListo(index);

    while(i > 0){
        darvo[i] += sKolko;
        i /= 2;
    }

}



void praveneNaPrevkluchvaniata(){
    for(unsigned int i = 0; i < redica.size(); i++){
        if(redica[i] == '+'){
            prevkluchvania.push_back(1);
        }else{
            if(redica[i] == '-'){
                prevkluchvania.push_back(-1);
            }else{
                prevkluchvania.push_back(0);
            }
        }
    }
}

void popravqneNaPrevkluchvaniqtaa(){
    int posledovatelenBroiNuli = 0;

    for(int i = prevkluchvania.size() - 1; i >= 0; i--){
        if(prevkluchvania[i] == 0){
            posledovatelenBroiNuli++;
        }else{
            if(posledovatelenBroiNuli % 2 == 0){

            }else{
                prevkluchvania[i] = 0;
            }
            posledovatelenBroiNuli = 0;
        }
    }
}


void promqna(int otKade, int doKade){
    for(int i = otKade; i <= doKade; i++){
        if(darvo[daiListo(i)] == 1){
            updatevane(i, -2);
        }else{
            if(darvo[daiListo(i)] == -1){
                updatevane(i, 2);
            }
        }
    }
    /*cout<<"v promqnata sum "<<otKade<<" "<<doKade<<endl;
    updatevane(otKade, doKade);*/
}

int naKoiKanalShteSme(){
    /*int kanal = 1;

    for(unsigned int i = 0; i < redica.size(); i++){
        kanal += prevkluchvania[i];
        if(kanal <= 0){
            kanal = broiKanali;
        }
        if(kanal > broiKanali){
            kanal = 1;
        }
    }*/

    int potencialno = 1 + darvo[1];

    if(potencialno <= 0){
        potencialno = broiKanali + potencialno;
    }

    if(potencialno > broiKanali){
        potencialno = 1 + potencialno;
    }

    return potencialno;
}

void otpechatvaneNaRedicata(){
    for(unsigned int i = 0; i < redica.size(); i++){
        cout<<prevkluchvania[i]<<" ";
    }
    cout<<endl;
}

void otpechatvaneNaDolniqRedNaDarvoto(){
    for(unsigned int i = 0; i < redica.size(); i++){
        cout<<darvo[daiListo(i)]<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>broiKanali>>broiPuskaniq;

    cin>>redica;

    praveneNaPrevkluchvaniata();
    popravqneNaPrevkluchvaniqtaa();

    praveneNaDarvoto();

    //otpechatvaneNaDolniqRedNaDarvoto();

    for(int i = 0; i < broiPuskaniq; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;
        //otpechatvaneNaDolniqRedNaDarvoto();
        //cout<<"varha na darvoto e "<<darvo[1]<<endl;
        promqna(otKade - 1, doKade - 1);
        //otpechatvaneNaDolniqRedNaDarvoto();
        //cout<<"varha na darvoto e "<<darvo[1]<<endl;
        otgovori[i] = naKoiKanalShteSme();
    }

    for(int i = 0; i < broiPuskaniq; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
