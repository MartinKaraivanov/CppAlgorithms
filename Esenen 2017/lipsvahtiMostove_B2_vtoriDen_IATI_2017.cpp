#include<iostream>
using namespace std;

struct DanniZaOtgovor{
    int otKude;
    int doKude;
};

int broiOstrovi;
int broiMostove;

int broiSreshtaniqNaTozi[1005];

DanniZaOtgovor otgovori[1005];
int broiOtgovori;

int main(){
    cin>>broiOstrovi>>broiMostove;

    for(int i = 0; i < broiMostove; i++){
        int otKude;
        int doKude;
        cin>>otKude>>doKude;

        broiSreshtaniqNaTozi[otKude]++;
        broiSreshtaniqNaTozi[doKude]++;
    }

    int parviZaNovMost = -1;
    int vtoriZaNovMost = -1;

    for(int i = 1; i <= broiOstrovi; i++){
        if(broiSreshtaniqNaTozi[i]%2 == 1){
            if(parviZaNovMost == -1){
                parviZaNovMost = i;
                broiSreshtaniqNaTozi[i]++;
            }else{
                vtoriZaNovMost = i;
                broiSreshtaniqNaTozi[i]++;
                otgovori[broiOtgovori] = {parviZaNovMost, vtoriZaNovMost};
                broiOtgovori++;
                parviZaNovMost = -1;
                vtoriZaNovMost = -1;
            }
        }
        if(broiSreshtaniqNaTozi[i] == 0){
            if(i < broiOstrovi){
                otgovori[broiOtgovori] = {i, i + 1};
                broiOtgovori++;
                otgovori[broiOtgovori] = {i, i + 1};
                broiOtgovori++;
                broiSreshtaniqNaTozi[i] += 2;
                broiSreshtaniqNaTozi[i + 1] += 2;
            }else{
                otgovori[broiOtgovori] = {i, 1};
                broiOtgovori++;
                otgovori[broiOtgovori] = {i, 1};
                broiOtgovori++;
                broiSreshtaniqNaTozi[i] += 2;
                broiSreshtaniqNaTozi[1] += 2;
            }
        }
    }

    cout<<broiOtgovori<<endl;

    for(int i = 0; i < broiOtgovori; i++){
        cout<<otgovori[i].otKude<<" "<<otgovori[i].doKude<<endl;
    }

    return 0;
}
