#include<iostream>
#include<algorithm>
using namespace std;

int broiTezhesti;
vector<int> tezhina;

vector<int> indexi;

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
        int tuk;
        cin>>tuk;
        tezhina.push_back(tuk);
        indexi.push_back(i);
    }

    int broiVazmozhnosti = 0;

    sort(indexi.begin(), indexi.end());

    do{
        broiVazmozhnosti += broiNachiniZaSlagane(indexi[broiTezhesti], 0, 0);
    }while(next_permutation(indexi.begin(), indexi.end()));

    cout<<broiVazmozhnosti<<endl;

    return 0;
}
