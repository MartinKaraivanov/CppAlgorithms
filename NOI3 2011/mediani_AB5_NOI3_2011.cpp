#include<iostream>
#include<vector>
#include<iomanip>
#include<stdio.h>
using namespace std;

struct DanniZaVarha{
    long long stoinost;
    int lqvoDete;
    int dqsnoDete;
    int visochina;
    int broiVNegovotoPoddarvo;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(long long stoinost){
    varhove.push_back({stoinost, -1, -1, 1, 1});
    return varhove.size() - 1;
}

int kakvaEVisochinataTuk(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].visochina;
}

int broiVPoddarvotoNa(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].broiVNegovotoPoddarvo;
}

void preizchisliTuka(int vrah){
    if(vrah == -1){
        return ;
    }

    varhove[vrah].visochina = max(kakvaEVisochinataTuk(varhove[vrah].lqvoDete), kakvaEVisochinataTuk(varhove[vrah].dqsnoDete)) + 1;
    varhove[vrah].broiVNegovotoPoddarvo = broiVPoddarvotoNa(varhove[vrah].lqvoDete) + broiVPoddarvotoNa(varhove[vrah].dqsnoDete) + 1;
}

int zavartiNadqsno(int vrah){
    if(vrah == -1){
        return -1;
    }

    int lqvotoDete = varhove[vrah].lqvoDete;

    if(lqvotoDete == -1){
        return vrah;
    }

    int dqsnotoNaLqvoto = varhove[lqvotoDete].dqsnoDete;

    if(dqsnotoNaLqvoto == -1){
        return vrah;
    }

    varhove[vrah].lqvoDete = dqsnotoNaLqvoto;
    preizchisliTuka(vrah);

    varhove[lqvotoDete].dqsnoDete = vrah;
    preizchisliTuka(lqvotoDete);

    return lqvotoDete;
}

int zavartiNalqvo(int vrah){
    if(vrah == -1){
        return -1;
    }

    int dqsnotoDete = varhove[vrah].dqsnoDete;

    if(dqsnotoDete == -1){
        return vrah;
    }

    int lqvotoNaDqsnoto = varhove[dqsnotoDete].lqvoDete;

    if(lqvotoNaDqsnoto == -1){
        return vrah;
    }

    varhove[vrah].dqsnoDete = lqvotoNaDqsnoto;
    preizchisliTuka(vrah);

    varhove[dqsnotoDete].lqvoDete = vrah;
    preizchisliTuka(dqsnotoDete);

    return dqsnotoDete;
}

int kolkoEBalansa(int vrah){
    if(vrah == -1){
        return -1;
    }

    return kakvaEVisochinataTuk(varhove[vrah].lqvoDete) - kakvaEVisochinataTuk(varhove[vrah].dqsnoDete);
}

int balansirai(int segashenVrah){
    if(segashenVrah == -1){
        return segashenVrah;
    }

    int balans = kolkoEBalansa(segashenVrah);

    int lqvoDete = varhove[segashenVrah].lqvoDete;
    int dqsnoDete = varhove[segashenVrah].dqsnoDete;

    if(balans > 1 && lqvoDete > -1 && kolkoEBalansa(lqvoDete) >= 0){
        return zavartiNadqsno(segashenVrah);
    }

    if(balans > 1 && lqvoDete > -1 && kolkoEBalansa(lqvoDete) < 0){
        varhove[segashenVrah].lqvoDete = zavartiNalqvo(lqvoDete);
        preizchisliTuka(segashenVrah);
        return zavartiNadqsno(segashenVrah);
    }

    if(balans < -1 && dqsnoDete > -1 && kolkoEBalansa(dqsnoDete) <= 0){
        return zavartiNalqvo(segashenVrah);
    }

    if(balans < -1 && dqsnoDete > -1 && kolkoEBalansa(dqsnoDete) > 0){
        varhove[segashenVrah].dqsnoDete = zavartiNadqsno(dqsnoDete);
        preizchisliTuka(segashenVrah);
        return zavartiNalqvo(segashenVrah);
    }

    return segashenVrah;
}

