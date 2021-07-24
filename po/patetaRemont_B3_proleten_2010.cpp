#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Danni{
    int otVrah;
    int doVrah;
};

struct zaGradovete{
    int komshiq;
    int cenaDoNego;
};

int broiGradove;
int broiPatishta;

int cenaZaRemonttTovaMqsto[1100];

vector<zaGradovete> sasedstvo[1100];

bool otGlavnotoLiE[1100];

Danni otgovori[1500];
int broiOtg;

bool poMalkoLiE(Danni a, Danni b){
    if(a.otVrah < b.otVrah){
        return true;
    }else{
        if(b.otVrah < a.otVrah){
            return false;
        }else{
            return a.doVrah < b.doVrah;
        }
    }
    //return a.otVrah<b.otVrah;
}

int treeNamirane(){
    int cena = 0;
    bool pravimLiNeshto = true;

    otGlavnotoLiE[1] = true;

    while(pravimLiNeshto){
        pravimLiNeshto = false;

        int otGrad;
        int doGrad;

        int naiMalko = 10000000;

        for(int i = 1; i <= broiGradove; i++){
            if(otGlavnotoLiE[i]){
                for(int j = 0; j <sasedstvo[i].size(); j++){
                    if((sasedstvo[i][j].cenaDoNego < naiMalko) && (otGlavnotoLiE[sasedstvo[i][j].komshiq] == false)){
                        naiMalko = sasedstvo[i][j].cenaDoNego;
                        otGrad = i;
                        doGrad = sasedstvo[i][j].komshiq;
                        pravimLiNeshto = true;
                    }
                }
            }
        }

        if(pravimLiNeshto == true){
            cena+=naiMalko;
            otgovori[broiOtg].otVrah = min(otGrad, doGrad);
            otgovori[broiOtg].doVrah = max(doGrad, otGrad);
            otGlavnotoLiE[doGrad] = true;
            broiOtg++;
        }

    }

    return cena;
}

int main(){
    cin>>broiGradove>>broiPatishta;

    for(int i = 1; i <= broiGradove; i++){
        int cenichka;
        cin>>cenichka;
        cenaZaRemonttTovaMqsto[i] = cenichka;
    }

    for(int i = 0; i < broiPatishta; i++){
        int parviGrad;
        int vtoriGrad;
        int razst;
        cin>>parviGrad>>vtoriGrad>>razst;

        if(razst%2==0){
            zaGradovete zaDob = {vtoriGrad, (razst/2)*cenaZaRemonttTovaMqsto[parviGrad] +
                (razst/2)*cenaZaRemonttTovaMqsto[vtoriGrad]};

            sasedstvo[parviGrad].push_back(zaDob);

            zaGradovete zaDob2 = {parviGrad, (razst/2)*cenaZaRemonttTovaMqsto[parviGrad] +
                (razst/2)*cenaZaRemonttTovaMqsto[vtoriGrad]};

            sasedstvo[vtoriGrad].push_back(zaDob2);
        }else{
            zaGradovete zaDob = {vtoriGrad, ((razst/2) + 1)*cenaZaRemonttTovaMqsto[min(parviGrad, vtoriGrad)] +
                (razst/2)*cenaZaRemonttTovaMqsto[max(vtoriGrad, parviGrad)]};

            sasedstvo[parviGrad].push_back(zaDob);

            zaGradovete zaDob2 = {parviGrad, ((razst/2) + 1)*cenaZaRemonttTovaMqsto[min(parviGrad, vtoriGrad)] +
                (razst/2)*cenaZaRemonttTovaMqsto[max(vtoriGrad, parviGrad)]};

            sasedstvo[vtoriGrad].push_back(zaDob2);
        }
    }

    int cena = treeNamirane();

    sort(otgovori, otgovori + broiOtg, poMalkoLiE);

    cout<<cena<<endl;

    for(int i = 0; i < broiOtg; i++){
        cout<<otgovori[i].otVrah<<" "<<otgovori[i].doVrah<<endl;
    }


    return 0;
}
