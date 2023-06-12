#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct Koordinati{
    long long x;
    long long y;
};

long long broiKvadrati;
long long broiTochki;

Koordinati centrove[50010];
Koordinati tochki[500010];

long long broiZaqvki;
long long zaqvki[500010];

long long nujnaStrana[500010];

long long otgovori[500010];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKvadrati>>broiTochki;

    for(long long i = 0; i < broiKvadrati; i++){
        cin>>centrove[i].x>>centrove[i].y;
    }

    for(long long i = 0; i < broiTochki; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    cin>>broiZaqvki;

    for(long long i = 0; i < broiZaqvki; i++){
        cin>>zaqvki[i];
    }

    for(long long i = 0; i < broiTochki; i++){
        long long nujno = max(abs(tochki[i].x - centrove[0].x), abs(tochki[i].y - centrove[0].y));
        for(long long j = 1; j < broiKvadrati; j++){
            long long tuka = max(abs(tochki[i].x - centrove[j].x), abs(tochki[i].y - centrove[j].y));

            nujno = min(nujno, tuka);
        }

        nujnaStrana[i] = nujno*2;
    }

    sort(nujnaStrana, nujnaStrana + broiTochki);

    for(long long q = 0; q < broiZaqvki; q++){
        long long tukaStrana = zaqvki[q];

        long long lqvKrai = 0;
        long long desenKrai = broiTochki - 1;

        while(lqvKrai < desenKrai){
            long long sredata = (lqvKrai + desenKrai)/2;

            if(nujnaStrana[sredata] > tukaStrana){
                desenKrai = sredata;
            }else{
                lqvKrai = sredata + 1;
            }
        }

        if(nujnaStrana[lqvKrai] > tukaStrana){
            lqvKrai--;
        }

        otgovori[q] = lqvKrai + 1;

    }

    for(long long i = 0; i < broiZaqvki; i++){
        cout<<otgovori[i]<<" ";
    }
    cout<<endl;


    return 0;
}
