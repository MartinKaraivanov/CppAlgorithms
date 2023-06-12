#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;

int broiUchastnici;
int broiRundove;

int znaci[128][32];

const int tochki[3][3] =
{
    {0, +1, -1},
    {-1, 0, +1},
    {+1, -1, 0}
};

int igrai(int* parvo, int* vtoro, int rundove){
    int rezultat = 0;
    for(int i = 0; i < rundove; i++){
        rezultat += tochki[parvo[i]][vtoro[i]];
    }
    return rezultat;
}

int main(){

    cin>>broiUchastnici>>broiRundove;

    for(int i = 0; i < broiUchastnici; i++){
        string kombinaciq;
        cin>>kombinaciq;
        for(int j = 0; j < broiRundove; j++){
            if(kombinaciq[j] == 'H'){
                znaci[i][j] = 1;
            }else{
                if(kombinaciq[j] == 'X'){
                    znaci[i][j] = 2;
                }else{
                    znaci[i][j] = 0;
                }
            }
        }
    }

    if(broiRundove == 1){
        for(int i = 1; i < broiUchastnici; i++){
            if(znaci[i][0] != znaci[0][0]){
                cout<<0<<endl;
                return 0;
            }
        }
        cout<<1<<endl;
        return 0;
    }


    long long otgovor = 0;

    map<string, long long> kolkoPatiGoIma;

    int lqvaPolovina = broiRundove/2;
    int dqsnaPolovina = broiRundove - lqvaPolovina;

    int lqvaMaska = pow(3, lqvaPolovina);
    for(int i = 0; i < lqvaMaska; i++){
        int segashno[24];

        int vremenno = i;
        for(int j = 0; j < lqvaPolovina; j++){
            segashno[j] = vremenno%3;
            vremenno /= 3;
        }

        string rezultat(broiUchastnici, 'A');
        for(int j = 0; j < broiUchastnici; j++){
            rezultat[j] = 'A' - igrai(segashno, znaci[j], lqvaPolovina);
        }
        kolkoPatiGoIma[rezultat]++;
    }

    //cout<<"minahme parvoto"<<endl;

    int dqsnaMaska = pow(3, dqsnaPolovina);
    for(int i = 0; i < dqsnaMaska; i++){
        int segashno[24];

        int vremenno = i;
        for(int j = 0; j < dqsnaPolovina; j++){
            segashno[j] = vremenno%3;
            vremenno /= 3;
        }

        string rezultat(broiUchastnici, 'A');
        for(int j = 0; j < broiUchastnici; j++){
            rezultat[j] = 'A' + igrai(segashno, znaci[j] + lqvaPolovina, dqsnaPolovina);
        }

        if(kolkoPatiGoIma.find(rezultat) != kolkoPatiGoIma.end()){
            otgovor += kolkoPatiGoIma[rezultat];
        }
    }

    cout<<otgovor<<endl;


    return 0;
}
