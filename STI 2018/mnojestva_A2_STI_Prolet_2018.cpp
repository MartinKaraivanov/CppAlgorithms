#include<iostream>
#include<algorithm>
using namespace std;

const int mnogo = 1000000007;

int broiDvoikiMnojestva;
int broiChislaVMnojestvo;

int obshtoChisla;

int chisla[1000010];

bool mojeLiPriTolkova(int razlikaSega){
    //cout<<"sega gledame za s razlika "<<razlikaSega<<endl;
    if(chisla[1] - chisla[0] > razlikaSega){
        //cout<<"tuka direktno parvata dvoika ne moje"<<endl;
        return false;
    }

    int broiSNaiMnTakavaRazlika = 1;

    int doKadeGledame = obshtoChisla - (broiChislaVMnojestvo - 1)*2 - 1;

    //cout<<"gledame do "<<doKadeGledame<<endl;

    int i = 2;

    while(i < doKadeGledame){
        int tuka = chisla[i + 1] - chisla[i];

        if(tuka <= razlikaSega){
            broiSNaiMnTakavaRazlika++;
            i += 2;
        }else{
            i++;
        }
    }

    if(broiSNaiMnTakavaRazlika >= broiDvoikiMnojestva){
        return true;
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiDvoikiMnojestva>>broiChislaVMnojestvo;

    obshtoChisla = 2*broiDvoikiMnojestva*broiChislaVMnojestvo;

    for(int i = 0; i < obshtoChisla; i++){
        cin>>chisla[i];
    }

    sort(chisla, chisla + obshtoChisla);

    int lqvKrai = 0;
    int desenKrai = chisla[obshtoChisla - 1] - chisla[0];

    while(lqvKrai < desenKrai){

        int sredata = (lqvKrai + desenKrai)/2;

        if(mojeLiPriTolkova(sredata) == true){
            desenKrai = sredata;
        }else{
            lqvKrai = sredata + 1;
        }
    }

    cout<<lqvKrai<<endl;

    return 0;
}
