#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int broiKupchinki;

long long orehiVKupch[100010];

int suma;
int nujno;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiKupchinki;

    cin>>orehiVKupch[1];
    suma += orehiVKupch[1];
    orehiVKupch[1] = 0;

    for(int i = 2; i <= broiKupchinki; i++){
        cin>>orehiVKupch[i];
        suma += orehiVKupch[i];

        orehiVKupch[i] = orehiVKupch[i-1] - orehiVKupch[i];
    }

    nujno = suma/broiKupchinki;

    for(int i = 2; i <= broiKupchinki; i++){
        orehiVKupch[i] += (i-1)*nujno;
    }

    sort(orehiVKupch+1, orehiVKupch+broiKupchinki+1);

    int sredata = (broiKupchinki + 1)/2;

    long long broiPremestvaniq = 0;

    for(int i = 1; i < sredata; i++){
        broiPremestvaniq -= orehiVKupch[i];
    }

    for(int i = sredata+1; i <= broiKupchinki; i++){
        broiPremestvaniq += orehiVKupch[i];
    }

    if(broiKupchinki % 2 == 0){
        broiPremestvaniq -= orehiVKupch[sredata];
    }

    cout<<broiPremestvaniq<<endl;


    return 0;
}
