#include<iostream>
#include<map>
using namespace std;

int broiProgrami;
int broiIzpalneniq;

struct DanniZaProgramata{
    int vremePreproces;
    int vremeSashtinsko;
};

DanniZaProgramata programi[1000010];

struct DanniZaIntervala{
    int vremeSashtinsko;
    int vremePreproces;
    int vremeBezdGore;
    int vremeBezdDolu;
};

DanniZaIntervala intervali[1000010];

struct DanniZaOtgovor{
    int nujniSekundi;
    int parvoBezdeistvie;
    int vtoroBezdeistvie;
};

int obshtoSekundi;

map<int, int> gorniBezdeistviq;
map<int, int> dolniBezdeistviq;

void napraviIntervalite(){

    intervali[0] = {0, programi[0].vremePreproces, 0, programi[0].vremePreproces};

    dolniBezdeistviq[programi[0].vremePreproces]++;

    for(int i = 1; i < broiProgrami; i++){

        intervali[i] = {programi[i - 1].vremeSashtinsko, programi[i].vremePreproces, 0, 0};

        if(programi[i].vremePreproces <= programi[i - 1].vremeSashtinsko){
            int tekushtoGornoBezd = programi[i - 1].vremeSashtinsko - programi[i].vremePreproces;

            intervali[i].vremeBezdGore = tekushtoGornoBezd;
            gorniBezdeistviq[tekushtoGornoBezd]++;
        }else{
            int tekushtoDolnoBezd = programi[i].vremePreproces - programi[i - 1].vremeSashtinsko;

            intervali[i].vremeBezdDolu = tekushtoDolnoBezd;
            dolniBezdeistviq[tekushtoDolnoBezd]++;
        }
    }

    intervali[broiProgrami] = {programi[broiProgrami - 1].vremeSashtinsko, 0, programi[broiProgrami - 1].vremeSashtinsko, 0};

    gorniBezdeistviq[programi[broiProgrami - 1].vremeSashtinsko]++;
}

void updateniPrograma(int koqSmenqme, int sKoqSmenqme, bool preprocesLi){

    DanniZaIntervala originalen = intervali[koqSmenqme];

    if(preprocesLi == true){
        intervali[koqSmenqme].vremePreproces = programi[sKoqSmenqme].vremePreproces;
    }else{
        intervali[koqSmenqme].vremeSashtinsko = programi[sKoqSmenqme].vremeSashtinsko;
    }

    if(intervali[koqSmenqme].vremePreproces <= intervali[koqSmenqme].vremeSashtinsko){
        gorniBezdeistviq[intervali[koqSmenqme].vremeBezdGore]--;
        if(gorniBezdeistviq[intervali[koqSmenqme].vremeBezdGore] == 0){
            gorniBezdeistviq.erase(intervali[koqSmenqme].vremeBezdGore);
        }
        dolniBezdeistviq[intervali[koqSmenqme].vremeBezdDolu]--;
        if(dolniBezdeistviq[intervali[koqSmenqme].vremeBezdDolu] == 0){
            dolniBezdeistviq.erase(intervali[koqSmenqme].vremeBezdDolu);
        }

        intervali[koqSmenqme].vremeBezdGore = intervali[koqSmenqme].vremeSashtinsko - intervali[koqSmenqme].vremePreproces;
        intervali[koqSmenqme].vremeBezdDolu = 0;

        gorniBezdeistviq[intervali[koqSmenqme].vremeSashtinsko - intervali[koqSmenqme].vremePreproces]++;
    }else{
        gorniBezdeistviq[intervali[koqSmenqme].vremeBezdGore]--;
        if(gorniBezdeistviq[intervali[koqSmenqme].vremeBezdGore] == 0){
            gorniBezdeistviq.erase(intervali[koqSmenqme].vremeBezdGore);
        }
        dolniBezdeistviq[intervali[koqSmenqme].vremeBezdDolu]--;
        if(dolniBezdeistviq[intervali[koqSmenqme].vremeBezdDolu] == 0){
            dolniBezdeistviq.erase(intervali[koqSmenqme].vremeBezdDolu);
        }

        intervali[koqSmenqme].vremeBezdDolu = intervali[koqSmenqme].vremePreproces - intervali[koqSmenqme].vremeSashtinsko;
        intervali[koqSmenqme].vremeBezdGore = 0;

        dolniBezdeistviq[intervali[koqSmenqme].vremePreproces - intervali[koqSmenqme].vremeSashtinsko]++;
    }

    int originalniSekundi = max(originalen.vremePreproces, originalen.vremeSashtinsko);
    int noviSekundi = max(intervali[koqSmenqme].vremePreproces, intervali[koqSmenqme].vremeSashtinsko);

    obshtoSekundi += noviSekundi - originalniSekundi;
}

void smeniProgramite(int koqSmenqme, int sKoqSmenqme){

    updateniPrograma(koqSmenqme, sKoqSmenqme, true);
    updateniPrograma(koqSmenqme + 1, sKoqSmenqme, false);

    updateniPrograma(sKoqSmenqme, koqSmenqme, true);
    updateniPrograma(sKoqSmenqme + 1, koqSmenqme, false);

    swap(programi[koqSmenqme], programi[sKoqSmenqme]);

}

void smetniIzpalnenieto(){

    int sumarnoVreme = 0;

    for(int i = 0; i <= broiProgrami; i++){
        sumarnoVreme += max(intervali[i].vremePreproces, intervali[i].vremeSashtinsko);
    }

    obshtoSekundi = sumarnoVreme;
}

DanniZaOtgovor query(){
    return {obshtoSekundi, gorniBezdeistviq.rbegin()->first, dolniBezdeistviq.rbegin()->first};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiProgrami>>broiIzpalneniq;

    for(int i = 0; i < broiProgrami; i++){
        cin>>programi[i].vremePreproces;
    }

    for(int i = 0; i < broiProgrami; i++){
        cin>>programi[i].vremeSashtinsko;
    }

    napraviIntervalite();

    smetniIzpalnenieto();

    DanniZaOtgovor nachalno = query();

    cout<<nachalno.nujniSekundi<<" "<<nachalno.parvoBezdeistvie<<" "<<nachalno.vtoroBezdeistvie<<endl;

    for(int i = 0; i < broiIzpalneniq - 1; i++){
        int koeSmenqme;
        int sKoeSmenqme;

        cin>>koeSmenqme>>sKoeSmenqme;

        smeniProgramite(koeSmenqme - 1, sKoeSmenqme - 1);

        DanniZaOtgovor novOtgovor = query();

        cout<<novOtgovor.nujniSekundi<<" "<<novOtgovor.parvoBezdeistvie<<" "<<novOtgovor.vtoroBezdeistvie<<endl;
    }

    return 0;
}
