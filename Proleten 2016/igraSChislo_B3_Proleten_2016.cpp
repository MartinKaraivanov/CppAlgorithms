#include<iostream>
#include<vector>
using namespace std;

vector<int> elementi;



vector<int> darvo;
int brGorniVarhove = 0;
int brLista = 0;
int brElementi = 0;

inline int broiElementi(){
    return brElementi;
}

int daiPurvataStepenNaDvoikata(int x){
    int result = 1;
    while (result < x){
        result = result << 1; // 2*result;
    }
    return result;
}

inline int darvesenIndex(int indexNaElement){
    return brGorniVarhove + indexNaElement;
}

void praveneNaDarvoto(){
    darvo.clear();
    brElementi = elementi.size();
    brLista = daiPurvataStepenNaDvoikata(elementi.size());
    brGorniVarhove = brLista;
    darvo.resize(brGorniVarhove + brLista);

    for(unsigned int i = 0; i < elementi.size(); i++){
        darvo[darvesenIndex(i)] = elementi[i];
    }
    for(int vrah = brGorniVarhove - 1; vrah > 0; vrah--){
        darvo[vrah] = darvo[vrah << 1] + darvo[(vrah << 1) + 1];   // darvo[2*vrah] + darvo[2*vrah + 1];
    }
}


inline int daiStoinosttaNaIndex(int indexNaelement){
    return darvo[darvesenIndex(indexNaelement)];
}

void promeniShotinostNaIndex(int indexNaElement, int novaStoinost){
    int darvIndex = darvesenIndex(indexNaElement);
    int delta = novaStoinost - darvo[darvIndex];

    for(int i = darvIndex; i > 0; i = i >> 1 ){  /*i /= 2*/
        darvo[i] += delta;
    }
}

inline int kolkoESumataNacialoto(){
    return darvo[1];
}

int kolkoESumataOtDoIndex(int indexNaLqvElement, int indexNaDesenElement){
    int lqvIndex = darvesenIndex(indexNaLqvElement);
    int desenIndex = darvesenIndex(indexNaDesenElement);

    if(lqvIndex == desenIndex){
        return darvo[lqvIndex];
    }

    int sborche = darvo[lqvIndex] + darvo[desenIndex];

    while(lqvIndex + 1 != desenIndex){
        if ((lqvIndex & 1) == 0){ //(lqvIndex % 2 == 0){
            sborche += darvo[lqvIndex + 1];
        }
        if ((desenIndex & 1) == 1){ //(desenIndex % 2 == 1){
            sborche += darvo[desenIndex - 1];
        }

        lqvIndex = lqvIndex >> 1; // lqvIndex /= 2;
        desenIndex = desenIndex >> 1;// desenIndex /= 2;
    }

    return sborche;
}

// -------------- dotuk s temata za darvoto

// --------------- tuk e temata s prevurtaneto

int kolkoSaIzmesteniNaiOtzad = 0;

inline int daiIndexNaElement(int poziciq){
    int res = poziciq + kolkoSaIzmesteniNaiOtzad;
    if (res >= brElementi){
        res -= brElementi;
    }
    return res;
}

inline void premestvane(){
    kolkoSaIzmesteniNaiOtzad++;
    if (kolkoSaIzmesteniNaiOtzad >= brElementi){
        kolkoSaIzmesteniNaiOtzad -= brElementi;
    }
}

inline int daiStoinostta(int poziciq){
    return daiStoinosttaNaIndex(daiIndexNaElement(poziciq));
}

inline void promeniShotinost(int poziciq, int novaStoinost){
    promeniShotinostNaIndex(daiIndexNaElement(poziciq), novaStoinost);
}

int kolkoEdiniciImaPrediPoziciq(int poziciq){
    if(poziciq == 0){
        return 0;
    }

    int nachalenIndex = daiIndexNaElement(0);

    int kraenIndex = daiIndexNaElement(poziciq - 1);

    int broiEdinici = 0;

    if(nachalenIndex <= kraenIndex){
        broiEdinici = kolkoESumataOtDoIndex(nachalenIndex, kraenIndex);
    }else{
        broiEdinici =
        kolkoESumataNacialoto() - kolkoESumataOtDoIndex(kraenIndex, nachalenIndex) +
        daiStoinosttaNaIndex(nachalenIndex) + daiStoinosttaNaIndex(kraenIndex);
    }

    return broiEdinici;
}

void promiana(int poziciq){
    if ((kolkoEdiniciImaPrediPoziciq(poziciq) & 1) == 1){  //(kolkoEdiniciImaPrediPoziciq(poziciq) % 2 == 1){
        if(daiStoinostta(poziciq) == 1){
            promeniShotinost(poziciq, 0);
        }else{
            promeniShotinost(poziciq, 1);
        }
    }
}

void otpechatvane(){
    for(int i = 0; i < broiElementi(); i++){
        if(daiStoinostta(i) == 0){
            cout<<2;
        }else{
            cout<<1;
        }
    }

    cout<<endl;
}

int main(){
    int broiPitaniqZaCifri;

    string chi;

    cin>>chi;

    elementi.reserve(chi.size());

    for(unsigned int i = 0; i < chi.size(); i++){
        elementi.push_back((chi[i] - '0')%2);
    }

    praveneNaDarvoto();

    cin>>broiPitaniqZaCifri;

    for(int i = 0; i < broiPitaniqZaCifri; i++){
        int naKoqPoziciq;
        cin>>naKoqPoziciq;
        promiana(naKoqPoziciq - 1);
        premestvane();
    }

    otpechatvane();

    return 0;
}
