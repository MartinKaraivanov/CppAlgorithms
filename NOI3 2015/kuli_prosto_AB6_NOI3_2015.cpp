#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;

int broiKuli;

int kolkoPokriva[1000010];

vector<int> decaNaTozi[1000010];
int bashtaNaTozi[1000010];

int nomerche;

int toziKolkoKubchetaIma[1000010];

void nameriReshenie(int segashen){
    for(int i = 0; i < (int)decaNaTozi[segashen].size(); i++){
        nameriReshenie(decaNaTozi[segashen][i]);
    }

    nomerche++;
    toziKolkoKubchetaIma[segashen] = nomerche;
}

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKuli;*/

    scanf("%i", &broiKuli);

    for(int i = 1; i <= broiKuli; i++){
        //cin>>kolkoPokriva[i];
        scanf("%i", &kolkoPokriva[i]);
    }

    vector<int> s;

    //s.reserve(broiKuli + 1);

    for(int i = 1; i <= broiKuli; i++){
        //if (kolkoPokriva[i] > 0){
          //  decaNaTozi[i].reserve(kolkoPokriva[i] + 1);
        //}

        for(int j = 0; j < kolkoPokriva[i]; j++){
            if(s.size() == 0){
                cout<<"prazen e steka"<<endl;
            }

            int naiOtgore = s.back();
            s.pop_back();

            bashtaNaTozi[naiOtgore] = i;
            decaNaTozi[i].push_back(naiOtgore);

        }

        s.push_back(i);
    }

    while(s.size() > 0){
        int naiOtgore = s.back();
        s.pop_back();

        bashtaNaTozi[naiOtgore] = broiKuli + 1;
        decaNaTozi[broiKuli + 1].push_back(naiOtgore);
    }

    nameriReshenie(broiKuli + 1);

    for(int i = 1; i <= broiKuli; i++){
        //cout<<toziKolkoKubchetaIma[i]<<endl;
        printf("%i \n", toziKolkoKubchetaIma[i]);
    }

    return 0;
}
