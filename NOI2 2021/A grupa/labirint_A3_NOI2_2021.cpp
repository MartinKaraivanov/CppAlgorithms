#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int broiRedove;
int broiKoloni;

char kakvoImaTuk[1510][1510];

int broiSmeni;

//int tukaKoeNomercheE[1510][1510];
//int nomerche;
int poslednoNomerche;

vector<vector<int>> decaNaTozi;

struct DanniZaVarha{
    int dalbch;
    int korenNaDrvtoMu;
    int momentNaVlizane;
    int momentNaIzlizane;
};

vector<DanniZaVarha> dalbochini;
vector<int> roditel;

vector<int> otKoiCikulE;
int nomercheCikul;

vector<int> toziKoiVCkulaE;

vector<int> poprincipVisited;
int koeIzvikvaneSme;

vector<int> daljinaNaCikula;

int koiEZacikleniq(int start){
    koeIzvikvaneSme++;

    int zaCik = -1;
    int segashen = start;
    while(segashen != 0){
        if(poprincipVisited[segashen] == koeIzvikvaneSme){
            zaCik = segashen;
            break;
        }
        if(poprincipVisited[segashen] > 0){
            break;
        }

        poprincipVisited[segashen] = koeIzvikvaneSme;

        segashen = roditel[segashen];
    }

    return zaCik;
}

void popalvaneNaCikala(int start){
    nomercheCikul++;

    int chi = 1;
    int segashen = start;

    while(segashen != start || chi == 1){
        otKoiCikulE[segashen] = nomercheCikul;
        toziKoiVCkulaE[segashen] = chi;

        chi++;
        segashen = roditel[segashen];
    }

    daljinaNaCikula[nomercheCikul] = chi - 1;
}

void namiraneNaCiklite(){
    for(int i = 1; i <= poslednoNomerche; i++){
        if(poprincipVisited[i] == 0 && dalbochini[i].dalbch == 0 && decaNaTozi[i].size() > 0){
            int tuka = koiEZacikleniq(i);
            //cout<<"pusnhame ot "<<i<<" i ni varna "<<tuka<<endl;
            if(tuka > -1){
                popalvaneNaCikala(tuka);
            }
        }
    }
}

inline int daiNomerche(int x, int y){
    return broiKoloni*(y - 1) + x;
    /*if(tukaKoeNomercheE[x][y] > 0){
        return tukaKoeNomercheE[x][y];
    }

    nomerche++;
    tukaKoeNomercheE[x][y] = nomerche;
    return nomerche;*/
}

inline int bashta(int x, int y, char tuka){
    int koiENoviq = -1;

    if(tuka == '<'){
        if(x > 1){
            koiENoviq = daiNomerche(x - 1, y);
        }else{
            koiENoviq = 0;
        }
    }else{
        if(tuka == '>'){
            if(x < broiKoloni){
                koiENoviq = daiNomerche(x + 1, y);
            }else{
                koiENoviq = 0;
            }
        }else{
            if(tuka == 'v'){
                if(y < broiRedove){
                    koiENoviq = daiNomerche(x, y + 1);
                }else{
                    koiENoviq = 0;
                }
            }else{
                if(y > 1){
                    koiENoviq = daiNomerche(x, y - 1);
                }else{
                    koiENoviq = 0;
                }
            }
        }
    }

    return koiENoviq;
}

void praveneNaGrafa(){
    for(int y = 1; y <= broiRedove; y++){
        for(int x = 1; x <= broiKoloni; x++){
            char tuka = kakvoImaTuk[y][x];

            int tukaNomerche = daiNomerche(x, y);

            int bashtaMu = bashta(x, y, tuka);

            decaNaTozi[bashtaMu].push_back(tukaNomerche);
            roditel[tukaNomerche] = bashtaMu;
        }
    }

    roditel[0] = -1;
}

int momentche;

inline int daiMoment(){
    momentche++;
    return momentche;
}

