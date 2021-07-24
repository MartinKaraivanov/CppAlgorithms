#include<iostream>
#include<queue>
using namespace std;

int broiSastezaniq;
int broiUchenici;

vector<int> koiUchastvaTuk[2050];

bool stanchoTukLiE[2050];

bool koiPesniZnae[2010][2010];

int broiPesni;

int main(){
    cin>>broiSastezaniq>>broiUchenici;

    for(int i = 0; i < broiSastezaniq; i++){
        int kolkoImaTuka;
        cin>>kolkoImaTuka;
        for(int j = 0; j < kolkoImaTuka; j++){
            int uchenik;
            cin>>uchenik;
            if(uchenik == 1){
                stanchoTukLiE[i] = true;
            }
            koiUchastvaTuk[i].push_back(uchenik);
        }
    }

    for(int i = 0; i < broiSastezaniq; i++){
        if(stanchoTukLiE[i]){
            broiPesni++;
            for(int j = 0; j < koiUchastvaTuk[i].size(); j++){
                koiPesniZnae[koiUchastvaTuk[i][j]][broiPesni] = true;
            }
        }else{
            for(int j = 0; j < koiUchastvaTuk[i].size(); j++){
                for(int k = 1; k <= broiPesni; k++){
                    if(koiPesniZnae[koiUchastvaTuk[i][j]][k] == true){
                        for(int u = 0; u < koiUchastvaTuk[i].size(); u++){
                            koiPesniZnae[koiUchastvaTuk[i][u]][k] = true;
                        }
                    }
                }
            }
        }
    }

    int broiVseznaikovci = 0;

    queue<int> q;

    for(int i = 2; i <= broiUchenici; i++){
        bool vsichkiPesniLiZnae = true;
        for(int j = 1; j <= broiPesni; j++){
            if(koiPesniZnae[i][j] == false){
                vsichkiPesniLiZnae = false;
                break;
            }
        }
        if(vsichkiPesniLiZnae == true){
            broiVseznaikovci++;
            q.push(i);
        }
    }

    cout<<broiVseznaikovci<<endl;

    while(q.empty() == false){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
