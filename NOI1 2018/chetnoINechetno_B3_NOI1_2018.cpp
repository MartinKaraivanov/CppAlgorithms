#include<iostream>
using namespace std;

unsigned long long broiIzrazi;
unsigned long long otgovori[12];

int main(){
    cin>>broiIzrazi;

    for(unsigned long long k = 0; k < broiIzrazi; k++){
        string izraz;
        cin>>izraz;

        unsigned long long obshtaSuma = 0;

        unsigned long long segashnaSuma = 0;
        unsigned long long segashnoChislo = 0;

        izraz.push_back('+');

        for(unsigned long long i = 0; i < izraz.size(); i++){
            if(izraz[i] == '+'){
                if(segashnaSuma > 0){
                    obshtaSuma+=segashnaSuma*segashnoChislo;
                }else{
                    obshtaSuma+=segashnoChislo;
                }
                segashnaSuma = 0;
                segashnoChislo = 0;
                continue;
            }

            if(izraz[i] == '*'){
                if(segashnaSuma == 0){
                    segashnaSuma = segashnoChislo;
                }else{
                    segashnaSuma *= segashnoChislo;
                }
                segashnoChislo = 0;
                continue;
            }

            segashnoChislo = 10*segashnoChislo + (izraz[i] - '0');
        }

        otgovori[k] = obshtaSuma%2;
    }

    for(unsigned long long i = 0; i < broiIzrazi; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
