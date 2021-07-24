#include<iostream>
using namespace std;

int broiChisla;
int chisla[1000010];
int sumaKoqtoDaPravqt;

int parvaPoziciqNaKoqtoSeSresha[1010];

int main(){
    cin>>broiChisla;

    for(int i = 1; i <= broiChisla; i++){
        cin>>chisla[i];
    }

    cin>>sumaKoqtoDaPravqt;

    for(int i = 1; i <= broiChisla; i++){
        if(parvaPoziciqNaKoqtoSeSresha[chisla[i]] == 0){
            parvaPoziciqNaKoqtoSeSresha[chisla[i]] = i;
        }
    }

    int parvoOtTqh = 0;
    int vtoroOtTqh = 0;

    for(int i = 1; i <= broiChisla; i++){
        int ostavashto = sumaKoqtoDaPravqt - chisla[i];
        if(ostavashto < 1000 && parvaPoziciqNaKoqtoSeSresha[ostavashto] > 0){
            parvoOtTqh = i;
            vtoroOtTqh = parvaPoziciqNaKoqtoSeSresha[ostavashto];
            break;
        }
    }

    cout<<parvoOtTqh<<" "<<vtoroOtTqh<<endl;

    return 0;
}
