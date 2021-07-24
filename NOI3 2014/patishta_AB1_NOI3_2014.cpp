#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int broiDiscoteki;

struct DanniZaSasedstvoto{
    int doKoi;
    int vreme;
};

vector<DanniZaSasedstvoto> sasedstvo[1000010];

int broinoshti;

vector<int> pow2ancestors[1000010];

int razstDo[1000010];

int dalbochina[1000010];

struct DanniZaNosht{
    int parvaDiscoteca;
    int vtoraDiscoteca;
    int novoVreme;
};

DanniZaNosht noshti[100010];

void nameriRazst(int segashen, int otKadeIdvame, int poslednoRazst, int dalb){
    razstDo[segashen] = razstDo[otKadeIdvame] + poslednoRazst;
    dalbochina[segashen] = dalb;
    pow2ancestors[segashen].reserve(22);
    pow2ancestors[segashen].push_back(segashen);

    //cout<<"sega sum v "<<segashen<<" s rebro "<<poslednoRazst<<endl;

    if(otKadeIdvame != 0){
        pow2ancestors[segashen].push_back(otKadeIdvame);
    }

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        DanniZaSasedstvoto sledvasht = sasedstvo[segashen][i];
        nameriRazst(sledvasht.doKoi, segashen, sledvasht.vreme, dalb + 1);
    }
}

void praveneNaDrugiteAncestori(){
    bool pravimLiNeshto = true;

    for(int pow2razstoqnie = 2; pravimLiNeshto == true; pow2razstoqnie++){
        pravimLiNeshto = false;

        for(int discoteka = 1; discoteka <= broiDiscoteki; discoteka++){
            if((int)pow2ancestors[discoteka].size() > pow2razstoqnie - 1){
                int mnogoPradqdo = pow2ancestors[discoteka][pow2razstoqnie - 1];
                if(mnogoPradqdo != -1 && (int)pow2ancestors[mnogoPradqdo].size() > pow2razstoqnie - 1){
                    pow2ancestors[discoteka].push_back(pow2ancestors[mnogoPradqdo][pow2razstoqnie - 1]);
                    pravimLiNeshto = true;
                }
            }
        }
    }

}

int lca(int parvi, int vtori){
    int segashnoOtKade = parvi;
    int segashnoDoKade = vtori;

    if(dalbochina[segashnoOtKade] < dalbochina[segashnoDoKade]){
        swap(segashnoOtKade, segashnoDoKade);
    }

    int razlikaVNivata = dalbochina[segashnoOtKade] - dalbochina[segashnoDoKade];

    for(int i = 1; razlikaVNivata > 0; i++){
        if(razlikaVNivata % 2 == 1){
            segashnoOtKade = pow2ancestors[segashnoOtKade][i];
        }
        razlikaVNivata /= 2;
    }

    if(segashnoOtKade == segashnoDoKade){
        return segashnoOtKade;
    }

    int i = pow2ancestors[segashnoOtKade].size() - 1;
    while(i > 0){
        if(pow2ancestors[segashnoOtKade][i] != pow2ancestors[segashnoDoKade][i]){
            segashnoOtKade = pow2ancestors[segashnoOtKade][i];
            segashnoDoKade = pow2ancestors[segashnoDoKade][i];
            i = min((int)pow2ancestors[segashnoOtKade].size() - 1, i - 1);
        }else{
            i--;
        }
    }

    int lowestCommonAncestor = pow2ancestors[segashnoOtKade][1];

    return lowestCommonAncestor;
}

int razstoqnieMezhdu(int parvi, int vtori, int lowestCA){
    int doParviq = razstDo[parvi];
    int doVtoriq = razstDo[vtori];
    int doLCA = razstDo[lowestCA];

    int mezhduDvamata = doParviq + doVtoriq - 2*doLCA;

    return mezhduDvamata;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //cin>>broiDiscoteki;

    scanf("%i", &broiDiscoteki);

    for(int i = 2; i <= broiDiscoteki; i++){
        int koiEBashtata;
        int kolkoEVremeto;
        //cin>>koiEBashtata>>kolkoEVremeto;
        scanf("%i %i", &koiEBashtata, &kolkoEVremeto);

        sasedstvo[koiEBashtata].push_back({i, kolkoEVremeto});
    }

    //cin>>broinoshti;

    scanf("%i", &broinoshti);

    for(int t = 0; t < broinoshti; t++){
        int parvaDiscoteka;
        int vtoraDiscoteka;
        int vremeNovoRebro;

        //cin>>parvaDiscoteka>>vtoraDiscoteka>>vremeNovoRebro;
        scanf("%i %i %i", &parvaDiscoteka, &vtoraDiscoteka, &vremeNovoRebro);

        noshti[t] = {parvaDiscoteka, vtoraDiscoteka, vremeNovoRebro};

    }

    nameriRazst(1, 0, 0, 1);
    praveneNaDrugiteAncestori();

    for(int i = 0; i < broinoshti; i++){
        int parvaDiscoteka = noshti[i].parvaDiscoteca;
        int vtoraDiscoteka = noshti[i].vtoraDiscoteca;
        int vremeNovoRebro = noshti[i].novoVreme;

        int lowestCA = lca(parvaDiscoteka, vtoraDiscoteka);

        int mezhduDiscotekite = razstoqnieMezhdu(parvaDiscoteka, vtoraDiscoteka, lowestCA);

        int akoNeIzpolzvame = razstDo[parvaDiscoteka] + mezhduDiscotekite;
        int akoIzpolzvamePoSredata = razstDo[parvaDiscoteka] + vremeNovoRebro;
        int akoIzpolzvameVNachaloto = vremeNovoRebro + mezhduDiscotekite;
        int akoIzpolzvameMezhduLCAIParviq =
            razstDo[lowestCA] + 2*vremeNovoRebro + razstoqnieMezhdu(lowestCA, vtoraDiscoteka, lowestCA);

        int naiDobreto =
            min(min(akoNeIzpolzvame, akoIzpolzvamePoSredata), min(akoIzpolzvameVNachaloto, akoIzpolzvameMezhduLCAIParviq));

        //cout<<naiDobreto<<endl;
        printf("%i \n", naiDobreto);
    }

    return 0;
}
