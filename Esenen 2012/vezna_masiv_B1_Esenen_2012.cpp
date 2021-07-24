#include<iostream>
#include<algorithm>
using namespace std;

int broiTezhesti;
int tezhina[10];

int indexi[10];

int broiNachiniZaSlagane(int koqTezhest, int tezhinaLqvo, int tezhinaDqsno){
    if(tezhinaLqvo > tezhinaDqsno){
        return 0;
    }

    if(koqTezhest == 0){
        return 1;
    }

    int broiAkoSlozhimNaDqsnoto =
        broiNachiniZaSlagane(koqTezhest - 1, tezhinaLqvo, tezhinaDqsno + tezhina[indexi[koqTezhest]]);
    int broiAkoSlozhimNaLqvoto =
        broiNachiniZaSlagane(koqTezhest - 1, tezhinaLqvo + tezhina[indexi[koqTezhest]], tezhinaDqsno);

    int zaTuk = broiAkoSlozhimNaDqsnoto + broiAkoSlozhimNaLqvoto;

    return zaTuk;
}

int main(){
    cin>>broiTezhesti;

    for(int i = 1; i <= broiTezhesti; i++){
        cin>>tezhina[i];
        indexi[i] = i;
    }

    int broiVazmozhnosti = 0;

    do{
        broiVazmozhnosti += broiNachiniZaSlagane(broiTezhesti, 0, 0);
    }while(next_permutation(indexi + 1, indexi + 1 + broiTezhesti));

    cout<<broiVazmozhnosti<<endl;

    return 0;
}
