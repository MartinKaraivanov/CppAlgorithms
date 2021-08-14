#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVarha{
    int stoinost;
    int lqvoDete;
    int dqsnoDete;
    int visochina;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, -1, -1, 1});
    return varhove.size() - 1;
}

int kakvaEVisochinataTuk(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].visochina;
}

void preizchisliTuka(int vrah){
    if(vrah == -1){
        return ;
    }

    varhove[vrah].visochina = max(kakvaEVisochinataTuk(varhove[vrah].lqvoDete), kakvaEVisochinataTuk(varhove[vrah].dqsnoDete)) + 1;
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

int main(){
    while(true){
        int kakvo;
        cin>>kakvo;

        if(kakvo == 0){
            break;
        }

        int kolko;
        cin>>kolko;

        if(kakvo == 1){
            vmakni(kolko);
        }

        if(kakvo == 2){
            iztrii(kolko);
        }

        otpechatvaneKatoDarvo(korenNomer);
    }

    return 0;
}
