#include<iostream>
using namespace std;

const long long mnogo = 1000000007;

long long daljina;
int tipove;

long long vdigniNaStepen(long long chislo, long long stepen){

    long long zaVrasht = 1;

    long long stepenuvano = chislo;

    long long kopieStepen = stepen;

    while(kopieStepen > 0){
        if((kopieStepen & 1) == 1){
            zaVrasht = (zaVrasht * stepenuvano)%mnogo;
        }

        stepenuvano = (stepenuvano * stepenuvano)%mnogo;

        kopieStepen >>= 1;
    }

    return zaVrasht;
}

void kopiraiMatricata(long long (&kade)[3][3], long long (&otKade)[3][3]){

    for(long long i = 0; i < 3; i++){
        for(long long j = 0; j < 3; j++){
            kade[i][j] = otKade[i][j];
        }
    }

}

void umnojiMatricite(long long (&parva)[3][3], long long (&vtora)[3][3]){
    long long rezultat[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            rezultat[i][j] = 0;

            for(int h = 0; h < 3; h++){
                rezultat[i][j] = (rezultat[i][j] + (parva[i][h] * vtora[h][j])%mnogo)%mnogo;
            }
        }
    }

    kopiraiMatricata(parva, rezultat);
}

void vdigniNaStepenMatricata(long long (&matrica)[3][3], long long stepen){

    long long kopieNaStepen = stepen - 1;

    long long stepenNaDvoikata[3][3];

    kopiraiMatricata(stepenNaDvoikata, matrica);

    while(kopieNaStepen > 0){
        if((kopieNaStepen & 1) == 1){
            umnojiMatricite(matrica, stepenNaDvoikata);
        }

        umnojiMatricite(stepenNaDvoikata, stepenNaDvoikata);

        kopieNaStepen >>= 1;
    }

}

long long priTolkova[2000010];

long long otgovor(long long kolkoKubcheta){
    if(kolkoKubcheta == 0){
        return 1;
    }
    if(kolkoKubcheta == 1){
        return 0;
    }
    if(kolkoKubcheta == 2){
        if(tipove == 1 || tipove == 3){
            return 1;
        }else{
            return 0;
        }
    }
    if(kolkoKubcheta == 3){
        if(tipove == 2 || tipove == 3){
            return 1;
        }else{
            return 0;
        }
    }

    if(priTolkova[kolkoKubcheta] > -1){
        return priTolkova[kolkoKubcheta];
    }

    long long broiTuka = 0;

    if(kolkoKubcheta%2 == 0){
        if(tipove == 1 || tipove == 3){
            broiTuka = (broiTuka + otgovor(kolkoKubcheta - 2))%mnogo;
            broiTuka = (broiTuka + otgovor(kolkoKubcheta - 4))%mnogo;
        }
        if(tipove == 2 || tipove == 3){
            broiTuka = (broiTuka + 2*otgovor(kolkoKubcheta - 3))%mnogo;
        }
    }else{
        if(tipove == 1 || tipove == 3){
            broiTuka = (broiTuka + otgovor(kolkoKubcheta - 2))%mnogo;
        }
        if(tipove == 2 || tipove == 3){
            broiTuka = (broiTuka + otgovor(kolkoKubcheta - 3))%mnogo;
        }
    }

    priTolkova[kolkoKubcheta] = broiTuka;
    return broiTuka;
}

long long tovaCHisloNaFibonachi(long long koeChislo){
    if(koeChislo == 1){
        return 1;
    }
    if(koeChislo == 2){
        return 2;
    }

    /*long long predishno = 1;
    long long segashno = 2;

    for(long long i = 3; i <= koeChislo; i++){
        long long sledvashto = (predishno + segashno)%mnogo;

        predishno = segashno;
        segashno = sledvashto;
    }

    return segashno;*/

    long long matrichka[3][3];
    matrichka[0][0] = 1;
    matrichka[1][0] = 1;
    matrichka[0][1] = 1;
    matrichka[1][1] = 0;
    matrichka[0][2] = 0;
    matrichka[1][2] = 0;
    matrichka[2][0] = 0;
    matrichka[2][1] = 0;
    matrichka[2][2] = 0;

    vdigniNaStepenMatricata(matrichka, koeChislo);

    return matrichka[0][0];
}

long long daiTovaSTrannoChislo(long long koeChislo){
    if(koeChislo == 1){
        return 1;
    }
    if(koeChislo == 2){
        return 2;
    }
    if(koeChislo == 3){
        return 5;
    }

    /*long long poPredishno = 1;
    long long predishno = 1;
    long long segashno = 2;

    for(long long i = 3; i <= koeChislo; i++){
        long long sledvashto = (2*segashno + poPredishno)%mnogo;

        poPredishno = predishno;
        predishno = segashno;
        segashno = sledvashto;
    }

    return segashno;*/

    long long matrichka[3][3];
    matrichka[0][0] = 2;
    matrichka[1][0] = 1;
    matrichka[0][1] = 0;
    matrichka[1][1] = 0;
    matrichka[0][2] = 1;
    matrichka[1][2] = 0;
    matrichka[2][0] = 0;
    matrichka[2][1] = 1;
    matrichka[2][2] = 0;

    vdigniNaStepenMatricata(matrichka, koeChislo - 2);

    long long startovaRedica[3][3];
    startovaRedica[0][0] = 2;
    startovaRedica[1][0] = 0;
    startovaRedica[2][0] = 0;
    startovaRedica[0][1] = 1;
    startovaRedica[0][2] = 1;
    startovaRedica[1][1] = 0;
    startovaRedica[1][2] = 0;
    startovaRedica[2][1] = 0;
    startovaRedica[2][2] = 0;

    umnojiMatricite(startovaRedica, matrichka);

    return startovaRedica[0][0];
}

int main(){

    cin>>daljina>>tipove;

    /*for(long long i = 0; i <= daljina*2; i++){
        priTolkova[i] = -1;
    }

    cout<<"pri 3:"<<endl;
    for(int i = 1; i <= 10; i++){
        cout<<i<<" "<<otgovor(i*2)<<endl;
    }

    cout<<otgovor(daljina*2)<<endl;*/

    if(tipove == 1){
        cout<<tovaCHisloNaFibonachi(daljina)<<endl;
    }else{
        if(tipove == 2){
            if(daljina%3 == 0){
                cout<<vdigniNaStepen(2, daljina/3);
            }else{
                cout<<0<<endl;
            }
        }else{
            cout<<daiTovaSTrannoChislo(daljina)<<endl;
        }
    }

    return 0;
}
