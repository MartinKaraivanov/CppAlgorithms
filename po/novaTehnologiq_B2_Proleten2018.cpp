#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Danni{
    int doOfic;
    int cena;

    Danni(int doOfic, int cena)
        : doOfic(doOfic), cena(cena)
    {

    }
};

struct koeESPoMalkaCena{
    bool operator()(Danni const& a, Danni const& b)
    {
        return a.cena > b.cena;
    }
};

int broiOfici;
int broiKategorii;

bool vOficaImaLiOtTaziKategoriq[1100][50];
bool otDarvotoLiEOfica[1100];
vector<Danni> sasedstvo[1100];
vector<int> otDarvoto;

priority_queue<Danni, vector<Danni>, koeESPoMalkaCena> q;

int naiMNomNaKategoriqMezhdu(int parviOfic, int vtoriOfic){
    int zaVrashtane = broiKategorii + 1;

    for(int i = 1; i <= broiKategorii; i++){
        if((vOficaImaLiOtTaziKategoriq[parviOfic][i]==true) && (vOficaImaLiOtTaziKategoriq[vtoriOfic][i] == true)){
            zaVrashtane = i;
            break;
        }
    }

    return zaVrashtane;
}

void dobavqneNaSasediteKamOpashkata(int naKoi){
    for(unsigned int i = 0; i < sasedstvo[naKoi].size(); i++){
        if(otDarvotoLiEOfica[sasedstvo[naKoi][i].doOfic] == false){
            q.push(sasedstvo[naKoi][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOfici>>broiKategorii;

    for(int i = 1; i <= broiOfici; i++){
        int broiRabotniciVOfica;
        cin>>broiRabotniciVOfica;

        for(int j = 1; j <= broiRabotniciVOfica; j++){
            int kategoriqNaRabotnika;
            cin>>kategoriqNaRabotnika;

            vOficaImaLiOtTaziKategoriq[i][kategoriqNaRabotnika] = true;
        }

        for(int vtoriO = 1; vtoriO < i; vtoriO++){
            int naiM = naiMNomNaKategoriqMezhdu(i, vtoriO);
            Danni zaDob = {vtoriO, naiM};
            sasedstvo[i].push_back(zaDob);
            zaDob = {i, naiM};
            sasedstvo[vtoriO].push_back(zaDob);
        }

    }

    otDarvotoLiEOfica[1] = true;
    //otDarvoto.push_back(1);

    dobavqneNaSasediteKamOpashkata(1);

    bool pravimLiNeshto = true;
    int cenaZaRaznasqne = 0;

    while(q.empty() == false){
        Danni naiOtpred = q.top();
        q.pop();

        if(otDarvotoLiEOfica[naiOtpred.doOfic] == false){
            cenaZaRaznasqne += naiOtpred.cena;
            otDarvotoLiEOfica[naiOtpred.doOfic] = true;
            dobavqneNaSasediteKamOpashkata(naiOtpred.doOfic);
        }
    }

    /*while(pravimLiNeshto == true){
        pravimLiNeshto = false;

        int naiMalkaCenaZaDobNaNOfic = 1000;
        int doKoiofic;

        for(int d = 0; d < otDarvoto.size(); d++){
            int i = otDarvoto[d];

            for(int j = 0; j < sasedstvo[i].size(); j++){
                if((otDarvotoLiEOfica[sasedstvo[i][j].doOfic] == false) &&
                    (sasedstvo[i][j].cena < naiMalkaCenaZaDobNaNOfic) && (sasedstvo[i][j].cena > 0))
                {
                    naiMalkaCenaZaDobNaNOfic = sasedstvo[i][j].cena;
                    doKoiofic = sasedstvo[i][j].doOfic;
                    pravimLiNeshto = true;
                }
            }

        }

        if(pravimLiNeshto){
            cenaZaRaznasqne+=naiMalkaCenaZaDobNaNOfic;
            otDarvotoLiEOfica[doKoiofic] = true;
            otDarvoto.push_back(doKoiofic);
        }

    }*/

    cout<<cenaZaRaznasqne<<endl;

    return 0;
}
