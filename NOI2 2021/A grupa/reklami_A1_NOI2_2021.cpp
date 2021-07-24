#include<iostream>
#include<map>
using namespace std;

struct DanniZaMinutata{
    long long broiVlezli;
    long long broiIzlezli;
    long long broiHoraVlezliDo;
    long long broiHoraIzlezliDo;
    long long naiGolqmotoDo;
    long long broiKoitoSheChuqtTogava;
};

int broiHora;
long long daljinaNaReklamata;

map<long long, DanniZaMinutata> minuti;

/*map<long long, long long> broiHoraVlezliDo;
map<long long, long long> broiHoraIzlezliDo;

map<long long, long long> naiGolqmotoDo;

map<long long, long long> broiKoitoSheChuqtTogava;*/

long long naiMalakMoment = 1000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiHora>>daljinaNaReklamata;

    for(int i = 0; i < broiHora; i++){
        long long kogaVliza;
        long long kogaIzliza;

        cin>>kogaVliza>>kogaIzliza;

        if(kogaIzliza - kogaVliza >= daljinaNaReklamata){
            minuti[kogaVliza].broiVlezli++;
            minuti[kogaIzliza].broiIzlezli++;
            naiMalakMoment = min(naiMalakMoment, kogaVliza);
        }
    }

    long long preden = 0;

    for(map<long long, DanniZaMinutata>::iterator i = minuti.begin(); i != minuti.end(); i++){
        long long segashen = i -> first;
        DanniZaMinutata tuka = i -> second;

        minuti[segashen].broiHoraVlezliDo = minuti[preden].broiHoraVlezliDo + tuka.broiVlezli;
        minuti[segashen].broiHoraIzlezliDo = minuti[preden].broiHoraIzlezliDo + tuka.broiIzlezli;

        preden = segashen;
    }

    /*for(map<long long, DanniZaMinutata>::iterator i = minuti.begin(); i != minuti.end(); i++){
        cout<<i -> first<<" "<<broiHoraVlezliDo[i -> first]<<" "<<broiHoraIzlezliDo[i -> first]<<endl;
    }*/

    long long naiGolqmoto = 0;

    for(map<long long, DanniZaMinutata>::iterator i = minuti.begin(); i != minuti.end(); i++){
        long long segashen = i -> first;

        auto proba = minuti.lower_bound(segashen + daljinaNaReklamata);

        if(proba == minuti.end()){
            break;
        }

        long long doKadeIzlezliHora = (*proba).first;

        //cout<<i -> first<<" "<<doKadeIzlezliHora<<endl;

        //cout<<broiHoraIzlezliDo[doKadeIzlezliHora] - minuti[doKadeIzlezliHora].broiIzlezli<<endl;

        long long broiTuka =
            minuti[segashen].broiHoraVlezliDo -
                (minuti[doKadeIzlezliHora].broiHoraIzlezliDo - minuti[doKadeIzlezliHora].broiIzlezli);

        naiGolqmoto = max(naiGolqmoto, broiTuka);
        minuti[doKadeIzlezliHora].naiGolqmotoDo = naiGolqmoto;

        minuti[segashen].broiKoitoSheChuqtTogava = broiTuka;
        //cout<<"broi tuka: "<<broiTuka<<" nai golqm do tuka: "<<naiGolqmotoDo[i -> first]<<" sbor tuka: "<<sborTuka<<endl;
    }

    long long naiGolqmSbor = 0;

    for(map<long long, DanniZaMinutata>::iterator i = minuti.begin(); i != minuti.end(); i++){
        long long segashen = i -> first;

        auto proba = minuti.lower_bound(segashen + daljinaNaReklamata);

        if(proba == minuti.end()){
            break;
        }

        long long doKadeIzlezliHora = (*proba).first;

        //cout<<i -> first<<" "<<doKadeIzlezliHora<<endl;

        //cout<<broiHoraIzlezliDo[doKadeIzlezliHora] - minuti[doKadeIzlezliHora].broiIzlezli<<endl;

        long long broiTuka = minuti[segashen].broiKoitoSheChuqtTogava;

        long long sborTuka = broiTuka + minuti[segashen].naiGolqmotoDo;
        naiGolqmSbor = max(naiGolqmSbor, sborTuka);

        if(doKadeIzlezliHora - segashen >= 2*daljinaNaReklamata){
            naiGolqmSbor = max(naiGolqmSbor, 2*broiTuka);
        }

        //cout<<"broi tuka: "<<broiTuka<<" nai golqm do tuka: "<<naiGolqmotoDo[i -> first]<<" sbor tuka: "<<sborTuka<<endl;
    }

    cout<<naiGolqmSbor<<endl;

    return 0;
}
