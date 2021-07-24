#include<iostream>
#include<vector>
using namespace std;


/*
struct BinarySearchTree{
    private vector<DanniZaVrah> elementi;
    private int nomerNaKorena = -1;
    void dobavi(int stoinost);
    void premahni(int stoinost);
    bool imaLiElementa(int stoinost);
    void otpechatai();
    void otpechataiKatodarvo();
};
*/


struct DanniZaVrah{
    int stoinost;
    int lqvoDeteNomer;
    int dqsnoDeteNomer;
};

vector<DanniZaVrah> elementi;
int nomerNaKorena = -1;

int dobaviNovoVectora(int stoinost){
    int nomerche = elementi.size();
    DanniZaVrah nov = {stoinost, -1, -1};
    elementi.push_back(nov);
    return nomerche;
}

int dobaviVrah(int poddarvoNomer, int stoinost){
    if(poddarvoNomer == -1){
        return dobaviNovoVectora(stoinost);
    }

    if(stoinost <= elementi[poddarvoNomer].stoinost){
        elementi[poddarvoNomer].lqvoDeteNomer = dobaviVrah(elementi[poddarvoNomer].lqvoDeteNomer, stoinost);
    }else{
        elementi[poddarvoNomer].dqsnoDeteNomer = dobaviVrah(elementi[poddarvoNomer].dqsnoDeteNomer, stoinost);
    }

    return poddarvoNomer;
}

void dobaviane(int stoinost){
    nomerNaKorena = dobaviVrah(nomerNaKorena, stoinost);
}

/*void hubavoDobavqne(int stoinost){
    if(nomerNaKorena == -1){
        nomerNaKorena = dobaviNovoVectora(stoinost);
        return ;
    }

    int segashenNomer = nomerNaKorena;

    while(true){
        if(stoinost <= elementi[segashenNomer].stoinost && elementi[segashenNomer].lqvoDeteNomer == -1){
            int novoNomerche = dobaviNovoVectora(stoinost);
            elementi[segashenNomer].lqvoDeteNomer = novoNomerche;
            break;
        }
        if(stoinost > elementi[segashenNomer].stoinost && elementi[segashenNomer].dqsnoDeteNomer == -1){
            int novoNomerche = dobaviNovoVectora(stoinost);
            elementi[segashenNomer].dqsnoDeteNomer = novoNomerche;
            break;
        }

        if(stoinost < elementi[segashenNomer].stoinost){
            segashenNomer = elementi[segashenNomer].lqvoDeteNomer;
        }else{
            segashenNomer = elementi[segashenNomer].dqsnoDeteNomer;
        }
    }

}*/

bool imaLiElementa(int nomerSegashen, int stoinost){
    if(elementi[nomerSegashen].stoinost == stoinost){
        return true;
    }
    if(stoinost < elementi[nomerSegashen].stoinost && elementi[nomerSegashen].lqvoDeteNomer == -1){
        return false;
    }
    if(stoinost > elementi[nomerSegashen].stoinost && elementi[nomerSegashen].dqsnoDeteNomer == -1){
        return false;
    }

    bool imaLi = false;

    if(stoinost < elementi[nomerSegashen].stoinost){
        imaLi = imaLiElementa(elementi[nomerSegashen].lqvoDeteNomer, stoinost);
    }else{
        imaLi = imaLiElementa(elementi[nomerSegashen].dqsnoDeteNomer, stoinost);
    }

    return imaLi;
}

bool kazhiDaliGoIma(int stoinost){
    return imaLiElementa(nomerNaKorena, stoinost);
}

/*int hubavoNmeraNaElementa(int stoinost){
    int segashenNomer = nomerNaKorena;

    while(segashenNomer != -1){
        if(stoinost == elementi[segashenNomer].stoinost){
            break;
        }

        if(stoinost < elementi[segashenNomer].stoinost){
            segashenNomer = elementi[segashenNomer].lqvoDeteNomer;
        }else{
            segashenNomer = elementi[segashenNomer].dqsnoDeteNomer;
        }
    }

    return segashenNomer;
}*/

/*bool hubavoImaLiElementa(int stoinost){
    int nomer = hubavoNmeraNaElementa(stoinost);
    return (nomer != -1);
}*/

void otpechtvane(int vrah){
    if(elementi[vrah].lqvoDeteNomer != -1){
        otpechtvane(elementi[vrah].lqvoDeteNomer);
    }
    cout<<elementi[vrah].stoinost<<" ";
    if(elementi[vrah].dqsnoDeteNomer != -1){
        otpechtvane(elementi[vrah].dqsnoDeteNomer);
    }
}

void otpechatvaneNapravo(){
    otpechtvane(nomerNaKorena);
}

