#include<iostream>
#include<queue>
#include<vector>
using namespace std;

long long broiPalachinki;
int broiKotloni;

int vremeZaToziKotlon[23];

long long broiPalachinkiZaTakovaVreme(long long zaVreme){
    long long broiPl = 0;

    for(int i = 0; i < broiKotloni; i++){
        broiPl += (zaVreme / vremeZaToziKotlon[i]);
    }

    return broiPl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiPalachinki>>broiKotloni;

    for(int i = 0; i < broiKotloni; i++){
        cin>>vremeZaToziKotlon[i];
    }

    long long lqvKrai = 0;
    long long desenKrai = broiPalachinki*vremeZaToziKotlon[0];

    while(lqvKrai < desenKrai){
        long long poSredata = (lqvKrai + desenKrai)/2;

        if(broiPalachinkiZaTakovaVreme(poSredata) >= broiPalachinki){
            desenKrai = poSredata;
        }else{
            lqvKrai = poSredata + 1;
        }
    }

    long long kogaSheStaneGotovo = lqvKrai;

    cout<<kogaSheStaneGotovo<<endl;

    return 0;
}
