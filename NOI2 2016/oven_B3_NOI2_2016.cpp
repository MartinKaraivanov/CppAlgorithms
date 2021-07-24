#include<iostream>
using namespace std;

struct emIEn{
    int m;
    int n;
};

int broiZdraviOstanali;

emIEn otgovori[1000000];
int broiOtgovori;

int main(){
    cin>>broiZdraviOstanali;

    for(int m = 1; m < broiZdraviOstanali/2 + 1; m++){
        for(int n = 1; n < broiZdraviOstanali/2 + 1; n++){
            int schupeniOgradki;
            if(m >= n){
                schupeniOgradki = 2 * min(m, n) - 1;
            }else{
                schupeniOgradki = 2 * min(m, n);
            }
            int obshtoOgradki = 2*(m + n) + (m - 1) * n + (n - 1) * m;
            int broiOstavashti = obshtoOgradki - schupeniOgradki;
            if(broiOstavashti == broiZdraviOstanali){
                otgovori[broiOtgovori] = {m, n};
                broiOtgovori++;
                break;
            }
            if(broiOstavashti > broiZdraviOstanali){
                break;
            }
        }
    }

    cout<<broiOtgovori<<endl;

    for(int i = 0; i < broiOtgovori; i++){
        cout<<otgovori[i].m<<" "<<otgovori[i].n<<" "<<endl;
    }

    return 0;
}