void praveneNaDalbochinite(int segashen, int dalb, int korenche){

    dalbochini[segashen].momentNaVlizane = daiMoment();

    dalbochini[segashen].dalbch = dalb;
    dalbochini[segashen].korenNaDrvtoMu = korenche;

    for(int i = 0; i < decaNaTozi[segashen].size(); i++){
        if(toziKoiVCkulaE[decaNaTozi[segashen][i]] == 0){
            praveneNaDalbochinite(decaNaTozi[segashen][i], dalb + 1, korenche);
        }
    }

    dalbochini[segashen].momentNaIzlizane = daiMoment();
}

void namiraneNaDalbochinite(){
    for(int i = 1; i <= poslednoNomerche; i++){
        if(toziKoiVCkulaE[i] > 0){
            praveneNaDalbochinite(i, 1, i);
        }
    }
}

inline bool toziVPoddarvotLiE(int koiDaliE, int vChiePoddarvo){
    if(dalbochini[koiDaliE].momentNaVlizane >= dalbochini[vChiePoddarvo].momentNaVlizane &&
        dalbochini[koiDaliE].momentNaIzlizane <= dalbochini[vChiePoddarvo].momentNaIzlizane)
    {
        return true;
    }

    return false;
}

vector<int> otgovori;
//bool toziOtgovorPriNormalenLiE[100010];

struct DanniZaPitaneto{
    int yPochvane;
    int xPochvane;
    int ySmenen;
    int xSmenen;
    char kakvaESmqnata;
};

