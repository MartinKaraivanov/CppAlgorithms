#include<iostream>
#include<cmath>
using namespace std;

long long chisla[3];

int main(){
    for(int t = 0; t < 3; t++){
        cin>>chisla[t];

        long long broiCifri = 0;

        long long copie = chisla[t];

        while(copie > 0){
            broiCifri++;
            copie /= 10;
        }

        long long dolnaGranica = 2*pow(10, broiCifri - 1) - 1;
        long long gornaGranica = pow(10, broiCifri)/3 + 2;

        if(chisla[t] >= dolnaGranica && chisla[t] <= gornaGranica){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }

    }

    return 0;
}
