#include<iostream>
using namespace std;

string vhod;

const long long mnogo = 1000000007;

long long priTolkova[111][111];

long long broiPalindromi(int otKade, int doKade){
    if(otKade == doKade){
        //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<1<<endl;
        return 1;
    }

    if(doKade < otKade){
        //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<0<<endl;
        return 0;
    }

    if(priTolkova[otKade][doKade] > -1){
        return priTolkova[otKade][doKade];
    }

    //cout<<otKade<<" "<<doKade<<endl;

    long long zaTuk = broiPalindromi(otKade, doKade - 1)%mnogo;

    for(int i = otKade; i <= doKade; i++){
        if(vhod[i] == vhod[doKade]){
            //cout<<i<<" "<<doKade<<" sega puskam za "<<i+1<<" "<<doKade-1<<endl;
            zaTuk = (zaTuk + 1 + broiPalindromi(i + 1, doKade - 1))%mnogo;
        }
    }

    //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<zaTuk<<endl;
    priTolkova[otKade][doKade] = zaTuk;
    return zaTuk;
}

int main(){
    cin>>vhod;

    for(int i = 0; i <= vhod.size(); i++){
        for(int j = 0; j <= vhod.size(); j++){
            priTolkova[i][j] = -1;
        }
    }

    long long otgovor = broiPalindromi(0, vhod.size() - 1);

    cout<<otgovor<<endl;

    return 0;
}