int vmakvane(int segashenVrah, long long stoinost){
    if(segashenVrah == -1){
        return daiNovVrah(stoinost);
    }

    if(stoinost <= varhove[segashenVrah].stoinost){
        int tuka = vmakvane(varhove[segashenVrah].lqvoDete, stoinost);
        varhove[segashenVrah].lqvoDete = tuka;
    }else{
        int tuka = vmakvane(varhove[segashenVrah].dqsnoDete, stoinost);
        varhove[segashenVrah].dqsnoDete = tuka;
    }

    preizchisliTuka(segashenVrah);

    return balansirai(segashenVrah);
}

void vmakni(long long stoinost){
    korenNomer = vmakvane(korenNomer, stoinost);
}

void otpechatvaneKatoDarvo(int vrah){
    if(vrah == -1){
        return ;
    }

    cout<<varhove[vrah].stoinost<<": ";
    if(varhove[vrah].lqvoDete > -1){
        cout<<"lqvo: "<<varhove[varhove[vrah].lqvoDete].stoinost<<" ";
    }
    if(varhove[vrah].dqsnoDete > -1){
        cout<<"dqsno: "<<varhove[varhove[vrah].dqsnoDete].stoinost<<" ";
    }
    cout<<endl;
    if(varhove[vrah].lqvoDete > -1){
        otpechatvaneKatoDarvo(varhove[vrah].lqvoDete);
    }
    if(varhove[vrah].dqsnoDete > -1){
        otpechatvaneKatoDarvo(varhove[vrah].dqsnoDete);
    }
}

int kolkoVarhaIma(){
    if(korenNomer == -1){
        return 0;
    }

    return varhove[korenNomer].broiVNegovotoPoddarvo;
}

long long kakvoImaNaPoziciq(int koqPoziciq){

    int segashenVrah = korenNomer;
    int koqPoziciqTarsim = koqPoziciq;

    while(segashenVrah != -1){
        int vlqvoto = broiVPoddarvotoNa(varhove[segashenVrah].lqvoDete);

        //cout<<"sega sme na "<<varhove[segashenVrah].stoinost<<" i tarsime poziciq "<<koqPoziciq<<" a v lqvoto ima "<<vlqvoto<<endl;

        if(vlqvoto == koqPoziciqTarsim){
            return varhove[segashenVrah].stoinost;
        }else{
            if(vlqvoto > koqPoziciqTarsim){
                segashenVrah = varhove[segashenVrah].lqvoDete;
            }else{
                segashenVrah = varhove[segashenVrah].dqsnoDete;
                koqPoziciqTarsim = koqPoziciqTarsim - vlqvoto - 1;
            }
        }
    }

    return -1;
}

long long kakvoENaPoziciq(int koqPoziciq){
    return kakvoImaNaPoziciq(koqPoziciq);
}

int broiDeistviq;

struct DanniZaDeistvieto{
    char tip;
    long long chislo;
};

DanniZaDeistvieto deistviq[200010];

vector<long long> otgovori;

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiDeistviq;*/

    scanf("%i", &broiDeistviq);

    for(int i = 0; i < broiDeistviq; i++){
        char tip[10];
        //cin>>tip;

        scanf("%s", tip);

        //cout<<broiDeistviq<<" "<<i<<" "<<tip[0]<<endl;

        if(tip[0] == 'A'){
            float kolko;
            //cin>>kolko;

            scanf("%f", &kolko);

            //cout<<kolko<<endl;

            long long pakKolko = kolko*100000;

            //cout<<pakKolko<<endl;

            deistviq[i] = {tip[0], pakKolko};
        }else{

            deistviq[i] = {tip[0], 0};
        }
    }

    for(int i = 0; i < broiDeistviq; i++){
        char tip = deistviq[i].tip;

        if(tip == 'A'){

            long long pakKolko = deistviq[i].chislo;

            vmakni(pakKolko);
        }else{

            int segaVarhove = kolkoVarhaIma();

            if(segaVarhove%2  == 0){
                otgovori.push_back((kakvoENaPoziciq(segaVarhove/2 - 1) + kakvoENaPoziciq(segaVarhove/2))/2);
            }else{
                otgovori.push_back(kakvoENaPoziciq(segaVarhove/2));
            }
        }
    }

    for(int i = 0; i < (int)otgovori.size(); i++){
        float tuka = otgovori[i];

        tuka /= 100000;

        //cout<<fixed<<setprecision(3)<<tuka<<endl;
        printf("%.3f \n", tuka);
    }

    return 0;
}