vector<DanniZaPitaneto> pitaniq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiRedove>>broiKoloni;

    decaNaTozi.resize(broiRedove*broiKoloni + 2);
    dalbochini.resize(broiRedove*broiKoloni + 2);
    roditel.resize(broiRedove*broiKoloni + 2);
    otKoiCikulE.resize(broiRedove*broiKoloni + 2);
    toziKoiVCkulaE.resize(broiRedove*broiKoloni + 2);
    poprincipVisited.resize(broiRedove*broiKoloni + 2);
    daljinaNaCikula.resize(broiRedove*broiKoloni + 2);

    for(int y = 1; y <= broiRedove; y++){
        //char red[1510];
        cin>>kakvoImaTuk[y]+1;
        //for(int x = 1; x <= broiKoloni; x++){
          //  kakvoImaTuk[y][x] = red[x - 1];
        //}
    }

    cin>>broiSmeni;

    otgovori.resize(broiSmeni + 2);
    pitaniq.resize(broiSmeni + 2);

    for(int i = 0; i < broiSmeni; i++){
        cin>>pitaniq[i].yPochvane>>pitaniq[i].xPochvane>>pitaniq[i].ySmenen>>pitaniq[i].xSmenen>>pitaniq[i].kakvaESmqnata;
    }

    poslednoNomerche = broiRedove*broiKoloni;

    praveneNaGrafa();

    toziKoiVCkulaE[0] = 1;
    praveneNaDalbochinite(0, 1, 0);

    if(momentche < 2*(poslednoNomerche + 1)){
        namiraneNaCiklite();
        namiraneNaDalbochinite();
    }

    /*for(int i = 0; i <= nomerche; i++){
        cout<<i<<" "<<momentNaVlizane[i]<<" "<<momentNaIzlizane[i]<<endl;
    }*/

    /*for(int i = 0; i <= poslednoNomerche; i++){
        cout<<i<<" "<<toziKoiVCkulaE[i]<<" "<<daljinaNaCikula[otKoiCikulE[dalbochini[i].korenNaDrvtoMu]]<<endl;
    }*/

    /*for(int i = 0; i <= nomerche; i++){
        cout<<i<<" "<<dalbochini[i].dalbch<<" "<<dalbochini[i].korenNaDrvtoMu<<endl;
    }*/

    /*for(int y = 1; y <= broiRedove; y++){
        for(int x = 1; x <= broiKoloni; x++){
            cout<<x<<" "<<y<<" "<<daiNomerche(x, y)<<" "<<dalbochini[daiNomerche(x, y)].dalbch<<" ";
            cout<<dalbochini[daiNomerche(x, y)].korenNaDrvtoMu<<endl;
        }
    }*/

    for(int i = 0; i < broiSmeni; i++){
        int xPoch = pitaniq[i].xPochvane;
        int yPoch = pitaniq[i].yPochvane;
        int xSmqn = pitaniq[i].xSmenen;
        int ySmqn = pitaniq[i].ySmenen;
        char smqna = pitaniq[i].kakvaESmqnata;

        int otKoiPuskame = daiNomerche(xPoch, yPoch);
        int koiSmenqme = daiNomerche(xSmqn, ySmqn);

        int noviqBashta = bashta(xSmqn, ySmqn, smqna);

        if(toziVPoddarvotLiE(otKoiPuskame, koiSmenqme))
        {
            //toziOtgovorPriNormalenLiE[i] = true;
            //cout<<"sega sme v purviq sluchai "<<endl;
            if(otKoiCikulE[dalbochini[noviqBashta].korenNaDrvtoMu] == otKoiCikulE[dalbochini[0].korenNaDrvtoMu]){

                if(toziVPoddarvotLiE(noviqBashta, koiSmenqme))
                {
                    otgovori[i] = 0;
                }else{
                    int segashnoNivo = dalbochini[koiSmenqme].dalbch - 1;
                    int novoNivo = dalbochini[noviqBashta].dalbch;
                    otgovori[i] = novoNivo + dalbochini[otKoiPuskame].dalbch - segashnoNivo - 1;
                    //toziOtgovorPriNormalenLiE[i] = true;
                }
            }else{
                otgovori[i] = 0;
            }
        }else{
            if(toziKoiVCkulaE[koiSmenqme] > 0 &&
                otKoiCikulE[dalbochini[koiSmenqme].korenNaDrvtoMu] ==
                    otKoiCikulE[dalbochini[otKoiPuskame].korenNaDrvtoMu])
            {
                //toziOtgovorPriNormalenLiE[i] = true;
                //cout<<"sega sme vav vtoriq sluchai "<<endl;
                if(otKoiCikulE[dalbochini[noviqBashta].korenNaDrvtoMu] == otKoiCikulE[dalbochini[0].korenNaDrvtoMu]){
                    int daljina = daljinaNaCikula[otKoiCikulE[dalbochini[koiSmenqme].korenNaDrvtoMu]];
                    int nomerParvi = toziKoiVCkulaE[dalbochini[otKoiPuskame].korenNaDrvtoMu];
                    int nomerVtori = toziKoiVCkulaE[koiSmenqme];

                    int razstVCIkula =
                        abs((daljina - nomerVtori) -
                            (daljina - nomerParvi));

                    if(nomerParvi < nomerVtori){
                        razstVCIkula = nomerVtori - nomerParvi;
                    }else{
                        razstVCIkula = (daljina + nomerVtori - nomerParvi)%daljina;
                    }

                    //cout<<nomerParvi<<" "<<nomerVtori<<" "<<razstVCIkula<<endl;

                    //cout<<razstVCIkula<<endl;

                    /*cout<<"ouskame ot "<<otKoiPuskame<<" smenqme "<<koiSmenqme<<endl;
                    cout<<"koren na puskameto "<<dalbochini[otKoiPuskame].korenNaDrvtoMu;
                    cout<<" i na tozi koito smenqme "<<dalbochini[koiSmenqme].korenNaDrvtoMu<<endl;
                    cout<<"nomer parvi "<<nomerParvi<<" nomer vtori "<<nomerVtori<<endl;
                    cout<<"razst v cikula: "<<razstVCIkula<<" noviq bashta "<<noviqBashta<<" "<<endl;*/

                    otgovori[i] =
                        dalbochini[otKoiPuskame].dalbch - 1 +
                        razstVCIkula +
                        1 +
                        dalbochini[noviqBashta].dalbch - 1;
                    //toziOtgovorPriNormalenLiE[i] = true;
                }else{
                    otgovori[i] = 0;
                }
            }else{
                //cout<<"sega sme vav krainiq sluchai"<<endl;
                //toziOtgovorPriNormalenLiE[i] = true;
                if(otKoiCikulE[dalbochini[otKoiPuskame].korenNaDrvtoMu] == otKoiCikulE[dalbochini[0].korenNaDrvtoMu]){
                    otgovori[i] = dalbochini[otKoiPuskame].dalbch - 1;
                }else{
                    otgovori[i] = 0;
                }
            }
        }
    }

    for(int i = 0; i < broiSmeni; i++){
        /*if(toziOtgovorPriNormalenLiE[i] == true){
            cout<<" ";
        }*/
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
