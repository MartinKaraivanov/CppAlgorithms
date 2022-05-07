#include<iostream>
#include<vector>
#include<set>
#include<stdio.h>
using namespace std;

int broiUchastnici;
int broiZaqvki;

set<int> pregradi;

struct DanniZaVarhaNormalen{
    long long maxVIntervala;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

//vector<DanniZaVarhaNormalen> varhoveNormalni;
DanniZaVarhaNormalen varhoveNormalni[200010];
int broiVarhoveNormalni;
int korenNomerNormalen = -1;

int daiNovVrahNormalen(DanniZaVarhaNormalen novVrah){
    //varhoveNormalni.push_back(novVrah);
    varhoveNormalni[broiVarhoveNormalni] = novVrah;
    broiVarhoveNormalni++;
    //return varhoveNormalni.size() - 1;
    return broiVarhoveNormalni - 1;
}

int postroiDarvoNormalno(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrahNormalen({0, otKade, doKade, -1, -1});
    }

    int lqvoDete = postroiDarvoNormalno(otKade, (otKade + doKade)/2);
    int dqsnoDete = postroiDarvoNormalno((otKade + doKade)/2 + 1, doKade);

    return daiNovVrahNormalen({0, otKade, doKade, lqvoDete, dqsnoDete});
}

void preizchisliNormalno(int segashenVrah){
    if(segashenVrah == -1 || varhoveNormalni[segashenVrah].lqvoDete == -1 || varhoveNormalni[segashenVrah].dqsnoDete == -1){
        return ;
    }

    varhoveNormalni[segashenVrah].maxVIntervala =
        max(varhoveNormalni[varhoveNormalni[segashenVrah].lqvoDete].maxVIntervala, varhoveNormalni[varhoveNormalni[segashenVrah].dqsnoDete].maxVIntervala);
}

void updateNormalno(int segashenVrah, int kade, long long sKolko){
    if(segashenVrah == -1 || varhoveNormalni[segashenVrah].otKadeObhvashta > kade || varhoveNormalni[segashenVrah].doKadeObhvashta < kade){
        return ;
    }
    if(kade <= varhoveNormalni[segashenVrah].otKadeObhvashta && kade >= varhoveNormalni[segashenVrah].doKadeObhvashta){
        varhoveNormalni[segashenVrah].maxVIntervala += sKolko;
        return ;
    }

    updateNormalno(varhoveNormalni[segashenVrah].lqvoDete, kade, sKolko);
    updateNormalno(varhoveNormalni[segashenVrah].dqsnoDete, kade, sKolko);

    preizchisliNormalno(segashenVrah);
}

long long queryNormalno(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1 || otKade > varhoveNormalni[segashenVrah].doKadeObhvashta || doKade < varhoveNormalni[segashenVrah].otKadeObhvashta){
        return 0;
    }

    if(otKade <= varhoveNormalni[segashenVrah].otKadeObhvashta && doKade >= varhoveNormalni[segashenVrah].doKadeObhvashta){
        return varhoveNormalni[segashenVrah].maxVIntervala;
    }

    return max(queryNormalno(varhoveNormalni[segashenVrah].lqvoDete, otKade, doKade), queryNormalno(varhoveNormalni[segashenVrah].dqsnoDete, otKade, doKade));
}

struct DanniZaVarhaInterval{
    long long sborChetni;
    long long sborNechetni;
    int lazyChetnos;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

//vector<DanniZaVarhaInterval> varhoveIntervali;
DanniZaVarhaInterval varhoveIntervali[200010];
int broiVarhoveIntervali;
int korenNomerIntervali = -1;

int daiNovVrahIntervalen(DanniZaVarhaInterval novVrah){
    //varhoveIntervali.push_back(novVrah);
    varhoveIntervali[broiVarhoveIntervali] = novVrah;
    broiVarhoveIntervali++;
    //return varhoveIntervali.size() - 1;
    return broiVarhoveIntervali - 1;
}

int postroiDarvoIntervali(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrahIntervalen({0,  0, 0, otKade, doKade, -1, -1});
    }

