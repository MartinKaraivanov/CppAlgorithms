#include<iostream>
#include<algorithm>
using namespace std;

long long redica[1000010];

bool imameLiChisloto[65];
long long naTovaChisloKakvoTrqbvaDaPishe[65];

long long priTolkova[65][65];

void podgotvqne(long long kolkoTrqbvaDaVzemaNaiMnogo, long long otKolkoNaiMnogo){
  // ne e nujno
    for(long long i = 0; i <= kolkoTrqbvaDaVzemaNaiMnogo; i++){
        for(long long j = 0; j <= otKolkoNaiMnogo; j++){
            priTolkova[i][j] = 0;
        }
    }
}

long long broiKombinacii(long long kolkoDaVzemem, long long otKolko){
    if((kolkoDaVzemem <= 0) || (otKolko <= 0)|| (kolkoDaVzemem > otKolko)){
        cout << "ne moje da se vzemat " << kolkoDaVzemem << " elementa ot " << otKolko <<endl;
        return 0;
    }

    if(kolkoDaVzemem == 1){
        return otKolko;
    }

    if(otKolko == kolkoDaVzemem){
        return 1;
    }

    if(priTolkova[kolkoDaVzemem][otKolko] > 0){
        return priTolkova[kolkoDaVzemem][otKolko];
    }

    long long bezNego = broiKombinacii(kolkoDaVzemem, otKolko - 1);
    long long sasNego = broiKombinacii(kolkoDaVzemem - 1, otKolko - 1);

    priTolkova[kolkoDaVzemem][otKolko] = sasNego + bezNego;
    return sasNego+bezNego;
}

void podgotvqne2(long long kolkoTrqbvaDaVzemaNaiMnogo, long long otKolkoNaiMnogo){
    for(long long kolkoTrqbvaDaVzema = 1; kolkoTrqbvaDaVzema <= kolkoTrqbvaDaVzemaNaiMnogo; kolkoTrqbvaDaVzema++){
        priTolkova[kolkoTrqbvaDaVzema][kolkoTrqbvaDaVzema] = 1;
    }

    for(long long otKolko = 1; otKolko <= otKolkoNaiMnogo; otKolko++){
        priTolkova[1][otKolko] = otKolko;
    }

    for(long long kolkoDaVzema = 2; kolkoDaVzema <= kolkoTrqbvaDaVzemaNaiMnogo; kolkoDaVzema++){
        for(long long otKolko = kolkoDaVzema + 1; otKolko <= otKolkoNaiMnogo; otKolko++){
            long long bezNego = 0;
            long long sasNego = 0;

            bezNego = priTolkova[kolkoDaVzema][otKolko - 1];
            sasNego = priTolkova[kolkoDaVzema - 1][otKolko - 1];

            priTolkova[kolkoDaVzema][otKolko] = sasNego + bezNego;
        }
    }

}

long long broiKombinacii2(long long kolkoDaVzemem, long long otKolko){
    if((kolkoDaVzemem <= 0) || (otKolko <= 0)|| (kolkoDaVzemem > otKolko)){
        cout << "ne moje da se vzemat " << kolkoDaVzemem << " elementa ot " << otKolko <<endl;
        return 0;
    }

    return priTolkova[kolkoDaVzemem][otKolko];
}

long long nomeraNaSrednoto(long long kolko, long long otKolko){
    long long brKomb = broiKombinacii2(kolko, otKolko);

    long long srNomerche = (brKomb + 1)/2;

    return srNomerche;
}

long long cifriteKotoNiTrqbvat[65];

void namiraneNaKombinaciqSNomer(long long koiNomer, long long broiRazlichnniChisla, long long naiGolqmoChislo){
    long long otKadeZapochvame = 1;
    long long natrupani = 0;
    for(long long indexcheOtMasiva = 0; indexcheOtMasiva < broiRazlichnniChisla; indexcheOtMasiva++){
        for(long long i = otKadeZapochvame; i <= naiGolqmoChislo; i++){
            long long uvelich = 1;
            if(indexcheOtMasiva < broiRazlichnniChisla - 1){
                uvelich = broiKombinacii2(broiRazlichnniChisla - (indexcheOtMasiva + 1), naiGolqmoChislo - i);
            }
            natrupani += uvelich;
            if(natrupani >= koiNomer){
                cifriteKotoNiTrqbvat[indexcheOtMasiva] = i;
                otKadeZapochvame = i + 1;
                natrupani -= uvelich;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long broiChislaVRedicata;
    long long naiGolqmoChislo;

    cin>>broiChislaVRedicata>>naiGolqmoChislo;


    if(broiChislaVRedicata > 1000000){
        cout<<"bla bla"<<endl;
    }

    if(naiGolqmoChislo > 60){
        cout<<"bla bla"<<endl;
    }

    long long broiRazlichnniChisla = 0;

    for(long long i = 0; i < broiChislaVRedicata; i++){
        cin>>redica[i];
        if(!imameLiChisloto[redica[i]]){
            broiRazlichnniChisla++;
            imameLiChisloto[redica[i]] = true;
        }
    }

    if(broiRazlichnniChisla > 60){
        cout<<"bla bla"<<endl;
    }

    podgotvqne2(broiRazlichnniChisla, naiGolqmoChislo);

    long long sredenNomer = nomeraNaSrednoto(broiRazlichnniChisla, naiGolqmoChislo);

    namiraneNaKombinaciqSNomer(sredenNomer, broiRazlichnniChisla, naiGolqmoChislo);

    long long kade = 0;

    for(long long i = 1; i <= naiGolqmoChislo; i++){
        if(imameLiChisloto[i]){
            naTovaChisloKakvoTrqbvaDaPishe[i] = cifriteKotoNiTrqbvat[kade];
            kade++;
        }
    }

    for(long long i = 0; i < broiChislaVRedicata; i++){
        cout<<naTovaChisloKakvoTrqbvaDaPishe[redica[i]]<<" ";
    }

    cout<<endl;

    return 0;
}
