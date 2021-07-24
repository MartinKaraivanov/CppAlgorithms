#include<iostream>
using namespace std;

int broiRabotnici;
bool manageri[55][55];
int zaplati[55];

bool kraenLiEChovekat(int koiChovek){
    for(int i=0;i<broiRabotnici;i++){
        if(manageri[koiChovek][i]==true){
            return false;
        }
    }

    return true;
}

int kolkoEZaplatatNaChoveka(int koiChovek){
    if(kraenLiEChovekat(koiChovek)==true){
        return 1;
    }

    int zaplataNaToziChovek=0;

    for(int i=0;i<broiRabotnici;i++){
        if(manageri[koiChovek][i]==true){
            zaplataNaToziChovek+=kolkoEZaplatatNaChoveka(i);
        }
    }

    return zaplataNaToziChovek;
}

int main(){
    cin>>broiRabotnici;

    for(int i=0;i<broiRabotnici;i++){
        for(int j=0;j<broiRabotnici;j++){
            char ManagerLIENaTozi;
            cin>>ManagerLIENaTozi;

            if(ManagerLIENaTozi=='Y'){
                manageri[i][j]=true;
            }
        }
    }

    int zaplataSumarno=0;

    for(int i=0;i<broiRabotnici;i++){
        zaplataSumarno+=kolkoEZaplatatNaChoveka(i);
    }

    cout<<zaplataSumarno;

    return 0;
}
