#include<iostream>
#include<algorithm>
using namespace std;

int broiChisla;

int chisla[1000010];

int broiPatiTovaEDvoika[3000010];

int broiPatiTovaETroika[3000010];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    sort(chisla, chisla + broiChisla);

    /*for(int i = 0; i < broiChisla; i++){
        for(int j = i + 1; j < broiChisla; j++){
            if(chisla[j]%chisla[i] == 0){
                broiPatiTovaEDvoika[j]++;
                broiPatiTovaETroika[j] += broiPatiTovaEDvoika[i];
            }
        }
    }*/

    for(int i = 0; i < broiChisla; i++){
        for(int j = chisla[i]+chisla[i]; j <= chisla[broiChisla - 1]; j += chisla[i]){
            broiPatiTovaEDvoika[j]++;
            broiPatiTovaETroika[j] += broiPatiTovaEDvoika[chisla[i]];
            //cout<<"sega sam "<<chisla[i]<<" i napravih "<<j<<" da e dvoika "<<broiPatiTovaEDvoika[j];
            //cout<<" i "<<broiPatiTovaETroika[j]<<" pati troika "<<endl;
        }
    }

    int broiTroiki = 0;

    for(int i = 0; i < broiChisla; i++){
        broiTroiki += broiPatiTovaETroika[chisla[i]];
    }

    cout<<broiTroiki<<endl;

    return 0;
}
