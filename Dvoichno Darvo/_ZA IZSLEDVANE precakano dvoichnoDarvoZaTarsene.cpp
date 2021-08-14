#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVarha{
    int stoinost;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVarha> varhove;
int broiVarhove;

int korenNomer = -1;

int daiNovVrah(int stoinost){
    varhove.push_back({stoinost, -1, -1});
    return varhove.size() - 1;
}

bool imaLiTaziStoinost(int stoinost){
    int segashenNomer = korenNomer;

    bool imaLiGo = false;

    while(segashenNomer != -1){
        if(varhove[segashenNomer].stoinost == stoinost){
            imaLiGo = true;
            break;
        }

        if(stoinost <= varhove[segashenNomer].stoinost){
            segashenNomer = varhove[segashenNomer].lqvoDete;
        }else{
            segashenNomer = varhove[segashenNomer].dqsnoDete;
        }
    }

    return imaLiGo;
}


int dobaviVrah(int segashenVrah, int stoinost){
    if(segashenVrah == -1){
        int noviqVrah = daiNovVrah(stoinost);
        cout<<"vrashtam vrah nomer "<<noviqVrah<<" sas stoinost "<<varhove[noviqVrah].stoinost<<endl;
        return noviqVrah;
    }

    if(stoinost <= varhove[segashenVrah].stoinost){
        int tukaRezultat = dobaviVrah(varhove[segashenVrah].lqvoDete, stoinost);
        //cout<<"tuka rezultatat e "<<tukaRezultat<<endl;
        varhove[segashenVrah].lqvoDete = tukaRezultat;


        // sko prednite 2 reda go napravim taka kakto po-dolu, se precakva qko s primer
        // 5
        // 3 1 2 5 7
        ////varhove[segashenVrah].lqvoDete = dobaviVrah(varhove[segashenVrah].lqvoDete, stoinost);


        cout<<"veche e slojeno lqvoto dete na "<<varhove[segashenVrah].stoinost<<" e "<<varhove[varhove[segashenVrah].lqvoDete].stoinost<<endl;
    }else{
        int tukaRezultat = dobaviVrah(varhove[segashenVrah].dqsnoDete, stoinost);
        //cout<<"tuka rezultatat e "<<tukaRezultat<<endl;
        varhove[segashenVrah].dqsnoDete = tukaRezultat;

        // sko prednite 2 reda go napravim taka kakto po-dolu, se precakva qko s primer
        // 5
        // 3 1 2 5 7
        ////varhove[segashenVrah].dqsnoDete = dobaviVrah(varhove[segashenVrah].dqsnoDete, stoinost);

        cout<<"veche e slojeno dqsnoto dete na "<<varhove[segashenVrah].stoinost<<" e "<<varhove[varhove[segashenVrah].dqsnoDete].stoinost<<endl;
    }

    return segashenVrah;
}

void dobavi(int stoinost){
    korenNomer = dobaviVrah(korenNomer, stoinost);
}

int nameriNaiMalkiq(int vPoddarvotoNa){
    /*if(varhove[vPoddarvotoNa].lqvoDete == -1){
        return varhove[vPoddarvotoNa].stoinost;
    }

    return nameriNaiMalkiq(varhove[vPoddarvotoNa].lqvoDete);*/

    int poslednaStoinost = 0;

    while(vPoddarvotoNa != -1){
        poslednaStoinost = varhove[vPoddarvotoNa].stoinost;

        vPoddarvotoNa = varhove[vPoddarvotoNa].lqvoDete;
    }

    return poslednaStoinost;
}


int premahniVrah(int segashenVrah, int stoinost){
    if(segashenVrah == -1){
        return -1;
    }

    if(stoinost < varhove[segashenVrah].stoinost){
        varhove[segashenVrah].lqvoDete = premahniVrah(varhove[segashenVrah].lqvoDete, stoinost);
    }else{
        if(stoinost > varhove[segashenVrah].stoinost){
            varhove[segashenVrah].dqsnoDete = premahniVrah(varhove[segashenVrah].dqsnoDete, stoinost);
        }else{
            if((varhove[segashenVrah].lqvoDete == -1) || (varhove[segashenVrah].dqsnoDete == -1)){
                int dete = varhove[segashenVrah].lqvoDete;

                if(dete == -1){
                    dete = varhove[segashenVrah].dqsnoDete;
                }

                return dete;
            }else{
                varhove[segashenVrah].stoinost = nameriNaiMalkiq(varhove[segashenVrah].dqsnoDete);
                varhove[segashenVrah].dqsnoDete = premahniVrah(varhove[segashenVrah].dqsnoDete, varhove[segashenVrah].stoinost);
            }
        }
    }

    return segashenVrah;
}

void mahni(int stoinost){
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
    int broiVarhove;
    cin>>broiVarhove;

    for(int i = 0; i < broiVarhove; i++){
        int tuka;
        cin>>tuka;

        dobavi(tuka);

        otpechatvaneKatoDarvo(korenNomer);

        cout<<"dobavih "<<tuka<<endl<<endl;
    }

    cout<<"ok"<<endl;

    otpechatvaneKatoDarvo(korenNomer);

    while(true){
        int chislo;

        cin>>chislo;

        int kakvo;

        cin>>kakvo;

        if(chislo == 0){
            break;
        }

        if(chislo == 1){
            dobavi(kakvo);
        }
        if(chislo == 2){
            mahni(kakvo);
        }

        otpechatvaneKatoDarvo(korenNomer);
    }

    return 0;
}
