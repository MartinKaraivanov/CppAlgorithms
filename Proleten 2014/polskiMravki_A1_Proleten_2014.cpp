#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<stdio.h>
using namespace std;

int broiVarhove;
int broiNeKraini;

int sasedstvo[1000010][4];

int skorostHorizonLqva;
int skorostNagoreLqva;
int skorostNadoluLqva;

int skorostHorizonDqsna;
int skorostNagoreDqsna;
int skorostNadoluDqsna;

struct DanniZaMomenta{
    double vKoiMoment;
    int vKoiVrah;
    int preden;
};

DanniZaMomenta momentiLqva[10000010];
int broiMomentiLqva = 0;

DanniZaMomenta momentiDqsna[10000010];
int broiMomentiDqsna = 0;

double normalnoVremeLqva = 0;

void dfsNormalnoParva(int segashenVrah, int otKadeIdvame){

    momentiLqva[broiMomentiLqva] = {normalnoVremeLqva, segashenVrah, otKadeIdvame};
    broiMomentiLqva++;

    if(sasedstvo[segashenVrah][0] != 0){
        normalnoVremeLqva += skorostHorizonLqva;
        dfsNormalnoParva(sasedstvo[segashenVrah][0], segashenVrah);
        normalnoVremeLqva += skorostHorizonLqva;
        momentiLqva[broiMomentiLqva] = {normalnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][0]};
        broiMomentiLqva++;
    }

    if(sasedstvo[segashenVrah][1] != 0){
        normalnoVremeLqva += skorostNagoreLqva;
        dfsNormalnoParva(sasedstvo[segashenVrah][1], segashenVrah);
        normalnoVremeLqva += skorostNadoluLqva;
        momentiLqva[broiMomentiLqva] = {normalnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][1]};
        broiMomentiLqva++;
    }

    if(sasedstvo[segashenVrah][2] != 0){
        normalnoVremeLqva += skorostNagoreLqva;
        dfsNormalnoParva(sasedstvo[segashenVrah][2], segashenVrah);
        normalnoVremeLqva += skorostNadoluLqva;
        momentiLqva[broiMomentiLqva] = {normalnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][2]};
        broiMomentiLqva++;
    }

    if(sasedstvo[segashenVrah][3] != 0){
        normalnoVremeLqva += skorostHorizonLqva;
        dfsNormalnoParva(sasedstvo[segashenVrah][3], segashenVrah);
        normalnoVremeLqva += skorostHorizonLqva;
        momentiLqva[broiMomentiLqva] = {normalnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][3]};
        broiMomentiLqva++;
    }

}

double normalnoVremeDqsna = 0;

void dfsNormalnoVtora(int segashenVrah, int otKadeIdvame){

    momentiDqsna[broiMomentiDqsna] = {normalnoVremeDqsna, segashenVrah, otKadeIdvame};
    broiMomentiDqsna++;

    if(sasedstvo[segashenVrah][3] != 0){
        normalnoVremeDqsna += skorostHorizonDqsna;
        dfsNormalnoVtora(sasedstvo[segashenVrah][3], segashenVrah);
        normalnoVremeDqsna += skorostHorizonDqsna;
        momentiDqsna[broiMomentiDqsna] = {normalnoVremeDqsna, segashenVrah, sasedstvo[segashenVrah][3]};
        broiMomentiDqsna++;
    }

    if(sasedstvo[segashenVrah][2] != 0){
        normalnoVremeDqsna += skorostNagoreDqsna;
        dfsNormalnoVtora(sasedstvo[segashenVrah][2], segashenVrah);
        normalnoVremeDqsna += skorostNadoluDqsna;
        momentiDqsna[broiMomentiDqsna] = {normalnoVremeDqsna, segashenVrah, sasedstvo[segashenVrah][2]};
        broiMomentiDqsna++;
    }

    if(sasedstvo[segashenVrah][1] != 0){
        normalnoVremeDqsna += skorostNagoreDqsna;
        dfsNormalnoVtora(sasedstvo[segashenVrah][1], segashenVrah);
        normalnoVremeDqsna += skorostNadoluDqsna;
        momentiDqsna[broiMomentiDqsna] = {normalnoVremeDqsna, segashenVrah, sasedstvo[segashenVrah][1]};
        broiMomentiDqsna++;
    }

    if(sasedstvo[segashenVrah][0] != 0){
        normalnoVremeDqsna += skorostHorizonDqsna;
        dfsNormalnoVtora(sasedstvo[segashenVrah][0], segashenVrah);
        normalnoVremeDqsna += skorostHorizonDqsna;
        momentiDqsna[broiMomentiDqsna] = {normalnoVremeDqsna, segashenVrah, sasedstvo[segashenVrah][0]};
        broiMomentiDqsna++;
    }

}


