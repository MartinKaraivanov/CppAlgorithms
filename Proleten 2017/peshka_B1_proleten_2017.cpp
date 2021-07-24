#include<iostream>
#include<vector>
using namespace std;

long long poletaZaIzminavane;
int broiZapisani;

bool imameLiTova[10500];

vector<long long> vazmoshniHodove;

const long long mnogo = 1000000007;

long long priTolkova[10500];

long long maximalenBroiNachini(long long brPoleta){
    if(brPoleta == 0){
        return 1;
    }
    if(brPoleta < 0){
        return 0;
    }
    if(priTolkova[brPoleta] > -1){
        return priTolkova[brPoleta]%mnogo;
    }

    long long zaTuk = 0;

    for(unsigned int i = 0; i < vazmoshniHodove.size(); i++){
        long long segashno = (maximalenBroiNachini(brPoleta - vazmoshniHodove[i]))%mnogo;

        zaTuk = (zaTuk + segashno)%mnogo;
    }

    int zaVrasht = zaTuk%mnogo;

    priTolkova[brPoleta] = zaVrasht;
    return zaVrasht;
}

int sCycli(int zaBroiPoleta){
    priTolkova[0] = 1;

    for(int brPoleta = 1; brPoleta <= zaBroiPoleta; brPoleta++){
        long long zaTuk = 0;

        for(unsigned int i = 0; i < vazmoshniHodove.size(); i++){
            if(brPoleta - vazmoshniHodove[i] >= 0){
                long long segashno = (priTolkova[brPoleta - vazmoshniHodove[i]])%mnogo;

                zaTuk = (zaTuk + segashno)%mnogo;
            }
        }

        priTolkova[brPoleta] = zaTuk%mnogo;
    }

    return priTolkova[zaBroiPoleta]%mnogo;
}

int main(){
    cin>>poletaZaIzminavane>>broiZapisani;

    for(int i = 0; i < broiZapisani; i++){
        int chi;
        cin>>chi;
        if(imameLiTova[chi] == false){
            vazmoshniHodove.push_back(chi);
            imameLiTova[chi] = true;
        }
    }

    /*for(int i = 0; i <= poletaZaIzminavane; i++){
        priTolkova[i] = -1;
    }*/

    int broiNachini = sCycli(poletaZaIzminavane);

    cout<<broiNachini<<endl;

    return 0;
}
