#include<iostream>
#include<vector>
using namespace std;

long long priTolkova[64][64];

long long izberi(long long otTolkova, long long tolkova){

    if(tolkova == 1){
        return otTolkova;
    }
    if(tolkova > otTolkova){
        return 0;
    }
    if(tolkova == otTolkova){
        return 1;
    }

    if(priTolkova[otTolkova][tolkova] > -1){
        return priTolkova[otTolkova][tolkova];
    }

    long long tuka = izberi(otTolkova - 1, tolkova) + izberi(otTolkova - 1, tolkova - 1);

    priTolkova[otTolkova][tolkova] = tuka;
    return tuka;
}

long long kolkoKombinaciiImaPredi(vector<long long> kombinaciq){

    long long broiche = 0;

    long long prednoto = 0;

    for(long long i = 0; i < 6; i++){
        for(long long j = prednoto + 1; j < kombinaciq[i]; j++){
            long long tukaDobavka = izberi(49 - j, 6 - 1 - i);
            broiche += tukaDobavka;
        }
        prednoto = kombinaciq[i];
    }


    return broiche;
}

vector<long long> parvaKombinaciq;
vector<long long> vtoraKombinaciq;

int main(){

    for(int i = 0; i < 6; i++){
        int tukaChi;
        cin>>tukaChi;
        parvaKombinaciq.push_back(tukaChi);
    }

    for(int i = 0; i < 6; i++){
        int tukaChi;
        cin>>tukaChi;
        vtoraKombinaciq.push_back(tukaChi);
    }

    for(int i = 0; i <= 49; i++){
        for(int j = 0; j <= 6; j++){
            priTolkova[i][j] = -1;
        }
    }

    long long nomerParva = kolkoKombinaciiImaPredi(parvaKombinaciq);

    long long nomerVtora = kolkoKombinaciiImaPredi(vtoraKombinaciq);

    cout<<max(nomerVtora - nomerParva - 1, (long long)0)<<endl;

    return 0;
}
