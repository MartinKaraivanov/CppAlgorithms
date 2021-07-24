#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int broiVarhove;

int sinNachalo;
int chervenNachalo;

int broiZaNashiq;

vector<int> sasedstvo[500050];

bool toziOtCikulaLiE[500050];

bool visited[500050];

bool parviqImaLiSreshtaSDrugiq = false;
bool parviqImaLiSreshtaSCikula = false;

bool vtoriqImaLiSreshtaSDrugiq = false;
bool vtoriqImaLiSreshtaSCikula = false;

bool otDulgataStranaLiE[500050];
bool otKasataStranaLiE[500050];

int broiTochkiZaTozi[500050];

int sinDalgaStrana[500050];
int sinKasaStrana[500050];

int chervenDalgaStrana[500050];
int chervenKasaStrana[500050];

int dfsZaNamiraneNaCikli(int segashen, int otKoiIdvame){
    visited[segashen] = true;

    int koitoSheVrushtame = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        int tukashen = -1;
        if(visited[sasedstvo[segashen][i]] == false){
            tukashen = dfsZaNamiraneNaCikli(sasedstvo[segashen][i], segashen);
        }else{
            if(sasedstvo[segashen][i] != otKoiIdvame){
                tukashen = sasedstvo[segashen][i];
            }
        }
        if(tukashen != -1){
            koitoSheVrushtame = tukashen;
            break;
        }
    }

    if(koitoSheVrushtame != -1){
        toziOtCikulaLiE[segashen] = true;
    }

    if(segashen == koitoSheVrushtame){
        koitoSheVrushtame = -1;
    }

    return koitoSheVrushtame;
}

int kakvoSreshtamePurvo(int segashen){
    if(segashen == sinNachalo || segashen == chervenNachalo){
        return 1;
    }
    if(toziOtCikulaLiE[segashen] == true){
        return 2;
    }

    int zaVrasht = 0;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(visited[sasedstvo[segashen][i]] == false){
            visited[sasedstvo[segashen][i]] = true;
            int kakuvTipE = kakvoSreshtamePurvo(sasedstvo[segashen][i]);
            if(kakuvTipE > 0){
                zaVrasht = kakuvTipE;
                break;
            }
        }
    }
     return zaVrasht;
}

void nulirane(){
    for(int i = 0; i <= broiVarhove; i++){
        visited[i] = false;
    }
}

int naKogoPrinadlezhi[500050];

int dfsZaSreshta(int segashen, int otKadeIdvame, int koiTarsime, int dalb){

    if(segashen == koiTarsime){
        naKogoPrinadlezhi[segashen] = 2;
        return dalb/2 - 1;
    }

    if(naKogoPrinadlezhi[segashen] != 0){
        return -1;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int zaTuk = dfsZaSreshta(sasedstvo[segashen][i], segashen, koiTarsime, dalb + 1);
            if(zaTuk > -1){
                zaVrasht = zaTuk;
                break;
            }
        }
    }

    if(zaVrasht > 0){
        naKogoPrinadlezhi[segashen] = 2;
        zaVrasht--;
    }

    return zaVrasht;
}

void dfsZaOcvetqvane(int segashen){
    if(naKogoPrinadlezhi[segashen] > 0 || segashen == chervenNachalo){
        return ;
    }

    naKogoPrinadlezhi[segashen] = 1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        dfsZaOcvetqvane(sasedstvo[segashen][i]);
    }
}

int vKoqTochkaSeSreshtaSCikula(int segashen, int otKadeSmeDoshli){
    if(toziOtCikulaLiE[segashen] == true){
        return segashen;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeSmeDoshli){
            int tukashen = vKoqTochkaSeSreshtaSCikula(sasedstvo[segashen][i], segashen);
            if(tukashen > -1){
                zaVrasht = tukashen;
                break;
            }
        }
    }

    return zaVrasht;
}

int razstOtNqkudeDoNqkude(int segashen, int otKudeIdvame, int doKude, int pat){
    if(segashen == doKude){
        return pat;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKudeIdvame){
            int zaTuka = razstOtNqkudeDoNqkude(sasedstvo[segashen][i], segashen, doKude, pat+1);
            if(zaTuka > -1){
                zaVrasht = zaTuka;
                break;
            }
        }
    }

    return zaVrasht;
}

