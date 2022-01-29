#include<iostream>
#include<vector>
using namespace std;

struct DanniZaVarha{
    long long lazyStoinost;
    int lqvoDete;
    int dqsnoDete;
    int broiElementi;
    long long sborElementi;
};

//vector<DanniZaVarha> varhove;

DanniZaVarha varhove[4750010];
int broiVarhove;

//vector<int> koreni;

int koreni[100010];
int broiKoreni;

int broielementiV(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].broiElementi;
}

long long sborElementiV(int vrah){
    if(vrah == -1){
        return 0;
    }

    return varhove[vrah].sborElementi;
}

void preizchisliTuka(int vrah){
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

int daiNovVrah(long long lazyStoinost, int lqvoDete, int dqsnoDete){
    //varhove.push_back({lazyStoinost, lqvoDete, dqsnoDete, 0, 0});
    //preizchisliTuka(varhove.size() - 1);

    varhove[broiVarhove] = {lazyStoinost, lqvoDete, dqsnoDete, 0, 0};
    preizchisliTuka(broiVarhove);
    broiVarhove++;

    return broiVarhove - 1;
}

int napraviDarvo(vector<int> &otVector, int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah(otVector[otKade], -1, -1);
    }

    int lqvotoDete = napraviDarvo(otVector, otKade, (otKade + doKade)/2);
    int dqsnotoDete = napraviDarvo(otVector, (otKade + doKade)/2 + 1, doKade);

    return daiNovVrah(0, lqvotoDete, dqsnotoDete);
}

int napraviDarvo(vector<int> &otVector){
    //koreni.push_back(napraviDarvo(otVector, 0, otVector.size() - 1));
    koreni[broiKoreni] = napraviDarvo(otVector, 0, otVector.size() - 1);
    broiKoreni++;

    return broiKoreni - 1;
}

long long querySbor(int segashenVrah, int otKade, int doKade, long long delta){
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
    long long sumaOtDqsno = querySbor(varhove[segashenVrah].dqsnoDete, max(0, otKade - broiElementiVLqvoto), doKade - broiElementiVLqvoto, delta + varhove[segashenVrah].lazyStoinost);

    return sumaOtLqvo + sumaOtDqsno;
}

long long querySborVersiq(int versiq, int otKade, int doKade){
    return querySbor(koreni[versiq], otKade, doKade, 0);
}

int update(int segashenVrah, int otKade, int doKade, long long delta){
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


int updateVersiq(int versiq, int otKade, int doKade, long long delta){
    //koreni.push_back(update(koreni[versiq], otKade, doKade, delta));
    koreni[broiKoreni] = update(koreni[versiq], otKade, doKade, delta);
    broiKoreni++;

    return broiKoreni - 1;
}

void printiraiKatoDarvo(int segashenVrah){
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int broiGradove;
    int broiMravuniaciVGrad;

    cin>>broiGradove>>broiMravuniaciVGrad;

    vector<int> mravuniaciVParviGrad;

    for(int i = 0; i < broiMravuniaciVGrad; i++){
        int tuka;
        cin>>tuka;

        mravuniaciVParviGrad.push_back(tuka);
    }

    int parviGradVersiq = napraviDarvo(mravuniaciVParviGrad);

    //mravuniaciVParviGrad = vector<int>{};

    vector<long long> otgovori;

    long long broiVHubaviqKvartalNaPredniq = 0;

    for(int k = 0; k < broiGradove - 1; k++){
        int otKoiVzemame;
        int x;
        int y;
        long long sKolkoUvelich;
        int z;
        int t;

        cin>>otKoiVzemame>>x>>y>>sKolkoUvelich>>z>>t;

        int L = (x + broiVHubaviqKvartalNaPredniq)%broiMravuniaciVGrad;
        int R = (y + broiVHubaviqKvartalNaPredniq)%broiMravuniaciVGrad;
        int i = (z + broiVHubaviqKvartalNaPredniq)%broiMravuniaciVGrad;
        int j = (t + broiVHubaviqKvartalNaPredniq)%broiMravuniaciVGrad;

        //cout<<"novite stoinosti "<<L<<" "<<R<<" "<<i<<" "<<j<<" a s e "<<broiVHubaviqKvartalNaPredniq<<endl;

        //cout<<"===== updatevame versiq "<<otKoiVzemame - 1<<" ot "<<L<<" do "<<R<<" s "<<sKolkoUvelich<<endl;
        int novaVersiq = updateVersiq(otKoiVzemame - 1, L, R, sKolkoUvelich);

        //printiraiKatoDarvo(koreni[novaVersiq]);

        /*cout << "=> ";
        for(int p = 0; p < broiMravuniaciVGrad; p++){
            cout<<querySborVersiq(novaVersiq, p, p)<<" ";
        }
        cout<<endl;*/

        /////cout<<"sboryt na novoto cqlo e "<<querySborVersiq(novaVersiq, 0, broiMravuniaciVGrad - 1)<<endl;

        long long tukaKvartal = querySborVersiq(novaVersiq, i, j);
        //cout<<"===== pitame za versiq "<<novaVersiq<<" ot "<<i<<" do "<<j<<" i poluchavame otg "<<tukaKvartal<<endl;

        otgovori.push_back(tukaKvartal);
        broiVHubaviqKvartalNaPredniq = tukaKvartal;
    }

    for(int i = 0; i < otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
