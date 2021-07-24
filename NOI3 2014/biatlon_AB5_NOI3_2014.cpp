#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

struct DanniZaVrah{
    int broiVTova;
    int lqvNomer;
    int desenNomer;
    int stoinost;
};

int broiUchastnici;

//int toziKolkoSaGoIzprevarili[1000010];

int otgovori[1000010];

int broiNujniVarhove;

int darvo[3000010];

void praveneNaBroiNujniVarhove(){
    int brNujniVrhv = 1;

    while(true){
        if(brNujniVrhv >= broiUchastnici){
            brNujniVrhv <<= 1;   /////////// << i >> vmesto *2 i /2
            break;
        }

        brNujniVrhv <<= 1;
    }

    broiNujniVarhove = brNujniVrhv;
}

inline int daiListo(int index){
    return index + (broiNujniVarhove>>1); /// delenoNa2
}

void stroeneNaDarvoto(){
    for(int i = 0; i < broiUchastnici; i++){
        darvo[daiListo(i)] = 1;
    }

    for(int i = daiListo(0) - 1; i > 0; i--){
        darvo[i] = darvo[i<<1] + darvo[(i<<1) + 1];
    }
}

void update(int koi, int sKolko){
    int index = daiListo(koi);

    while(index > 0){
        darvo[index] += sKolko;
        index >>= 1;
    }
}

int query(int kolkoNuli){
    int segashen = 1;

    int broiNuli = 0;

    int doKade = daiListo(0);

    while(segashen < doKade){
        if(darvo[segashen<<1] + broiNuli >= kolkoNuli){
            segashen = segashen<<1;
        }else{
            broiNuli += darvo[segashen<<1];
            segashen = (segashen<<1) + 1;
        }
    }

    int kadeShteE = segashen - doKade;

    return kadeShteE;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //cin>>broiUchastnici;

    scanf("%i", &broiUchastnici);

    /*for(int i = 0; i < broiUchastnici; i++){
        cin>>toziKolkoSaGoIzprevarili[i];
    }*/

    praveneNaBroiNujniVarhove();
    stroeneNaDarvoto();

    for(int i = 0; i < broiUchastnici; i++){
        //int koqNulaIskame = toziKolkoSaGoIzprevarili[i] + 1;
        int koqNulaIskame;
        //cin>>koqNulaIskame;
        scanf("%i", &koqNulaIskame);
        koqNulaIskame++;

        int kade = query(koqNulaIskame);

        otgovori[kade] = i + 1;

        update(kade, -1);
    }

    for(int i = 0; i < broiUchastnici; i++){
        //cout<<otgovori[i]<<endl;
        printf("%i \n", otgovori[i]);
    }

    return 0;
}
