#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct DanniZaSbora{
    long long sbor;
    int tip;
};

long long otKade;
long long doKade;

bool sastavnoLIE[1000010];

vector<long long> prostiChisla;

void eratosten(){
    sastavnoLIE[0] = true;
    sastavnoLIE[1] = true;

    long long korenKvadraten = sqrt(doKade);

    for(long long i = 2; i <= korenKvadraten; i++){
        if(sastavnoLIE[i] == false){
            for(long long x = i*i; x <= doKade; x+=i){
                sastavnoLIE[x] = true;
            }
        }
    }

    for(long long i = 2; i <= doKade; i++){
        if(sastavnoLIE[i] == false){
            prostiChisla.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>otKade>>doKade;

    eratosten();

    long long sNaiGolqmataDaljina = 0;
    long long otKadeZapochva = -1;
    long long kakavESbora = 0;

    for(unsigned long long i = 0; i < prostiChisla.size(); i++){
        long long tekushtSbor = 0;
        long long tekushtaDaljina = 0;

        for(unsigned long long j = i; j < prostiChisla.size(); j++){
            tekushtSbor += prostiChisla[j];

            if(tekushtSbor > doKade){
                break;
            }

            //cout<<prostiChisla[i]<<" "<<prostiChisla[j]<<" "<<tekushtSbor<<endl;

            tekushtaDaljina++;

            if(sastavnoLIE[tekushtSbor] == false && tekushtSbor >= otKade && tekushtaDaljina > sNaiGolqmataDaljina){
                sNaiGolqmataDaljina = tekushtaDaljina;
                otKadeZapochva = i;
                kakavESbora = tekushtSbor;
            }
        }
    }

    if(sNaiGolqmataDaljina == 0){
        cout<<"no prime"<<endl;
    }else{
        cout<<kakavESbora<<" "<<sNaiGolqmataDaljina<<endl;
        for(unsigned long long i = otKadeZapochva; i < otKadeZapochva + sNaiGolqmataDaljina; i++){
            cout<<prostiChisla[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
