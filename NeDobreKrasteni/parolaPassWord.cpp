#include<iostream>
using namespace std;

int parola[100];

int main(){
    int broiChisaOtParvaRedica;

    cin>>broiChisaOtParvaRedica;

    int parvaRedica[broiChisaOtParvaRedica];

    for(int i=0;i<broiChisaOtParvaRedica;i++){
        cin>>parvaRedica[i];
    }

    int broiChislaOtVtoraRedica;

    cin>>broiChislaOtVtoraRedica;

    int vtoraRedica[broiChislaOtVtoraRedica];

    for(int i=0;i<broiChislaOtVtoraRedica;i++){
        cin>>vtoraRedica[i];
    }

    int i=0;
    int j=0;
    int broiCifriVParolata=0;

    while((i<broiChisaOtParvaRedica) && (j<broiChislaOtVtoraRedica)){
        if(parvaRedica[i]==vtoraRedica[j]){
            i++;
            j++;
        }else{
            int sbor=0;
            while(sbor<vtoraRedica[j]){
                parola[broiCifriVParolata]=parvaRedica[i];
                sbor+=parvaRedica[i];
                i++;
                broiCifriVParolata++;
            }
            j++;
        }
    }

    for(int i=0;i<broiCifriVParolata;i++){
        cout<<parola[i]<<" ";
    }

    cout<<endl;

    return 0;
}
