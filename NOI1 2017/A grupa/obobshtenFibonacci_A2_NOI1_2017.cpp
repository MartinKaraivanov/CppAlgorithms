#include<iostream>
using namespace std;

long long desetichnaCifra(char a){
    if(a == 'A'){
        return 10;
    }
    if(a == 'B'){
        return 11;
    }
    if(a == 'C'){
        return 12;
    }
    if(a == 'D'){
        return 13;
    }
    if(a == 'E'){
        return 14;
    }
    if(a == 'F'){
        return 15;
    }

    return a - '0';
}

long long poslednite2cifriNaChislo(string chislo, long long p){
    long long posledna = desetichnaCifra(chislo[chislo.size() - 1]) * 1;
    long long predposledna = 0;
    if(chislo.size() > 1){
        predposledna = desetichnaCifra(chislo[chislo.size() - 2]) * p;
    }

    return posledna + predposledna;
}

char ostatakVSistema(long long ostatak){
    if(ostatak == 10){
        return 'A';
    }
    if(ostatak == 11){
        return 'B';
    }
    if(ostatak == 12){
        return 'C';
    }
    if(ostatak == 13){
        return 'D';
    }
    if(ostatak == 14){
        return 'E';
    }
    if(ostatak == 15){
        return 'F';
    }

    return ostatak + '0';
}

char predposlednataCifra(long long chislo, long long p){
    chislo /= p;

    char ostatk = ostatakVSistema(chislo % p);

    return ostatk;
}

long long daljinaNaCikula(long long parvo, long long vtoro, long long p){
    long long segashno = vtoro;
    long long predishno = parvo;
    bool nachalotoLiE = true;

    long long daljina = 0;

    while((segashno != vtoro || predishno != parvo) || nachalotoLiE == true){
        daljina++;

        long long sledvashto = (segashno + predishno)%(p*p);
        //cout<<predishno<<" "<<segashno<<" "<<sledvashto<<endl;
        predishno = segashno;
        segashno = sledvashto;
        nachalotoLiE = false;
    }

    //cout<<segashno<<" "<<vtoro<<"  "<<predishno<<" "<<parvo<<endl;

    return daljina;
}

char koiEKtotoChislo(long long parvo, long long vtoro, long long k, long long p){
    long long segashno = vtoro;
    long long predishno = parvo;

    for(long long i = 0; i < k - 1; i++){
        long long sledvashto = (segashno + predishno)%(p*p);
        predishno = segashno;
        segashno = sledvashto;
    }

    char vtorataCifra = predposlednataCifra(predishno, p);

    return vtorataCifra;
}


long long ostatkNaGolqmoChislo(string koeChisloKatoString, long long daljina){
    long long ostatk = 0;

    for(long long i = 0; i < koeChisloKatoString.size(); i++){
        ostatk = (10*ostatk + desetichnaCifra(koeChisloKatoString[i]))%daljina;
    }

    return ostatk;
}

long long koeTarsim(long long daljina, string koeChisloKatoString, long long koeChislo){
    if(koeChisloKatoString.size() <= 18){
        return koeChislo%daljina;
    }

    return ostatkNaGolqmoChislo(koeChisloKatoString, daljina);
}

long long kasoChisloOtStringKamNormalno(string koeChisloKatoString){
    long long koeChislo = 0;

    for(unsigned long long i = 0; i < koeChisloKatoString.size(); i++){
        koeChislo = koeChislo*10 + (koeChisloKatoString[i] - '0');
    }

    return koeChislo;
}

int main(){
    long long p;
    long long koeChislo = -1;

    string koeChisloKatoString;

    string parvoChislo;
    string vtoroChislo;

    long long desetichnoParvoPosledniDveCifri;
    long long desetichnoVtoroPosledniDveCifri;

    cin>>p>>koeChisloKatoString;

    cin>>parvoChislo>>vtoroChislo;

    if(koeChisloKatoString.size() <= 18){
        koeChislo = kasoChisloOtStringKamNormalno(koeChisloKatoString);
    }

    desetichnoParvoPosledniDveCifri = poslednite2cifriNaChislo(parvoChislo, p);
    desetichnoVtoroPosledniDveCifri = poslednite2cifriNaChislo(vtoroChislo, p);

    long long parvoto = desetichnoParvoPosledniDveCifri;
    long long vtoroto = desetichnoVtoroPosledniDveCifri;

    long long daljina = daljinaNaCikula(parvoto, vtoroto, p);

    long long koetoTarsim = koeTarsim(daljina, koeChisloKatoString, koeChislo);

    //cout<<daljina<<" "<<koetoTarsim<<endl;

    char vtorataCifra = koiEKtotoChislo(parvoto, vtoroto, koetoTarsim, p);

    cout<<vtorataCifra<<endl;

    return 0;
}
