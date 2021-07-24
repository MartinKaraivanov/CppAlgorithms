#include<iostream>
#include<map>
#include<vector>
using namespace std;

string vhodniDanni[6];

int raboteshtaLiEGlavata[4][2][2];

int gornaLenta[30000000];
int dolnaLenta[30000000];

int priTolkova[30000000][4];

int minimalenBroiNeetikiraniKashoni(int lqvIndexNaChastta, int rotaciq){
    //cout<<lqvIndexNaChastta<<" "<<rotaciq<<endl;
    if(lqvIndexNaChastta == 0){
        return (gornaLenta[lqvIndexNaChastta] + gornaLenta[lqvIndexNaChastta + 1] +
         dolnaLenta[lqvIndexNaChastta] + dolnaLenta[lqvIndexNaChastta + 1]) -
        (raboteshtaLiEGlavata[rotaciq][0][0]*gornaLenta[lqvIndexNaChastta] +
        raboteshtaLiEGlavata[rotaciq][0][1]*gornaLenta[lqvIndexNaChastta + 1] +
        raboteshtaLiEGlavata[rotaciq][1][0]*dolnaLenta[lqvIndexNaChastta] +
        raboteshtaLiEGlavata[rotaciq][1][1]*dolnaLenta[lqvIndexNaChastta + 1]);
    }

    if(priTolkova[lqvIndexNaChastta][rotaciq] > -1){
        return priTolkova[lqvIndexNaChastta][rotaciq];
    }

    int zaTuk =
        (gornaLenta[lqvIndexNaChastta] + gornaLenta[lqvIndexNaChastta + 1] +
         dolnaLenta[lqvIndexNaChastta] + dolnaLenta[lqvIndexNaChastta + 1]) -
        (raboteshtaLiEGlavata[rotaciq][0][0]*gornaLenta[lqvIndexNaChastta] +
        raboteshtaLiEGlavata[rotaciq][0][1]*gornaLenta[lqvIndexNaChastta + 1] +
        raboteshtaLiEGlavata[rotaciq][1][0]*dolnaLenta[lqvIndexNaChastta] +
        raboteshtaLiEGlavata[rotaciq][1][1]*dolnaLenta[lqvIndexNaChastta + 1]);

    int bezZavurtane = zaTuk + minimalenBroiNeetikiraniKashoni(lqvIndexNaChastta - 2, rotaciq);

    int zavurtaneNadqsno = zaTuk + minimalenBroiNeetikiraniKashoni(lqvIndexNaChastta - 2, (rotaciq + 1)%4);

    int zavurtaneNalqvo = zaTuk + minimalenBroiNeetikiraniKashoni(lqvIndexNaChastta - 2, (rotaciq - 1 + 4)%4);

    int naiDobroto = min(bezZavurtane, min(zavurtaneNadqsno, zavurtaneNalqvo));

    priTolkova[lqvIndexNaChastta][rotaciq] = naiDobroto;
    return naiDobroto;
}

void sCycli(int zaKoiLqvIndex){
    for(int rotaciq = 0; rotaciq < 4; rotaciq++){
        priTolkova[0][rotaciq] =
            (gornaLenta[0] + gornaLenta[0 + 1] + dolnaLenta[0] + dolnaLenta[0 + 1]) -
            (raboteshtaLiEGlavata[rotaciq][0][0]*gornaLenta[0] +
            raboteshtaLiEGlavata[rotaciq][0][1]*gornaLenta[0 + 1] +
            raboteshtaLiEGlavata[rotaciq][1][0]*dolnaLenta[0] +
            raboteshtaLiEGlavata[rotaciq][1][1]*dolnaLenta[0 + 1]);
    }

    for(int lqvIndexNaChastta = 2; lqvIndexNaChastta <= zaKoiLqvIndex; lqvIndexNaChastta++){
        for(int rotaciq = 0; rotaciq < 4; rotaciq++){
            int zaTuk =
                (gornaLenta[lqvIndexNaChastta] + gornaLenta[lqvIndexNaChastta + 1] +
                 dolnaLenta[lqvIndexNaChastta] + dolnaLenta[lqvIndexNaChastta + 1]) -
                (raboteshtaLiEGlavata[rotaciq][0][0]*gornaLenta[lqvIndexNaChastta] +
                raboteshtaLiEGlavata[rotaciq][0][1]*gornaLenta[lqvIndexNaChastta + 1] +
                raboteshtaLiEGlavata[rotaciq][1][0]*dolnaLenta[lqvIndexNaChastta] +
                raboteshtaLiEGlavata[rotaciq][1][1]*dolnaLenta[lqvIndexNaChastta + 1]);

            int bezZavurtane = zaTuk + priTolkova[lqvIndexNaChastta - 2][rotaciq];

            int zavurtaneNadqsno = zaTuk + priTolkova[lqvIndexNaChastta - 2][(rotaciq + 1)%4];

            int zavurtaneNalqvo = zaTuk + priTolkova[lqvIndexNaChastta - 2][(rotaciq - 1 + 4)%4];

            int naiDobroto = min(bezZavurtane, min(zavurtaneNadqsno, zavurtaneNalqvo));

            priTolkova[lqvIndexNaChastta][rotaciq] = naiDobroto;
        }
    }

}

