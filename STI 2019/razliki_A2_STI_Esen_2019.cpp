#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int mnogo = 1000000007;

struct DanniZaVarha{
    int stoinost;
    int lqvoDete;
    int dqsnoDete;
    int visochina;
    int broiVNegovotoPoddarvo;
    int naiMalkataRazlikaVPodd;
    int naiMalkiqtVPoddarvoto;
    int naiGolemiqtVPoddarvoto;
    int sumaVPoddarvoto;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, -1, -1, 1, 1, mnogo, stoinost, stoinost});
    return varhove.size() - 1;
}

int kakvaEVisochinataTuk(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].visochina;
}

int kolkoSaTuka(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].broiVNegovotoPoddarvo;
}

int naiMRazlikaTuka(int vrah){
    if(vrah == -1){
        return mnogo;
    }

    return varhove[vrah].naiMalkataRazlikaVPodd;
}

int naiLqvTuka(int vrah){
    if(vrah == -1){
        return -1;
    }

    return varhove[vrah].naiMalkiqtVPoddarvoto;
}

int naiDesenTuka(int vrah){
    if(vrah == -1){
        return -1;
    }

    return varhove[vrah].naiGolemiqtVPoddarvoto;
}

int kolkoESumataTuka(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].sumaVPoddarvoto;
}

void preizchisliTuka(int vrah){
    if(vrah == -1){
        return ;
    }

    varhove[vrah].visochina = max(kakvaEVisochinataTuk(varhove[vrah].lqvoDete), kakvaEVisochinataTuk(varhove[vrah].dqsnoDete)) + 1;

    varhove[vrah].broiVNegovotoPoddarvo = kolkoSaTuka(varhove[vrah].lqvoDete) + kolkoSaTuka(varhove[vrah].dqsnoDete) + 1;

    int naiDesenLqv = naiDesenTuka(varhove[vrah].lqvoDete);
    int naiLqvDesen = naiLqvTuka(varhove[vrah].dqsnoDete);

    int sPredniq = mnogo;
    if(naiDesenLqv >= 0){
        sPredniq = varhove[vrah].stoinost - naiDesenLqv;
    }

    int susSledvashtiq = mnogo;
    if(naiLqvDesen >= 0){
        susSledvashtiq = naiLqvDesen - varhove[vrah].stoinost;
    }

    varhove[vrah].naiMalkataRazlikaVPodd =
        min(min(naiMRazlikaTuka(varhove[vrah].lqvoDete), naiMRazlikaTuka(varhove[vrah].dqsnoDete)),
            min(sPredniq, susSledvashtiq));

    int naiLqvLqv = naiLqvTuka(varhove[vrah].lqvoDete);
    int naiDesenDesen = naiDesenTuka(varhove[vrah].dqsnoDete);

    if(naiLqvLqv > 0){
        varhove[vrah].naiMalkiqtVPoddarvoto = naiLqvLqv;
    }else{
        varhove[vrah].naiMalkiqtVPoddarvoto = varhove[vrah].stoinost;
    }

    if(naiDesenDesen > 0){
        varhove[vrah].naiGolemiqtVPoddarvoto = naiDesenDesen;
    }else{
        varhove[vrah].naiGolemiqtVPoddarvoto = varhove[vrah].stoinost;
    }

    varhove[vrah].sumaVPoddarvoto = kolkoESumataTuka(varhove[vrah].lqvoDete) + kolkoESumataTuka(varhove[vrah].dqsnoDete) + varhove[vrah].stoinost;
}

int zavartiNadqsno(int vrah){
    if(vrah == -1){
        return vrah;
    }

    int lqvotoDete = varhove[vrah].lqvoDete;

    if(lqvotoDete == -1){
        return vrah;
    }

    int dqsnotoDolnoDete = varhove[lqvotoDete].dqsnoDete;

    varhove[vrah].lqvoDete = dqsnotoDolnoDete;
    preizchisliTuka(vrah);

    varhove[lqvotoDete].dqsnoDete = vrah;
    preizchisliTuka(lqvotoDete);

    return lqvotoDete;
}

int zavartiNalqvo(int vrah){
    if(vrah == -1){
        return vrah;
    }

    int dqsnoDete = varhove[vrah].dqsnoDete;

    if(dqsnoDete == -1){
        return vrah;
    }

    int lqvoDolnoDete = varhove[dqsnoDete].lqvoDete;

    varhove[vrah].dqsnoDete = lqvoDolnoDete;
    preizchisliTuka(vrah);

    varhove[dqsnoDete].lqvoDete = vrah;
    preizchisliTuka(dqsnoDete);

    return dqsnoDete;
}

