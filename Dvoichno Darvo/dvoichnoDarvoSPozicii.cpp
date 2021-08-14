#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVarha{
    int stoinost;
    int lqvoDete;
    int dqsnoDete;
    int broiVNegovotoPoddarvo;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, -1, -1, 1});
    return varhove.size() - 1;
}

int kolkoImaTuka(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].broiVNegovotoPoddarvo;
}

void preizchisliTuka(int vrah){
    if(vrah == -1){
        return ;
    }

    varhove[vrah].broiVNegovotoPoddarvo = kolkoImaTuka(varhove[vrah].lqvoDete) + kolkoImaTuka(varhove[vrah].dqsnoDete) + 1;
}

int kakvoImaNaPoziciq(int poziciq){
    int segashenNomer = korenNomer;

    bool imaLiGo = false;
    int kakvoE = -1;

    while(segashenNomer == -1){
        if(kolkoImaTuka(varhove[segashenNomer].lqvoDete) == poziciq){
           kakvoE = varhove[segashenNomer].stoinost;
           imaLiGo = true;
           break;
        }

        if(poziciq < varhove[varhove[segashenNomer].lqvoDete].broiVNegovotoPoddarvo){
            segashenNomer = varhove[segashenNomer].lqvoDete;
        }else{
            segashenNomer = varhove[segashenNomer].dqsnoDete;
            preizchisliTuka(segashenNomer);
            poziciq -= varhove[varhove[segashenNomer].lqvoDete].broiVNegovotoPoddarvo + 1;
        }
    }

    if(imaLiGo == false){
        return 0;
    }

    return kakvoE;
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

    return segashenVrah;
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

        return {zaVrasgtaneVrah, segashenVrah};

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

        return {segashenVrah, premahnat};
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

int main(){
    int broiVarhove;
    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove; i++){
        int koqPoziciq;
        int tuka;
        cin>>koqPoziciq>>tuka;

        dobavi(koqPoziciq, tuka);

        otpechatvaneKatoDarvo(korenNomer);
        dfsPechataneHubavo(korenNomer);
        cout<<endl;

        cout<<"dobavih "<<tuka<<endl<<endl;
    }

    cout<<"ok"<<endl;

    otpechatvaneKatoDarvo(korenNomer);

    while(true){
        int chislo;

        cin>>chislo;

        int kade;

        cin>>kade;

        if(chislo == 0){
            break;
        }

        if(chislo == 1){
            int kakvo;
            cin>>kakvo;
            dobavi(kade, kakvo);
        }
        if(chislo == 2){
            mahni(kade);
        }
        if(chislo == 3){
            int novaSt;
            cin>>novaSt;
            promeniNaPoziciq(korenNomer, kade, novaSt);
        }

        otpechatvaneKatoDarvo(korenNomer);
        dfsPechataneHubavo(korenNomer);
        cout<<endl;
    }

    return 0;
}
