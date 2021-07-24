#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

string vsichkiBukvi;
string nachalniGlasni;

char glasni[10];
int broiGlasni;
char suglasni[30];
int broiSuglasni;

long long chisloKoetoTarsim;

map<char, bool> glasnaLiE;

vector<int> otgovorVCifri;

int main(){
    cin>>vsichkiBukvi;

    cin>>nachalniGlasni;

    cin>>chisloKoetoTarsim;

    for(unsigned int i = 0; i < nachalniGlasni.size(); i++){
        glasnaLiE[nachalniGlasni[i]] = true;
    }

    for(unsigned int i = 0; i < vsichkiBukvi.size(); i++){
        if(!glasnaLiE[vsichkiBukvi[i]]){
            suglasni[broiSuglasni] = vsichkiBukvi[i];
            broiSuglasni++;
        }else{
            glasni[broiGlasni] = vsichkiBukvi[i];
            broiGlasni++;
        }
    }

    int kolkoSrichkiIma = 1;

    long long nachalno = broiSuglasni*broiGlasni;

    long long segashnoSumarno = nachalno;

    long long suma = segashnoSumarno;

    while(suma < chisloKoetoTarsim){
        segashnoSumarno *= nachalno;
        suma += segashnoSumarno;
        kolkoSrichkiIma++;
    }

    suma -= segashnoSumarno;

    chisloKoetoTarsim -= suma;

    while(kolkoSrichkiIma > 0){

        long long zaSuglasna = pow(broiSuglasni, kolkoSrichkiIma - 1)*pow(broiGlasni, kolkoSrichkiIma);
        int suglasnaBukva = (chisloKoetoTarsim - 1)/zaSuglasna;
        otgovorVCifri.push_back(suglasnaBukva);

        chisloKoetoTarsim -= suglasnaBukva*zaSuglasna;

        long long zaGlasna = zaSuglasna/broiGlasni;
        int glasnaBukva = (chisloKoetoTarsim - 1)/zaGlasna;
        otgovorVCifri.push_back(glasnaBukva);

        chisloKoetoTarsim -= glasnaBukva*zaGlasna;

        kolkoSrichkiIma--;
    }

    for(unsigned int i = 0; i < otgovorVCifri.size(); i++){
        if(i % 2 == 0){
            cout<<suglasni[otgovorVCifri[i]];
        }else{
            cout<<glasni[otgovorVCifri[i]];
        }
    }

    cout<<endl;

    return 0;
}
