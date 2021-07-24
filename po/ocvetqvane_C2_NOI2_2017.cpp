#include<iostream>
using namespace std;

int broiPitanki;

long long broiCvetoveZaVarha[101000];
int broiVarhoveNaToziGraph;
int otKoiVrahIdva[101000];
int visited[101000];

int otgovori[15];

void nulirane(){
    for(int i = 0; i <= broiVarhoveNaToziGraph; i++){
        broiCvetoveZaVarha[i]=0;
        otKoiVrahIdva[i] = 0;
        visited[i]=0;
    }
}

int main(){
    cin>>broiPitanki;

    for(int m = 0; m < broiPitanki; m++){
        int broiVarhove;
        cin>>broiVarhove;
        broiVarhoveNaToziGraph = broiVarhove;
        for(int j=1;j<=broiVarhove;j++){
            int otKoiVrahImaRebro;
            cin>>otKoiVrahImaRebro;
            otKoiVrahIdva[j] = otKoiVrahImaRebro;
        }

        for(int i = 1; i <= broiVarhoveNaToziGraph; i++){
            broiCvetoveZaVarha[i]++;
            broiCvetoveZaVarha[otKoiVrahIdva[i]]++;
        }


        int otgovor = 0;
        int naiGolqmBroiR = 0;
        for(int j = 1; j <= broiVarhoveNaToziGraph; j++){
            if(broiCvetoveZaVarha[j]>naiGolqmBroiR){
                naiGolqmBroiR = broiCvetoveZaVarha[j];
            }
        }
        otgovor = naiGolqmBroiR;

        bool imameLiNechetenCycle = false;

        for(int k = 1; k <= broiVarhoveNaToziGraph; k++){
            int h=k;
            int d=1;

            int dalzhinaNaCycle=0;

            if(visited[k] == 0){
                while(true){
                    if(visited[h]==0){
                        visited[h] = d;
                    }else{
                        dalzhinaNaCycle = d - visited[h];
                        break;
                    }
                    h = otKoiVrahIdva[h];
                    d++;
                }

                if(dalzhinaNaCycle%2==1){
                    imameLiNechetenCycle = true;
                    break;
                }

            }

        }

        int nuzhniCvetoveSamoZaCyclea;

        if(!imameLiNechetenCycle){
            nuzhniCvetoveSamoZaCyclea = 2;
        }else{
            nuzhniCvetoveSamoZaCyclea = 3;
        }

        otgovori[m] = max(otgovor, nuzhniCvetoveSamoZaCyclea);

        nulirane();

    }

    for(int i = 0; i < broiPitanki; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
