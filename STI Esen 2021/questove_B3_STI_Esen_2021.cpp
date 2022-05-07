#include<iostream>
using namespace std;

const long long mnogo = 1000000000000007;

long long broiKuestove;
long long kolkoOpitNiTrZaParvotoNivo;
long long kolkoOpitNiTrZaVtorotoNivo;

struct DanniZaKuesta{
    long long opitZaNivo;
    long long vremeOtnema;
};

DanniZaKuesta kuestoveParvoNivo[512];
DanniZaKuesta kuestoveVtoroNivo[512];

long long priTolkova[128][512][512];

long long naiKratkoVremeZaIzp(long long doKade, long long nujenOpitParvo, long long nujenOpitVtoro){
    if(nujenOpitParvo < 0){
        nujenOpitVtoro += nujenOpitParvo;
        nujenOpitParvo = 0;
    }

    if(nujenOpitVtoro < 0){
        nujenOpitVtoro = 0;
    }

    if(nujenOpitVtoro <= 0 && nujenOpitParvo <= 0){
        return 0;
    }

    if(doKade <= 0){
        return mnogo;
    }


    if(priTolkova[doKade][nujenOpitParvo][nujenOpitVtoro] > 0){
        return priTolkova[doKade][nujenOpitParvo][nujenOpitVtoro];
    }

    /// ako ne vzemem tozi
    long long akoNeVzemem = naiKratkoVremeZaIzp(doKade - 1, nujenOpitParvo, nujenOpitVtoro);

    /// ako dadem na parviq
    long long akoDademNaParviq = mnogo;
    if(nujenOpitParvo > 0){
        akoDademNaParviq = kuestoveParvoNivo[doKade].vremeOtnema + naiKratkoVremeZaIzp(doKade - 1, nujenOpitParvo - kuestoveParvoNivo[doKade].opitZaNivo, nujenOpitVtoro);
    }

    /// ako dadem na vtoriq
    long long akoDademNaVtoriq = mnogo;
    if(nujenOpitVtoro > 0){
        akoDademNaVtoriq = kuestoveVtoroNivo[doKade].vremeOtnema + naiKratkoVremeZaIzp(doKade - 1, nujenOpitParvo, nujenOpitVtoro - kuestoveVtoroNivo[doKade].opitZaNivo);
    }

    long long zaTuka = min(akoNeVzemem, min(akoDademNaParviq, akoDademNaVtoriq));

    priTolkova[doKade][nujenOpitParvo][nujenOpitVtoro] = zaTuka;
    return zaTuka;
}

long long sCycli(long long zaDoKade, long long zaNujenOpitParvo, long long zaNujenOpitVtoro){
    for(long long i = 0; i <= zaNujenOpitParvo; i++){
        for(long long j = 0; j <= zaNujenOpitVtoro; j++){
            priTolkova[0][i][j] = mnogo;
        }
    }

    for(long long i = 0; i <= zaDoKade; i++){
        priTolkova[i%2][0][0] = 0;
    }

    for(long long doKade = 1; doKade <= zaDoKade; doKade++){
        for(long long nujenOpitParvo = 0; nujenOpitParvo <= zaNujenOpitParvo; nujenOpitParvo++){
            for(long long nujenOpitVtoro = 0; nujenOpitVtoro <= zaNujenOpitVtoro; nujenOpitVtoro++){

                /// ako ne vzemem tozi
                long long akoNeVzemem = priTolkova[(doKade - 1)%2][nujenOpitParvo][nujenOpitVtoro];

                /// ako dadem na parviq
                long long novOpitParvoto = nujenOpitParvo - kuestoveParvoNivo[doKade].opitZaNivo;
                long long akoDademNaParviq = kuestoveParvoNivo[doKade].vremeOtnema;
                if(novOpitParvoto <= 0){
                    akoDademNaParviq += priTolkova[(doKade - 1)%2][0][max((long long)0, nujenOpitVtoro + novOpitParvoto)];
                }else{
                    akoDademNaParviq += priTolkova[(doKade - 1)%2][novOpitParvoto][nujenOpitVtoro];
                }

                /// ako dadem na vtoriq
                long long akoDademNaVtoriq =
                    kuestoveVtoroNivo[doKade].vremeOtnema + priTolkova[(doKade - 1)%2][nujenOpitParvo][max((long long)0, nujenOpitVtoro - kuestoveVtoroNivo[doKade].opitZaNivo)];

                long long zaTuka = min(akoNeVzemem, min(akoDademNaParviq, akoDademNaVtoriq));

                priTolkova[doKade%2][nujenOpitParvo][nujenOpitVtoro] = zaTuka;

            }
        }
    }

    return priTolkova[zaDoKade%2][zaNujenOpitParvo][zaNujenOpitVtoro];
}


int main(){

    cin>>broiKuestove>>kolkoOpitNiTrZaParvotoNivo>>kolkoOpitNiTrZaVtorotoNivo;

    for(long long i = 1; i <= broiKuestove; i++){
        cin>>kuestoveParvoNivo[i].opitZaNivo>>kuestoveParvoNivo[i].vremeOtnema>>kuestoveVtoroNivo[i].opitZaNivo>>kuestoveVtoroNivo[i].vremeOtnema;
    }

    if(broiKuestove >= 128 || kolkoOpitNiTrZaParvotoNivo >= 512 || kolkoOpitNiTrZaVtorotoNivo >= 512){
        cout<<"grozen tekst"<<endl;
        return 0;
    }

    long long otgovor = naiKratkoVremeZaIzp(broiKuestove, kolkoOpitNiTrZaParvotoNivo, kolkoOpitNiTrZaVtorotoNivo);
    //long long otgovor = sCycli(broiKuestove, kolkoOpitNiTrZaParvotoNivo, kolkoOpitNiTrZaVtorotoNivo)

    if(otgovor < mnogo){
        cout<<otgovor<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}