DanniZaMomenta obratniMomentiLqva[20000010];
int broiObratniMomentiLqva = 0;

DanniZaMomenta obratniMomentiDqsna[20000010];
int broiObratniMomentiDqsna = 0;

double obratnoVremeLqva = 0;

void dfsObratnoParva(int segashenVrah, int otKadeIdvame){

    obratniMomentiLqva[broiObratniMomentiLqva] = {obratnoVremeLqva, segashenVrah, otKadeIdvame};
    broiObratniMomentiLqva++;

    if(sasedstvo[segashenVrah][3] != 0){
        obratnoVremeLqva += skorostHorizonLqva;
        dfsObratnoParva(sasedstvo[segashenVrah][3], segashenVrah);
        obratnoVremeLqva += skorostHorizonLqva;
        obratniMomentiLqva[broiObratniMomentiLqva] = {obratnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][3]};
        broiObratniMomentiLqva++;
    }

    if(sasedstvo[segashenVrah][2] != 0){
        obratnoVremeLqva += skorostNagoreLqva;
        dfsObratnoParva(sasedstvo[segashenVrah][2], segashenVrah);
        obratnoVremeLqva += skorostNadoluLqva;
        obratniMomentiLqva[broiObratniMomentiLqva] = {obratnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][2]};
        broiObratniMomentiLqva++;
    }

    if(sasedstvo[segashenVrah][1] != 0){
        obratnoVremeLqva += skorostNagoreLqva;
        dfsObratnoParva(sasedstvo[segashenVrah][1], segashenVrah);
        obratnoVremeLqva += skorostNadoluLqva;
        obratniMomentiLqva[broiObratniMomentiLqva] = {obratnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][1]};
        broiObratniMomentiLqva++;
    }

    if(sasedstvo[segashenVrah][0] != 0){
        obratnoVremeLqva += skorostHorizonLqva;
        dfsObratnoParva(sasedstvo[segashenVrah][0], segashenVrah);
        obratnoVremeLqva += skorostHorizonLqva;
        obratniMomentiLqva[broiObratniMomentiLqva] = {obratnoVremeLqva, segashenVrah, sasedstvo[segashenVrah][0]};
        broiObratniMomentiLqva++;
    }

}

double obratnovremeDqsna = 0;

