#include<iostream>
#include<vector>
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
    int vKoiMoment;
    int vKoiVrah;
    int preden;
};

DanniZaMomenta momentiLqva[10000010];
int broiMomentiLqva = 0;

DanniZaMomenta momentiDqsna[10000010];
int broiMomentiDqsna = 0;

int normalnoVremeLqva = 0;

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

int normalnoVremeDqsna = 0;

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

int ednotoVKoetoSeSresht;
int drugotoVKoetoSeSresht;


int main(){

    cin>>broiVarhove>>broiNeKraini;

    for(int i = 0; i < broiNeKraini; i++){
        int koiVrah;

        cin>>koiVrah;

        for(int j = 0; j < 4; j++){
            cin>>sasedstvo[koiVrah][j];
        }
    }

    cin>>skorostHorizonLqva>>skorostNagoreLqva>>skorostNadoluLqva>>skorostHorizonDqsna>>skorostNagoreDqsna>>skorostNadoluDqsna;

    dfsNormalnoParva(1, 0);
    dfsNormalnoVtora(1, 0);

    for(int i = 0; i < broiMomentiLqva; i++){
        int indexDqsna = broiMomentiDqsna - i - 1;

        cout<<momentiLqva[i].vKoiMoment<<" "<<momentiLqva[i].vKoiVrah<<"    "<<momentiDqsna[indexDqsna].vKoiMoment<<" "<<momentiDqsna[indexDqsna].vKoiVrah<<endl;

        if(momentiLqva[i].vKoiMoment == momentiDqsna[indexDqsna].vKoiMoment){
            ednotoVKoetoSeSresht = momentiLqva[i].vKoiVrah;
            drugotoVKoetoSeSresht = momentiLqva[i].preden;
            break;
        }else{
            if(momentiLqva[i].vKoiMoment > momentiDqsna[indexDqsna].vKoiMoment){
                ednotoVKoetoSeSresht = momentiLqva[i].vKoiVrah;
                drugotoVKoetoSeSresht = momentiLqva[i].preden;
                break;
            }
        }
    }

    cout<<ednotoVKoetoSeSresht<<" "<<drugotoVKoetoSeSresht<<endl;

    return 0;
}
