#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long broinachalniChisla;
long long broiZaqvki;

long long nachalniChisla[1000010];

struct DanniZaZaqvkata{
    long long tip;
    long long otKade;
    long long doKade;
};

DanniZaZaqvkata zaqvki[50010];

long long broiCifri(long long chi){
    long long br = 0;

    while(chi > 0){
        chi /= 10;
        br++;
    }

    return br;
}

/*long long rotateniChisloto(long long chi){
    long long poslCifra = chi%10;
    chi /= 10;

    long long brCifr = broiCifri(chi);

    long long desetNaStepenta = 1;

    for(long long i = 0; i < brCifr; i++){
        desetNaStepenta *= 10;
    }

    chi = poslCifra*desetNaStepenta + chi;

    return chi;
}*/

struct DanniZaMatrica{
    long long matrica[7][7];
};

struct DanniZaVarha{
    long long lazyStoinost;
    DanniZaMatrica sborPoPozicii;
    long long otKadeObhvashta;
    long long doKadeObhvashta;
    long long lqvoDete;
    long long dqsnoDete;
};


vector<DanniZaVarha> varhove;
long long korenNomer = -1;

DanniZaMatrica praznaMatrica;

void opraviCifrite(long long naVrah, long long chislo){
    long long brCifri = broiCifri(chislo);

    long long index = 0;
    while(chislo > 0){
        long long cifra = chislo%10;
        varhove[naVrah].sborPoPozicii.matrica[brCifri][index] = cifra;
        chislo /= 10;
        index++;
    }


}

long long smetniSumataV(long long vrah, long long dopRotaciq){

    long long stoinost = 0;

    for(long long i = 1; i <= 6; i++){
        long long desetNaStepen = 1;

        for(long long j = 0; j < i; j++){
            stoinost += varhove[vrah].sborPoPozicii.matrica[i][(j + varhove[vrah].lazyStoinost + dopRotaciq)%i]*desetNaStepen;
            desetNaStepen *= 10;
        }
    }

    return stoinost;
}

void preizchisli(long long zaVrah){
    if(zaVrah == -1){
        return ;
    }

    long long lqvoDete = varhove[zaVrah].lqvoDete;
    long long dqsnoDete = varhove[zaVrah].dqsnoDete;

    if(lqvoDete == -1 && dqsnoDete == -1){
        return ;
    }

    for(long long i = 1; i <= 6; i++){
        for(long long j = 0; j < i; j++){
            varhove[zaVrah].sborPoPozicii.matrica[i][j] = //todo: greshka v posokata. predi beshe pravilno
                varhove[lqvoDete].sborPoPozicii.matrica[i][(j + varhove[lqvoDete].lazyStoinost)%i] +
                varhove[dqsnoDete].sborPoPozicii.matrica[i][(j + varhove[dqsnoDete].lazyStoinost)%i];
        }
    }

}

long long daiNovVrah(DanniZaVarha novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

long long napraviDarvo(long long otKade, long long doKade){
    if(otKade == doKade){
        long long novVrah = daiNovVrah({0, praznaMatrica, otKade, doKade, -1, -1});
        opraviCifrite(novVrah, nachalniChisla[otKade]);
        return novVrah;
    }

    long long lqvoDete = napraviDarvo(otKade, (otKade + doKade)/2);
    long long dqsnoDete = napraviDarvo((otKade + doKade)/2 + 1, doKade);

    long long noviqVrah = daiNovVrah({0, praznaMatrica, otKade, doKade, lqvoDete, dqsnoDete});

    preizchisli(noviqVrah);

    return noviqVrah;
}

void update(long long segashenVrah, long long otKade, long long doKade){
    if(segashenVrah == -1 || varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return ;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        varhove[segashenVrah].lazyStoinost++;
        preizchisli(segashenVrah);
        return ;
    }

    update(varhove[segashenVrah].lqvoDete, otKade, doKade);
    update(varhove[segashenVrah].dqsnoDete, otKade, doKade);

    preizchisli(segashenVrah);
}

long long query(long long segashenVrah, long long otKade, long long doKade, long long lazy){
    if(segashenVrah == -1 || varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return 0;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        return smetniSumataV(segashenVrah, lazy);
    }

    return query(varhove[segashenVrah].lqvoDete, otKade, doKade, lazy + varhove[segashenVrah].lazyStoinost) +
            query(varhove[segashenVrah].dqsnoDete, otKade, doKade, lazy + varhove[segashenVrah].lazyStoinost);
}

vector<long long> otgovori;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broinachalniChisla>>broiZaqvki;

    for(long long i = 0; i < broinachalniChisla; i++){
        cin>>nachalniChisla[i];
    }

    korenNomer = napraviDarvo(0, broinachalniChisla - 1);

    /*for(int i = 0; i < broinachalniChisla; i++){
        vector<vector<long long>> chisla = daiCifrite(nachalniChisla[i]);
        for(int j = 1; j < 6; j++){
            for(auto k : chisla[j]){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }*/

    for(long long i = 0; i < broiZaqvki; i++){
        long long tip;
        long long otKade;
        long long doKade;
        cin>>tip>>otKade>>doKade;

        otKade--;
        doKade--;

        zaqvki[i] = {tip, otKade, doKade};
    }

    for(long long i = 0; i < broiZaqvki; i++){

        long long tip = zaqvki[i].tip;
        long long otKade = zaqvki[i].otKade;
        long long doKade = zaqvki[i].doKade;

        if(tip == 1){
            update(korenNomer, otKade, doKade);
        }else{
            long long tukaOtg = query(korenNomer, otKade, doKade, 0);
            otgovori.push_back(tukaOtg);
        }
    }

    for(long long i = 0; i < (long long)otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
