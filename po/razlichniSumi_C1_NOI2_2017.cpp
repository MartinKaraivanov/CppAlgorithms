#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int broiChisla;
int chisla[5000];
bool sborovePlus[100000000];
bool sboroveMinus[100000000];
long long broiRazlichniSborove;

void sboroveISumi(int suma){
    if(suma>=0){
        if(sborovePlus[suma]==false){
            broiRazlichniSborove++;
            sborovePlus[suma]=true;
            //cout<<suma<<endl;
        }
    }
    if(suma<0){
        if(sboroveMinus[abs(suma)]==false){
            broiRazlichniSborove++;
            sboroveMinus[abs(suma)]=true;
            //cout<<suma<<endl;
        }
    }
}

void broiRazlichniSumi(int kolkoChislaIzbirame, int kolkoElementaSmeVzeli, int otKade, int sborSuma){
    if(kolkoElementaSmeVzeli==kolkoChislaIzbirame){
        sboroveISumi(sborSuma);
    }else{
        if(kolkoElementaSmeVzeli<kolkoChislaIzbirame){
            if(kolkoElementaSmeVzeli>0){
                sboroveISumi(sborSuma);
            }
            for(int i=otKade;i<broiChisla;i++){
                broiRazlichniSumi(kolkoChislaIzbirame, kolkoElementaSmeVzeli+1, i+1, sborSuma+chisla[i]);
            }
        }
    }
}

int main(){
    cin>>broiChisla;

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    broiRazlichniSumi(broiChisla, 0, 0, 0);

    cout<<broiRazlichniSborove<<endl;

    return 0;
}
