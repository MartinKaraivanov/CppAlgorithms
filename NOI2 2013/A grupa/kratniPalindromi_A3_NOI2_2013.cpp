#include<iostream>
using namespace std;

long long kolkoCifreni;
long long kratniNaKolko;

long long desetNaKoqStepen[20];

void praveneNaDesetNaKoqStepen(){
    long long rezultat = 1;

    desetNaKoqStepen[0] = 1;
    for(int i = 1; i <= 10; i++){
        rezultat *= 10;
        desetNaKoqStepen[i] = rezultat;
    }
}

long long obratnotoChislo(long long chislo, long long kolkoCifrenoE){
    long long otgovor = 0;

    long long index = 0;

    while(chislo > 0){
        long long cifra = chislo%10;
        chislo /= 10;

        otgovor = otgovor*10 + cifra;
        index++;
    }

    return otgovor;
}

int main(){
    cin>>kolkoCifreni>>kratniNaKolko;

    praveneNaDesetNaKoqStepen();

    bool chetenLiEBroqNaCifrite = (kolkoCifreni%2 == 0);

    long long otKade = desetNaKoqStepen[kolkoCifreni/2 - 1];
    long long doKade = desetNaKoqStepen[kolkoCifreni/2] - 1;

    long long broqDelenoNaDve = kolkoCifreni/2;

    long long broiHubaviChisla = 0;

    for(long long chislo = otKade; chislo <= doKade; chislo++){
        long long naobratno = obratnotoChislo(chislo, broqDelenoNaDve);

        if(chetenLiEBroqNaCifrite == false){
            for(int sredna = 0; sredna <= 9; sredna++){
                long long copieNaChislo = chislo*10 + sredna;

                copieNaChislo *= desetNaKoqStepen[broqDelenoNaDve];
                copieNaChislo += naobratno;

                if(copieNaChislo % kratniNaKolko == 0){
                    broiHubaviChisla++;
                }
                //cout<<copieNaChislo<<endl;
            }
        }else{
            long long copieNaChislo = chislo*desetNaKoqStepen[broqDelenoNaDve];
            copieNaChislo += naobratno;
            if(copieNaChislo % kratniNaKolko == 0){
                broiHubaviChisla++;
            }
            //cout<<copieNaChislo<<endl;
        }

    }

    cout<<broiHubaviChisla<<endl;

    return 0;
}
