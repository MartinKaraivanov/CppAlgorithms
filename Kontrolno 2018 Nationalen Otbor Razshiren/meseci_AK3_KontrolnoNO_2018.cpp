#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

const int mod = 1000000007;

int broiGodini;

string vhod;

string meseci;

int razdelitel[12];

int priTolkova[(1<<25)];

int broiNachinipri(int kade, int sastoqnie){
    //cout<<"sega sme na "<<kade<<" i "<<sastoqnie<<endl;

    if(kade >= broiGodini*12){
        return 1;
    }

    if(priTolkova[sastoqnie] != -1){
        return priTolkova[sastoqnie];
    }

    int zaTuka = 0;

    for(int i = 0; i < 12; i++){
        if(vhod[kade] == '?' || vhod[kade] == meseci[i]){
            int kakvoImame = razdelitel[i];
            if(i > 0){
                kakvoImame = kakvoImame - razdelitel[i-1] - 1;
            }

            if(kakvoImame > 0){
                razdelitel[i]--;
                sastoqnie = sastoqnie ^ (3 << razdelitel[i]);
                zaTuka = (zaTuka + (long long)kakvoImame * broiNachinipri(kade + 1, sastoqnie))%mod;
                sastoqnie = sastoqnie ^ (3 << razdelitel[i]);
                razdelitel[i]++;
            }

        }
    }

    priTolkova[sastoqnie] = zaTuka;
    return zaTuka;
}

int main(){

    cin>>broiGodini;

    cin>>vhod;

    meseci = "JFMAMJJASOND";

    int nachalnoSastoqnie = 0;

    for(int i = 0; i < 12; i++){
        razdelitel[i] = broiGodini + i;
        nachalnoSastoqnie = nachalnoSastoqnie | (1 << razdelitel[i]);
    }

    //cout<<nachalnoSastoqnie<<endl;

    memset(priTolkova, -1, sizeof(priTolkova));

    int otgovor = broiNachinipri(0, nachalnoSastoqnie);

    cout<<otgovor<<endl;

    return 0;
}