void dfsObratnoVtora(int segashenVrah, int otKadeIdvame){

    obratniMomentiDqsna[broiObratniMomentiDqsna] = {obratnovremeDqsna, segashenVrah, otKadeIdvame};
    broiObratniMomentiDqsna++;

    if(sasedstvo[segashenVrah][0] != 0){
        obratnovremeDqsna += skorostHorizonDqsna;
        dfsObratnoVtora(sasedstvo[segashenVrah][0], segashenVrah);
        obratnovremeDqsna += skorostHorizonDqsna;
        obratniMomentiDqsna[broiObratniMomentiDqsna] = {obratnovremeDqsna, segashenVrah, sasedstvo[segashenVrah][0]};
        broiObratniMomentiDqsna++;
    }

    if(sasedstvo[segashenVrah][1] != 0){
        obratnovremeDqsna += skorostNagoreDqsna;
        dfsObratnoVtora(sasedstvo[segashenVrah][1], segashenVrah);
        obratnovremeDqsna += skorostNadoluDqsna;
        obratniMomentiDqsna[broiObratniMomentiDqsna] = {obratnovremeDqsna, segashenVrah, sasedstvo[segashenVrah][1]};
        broiObratniMomentiDqsna++;
    }

    if(sasedstvo[segashenVrah][2] != 0){
        obratnovremeDqsna += skorostNagoreDqsna;
        dfsObratnoVtora(sasedstvo[segashenVrah][2], segashenVrah);
        obratnovremeDqsna += skorostNadoluDqsna;
        obratniMomentiDqsna[broiObratniMomentiDqsna] = {obratnovremeDqsna, segashenVrah, sasedstvo[segashenVrah][2]};
        broiObratniMomentiDqsna++;
    }

    if(sasedstvo[segashenVrah][3] != 0){
        obratnovremeDqsna += skorostHorizonDqsna;
        dfsObratnoVtora(sasedstvo[segashenVrah][3], segashenVrah);
        obratnovremeDqsna += skorostHorizonDqsna;
        obratniMomentiDqsna[broiObratniMomentiDqsna] = {obratnovremeDqsna, segashenVrah, sasedstvo[segashenVrah][3]};
        broiObratniMomentiDqsna++;
    }

}

int ednotoVKoetoSeSresht;
int prednotoPrediSreshtata;

double momentParvoLqva;
double momentVtoroLqva;
double momentParvoDqsna;
double momentVtoroDqsna;

double momentVrashatneLqva;
double momentVrashtaneDqsna;

int kakuvTipSaTeziDvataVarha(int vtoriqPoRedNaLeviq, int predishniqPoRedNaLeviq){

    if(sasedstvo[vtoriqPoRedNaLeviq][0] == predishniqPoRedNaLeviq ||
        sasedstvo[vtoriqPoRedNaLeviq][3] == predishniqPoRedNaLeviq ||
        sasedstvo[predishniqPoRedNaLeviq][0] == vtoriqPoRedNaLeviq ||
        sasedstvo[predishniqPoRedNaLeviq][3] == vtoriqPoRedNaLeviq)
    {
        return 1;
    }

    if(sasedstvo[vtoriqPoRedNaLeviq][1] == predishniqPoRedNaLeviq ||
        sasedstvo[vtoriqPoRedNaLeviq][2] == predishniqPoRedNaLeviq)
    {
        return 2;
    }

    return 3;
}

