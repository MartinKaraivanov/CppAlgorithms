#include<iostream>
#include<vector>
using namespace std;

struct Darvo{

    private: struct DanniZaVarha{
        long long lazyStoinost;
        int lqvoDete;
        int dqsnoDete;
        int broiElementi;
        long long sborElementi;
    };

    private: vector<DanniZaVarha> varhove;

    private: vector<int> koreni;


    private: int broielementiV(int vrah){
        if(vrah == -1){
            return 0;
        }

        return varhove[vrah].broiElementi;
    }

    private: long long sborElementiV(int vrah){
        if(vrah == -1){
            return 0;
        }

        return varhove[vrah].sborElementi;
    }

    private: void preizchisliTuka(int vrah){
        if(vrah == -1){
            return ;
        }

        if(varhove[vrah].lqvoDete == -1 && varhove[vrah].dqsnoDete == -1){
            varhove[vrah].broiElementi = 1;
        }else{
            varhove[vrah].broiElementi = broielementiV(varhove[vrah].lqvoDete) + broielementiV(varhove[vrah].dqsnoDete);
        }

        varhove[vrah].sborElementi =
            sborElementiV(varhove[vrah].lqvoDete) + sborElementiV(varhove[vrah].dqsnoDete) + (varhove[vrah].lazyStoinost*varhove[vrah].broiElementi);
    }

    private: int daiNovVrah(long long lazyStoinost, int lqvoDete, int dqsnoDete){
        varhove.push_back({lazyStoinost, lqvoDete, dqsnoDete, 0, 0});
        preizchisliTuka(varhove.size() - 1);

        return varhove.size() - 1;
    }

    private: int napraviDarvo(vector<int> &otVector, int otKade, int doKade){
        if(otKade == doKade){
            return daiNovVrah(otVector[otKade], -1, -1);
        }

        int lqvotoDete = napraviDarvo(otVector, otKade, (otKade + doKade)/2);
        int dqsnotoDete = napraviDarvo(otVector, (otKade + doKade)/2 + 1, doKade);

        return daiNovVrah(0, lqvotoDete, dqsnotoDete);
    }

    public: int napraviDarvo(vector<int> &otVector){
        koreni.push_back(napraviDarvo(otVector, 0, otVector.size() - 1));

        return koreni.size() - 1;
    }

    private: long long querySbor(int segashenVrah, int otKade, int doKade, long long delta){
        if(segashenVrah == -1){
            return 0;
        }
        if(otKade > doKade){
            return 0;
        }
        if(otKade < 0 || doKade < 0){
            return 0;
        }
        if(otKade >= broielementiV(segashenVrah)){
            return 0;
        }
        if(otKade == 0 && doKade >= broielementiV(segashenVrah) - 1){
            return varhove[segashenVrah].sborElementi + delta*varhove[segashenVrah].broiElementi;
        }

        int broiElementiVLqvoto = broielementiV(varhove[segashenVrah].lqvoDete);

        long long sumaOtLqvo = querySbor(varhove[segashenVrah].lqvoDete, otKade, doKade, delta + varhove[segashenVrah].lazyStoinost);
        long long sumaOtDqsno =
            querySbor(varhove[segashenVrah].dqsnoDete, max(0, otKade - broiElementiVLqvoto), doKade - broiElementiVLqvoto, delta + varhove[segashenVrah].lazyStoinost);

        return sumaOtLqvo + sumaOtDqsno;
    }

    public: long long querySborVersiq(int versiq, int otKade, int doKade){
        return querySbor(koreni[versiq], otKade, doKade, 0);
    }

    private: int update(int segashenVrah, int otKade, int doKade, long long delta){
        if(segashenVrah == -1){
            return segashenVrah;
        }
        if(otKade > doKade){
            return segashenVrah;
        }
        if(otKade < 0 || doKade < 0){
            return segashenVrah;
        }
        if(otKade >= broielementiV(segashenVrah)){
            return segashenVrah;
        }
        if(otKade == 0 && doKade >= broielementiV(segashenVrah) - 1){
            return daiNovVrah(varhove[segashenVrah].lazyStoinost + delta, varhove[segashenVrah].lqvoDete, varhove[segashenVrah].dqsnoDete);
        }

        int broiElementiVlqvo = broielementiV(varhove[segashenVrah].lqvoDete);

        int novoLqvoDete = update(varhove[segashenVrah].lqvoDete, otKade, doKade, delta);
        int novoDqsnoDete = update(varhove[segashenVrah].dqsnoDete, max(0, otKade - broiElementiVlqvo), doKade - broiElementiVlqvo, delta);

        return daiNovVrah(varhove[segashenVrah].lazyStoinost, novoLqvoDete, novoDqsnoDete);
    }


    public: int updateVersiq(int versiq, int otKade, int doKade, long long delta){
        koreni.push_back(update(koreni[versiq], otKade, doKade, delta));

        return koreni.size() - 1;
    }

    public: void printiraiKatoDarvo(int segashenVrah){
        if(segashenVrah == -1){
            return ;
        }

        cout<<segashenVrah<<" sas stoinost "<<varhove[segashenVrah].lazyStoinost<<" s deca ";
        if(varhove[segashenVrah].lqvoDete != -1){
            cout<<"lqvo "<<varhove[segashenVrah].lqvoDete<<" ";
        }
        if(varhove[segashenVrah].dqsnoDete != -1){
            cout<<"dqsno "<<varhove[segashenVrah].dqsnoDete<<" ";
        }

        cout<<endl;

        printiraiKatoDarvo(varhove[segashenVrah].lqvoDete);
        printiraiKatoDarvo(varhove[segashenVrah].dqsnoDete);
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int broiVarhove;

    cin>>broiVarhove;

    vector<int> nachalniVarhove;

    for(int i = 0; i < broiVarhove; i++){
        int tuka;
        cin>>tuka;

        nachalniVarhove.push_back(tuka);
    }

    struct Darvo parvoDarvo;

    int parviGradVersiq = parvoDarvo.napraviDarvo(nachalniVarhove);

    int vtoraVersiq = parvoDarvo.updateVersiq(parviGradVersiq, 0, 1, -1);

    cout<<parvoDarvo.querySborVersiq(vtoraVersiq, 0, 1)<<endl;

    return 0;
}
