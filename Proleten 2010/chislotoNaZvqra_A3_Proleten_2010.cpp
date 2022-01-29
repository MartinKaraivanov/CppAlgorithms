#include<iostream>
using namespace std;

const long long mnogo = 1000000007;

long long kolkoCifreno;
long long poneKolkoShestici;

long long priTolkova[100010];


/*
long long broiNachiniZa(long long kolkoMesta, long long kolkoShesticiNakraq){
    if(kolkoMesta < kolkoShesticiNakraq){
        return 0;
    }
    if(kolkoMesta == 1){
        if(kolkoShesticiNakraq == 1){
            return 1;
        }else{
            return 8;
        }
    }

    if(priTolkova[kolkoMesta][kolkoShesticiNakraq] > 0){
        return priTolkova[kolkoMesta][kolkoShesticiNakraq]%mnogo;
    }

    //cout<<"vikat ni za "<<kolkoMesta<<" mesta i "<<kolkoShesticiNakraq<<" sgestici nakraq"<<endl;

    long long zaTuka = 0;

    if(kolkoShesticiNakraq == 0){
        for(long long i = 0; i < min(poneKolkoShestici, kolkoMesta); i++){
            zaTuka = (zaTuka + broiNachiniZa(kolkoMesta - 1, i))%mnogo;
        }
        zaTuka = (zaTuka*9)%mnogo;
    }else{
        //cout<<"sega e normalen sluchai"<<endl;
        zaTuka = broiNachiniZa(kolkoMesta - 1, kolkoShesticiNakraq - 1)%mnogo;  // moje napravo do 0
    }

    priTolkova[kolkoMesta][kolkoShesticiNakraq] = zaTuka%mnogo;
    return zaTuka%mnogo;
}
*/

long long broiNachiniZa(long long kolkoMesta);

long long broiNachiniZaKolko(long long kolkoMesta, long long kolkoShesticiNakraq){
    if(kolkoMesta < kolkoShesticiNakraq){
        return 0;
    }
    if(kolkoMesta == kolkoShesticiNakraq){
        return 1;
    }
    if(kolkoMesta == 1){
        return 8;
    }

    return broiNachiniZa(kolkoMesta - kolkoShesticiNakraq)%mnogo;  // moje napravo do 0
}

long long broiNachiniZa(long long kolkoMesta){  // smiata samo ako vtoria parametar e 0
    if(kolkoMesta == 0){
        return 1;
    }
    if(kolkoMesta == 1){
        return 8;
    }

    if(priTolkova[kolkoMesta] > 0){
        return priTolkova[kolkoMesta]%mnogo;
    }

    //cout<<"vikat ni za "<<kolkoMesta<<" mesta i "<<kolkoShesticiNakraq<<" sgestici nakraq"<<endl;

    long long zaTuka = 0;

    for(long long i = 1; i <= min(poneKolkoShestici, kolkoMesta); i++){
        zaTuka = (zaTuka + broiNachiniZa(kolkoMesta - i))%mnogo;
    }
    zaTuka = (zaTuka*9)%mnogo;

    priTolkova[kolkoMesta] = zaTuka%mnogo;
    return zaTuka%mnogo;
}

void sCycli(long long zaKolkoMesta){
    priTolkova[0] = 1;
    priTolkova[1] = 8;

    if(poneKolkoShestici != 1){
        priTolkova[2] = (priTolkova[0] + priTolkova[1])*9;
    }else{
        priTolkova[2] = priTolkova[1]*9;
    }


    for(long long i = 3; i < poneKolkoShestici; i++){
        priTolkova[i] = (priTolkova[i - 1] + priTolkova[i - 1]*9)%mnogo;
    }

    for(long long kolkoMesta = max((long long)3, poneKolkoShestici); kolkoMesta <= zaKolkoMesta; kolkoMesta++){
        /*long long zaTuka = 0;

        for(long long i = 1; i <= min(poneKolkoShestici, kolkoMesta); i++){
            zaTuka = (zaTuka + priTolkova[kolkoMesta - i])%mnogo;
        }
        zaTuka = (zaTuka*9)%mnogo;

        priTolkova[kolkoMesta] = zaTuka%mnogo;*/

        priTolkova[kolkoMesta] = ((priTolkova[kolkoMesta - 1] - priTolkova[kolkoMesta - poneKolkoShestici - 1]*9)%mnogo + priTolkova[kolkoMesta - 1]*9)%mnogo;
    }
}

int main(){

    cin>>kolkoCifreno>>poneKolkoShestici;

    long long otgovor = 0;

    long long desteNaStepenta = 1;

    sCycli(kolkoCifreno);

    for(long long i = kolkoCifreno; i >= poneKolkoShestici; i--){
        //cout<<i<<" "<<poneKolkoShestici<<endl;
        //long long tekushto = (broiNachiniZa(i - poneKolkoShestici)*desteNaStepenta)%mnogo;
        long long tekushto = (priTolkova[i - poneKolkoShestici]*desteNaStepenta)%mnogo;
        //cout<<"na "<<i<<" poozicii i "<<poneKolkoShestici<<" shestici kazvame "<<tekushto<<endl;
        otgovor = (otgovor + tekushto)%mnogo;
        desteNaStepenta = (desteNaStepenta * 10)%mnogo;
    }

    cout<<otgovor<<endl;

    return 0;
}