    int lqvoDete = postroiDarvoIntervali(otKade, (otKade + doKade)/2);
    int dqsnoDete = postroiDarvoIntervali((otKade + doKade)/2 + 1, doKade);

    return daiNovVrahIntervalen({0, 0, 0, otKade, doKade, lqvoDete, dqsnoDete});
}

void preizchisliIntervali(int vrah){
    if(vrah == -1 || varhoveIntervali[vrah].lqvoDete == -1 || varhoveIntervali[vrah].dqsnoDete == -1){
        return ;
    }

    varhoveIntervali[vrah].sborChetni = 0;
    varhoveIntervali[vrah].sborNechetni = 0;

    if(varhoveIntervali[varhoveIntervali[vrah].lqvoDete].lazyChetnos%2 == 0){
        varhoveIntervali[vrah].sborChetni += varhoveIntervali[varhoveIntervali[vrah].lqvoDete].sborChetni;
        varhoveIntervali[vrah].sborNechetni += varhoveIntervali[varhoveIntervali[vrah].lqvoDete].sborNechetni;
    }else{
        varhoveIntervali[vrah].sborChetni += varhoveIntervali[varhoveIntervali[vrah].lqvoDete].sborNechetni;
        varhoveIntervali[vrah].sborNechetni += varhoveIntervali[varhoveIntervali[vrah].lqvoDete].sborChetni;
    }

    if(varhoveIntervali[varhoveIntervali[vrah].dqsnoDete].lazyChetnos%2 == 0){
        varhoveIntervali[vrah].sborChetni += varhoveIntervali[varhoveIntervali[vrah].dqsnoDete].sborChetni;
        varhoveIntervali[vrah].sborNechetni += varhoveIntervali[varhoveIntervali[vrah].dqsnoDete].sborNechetni;
    }else{
        varhoveIntervali[vrah].sborChetni += varhoveIntervali[varhoveIntervali[vrah].dqsnoDete].sborNechetni;
        varhoveIntervali[vrah].sborNechetni += varhoveIntervali[varhoveIntervali[vrah].dqsnoDete].sborChetni;
    }
}


void updateIntervaliStoinost(int segashenVrah, int kade, long long novaStoinost){
    if(segashenVrah == -1 || kade > varhoveIntervali[segashenVrah].doKadeObhvashta || kade < varhoveIntervali[segashenVrah].otKadeObhvashta){
        return ;
    }
    if(kade <= varhoveIntervali[segashenVrah].otKadeObhvashta && kade >= varhoveIntervali[segashenVrah].doKadeObhvashta){
        varhoveIntervali[segashenVrah].sborChetni = novaStoinost;
        return ;
    }

    updateIntervaliStoinost(varhoveIntervali[segashenVrah].lqvoDete, kade, novaStoinost);
    updateIntervaliStoinost(varhoveIntervali[segashenVrah].dqsnoDete, kade, novaStoinost);

    preizchisliIntervali(segashenVrah);
}

void updateIntervaliChetnost(int segashenVrah, int otKade, int doKade, int deltaChetnost){
    if(segashenVrah == -1 || doKade < varhoveIntervali[segashenVrah].otKadeObhvashta || otKade > varhoveIntervali[segashenVrah].doKadeObhvashta){
        return ;
    }
    if(otKade <= varhoveIntervali[segashenVrah].otKadeObhvashta && doKade >= varhoveIntervali[segashenVrah].doKadeObhvashta){
        varhoveIntervali[segashenVrah].lazyChetnos += deltaChetnost;
        return ;
    }

    updateIntervaliChetnost(varhoveIntervali[segashenVrah].lqvoDete, otKade, doKade, deltaChetnost);
    updateIntervaliChetnost(varhoveIntervali[segashenVrah].dqsnoDete, otKade, doKade, deltaChetnost);

    preizchisliIntervali(segashenVrah);
}

struct DanniZaVrashtaneto{
    long long sborChetni;
    long long sborNechetni;
};

