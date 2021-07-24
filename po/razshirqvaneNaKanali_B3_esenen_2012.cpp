#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Danni{
    int doVrah;
    int razst;
};

struct DanniZaRebro{
    int otKoi;
    int doKoi;
    int kolkoEShiroko;

    DanniZaRebro(int otKoi, int doKoi, int kolkoEShiroko)
        : otKoi(otKoi), doKoi(doKoi), kolkoEShiroko(kolkoEShiroko)
    {

    }
};

struct poBlizo{
    bool operator()(DanniZaRebro const& a, DanniZaRebro const& b)
    {
        return a.kolkoEShiroko < b.kolkoEShiroko;
    }
};

int broiEzera;
int broiKanali;
int shirinaNaLodka;

vector<Danni> sasedstvo[1050];

priority_queue<DanniZaRebro, vector<DanniZaRebro>, poBlizo> q;

bool otGlavnotoLiE[1050];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiEzera>>broiKanali;

    for(int i = 0; i < broiKanali; i++){
        int otEzero;
        int doEzero;
        int shir;
        cin>>otEzero>>doEzero>>shir;
        Danni zaDobEdno = {doEzero, shir};
        sasedstvo[otEzero].push_back(zaDobEdno);
        Danni zaDobDve = {otEzero, shir};
        sasedstvo[doEzero].push_back(zaDobDve);
    }

    cin>>shirinaNaLodka;

    otGlavnotoLiE[1] = true;

    for(unsigned int i = 0; i < sasedstvo[1].size(); i++){
        q.push({1, sasedstvo[1][i].doVrah, sasedstvo[1][i].razst});
    }

    int broiKanaliZaRazshir = 0;

    while(q.empty() == false){
        DanniZaRebro naiShiroko = q.top();
        q.pop();

        if(otGlavnotoLiE[naiShiroko.doKoi] == false){
            int doKoiOtiv = naiShiroko.doKoi;
            int shirina = naiShiroko.kolkoEShiroko;

            otGlavnotoLiE[doKoiOtiv] = true;

            if(shirina < shirinaNaLodka){
                broiKanaliZaRazshir++;
            }

            for(unsigned int i = 0; i < sasedstvo[doKoiOtiv].size(); i++){
                if(otGlavnotoLiE[sasedstvo[doKoiOtiv][i].doVrah] == false){
                    q.push({doKoiOtiv, sasedstvo[doKoiOtiv][i].doVrah, sasedstvo[doKoiOtiv][i].razst});
                }
            }
        }
    }

    cout<<broiKanaliZaRazshir<<endl;

    return 0;
}
