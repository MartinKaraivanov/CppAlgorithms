#include<iostream>
using namespace std;

int broiChisla;
int chisloNaTaziPoziciq[1000010];
int naiGolqmoChislo;

int razmerNaDarvoto;

long long broiPoGolemiDoTuk[2100010];

void nameriRazmerNaDarvoto(){
    int i = 1;
    while(i < broiChisla){
        i *= 2;
    }
    razmerNaDarvoto = i*2;
}

int daiListo(int index){
    return index + razmerNaDarvoto/2;
}

void update(int koeChislo, int stoinost){
    int index = daiListo(koeChislo);
    while(index > 0){
        broiPoGolemiDoTuk[index] += stoinost;
        index /= 2;
    }
}

int querySuma(int otKoe, int doKoe){
    int lqvIndex = daiListo(otKoe);
    int desenIndex = daiListo(doKoe);

    if(lqvIndex == desenIndex){
        return broiPoGolemiDoTuk[lqvIndex];
    }

    int suma = broiPoGolemiDoTuk[lqvIndex] + broiPoGolemiDoTuk[desenIndex];
    while(lqvIndex + 1 != desenIndex){
        if(lqvIndex % 2 == 0){
            suma += broiPoGolemiDoTuk[lqvIndex + 1];
        }
        if(desenIndex % 2 == 1){
            suma += broiPoGolemiDoTuk[desenIndex - 1];
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return suma;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiChisla;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisloNaTaziPoziciq[i];
    }

    nameriRazmerNaDarvoto();
    //cout<<razmerNaDarvoto<<endl;

    naiGolqmoChislo = broiChisla;

    long long broiInversii = 0;

    for(int i = 1; i <= broiChisla; i++){
        int broiPoGolemi = querySuma(chisloNaTaziPoziciq[i], naiGolqmoChislo);
        broiInversii+=broiPoGolemi;

        update(chisloNaTaziPoziciq[i], 1);
    }

    cout<<broiInversii<<endl;

    return 0;
}
