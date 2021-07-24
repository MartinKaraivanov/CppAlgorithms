#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

int broiCifri;
int kolkoPatiSePOvtarq;
int otStart;
int doFinal;

vector<char> cifri;
vector<string> redichka;

vector<string> generate(vector<string> prev, vector<char> digits) {
     vector<string> next;
     for(unsigned int i = 0; i < digits.size(); i++) {
        if(i%2 == 0) {
            for(unsigned int j = 0; j < prev.size(); j++) {
                next.push_back(digits[i] + prev[j]);
            }
        }else{
            for(int j = prev.size() - 1; j >= 0; j--) {
                next.push_back(digits[i] + prev[j]);
            }
        }
     }
     return next;
}

int sumaOtCifri(int chislo){
    int sumichka = 0;
    while(chislo > 0){
        int cifrichka = chislo%10;
        sumichka+=cifrichka;
        chislo/=10;
    }

    return sumichka;
}

int convert(string strinkche){
    int chislence = 0;
    for(unsigned int i = 0; i < strinkche.size(); i++){
        chislence = 10*chislence + (strinkche[i] - '0');
    }

    return chislence;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiCifri>>kolkoPatiSePOvtarq>>otStart>>doFinal;

    for(int i = 0; i < broiCifri; i++){
        char cifrichka;
        cin>>cifrichka;
        cifri.push_back(cifrichka);
        string c ;
        c += cifrichka;
        redichka.push_back((c));
    }

    for(int i = 1; i < kolkoPatiSePOvtarq; i++){
        redichka = generate(redichka, cifri);
    }

    int naiGolqmoChislo = convert(redichka[doFinal - 1]);
    int naiGolqmaSumaOtCifrichkite = 0;

    for(unsigned int i = otStart - 1; i < doFinal - 1; i++){
        int segashnoChislo = convert(redichka[i]);
        naiGolqmoChislo = max(naiGolqmoChislo, segashnoChislo);
        int sumaOtCifrSegashno = sumaOtCifri(segashnoChislo);
        int sumaOtCifriSledvashto = sumaOtCifri(convert(redichka[i + 1]));
        int absolutnichko = abs(sumaOtCifrSegashno - sumaOtCifriSledvashto);
        naiGolqmaSumaOtCifrichkite = max(naiGolqmaSumaOtCifrichkite, absolutnichko);
    }

    cout<<naiGolqmoChislo<<" "<<naiGolqmaSumaOtCifrichkite<<endl;

    return 0;
}
