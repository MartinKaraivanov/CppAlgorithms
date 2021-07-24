#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaChisloto{
    int index;
    int doKadeNalqvo;
};

const int mnogo = 1000000007;

int broiChisla;

int chisla[1000010];

int broiZaqvki;

vector<int> zaqvkiZaToziIndex[1000010];

int sborOtNachalotoDo(int doKade){
    int sbor = 0;

    int sborVOriginalnataRedica = 0;

    int aktivenSbor = 0;

    vector<DanniZaChisloto> s;

    for(int i = 1; i <= doKade; i++){

        for(unsigned int j = 0; j < zaqvkiZaToziIndex[i].size(); j++){

            sbor = (sbor + sborVOriginalnataRedica)%mnogo;

            int tekushtAktivenSbor = aktivenSbor;

            sbor = (sbor + tekushtAktivenSbor)%mnogo;

            int doKadeNalqvoE = 0;

            int indexOtSteka = (int)s.size() - (int)1;

            while(true){
                if(indexOtSteka == -1){
                    doKadeNalqvoE = 1;
                    break;
                }
                if(chisla[s[indexOtSteka].index] > zaqvkiZaToziIndex[i][j]){

                    tekushtAktivenSbor -=
                        (s[indexOtSteka].index - s[indexOtSteka].doKadeNalqvo + 1)*chisla[s[indexOtSteka].index];

                    indexOtSteka--;
                }else{
                    doKadeNalqvoE = s[indexOtSteka].index + 1;
                    break;
                }
            }

            tekushtAktivenSbor +=
                (i - doKadeNalqvoE + 1)*zaqvkiZaToziIndex[i][j];

            sbor = (sbor + tekushtAktivenSbor)%mnogo;

        }

        int doKadeNalqvoE = 0;

        sbor = (sbor + aktivenSbor)%mnogo;
        sborVOriginalnataRedica = (sborVOriginalnataRedica + aktivenSbor)%mnogo;

        while(true){

            if(s.empty() == true){
                doKadeNalqvoE = 1;
                break;
            }
            if(chisla[s[s.size() - 1].index] > chisla[i]){
                aktivenSbor -= (s[s.size() - 1].index - s[s.size() - 1].doKadeNalqvo + 1)*chisla[s[s.size() - 1].index];

                s.pop_back();
            }else{
                doKadeNalqvoE = s[s.size() - 1].index + 1;
                break;
            }
        }

        s.push_back({i, doKadeNalqvoE});

        aktivenSbor += (s[s.size() - 1].index - s[s.size() - 1].doKadeNalqvo + 1)*chisla[s[s.size() - 1].index];
    }

    sbor = (sbor + aktivenSbor)%mnogo;

    return sbor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiChisla;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    cin>>broiZaqvki;

    for(int i = 1; i <= broiZaqvki; i++){
        int doKade;
        int kakSvarshva;
        cin>>doKade>>kakSvarshva;

        zaqvkiZaToziIndex[doKade + 1].push_back(kakSvarshva);
    }

    int sbor = sborOtNachalotoDo(broiChisla);

    cout<<sbor<<endl;

    return 0;
}
