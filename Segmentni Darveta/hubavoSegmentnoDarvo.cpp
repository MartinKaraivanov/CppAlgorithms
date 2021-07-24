#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVrah{
    int stoinost;
    int otKoiIndexObhvashta;
    int doKoiIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};

vector<DanniZaVrah> varhove;
int nomerNaKorena = -1;

int broiChisla;
vector<int> chisla;

int daiNovVrah(DanniZaVrah novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otIndex, int doIndex){
    if(otIndex == doIndex){
        return daiNovVrah({0, otIndex, doIndex, -1, -1});
    }

    int lqvoDeteNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDeteNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({0, otIndex, doIndex, lqvoDeteNomer, dqsnoDeteNomer});
}

void update(int korenNaPoddarvoVrahNomer, int otIndex, int doIndex, int sKolko){
    if(korenNaPoddarvoVrahNomer == -1 ||
       otIndex > varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta ||
       doIndex < varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta){

        return;
    }

    if(otIndex <= varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta &&
       doIndex >= varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){

        varhove[korenNaPoddarvoVrahNomer].stoinost += sKolko;
        return;
    }

    update(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer, otIndex, doIndex, sKolko);
    update(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer, otIndex, doIndex, sKolko);
}

int kakvoPisheTam(int korenNaPoddarvoVrahNomer, int naKoiIndex){
    if(korenNaPoddarvoVrahNomer == -1 ||
       naKoiIndex < varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta ||
       naKoiIndex > varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){
        return 0;
    }

    if(naKoiIndex == varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta &&
       naKoiIndex == varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){
        return varhove[korenNaPoddarvoVrahNomer].stoinost;
    }

    int zaTuka = varhove[korenNaPoddarvoVrahNomer].stoinost;

    zaTuka += kakvoPisheTam(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer, naKoiIndex);
    zaTuka += kakvoPisheTam(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer, naKoiIndex);

    return zaTuka;
}

int main(){
    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        int chislo;
        cin>>chislo;
        chisla.push_back(chislo);
    }

    nomerNaKorena = napraviDarvo(0, broiChisla - 1);

    for(int i = 0; i < broiChisla; i++){
        update(nomerNaKorena, i, i, chisla[i]);
    }

    for(int i = 0; i < broiChisla; i++){
        cout<<kakvoPisheTam(nomerNaKorena, i)<<" ";
    }
    cout<<endl;

    update(nomerNaKorena, 1, 3, 5);

    for(int i = 0; i < broiChisla; i++){
        cout<<kakvoPisheTam(nomerNaKorena, i)<<" ";
    }
    cout<<endl;

    return 0;
}
