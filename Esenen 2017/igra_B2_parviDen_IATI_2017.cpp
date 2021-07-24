#include<iostream>
using namespace std;

int broiChisla;
int chisla[505];

long long priTolkova[505][505];

long long maximalenBroiTochki(int otKoiIndex, int kolko){
    //cout<<otKoiIndex<<" "<<kolko<<endl;
    if(otKoiIndex < 0 || kolko <= 1){
        return 0;
    }

    if(priTolkova[otKoiIndex][kolko] > -1){
        return priTolkova[otKoiIndex][kolko];
    }

    long long zaTuk = maximalenBroiTochki(otKoiIndex, kolko - 1);

    for(int i = otKoiIndex; i < otKoiIndex + kolko - 1; i++){
        if(chisla[i] == chisla[otKoiIndex + kolko - 1]){
            //cout<<otKoiIndex<<" "<<kolko<<" "<<i<<" "<<chisla[i]<<" "<<chisla[otKoiIndex + kolko - 1]<<endl;
            long long tekushto =
                2 +
                maximalenBroiTochki(i + 1, otKoiIndex + kolko - 1 - i - 1) +
                maximalenBroiTochki(otKoiIndex, i - otKoiIndex);

            zaTuk = max(zaTuk, tekushto);
        }
    }

    //cout<<otKoiIndex<<" "<<kolko<<" "<<zaTuk<<endl;

    priTolkova[otKoiIndex][kolko] = zaTuk;

    return zaTuk;
}

long long sCycli(int zaOtKoi, int zaKolko){
    for(int kolko = 2; kolko <= broiChisla; kolko++){
        for(int otKoiIndex = 0; otKoiIndex <= broiChisla - kolko; otKoiIndex++){

            long long zaTuk = priTolkova[otKoiIndex][kolko - 1];

            for(int i = otKoiIndex; i < otKoiIndex + kolko - 1; i++){
                if(chisla[i] == chisla[otKoiIndex + kolko - 1]){
                    //cout<<otKoiIndex<<" "<<kolko<<" "<<i<<" "<<chisla[i]<<" "<<chisla[otKoiIndex + kolko - 1]<<endl;
                    long long tekushto =
                        2 +
                        priTolkova[i + 1][otKoiIndex + kolko - 1 - i - 1] +
                        priTolkova[otKoiIndex][i - otKoiIndex];

                    zaTuk = max(zaTuk, tekushto);
                }
            }

            //cout<<otKoiIndex<<" "<<kolko<<" "<<zaTuk<<endl;

            priTolkova[otKoiIndex][kolko] = zaTuk;
        }
    }

    return priTolkova[zaOtKoi][zaKolko];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
    }

    /*for(int i = 0; i < broiChisla; i++){
        for(int j = 0; j <= broiChisla; j++){
            priTolkova[i][j] = -1;
        }
    }

    long long broiMahashtiSe = maximalenBroiTochki(0, broiChisla);*/
    long long broiMahashtiSe = sCycli(0, broiChisla);

    cout<<broiMahashtiSe<<endl;

    return 0;
}
