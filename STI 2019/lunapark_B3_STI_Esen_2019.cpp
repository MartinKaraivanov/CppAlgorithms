#include<iostream>
#include<vector>
using namespace std;

long long broiStancii;

struct DanniZaSaseda{
    long long koiE;
    long long razstoqnie;
};

vector<DanniZaSaseda> sasedstvo[200010];

long long koiGleda[200010];

struct DanniZaVarha{
    long long naiGolqmDoNegoVPddrv;
    long long korenNaPoddarvo;
};

DanniZaVarha dalbochini[200010];

long long toziKoiVCkulaE[200010];

long long daljinaNaCikula;

bool visited[200010];

struct DanniZaZaciklen{
    long long koiE;
    long long nomer;
};

vector<long long> koiSavCikula;

DanniZaZaciklen koiEZacikleniq(long long segashen, long long otKadeIdvame){
    if(visited[segashen] == true){
        return {segashen, 1};
    }

    visited[segashen] = true;

    DanniZaZaciklen zaVrasht = {-1, -1};

    for(unsigned long long i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i].koiE != otKadeIdvame){
            DanniZaZaciklen potencialen = koiEZacikleniq(sasedstvo[segashen][i].koiE, segashen);

            if(potencialen.koiE > -1){
                zaVrasht = potencialen;
                break;
            }
        }
    }

    if(zaVrasht.koiE > -1){
        toziKoiVCkulaE[segashen] = zaVrasht.nomer;
        zaVrasht.nomer++;
        koiSavCikula.push_back(segashen);
    }

    if(zaVrasht.koiE == segashen){
        daljinaNaCikula = zaVrasht.nomer;
        zaVrasht.koiE = -1;
        zaVrasht.nomer = -1;
    }

    return zaVrasht;
}

void dalbochinirane(long long segashen, long long otKadeIdvame, long long poslednoRebro, long long korenNaPoddarvo){
    dalbochini[segashen].korenNaPoddarvo = korenNaPoddarvo;
    dalbochini[segashen].naiGolqmDoNegoVPddrv = max(poslednoRebro, dalbochini[otKadeIdvame].naiGolqmDoNegoVPddrv);

    for(unsigned long long i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i].koiE != otKadeIdvame && toziKoiVCkulaE[sasedstvo[segashen][i].koiE] == 0){
            dalbochinirane(sasedstvo[segashen][i].koiE, segashen, sasedstvo[segashen][i].razstoqnie, korenNaPoddarvo);
        }
    }
}

void praveneNaDalbochinite(){
    for(unsigned long long i = 0; i < koiSavCikula.size(); i++){
        dalbochinirane(koiSavCikula[i], 0, 0, koiSavCikula[i]);
    }
}

long long daljini[200010];

void namiraneNaDaljinite(){

    for(unsigned long long i = 0; i < koiSavCikula.size() - 1; i++){
        long long segashen = koiSavCikula[i];
        long long sledvasht = koiSavCikula[i + 1];
        for(unsigned long long j = 0; j < sasedstvo[segashen].size(); j++){
            if(sasedstvo[segashen][j].koiE == sledvasht){
                daljini[i] = sasedstvo[segashen][j].razstoqnie;
                break;
            }
        }
    }

    long long posleden = koiSavCikula[koiSavCikula.size() - 1];
    long long parvi = koiSavCikula[0];

    for(unsigned long long i = 0; i < sasedstvo[posleden].size(); i++){
        if(sasedstvo[posleden][i].koiE == parvi){
            daljini[koiSavCikula.size() - 1] = sasedstvo[posleden][i].razstoqnie;
            break;
        }
    }
}

long long darvo[530000];
long long broiNujniVarhove;

void praveneNaBroiNujniVarhove(){
    long long brNujniVrhv = 1;

    while(true){
        if(brNujniVrhv >= daljinaNaCikula){
            brNujniVrhv *= 2;
            break;
        }

        brNujniVrhv *= 2;
    }

    broiNujniVarhove = brNujniVrhv;
}

long long daiListo(long long index){
    return index + broiNujniVarhove/2;
}

