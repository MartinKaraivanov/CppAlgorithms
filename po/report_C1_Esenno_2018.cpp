#include<iostream>
using namespace std;
int main(){
    int broiDni;

    cin>>broiDni;

    int naDen[broiDni];

    for(int i=0;i<broiDni;i++){
        cin>>naDen[i];
    }

    int naiMalkoPrediToziDen[broiDni];

    for(int i=0;i<broiDni;i++){
        int nach=100000000;
        int naiM=nach;
        for(int j=0;j<i;j++){
            if(naDen[j]<naiM){
                naiM=naDen[j];
            }
        }
        if(naiM!=nach){
            naiMalkoPrediToziDen[i]=naiM;
        }else{
            naiMalkoPrediToziDen[i]=0;
        }
    }

    for(int i=0;i<broiDni;i++){
        cout<<naiMalkoPrediToziDen[i]<<" ";
    }

    return 0;
}