void otpechatvaneKatoDarvo(int vrah){
    cout<<elementi[vrah].stoinost<<": ";
    if(elementi[vrah].lqvoDeteNomer > -1){
        cout<<"lqvo: "<<elementi[elementi[vrah].lqvoDeteNomer].stoinost<<" ";
    }
    if(elementi[vrah].dqsnoDeteNomer > -1){
        cout<<"dqsno: "<<elementi[elementi[vrah].dqsnoDeteNomer].stoinost<<" ";
    }
    cout<<endl;
    if(elementi[vrah].lqvoDeteNomer > -1){
        otpechatvaneKatoDarvo(elementi[vrah].lqvoDeteNomer);
    }
    if(elementi[vrah].dqsnoDeteNomer > -1){
        otpechatvaneKatoDarvo(elementi[vrah].dqsnoDeteNomer);
    }
}

void darvesnoOtpechatvane(){
    otpechatvaneKatoDarvo(nomerNaKorena);
}

int naiMalkiq(int segashenVrah, int predishenVrah){
    int naiMVrah = segashenVrah;
    bool parviqLiE = true;

    int segashen = segashenVrah;
    int otKadeIdvame = predishenVrah;

    while(elementi[segashen].lqvoDeteNomer > -1){
        parviqLiE = false;
        naiMVrah = elementi[segashen].lqvoDeteNomer;
        otKadeIdvame = segashen;
        segashen = elementi[segashen].lqvoDeteNomer;
    }

    elementi[naiMVrah].lqvoDeteNomer = elementi[predishenVrah].lqvoDeteNomer;

    if(parviqLiE == true){

    }else{
        elementi[otKadeIdvame].lqvoDeteNomer = elementi[naiMVrah].dqsnoDeteNomer;
        elementi[naiMVrah].dqsnoDeteNomer = elementi[predishenVrah].dqsnoDeteNomer;
    }

    return naiMVrah;
}

void premahvane(int segashenVrah, int stoinostTarsena, int otKadeIdvme){
    /*if(kazhiDaliGoIma(stoinostTarsena) == false){
        return ;
    }*/

    if(stoinostTarsena < elementi[segashenVrah].stoinost && elementi[segashenVrah].lqvoDeteNomer == -1){
        return ;
    }
    if(stoinostTarsena > elementi[segashenVrah].stoinost && elementi[segashenVrah].dqsnoDeteNomer == -1){
        return ;
    }
    if(stoinostTarsena == elementi[segashenVrah].stoinost){
        if(elementi[segashenVrah].lqvoDeteNomer == -1 && elementi[segashenVrah].dqsnoDeteNomer == -1){
            if(stoinostTarsena < elementi[otKadeIdvme].stoinost){
                elementi[otKadeIdvme].lqvoDeteNomer = -1;
                return ;
            }else{
                if(stoinostTarsena > elementi[otKadeIdvme].stoinost){
                    elementi[otKadeIdvme].dqsnoDeteNomer = -1;
                    return ;
                }
            }
        }

        if(elementi[segashenVrah].lqvoDeteNomer > -1 && elementi[segashenVrah].dqsnoDeteNomer == -1){
            if(stoinostTarsena < elementi[otKadeIdvme].stoinost){
                elementi[otKadeIdvme].lqvoDeteNomer = elementi[segashenVrah].lqvoDeteNomer;
            }else{
                if(stoinostTarsena > elementi[otKadeIdvme].stoinost){
                    elementi[otKadeIdvme].dqsnoDeteNomer = elementi[segashenVrah].lqvoDeteNomer;
                }
            }
            return ;
        }

        if(elementi[segashenVrah].lqvoDeteNomer == -1 && elementi[segashenVrah].dqsnoDeteNomer > -1){
            if(stoinostTarsena < elementi[otKadeIdvme].stoinost){
                elementi[otKadeIdvme].lqvoDeteNomer = elementi[segashenVrah].dqsnoDeteNomer;
            }else{
                if(stoinostTarsena > elementi[otKadeIdvme].stoinost){
                    elementi[otKadeIdvme].dqsnoDeteNomer = elementi[segashenVrah].dqsnoDeteNomer;
                }
            }
            return ;
        }

        int zamestitel = naiMalkiq(elementi[segashenVrah].dqsnoDeteNomer, segashenVrah);

        if(segashenVrah == nomerNaKorena){
            nomerNaKorena = zamestitel;
        }else{
            if(segashenVrah == elementi[otKadeIdvme].lqvoDeteNomer){
                elementi[otKadeIdvme].lqvoDeteNomer = zamestitel;
            }else{
                if(segashenVrah == elementi[otKadeIdvme].dqsnoDeteNomer){
                    elementi[otKadeIdvme].dqsnoDeteNomer = zamestitel;
                }
            }
        }

        return ;
    }

    if(stoinostTarsena < elementi[segashenVrah].stoinost){
        premahvane(elementi[segashenVrah].lqvoDeteNomer, stoinostTarsena, segashenVrah);
    }
    if(stoinostTarsena > elementi[segashenVrah].stoinost){
        premahvane(elementi[segashenVrah].dqsnoDeteNomer, stoinostTarsena, segashenVrah);
    }

}

