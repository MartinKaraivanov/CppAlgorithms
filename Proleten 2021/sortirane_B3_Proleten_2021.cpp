#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int broiChisla;

struct DanniZaChisloto{
    int stoinost;
    int originalenIndex;
};

vector<DanniZaChisloto> parvonachalniChisla;

vector<int> chisla;

vector<int> premestvaniq;

void pechataiCqloto(){
    for(int i = 1; i <= broiChisla; i++){
        cout<<chisla[i]<<" ";
    }
    cout<<endl;
}

bool koiEPoNapred(DanniZaChisloto a, DanniZaChisloto b){
    if(a.stoinost < b.stoinost){
        return true;
    }
    if(a.stoinost > b.stoinost){
        return false;
    }
    return a.originalenIndex < b.originalenIndex;
}

void premestvane(int koiIndex){
    int stoinost = chisla[koiIndex];

    for(int i = koiIndex; i > 1; i--){
        chisla[i] = chisla[i - 1];
    }

    chisla[1] = stoinost;

    premestvaniq.push_back(koiIndex);
}

bool stoinostiteVIntervalaLiSa(int otIndex, int doIndex, int otChi, int doChi){
    bool okliE = true;

    for(int i = otIndex; i <= doIndex; i++){
        if(chisla[i] < otChi && chisla[i] > doChi){
            okliE = false;
            break;
        }
    }

    return okliE;
}

void premesti(int kolkoChisla, int indexMestene){
    //cout<<"mestim " << kolkoChisla << " pati ot " << indexMestene<<endl;
    for(int i = 0; i < kolkoChisla; i++){
        premestvane(indexMestene);
    }
}

struct DanniZaRedicata{
    int naiMalko;
    int naiGolqmoto;
};

DanniZaRedicata naiMalkoiNaiGolqmo(int otKade, int doKade){
    DanniZaRedicata otgovor = {256, 0};

    for(int i = otKade; i <= doKade; i++){
        otgovor.naiMalko = min(otgovor.naiMalko, chisla[i]);
        otgovor.naiGolqmoto = max(otgovor.naiGolqmoto, chisla[i]);
    }

    return otgovor;
}

bool sortiranoLiE(int otIndex, int doIndex){
    bool okLiE = true;

    int predno = chisla[otIndex];

    for(int i = otIndex + 1; i <= doIndex; i++){
        if(chisla[i] < predno){
            okLiE = false;
            break;
        }

        predno = chisla[i];
    }

    return okLiE;
}

void razdeli(int doIndex){
    DanniZaRedicata zaTuk = naiMalkoiNaiGolqmo(1, doIndex);

    int srednoChislo = (zaTuk.naiMalko + zaTuk.naiGolqmoto)/2;

    // todo po-byrzo

    //while(stoinostiteVIntervalaLiSa(1, doIndex/2, srednoChislo + 1, zaTuk.naiGolqmoto) == false){
    for(int i = 0; i < 16*doIndex; i++){
        if(chisla[doIndex/2] > srednoChislo){
            //cout<<"mestim srednoto"<<endl;
            premestvane(doIndex/2);
            //pechataiCqloto();
        }else{
            //cout<<"mestim krainoto"<<endl;
            premestvane(doIndex);
            //pechataiCqloto();
        }
    }
    //cout<<"gruppirano e"<<endl;
}

void sortirai(int doIndex){
    //cout<<"do "<<doIndex<<endl;
    //pechataiCqloto();

    if(doIndex == 1){
        return ;
    }

    /*if(sortiranoLiE(doIndex/2 + 1, doIndex) == false &&
        stoinostiteVIntervalaLiSa(doIndex/2+1, doIndex, doIndex/2+1, doIndex) == false)
    {*/
        razdeli(doIndex);
        sortirai(doIndex/2);
        premesti(doIndex/2, doIndex);
    //}

    sortirai(doIndex/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiChisla;

    chisla.push_back(0);
    parvonachalniChisla.push_back({0, 0});
    for(int i = 1; i <= broiChisla; i++){
        int tuka;
        cin>>tuka;

        parvonachalniChisla.push_back({tuka, i});
        chisla.push_back(tuka);
    }

    sort(parvonachalniChisla.begin(), parvonachalniChisla.end(), koiEPoNapred);

    for(int i = 1; i < (int)parvonachalniChisla.size(); i++){
        chisla[parvonachalniChisla[i].originalenIndex] = i;
    }

    /*for(int i = 1; i < broiChisla; i++){
        cout<<chisla[i]<<" "<<parvonachalniChisla[i].stoinost<<endl;
    }*/

    sortirai(broiChisla);

    //pechataiCqloto();

    cout<<premestvaniq.size()<<endl;

    for(int i = 0; i < (int)premestvaniq.size(); i++){
        cout<<premestvaniq[i]<<" ";
    }

    cout<<endl;

    /*int predno = 1;
    int broiPodredOtNego = 1;

    vector<int> istinskiPremestvaniq;

    premestvaniq.push_back(0);

    for(int i = 0; i < (int)premestvaniq.size(); i++){
        if(premestvaniq[i] != predno){
            int doKade = broiPodredOtNego%predno;

            for(int j = 0; j < doKade; j++){
                istinskiPremestvaniq.push_back(predno);
            }

            predno = premestvaniq[i];
            broiPodredOtNego = 1;
        }else{
            broiPodredOtNego++;
        }
    }

    cout<<istinskiPremestvaniq.size()<<endl;

    for(int i = 0; i < (int)istinskiPremestvaniq.size(); i++){
        cout<<istinskiPremestvaniq[i]<<" ";
    }
    cout<<endl;*/

    return 0;
}
