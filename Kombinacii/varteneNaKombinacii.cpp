#include<iostream>
#include<vector>
using namespace std;

vector<int> vzeto;
vector<int> trqbvashtiqNiVector;

int broiChisla;
int naiGolqmoChislo;
int koqKombinaciq;


int broiche;

void pechatane(){
    broiche++;
    if(broiche == koqKombinaciq){
        trqbvashtiqNiVector = vzeto;
    }
}

void praveneNaKombinaciite(int indexche, int chislo){
    if(indexche == broiChisla){
        pechatane();
        return ;
    }

    if(chislo > naiGolqmoChislo){
        return ;
    }

    vzeto.push_back(chislo);
    praveneNaKombinaciite(indexche + 1, chislo + 1);
    vzeto.pop_back();

    praveneNaKombinaciite(indexche, chislo + 1);

}

int main(){
    cin>>broiChisla>>naiGolqmoChislo>>koqKombinaciq;

    praveneNaKombinaciite(0, 1);

    for(auto a : trqbvashtiqNiVector){
        cout<<a<<" ";
    }

    return 0;
}
