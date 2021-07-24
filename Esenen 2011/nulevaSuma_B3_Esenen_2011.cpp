#include<iostream>
#include<algorithm>
using namespace std;

int broiUchenici;

long long poKolkoPutiOtricatelno[10005];
long long poKolkoPutiPolozhitelno[10005];

long long broiPredstavqnieNaNula(long long otKoePoveche[10005], long long otKoePoMalko[10005]){
    long long broiche = 0;

    for(int i = 1; i <= 5000; i++){
        if(otKoePoveche[i] >= 2 && otKoePoMalko[2*i] > 0){
            broiche +=
                ((otKoePoveche[i]*(otKoePoveche[i] - 1)/2)*otKoePoMalko[2*i]);
        }
    }

    for(int i = 1; i <= 5000; i++){
        if(otKoePoveche[i] > 0){
            for(int j = i + 1; j <= 10000 - i; j++){
                if(otKoePoveche[j] > 0){
                    int ostavashto = i+j;
                    broiche += otKoePoveche[i]*otKoePoveche[j]*otKoePoMalko[ostavashto];
                }
            }
        }
    }

    return broiche;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiUchenici;

    for(int i = 0; i < broiUchenici; i++){
        int tuk;
        cin>>tuk;

        if(tuk < 0){
            poKolkoPutiOtricatelno[-tuk]++;
        }else{
            poKolkoPutiPolozhitelno[tuk]++;
        }
    }

    long long broiTakivaTroiki = 0;

    if(poKolkoPutiPolozhitelno[0] >= 3){
        broiTakivaTroiki += (poKolkoPutiPolozhitelno[0] * (poKolkoPutiPolozhitelno[0] - 1) * (poKolkoPutiPolozhitelno[0] - 2))/6;
    }

    if(poKolkoPutiPolozhitelno[0] >= 1){
        for(int i = 1; i <= 10000; i++){
            if(poKolkoPutiPolozhitelno[i] > 0 && poKolkoPutiOtricatelno[i] > 0){
                broiTakivaTroiki += poKolkoPutiPolozhitelno[i]*poKolkoPutiOtricatelno[i]*poKolkoPutiPolozhitelno[0];
            }
        }
    }

    broiTakivaTroiki += broiPredstavqnieNaNula(poKolkoPutiPolozhitelno, poKolkoPutiOtricatelno);
    broiTakivaTroiki += broiPredstavqnieNaNula(poKolkoPutiOtricatelno, poKolkoPutiPolozhitelno);

    /*for(int i = 1; i <= 5000; i++){
        if(poKolkoPutiPolozhitelno[i] >= 2 && poKolkoPutiOtricatelno[2*i] > 0){
            broiTakivaTroiki +=
                ((poKolkoPutiPolozhitelno[i]*(poKolkoPutiPolozhitelno[i] - 1)/2)*poKolkoPutiOtricatelno[2*i]);
        }
    }

    for(int i = 1; i <= 5000; i++){
        if(poKolkoPutiOtricatelno[i] >= 2 && poKolkoPutiPolozhitelno[2*i] > 0){
            broiTakivaTroiki +=
                ((poKolkoPutiOtricatelno[i]*(poKolkoPutiOtricatelno[i] - 1)/2)*poKolkoPutiPolozhitelno[2*i]);
        }
    }

    for(int i = 1; i <= 5000; i++){
        if(poKolkoPutiPolozhitelno[i] > 0){
            for(int j = i + 1; j <= 10000 - i; j++){
                if(poKolkoPutiPolozhitelno[j] > 0){
                    int ostavashto = i+j;
                    broiTakivaTroiki += poKolkoPutiPolozhitelno[i]*poKolkoPutiPolozhitelno[j]*poKolkoPutiOtricatelno[ostavashto];
                }
            }
        }
    }

    for(int i = 1; i <= 5000; i++){
        if(poKolkoPutiOtricatelno[i] > 0){
            for(int j = i + 1; j <= 10000 - i; j++){
                if(poKolkoPutiOtricatelno[j] > 0){
                    int ostavashto = i + j;
                    broiTakivaTroiki += poKolkoPutiOtricatelno[i]*poKolkoPutiOtricatelno[j]*poKolkoPutiPolozhitelno[ostavashto];
                }
            }
        }
    }*/

    /*for(int i = 0; i >= -10000; i--){
        if(poKolkoPutiGoIma[otgovarqshtoChislo(i)] > 0){
            for(int j = 0; j <= 10000; j++){
                if(poKolkoPutiGoIma[otgovarqshtoChislo(j)] > 0){
                    int ostavashto = -(i + j);

                    if(ostavashto > i && ostavashto < j){
                        continue;
                    }
                    //cout<<i<<" "<<j<<" "<<ostavashto<<endl;
                    int broiOstavashto = poKolkoPutiGoIma[otgovarqshtoChislo(ostavashto)];
                    int broiOtricatelno = poKolkoPutiGoIma[otgovarqshtoChislo(i)];
                    int broiPolozhitelno = poKolkoPutiGoIma[otgovarqshtoChislo(j)];
                    int delenoNaKolko = 1;

                    if(ostavashto == i){
                        broiOstavashto--;
                        delenoNaKolko = 2;
                    }
                    if(ostavashto == j){
                        broiOstavashto--;
                        if(delenoNaKolko == 2){
                            broiPolozhitelno--;
                            delenoNaKolko = 6;
                        }else{
                            delenoNaKolko = 2;
                        }
                    }

                    //cout<<broiOtricatelno<<" "<<broiPolozhitelno<<" "<<broiOstavashto<<endl<<endl;

                    if(broiOstavashto > 0 && broiOtricatelno > 0 && broiPolozhitelno > 0){
                        broiTakivaTroiki += (broiOstavashto*broiOtricatelno*broiPolozhitelno)/delenoNaKolko;
                    }

                }
            }
        }
    }*/

    cout<<broiTakivaTroiki<<endl;

    return 0;
}
