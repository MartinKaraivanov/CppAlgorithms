#include<iostream>
using namespace std;

int main(){
    long long broiMonitori,naiGolqmaRezoluciq;
    cin>>broiMonitori;

    long long horizontalna[broiMonitori],vertikalna[broiMonitori];
    for(int i=0;i<broiMonitori;i++){
        cin>>horizontalna[i]>>vertikalna[i];
    }
    naiGolqmaRezoluciq=0;
    for(int i=0;i<broiMonitori;i++){
        int obshtoHorizontalna = 0;
        for(int j=i;j<broiMonitori;j++){
            if(vertikalna[i]==vertikalna[j]){
                obshtoHorizontalna=obshtoHorizontalna+horizontalna[j];
            }
        }
        if(obshtoHorizontalna>naiGolqmaRezoluciq){
                naiGolqmaRezoluciq=obshtoHorizontalna;
        }

    }
    cout<<naiGolqmaRezoluciq;
    cout<<endl;

    return 0;
}
