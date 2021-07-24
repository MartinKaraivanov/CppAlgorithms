#include<iostream>
using namespace std;

int broiChisla;
int chisla[1050];

int naiMalkoChislo = 1000000;
int naiGolqmoChislo;

long long priTolko[1000][1000];

const long long Mnogo = 123456789012345;

long long broiProgressii(int indexche, int promqna){

    if(priTolko[indexche][promqna] >= 0){
        return priTolko[indexche][promqna];
    }

    long long broiche = 0;

    int kolkoPatiSmeQViknali = 0;

    for(int i = 0; i < indexche; i++){
        long long zaTozi = 0;
        if(chisla[i] + promqna == chisla[indexche]){
            zaTozi = broiProgressii(i, promqna);
            kolkoPatiSmeQViknali++;
        }
        broiche += zaTozi;
    }

    long long novotoChislo = (broiche + kolkoPatiSmeQViknali)%Mnogo;
    priTolko[indexche][promqna] = novotoChislo;

    return novotoChislo;
}

int main(){
    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
        naiGolqmoChislo = max(naiGolqmoChislo, chisla[i]);
        naiMalkoChislo = min(naiMalkoChislo, chisla[i]);
    }

    int naiGolqmoD = naiGolqmoChislo - naiMalkoChislo;

    for(int i = 0; i < broiChisla; i++){
        for(int j = 0; j <= naiGolqmoD; j++){
            priTolko[i][j] = -1;
        }
    }

    long long obshtBroiProgressii = 0;

    //cout<<naiGolqmoChislo<<" "<<naiMalkoChislo<<" "<<naiGolqmoChislo-naiMalkoChislo<<endl;

    for(int i = 0; i < broiChisla; i++){
        for(int d = 1; d <= naiGolqmoD; d++){
            long long segashnoDobavqne = broiProgressii(i, d);
            obshtBroiProgressii = (obshtBroiProgressii + segashnoDobavqne)%Mnogo;
            if(segashnoDobavqne > 0){
                //cout<<segashnoDobavqne<<" "<<i<<" "<<d<<endl;
            }
        }
    }

    cout<<obshtBroiProgressii<<endl;

    return 0;
}
