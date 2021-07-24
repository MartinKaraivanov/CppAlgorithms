#include<iostream>
#include<cmath>
using namespace std;

long long kolkoDaEDo;

bool imameLiGo[20010];

int main(){
    cin>>kolkoDaEDo;

    long long broiChe = 0;
    long long naiDalga = 0;

    int doKade = round(kolkoDaEDo*sqrt(2));

    for(int i = 1; i <= doKade; i++){
        int malkoChislo = 1;
        int golqmoChislo = kolkoDaEDo;
        int kvadrat = i * i;
        int kvadratNaMalkoto = malkoChislo * malkoChislo;
        int kvadratNaGolqmoto = golqmoChislo*golqmoChislo;
        while(golqmoChislo >= malkoChislo){
            int sborchetoIm = kvadratNaMalkoto + kvadratNaGolqmoto;
            if(sborchetoIm < kvadrat){
                malkoChislo++;
                kvadratNaMalkoto = malkoChislo*malkoChislo;
            }else{
                if(sborchetoIm > kvadrat){
                    golqmoChislo--;
                    kvadratNaGolqmoto = golqmoChislo*golqmoChislo;
                }else{
                    broiChe++;
                    naiDalga = i;
                    break;
                }
            }
        }
    }

    /*for(int i = 1; i <= doKade; i++){
        int kvadrat = i * i;
        for(int j = 1; j <= kolkoDaEDo; j++){
            int kvadratNaJ = j * j;
            int kvadratNaR = kvadrat - kvadratNaJ;
            if(kvadratNaR == 0){
                continue;
            }
            if(kvadratNaR < kvadratNaJ){
                break;
            }
            double r = sqrt(kvadratNaR);
            if(round(r) > kolkoDaEDo){
                continue;
            }
            if(abs(r - round(r)) < 0.00001){
                broiChe++;
                naiDalga = i;
                break;
            }
        }
    }*/

    /*for(long long i = 1; i <= kolkoDaEDo; i++){
        for(long long j = i; j <= kolkoDaEDo; j++){
            double d = i * i + j * j;
            double c = sqrt(d);
            int k = round(c);
            if(abs(c - round(c)) < 0.00001 && imameLiGo[k] == false){
                broiChe++;
                imameLiGo[k] = true;
                //cout<<i<<" "<<j<<" "<<c<<endl;
                if(c > naiDalga){
                    naiDalga = c;
                }
            }

        }
    }*/

    cout<<naiDalga<<" "<<broiChe<<endl;

    return 0;
}