double momentNovoParvoLqvo;
double momentNovoVtoroLqva;
double momentNovoParvoDqsna;
double momentNovoVtoroDqsna;

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //cin>>broiVarhove>>broiNeKraini;
    scanf("%i %i", &broiVarhove, &broiNeKraini);

    for(int i = 0; i < broiNeKraini; i++){
        int koiVrah;

        //cin>>koiVrah;
        scanf("%i", &koiVrah);

        for(int j = 0; j < 4; j++){
            //cin>>sasedstvo[koiVrah][j];
            scanf("%i", &sasedstvo[koiVrah][j]);
        }
    }

    sasedstvo[0][1] = 1;

    //cin>>skorostHorizonLqva>>skorostNagoreLqva>>skorostNadoluLqva>>skorostHorizonDqsna>>skorostNagoreDqsna>>skorostNadoluDqsna;
    scanf("%i %i %i %i %i %i", &skorostHorizonLqva, &skorostNagoreLqva, &skorostNadoluLqva, &skorostHorizonDqsna, &skorostNagoreDqsna, &skorostNadoluDqsna);

    dfsNormalnoParva(0, -1);
    dfsNormalnoVtora(0, -1);

    dfsObratnoParva(0, -1);
    //dfsObratnoParva(0, -1);

    int broiSegaobratniM = broiObratniMomentiLqva;
    for(int i = 0; i < broiSegaobratniM; i++){
        obratniMomentiLqva[broiObratniMomentiLqva] = {obratniMomentiLqva[i].vKoiMoment + obratnoVremeLqva, obratniMomentiLqva[i].vKoiVrah, obratniMomentiLqva[i].preden};
        broiObratniMomentiLqva++;
    }

    dfsObratnoVtora(0, -1);
    //dfsObratnoVtora(0, -1);

    int broiSegaobratniMDqsna = broiObratniMomentiDqsna;
    for(int i = 0; i < broiSegaobratniMDqsna; i++){
        obratniMomentiDqsna[broiObratniMomentiDqsna] = {obratniMomentiDqsna[i].vKoiMoment + obratnovremeDqsna, obratniMomentiDqsna[i].vKoiVrah, obratniMomentiDqsna[i].preden};
        broiObratniMomentiDqsna++;
    }

    /*cout<<"momenti lqva:"<<endl;
    for(int i = 0; i < broiMomentiLqva; i++){
        cout<<momentiLqva[i].vKoiMoment<<" "<<momentiLqva[i].vKoiVrah<<endl;
    }
    cout<<endl;*/

    /*bool prostLiESluchaq = false;

    for(int i = 0; i < broiMomentiLqva; i++){
        int indexDqsna = broiMomentiDqsna - i - 1;

        cout<<momentiLqva[i].vKoiMoment<<" "<<momentiLqva[i].vKoiVrah<<"    "<<momentiDqsna[indexDqsna].vKoiMoment<<" "<<momentiDqsna[indexDqsna].vKoiVrah<<endl;

        if(momentiLqva[i].vKoiMoment - momentiDqsna[indexDqsna].vKoiMoment < 0.00001 && momentiLqva[i].vKoiMoment - momentiDqsna[indexDqsna].vKoiMoment > -0.00001){
            ednotoVKoetoSeSresht = momentiLqva[i].vKoiVrah;
            prednotoPrediSreshtata = momentiLqva[i].preden;
            prostLiESluchaq = true;
            momentVrashatneLqva = momentiLqva[i].vKoiMoment;
            momentVrashtaneDqsna = momentiDqsna[i].vKoiMoment;
            break;
        }else{
            if(momentiLqva[i].vKoiMoment > momentiDqsna[indexDqsna].vKoiMoment){
                ednotoVKoetoSeSresht = momentiLqva[i].vKoiVrah;
                prednotoPrediSreshtata = momentiLqva[i].preden;
                momentParvoLqva = momentiLqva[i - 1].vKoiMoment;
                momentVtoroLqva = momentiLqva[i].vKoiMoment;
                momentParvoDqsna = momentiDqsna[indexDqsna].vKoiMoment;
                momentVtoroDqsna = momentiDqsna[indexDqsna + 1].vKoiMoment;
                break;
            }
        }
    }*/

    int indexLqva = 0;
    int indexDqsna = 0;

    while(true){
        if(momentiLqva[indexLqva].vKoiVrah == momentiDqsna[indexDqsna].preden &&
            momentiLqva[indexLqva].preden == momentiDqsna[indexDqsna].vKoiVrah)
        {
            momentParvoLqva = momentiLqva[indexLqva - 1].vKoiMoment;
            momentVtoroLqva = momentiLqva[indexLqva].vKoiMoment;
            momentParvoDqsna = momentiDqsna[indexDqsna - 1].vKoiMoment;
            momentVtoroDqsna = momentiDqsna[indexDqsna].vKoiMoment;

            ednotoVKoetoSeSresht = momentiLqva[indexLqva].vKoiVrah;
            prednotoPrediSreshtata = momentiDqsna[indexDqsna].vKoiVrah;
            break;
        }

        if(momentiLqva[indexLqva].vKoiMoment < momentiDqsna[indexDqsna].vKoiMoment){
            indexLqva++;
        }else{
            indexDqsna++;
        }
    }

    //cout<<ednotoVKoetoSeSresht<<" "<<prednotoPrediSreshtata<<endl;

    //cout<<"momenti okolo sreshtata "<<momentParvoLqva<<" "<<momentVtoroLqva<<"  "<<momentParvoDqsna<<" "<<momentVtoroDqsna<<endl;

    double momentNaSreshta =
        (momentVtoroLqva*momentVtoroDqsna - momentParvoLqva*momentParvoDqsna)/(momentVtoroDqsna - momentParvoDqsna + momentVtoroLqva - momentParvoLqva);

    //cout<<"moment na sreshtata "<<momentNaSreshta<<endl;

    int tip = kakuvTipSaTeziDvataVarha(ednotoVKoetoSeSresht, prednotoPrediSreshtata);
        /// 1 - horizontalna, 2 - predniq sprqmo lqavata mravka e po gore ot nas, 3 - obratnoto na 2

    double razlikaLqvata = momentNaSreshta - momentParvoLqva;
    double razlikaDqsnata = momentNaSreshta - momentParvoDqsna;

    double lqvaKakvaChastOtCqloto = -1;
    double dqsnaKakvaChastOtCqloto = -1;

    double ostLqvaVrashtane = -1;
    double ostDqsnaVrashtane = -1;

    if(tip == 1){
        lqvaKakvaChastOtCqloto = razlikaLqvata/skorostHorizonLqva;
        dqsnaKakvaChastOtCqloto = razlikaDqsnata/skorostHorizonDqsna;

        ostLqvaVrashtane = lqvaKakvaChastOtCqloto*skorostHorizonLqva;
        ostDqsnaVrashtane = dqsnaKakvaChastOtCqloto*skorostHorizonDqsna;
    }else{
        if(tip == 2){
            lqvaKakvaChastOtCqloto = razlikaLqvata/skorostNadoluLqva;
            dqsnaKakvaChastOtCqloto = razlikaDqsnata/skorostNagoreDqsna;

            ostLqvaVrashtane = lqvaKakvaChastOtCqloto*skorostNagoreLqva;
            ostDqsnaVrashtane = dqsnaKakvaChastOtCqloto*skorostNadoluDqsna;
        }else{
            lqvaKakvaChastOtCqloto = razlikaLqvata/skorostNagoreLqva;
            dqsnaKakvaChastOtCqloto = razlikaDqsnata/skorostNadoluDqsna;

            ostLqvaVrashtane = lqvaKakvaChastOtCqloto*skorostNadoluLqva;
            ostDqsnaVrashtane = dqsnaKakvaChastOtCqloto*skorostNagoreDqsna;
        }
    }

    momentVrashatneLqva = momentNaSreshta + ostLqvaVrashtane;
    momentVrashtaneDqsna = momentNaSreshta + ostDqsnaVrashtane;


    //cout<<"leviq se vrashta v svoq v "<<momentVrashatneLqva<<" dqsnata se vrashta v svoq "<<momentVrashtaneDqsna<<endl;

    int indexLqvaObraten = -1;

    for(int i = 0; i < broiObratniMomentiLqva; i++){
        if(obratniMomentiLqva[i].vKoiVrah == prednotoPrediSreshtata && obratniMomentiLqva[i].preden == ednotoVKoetoSeSresht){
            indexLqvaObraten = i;
            /*if(prostLiESluchaq == true){
                indexLqvaObraten--;
            }*/
            break;
        }
    }

    int indexDqsnaObraten = -1;

    for(int i = 0; i < broiObratniMomentiDqsna; i++){
        if(obratniMomentiDqsna[i].vKoiVrah == ednotoVKoetoSeSresht && obratniMomentiDqsna[i].preden == prednotoPrediSreshtata){
            indexDqsnaObraten = i;
            break;
        }
    }

    double razlikaVLeviq = momentVrashatneLqva - obratniMomentiLqva[indexLqvaObraten].vKoiMoment;
    double razlikaVDesniq = momentVrashtaneDqsna - obratniMomentiDqsna[indexDqsnaObraten].vKoiMoment;

    for(int i = 0; i < broiObratniMomentiLqva; i++){
        obratniMomentiLqva[i].vKoiMoment += razlikaVLeviq;
    }

    for(int i = 0; i < broiObratniMomentiDqsna; i++){
        obratniMomentiDqsna[i].vKoiMoment += razlikaVDesniq;
    }

    //cout<<"indexite sa lqv "<<indexLqvaObraten<<" "<<obratniMomentiLqva[indexLqvaObraten].vKoiMoment;
    //cout<<" "<<obratniMomentiLqva[indexLqvaObraten].vKoiVrah<<" preden "<<obratniMomentiLqva[indexLqvaObraten].preden<<endl;
    //cout<<"desen "<<indexDqsnaObraten<<" "<<obratniMomentiDqsna[indexDqsnaObraten].vKoiMoment<<" ";
    //cout<<obratniMomentiDqsna[indexDqsnaObraten].vKoiVrah<<" preden "<<obratniMomentiDqsna[indexDqsnaObraten].preden<<endl;

    /*for(int i = 0; i < broiObratniMomentiLqva; i++){
        cout<<obratniMomentiLqva[i].vKoiMoment<<" "<<obratniMomentiLqva[i].vKoiVrah<<endl;
    }
    cout<<endl<<endl;
    for(int i = 0; i < broiObratniMomentiDqsna; i++){
        cout<<obratniMomentiDqsna[i].vKoiMoment<<" "<<obratniMomentiDqsna[i].vKoiVrah<<endl;
    }*/

    indexLqvaObraten++;
    indexDqsnaObraten++;

    while(true){
        if(obratniMomentiLqva[indexLqvaObraten].vKoiVrah == obratniMomentiDqsna[indexDqsnaObraten].preden &&
            obratniMomentiLqva[indexLqvaObraten].preden == obratniMomentiDqsna[indexDqsnaObraten].vKoiVrah)
        {
            momentNovoParvoLqvo = obratniMomentiLqva[indexLqvaObraten - 1].vKoiMoment;
            momentNovoVtoroLqva = obratniMomentiLqva[indexLqvaObraten].vKoiMoment;
            momentNovoParvoDqsna = obratniMomentiDqsna[indexDqsnaObraten - 1].vKoiMoment;
            momentNovoVtoroDqsna = obratniMomentiDqsna[indexDqsnaObraten].vKoiMoment;
            break;
        }

        if(obratniMomentiLqva[indexLqvaObraten].vKoiMoment < obratniMomentiDqsna[indexDqsnaObraten].vKoiMoment){
            indexLqvaObraten++;
        }else{
            indexDqsnaObraten++;
        }
    }

    //cout<<"novite sa: parvo na lqva "<<momentNovoParvoLqvo<<" vtoro na lqva "<<momentNovoVtoroLqva<<endl;
    //cout<<"parvo na dqsna "<<momentNovoParvoDqsna<<" vtoroto "<<momentNovoVtoroDqsna<<endl;

    double momentNaNovataSreshta =
            (momentNovoVtoroLqva*momentNovoVtoroDqsna - momentNovoParvoLqvo*momentNovoParvoDqsna)/
            (momentNovoVtoroDqsna - momentNovoParvoDqsna + momentNovoVtoroLqva - momentNovoParvoLqvo);

    //cout<<fixed<<setprecision(5)<<momentNaNovataSreshta<<endl;
    printf("%.5f", momentNaNovataSreshta);

    return 0;
}
