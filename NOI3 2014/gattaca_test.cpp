#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

long long daljinaParvo;
long long daljinaVtoro;
long long naiMalkoKolkoPati;

string parvo;
string vtoro;

const long long BASE = 257;
const long long MOD = 1000000007;

long long basePowParva[100010];
long long prefixHashParva[100010];

long long basePowVtora[100010];
long long prefixHashVtora[100010];

void rabinKarpPrecalc(string& posledovatelnost, long long (&basePow)[100010], long long (&prefixHash)[100010]){
    basePow[0] = 1;
    for(long long i = 1; i < (long long)posledovatelnost.size(); i++){
        basePow[i] = (basePow[i - 1] * BASE)%MOD;
    }

    prefixHash[0] = posledovatelnost[0];
    for(long long i = 1; i < (long long)posledovatelnost.size(); i++){
        prefixHash[i] = (prefixHash[i - 1] * BASE + posledovatelnost[i])%MOD;
    }
}

long long daiHash(long long otKade, long long doKade, long long (&basePow)[100010], long long (&prefixHash)[100010]){
    long long h1 = prefixHash[doKade];

    long long h2 = 0;

    if(otKade > 0){
        h2 = prefixHash[otKade - 1];
    }

    h2 = ((long long)h2 * basePow[doKade - otKade + 1])%MOD;

    return (h1 - h2 + MOD)%MOD;
}

struct DanniZaHasha{
    long long hash;
    long long tip;
    long long nachalenIndex;
};

bool koiEPoNapred(DanniZaHasha a, DanniZaHasha b){
    if(a.hash < b.hash){
        return true;
    }
    if(a.hash > b.hash){
        return false;
    }

    return a.tip < b.tip;
}

vector<int> nachalniIndexi[100010];

bool stavaLiSTakavaDaljina(long long daljina, bool daTrupaLi){
    vector<DanniZaHasha> vsichki;

    for(long long i = daljina - 1; i < daljinaParvo; i++){
        long long tukaHash = daiHash(i - daljina + 1, i, basePowParva, prefixHashParva);
        vsichki.push_back({tukaHash, 1, i - daljina + 1});
    }

    for(long long i = daljina - 1; i < daljinaVtoro; i++){
        long long tukaHash = daiHash(i - daljina + 1, i, basePowVtora, prefixHashVtora);
        vsichki.push_back({tukaHash, 2, i - daljina + 1});
    }

    sort(vsichki.begin(), vsichki.end(), koiEPoNapred);

    /*cout<<"DALJINATA E "<<daljina<<endl;
    for(long long i = 0; i < vsichki.size(); i++){
        cout<<i<<" "<<vsichki[i].hash<<" "<<vsichki[i].tip<<endl;
    }*/

    long long segashenParviHash = 0;
    long long indexatMu = 0;
    long long broiOtNego = 0;

    long long maxBroi = 0;

    for(long long i = 0; i < (long long)vsichki.size(); i++){
        DanniZaHasha tekusht = vsichki[i];
        if(tekusht.tip == 1){
            segashenParviHash = tekusht.hash;
            broiOtNego = 0;
            indexatMu = tekusht.nachalenIndex;
        }else{
            if(tekusht.hash == segashenParviHash){
                broiOtNego++;
                //cout<<"tuka namerihme "<<tekusht.hash<<" "<<segashenParviHash<<endl;

                maxBroi = max(maxBroi, broiOtNego);

                if(daTrupaLi == true && broiOtNego == naiMalkoKolkoPati){
                    nachalniIndexi[daljina].push_back(indexatMu);
                }
            }
        }
    }

    if(maxBroi >= naiMalkoKolkoPati){
        return true;
    }else{
        return false;
    }
}

string daiStringNaparviq(long long otKade, long long kolkoDalag){
    string zaVrasht;

    int br = 0;
    int index = otKade;

    while(br < kolkoDalag){
        zaVrasht.push_back(parvo[index]);
        index++;
        br++;
    }

    return zaVrasht;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>daljinaParvo>>daljinaVtoro>>naiMalkoKolkoPati;

    cin>>parvo;
    cin>>vtoro;

    rabinKarpPrecalc(parvo, basePowParva, prefixHashParva);
    rabinKarpPrecalc(vtoro, basePowVtora, prefixHashVtora);

    long long lqvKrai = 1;
    long long desenKrai = daljinaParvo;

    while(lqvKrai < desenKrai){
        long long sredata = (lqvKrai + desenKrai)/2;

        //cout<<"sredata sega e "<<sredata<<endl;

        if(stavaLiSTakavaDaljina(sredata, false) == true){
            //cout<<"tuka stava "<<nachalniIndexi[sredata].size()<<endl;
            lqvKrai = sredata + 1;
        }else{
            //cout<<"tuka ne stava"<<endl;
            desenKrai = sredata;
        }
    }

    if(stavaLiSTakavaDaljina(lqvKrai, false) == false){
        lqvKrai -= 1;
    }

    stavaLiSTakavaDaljina(lqvKrai, true);

    //cout<<lqvKrai<<endl;

    //cout<<"otgovor "<<lqvKrai<<endl;

    string otgovor = daiStringNaparviq(nachalniIndexi[lqvKrai][0], lqvKrai);

    for(long long i = 1; i < (long long)nachalniIndexi[lqvKrai].size(); i++){
        string potenicalen = daiStringNaparviq(nachalniIndexi[lqvKrai][i], lqvKrai);

        otgovor = min(otgovor, potenicalen);
    }

    cout<<otgovor<<endl;

    return 0;
}
