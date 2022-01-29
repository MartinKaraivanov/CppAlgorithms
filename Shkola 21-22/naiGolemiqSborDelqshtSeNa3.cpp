#include<iostream>
#include<vector>
using namespace std;

int broiRedove;

vector<int> chisla[1000];

int naiGolqmataSuma(int doKoiRed, int sKakuvOstatuk){
    if(doKoiRed == 0){
        if(sKakuvOstatuk == 0){
            return 0;
        }else{
            return -1000000;
        }
    }

    int naiGolqmotoSOst0 = -1000000;
    int naiGolqmotoSOst1 = -1000000;
    int naiGolqmotoSOst2 = -1000000;

    for(int i = 0; i < (int)chisla[doKoiRed].size(); i++){
        int segChislo = chisla[doKoiRed][i];
        if(segChislo%3 == 0){
            naiGolqmotoSOst0 = max(naiGolqmotoSOst0, segChislo);
        }
        if(segChislo%3 == 1){
            naiGolqmotoSOst1 = max(naiGolqmotoSOst1, segChislo);
        }
        if(segChislo%3 == 2){
            naiGolqmotoSOst2 = max(naiGolqmotoSOst2, segChislo);
        }
    }

    int priIzpNaS0 = naiGolqmotoSOst0 + naiGolqmataSuma(doKoiRed - 1, sKakuvOstatuk);
    int priIzpNaS1 = naiGolqmotoSOst1 + naiGolqmataSuma(doKoiRed - 1, (sKakuvOstatuk + 3 - 1)%3);
    int priIzpNaS2 = naiGolqmotoSOst2 + naiGolqmataSuma(doKoiRed - 1, (sKakuvOstatuk + 3 - 2)%3);

    return max(priIzpNaS0, max(priIzpNaS1, priIzpNaS2));
}

int main(){

    cin>>broiRedove;

    for(int i = 1; i <= broiRedove; i++){
        int broiNaReda;

        cin>>broiNaReda;

        for(int j = 0; j < broiNaReda; j++){
            int tuka;
            cin>>tuka;

            chisla[i].push_back(tuka);
        }
    }

    cout<<naiGolqmataSuma(broiRedove, 0)<<endl;

    return 0;
}
