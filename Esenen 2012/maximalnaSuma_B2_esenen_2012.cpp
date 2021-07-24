#include<iostream>
#include<vector>
using namespace std;

int broiKutii;

vector<int> kutii[550];

long long priTolkova[2][1051];

/*long long naiGolqmaSuma(int doKutiq, int prednoChislo){
    if(doKutiq == 0){
        return 0;
    }

    if(priTolkova[doKutiq][prednoChislo] != 0){
        return priTolkova[doKutiq][prednoChislo];
    }

    long long zaTuk = 0;

    zaTuk += naiGolqmaSuma(doKutiq - 1, prednoChislo);

    for(unsigned int i = 0; i < kutii[doKutiq].size(); i++){
        if(kutii[doKutiq][i] <= prednoChislo){
            long long tekushto = kutii[doKutiq][i] + naiGolqmaSuma(doKutiq - 1, kutii[doKutiq][i]);

            zaTuk = max(zaTuk, tekushto);
        }
    }

    priTolkova[doKutiq][prednoChislo] = zaTuk;
    return zaTuk;
}*/

long long sCycli(){

    for(int doKutiq = 1; doKutiq <= broiKutii; doKutiq++){
        for(int prednoChislo = 0; prednoChislo <= 1001; prednoChislo++){
            long long zaTuk = 0;

            zaTuk += priTolkova[(doKutiq - 1)%2][prednoChislo];

            for(unsigned int i = 0; i < kutii[doKutiq].size(); i++){
                if(kutii[doKutiq][i] <= prednoChislo){
                    long long tekushto = kutii[doKutiq][i] + priTolkova[(doKutiq - 1)%2][kutii[doKutiq][i]];

                    zaTuk = max(zaTuk, tekushto);
                }
            }

            priTolkova[doKutiq%2][prednoChislo] = zaTuk;

        }
    }

    return priTolkova[broiKutii%2][1001];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiKutii;

    for(int i = 1; i <= broiKutii; i++){
        int broiTuka;
        cin>>broiTuka;
        for(int j = 0; j < broiTuka; j++){
            int tuka;
            cin>>tuka;
            kutii[i].push_back(tuka);
        }
    }

    //long long naiGolqmaSumaOtNenamalqvashtaRedica = naiGolqmaSuma(broiKutii, 1001);
    long long naiGolqmaSumaOtNenamalqvashtaRedica = sCycli();

    cout<<naiGolqmaSumaOtNenamalqvashtaRedica<<endl;

    return 0;
}
