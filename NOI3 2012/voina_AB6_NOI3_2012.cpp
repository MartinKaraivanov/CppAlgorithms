#include<iostream>
#include<vector>
using namespace std;

int broiGradove;

struct DanniZaSaseda{
    int koiE;
    int razstoqnie;
};

vector<DanniZaSaseda> sasedstvo[1000010];

bool granichenliE[1000010];

void nameriGranichnite(){
    for(int i = 1; i <= broiGradove; i++){
        if(sasedstvo[i].size() == 1){
            granichenliE[i] = true;
        }
    }
}

struct DanniZaPatq{
    int daljina;
    int prezKoi;
};

DanniZaPatq naiDalagNadolu[1000010];
DanniZaPatq vtoriqNaiDalagNadolu[1000010];

DanniZaPatq naiKasiqNadolu[1000010];
DanniZaPatq vtoriqNaiKasNadolu[1000010];

struct DanniZaVrashtaneto{
    int naiDalgiqPat;
    int naiKasiqPat;
};

DanniZaVrashtaneto izchisliNadolu(int segashen, int otKadeIdvam, int rebroto){
    naiKasiqNadolu[segashen] = {1000000010, -1};
    vtoriqNaiKasNadolu[segashen] = {1000000010, -1};

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        int sledvasht = sasedstvo[segashen][i].koiE;

        if(sledvasht != otKadeIdvam){

            DanniZaVrashtaneto tuka = izchisliNadolu(sasedstvo[segashen][i].koiE, segashen, sasedstvo[segashen][i].razstoqnie);

            if(tuka.naiDalgiqPat > naiDalagNadolu[segashen].daljina){
                vtoriqNaiDalagNadolu[segashen] = naiDalagNadolu[segashen];
                naiDalagNadolu[segashen] = {tuka.naiDalgiqPat, sledvasht};
            }else{
                if(tuka.naiDalgiqPat > vtoriqNaiDalagNadolu[segashen].daljina){
                    vtoriqNaiDalagNadolu[segashen] = {tuka.naiDalgiqPat, sledvasht};
                }
            }

            if(tuka.naiKasiqPat < naiKasiqNadolu[segashen].daljina){
                vtoriqNaiKasNadolu[segashen] = naiKasiqNadolu[segashen];
                naiKasiqNadolu[segashen] = {tuka.naiKasiqPat, sledvasht};
            }else{
                if(tuka.naiKasiqPat < vtoriqNaiKasNadolu[segashen].daljina){
                    vtoriqNaiKasNadolu[segashen] = {tuka.naiKasiqPat, sledvasht};
                }
            }

        }
    }

    int kasotoZaVrasht = rebroto;

    if(granichenliE[segashen] == false){
        kasotoZaVrasht = naiKasiqNadolu[segashen].daljina + rebroto;
    }

    return {naiDalagNadolu[segashen].daljina + rebroto, kasotoZaVrasht};
}

int naiDalgiqNagore[1000010];
int naiKasiqNagore[1000010];

void izchisliNagore(int segashen, int otKadeIdvame, int naiGolqmotoOtgore, int naiKasotoOtgore){

    naiDalgiqNagore[segashen] = naiGolqmotoOtgore;
    naiKasiqNagore[segashen] = naiKasotoOtgore;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        int sledvashtiq = sasedstvo[segashen][i].koiE;

        if(sledvashtiq != otKadeIdvame){
            int ednotoDalgo = naiGolqmotoOtgore;
            int drugotoDalgo = -1;

            if(naiDalagNadolu[segashen].prezKoi != sledvashtiq){
                drugotoDalgo = naiDalagNadolu[segashen].daljina;
            }else{
                drugotoDalgo = vtoriqNaiDalagNadolu[segashen].daljina;
            }

            int ednotoKaso = naiKasotoOtgore;
            int drugotoKaso = -1;

            if(naiKasiqNadolu[segashen].prezKoi != sledvashtiq){
                drugotoKaso = naiKasiqNadolu[segashen].daljina;
            }else{
                drugotoKaso = vtoriqNaiKasNadolu[segashen].daljina;
            }

            izchisliNagore(sledvashtiq, segashen, max(ednotoDalgo, drugotoDalgo)+sasedstvo[segashen][i].razstoqnie, min(ednotoKaso, drugotoKaso)+sasedstvo[segashen][i].razstoqnie);
        }
    }

}

int naiOtdalechenOt[1000010];
int naiPriblijenDo[1000010];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove;

    for(int i = 0; i < broiGradove - 1; i++){
        int otKade;
        int doKade;
        int daljina;

        cin>>otKade>>doKade>>daljina;

        sasedstvo[otKade].push_back({doKade, daljina});
        sasedstvo[doKade].push_back({otKade, daljina});
    }

    nameriGranichnite();

    izchisliNadolu(1, -1, 0);
    izchisliNagore(1, -1, 0, 1000000010);

    for(int i = 1; i <= broiGradove; i++){
        naiOtdalechenOt[i] = max(naiDalagNadolu[i].daljina, naiDalgiqNagore[i]);
        naiPriblijenDo[i] = min(naiKasiqNadolu[i].daljina, naiKasiqNagore[i]);
    }

    int naiMalkataRazlika = 1000000010;
    int vKoiE = 0;

    for(int i = 1; i <= broiGradove; i++){
        int tuka = naiOtdalechenOt[i] - naiPriblijenDo[i];

        if(tuka < naiMalkataRazlika){
            naiMalkataRazlika = tuka;
            vKoiE = i;
        }
    }

    cout<<vKoiE<<" "<<naiMalkataRazlika<<endl;

    return 0;
}