int dfsBezDalgataStrana(int segashen, int otKadeIdvame, int koiTursime, int dalb){
    if(segashen == koiTursime){
        return dalb/2 - 1;
    }

    if(otDulgataStranaLiE[segashen] == true){
        return -1;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int zaTuk = dfsBezDalgataStrana(sasedstvo[segashen][i], segashen, koiTursime, dalb + 1);
            if(zaTuk > -1){
                zaVrasht = zaTuk;
                break;
            }
        }
    }

    if(zaVrasht > 0){
        naKogoPrinadlezhi[segashen] = 2;
        zaVrasht--;
    }

    if(zaVrasht == 0){
        zaVrasht--;
    }

    return zaVrasht;
}

int namiraneNaDalgataStrana(int segashen, int otKadeIdvame, int koiTarsime){
    if(segashen == koiTarsime){
        return 1;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int zaTuk = namiraneNaDalgataStrana(sasedstvo[segashen][i], segashen, koiTarsime);
            if(zaTuk > -1){
                zaVrasht = zaTuk;
                break;
            }
        }
    }

    if(zaVrasht > -1){
        otDulgataStranaLiE[segashen] = true;
    }

    return zaVrasht;
}

int namiraneNaKasataStrana(int segashen, int otKadeIdvame, int koiTarsime){
    if(segashen == koiTarsime){
        return 1;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int zaTuk = namiraneNaKasataStrana(sasedstvo[segashen][i], segashen, koiTarsime);
            if(zaTuk > -1){
                zaVrasht = zaTuk;
                break;
            }
        }
    }

    if(zaVrasht > -1){
        otKasataStranaLiE[segashen] = true;
    }

    return zaVrasht;
}

int namiraneNaTochkiZaTozi(int segashen, int otKadeIdvame){
    int broiZaTozi = 1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            broiZaTozi += namiraneNaTochkiZaTozi(sasedstvo[segashen][i], segashen);
        }
    }

    return broiZaTozi;
}

void praveneNaNamiranetoNaTochki(){
    for(int i = 0; i <= broiVarhove; i++){
        if(toziOtCikulaLiE[i] == true){
            for(unsigned int j = 0; j < sasedstvo[i].size(); j++){
                if(toziOtCikulaLiE[sasedstvo[i][j]] == false){
                    broiTochkiZaTozi[i] += namiraneNaTochkiZaTozi(sasedstvo[i][j], i);
                }
            }
            broiTochkiZaTozi[i]++;
        }
    }
}

int koiESredniqOtDalgataStrana(int segasgen, int otKadeIdvame, int dalzhinaNaCqloto, int segashnaDalb){
    if(segashnaDalb*2 > dalzhinaNaCqloto){
        return segasgen;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segasgen].size(); i++){
        if(sasedstvo[segasgen][i] != otKadeIdvame && otDulgataStranaLiE[sasedstvo[segasgen][i]] == true){
            int tukashen = koiESredniqOtDalgataStrana(sasedstvo[segasgen][i], segasgen, dalzhinaNaCqloto, segashnaDalb + 1);

            if(tukashen != -1){
                zaVrasht = tukashen;
                break;
            }
        }
    }

    return zaVrasht;
}

int koiESredniqOtKasataStrana(int segasgen, int otKadeIdvame, int dalzhinaNaCqloto, int segashnaDalb){
    if(segashnaDalb*2 > dalzhinaNaCqloto){
        return segasgen;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segasgen].size(); i++){
        if(sasedstvo[segasgen][i] != otKadeIdvame && otKasataStranaLiE[sasedstvo[segasgen][i]] == true){
            int tukashen = koiESredniqOtKasataStrana(sasedstvo[segasgen][i], segasgen, dalzhinaNaCqloto, segashnaDalb + 1);

            if(tukashen != -1){
                zaVrasht = tukashen;
                break;
            }
        }
    }

    return zaVrasht;
}

int dfsZaCherveniqDalgaStrana(int segashen, int otKadeIdvame, int koiTarsim){
    if(segashen == koiTarsim){
        return 0;
    }

    int zaVrasht = broiTochkiZaTozi[segashen];

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame && otDulgataStranaLiE[sasedstvo[segashen][i]] == true){
            zaVrasht += dfsZaCherveniqDalgaStrana(sasedstvo[segashen][i], segashen, koiTarsim);
        }
    }

    chervenDalgaStrana[segashen] = zaVrasht;

    return zaVrasht;
}

