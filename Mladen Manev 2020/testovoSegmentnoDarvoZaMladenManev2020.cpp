#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVrah{
    int stoinostDelta;
    int otKoiIndexOhvashta;
    int doKoiIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};
vector<DanniZaVrah> varhove;
int korenNomerNaVrah = -1;

vector<int> chisla;

int daiNovVrah(DanniZaVrah vrah){
    varhove.push_back(vrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otIndex, int doIndex){
    if(otIndex == doIndex){
        return daiNovVrah({0, otIndex, doIndex, -1, -1});
    }

    int lqvoDeteVrahNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDeteVraNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({0, otIndex, doIndex, lqvoDeteVrahNomer, dqsnoDeteVraNomer});
}

void promqna(int korenNaPoddarvoVrahNomer, int otIndex, int doIndex, int sKolko){
    if(korenNaPoddarvoVrahNomer == -1 ||
       otIndex > varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta ||
       doIndex < varhove[korenNaPoddarvoVrahNomer].otKoiIndexOhvashta){

        return;
    }

    if(otIndex <= varhove[korenNaPoddarvoVrahNomer].otKoiIndexOhvashta &&
       doIndex >= varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){

        varhove[korenNaPoddarvoVrahNomer].stoinostDelta += sKolko;
        return;
    }

    promqna(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer, otIndex, doIndex, sKolko);
    promqna(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer, otIndex, doIndex, sKolko);
}

int kakvoPisheTam(int korenNaPoddarvoVrahNomer, int naKoiIndex){
    if(korenNaPoddarvoVrahNomer == -1 ||
       naKoiIndex < varhove[korenNaPoddarvoVrahNomer].otKoiIndexOhvashta ||
       naKoiIndex > varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){
        return 0;
    }

    if(naKoiIndex == varhove[korenNaPoddarvoVrahNomer].otKoiIndexOhvashta &&
       naKoiIndex == varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){
        return varhove[korenNaPoddarvoVrahNomer].stoinostDelta;
    }

    int zaTuka = varhove[korenNaPoddarvoVrahNomer].stoinostDelta;

    zaTuka += kakvoPisheTam(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer, naKoiIndex);
    zaTuka += kakvoPisheTam(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer, naKoiIndex);

    return zaTuka;
}

int main(){
    int broiChisla;

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        int tukChislo;
        cin>>tukChislo;
        chisla.push_back(tukChislo);
    }

    korenNomerNaVrah = napraviDarvo(0, broiChisla - 1);

    for(unsigned int i = 0; i < chisla.size(); i++){
        promqna(korenNomerNaVrah, i, i, chisla[i]);
    }

    /*for(unsigned int i = 0; i < varhove.size(); i++){
        cout<<varhove[i].stoinostDelta<<" "<<varhove[i].otKoiIndexOhvashta<<" "<<varhove[i].doKoiIndexObhvashta<<" ";
        cout<<varhove[i].lqvoDeteVrahNomer<<" "<<varhove[i].dqsnoDeteVrahNomer<<endl;
    }*/

    for(int i = 0; i < broiChisla; i++){
        cout<<kakvoPisheTam(korenNomerNaVrah, i)<<" ";
    }
    cout<<endl;

    promqna(korenNomerNaVrah, 2, 3, 1);

    for(int i = 0; i < broiChisla; i++){
        cout<<kakvoPisheTam(korenNomerNaVrah, i)<<" ";
    }
    cout<<endl;

    promqna(korenNomerNaVrah, 1, 2, 2);

    for(int i = 0; i < broiChisla; i++){
        cout<<kakvoPisheTam(korenNomerNaVrah, i)<<" ";
    }
    cout<<endl;

    return 0;
}
