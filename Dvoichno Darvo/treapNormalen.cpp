#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

struct DanniZaVarha{
    int stoinost;
    int prioritet;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVarha> varhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, rand()%100010, -1, -1});
    return varhove.size() - 1;
}

void preizchisliTuka(int vrah){

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

int nameriVrah(int segashenVrah, int stoinost){
    if(segashenVrah == -1 || varhove[segashenVrah].stoinost == stoinost){
        return segashenVrah;
    }

    if(varhove[segashenVrah].stoinost < stoinost){
        return nameriVrah(varhove[segashenVrah].lqvoDete, stoinost);
    }else{
        return nameriVrah(varhove[segashenVrah].dqsnoDete, stoinost);
    }
}

int vmakniVrah(int segashenVrah, int stoinost){
    if(segashenVrah == -1){
        return daiNovVrah(stoinost);
    }

    if(stoinost <= varhove[segashenVrah].stoinost){
        int tuka = vmakniVrah(varhove[segashenVrah].lqvoDete, stoinost);
        varhove[segashenVrah].lqvoDete = tuka;
        preizchisliTuka(segashenVrah);

        if(kolkoEPrioritetaTuk(varhove[segashenVrah].lqvoDete) > kolkoEPrioritetaTuk(segashenVrah)){
            return zavartiNadqsno(segashenVrah);
        }
    }else{
        int tuka = vmakniVrah(varhove[segashenVrah].dqsnoDete, stoinost);
        varhove[segashenVrah].dqsnoDete = tuka;
        preizchisliTuka(segashenVrah);

        if(kolkoEPrioritetaTuk(varhove[segashenVrah].dqsnoDete) > kolkoEPrioritetaTuk(segashenVrah)){
            return zavartiNalqvo(segashenVrah);
        }
    }

    return segashenVrah;
}

void vmakni(int stoinost){
    korenNomer = vmakniVrah(korenNomer, stoinost);
}

int premahniVrah(int segashenVrah, int stoinost){
    if(segashenVrah == -1){
        return segashenVrah;
    }

    if(stoinost == varhove[segashenVrah].stoinost){
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
                varhove[zaVrasgtane].lqvoDete = premahniVrah(varhove[zaVrasgtane].lqvoDete, stoinost);
            }else{
                zaVrasgtane = zavartiNadqsno(segashenVrah);
                varhove[zaVrasgtane].dqsnoDete = premahniVrah(varhove[zaVrasgtane].dqsnoDete, stoinost);
            }

            preizchisliTuka(zaVrasgtane);

            return zaVrasgtane;
        }
    }else{
        if(stoinost < varhove[segashenVrah].stoinost){
            varhove[segashenVrah].lqvoDete = premahniVrah(varhove[segashenVrah].lqvoDete, stoinost);
        }else{
            varhove[segashenVrah].dqsnoDete = premahniVrah(varhove[segashenVrah].dqsnoDete, stoinost);
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
        if(kakvo  == 2){
            iztrii(kolko);
        }

        otpechatvaneKatoDarvo(korenNomer);
    }

    return 0;
}
