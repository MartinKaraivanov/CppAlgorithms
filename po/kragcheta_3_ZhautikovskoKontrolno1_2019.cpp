#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct DanniZaKragchetata{
    long long x;
    long long y;
    int naKoqZayavkaEDadeno;
    bool imaLiGo;
};

int broiZaqvki;
int broiZaqvOtTipEdno;
DanniZaKragchetata kragcheta[205000];
vector<int> indexiKoitoGiIma;
long long zaPechatane[202000];
int broiZaPechatane;

bool vKragchetoLiE(long long xKragche, long long yKragche, long long  xTochka, long long yTochka){
    long double a = abs(xKragche - xTochka);
    long double b = abs(yKragche - yTochka);
    long double cNaVtora = a*a + b*b;
    long double c = sqrt(cNaVtora);

    if(c < yKragche){
        return true;
    }
    return false;
}

int main(){
    cin>>broiZaqvki;

    for(int i = 1; i <= broiZaqvki; i++){
        int tip;
        long long xche;
        long long yche;
        cin>>tip>>xche>>yche;

        if(tip == 1){
            kragcheta[broiZaqvOtTipEdno].x = xche;
            kragcheta[broiZaqvOtTipEdno].y = yche;
            kragcheta[broiZaqvOtTipEdno].naKoqZayavkaEDadeno = i;
            indexiKoitoGiIma.push_back(broiZaqvOtTipEdno);
            broiZaqvOtTipEdno++;
        }else{
            bool nameriliLiSmeQ = false;

            for(int k = 0; k < indexiKoitoGiIma.size(); k++){
                int j = indexiKoitoGiIma[k];
                bool tukaLiETochkata = vKragchetoLiE(kragcheta[j].x, kragcheta[j].y, xche, yche);

                if(tukaLiETochkata == true){
                    zaPechatane[broiZaPechatane] = kragcheta[j].naKoqZayavkaEDadeno;
                    broiZaPechatane++;
                    indexiKoitoGiIma.erase(indexiKoitoGiIma.begin() + k);
                    nameriliLiSmeQ = true;
                    break;
                }
            }

            if(nameriliLiSmeQ == false){
                zaPechatane[broiZaPechatane] = -1;
                broiZaPechatane++;
            }

        }

    }

    for(int i = 0; i < broiZaPechatane; i++){
        cout<<zaPechatane[i]<<endl;
    }

    return 0;
}