int dfsZaCherveniqKasaStrana(int segashen, int otKadeIdvame, int koiTarsim){
    if(segashen == koiTarsim){
        return 0;
    }

    int zaVrasht = broiTochkiZaTozi[segashen];

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame && otKasataStranaLiE[sasedstvo[segashen][i]] == true){
            zaVrasht += dfsZaCherveniqKasaStrana(sasedstvo[segashen][i], segashen, koiTarsim);
        }
    }

    chervenKasaStrana[segashen] = zaVrasht;

    return zaVrasht;
}

int koiEEdiKoiSiOtDalgata(int segashen, int otKadeIdvame, int koiTarsim, int koiPodredTursim,int pat){
    if(pat == koiPodredTursim){
        return segashen;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame && otDulgataStranaLiE[sasedstvo[segashen][i]] == true){
            int tukashen = koiEEdiKoiSiOtDalgata(sasedstvo[segashen][i], segashen, koiTarsim, koiPodredTursim, pat+1);
            if(tukashen != -1){
                zaVrasht = tukashen;
                break;
            }
        }
    }

    return zaVrasht;
}

int koiEEdiKoiSiOtKasata(int segashen, int otKadeIdvame, int koiTarsim, int koiPodredTursim,int pat){
    if(pat == koiPodredTursim){
        return segashen;
    }

    int zaVrasht = -1;

    for(unsigned int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame && otKasataStranaLiE[sasedstvo[segashen][i]] == true){
            int tukashen = koiEEdiKoiSiOtKasata(sasedstvo[segashen][i], segashen, koiTarsim, koiPodredTursim, pat+1);
            if(tukashen != -1){
                zaVrasht = tukashen;
                break;
            }
        }
    }

    return zaVrasht;
}

void izchislqvaneNaSituaciqta(){
    for(unsigned int i = 0; i < sasedstvo[sinNachalo].size(); i++){
        nulirane();
        visited[sinNachalo] = true;
        int sreshta = kakvoSreshtamePurvo(sasedstvo[sinNachalo][i]);
        if(sreshta == 1){
            parviqImaLiSreshtaSDrugiq = true;
        }
        if(sreshta == 2){
            parviqImaLiSreshtaSCikula = true;
        }
    }

    for(unsigned int i = 0; i < sasedstvo[chervenNachalo].size(); i++){
        nulirane();
        visited[chervenNachalo] = true;
        int sreshta = kakvoSreshtamePurvo(sasedstvo[chervenNachalo][i]);
        if(sreshta == 1){
            vtoriqImaLiSreshtaSDrugiq = true;
        }
        if(sreshta == 2){
            vtoriqImaLiSreshtaSCikula = true;
        }
    }
}

void zaNashiqAkoCikulaNeEMezhduTqh(){
    dfsZaSreshta(sinNachalo, 0, chervenNachalo, 1);
}

