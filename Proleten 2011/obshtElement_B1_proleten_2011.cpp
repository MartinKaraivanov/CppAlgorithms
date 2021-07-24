#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int broiRedici;

int dalzhiniNaRedicite[1005];

vector<int> redici[1005];

int naiMalkotoChislo;

int main(){
    cin>>broiRedici;

    for(int i = 0; i < broiRedici; i++){
        cin>>dalzhiniNaRedicite[i];
    }

    for(int i = 0; i < broiRedici; i++){
        for(int j = 0; j < dalzhiniNaRedicite[i]; j++){
            int chislo;
            cin>>chislo;
            redici[i].push_back(chislo);
        }
    }

    for(int i = 0; i < broiRedici; i++){
        sort(redici[i].begin(), redici[i].end());
    }

    bool imameLiTakovaChislo = false;

    for(int i = 0; i < dalzhiniNaRedicite[0]; i++){
        int chislo = redici[0][i];
        bool navsqkadeLiGoIma = true;
        for(int j = 1; j < broiRedici; j++){
            /*bool tukImaLiGo = false;
            for(int k = 0; k < dalzhiniNaRedicite[j]; k++){
                if(redici[j][k] == chislo){
                    tukImaLiGo = true;
                    break;
                }
                if(redici[j][k] > chislo){
                    break;
                }
            }*/
            bool tukImaLiGo = binary_search(redici[j].begin(), redici[j].end(), chislo);
            if(tukImaLiGo == false){
                navsqkadeLiGoIma = false;
                break;
            }
        }
        if(navsqkadeLiGoIma == true){
            imameLiTakovaChislo = true;
            naiMalkotoChislo = chislo;
            break;
        }
    }

    if(imameLiTakovaChislo == true){
        cout<<naiMalkotoChislo<<endl;
    }else{
        cout<<"x"<<endl;
    }

    return 0;
}