int kolkoEBalansa(int vrah){
    if(vrah == -1){
        return 0;
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

int vmakvane(int segashenVrah, int stoinost){
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

void vmakni(int kakvo){
    korenNomer = vmakvane(korenNomer, kakvo);
}

int naiMalkataSt(int vPoddarvotoNa){
    int segashen = vPoddarvotoNa;

    while(varhove[segashen].lqvoDete != -1){
        segashen = varhove[segashen].lqvoDete;
    }

    return varhove[segashen].stoinost;
}

struct DanniZaPremahvaneto{
    int novVrah;
    int premahnatVrah;
};

DanniZaPremahvaneto premahniVrah(int segashenVrah, int stoinost){
    if(segashenVrah == -1){
        return {-1, -1};
    }

    if(stoinost == varhove[segashenVrah].stoinost){
        int zaVrashtaneVrah = -1;

        if((varhove[segashenVrah].lqvoDete == -1) || (varhove[segashenVrah].dqsnoDete == -1)){
            zaVrashtaneVrah = varhove[segashenVrah].lqvoDete;
            if(zaVrashtaneVrah == -1){
                zaVrashtaneVrah = varhove[segashenVrah].dqsnoDete;
            }
        }else{
            int naiMalkaStoinost = naiMalkataSt(varhove[segashenVrah].dqsnoDete);

            DanniZaPremahvaneto tuka = premahniVrah(varhove[segashenVrah].dqsnoDete, naiMalkaStoinost);

            varhove[segashenVrah].dqsnoDete = tuka.novVrah;
            zaVrashtaneVrah = tuka.premahnatVrah;

            varhove[zaVrashtaneVrah].lqvoDete = varhove[segashenVrah].lqvoDete;
            varhove[zaVrashtaneVrah].dqsnoDete = varhove[segashenVrah].dqsnoDete;

            preizchisliTuka(zaVrashtaneVrah);
        }

        varhove[segashenVrah].lqvoDete = -1;
        varhove[segashenVrah].dqsnoDete = -1;

        preizchisliTuka(segashenVrah);

        return {balansirai(zaVrashtaneVrah), segashenVrah};
    }else{
        int premahnatVrah = -1;

        if(stoinost < varhove[segashenVrah].stoinost){
            DanniZaPremahvaneto tuka = premahniVrah(varhove[segashenVrah].lqvoDete, stoinost);
            varhove[segashenVrah].lqvoDete = tuka.novVrah;
            premahnatVrah = tuka.premahnatVrah;
        }else{
            DanniZaPremahvaneto tuka = premahniVrah(varhove[segashenVrah].dqsnoDete, stoinost);
            varhove[segashenVrah].dqsnoDete = tuka.novVrah;
            premahnatVrah = tuka.premahnatVrah;
        }

        preizchisliTuka(segashenVrah);

        return {balansirai(segashenVrah), premahnatVrah};
    }
}

void iztrii(int stoinost){
    korenNomer = premahniVrah(korenNomer, stoinost).novVrah;
}

int kakvoImaNaPoziciq(int segashenVrah, int poziciq){
    int vLqvoto = kolkoSaTuka(varhove[segashenVrah].lqvoDete);

    //cout<<"sega sme na "<<varhove[segashenVrah].stoinost<<" vLqvoto ima "<<vLqvoto<<" i otivame na poziciq "<<poziciq<<endl;

    if(vLqvoto == poziciq){
        int zaVrasht = varhove[segashenVrah].stoinost;
        return zaVrasht;
    }

    if(vLqvoto > poziciq){
        int zaVrasht = kakvoImaNaPoziciq(varhove[segashenVrah].lqvoDete, poziciq);
        return zaVrasht;
    }

    int zaVrasht = kakvoImaNaPoziciq(varhove[segashenVrah].dqsnoDete, poziciq - vLqvoto - 1);
    return zaVrasht;
}

int tamKakvoIma(int kade){
    return kakvoImaNaPoziciq(korenNomer, kade);
}

int sumataVIntervala(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1){
        return 0;
    }

    int vLqvoto = kolkoSaTuka(varhove[segashenVrah].lqvoDete);

    int tukaZaVrasht = 0;

    if(vLqvoto <= doKade && vLqvoto >= otKade){
        tukaZaVrasht += varhove[segashenVrah].stoinost;
    }

    if(otKade < vLqvoto){
        tukaZaVrasht += sumataVIntervala(varhove[segashenVrah].lqvoDete, otKade, vLqvoto - 1);
    }

    if(doKade > vLqvoto){
        tukaZaVrasht += sumataVIntervala(varhove[segashenVrah].dqsnoDete, max(0, otKade - vLqvoto - 1), doKade - vLqvoto - 1);
    }

    preizchisliTuka(segashenVrah);

    return tukaZaVrasht;
}

int naiMalkatarazlikaVIntervala(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1){
        return 0;
    }

    int vLqvoto = kolkoSaTuka(varhove[segashenVrah].lqvoDete);
    int vDqsnoto = kolkoSaTuka(varhove[segashenVrah].dqsnoDete);

    if(vLqvoto + vDqsnoto + 1 == doKade - otKade + 1){
        //cout<<"sega sme v krainiq sluchai i sh vrashtame "<<varhove[segashenVrah].naiMalkataRazlikaVPodd<<endl;
        return varhove[segashenVrah].naiMalkataRazlikaVPodd;
    }

    //cout<<"sega sme na "<<varhove[segashenVrah].stoinost<<" iskame ot "<<otKade<<" do "<<doKade<<endl;

    int tukaZaVrasht = mnogo;

    if(otKade < vLqvoto){
        int tukaRezultat = naiMalkatarazlikaVIntervala(varhove[segashenVrah].lqvoDete, otKade, min(vLqvoto - 1, doKade));
        int sprqmoNashiq = mnogo;
        if(vLqvoto <= doKade && vLqvoto >= otKade){
            sprqmoNashiq = varhove[segashenVrah].stoinost - varhove[varhove[segashenVrah].lqvoDete].naiGolemiqtVPoddarvoto;
        }
        int tekushtoPoDobro = min(tukaRezultat, sprqmoNashiq);
        //cout<<"v lqvoto poddarvo se poluchava "<<tekushtoPoDobro<<endl;
        tukaZaVrasht = min(tukaZaVrasht, tekushtoPoDobro);
    }

    if(doKade > vLqvoto){
        int tukaRezultat = naiMalkatarazlikaVIntervala(varhove[segashenVrah].dqsnoDete, max(0, otKade - vLqvoto - 1), doKade - vLqvoto - 1);
        int sprqmoNashiq = mnogo;
        if(vLqvoto <= doKade && vLqvoto >= otKade){
            sprqmoNashiq = varhove[varhove[segashenVrah].dqsnoDete].naiMalkiqtVPoddarvoto - varhove[segashenVrah].stoinost;
        }
        int tekushtotoPoDobro = min(tukaRezultat, sprqmoNashiq);
        //cout<<"v dqsnoto poddarvo se poluchava "<<tekushtotoPoDobro<<endl;
        tukaZaVrasht = min(tukaZaVrasht, tekushtotoPoDobro);
    }

    preizchisliTuka(segashenVrah);

    return tukaZaVrasht;
}

void otpechatvaneKatoDarvo(int vrah){
    if(vrah == -1){
        return ;
    }

    cout<<varhove[vrah].stoinost<<"("<<varhove[vrah].broiVNegovotoPoddarvo<<") s nai malka razlikavpodd "<<varhove[vrah].naiMalkataRazlikaVPodd<<" nai malak v podd ";
    cout<<varhove[vrah].naiMalkiqtVPoddarvoto<<" i nai golqm v podd "<<varhove[vrah].naiGolemiqtVPoddarvoto<<" : ";
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

int broiZaqvki;

vector<int> otgovori;

int main(){
    cin>>broiZaqvki;

    for(int i = 0; i < broiZaqvki; i++){
        char tip;
        cin>>tip;

        if(tip == 'I'){
            int koeCHislo;
            cin>>koeCHislo;

            vmakni(koeCHislo);
        }else{
            if(tip == 'D'){
                int koeChislo;
                cin>>koeChislo;

                iztrii(koeChislo);
            }else{
                if(tip == 'X'){
                    int otKade;
                    int doKade;

                    cin>>otKade>>doKade;

                    int kakvoENaOtKade = tamKakvoIma(otKade);
                    int kakvoENaDokade = tamKakvoIma(doKade);

                    //cout<<kakvoENaDokade-kakvoENaOtKade<<endl;
                    otgovori.push_back(kakvoENaDokade-kakvoENaOtKade);
                }else{
                    int otKade;
                    int doKade;

                    cin>>otKade>>doKade;

                    //cout<<naiMalkatarazlikaVIntervala(korenNomer, otKade, doKade)<<endl;
                    otgovori.push_back(naiMalkatarazlikaVIntervala(korenNomer, otKade, doKade));
                }
                //cout<<"------------------------------------------------------------"<<endl;
            }
        }

        //otpechatvaneKatoDarvo(korenNomer);
        //cout<<endl;
    }

    for(int i = 0; i < (int)otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

}
