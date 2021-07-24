#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long chisla[1000000];
unsigned long long chislaOtBroqNaCifrite[1000000];

bool poMalkoLiE(unsigned long long a,long long b){
    return a<b;
}

int main(){
    int broiChisla;

    cin>>broiChisla;

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    for(int i=0;i<broiChisla;i++){
        int broiOtTaziifra[10];

        for(int cifra=0;cifra<10;cifra++){
            broiOtTaziifra[cifra]=0;
        }

        unsigned long long kopieNaChisloto=chisla[i];
        while(kopieNaChisloto>0){
            broiOtTaziifra[kopieNaChisloto%10]++;
            kopieNaChisloto/=10;
        }

        bool purvaCifraLiE = true;
        for(int cifra=1;cifra<10;cifra++){
            if (broiOtTaziifra[cifra] > 0){
                int broiOtCifrta=broiOtTaziifra[cifra];
                while(broiOtCifrta>0){
                    chislaOtBroqNaCifrite[i]=chislaOtBroqNaCifrite[i]*10+cifra;
                    broiOtCifrta--;
                }

                if (purvaCifraLiE==true){
                    purvaCifraLiE = false;

                    broiOtCifrta=broiOtTaziifra[0];
                    while(broiOtCifrta>0){
                        chislaOtBroqNaCifrite[i]=chislaOtBroqNaCifrite[i]*10+0;
                        broiOtCifrta--;
                    }
                }
            }
        }
    }

    sort(chislaOtBroqNaCifrite,chislaOtBroqNaCifrite+broiChisla,poMalkoLiE);

    int broiBezDrugarche=0;

    for(int i=0;i<broiChisla;i++){
        if( ((i == 0) ||(chislaOtBroqNaCifrite[i-1]!=chislaOtBroqNaCifrite[i])) &&
            ((i == broiChisla-1 )|| (chislaOtBroqNaCifrite[i+1]!=chislaOtBroqNaCifrite[i])) ){
            broiBezDrugarche++;
        }
    }

    int kombineishyn=broiChisla-broiBezDrugarche;

    cout<<kombineishyn;

    return 0;
}
