#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVtorataKupchinka{
    int stoinost;
    int naiMalakDoTuk;
};

int broiKarti;
int karti[20];

vector<int> parvaKupchinka;
vector<DanniZaVtorataKupchinka> vtoraKupchinka;

bool parvataPraznaLiE(){
    return parvaKupchinka.size() == 0;
}

bool vtorataPraznaLiE(){
    return vtoraKupchinka.size() == 0;
}

int minimalenElementOtVtorata(){
    /*if(vtoraKupchinka.size() == 0){
        return 0;
    }

    int naiMaak = 101;

    for(unsigned int i = 0; i < vtoraKupchinka.size(); i++){
        naiMaak = min(naiMaak, vtoraKupchinka[i].stoinost);
    }

    return naiMaak;*/

    if(vtoraKupchinka.size() == 0){
        return 0;
    }

    return vtoraKupchinka[vtoraKupchinka.size() - 1].naiMalakDoTuk;
}

int izvadiOtParvata(){
    int naiNakraq = parvaKupchinka[parvaKupchinka.size() - 1];
    parvaKupchinka.pop_back();
    return naiNakraq;
}

int izvadiOtVtorata(){
    DanniZaVtorataKupchinka naiNakraq = vtoraKupchinka[vtoraKupchinka.size() - 1];
    vtoraKupchinka.pop_back();
    return naiNakraq.stoinost;
}

void dobaviVParvata(int kakvo){
    parvaKupchinka.push_back(kakvo);
}

void dobaviVavVtorata(int kakvo){
    DanniZaVtorataKupchinka zaDob = {kakvo, 0};

    if(vtoraKupchinka.size() == 0){
        zaDob.naiMalakDoTuk = kakvo;
    }else{
        int zasegaMinimalenElement = vtoraKupchinka[vtoraKupchinka.size() - 1].naiMalakDoTuk;
        zaDob.naiMalakDoTuk = min(zasegaMinimalenElement, kakvo);
    }

    vtoraKupchinka.push_back(zaDob);
}

int naiGolqmaSuma(int broiOstavashtiKarti){
    if(broiOstavashtiKarti == 0 || (parvataPraznaLiE() && vtorataPraznaLiE())){
        return 0;
    }

    int akoPremestimOt1Kam2 = 0;
    int akoPremestimOt2Kam3 = 0;

    int naiMalakOtVtorata = minimalenElementOtVtorata();

    if(!parvataPraznaLiE()){
        int naiOtzad = izvadiOtParvata();
        dobaviVavVtorata(naiOtzad);
        akoPremestimOt1Kam2 = naiMalakOtVtorata + naiGolqmaSuma(broiOstavashtiKarti - 1);
        int novo = izvadiOtVtorata();
        dobaviVParvata(novo);
    }

    if(!vtorataPraznaLiE()){
        int naiOtzad = izvadiOtVtorata();
        akoPremestimOt2Kam3 = naiMalakOtVtorata + naiGolqmaSuma(broiOstavashtiKarti - 1);
        dobaviVavVtorata(naiOtzad);
    }

    int naiDobro = max(akoPremestimOt1Kam2, akoPremestimOt2Kam3);

    return naiDobro;
}

int main(){
    cin>>broiKarti;

    for(int i = 0; i < broiKarti; i++){
        cin>>karti[i];
    }

    for(int i = broiKarti - 1; i >= 0; i--){
        dobaviVParvata(karti[i]);
    }

    int rezultatKoitoMozhemDaVzemem = naiGolqmaSuma(2*broiKarti);

    cout<<rezultatKoitoMozhemDaVzemem<<endl;

    return 0;
}
