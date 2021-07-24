#include<iostream>
using namespace std;

const long long BASE = 313;
const long long MOD = 1000004251;

long long broiTestove;
long long broiChislaVTova;

long long parvaRedica[801000];
long long obratnaParva[801000];
long long vtoraRedica[801000];
long long potencialnoVtoro[801000];

long long basePowParva[801000];
long long prefixHashParva[801000];

long long basePowVtora[801000];
long long prefixHashVtora[801000];

void rabinKarpPrecalc(long long redica[801000],
                      long long daljina,
                      long long (&basePow)[801000],
                      long long (&prefixHash)[801000]){
    basePow[0] = 1;

    for(long long i = 1; i < daljina; i++){
        basePow[i] = (basePow[i - 1] * BASE)%MOD;
        //cout<<"tuko shto napravih basepow na "<<i<<" da e "<<basePow[i]<<endl;
    }

    prefixHash[0] = redica[0];

    for(long long i = 1; i < daljina; i++){
        prefixHash[i] = (prefixHash[i - 1] * BASE + redica[i])%MOD;
        //cout<<"tuko shto napravih prefixhash na "<<i<<" da e "<<prefixHash[i]<<endl;
    }
}

long long daiHash(long long otKade, long long doKade, long long prefixHash[801000], long long basePow[801000]){
    long long h1 = prefixHash[doKade];
    long long h2 = -1;

    if(otKade > 0){
        h2 = prefixHash[otKade - 1];
    }else{
        h2 = 0;
    }

    h2 = (h2 * basePow[doKade - otKade + 1])%MOD;

    return (h1 - h2 + MOD)%MOD;
}

void nulirane(){
    for(long long i = 0; i < broiChislaVTova * 2; i++){
        parvaRedica[i] = 0;
        vtoraRedica[i] = 0;
        basePowParva[i] = 0;
        basePowVtora[i] = 0;
        prefixHashParva[i] = 0;
        prefixHashVtora[i] = 0;
    }
}

int nameriTozivTozi(long long (&koi)[801000], long long daljinaKoi, long long (&vKoi)[801000], long long daljinaVKoi){
    long long otgovor = -1;

    /*cout<<"povikahame da tursq "<<endl;
    for(int i = 0; i < daljinaKoi; i++){
        cout<<koi[i]<<" ";
    }
    cout<<endl<<"v"<<endl;
    for(int i = 0; i < daljinaVKoi; i++){
        cout<<vKoi[i]<<" ";
    }
    cout<<endl;*/

    rabinKarpPrecalc(koi, daljinaKoi, basePowVtora, prefixHashVtora);
    rabinKarpPrecalc(vKoi, daljinaVKoi, basePowParva, prefixHashParva);

    long long hashVtora = daiHash(0, daljinaKoi - 1, prefixHashVtora, basePowVtora);

    //cout<<"hasha na segashniq e "<<hashVtora<<endl;

    for(long long i = 0; i < daljinaVKoi; i++){
        bool tukaokLiE = true;

        long long hashTuk = daiHash(i, i + daljinaKoi - 1, prefixHashParva, basePowParva);

        //cout<<"ot "<<i<<" do "<<i + daljinaKoi - 1<<" tuka hash e "<<hashTuk<<endl;

        if(hashTuk != hashVtora){
            tukaokLiE = false;
        }

        if(tukaokLiE == true){
            otgovor = i;
            break;
        }
    }

    //cout<<"i she vurna "<<otgovor<<endl;
    return otgovor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiTestove;

    for(long long v = 0; v < broiTestove; v++){
        nulirane();

        cin>>broiChislaVTova;

        long long sborche = 0;

        for(long long i = 0; i < broiChislaVTova; i++){
            long long chislo;
            cin>>chislo;

            sborche += chislo;
            parvaRedica[i] = chislo;
            obratnaParva[broiChislaVTova - i - 1] = chislo;
            parvaRedica[broiChislaVTova + i] = chislo;
            obratnaParva[broiChislaVTova + broiChislaVTova - i - 1] = chislo;
        }

        for(long long i = 0; i < broiChislaVTova; i++){
            long long chislo;
            cin>>chislo;

            sborche += chislo;
            vtoraRedica[i] = chislo;
        }

        if(sborche%broiChislaVTova != 0){
            cout<<-1<<endl;
            continue;
        }

        long long namalqnka = sborche/broiChislaVTova;

        for(long long i = 0; i < broiChislaVTova; i++){
            potencialnoVtoro[i] = vtoraRedica[i] - namalqnka;
            potencialnoVtoro[i] *= (long long)-1;
        }

        /*for(long long i = 0; i < broiChislaVTova; i++){
            cout<<potencialnoVtoro[i]<<" ";
        }
        cout<<endl;*/

        long long obratnaPremestvanka =
            nameriTozivTozi(potencialnoVtoro, broiChislaVTova, obratnaParva, 2*broiChislaVTova);

        if(obratnaPremestvanka != -1){
            obratnaPremestvanka = broiChislaVTova - obratnaPremestvanka;
        }

        if(obratnaPremestvanka != -1){
            long long broiOperacii = 0;
            if(namalqnka != 0){
                broiOperacii++;
            }

            if(obratnaPremestvanka != 0){
                broiOperacii++;
            }

            cout<<broiOperacii<<endl;

            if(namalqnka != 0){
                cout<<"a "<<-namalqnka<<endl;
            }

            if(obratnaPremestvanka != 0){
                cout<<"r "<<obratnaPremestvanka - 1<<endl;
            }

            continue;
        }

        long long premestvanka =
            nameriTozivTozi(potencialnoVtoro, broiChislaVTova, parvaRedica, 2*broiChislaVTova);

        if(premestvanka == -1){
            cout<<-1<<endl;
            continue;
        }

        long long broiOperacii = 0;
        if(namalqnka != 0){
            broiOperacii++;
        }

        if(premestvanka != 0){
            broiOperacii+=2;
        }

        cout<<broiOperacii<<endl;

        if(namalqnka != 0){
            cout<<"a "<<-namalqnka<<endl;
        }

        if(premestvanka != 0){
            cout<<"r "<<premestvanka - 1<<endl;
            cout<<"r "<<broiChislaVTova - 1<<endl;
        }
    }


    return 0;
}
