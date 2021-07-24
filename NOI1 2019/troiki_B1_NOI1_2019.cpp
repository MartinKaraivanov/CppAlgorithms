#include<iostream>
using namespace std;

int broiOtsechki;
int dalzhini[210];

bool imameLiGi[200][200][200];

int main(){
    cin>>broiOtsechki;

    for(int i = 0; i < broiOtsechki; i++){
        cin>>dalzhini[i];
    }

    int broichence = 0;

    for(int i = 0; i < broiOtsechki; i++){
        for(int j = 0; j < broiOtsechki; j++){
            if(i != j && dalzhini[i] != dalzhini[j]){

                for(int k = 0; k < broiOtsechki; k++){

                    if(i != k && k != j && dalzhini[i] != dalzhini[k] && dalzhini[k] != dalzhini[j]){
                        if(imameLiGi[dalzhini[i]][dalzhini[j]][dalzhini[k]] == false){
                            if(dalzhini[i] + dalzhini[k] > dalzhini[j] && dalzhini[k] + dalzhini[j] > dalzhini[i] &&
                               dalzhini[i] + dalzhini[j] > dalzhini[k])
                            {
                                broichence++;
                                //cout<<dalzhini[i]<<" "<<dalzhini[k]<<" "<<dalzhini[j]<<endl;
                                imameLiGi[dalzhini[i]][dalzhini[j]][dalzhini[k]] = true;
                                imameLiGi[dalzhini[i]][dalzhini[k]][dalzhini[j]] = true;
                                imameLiGi[dalzhini[j]][dalzhini[i]][dalzhini[k]] = true;
                                imameLiGi[dalzhini[j]][dalzhini[k]][dalzhini[i]] = true;
                                imameLiGi[dalzhini[k]][dalzhini[j]][dalzhini[i]] = true;
                                imameLiGi[dalzhini[k]][dalzhini[i]][dalzhini[j]] = true;
                            }
                        }
                    }

                }

            }
        }
    }

    cout<<broichence<<endl;

    return 0;
}