DanniZaVrashtaneto queryIntervaliSbor(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1 || varhoveIntervali[segashenVrah].otKadeObhvashta > doKade || varhoveIntervali[segashenVrah].doKadeObhvashta < otKade){
        return {0, 0};
    }

    if(otKade <= varhoveIntervali[segashenVrah].otKadeObhvashta && doKade >= varhoveIntervali[segashenVrah].doKadeObhvashta){
        if(varhoveIntervali[segashenVrah].lazyChetnos%2 == 1){
            return {varhoveIntervali[segashenVrah].sborNechetni, varhoveIntervali[segashenVrah].sborChetni};
        }else{
            return {varhoveIntervali[segashenVrah].sborChetni, varhoveIntervali[segashenVrah].sborNechetni};
        }
    }

    DanniZaVrashtaneto otLqvoto = queryIntervaliSbor(varhoveIntervali[segashenVrah].lqvoDete, otKade, doKade);
    DanniZaVrashtaneto otDqsnoto = queryIntervaliSbor(varhoveIntervali[segashenVrah].dqsnoDete, otKade, doKade);

    long long chetni = otLqvoto.sborChetni + otDqsnoto.sborChetni;
    long long nechetni = otLqvoto.sborNechetni + otDqsnoto.sborNechetni;

    if(varhoveIntervali[segashenVrah].lazyChetnos%2 == 1){
        return {nechetni, chetni};
    }else{
        return {chetni, nechetni};
    }
}

int queryIntervaliChetnost(int segashenVrah, int kade){
    if(segashenVrah == -1 || varhoveIntervali[segashenVrah].otKadeObhvashta > kade || varhoveIntervali[segashenVrah].doKadeObhvashta <kade){
        return 0;
    }
    if(kade <= varhoveIntervali[segashenVrah].otKadeObhvashta && kade >= varhoveIntervali[segashenVrah].doKadeObhvashta){
        return varhoveIntervali[segashenVrah].lazyChetnos;
    }

    return varhoveIntervali[segashenVrah].lazyChetnos +
            queryIntervaliChetnost(varhoveIntervali[segashenVrah].lqvoDete, kade) +
            queryIntervaliChetnost(varhoveIntervali[segashenVrah].dqsnoDete, kade);
}

void dobaviPregrada(int sledKade){
    set<int>::iterator a = pregradi.upper_bound(sledKade);
    a--;
    int otKadeParvi = *a;
    int doKadeParvi = sledKade;

    a++;
    int otKadeVtori = sledKade + 1;
    int doKadeVtori = *a - 1;

    //cout<<"parvi interval ot "<<otKadeParvi<<" do "<<doKadeParvi<<" vtori interval ot "<<otKadeVtori<<" do "<<doKadeVtori<<endl;

    long long naiGolqmoVParviq = queryNormalno(korenNomerNormalen, otKadeParvi, doKadeParvi);
    long long naiGolqmoVavVtoriq = queryNormalno(korenNomerNormalen, otKadeVtori, doKadeVtori);

    updateIntervaliStoinost(korenNomerIntervali, otKadeParvi, naiGolqmoVParviq);
    updateIntervaliStoinost(korenNomerIntervali, otKadeVtori, naiGolqmoVavVtoriq);
    updateIntervaliChetnost(korenNomerIntervali, otKadeVtori, broiUchastnici - 1, 1);

    pregradi.insert(sledKade + 1);
}

void mahniPregrada(int sledKade){
    /*
    cout<<"sega pregradite koito imame sa predi: ";
    for(set<int>::iterator a = pregradi.begin(); a != pregradi.end(); a++){
        cout<<*a<<" ";
    }
    cout<<endl;
    */

    set<int>::iterator a = pregradi.upper_bound(sledKade);
    a--;
    int otKade = *a;
    a++;
    a++;
    int doKade = *a - 1;

    //cout<<"noviqt interval e "<<otKade<<" do "<<doKade<<endl;

    long long naiGolqmotoVNoviq = queryNormalno(korenNomerNormalen, otKade, doKade);

    updateIntervaliStoinost(korenNomerIntervali, sledKade + 1, 0);
    updateIntervaliStoinost(korenNomerIntervali, otKade, naiGolqmotoVNoviq);
    updateIntervaliChetnost(korenNomerIntervali, sledKade + 1, broiUchastnici - 1, -1);

    pregradi.erase(sledKade + 1);
}

