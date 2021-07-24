#include<iostream>
#include<vector>
using namespace std;

int broiChisla;

int chisla[1010];

int tovaChisloNaKoiX[1010];

int priTolkova[1010];

int broiMatrioshki(int doIndex){
    if(doIndex == 0){
        return 0;
    }

    if(priTolkova[doIndex] > 0){
        return priTolkova[doIndex];
    }

    int zaTuk = 0;

    for(int i = 0; i < doIndex; i++){
        if(chisla[i] < chisla[doIndex]){
            int tekushto = 1 + broiMatrioshki(i);

            zaTuk = max(zaTuk, tekushto);
        }
    }

    priTolkova[doIndex] = zaTuk;

    return zaTuk;
}

struct DanniZaVrah{
    int stoinost;
    int otKoiIndexObhvashta;
    int doKoiIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};

vector<DanniZaVrah> varhove;
int nomerNaKorena = -1;

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

void update(int korenNaPoddarvoNomer, int koiIndex, int novaStoinost){
    if(varhove[korenNaPoddarvoNomer].otKoiIndexObhvashta == koiIndex &&
        varhove[korenNaPoddarvoNomer].doKoiIndexObhvashta == koiIndex)
    {
        varhove[korenNaPoddarvoNomer].stoinost = novaStoinost;
        return ;
    }

    if(koiIndex < varhove[korenNaPoddarvoNomer].otKoiIndexObhvashta ||
        koiIndex > varhove[korenNaPoddarvoNomer].doKoiIndexObhvashta)
    {
        return ;
    }

    if(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer != -1){
        update(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer, koiIndex, novaStoinost);

        if(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer != -1){
            update(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer, koiIndex, novaStoinost);

            varhove[korenNaPoddarvoNomer].stoinost =
                max(varhove[varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer].stoinost,
                    varhove[varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer].stoinost);
        }else{
            varhove[korenNaPoddarvoNomer].stoinost = varhove[varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer].stoinost;
        }
    }
}

int query(int korenNaPoddarvoNomer, int otIndex, int doIndex){
    if(otIndex <= varhove[korenNaPoddarvoNomer].otKoiIndexObhvashta &&
        doIndex >= varhove[korenNaPoddarvoNomer].doKoiIndexObhvashta)
    {
        return varhove[korenNaPoddarvoNomer].stoinost;
    }

    if(otIndex > varhove[korenNaPoddarvoNomer].doKoiIndexObhvashta ||
        doIndex < varhove[korenNaPoddarvoNomer].otKoiIndexObhvashta)
    {
        return 0;
    }

    int zaTuk = 0;

    if(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer != -1){
        int otLqvoto = query(varhove[korenNaPoddarvoNomer].lqvoDeteVrahNomer, otIndex, doIndex);

        if(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer != -1){
            int otDqsnoto = query(varhove[korenNaPoddarvoNomer].dqsnoDeteVrahNomer, otIndex, doIndex);

            zaTuk = max(otLqvoto, otDqsnoto);
        }else{
            zaTuk = otLqvoto;
        }
    }

    return zaTuk;
}

int sCycli(int zaDoIndex){

    for(int doIndex = 1; doIndex <= zaDoIndex; doIndex++){

        int zaTuk = 1 + query(nomerNaKorena, 0, chisla[doIndex] - 1);

        update(nomerNaKorena, chisla[doIndex] - 1, zaTuk);

        priTolkova[doIndex] = zaTuk;
    }

    return priTolkova[zaDoIndex];
}

int obarnatoPriTolkova[1010];

int obarnatoSCycli(int zaDoChislo){
    int otgovor = 0;

    for(int doChislo = 0; doChislo < zaDoChislo; doChislo++){
        int zaTuk = 1 + query(nomerNaKorena, 0, tovaChisloNaKoiX[doChislo]);

        update(nomerNaKorena, tovaChisloNaKoiX[doChislo], zaTuk);

        otgovor = max(otgovor, zaTuk);
    }

    return otgovor;
}

int main(){
    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
        chisla[i]--;
        tovaChisloNaKoiX[chisla[i]] = i;
    }

    nomerNaKorena = napraviDarvo(0, broiChisla - 1);

    //int otgovor = sCycli(broiChisla);
    int otgovor = obarnatoSCycli(broiChisla);

    cout<<otgovor<<endl;

    return 0;
}
