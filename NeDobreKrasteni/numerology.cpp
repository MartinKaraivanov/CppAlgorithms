#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char ime[21];
    cin>>ime;
    long long daljina;
    daljina=strlen(ime);
    long long kodNaBukvata[daljina];
    for(int i=0;i<daljina;i++){
        if(toupper(ime[i])=='A'){
            kodNaBukvata[i]=1;
        }
        if(toupper(ime[i])=='B'){
            kodNaBukvata[i]=2;
        }
        if(toupper(ime[i])=='C'){
            kodNaBukvata[i]=3;
        }
        if(toupper(ime[i])=='D'){
            kodNaBukvata[i]=4;
        }
        if(toupper(ime[i])=='E'){
            kodNaBukvata[i]=5;
        }
        if(toupper(ime[i])=='F'){
            kodNaBukvata[i]=6;
        }
        if(toupper(ime[i])=='G'){
            kodNaBukvata[i]=7;
        }
        if(toupper(ime[i])=='H'){
            kodNaBukvata[i]=8;
        }
        if(toupper(ime[i])=='I'){
            kodNaBukvata[i]=9;
        }
        if(toupper(ime[i])=='J'){
            kodNaBukvata[i]=1;
        }
        if(toupper(ime[i])=='K'){
            kodNaBukvata[i]=2;
        }
        if(toupper(ime[i])=='L'){
            kodNaBukvata[i]=3;
        }
        if(toupper(ime[i])=='M'){
            kodNaBukvata[i]=4;
        }
        if(toupper(ime[i])=='N'){
            kodNaBukvata[i]=5;
        }
        if(toupper(ime[i])=='O'){
            kodNaBukvata[i]=6;
        }
        if(toupper(ime[i])=='P'){
            kodNaBukvata[i]=7;
        }
        if(toupper(ime[i])=='Q'){
            kodNaBukvata[i]=8;
        }
        if(toupper(ime[i])=='R'){
            kodNaBukvata[i]=9;
        }
        if(toupper(ime[i])=='S'){
            kodNaBukvata[i]=1;
        }
        if(toupper(ime[i])=='T'){
            kodNaBukvata[i]=2;
        }
        if(toupper(ime[i])=='U'){
            kodNaBukvata[i]=3;
        }
        if(toupper(ime[i])=='V'){
            kodNaBukvata[i]=4;
        }
        if(toupper(ime[i])=='W'){
            kodNaBukvata[i]=5;
        }
        if(toupper(ime[i])=='X'){
            kodNaBukvata[i]=6;
        }
        if(toupper(ime[i])=='Y'){
            kodNaBukvata[i]=7;
        }
        if(toupper(ime[i])=='Z'){
            kodNaBukvata[i]=8;
        }
    }
    long long kod=0;
    for(int i=0;i<daljina;i++){
        kod=kod+kodNaBukvata[i];
    }
    long long novKod=0;
    if(kod!=33){
        while(kod>0){
            novKod=novKod+kod%10;
            kod=kod/10;
        }
        if(novKod>9){
            long long novNovKod=0;
            while(novKod>0){
            novNovKod=novNovKod+novKod%10;
            novKod=novKod/10;
            }
            if(novNovKod>9){
                long long novNovNovKod=0;
                while(novNovNovKod>0){
                    novNovNovKod=novNovNovKod+novNovKod%10;
                    novNovKod=novNovKod/10;
                }
                cout<<novNovNovKod;
                return 0;
            }else{
                cout<<novNovKod;
                return 0;
            }
        }
        cout<<novKod;
    }else{
        cout<<"33";
    }

    return 0;
}
