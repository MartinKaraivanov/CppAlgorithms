#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int broivarhove;

int broiPitaniq;

struct DanniZaVarha{
    int stoinost;
    int prioritet;
    int lqvoDete;
    int dqsnoDete;
    int broiVNegovotoPoddarvo;
    int naiLqvaStoinost;
    int naiDqsnaStoinost;
    int cvetnost;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, rand()%100010, -1, -1, 1, stoinost, stoinost, 1});
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


void preizchisliTuka(int vrah){
    if(vrah == -1){
        return ;
    }

    varhove[vrah].broiVNegovotoPoddarvo = kolkoImaTuka(varhove[vrah].lqvoDete) + kolkoImaTuka(varhove[vrah].dqsnoDete) + 1;

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

    int dolnotoDqsnoDete = varhove[lqvotoDete].dqsnoDete;

    varhove[vrah].lqvoDete = dolnotoDqsnoDete;
    preizchisliTuka(vrah);

    varhove[lqvotoDete].dqsnoDete = vrah;
    preizchisliTuka(lqvotoDete);

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

    varhove[vrah].dqsnoDete = dolnotoLqvo;
    preizchisliTuka(vrah);

    varhove[dqsnotoDete].lqvoDete = vrah;
    preizchisliTuka(dqsnotoDete);

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

void iztrii(int poziciq){
    korenNomer = premahniVrah(korenNomer, poziciq);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broivarhove;

    for(int i = 0; i < broivarhove; i++){
        int tuka;
        cin>>tuka;

        vmakni(i, tuka);
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

                    vmakni(poziciq, stoinost);

                }else{

                    int koiIndex;
                    cin>>koiIndex;

                    koiIndex--;

                    iztrii(koiIndex);
                }
            }
        }

        //otpechatvaneKatoDarvo(korenNomer);
        //dfsPechataneHubavo(korenNomer);
        //cout<<endl;
        //cout<<"sega otgovora e "<<varhove[korenNomer].cvetnost<<endl;
    }


    return 0;
}
