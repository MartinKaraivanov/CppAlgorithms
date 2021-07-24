#include<iostream>
using namespace std;

string redica;

int broiNuliOtNachalotoDoTuk[1000010];
int broiEdiniciOtNachalotoDoTuk[1000010];

int main(){
    cin>>redica;

    broiNuliOtNachalotoDoTuk[0] = 0;
    broiEdiniciOtNachalotoDoTuk[0] = 0;

    for(int i = 0; i < redica.size(); i++){
        if(redica[i] == '0'){
            broiNuliOtNachalotoDoTuk[i + 1] = broiNuliOtNachalotoDoTuk[i] + 1;
            broiEdiniciOtNachalotoDoTuk[i + 1] = broiEdiniciOtNachalotoDoTuk[i];
        }else{
            broiEdiniciOtNachalotoDoTuk[i + 1] = broiEdiniciOtNachalotoDoTuk[i] + 1;
            broiNuliOtNachalotoDoTuk[i + 1] = broiNuliOtNachalotoDoTuk[i];
        }
    }

    int broiche = 0;

    for(int i = 1; i < redica.size() + 1; i++){
        if(broiNuliOtNachalotoDoTuk[i] == broiEdiniciOtNachalotoDoTuk[i]){
            broiche++;
        }
    }

    cout<<broiche<<endl;

    return 0;
}
