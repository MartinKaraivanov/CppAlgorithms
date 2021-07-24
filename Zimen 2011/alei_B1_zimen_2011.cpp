#include<iostream>
using namespace std;

int broiPloshtadki;
int broiRebra;

int toziKolkoSasediIma[150050];

int main(){
    cin>>broiPloshtadki>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        toziKolkoSasediIma[otKade]++;
        toziKolkoSasediIma[doKade]++;
    }

    int broiKragcheta = 0;

    for(int i = 1; i <= broiPloshtadki; i++){
        if(toziKolkoSasediIma[i] > 2){
            broiKragcheta += (toziKolkoSasediIma[i] - 2)/2;
        }
    }

    broiKragcheta++;

    cout<<broiKragcheta<<endl;

    return 0;
}
