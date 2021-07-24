#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;

long long broiKanali;
long long broiSmeni;

//string posledovatelnost;
char posledovatelnost[500010];

long long kakvaPosled[500010];
long long daljina;

struct DanniZaVrah{
    long long broiEdinici;
    long long broiMinusEdinici;
    bool imaLiTickhe;
    long long otKoiIndexObhvashta;
    long long doKoiIndexObhvashta;
    long long lqvoDeteNomer;
    long long dqsnoDeteNomer;
};

vector<DanniZaVrah> varhove;
long long nomerNaKorena = -1;

long long daiNovVrah(DanniZaVrah novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

long long napraviDarvo(long long otIndex, long long doIndex){
    if(otIndex == doIndex){
        if(kakvaPosled[otIndex] == 1){
            return daiNovVrah({1, 0, false, otIndex, doIndex, -1, -1});
        }else{
            return daiNovVrah({0, 1, false, otIndex, doIndex, -1, -1});
        }
    }

    long long lqvoDeteNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    long long dqsnoDeteNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    long long brEdinici = varhove[lqvoDeteNomer].broiEdinici + varhove[dqsnoDeteNomer].broiEdinici;
    long long brMinusEdinici = varhove[lqvoDeteNomer].broiMinusEdinici + varhove[dqsnoDeteNomer].broiMinusEdinici;

    return daiNovVrah({brEdinici, brMinusEdinici, false, otIndex, doIndex, lqvoDeteNomer, dqsnoDeteNomer});
}

void update(long long korenNaPoddarvoVrahNomer, long long otIndex, long long doIndex){
    if(korenNaPoddarvoVrahNomer == -1 ||
       otIndex > varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta ||
       doIndex < varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta){

        return;
    }

    if(otIndex <= varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta &&
       doIndex >= varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){

        //cout<<"sega slojihme tickche na vrah nomer "<<korenNaPoddarvoVrahNomer<<" a toi obhvashta ot ";
        //cout<<varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta<<" do ";
        //cout<<varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta<<endl;
        varhove[korenNaPoddarvoVrahNomer].imaLiTickhe = !varhove[korenNaPoddarvoVrahNomer].imaLiTickhe;
        return;
    }

    update(varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer, otIndex, doIndex);
    update(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer, otIndex, doIndex);

    if(varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer > -1){
        if(varhove[varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer].imaLiTickhe == true){
            varhove[korenNaPoddarvoVrahNomer].broiEdinici =
                varhove[varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer].broiMinusEdinici;
            varhove[korenNaPoddarvoVrahNomer].broiMinusEdinici =
                varhove[varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer].broiEdinici;
        }else{
            varhove[korenNaPoddarvoVrahNomer].broiEdinici =
                varhove[varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer].broiEdinici;
            varhove[korenNaPoddarvoVrahNomer].broiMinusEdinici =
                varhove[varhove[korenNaPoddarvoVrahNomer].lqvoDeteNomer].broiMinusEdinici;
        }

        if(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer > -1){
            if(varhove[varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer].imaLiTickhe == true){
                varhove[korenNaPoddarvoVrahNomer].broiEdinici +=
                    varhove[varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer].broiMinusEdinici;
                varhove[korenNaPoddarvoVrahNomer].broiMinusEdinici +=
                    varhove[varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer].broiEdinici;
            }else{
                varhove[korenNaPoddarvoVrahNomer].broiEdinici +=
                    varhove[varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer].broiEdinici;
                varhove[korenNaPoddarvoVrahNomer].broiMinusEdinici +=
                    varhove[varhove[korenNaPoddarvoVrahNomer].dqsnoDeteNomer].broiMinusEdinici;
            }
        }
    }
}

long long otgovori[500010];

long long smqnaOtKade[500010];
long long smqnaDoKade[500010];

long long kadeEKraqNaPdrdc[500010];

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/

    //cin>>broiKanali>>broiSmeni;
    scanf("%ld %ld", &broiKanali, &broiSmeni);

    //cin>>posledovatelnost;

    scanf("%500009s", posledovatelnost);

    //daljina = posledovatelnost.size();
    daljina = strlen(posledovatelnost);

    for(long long i = 0; i < daljina; i++){
        if(posledovatelnost[i] == '+'){
            kakvaPosled[i] = 1;
        }else{
            if(posledovatelnost[i] == '-'){
                kakvaPosled[i] = -1;
            }else{
                if(kakvaPosled[i - 1] == 1){
                    kakvaPosled[i] = -1;
                }else{
                    kakvaPosled[i] = 1;
                }
            }
        }
    }


    for(long long i = 0; i < broiSmeni; i++){
        //cin>>smqnaOtKade[i]>>smqnaDoKade[i];
        scanf("%ld %ld", &smqnaOtKade[i], &smqnaDoKade[i]);
    }

    long long kadeEZapochnala = daljina;

    for(long long i = daljina - 1; i >= 0; i--){
        if(posledovatelnost[i] != 'o'){
            kadeEZapochnala = daljina;
        }else{
            if(kadeEZapochnala == daljina){
                kadeEZapochnala = i;
            }

            kadeEKraqNaPdrdc[i] = kadeEZapochnala;
        }
    }

    nomerNaKorena = napraviDarvo(0, daljina - 1);

    for(long long i = 0; i < broiSmeni; i++){
        long long otKade = smqnaOtKade[i];
        long long dokade = smqnaDoKade[i];
        otKade--;
        dokade--;

        if(posledovatelnost[otKade] == 'o'){
            otKade = kadeEKraqNaPdrdc[otKade] + 1;
        }
        if(posledovatelnost[dokade + 1] == 'o'){
            dokade = kadeEKraqNaPdrdc[dokade + 1];
        }

        //cout<<"updatevame ot "<<otKade<<" do "<<dokade<<endl;

        //cout<<"predi update "<<varhove[nomerNaKorena].broiEdinici<<" "<<varhove[nomerNaKorena].broiMinusEdinici<<endl;

        update(nomerNaKorena, otKade, dokade);

        //cout<<"sled update "<<varhove[nomerNaKorena].broiEdinici<<" "<<varhove[nomerNaKorena].broiMinusEdinici<<endl;

        long long brEdinici = varhove[nomerNaKorena].broiEdinici;
        long long brMinusEdinici = varhove[nomerNaKorena].broiMinusEdinici;

        if(varhove[nomerNaKorena].imaLiTickhe == true){
            swap(brEdinici, brMinusEdinici);
        }

        long long stoinostSega = 1 + brEdinici - brMinusEdinici;

        if(stoinostSega <= 0){
            stoinostSega += broiKanali;
        }else{
            if(stoinostSega > broiKanali){
                stoinostSega -= broiKanali;
            }
        }

        printf("%ld \n", stoinostSega);
        //otgovori[i] = stoinostSega;
    }

    /*for(long long i = 0; i < broiSmeni; i++){
        //cout<<otgovori[i]<<endl;
        printf("%ld \n", otgovori[i]);
    }*/

    return 0;
}
