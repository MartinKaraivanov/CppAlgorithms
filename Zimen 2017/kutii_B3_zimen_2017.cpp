#include<iostream>
using namespace std;

struct DanniZaKutiq{
    int visochina;
    int ednaStrana;
    int drugaStrana;
};

int broiKutii;
DanniZaKutiq kutii[10010];

int priTolkova[10010];

int maximalnaVisochina(int sPoslednaKutiq){
    if(sPoslednaKutiq == 0){
        return kutii[sPoslednaKutiq].visochina;
    }

    if(priTolkova[sPoslednaKutiq] > 0){
        return priTolkova[sPoslednaKutiq];
    }

    int segashnaMaximalna = 0;

    for(int slKutiq = 0; slKutiq < sPoslednaKutiq; slKutiq++){
        int eventualno = kutii[sPoslednaKutiq].visochina;

        if((kutii[slKutiq].ednaStrana >= kutii[sPoslednaKutiq].ednaStrana &&
            kutii[slKutiq].drugaStrana >= kutii[sPoslednaKutiq].drugaStrana) ||
            (kutii[slKutiq].ednaStrana >= kutii[sPoslednaKutiq].drugaStrana &&
            kutii[slKutiq].drugaStrana >= kutii[sPoslednaKutiq].ednaStrana))
        {
            eventualno += maximalnaVisochina(slKutiq);

        }

        segashnaMaximalna = max(segashnaMaximalna, eventualno);
    }

    priTolkova[sPoslednaKutiq] = segashnaMaximalna;
    return segashnaMaximalna;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiKutii;

    for(int i = 0; i < broiKutii; i++){
        cin>>kutii[i].visochina>>kutii[i].ednaStrana>>kutii[i].drugaStrana;
    }

    int naiGolqmaVisochina = 0;

    for(int i = 0; i < broiKutii; i++){
        naiGolqmaVisochina = max(naiGolqmaVisochina, maximalnaVisochina(i));
    }

    cout<<naiGolqmaVisochina<<endl;

    return 0;
}