void zaNashiqAkoCikulaEMezhduTqh(){
    int kudeSeSreshtaParviqSCicula = vKoqTochkaSeSreshtaSCikula(sinNachalo, 0);
    int kudeSeSreshtaVtoriqSCicula = vKoqTochkaSeSreshtaSCikula(chervenNachalo, 0);

    int otParviqDoCikula = razstOtNqkudeDoNqkude(sinNachalo, 0, kudeSeSreshtaParviqSCicula, 1);
    int otVtoriqDoCikula = razstOtNqkudeDoNqkude(chervenNachalo, 0, kudeSeSreshtaVtoriqSCicula, 1);

    int naiGolqmoOtDo = 0;
    int vtoroNaiGolqmoOtDo = 0;
    int prezKoiENaiGolqmoto = -1;
    int prezKoiEVtorotoNaiGolqmo = -1;

    for(unsigned int i = 0; i < sasedstvo[kudeSeSreshtaParviqSCicula].size(); i++){
        int zaTuk =
            razstOtNqkudeDoNqkude(sasedstvo[kudeSeSreshtaParviqSCicula][i],
                                    kudeSeSreshtaParviqSCicula,
                                    kudeSeSreshtaVtoriqSCicula,
                                    1) + 1;
        if(zaTuk > vtoroNaiGolqmoOtDo){
            vtoroNaiGolqmoOtDo = zaTuk;
            prezKoiEVtorotoNaiGolqmo = sasedstvo[kudeSeSreshtaParviqSCicula][i];
        }
        if(zaTuk > naiGolqmoOtDo){
            swap(naiGolqmoOtDo, vtoroNaiGolqmoOtDo);
            swap(prezKoiENaiGolqmoto, prezKoiEVtorotoNaiGolqmo);
        }
    }

    namiraneNaDalgataStrana(prezKoiENaiGolqmoto, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula);
    namiraneNaKasataStrana(prezKoiEVtorotoNaiGolqmo, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula);

    otDulgataStranaLiE[kudeSeSreshtaParviqSCicula] = true;
    otDulgataStranaLiE[kudeSeSreshtaVtoriqSCicula] = true;
    otKasataStranaLiE[kudeSeSreshtaParviqSCicula] = true;
    otKasataStranaLiE[kudeSeSreshtaVtoriqSCicula] = true;

    if((otParviqDoCikula + vtoroNaiGolqmoOtDo - 1 < otVtoriqDoCikula) ||
        (otVtoriqDoCikula + vtoroNaiGolqmoOtDo - 1< otParviqDoCikula))
    {
        dfsBezDalgataStrana(sinNachalo, 0, chervenNachalo, 1);
    }else{
        praveneNaNamiranetoNaTochki();

        broiTochkiZaTozi[kudeSeSreshtaParviqSCicula] = 0;
        broiTochkiZaTozi[kudeSeSreshtaVtoriqSCicula] = 0;

        if(otParviqDoCikula == otVtoriqDoCikula){
            if((naiGolqmoOtDo % 2 == 0 && vtoroNaiGolqmoOtDo % 2 == 0) ||
                (naiGolqmoOtDo % 2 == 1 && vtoroNaiGolqmoOtDo % 2 == 0) ||
                (naiGolqmoOtDo % 2 == 0 && vtoroNaiGolqmoOtDo % 2 == 1))
            {
                dfsZaSreshta(prezKoiENaiGolqmoto, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula, 2);
                dfsZaSreshta(prezKoiEVtorotoNaiGolqmo, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula, 2);
            }else{
                if(naiGolqmoOtDo % 2 == 1 && vtoroNaiGolqmoOtDo % 2 == 1){
                    int sredenNaDalgata =
                        koiESredniqOtDalgataStrana(prezKoiENaiGolqmoto, kudeSeSreshtaParviqSCicula, naiGolqmoOtDo, 2);
                    int sredenNaKasata =
                        koiESredniqOtKasataStrana(prezKoiEVtorotoNaiGolqmo, kudeSeSreshtaParviqSCicula, vtoroNaiGolqmoOtDo, 2);

                    if(broiTochkiZaTozi[sredenNaDalgata] > broiTochkiZaTozi[sredenNaKasata]){
                        dfsZaSreshta(prezKoiENaiGolqmoto, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula, 2);
                        dfsZaSreshta(prezKoiEVtorotoNaiGolqmo, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula, 3);
                    }else{
                        dfsZaSreshta(prezKoiEVtorotoNaiGolqmo, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula, 2);
                        dfsZaSreshta(prezKoiENaiGolqmoto, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula, 3);
                    }
                }
            }
        }else{

            int segashenVrahZaDalga = prezKoiENaiGolqmoto;
            int otKadeIDvameZaDalga = kudeSeSreshtaParviqSCicula;
            int koiTarsim = kudeSeSreshtaVtoriqSCicula;

            while(segashenVrahZaDalga != koiTarsim){
                sinDalgaStrana[segashenVrahZaDalga] =
                    broiTochkiZaTozi[segashenVrahZaDalga] + broiTochkiZaTozi[otKadeIDvameZaDalga];
                for(unsigned int i = 0; i < sasedstvo[segashenVrahZaDalga].size(); i++){
                    if(sasedstvo[segashenVrahZaDalga][i] != otKadeIDvameZaDalga &&
                       otDulgataStranaLiE[sasedstvo[segashenVrahZaDalga][i]] == true)
                    {
                        otKadeIDvameZaDalga = segashenVrahZaDalga;
                        segashenVrahZaDalga = sasedstvo[segashenVrahZaDalga][i];
                        break;
                    }
                }
            }

            int segashenVrahZaKasa = prezKoiEVtorotoNaiGolqmo;
            int otKadeIDvameZaKasa = kudeSeSreshtaParviqSCicula;
            koiTarsim = kudeSeSreshtaVtoriqSCicula;

            while(segashenVrahZaKasa != koiTarsim){
                sinKasaStrana[segashenVrahZaKasa] =
                    broiTochkiZaTozi[segashenVrahZaKasa] + broiTochkiZaTozi[otKadeIDvameZaKasa];
                for(unsigned int i = 0; i < sasedstvo[segashenVrahZaKasa].size(); i++){
                    if(sasedstvo[segashenVrahZaKasa][i] != otKadeIDvameZaKasa &&
                       otKasataStranaLiE[sasedstvo[segashenVrahZaKasa][i]] == true)
                    {
                        otKadeIDvameZaKasa = segashenVrahZaKasa;
                        segashenVrahZaKasa = sasedstvo[segashenVrahZaKasa][i];
                        break;
                    }
                }
            }

            dfsZaCherveniqDalgaStrana(prezKoiENaiGolqmoto, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula);
            dfsZaCherveniqKasaStrana(prezKoiEVtorotoNaiGolqmo, kudeSeSreshtaParviqSCicula, kudeSeSreshtaVtoriqSCicula);

            int naiDobraKombinaciq = 0;
            int kolkoOtKusata = 0;
            int kolkoOtDalgata = 0;

            int razlikata = abs(otParviqDoCikula - otVtoriqDoCikula);

            int poprincipnoKolichestvo = (naiGolqmoOtDo + vtoroNaiGolqmoOtDo - 4)/2;
            int zaNashiqBroi = poprincipnoKolichestvo + razlikata;

            int minimumaZaDalgataStranaOtPredi = naiGolqmoOtDo/2;
            int maximumaZaDalgataStrana = minimumaZaDalgataStranaOtPredi + razlikata;

            if(otVtoriqDoCikula < otParviqDoCikula){
                poprincipnoKolichestvo = (naiGolqmoOtDo + vtoroNaiGolqmoOtDo - 4)/2;
                zaNashiqBroi = poprincipnoKolichestvo + razlikata;

                minimumaZaDalgataStranaOtPredi = naiGolqmoOtDo/2;
                maximumaZaDalgataStrana = minimumaZaDalgataStranaOtPredi + razlikata;
            }else{
                poprincipnoKolichestvo = (naiGolqmoOtDo + vtoroNaiGolqmoOtDo - 4)/2;
                zaNashiqBroi = poprincipnoKolichestvo - razlikata;

                maximumaZaDalgataStrana = naiGolqmoOtDo/2;
                minimumaZaDalgataStranaOtPredi = maximumaZaDalgataStrana - razlikata;
            }

            for(int i = minimumaZaDalgataStranaOtPredi; i <= maximumaZaDalgataStrana; i++){
                int kolkoIskameOtDalgata = i;
                int kolkoIskameOtKasata = zaNashiqBroi - i;

                int koiSePadaOtDalgata =
                    koiEEdiKoiSiOtDalgata(kudeSeSreshtaVtoriqSCicula, 0, kudeSeSreshtaParviqSCicula, kolkoIskameOtDalgata, 0);
                int koiSePadaOtKasata =
                    koiEEdiKoiSiOtKasata(kudeSeSreshtaVtoriqSCicula, 0, kudeSeSreshtaParviqSCicula, kolkoIskameOtKasata, 0);

                int tukashno = chervenDalgaStrana[koiSePadaOtDalgata] + chervenKasaStrana[koiSePadaOtKasata];

                if(tukashno > naiDobraKombinaciq){
                    naiDobraKombinaciq = tukashno;
                    kolkoOtKusata = kolkoIskameOtKasata;
                    kolkoOtDalgata = kolkoIskameOtDalgata;
                }
            }

            int koiSePadaOtDalgata =
                koiEEdiKoiSiOtDalgata(kudeSeSreshtaVtoriqSCicula, 0, kudeSeSreshtaParviqSCicula, kolkoOtDalgata, 0);
            int koiSePadaOtKasata =
                koiEEdiKoiSiOtKasata(kudeSeSreshtaVtoriqSCicula, 0, kudeSeSreshtaParviqSCicula, kolkoOtKusata, 0);

            naKogoPrinadlezhi[koiSePadaOtDalgata] = 2;
            naKogoPrinadlezhi[koiSePadaOtKasata] = 2;


        }
    }

}

void ocvetqvane(){
    dfsZaOcvetqvane(sinNachalo);

    for(int i = 1; i <= broiVarhove; i++){
        if(naKogoPrinadlezhi[i] == 1){
            broiZaNashiq++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiVarhove>>sinNachalo>>chervenNachalo;

    for(int i = 0; i < broiVarhove; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    dfsZaNamiraneNaCikli(1, 0);

    izchislqvaneNaSituaciqta();

    if(parviqImaLiSreshtaSDrugiq){
        zaNashiqAkoCikulaNeEMezhduTqh();
    }else{
        zaNashiqAkoCikulaEMezhduTqh();
    }

    ocvetqvane();

    cout<<broiZaNashiq<<endl;

    return 0;
}
