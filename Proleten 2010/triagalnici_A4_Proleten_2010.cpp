#include<iostream>
#include<vector>
using namespace std;

int broiOtsechki;
vector<int> presechniTochki[64];

int broiRazlichniTochki;

int otsechkataNaTiqDveTochki[64][64];

int main(){

    cin>>broiOtsechki;

    for(int i = 1; i <= broiOtsechki; i++){
        int broiTuka;
        cin>>broiTuka;

        for(int j = 0; j < broiTuka; j++){
            int tochkaNomer;
            cin>>tochkaNomer;

            broiRazlichniTochki = max(broiRazlichniTochki, tochkaNomer);

            presechniTochki[i].push_back(tochkaNomer);
        }
    }

    for(int i = 1; i <= broiOtsechki; i++){
        for(int j = 0; j < (int)presechniTochki[i].size(); j++){
            for(int k = j + 1; k < (int)presechniTochki[i].size(); k++){
                otsechkataNaTiqDveTochki[presechniTochki[i][j]][presechniTochki[i][k]] = i;
                otsechkataNaTiqDveTochki[presechniTochki[i][k]][presechniTochki[i][j]] = i;
            }
        }
    }

    int broiTriagalnici = 0;

    for(int i = 1; i <= broiRazlichniTochki; i++){
        for(int j = i + 1; j <= broiRazlichniTochki; j++){
            for(int k = j + 1; k <= broiRazlichniTochki; k++){
                if(otsechkataNaTiqDveTochki[i][j] > 0 && otsechkataNaTiqDveTochki[i][k] > 0 && otsechkataNaTiqDveTochki[j][k] > 0 &&
                    otsechkataNaTiqDveTochki[i][j] != otsechkataNaTiqDveTochki[i][k] && otsechkataNaTiqDveTochki[i][j] != otsechkataNaTiqDveTochki[j][k])
                {
                    broiTriagalnici++;
                }
            }
        }
    }

    cout<<broiTriagalnici<<endl;

    return 0;
}