void stroeneNaDarvoto(){
    for(long long i = 0; i < daljinaNaCikula; i++){
        darvo[daiListo(i)] = daljini[i];
    }

    for(long long i = daiListo(0) - 1; i > 0; i--){
        darvo[i] = max(darvo[2*i], darvo[2*i + 1]);
    }
}

long long query(long long otKade, long long doKade){
    long long lqvIndex = daiListo(otKade);
    long long desenIndex = daiListo(doKade);

    long long otgovor = max(darvo[lqvIndex], darvo[desenIndex]);
    while(lqvIndex + 1 < desenIndex){
        if(lqvIndex % 2 == 0){
            otgovor = max(otgovor, darvo[lqvIndex + 1]);
        }
        if(desenIndex % 2 == 1){
            otgovor = max(otgovor, darvo[desenIndex - 1]);
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }

    return otgovor;
}

long long sumaZaTiq(long long otKade, long long doKade){
    long long otEdiniqDoCikula = dalbochini[otKade].naiGolqmDoNegoVPddrv;
    long long otDrugiqDoCikula = dalbochini[doKade].naiGolqmDoNegoVPddrv;

    //cout<<otEdiniqDoCikula<<" "<<otDrugiqDoCikula<<endl;

    long long maxDoCikula = max(otEdiniqDoCikula, otDrugiqDoCikula);

    long long parviq = toziKoiVCkulaE[dalbochini[otKade].korenNaPoddarvo];
    long long vtoriq = toziKoiVCkulaE[dalbochini[doKade].korenNaPoddarvo];

    if(vtoriq < parviq){
        swap(parviq, vtoriq);
    }
    parviq--;
    vtoriq--;

    //cout<<"parviq e "<<parviq - 1<<" a vtoriq e "<<vtoriq - 1<<endl;

    long long direktnoVCikula = query(parviq, vtoriq - 1);
    long long zaobikolnoCikul = query(vtoriq, daljinaNaCikula - 1);
    if(parviq > 0){
        zaobikolnoCikul = max(zaobikolnoCikul, query(0, parviq - 1));
    }

    //cout<<direktnoVCikula<<" "<<zaobikolnoCikul<<endl;

    long long suma = 0;

    long long naiGolqmo = max(maxDoCikula, max(direktnoVCikula, zaobikolnoCikul));

    if(naiGolqmo == maxDoCikula){
        suma = 3*naiGolqmo;
    }else{
        long long vtoroNaiGolqmo = maxDoCikula;

        if(naiGolqmo == direktnoVCikula){
            vtoroNaiGolqmo = max(zaobikolnoCikul, vtoroNaiGolqmo);
        }else{
            vtoroNaiGolqmo = max(direktnoVCikula, vtoroNaiGolqmo);
        }

        suma = 2*naiGolqmo + vtoroNaiGolqmo;
    }

    return suma;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiStancii;

    for(long long i = 0; i < broiStancii; i++){
        long long otKade;
        long long doKade;
        long long razst;

        cin>>otKade>>doKade>>razst;

        sasedstvo[otKade].push_back({doKade, razst});
        sasedstvo[doKade].push_back({otKade, razst});
    }

    koiEZacikleniq(1, -1);
    praveneNaDalbochinite();
    namiraneNaDaljinite();

    praveneNaBroiNujniVarhove();
    stroeneNaDarvoto();

    /*for(long long i = 0; i < daljinaNaCikula; i++){
        cout<<daljini[i]<<" ";
    }
    cout<<endl;*/

    for(long long i = 1; i <= broiStancii; i++){
        koiGleda[i] = i;
    }

    long long broiPitaniq;

    cin>>broiPitaniq;

    long long sbor = 0;

    for(long long t = 0; t < broiPitaniq; t++){
        long long tip;
        long long otKoi;
        long long doKoi;

        cin>>tip>>otKoi>>doKoi;

        if(tip == 1){
            long long tekushtaSsum = sumaZaTiq(koiGleda[otKoi], koiGleda[doKoi]);
            //cout<<tekushtaSsum<<endl;
            sbor += tekushtaSsum;
        }else{
            swap(koiGleda[otKoi], koiGleda[doKoi]);
        }
    }

    cout<<sbor<<endl;

    return 0;
}