void mahane(int stoinost){
    premahvane(nomerNaKorena, stoinost, -1);
}

/*void hubavoPremavane(int stoinost){
    bool imaLiGo = hubavoImaLiElementa(stoinost);
    if(imaLiGo == false){
        return ;
    }

    int segashenNomer = nomerNaKorena;
    int predishen = -1;

    while(true){
        if(stoinost == elementi[segashenNomer].stoinost){
            break;
        }
        if(stoinost < elementi[segashenNomer].stoinost){
            predishen = segashenNomer;
            segashenNomer = elementi[segashenNomer].lqvoDeteNomer;
        }else{
            predishen = segashenNomer;
            segashenNomer = elementi[segashenNomer].dqsnoDeteNomer;
        }
    }

    /// Ako nqma deca:
    if(elementi[segashenNomer].lqvoDeteNomer == -1 && elementi[segashenNomer].dqsnoDeteNomer == -1){
        if(predishen != -1){
            if(segashenNomer == elementi[predishen].lqvoDeteNomer){
                elementi[predishen].lqvoDeteNomer = -1;
            }else{
                elementi[predishen].dqsnoDeteNomer = -1;
            }
        }else{
            nomerNaKorena = -1;
        }
        return ;
    }

    /// Ako ima samo lqvo dete:
    if(elementi[segashenNomer].lqvoDeteNomer > -1 && elementi[segashenNomer].dqsnoDeteNomer == -1){
        if(predishen != -1){
            if(segashenNomer == elementi[predishen].lqvoDeteNomer){
                elementi[predishen].lqvoDeteNomer = elementi[segashenNomer].lqvoDeteNomer;
            }else{
                elementi[predishen].dqsnoDeteNomer = elementi[segashenNomer].lqvoDeteNomer;
            }
        }else{
            nomerNaKorena = elementi[segashenNomer].lqvoDeteNomer;
        }
        return ;
    }

    /// Ako ima samo dqsno dete:
    if(elementi[segashenNomer].dqsnoDeteNomer > -1 && elementi[segashenNomer].lqvoDeteNomer == -1){
        if(predishen != -1){
            if(segashenNomer == elementi[predishen].lqvoDeteNomer){
                elementi[predishen].lqvoDeteNomer = elementi[segashenNomer].dqsnoDeteNomer;
            }else{
                elementi[predishen].dqsnoDeteNomer = elementi[segashenNomer].dqsnoDeteNomer;
            }
        }else{
            nomerNaKorena = elementi[segashenNomer].dqsnoDeteNomer;
        }
        return ;
    }

    /// Ako ima dve deca:

    int nomerNaNuzhnoto = elementi[segashenNomer].dqsnoDeteNomer;
    int prediNego = segashenNomer;
    bool praviliLiSmeZavoi = false;

    while(elementi[nomerNaNuzhnoto].lqvoDeteNomer > -1){
        prediNego = nomerNaNuzhnoto;
        nomerNaNuzhnoto = elementi[nomerNaNuzhnoto].lqvoDeteNomer;
        praviliLiSmeZavoi = true;
    }

    //cout<<nomerNaNuzhnoto<<" e nomera na nuzhnoto a "<<segashenNomer<<" she mahame "<<endl;

    elementi[nomerNaNuzhnoto].lqvoDeteNomer = elementi[segashenNomer].lqvoDeteNomer;

    if(praviliLiSmeZavoi == false){

    }else{
        elementi[prediNego].lqvoDeteNomer = elementi[nomerNaNuzhnoto].dqsnoDeteNomer;
        elementi[nomerNaNuzhnoto].dqsnoDeteNomer = elementi[segashenNomer].dqsnoDeteNomer;
    }

    if(segashenNomer == nomerNaKorena){
        nomerNaKorena = nomerNaNuzhnoto;
    }else{
        if(segashenNomer == elementi[predishen].lqvoDeteNomer){
            elementi[predishen].lqvoDeteNomer = nomerNaNuzhnoto;
        }else{
            elementi[predishen].dqsnoDeteNomer = nomerNaNuzhnoto;
        }
    }

    return ;
}*/

int main(){
    int broiElementi;
    cin>>broiElementi;

    for(int i = 0; i < broiElementi; i++){
        int element;
        cin>>element;
        dobaviane(element);
    }

    otpechatvaneNapravo();

    cout<<endl;

    cout<<kazhiDaliGoIma(6)<<endl;

    darvesnoOtpechatvane();

    cout<<"sled premahvaneto: "<<endl;

    mahane(5);

    darvesnoOtpechatvane();

    return 0;
}
