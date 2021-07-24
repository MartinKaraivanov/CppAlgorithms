#include<iostream>
using namespace std;

long long parvoChislo;
long long vtoroChislo;
long long tretoChislo;

bool purviteDveCifriEdnoLiSa(long long chislo){
    int poslednaCifra = 0;

    while(chislo > 1){
        poslednaCifra = chislo%2;
        chislo /= 2;
    }

    return poslednaCifra == 1;
}

int kolkoBitaImaChisloto(long long chislo){
    int broiBitove = 0;

    while(chislo > 0){
        broiBitove++;
        chislo /= 2;
    }

    return broiBitove;
}

bool imaLiNulaNaNechetnaPoziciq(long long chislo){
    int index = 0;

    while(chislo > 1){
        if(chislo % 2 == 0 && index % 2 == 0){
            return true;
        }
        index++;
        chislo /= 2;
    }

    return false;
}

long long daiPosledniteTolkovaBitove(long long chislo, int kolkoCifri){
    return ((1 << kolkoCifri) - 1) & chislo;
}

long long daiBitoveteSledNqkoiSi(long long chislo, int sledKoi){
    return chislo >> (sledKoi + 1);
}

int kakuvENaTaziPoziciqOtDqsnoNaLqvoBita(long long chislo, int poziciq){
    return (chislo >> poziciq) & 1;
}

bool otMLiEChisloto(long long chislo){
    //cout<<chislo<<endl;
    if(chislo == 1){
        return true;
    }
    if(chislo < 1){
        return false;
    }

    bool zaTuk = false;

    int broiBitovenaChisloto = kolkoBitaImaChisloto(chislo);

    if(purviteDveCifriEdnoLiSa(chislo) == true &&
        broiBitovenaChisloto >= 3 &&
        kakuvENaTaziPoziciqOtDqsnoNaLqvoBita(chislo, broiBitovenaChisloto - 3) == 1)
    {
        //cout<<"Purvite mu dve cifri sa 1"<<endl;
        bool tekushto = otMLiEChisloto(daiPosledniteTolkovaBitove(chislo, broiBitovenaChisloto - 2));

        zaTuk = zaTuk || tekushto;
    }

    for(int koibitOtdqsnoNaLqvo = 1; koibitOtdqsnoNaLqvo < broiBitovenaChisloto - 1; koibitOtdqsnoNaLqvo++){
        if(kakuvENaTaziPoziciqOtDqsnoNaLqvoBita(chislo, koibitOtdqsnoNaLqvo) == 0){
            //cout<<"ima 0 "<<endl;

            bool lqvataChast = otMLiEChisloto(daiBitoveteSledNqkoiSi(chislo, koibitOtdqsnoNaLqvo));
            bool dqsnaChast = otMLiEChisloto(daiPosledniteTolkovaBitove(chislo, koibitOtdqsnoNaLqvo));

            bool tekushto = lqvataChast && dqsnaChast;

            zaTuk = zaTuk || tekushto;
        }
    }

    return zaTuk;
}

bool okLiEChisloto(long long chislo){
    int kolkoBita = kolkoBitaImaChisloto(chislo);

    if(kolkoBita % 2 == 0){
        return false;
    }

    if(imaLiNulaNaNechetnaPoziciq(chislo) == true){
        return false;
    }

    return true;
}

int main(){
    cin>>parvoChislo>>vtoroChislo>>tretoChislo;

    bool purvoto = okLiEChisloto(parvoChislo);
    bool vtoroto = okLiEChisloto(vtoroChislo);
    bool tretoto = okLiEChisloto(tretoChislo);

    if(purvoto){
        cout<<1;
    }else{
        cout<<0;
    }

    if(vtoroto){
        cout<<1;
    }else{
        cout<<0;
    }

    if(tretoto){
        cout<<1;
    }else{
        cout<<0;
    }

    cout<<endl;

    return 0;
}
