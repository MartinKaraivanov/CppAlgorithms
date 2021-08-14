#include<iostream>
#include<vector>
using namespace std;

int broivarhove;

int broiPitaniq;

struct DanniZaVarha{
    int stoinost;
    int lqvoDete;
    int dqsnoDete;
    int broiVNegovotoPoddarvo;
    int cvetnost;
    int naiLqvaStoinost;
    int naiDqsnaStoinost;
    int visochina;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, -1, -1, 1, 1, stoinost, stoinost, 1});
    return varhove.size() - 1;
}

int kolkoImaTuka(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].broiVNegovotoPoddarvo;
}

int kakvaCvetnostImaTuka(int vrah){
    if(vrah == -1){
        return 0;
    }
    return varhove[vrah].cvetnost;
}

int naiLqvataStoinostTuk(int vrah){
    if(vrah == -1){
        return -1;
    }

    return varhove[vrah].naiLqvaStoinost;
}

int naiDqsnataStoinostTuk(int vrah){
    if(vrah == -1){
        return -1;
    }

    return varhove[vrah].naiDqsnaStoinost;
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

    varhove[vrah].broiVNegovotoPoddarvo = kolkoImaTuka(varhove[vrah].lqvoDete) + kolkoImaTuka(varhove[vrah].dqsnoDete) + 1;

    varhove[vrah].visochina = max(kakvaEVisochinataTuk(varhove[vrah].lqvoDete), kakvaEVisochinataTuk(varhove[vrah].dqsnoDete)) + 1;

    varhove[vrah].cvetnost = kakvaCvetnostImaTuka(varhove[vrah].lqvoDete) + kakvaCvetnostImaTuka(varhove[vrah].dqsnoDete);

    int naiLqvataDqsnaStoinost = naiLqvataStoinostTuk(varhove[vrah].dqsnoDete);
    int naiDqsnataLqvaStoinost = naiDqsnataStoinostTuk(varhove[vrah].lqvoDete);

    if(naiLqvataDqsnaStoinost == naiDqsnataLqvaStoinost && naiLqvataDqsnaStoinost == varhove[vrah].stoinost){
        varhove[vrah].cvetnost--;
    }

    if(varhove[vrah].stoinost != naiLqvataDqsnaStoinost && varhove[vrah].stoinost != naiDqsnataLqvaStoinost){
        varhove[vrah].cvetnost++;
    }

    int naiLqvLqv = naiLqvataStoinostTuk(varhove[vrah].lqvoDete);
    if(naiLqvLqv > 0){
        varhove[vrah].naiLqvaStoinost = naiLqvLqv;
    }else{
        varhove[vrah].naiLqvaStoinost = varhove[vrah].stoinost;
    }

    int naiDesenDesen = naiDqsnataStoinostTuk(varhove[vrah].dqsnoDete);
    if(naiDesenDesen > 0){
        varhove[vrah].naiDqsnaStoinost = naiDesenDesen;
    }else{
        varhove[vrah].naiDqsnaStoinost = varhove[vrah].stoinost;
    }
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


int promeniNaPoziciq(int segashenNomer, int poziciq, int novaStoinost){
    if(segashenNomer == -1){
        return -1;
    }

    int vLqvoto = kolkoImaTuka(varhove[segashenNomer].lqvoDete);

    if(poziciq == vLqvoto){
       varhove[segashenNomer].stoinost = novaStoinost;
    }else{
        if(poziciq < vLqvoto){
            int tuka = promeniNaPoziciq(varhove[segashenNomer].lqvoDete, poziciq, novaStoinost);
            varhove[segashenNomer].lqvoDete = tuka;
        }else{
            int tuka = promeniNaPoziciq(varhove[segashenNomer].dqsnoDete, poziciq - vLqvoto - 1, novaStoinost);
            varhove[segashenNomer].dqsnoDete = tuka;
        }
    }

    preizchisliTuka(segashenNomer);

    return segashenNomer;
}

void promeni(int kade, int novo){
    korenNomer = promeniNaPoziciq(korenNomer, kade, novo);
}


int dobaviVrah(int segashenVrah, int poziciq, int stoinost){
    if(segashenVrah == -1){
        return daiNovVrah(stoinost);
    }

    int vLqvoto = kolkoImaTuka(varhove[segashenVrah].lqvoDete);

    if(poziciq <= vLqvoto){
        int tuka = dobaviVrah(varhove[segashenVrah].lqvoDete, poziciq, stoinost);
        varhove[segashenVrah].lqvoDete = tuka;
    }else{
        int tuka = dobaviVrah(varhove[segashenVrah].dqsnoDete, poziciq - vLqvoto - 1, stoinost);
        varhove[segashenVrah].dqsnoDete = tuka;
    }

    preizchisliTuka(segashenVrah);

    return balansirai(segashenVrah);
}

void dobavi(int kade, int stoinost){
    korenNomer = dobaviVrah(korenNomer, kade, stoinost);
}


struct DanniZaPremahvaneto{
    int novVrah;
    int premahnatVrah;
};

DanniZaPremahvaneto premahniVrah(int segashenVrah, int poziciq){
    if(segashenVrah == -1){
        return {-1, -1};
    }

    int vLqvotoDete = kolkoImaTuka(varhove[segashenVrah].lqvoDete);

    if(poziciq == vLqvotoDete){
        int zaVrasgtaneVrah;

        if((varhove[segashenVrah].lqvoDete == -1) || (varhove[segashenVrah].dqsnoDete == -1)){
            zaVrasgtaneVrah = varhove[segashenVrah].lqvoDete;
            if(zaVrasgtaneVrah == -1){
                zaVrasgtaneVrah = varhove[segashenVrah].dqsnoDete;
            }
        }else{
            DanniZaPremahvaneto tuka = premahniVrah(varhove[segashenVrah].dqsnoDete, 0);
            varhove[segashenVrah].dqsnoDete = tuka.novVrah;

            zaVrasgtaneVrah = tuka.premahnatVrah;

            varhove[zaVrasgtaneVrah].lqvoDete = varhove[segashenVrah].lqvoDete;
            varhove[zaVrasgtaneVrah].dqsnoDete = varhove[segashenVrah].dqsnoDete;

            preizchisliTuka(zaVrasgtaneVrah);
        }

        varhove[segashenVrah].lqvoDete = -1;
        varhove[segashenVrah].dqsnoDete = -1;

        preizchisliTuka(segashenVrah);

        return {balansirai(zaVrasgtaneVrah), segashenVrah};

    }else{
        int premahnat = -1;

        if(poziciq < vLqvotoDete){
            DanniZaPremahvaneto tuka = premahniVrah(varhove[segashenVrah].lqvoDete, poziciq);
            varhove[segashenVrah].lqvoDete = tuka.novVrah;
            premahnat = tuka.premahnatVrah;
        }else{
            DanniZaPremahvaneto tuka = premahniVrah(varhove[segashenVrah].dqsnoDete, poziciq - vLqvotoDete - 1);
            varhove[segashenVrah].dqsnoDete = tuka.novVrah;
            premahnat = tuka.premahnatVrah;
        }

        preizchisliTuka(segashenVrah);

        return {balansirai(segashenVrah), premahnat};
    }
}

void mahni(int kade){
    korenNomer = premahniVrah(korenNomer, kade).novVrah;
}

int kolkoVarhaIma(){
    if(korenNomer == -1){
        return 0;
    }
    return varhove[korenNomer].broiVNegovotoPoddarvo;
}

void otpechatvaneKatoDarvo(int vrah){
    if(vrah == -1){
        return ;
    }

    cout<<varhove[vrah].stoinost<<" v poddarvoto mu ima "<<varhove[vrah].broiVNegovotoPoddarvo<<": ";
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

void dfsPechataneHubavo(int segashenVrah){
    if(segashenVrah == -1){
        return ;
    }

    dfsPechataneHubavo(varhove[segashenVrah].lqvoDete);

    cout<<varhove[segashenVrah].stoinost<<" ";

    dfsPechataneHubavo(varhove[segashenVrah].dqsnoDete);

}

struct DanniZaVrashtaneto{
    int cvetnost;
    int posledenElement;
};

DanniZaVrashtaneto nameriCvetnost(int segashenVrah, int posledenCvqt){
    if(segashenVrah == -1){
        return {0, 0};
    }

    DanniZaVrashtaneto naLqvo = nameriCvetnost(varhove[segashenVrah].lqvoDete, posledenCvqt);

    DanniZaVrashtaneto nasheVrashtane;

    nasheVrashtane.cvetnost = naLqvo.cvetnost;

    if(naLqvo.posledenElement == 0){
        if(varhove[segashenVrah].stoinost != posledenCvqt){
            nasheVrashtane.cvetnost++;
        }
    }else{
        if(varhove[segashenVrah].stoinost != naLqvo.posledenElement){
            nasheVrashtane.cvetnost++;
        }
    }

    DanniZaVrashtaneto naDqsno = nameriCvetnost(varhove[segashenVrah].dqsnoDete, varhove[segashenVrah].stoinost);

    nasheVrashtane.cvetnost += naDqsno.cvetnost;

    nasheVrashtane.posledenElement = varhove[segashenVrah].stoinost;

    return nasheVrashtane;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broivarhove;

    for(int i = 0; i < broivarhove; i++){
        int tuka;
        cin>>tuka;

        dobavi(i, tuka);
    }

    //dfsPechataneHubavo(korenNomer);
    //cout<<endl;

    int predenBalon = 0;

    cin>>broiPitaniq;

    for(int i = 0; i < broiPitaniq; i++){
        int tip;
        cin>>tip;

        if(tip == 4){
            //DanniZaVrashtaneto pitane = nameriCvetnost(korenNomer, 0);
            //cout<<pitane.cvetnost<<endl;
            cout<<varhove[korenNomer].cvetnost<<endl;
        }else{
            if(tip == 3){
                int poziciq;
                int novCvqt;

                cin>>poziciq>>novCvqt;

                poziciq--;

                promeni(poziciq, novCvqt);

            }else{
                if(tip == 2){
                    int poziciq;
                    int stoinost;

                    cin>>poziciq>>stoinost;

                    poziciq--;

                    dobavi(poziciq, stoinost);

                }else{

                    int koiIndex;
                    cin>>koiIndex;

                    koiIndex--;

                    mahni(koiIndex);
                }
            }
        }

        //otpechatvaneKatoDarvo(korenNomer);
        //dfsPechataneHubavo(korenNomer);
        //cout<<endl;
    }


    return 0;
}
