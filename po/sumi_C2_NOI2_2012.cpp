#include<iostream>
using namespace std;

int brChisla;
int chisla[25000];
int poGolqmoOtKolko;
int poMalkoOtKolko;
int brRazlSumi;
bool imameLiSumata[25000];

void pribavqneNaSumi(int suma){
    if((suma>=poGolqmoOtKolko) && (suma<=poMalkoOtKolko)){
        if(imameLiSumata[suma]==false){
            brRazlSumi++;
            imameLiSumata[suma]=true;
            //cout<<suma<<endl;
        }
    }
}

void broiOtgovarqshtiSumi(int kolkoChislaDaVzemem, int kolkoSmeVzeli,int suma, int otKade){
    if(kolkoSmeVzeli==kolkoChislaDaVzemem){
        pribavqneNaSumi(suma);
    }else{
        if(kolkoSmeVzeli>0){
            pribavqneNaSumi(suma);
        }
        if(suma<=poMalkoOtKolko){
            for(int i=otKade;i<brChisla;i++){
                broiOtgovarqshtiSumi(kolkoChislaDaVzemem, kolkoSmeVzeli+1,suma+chisla[i], i+1);
            }
        }
    }
}

int main(){
    cin>>brChisla>>poGolqmoOtKolko>>poMalkoOtKolko;

    for(int i=0;i<brChisla;i++){
        cin>>chisla[i];
    }

    broiOtgovarqshtiSumi(brChisla, 0, 0, 0);

    cout<<brRazlSumi<<endl;

    return 0;
}
