#include<iostream>
#include<queue>
using namespace std;

string hora[22000];
int broiHora;

string otNomercheKamIme(int nomerchence){
    return hora[nomerchence];
}

int otImeKamNomerche(string ime){
    for(int i=1;i<=broiHora;i++){
        if(ime==hora[i]){
            return i;
        }
    }
    return -1;
}

int dobavqne(string ime){
    broiHora++;
    hora[broiHora]=ime;
    return broiHora;
}

int daiNomerche(string ime){
    int nom=otImeKamNomerche(ime);
    if(nom==-1){
        return dobavqne(ime);
    }else{
        return nom;
    }
}

bool bashtaiSin[15000][15000];
int koiEBashtaMu[12000];

struct nomerIOtKoePokolenieE{
    int nomer;
    int pokolenie;
};

int main(){
    int broiDvoiki;
    cin>>broiDvoiki;

    for(int i=0;i<broiDvoiki;i++){
        string bashta;
        string sin;
        cin>>bashta>>sin;
        int nomercheNaBashta=daiNomerche(bashta);
        int nomercheNaSin=daiNomerche(sin);
        if(koiEBashtaMu[nomercheNaSin]>0){
            if(koiEBashtaMu[nomercheNaSin]==nomercheNaBashta){
                // nishto
            }else{
                cout<<sin<<endl;
                return 0;
            }
        }else{
            bashtaiSin[nomercheNaBashta][nomercheNaSin]=true;
            koiEBashtaMu[nomercheNaSin]=nomercheNaBashta;
        }
    }

    int naiDalgoPokolenie=0;
    int nomerNaChoekSNaiDalgotoPokolenie;

    for(int chovek=1;chovek<=broiHora;chovek++){
        if(koiEBashtaMu[chovek]==0){
            queue<nomerIOtKoePokolenieE> q;
            nomerIOtKoePokolenieE start = {chovek,1};
            q.push(start);

            while(q.empty()==false){
                nomerIOtKoePokolenieE predno=q.front();
                q.pop();

                if(predno.pokolenie>naiDalgoPokolenie){
                    naiDalgoPokolenie=predno.pokolenie;
                    nomerNaChoekSNaiDalgotoPokolenie=chovek;
                }else{
                    if(predno.pokolenie==naiDalgoPokolenie){
                        if(otNomercheKamIme(predno.nomer) > otNomercheKamIme(nomerNaChoekSNaiDalgotoPokolenie)){
                            naiDalgoPokolenie=predno.pokolenie;
                            nomerNaChoekSNaiDalgotoPokolenie=chovek;
                        }
                    }
                }

                for(int novChovek=1;novChovek<=broiHora;novChovek++){
                    if(bashtaiSin[predno.nomer][novChovek]==true){
                        nomerIOtKoePokolenieE novo = {novChovek , predno.pokolenie+1};
                        q.push(novo);
                    }
                }
            }

        }
    }

    cout<<otNomercheKamIme(nomerNaChoekSNaiDalgotoPokolenie)<<endl;


    return 0;
}