void daiTochki(int koi, long long kolko){
    updateNormalno(korenNomerNormalen, koi, kolko);

    set<int>::iterator a = pregradi.upper_bound(koi);
    a--;

    int otKade = *a;
    a++;
    int doKade = *a - 1;

    //cout<<"tozi koito updatevame se namira v intervala ot "<<otKade<<" do "<<doKade<<endl;

    long long naiGolqmoVIntervala = queryNormalno(korenNomerNormalen, otKade, doKade);
    updateIntervaliStoinost(korenNomerIntervali, otKade, naiGolqmoVIntervala);
}

long long daiSumaMejdu(int otKade, int doKade){
    set<int>::iterator lqvKrIterator = pregradi.upper_bound(otKade);
    set<int>::iterator desenKrIterator = pregradi.upper_bound(doKade);

    long long sumaTuka = 0;

    if(lqvKrIterator == desenKrIterator){
         if(queryIntervaliChetnost(korenNomerIntervali, otKade)%2 == 1){
            sumaTuka = queryNormalno(korenNomerNormalen, otKade, doKade);
         }else{
            sumaTuka = 0;
         }
    }else{
        lqvKrIterator++;
        if(lqvKrIterator == desenKrIterator){
            lqvKrIterator--;
            if(queryIntervaliChetnost(korenNomerIntervali, otKade)%2 == 1){
                sumaTuka = queryNormalno(korenNomerNormalen, otKade, *lqvKrIterator - 1);
            }else{
                sumaTuka = queryNormalno(korenNomerNormalen, *lqvKrIterator, doKade);
            }
        }else{
            lqvKrIterator--;
            desenKrIterator--;

            long long sumaPredi = 0;
            if(queryIntervaliChetnost(korenNomerIntervali, otKade)%2 == 1){
                sumaPredi = queryNormalno(korenNomerNormalen, otKade, *lqvKrIterator - 1);
            }
            long long sumaSled = 0;
            if(queryIntervaliChetnost(korenNomerIntervali, doKade)%2 == 1){
                sumaSled = queryNormalno(korenNomerNormalen, *desenKrIterator, doKade);
            }

            long long sumaPosredata = queryIntervaliSbor(korenNomerIntervali, *lqvKrIterator, *desenKrIterator - 1).sborNechetni;

            sumaTuka = sumaPredi + sumaSled + sumaPosredata;
        }
    }

    return sumaTuka;
}

//vector<long long> otgovori;
long long otgovori[100010];
int broiOtgovori;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiUchastnici>>broiZaqvki;

    korenNomerNormalen = postroiDarvoNormalno(0, broiUchastnici - 1);
    korenNomerIntervali = postroiDarvoIntervali(0, broiUchastnici - 1);

    pregradi.insert(0);
    pregradi.insert(broiUchastnici);

    for(int i = 0; i < broiZaqvki; i++){
        int tip;
        cin>>tip;

        if(tip == 1){
            int sledKade;
            cin>>sledKade;
            sledKade--;

            dobaviPregrada(sledKade);
        }else{
            if(tip == 2){
                int sledKade;
                cin>>sledKade;
                sledKade--;

                mahniPregrada(sledKade);
            }else{
                if(tip == 3){
                    int koi;
                    long long kolko;
                    cin>>koi>>kolko;
                    koi--;

                    daiTochki(koi, kolko);
                }else{
                    int otKade;
                    int doKade;
                    cin>>otKade>>doKade;
                    otKade--;
                    doKade--;

                    long long sumaTuka = daiSumaMejdu(otKade, doKade);

                    //cout<<"tuka otg "<<sumaTuka<<endl;

                    //otgovori.push_back(sumaTuka);
                    otgovori[broiOtgovori] = sumaTuka;
                    broiOtgovori++;
                }
            }
        }
    }

    //for(int i = 0; i < (int)otgovori.size(); i++){
    for(int i = 0; i < broiOtgovori; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
