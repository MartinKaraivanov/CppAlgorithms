#include<iostream>
#include<cmath>
using namespace std;

int broiKupchinki;
int kupchinki[10010];

int sumaNaZadaniqtaObshto;

int main(){
    cin>>broiKupchinki;

    for(int i = 0; i < broiKupchinki; i++){
        int tuk;
        cin>>tuk;
        sumaNaZadaniqtaObshto+=tuk;
        kupchinki[i] = tuk;
    }

    if(sumaNaZadaniqtaObshto%broiKupchinki != 0){
        cout<<-1<<endl;
        return 0;
    }

    int poKolkotrqbvaDaSa = sumaNaZadaniqtaObshto/broiKupchinki;

    int imameNuzhdaOt = poKolkotrqbvaDaSa - kupchinki[0];
    //int segaImame = kupchinki[0];

    int naiMnogoNavednazh = 0;

    for(int i = 0; i < broiKupchinki - 1; i ++){
        kupchinki[i] += imameNuzhdaOt;
        kupchinki[i + 1] -= imameNuzhdaOt;
        int segashno = abs(imameNuzhdaOt);
        naiMnogoNavednazh = max(naiMnogoNavednazh, segashno);
        imameNuzhdaOt = poKolkotrqbvaDaSa - kupchinki[i+1];
    }

    cout<<naiMnogoNavednazh<<endl;

    return 0;
}
