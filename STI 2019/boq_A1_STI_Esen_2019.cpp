#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long broiOstrovi;

long long broiKamioniNaOstrov[500010];

struct DanniZaSased{
    long long doOstrov;
    long long shtastie;
};

vector<DanniZaSased> sasedstvo[500010];

struct DanniZaOtgovor{
    long long otgovorBezDaVzemameTukaRebroto;
    long long otgovorKatoMojemDaVzememTukaRebroto;
};

struct DanniZaRezultat{
    DanniZaOtgovor rez;
    long long rebro;
};

bool koiEPoNapred(DanniZaRezultat a, DanniZaRezultat b){
    long long parvoto = a.rez.otgovorBezDaVzemameTukaRebroto + a.rebro - a.rez.otgovorKatoMojemDaVzememTukaRebroto;
    long long vtoroto = b.rez.otgovorBezDaVzemameTukaRebroto + b.rebro - b.rez.otgovorKatoMojemDaVzememTukaRebroto;
    return parvoto > vtoroto;
}

DanniZaOtgovor nameriOtgovora(long long segashen, long long otKadeIdvame){
    if(sasedstvo[segashen].size() == 0){
        return {0, 0};
    }

    if(sasedstvo[segashen].size() == 1 && sasedstvo[segashen][0].doOstrov == otKadeIdvame){
        if(broiKamioniNaOstrov[segashen] > 0){
            long long rebroNagore = sasedstvo[segashen][0].shtastie;
            return {0, rebroNagore};
        }else{
            return {0, 0};
        }
    }

    vector<DanniZaRezultat> rezultati;

    long long rebroNagore = 0;

    for(long long i = 0; i < (long long)sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i].doOstrov != otKadeIdvame){
            DanniZaRezultat tekushto =
                {nameriOtgovora(sasedstvo[segashen][i].doOstrov, segashen), sasedstvo[segashen][i].shtastie};

            rezultati.push_back(tekushto);
        }else{
            rebroNagore = sasedstvo[segashen][i].shtastie;
        }
    }

    sort(rezultati.begin(), rezultati.end(), koiEPoNapred);

    long long pravoNaKolko = broiKamioniNaOstrov[segashen];

    DanniZaOtgovor otgovor = {0, 0};

    int posledenBoqdisan = -1;

    for(long long i = 0; i < (long long)rezultati.size(); i++){
        if(pravoNaKolko > 0){
            otgovor.otgovorBezDaVzemameTukaRebroto += rezultati[i].rez.otgovorBezDaVzemameTukaRebroto + rezultati[i].rebro;
            posledenBoqdisan = i;
            pravoNaKolko--;
        }else{
            otgovor.otgovorBezDaVzemameTukaRebroto += rezultati[i].rez.otgovorKatoMojemDaVzememTukaRebroto;
        }
    }

    otgovor.otgovorKatoMojemDaVzememTukaRebroto = otgovor.otgovorBezDaVzemameTukaRebroto;

    if(pravoNaKolko > 0){
        otgovor.otgovorKatoMojemDaVzememTukaRebroto = otgovor.otgovorBezDaVzemameTukaRebroto + rebroNagore;
    }else{
        if(posledenBoqdisan > -1){
            otgovor.otgovorKatoMojemDaVzememTukaRebroto =
                max(otgovor.otgovorBezDaVzemameTukaRebroto,
                    otgovor.otgovorBezDaVzemameTukaRebroto -
                        (   rezultati[posledenBoqdisan].rez.otgovorBezDaVzemameTukaRebroto +
                            rezultati[posledenBoqdisan].rebro
                        ) +
                        rezultati[posledenBoqdisan].rez.otgovorKatoMojemDaVzememTukaRebroto +
                        rebroNagore
                );
        }
    }

    return otgovor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOstrovi;

    for(long long i = 0; i < broiOstrovi; i++){
        cin>>broiKamioniNaOstrov[i];
    }

    for(long long i = 0; i < broiOstrovi - 1; i++){
        long long otKade;
        long long doKade;
        long long kolkoShtastie;

        cin>>otKade>>doKade>>kolkoShtastie;

        sasedstvo[otKade].push_back({doKade, kolkoShtastie});
        sasedstvo[doKade].push_back({otKade, kolkoShtastie});
    }

    DanniZaOtgovor broiShtastie = nameriOtgovora(0, -1);

    cout<<max(broiShtastie.otgovorBezDaVzemameTukaRebroto, broiShtastie.otgovorKatoMojemDaVzememTukaRebroto)<<endl;

    return 0;
}
