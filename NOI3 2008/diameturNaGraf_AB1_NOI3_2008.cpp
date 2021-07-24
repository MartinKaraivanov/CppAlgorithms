#include<iostream>
#include<vector>
using namespace std;

int broiVarhove;

struct DanniZaSaseda{
    int koiNomer;
    int razstoqnie;
};

vector<DanniZaSaseda> sasedstvo[1010];

/*struct DanniZaNaiDalgiqPat{
    int daljina;
    int prezKoiE;
};

DanniZaNaiDalgiqPat naiDalagNadolu[1010];
DanniZaNaiDalgiqPat vtoriNaiDalagNadolu[1010];

int nadolu(int segashen, int otKadeIdvame){

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i].koiNomer != otKadeIdvame){
            int tekushto = nadolu(sasedstvo[segashen][i].koiNomer, segashen) + sasedstvo[segashen][i].razstoqnie;

            if(tekushto > naiDalagNadolu[segashen].daljina){
                vtoriNaiDalagNadolu[segashen] = naiDalagNadolu[segashen];
                naiDalagNadolu[segashen] = {tekushto, sasedstvo[segashen][i].koiNomer};
            }else{
                if(tekushto > vtoriNaiDalagNadolu[segashen].daljina){
                    vtoriNaiDalagNadolu[segashen] = {tekushto, sasedstvo[segashen][i].koiNomer};
                }
            }

        }
    }

    return naiDalagNadolu[segashen].daljina;
}*/

struct DanniZaVrashtane{
    int daljinaNadolu;
    int otgovorNadolu;
};

DanniZaVrashtane namiraneNaOtgovor(int segashen, int otKadeIdvame){
    int naiDalagTuka = 0;
    int vtoriNaiDalagTuk = 0;

    int otgovorTuka = 0;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i].koiNomer != otKadeIdvame){
            DanniZaVrashtane tekushtoNadolu = namiraneNaOtgovor(sasedstvo[segashen][i].koiNomer, segashen);

            int tekushto = tekushtoNadolu.daljinaNadolu + sasedstvo[segashen][i].razstoqnie;

            otgovorTuka = max(otgovorTuka, tekushtoNadolu.otgovorNadolu);

            if(tekushto > naiDalagTuka){
                vtoriNaiDalagTuk = naiDalagTuka;
                naiDalagTuka = tekushto;
            }else{
                if(tekushto > vtoriNaiDalagTuk){
                    vtoriNaiDalagTuk = tekushto;
                }
            }

        }
    }

    //int zaTuk = naiDalagTuka.daljina + vtoriNaiDalagTuk.daljina;

    return {naiDalagTuka, max(otgovorTuka, naiDalagTuka + vtoriNaiDalagTuk)};
}

/*int naiDalagNagore[1010];

void nagore(int segashen, int otKadeIdvame, int naiDobrotoOtgore){
    naiDalagNagore[segashen] = naiDobrotoOtgore;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i].koiNomer != otKadeIdvame){
            int naiDobrotoSledvasht = -1;

            if(naiDalagNadolu[segashen].prezKoiE != sasedstvo[segashen][i].koiNomer){
                naiDobrotoSledvasht = naiDalagNadolu[segashen].daljina;
            }else{
                naiDobrotoSledvasht = vtoriNaiDalagNadolu[segashen].daljina;
            }

            nagore(sasedstvo[segashen][i].koiNomer,
                   segashen,
                   max(naiDobrotoOtgore, naiDobrotoSledvasht) + sasedstvo[segashen][i].razstoqnie);
        }
    }
}*/

int main(){
    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove - 1; i++){
        int otKade;
        int doKade;
        int razst;
        cin>>otKade>>doKade>>razst;

        sasedstvo[otKade].push_back({doKade, razst});
        sasedstvo[doKade].push_back({otKade, razst});
    }

    /*nadolu(1, 0);
    nagore(1, 0, 0);

    int diametar = 0;

    for(int i = 1; i < broiVarhove; i++){
        diametar = max(naiDalagNadolu[i].daljina + naiDalagNagore[i], diametar);
    }

    cout<<diametar<<endl;*/

    int diametar = namiraneNaOtgovor(1, 0).otgovorNadolu;

    cout<<diametar<<endl;

    return 0;
}
