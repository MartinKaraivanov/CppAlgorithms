#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

struct DanniZaVarha{
    int stoinost;
    int prioritet;
    int lqvoDete;
    int dqsnoDete;
    int broiVNegovotoPoddarvo;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, rand()%100010, -1, -1, 1});
    return varhove.size() - 1;
}

int kolkoImaTuka(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].broiVNegovotoPoddarvo;
}

void preizchisliTuka(int vrah){
    varhove[vrah].broiVNegovotoPoddarvo = kolkoImaTuka(varhove[vrah].lqvoDete) + kolkoImaTuka(varhove[vrah].dqsnoDete) + 1;
}

int zavartiNadqsno(int vrah){
    if(vrah == -1){
        return vrah;
    }

    int lqvotoDete = varhove[vrah].lqvoDete;

    if(lqvotoDete == -1){
        return vrah;
    }

    int dolnotoDqsnoDete = varhove[lqvotoDete].dqsnoDete;

    varhove[lqvotoDete].dqsnoDete = vrah;
    preizchisliTuka(lqvotoDete);

    varhove[vrah].lqvoDete = dolnotoDqsnoDete;
    preizchisliTuka(vrah);

    return lqvotoDete;
}

int zavartiNalqvo(int vrah){
    if(vrah == -1){
        return vrah;
    }

    int dqsnotoDete = varhove[vrah].dqsnoDete;

    if(dqsnotoDete == -1){
        return vrah;
    }

    int dolnotoLqvo = varhove[dqsnotoDete].lqvoDete;

    varhove[dqsnotoDete].lqvoDete = vrah;
    preizchisliTuka(dqsnotoDete);

    varhove[vrah].dqsnoDete = dolnotoLqvo;
    preizchisliTuka(vrah);

    return dqsnotoDete;
}

int kolkoEPrioritetaTuk(int vrah){
    if(vrah == -1){
        return -1;
    }

    return varhove[vrah].prioritet;
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

int vmakniVrah(int segashenVrah, int poziciq, int stoinost){
    if(segashenVrah == -1){
        return daiNovVrah(stoinost);
    }

    int vLqvoto = kolkoImaTuka(varhove[segashenVrah].lqvoDete);

    if(poziciq <= vLqvoto){
        int tuka = vmakniVrah(varhove[segashenVrah].lqvoDete, poziciq, stoinost);
        varhove[segashenVrah].lqvoDete = tuka;

        preizchisliTuka(segashenVrah);

        if(kolkoEPrioritetaTuk(varhove[segashenVrah].lqvoDete) > kolkoEPrioritetaTuk(segashenVrah)){
            return zavartiNadqsno(segashenVrah);
        }
    }else{
        int tuka = vmakniVrah(varhove[segashenVrah].dqsnoDete, poziciq - vLqvoto - 1, stoinost);
        varhove[segashenVrah].dqsnoDete = tuka;

        preizchisliTuka(segashenVrah);

        if(kolkoEPrioritetaTuk(varhove[segashenVrah].dqsnoDete) > kolkoEPrioritetaTuk(segashenVrah)){
            return zavartiNalqvo(segashenVrah);
        }
    }

    return segashenVrah;
}

void vmakni(int kade, int stoinost){
    korenNomer = vmakniVrah(korenNomer, kade, stoinost);
}

int premahniVrah(int segashenVrah, int poziciq){
    if(segashenVrah == -1){
        return segashenVrah;
    }

    int vLqvoto = kolkoImaTuka(varhove[segashenVrah].lqvoDete);

    if(poziciq == vLqvoto){
        if(varhove[segashenVrah].lqvoDete == -1 || varhove[segashenVrah].dqsnoDete == -1){
            int dete = varhove[segashenVrah].lqvoDete;

            if(dete == -1){
                dete = varhove[segashenVrah].dqsnoDete;
            }

            return dete;
        }else{
            int zaVrasgtane = -1;
            if(kolkoEPrioritetaTuk(varhove[segashenVrah].lqvoDete) < kolkoEPrioritetaTuk(varhove[segashenVrah].dqsnoDete)){
                zaVrasgtane = zavartiNalqvo(segashenVrah);
                varhove[zaVrasgtane].lqvoDete = premahniVrah(varhove[zaVrasgtane].lqvoDete, kolkoImaTuka(varhove[segashenVrah].lqvoDete));
            }else{
                zaVrasgtane = zavartiNadqsno(segashenVrah);
                varhove[zaVrasgtane].dqsnoDete = premahniVrah(varhove[zaVrasgtane].dqsnoDete, kolkoImaTuka(varhove[segashenVrah].lqvoDete));
            }

            preizchisliTuka(zaVrasgtane);
            return zaVrasgtane;
        }
    }else{
        if(poziciq < vLqvoto){
            varhove[segashenVrah].lqvoDete = premahniVrah(varhove[segashenVrah].lqvoDete, poziciq);
        }else{
            varhove[segashenVrah].dqsnoDete = premahniVrah(varhove[segashenVrah].dqsnoDete, poziciq - vLqvoto - 1);
        }

        preizchisliTuka(segashenVrah);
        return segashenVrah;
    }
}

void iztrii(int stoinost){
    korenNomer = premahniVrah(korenNomer, stoinost);
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

void dfsPechataneHubavo(int segashenVrah){
    if(segashenVrah == -1){
        return ;
    }

    dfsPechataneHubavo(varhove[segashenVrah].lqvoDete);

    cout<<varhove[segashenVrah].stoinost<<" ";

    dfsPechataneHubavo(varhove[segashenVrah].dqsnoDete);

}

int main(){
    while(true){
        int kakvo;

        cin>>kakvo;

        if(kakvo == 0){
            break;
        }

        int kade;

        cin>>kade;

        if(kakvo == 1){
            int kolko;

            cin>>kolko;

            vmakni(kade, kolko);
        }
        if(kakvo  == 2){
            iztrii(kade);
        }
        if(kakvo == 3){
            int kolko;

            cin>>kolko;

            promeni(kade, kolko);
        }

        otpechatvaneKatoDarvo(korenNomer);
        dfsPechataneHubavo(korenNomer);
        cout<<endl;
    }

    return 0;
}
