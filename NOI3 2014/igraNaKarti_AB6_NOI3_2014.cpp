#include<iostream>
#include<vector>
using namespace std;

int broiKarti;
int karti[750];

int priTolkova[750][750];

int naiGolqmaStoinost(int lqvaKarta, int dalzhina){
    if(priTolkova[lqvaKarta][dalzhina] > -1){
        return priTolkova[lqvaKarta][dalzhina];
    }

    int naiDobro = 0;

    for(int i = lqvaKarta + 1; i < lqvaKarta + dalzhina - 1; i++){
        int segashno = karti[i] * (karti[lqvaKarta] + karti[lqvaKarta + dalzhina - 1])
            + naiGolqmaStoinost(lqvaKarta, i - lqvaKarta + 1) + naiGolqmaStoinost(i, lqvaKarta + dalzhina - i);
        naiDobro = max(naiDobro, segashno);
    }

    priTolkova[lqvaKarta][dalzhina] = naiDobro;
    return naiDobro;
}

int sCycli(int lqv, int dalag){

    for(int dalzhina = 3; dalzhina <= broiKarti; dalzhina++){
        for(int lqvaKarta = 0; lqvaKarta <= broiKarti - dalzhina; lqvaKarta++){

            int naiDobro = 0;

            for(int i = lqvaKarta + 1; i < lqvaKarta + dalzhina - 1; i++){
                int segashno = karti[i] * (karti[lqvaKarta] + karti[lqvaKarta + dalzhina - 1])
                    + priTolkova[lqvaKarta][i - lqvaKarta + 1] + priTolkova[i][lqvaKarta + dalzhina - i];
                naiDobro = max(naiDobro, segashno);
            }

            priTolkova[lqvaKarta][dalzhina] = naiDobro;
        }
    }

    return priTolkova[lqv][dalag];
}

int main(){
    cin>>broiKarti;

    for(int i = 0; i < broiKarti; i++){
        cin>>karti[i];
    }

    /*for(int i = 0; i <= broiKarti; i++){
        for(int j = 0; j <= broiKarti; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    int naiHubavaPeshalba = sCycli(0, broiKarti);

    cout<<naiHubavaPeshalba<<endl;

    return 0;
}
