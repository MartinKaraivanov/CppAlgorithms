#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

struct Darvo{
    private: struct DanniZaVarha{
        int stoinost;
        int lqvoDete;
        int dqsnoDete;
        int broiVNegovotoPoddarvo;
        int visochina;
        int roditel;
    };

    private: vector<DanniZaVarha> varhove;

    private: int korenNomer = -1;

    private: unordered_map<int, int> koiVavVectoraE;

    private: int daiNovVrah(int stoinost){
        varhove.push_back({stoinost, -1, -1, 1, 1, -1});
        koiVavVectoraE[stoinost] = varhove.size() - 1;
        return varhove.size() - 1;
    }

    private: int kolkoImaTuka(int vrah){
        if(vrah == -1){
            return 0;
        }

        return varhove[vrah].broiVNegovotoPoddarvo;
    }

    private: int kakvaEVisochinataTuk(int vrah){
        if(vrah == -1){
            return 0;
        }

        return varhove[vrah].visochina;
    }

    private: void slojiRoditel(int vrah, int roditel){
        if(vrah == -1){
            return ;
        }

        varhove[vrah].roditel = roditel;
    }

    private: void preizchisliTuka(int vrah){
        if(vrah == -1){
            return ;
        }

        varhove[vrah].broiVNegovotoPoddarvo = kolkoImaTuka(varhove[vrah].lqvoDete) + kolkoImaTuka(varhove[vrah].dqsnoDete) + 1;
        varhove[vrah].visochina = max(kakvaEVisochinataTuk(varhove[vrah].lqvoDete), kakvaEVisochinataTuk(varhove[vrah].dqsnoDete)) + 1;

        slojiRoditel(vrah, -1);
        slojiRoditel(varhove[vrah].lqvoDete, vrah);
        slojiRoditel(varhove[vrah].dqsnoDete, vrah);
    }

    private: int zavartiNadqsno(int vrah){
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

    private: int zavartiNalqvo(int vrah){
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

    private: int kolkoEBalansa(int vrah){
        if(vrah == -1){
            return 0;
        }

        return kakvaEVisochinataTuk(varhove[vrah].lqvoDete) - kakvaEVisochinataTuk(varhove[vrah].dqsnoDete);
    }

    private: int balansirai(int segashenVrah){
        if(segashenVrah == -1){
            return -1;
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

    public: int kakvoImaNaPoziciq(int poziciq){
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

    private: int smqnaNa(int segashenNomer, int poziciq, int novaStoinost){
        if(segashenNomer == -1){
            return -1;
        }

        int vLqvoto = kolkoImaTuka(varhove[segashenNomer].lqvoDete);

        if(poziciq == vLqvoto){
            varhove[segashenNomer].stoinost = novaStoinost;
        }else{
            if(poziciq < vLqvoto){
                int tuka = smqnaNa(varhove[segashenNomer].lqvoDete, poziciq, novaStoinost);
                varhove[segashenNomer].lqvoDete = tuka;
            }else{
                int tuka = smqnaNa(varhove[segashenNomer].dqsnoDete, poziciq - vLqvoto - 1, novaStoinost);
                varhove[segashenNomer].dqsnoDete = tuka;
            }
        }

        preizchisliTuka(segashenNomer);

        return segashenNomer;
    }

    public: void promeniNaPoziciq(int poziciq, int novaStoinost){
        int staraStoinost = kakvoImaNaPoziciq(poziciq);
        koiVavVectoraE[novaStoinost] = koiVavVectoraE[staraStoinost];
        koiVavVectoraE[staraStoinost] = -1;
        //koiVavVectoraE.erase(staraStoinost);
        korenNomer = smqnaNa(korenNomer, poziciq, novaStoinost);
    }


    private: int dobaviVrah(int segashenVrah, int poziciq, int stoinost){
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

    public: void dobavi(int kade, int stoinost){
        korenNomer = dobaviVrah(korenNomer, kade, stoinost);
    }


    private: struct DanniZaPremahvaneto{
        int novVrah;
        int premahnatVrah;
    };

    private: DanniZaPremahvaneto premahniVrah(int segashenVrah, int poziciq){
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

    public: void mahni(int kade){
        int stoinostta = kakvoImaNaPoziciq(kade);
        //koiVavVectoraE.erase(stoinostta);
        koiVavVectoraE[stoinostta] = -1;
        korenNomer = premahniVrah(korenNomer, kade).novVrah;
    }

    private: int toziNaKoqPoziciqE(int vrah){
        int segashenvrah = varhove[vrah].roditel;
        int predishenVrah = vrah;

        int poziciq = kolkoImaTuka(varhove[vrah].lqvoDete);

        while(segashenvrah != -1){
            if(varhove[segashenvrah].lqvoDete == predishenVrah){

            }else{
                poziciq += 1 + kolkoImaTuka(varhove[segashenvrah].lqvoDete);
            }

            predishenVrah = segashenvrah;
            segashenvrah = varhove[segashenvrah].roditel;
        }

        return poziciq;
    }

    public: int naKoqPoziciqE(int koi){
        if(koiVavVectoraE.find(koi) == koiVavVectoraE.end() || koiVavVectoraE[koi] == -1){
            return -1;
        }
        return toziNaKoqPoziciqE(koiVavVectoraE[koi]);
    }

    public: int kolkoVarhaIma(){
        if(korenNomer == -1){
            return 0;
        }

        return varhove[korenNomer].broiVNegovotoPoddarvo;
    }

    private: void darvovidnoPechatane(int vrah){
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
            darvovidnoPechatane(varhove[vrah].lqvoDete);
        }
        if(varhove[vrah].dqsnoDete > -1){
            darvovidnoPechatane(varhove[vrah].dqsnoDete);
        }
    }

    public: void otpechatvaneKatoDarvo(){
        darvovidnoPechatane(korenNomer);
    }

    private: void dfsPechataneHubavo(int segashenVrah){
        if(segashenVrah == -1){
            return ;
        }

        dfsPechataneHubavo(varhove[segashenVrah].lqvoDete);

        cout<<varhove[segashenVrah].stoinost<<" ";

        dfsPechataneHubavo(varhove[segashenVrah].dqsnoDete);

    }

    public: void pechataneSDfs(){
        dfsPechataneHubavo(korenNomer);
    }

};

int main(){
    int broiVarhove;
    cin>>broiVarhove;

    struct Darvo darvoto;

    for(int i = 0; i < broiVarhove; i++){
        int koqPoziciq;
        int tuka;
        cin>>koqPoziciq>>tuka;

        darvoto.dobavi(koqPoziciq, tuka);

        darvoto.otpechatvaneKatoDarvo();
        darvoto.pechataneSDfs();
        cout<<endl;

        cout<<"dobavih "<<tuka<<endl<<endl;
    }

    cout<<"ok"<<endl;

    darvoto.otpechatvaneKatoDarvo();

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
            darvoto.dobavi(kade, kakvo);
        }
        if(chislo == 2){
            darvoto.mahni(kade);
        }
        if(chislo == 3){
            int novaSt;
            cin>>novaSt;
            darvoto.promeniNaPoziciq(kade, novaSt);
        }
        if(chislo == 4){
            cout<<darvoto.naKoqPoziciqE(kade)<<endl;
        }

        darvoto.otpechatvaneKatoDarvo();
        darvoto.pechataneSDfs();
        cout<<endl;
    }

    return 0;
}