int main(){
    string segashno;
    int broichnce = 0;

    while(cin>>segashno){
        vhodniDanni[broichnce] = segashno;
        broichnce++;
    }

    int dalzhinaNaLiniqta = vhodniDanni[broichnce - 2].size();

    for(unsigned int j = 0; j < vhodniDanni[broichnce - 2].size(); j++){
        gornaLenta[j] = vhodniDanni[broichnce - 2][j] - '0';
    }
    for(unsigned int j = 0; j < vhodniDanni[broichnce - 1].size(); j++){
        dolnaLenta[j] = vhodniDanni[broichnce - 1][j] - '0';
    }

    raboteshtaLiEGlavata[0][0][0] = 1;
    raboteshtaLiEGlavata[0][0][1] = 1;
    raboteshtaLiEGlavata[0][1][0] = 1;
    raboteshtaLiEGlavata[0][1][1] = 1;

    for(int i = 0; i < broichnce - 2; i++){
        int kade = vhodniDanni[i][0] - '0';

        if(kade == 1){
            raboteshtaLiEGlavata[0][0][0] = 0;
        }else{
            if(kade == 2){
                raboteshtaLiEGlavata[0][0][1] = 0;
            }else{
                if(kade == 3){
                    raboteshtaLiEGlavata[0][1][1] = 0;
                }else{
                    raboteshtaLiEGlavata[0][1][0] = 0;
                }
            }
        }
    }

    for(int i = 1; i < 4; i++){
        raboteshtaLiEGlavata[i][0][0] = raboteshtaLiEGlavata[i - 1][1][0];
        raboteshtaLiEGlavata[i][0][1] = raboteshtaLiEGlavata[i - 1][0][0];
        raboteshtaLiEGlavata[i][1][0] = raboteshtaLiEGlavata[i - 1][1][1];
        raboteshtaLiEGlavata[i][1][1] = raboteshtaLiEGlavata[i - 1][0][1];
    }

    int naiMalakBroiNeetikiraniKashoni = 1000000;

    /*for(int i = 0; i < 4; i++){
        cout<<i<<endl;
        cout<<raboteshtaLiEGlavata[i][0][0]<<" "<<raboteshtaLiEGlavata[i][0][1]<<endl;
        cout<<raboteshtaLiEGlavata[i][1][0]<<" "<<raboteshtaLiEGlavata[i][1][1]<<endl;
    }

    for(int i = 0; i < dalzhinaNaLiniqta; i++){
        cout<<gornaLenta[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < dalzhinaNaLiniqta; i++){
        cout<<dolnaLenta[i]<<" ";
    }
    cout<<endl;*/

    /*for(int i = 0; i < dalzhinaNaLiniqta; i++){
        for(int j = 0; j < 4; j++){
            priTolkova[i][j] = -1;
        }
    }*/

    sCycli(dalzhinaNaLiniqta - 2);

    for(int i = 0; i < 4; i++){
        int broiSTakavaNachalnaRotaciq = priTolkova[dalzhinaNaLiniqta - 2][i]; //minimalenBroiNeetikiraniKashoni(dalzhinaNaLiniqta - 2, i);
        naiMalakBroiNeetikiraniKashoni =
            min(naiMalakBroiNeetikiraniKashoni, broiSTakavaNachalnaRotaciq);
    }

    cout<<naiMalakBroiNeetikiraniKashoni<<endl;

    return 0;
}
