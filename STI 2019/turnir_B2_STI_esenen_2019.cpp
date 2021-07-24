#include<iostream>
#include<vector>
using namespace std;

int broiIgrachi;

bool toziPobedilLiETozi[1010][1010];

vector<int> otgovor;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiIgrachi;

    for(int i = 0; i < broiIgrachi; i++){
        int broiPobediNaTozi;
        cin>>broiPobediNaTozi;
        for(int j = 0; j < broiPobediNaTozi; j++){
            int koiEPobedil;
            cin>>koiEPobedil;
            toziPobedilLiETozi[i][koiEPobedil] = true;
        }
    }

    otgovor.push_back(0);

    for(int i = 1; i < broiIgrachi; i++){
        if(toziPobedilLiETozi[i][otgovor[0]] == true){
            otgovor.insert(otgovor.begin(), i);
        }else{
            if(toziPobedilLiETozi[otgovor[otgovor.size() - 1]][i] == true){
                otgovor.push_back(i);
            }else{
                for(unsigned int j = 0; j < otgovor.size() - 1; j++){
                    if(toziPobedilLiETozi[otgovor[j]][i] == true && toziPobedilLiETozi[i][otgovor[j + 1]] == true){
                        otgovor.insert(otgovor.begin() + j + 1, i);
                        break;
                    }
                }
            }
        }

        /*for(unsigned int k = 0; k < otgovor.size(); k++){
            cout<<otgovor[k]<<" ";
        }
        cout<<endl;*/
    }

    for(unsigned int i = 0; i < otgovor.size(); i++){
        cout<<otgovor[i]<<" ";
    }

    cout<<endl;

    return 0;
}
