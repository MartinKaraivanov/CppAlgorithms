#include<iostream>
using namespace std;

string vhod;

const long long mnogo = 1000000007;

long long priTolkova[111][111];

long long broiPalindromi(int otKade, int daljina){
    int doKade = otKade + daljina - 1;

    if(otKade == doKade){
        //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<1<<endl;
        return 1;
    }

    if(doKade < otKade){
        //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<0<<endl;
        return 0;
    }

    if(priTolkova[otKade][daljina] > -1){
        return priTolkova[otKade][daljina];
    }

    //cout<<otKade<<" "<<doKade<<endl;

    long long zaTuk = broiPalindromi(otKade, daljina - 1)%mnogo;

    for(int i = otKade; i <= doKade; i++){
        if(vhod[i] == vhod[doKade]){
            //cout<<i<<" "<<doKade<<" sega puskam za "<<i+1<<" "<<doKade-1<<endl;
            zaTuk = (zaTuk + 1 + broiPalindromi(i + 1, daljina - (i - otKade) - 2))%mnogo;
        }
    }

    //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<zaTuk<<endl;
    priTolkova[otKade][daljina] = zaTuk;
    return zaTuk;
}

long long sCycli(int zaOtkade, int zaDaljina){
    for(int i = 0; i <= vhod.size(); i++){
        priTolkova[i][1] = 1;
    }

    for(int daljina = 2; daljina <= zaDaljina; daljina++){
        for(int otKade = 0; otKade <= zaDaljina - daljina; otKade++){
            int doKade = otKade + daljina - 1;

            long long zaTuk = broiPalindromi(otKade, daljina - 1)%mnogo;

            for(int i = otKade; i <= doKade; i++){
                if(vhod[i] == vhod[doKade]){
                    //cout<<i<<" "<<doKade<<" sega puskam za "<<i+1<<" "<<doKade-1<<endl;
                    zaTuk = (zaTuk + 1 + broiPalindromi(i + 1, daljina - (i - otKade) - 2))%mnogo;
                }
            }

            //cout<<"pri "<<otKade<<" "<<doKade<<" vrashtam "<<zaTuk<<endl;
            priTolkova[otKade][daljina] = zaTuk;
        }
    }

    return priTolkova[zaOtkade][zaDaljina];
}

int main(){
    cin>>vhod;

    /*for(int i = 0; i <= vhod.size(); i++){
        for(int j = 0; j <= vhod.size(); j++){
            priTolkova[i][j] = -1;
        }
    }

    long long otgovor = broiPalindromi(0, vhod.size());*/
    long long otgovor = sCycli(0, vhod.size());

    cout<<otgovor<<endl;

    return 0;
}
