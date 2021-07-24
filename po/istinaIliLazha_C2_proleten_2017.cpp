#include<iostream>
using namespace std;

int broiUchenici;
int broiTvardeniq;

char sasedstvo[10100][10100];

int main(){
    cin>>broiUchenici>>broiTvardeniq;

    for(int i=0;i<broiTvardeniq;i++){
        int tvarUch;
        char tvardenie;
        int natopenUchenik;

        cin>>tvarUch>>tvardenie>>natopenUchenik;

        sasedstvo[tvarUch][natopenUchenik] = tvardenie;
    }

    return 0;
}
