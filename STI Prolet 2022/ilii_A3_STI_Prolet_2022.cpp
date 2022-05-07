#include<iostream>
#include<vector>
using namespace std;

int broiChisla;
int broiPitaniq;

int chisla[100010];

int broiEdiniciV(int chislo){

    int broi = 0;

    while(chislo > 0){
        if((chislo & 1) == 1){
            broi++;
        }
        chislo >>= 1;
    }

    return broi;
}

struct DanniZaMasiva{
    int m[32];
};


struct DanniZaVarha{
    DanniZaMasiva ilitoSPoMalko;
    DanniZaMasiva itoSPoveche;
    DanniZaMasiva broiStolkova;
    DanniZaMasiva iliSTolkova;
    DanniZaMasiva iSTolkova;
    DanniZaMasiva broiSPoMalko;
    DanniZaMasiva broiSPoveche;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVarha> varhove;
int korenNomer = -1;

int daiNovVrah(DanniZaVarha novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int postroiDarvoto(int otKade, int doKade){
    if(otKade == doKade){
        int broiBitoveTuka = broiEdiniciV(chisla[otKade]);

        DanniZaMasiva ilito;
        DanniZaMasiva ito;
        DanniZaMasiva broq;
        DanniZaMasiva iliTolkova;
        DanniZaMasiva iTolkova;
        DanniZaMasiva broiPoMalko;
        DanniZaMasiva broiPoveche;
        for(int i = 0; i < 32; i++){
            if(broiBitoveTuka < i){
                ilito.m[i] = chisla[otKade];
                ito.m[i] = ~0;
                broq.m[i] = 0;
                iliTolkova.m[i] = 0;
                iTolkova.m[i] = ~0;
                broiPoMalko.m[i] = 1;
                broiPoveche.m[i] = 0;
            }else{
                if(broiBitoveTuka > i){
                    ilito.m[i] = 0;
                    ito.m[i] = chisla[otKade];
                    broq.m[i] = 0;
                    iliTolkova.m[i] = 0;
                    iTolkova.m[i] = ~0;
                    broiPoMalko.m[i] = 0;
                    broiPoveche.m[i] = 1;
                }else{
                    ilito.m[i] = 0;
                    ito.m[i] = ~0;
                    broq.m[i] = 1;
                    iliTolkova.m[i] = chisla[otKade];
                    iTolkova.m[i] = chisla[otKade];
                    broiPoMalko.m[i] = 0;
                    broiPoveche.m[i] = 0;
                }
            }
        }

        return daiNovVrah({ilito, ito, broq, iliTolkova, iTolkova, broiPoMalko, broiPoveche, otKade, doKade, -1, -1});
    }

    int lqvoDete = postroiDarvoto(otKade, (otKade + doKade)/2);
    int dqsnoDete = postroiDarvoto((otKade + doKade)/2 + 1, doKade);

    DanniZaMasiva ilito;
    DanniZaMasiva ito;
    DanniZaMasiva broq;
    DanniZaMasiva iliTolkova;
    DanniZaMasiva iTolkova;
    DanniZaMasiva broiPoMalko;
    DanniZaMasiva broiPoveche;

    for(int i = 0; i < 32; i++){
        ilito.m[i] = varhove[lqvoDete].ilitoSPoMalko.m[i] | varhove[dqsnoDete].ilitoSPoMalko.m[i];
        ito.m[i] = varhove[lqvoDete].itoSPoveche.m[i] & varhove[dqsnoDete].itoSPoveche.m[i];
        broq.m[i] = varhove[lqvoDete].broiStolkova.m[i] + varhove[dqsnoDete].broiStolkova.m[i];
        iliTolkova.m[i] = varhove[lqvoDete].iliSTolkova.m[i] | varhove[dqsnoDete].iliSTolkova.m[i];
        iTolkova.m[i] = varhove[lqvoDete].iSTolkova.m[i] & varhove[dqsnoDete].iSTolkova.m[i];
        broiPoMalko.m[i] = varhove[lqvoDete].broiSPoMalko.m[i] + varhove[dqsnoDete].broiSPoMalko.m[i];
        broiPoveche.m[i] = varhove[lqvoDete].broiSPoveche.m[i] + varhove[dqsnoDete].broiSPoveche.m[i];
    }

    return daiNovVrah({ilito, ito, broq, iliTolkova, iTolkova, broiPoMalko, broiPoveche, otKade, doKade, lqvoDete, dqsnoDete});
}

struct DanniZaVrashtaneto{
    int ilito;
    int ito;
    int broq;
    int iliSTolkova;
    int iSTolkova;
    int broiSPomalko;
    int broiSPoveche;
};

DanniZaVrashtaneto query(int segashenVrah, int otKade, int doKade, int kolkoBita){
    if(segashenVrah == -1 || varhove[segashenVrah].otKadeObhvashta > doKade || varhove[segashenVrah].doKadeObhvashta < otKade){
        return {0, ~0, 0, 0, ~0, 0, 0};
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        return {varhove[segashenVrah].ilitoSPoMalko.m[kolkoBita],
                varhove[segashenVrah].itoSPoveche.m[kolkoBita],
                varhove[segashenVrah].broiStolkova.m[kolkoBita],
                varhove[segashenVrah].iliSTolkova.m[kolkoBita],
                varhove[segashenVrah].iSTolkova.m[kolkoBita],
                varhove[segashenVrah].broiSPoMalko.m[kolkoBita],
                varhove[segashenVrah].broiSPoveche.m[kolkoBita]};
    }

    DanniZaVrashtaneto nalqvo = query(varhove[segashenVrah].lqvoDete, otKade, doKade, kolkoBita);
    DanniZaVrashtaneto nadqsno = query(varhove[segashenVrah].dqsnoDete, otKade, doKade, kolkoBita);

    return {nalqvo.ilito | nadqsno.ilito,
            nalqvo.ito & nadqsno.ito,
            nalqvo.broq + nadqsno.broq,
            nalqvo.iliSTolkova | nadqsno.iliSTolkova,
            nalqvo.iSTolkova & nadqsno.iSTolkova,
            nalqvo.broiSPomalko + nadqsno.broiSPomalko,
            nalqvo.broiSPoveche + nadqsno.broiSPoveche};
}

bool mojeLiOtDo(int otKade, int doKade){
    if(otKade == doKade){
        return false;
    }

    /*for(int i = otKade; i <= doKade; i++){
        cout<<chisla[i]<<" ";
    }
    cout<<endl;*/

    bool stavaLi = false;

    for(int i = 0; i < 32; i++){
        //cout<<"sega gledame za s "<<i<<" bita"<<endl;
        DanniZaVrashtaneto zaTuka = query(korenNomer, otKade, doKade, i);

        int tukaI = zaTuka.ito;
        int tukaIli = zaTuka.ilito;

        int broiSTolkova = zaTuka.broq;

        int broiVIlito = zaTuka.broiSPomalko;
        int broiVIto = zaTuka.broiSPoveche;

        /*vector<int> sTolkova;

        for(int j = otKade; j <= doKade; j++){
            int broiNaTovaChislo = broiEdiniciV(chisla[j]);
            if(broiNaTovaChislo < i){
                broiVIlito++;
                tukaIli = tukaIli | chisla[j];
                //cout<<chisla[j]<<" e za ilito i to stava "<<tukaIli<<endl;
            }else{
                if(broiNaTovaChislo > i){
                    broiVIto++;
                    tukaI = tukaI & chisla[j];
                    //cout<<chisla[j]<<" e za ito i to stava "<<tukaI<<endl;
                }else{
                    //cout<<chisla[j]<<" e tochno s tolkova"<<endl;
                    broiSTolkova++;
                    sTolkova.push_back(chisla[j]);
                }
            }
        }*/

        //cout<<"broq na v ilito e "<<broiVIlito<<" broq na v ito e "<<broiVIto<<" a broq s tolkova tochno e "<<broiSTolkova<<endl;
        //cout<<"i "<<tukaI<<" ili "<<tukaIli<<endl;

        if(broiVIlito == doKade - otKade + 1){
            break;
        }

        if(broiSTolkova == 0 && ((tukaI != tukaIli) || (broiVIlito == 0 || broiVIto == 0))){
            continue;
        }

        bool mojeLi = true;

        if(broiSTolkova == 0 && tukaI != tukaIli){
            mojeLi = false;
            //cout<<"nqma s tolkova i dvete sa razlichni"<<endl;
        }

        /*for(int j = 1; j < (int)sTolkova.size(); j++){
            if(sTolkova[j] != sTolkova[0]){
                mojeLi = false;
                //cout<<"s tolkova sa razlichni"<<endl;
                break;
            }
        }*/

        if(broiSTolkova > 0 && zaTuka.iSTolkova != zaTuka.iliSTolkova){
            mojeLi = false;
        }

        int chislotoSTolkova = zaTuka.iSTolkova;

        //cout<<"gledame za "<<i<<" bita: "<<endl;
        //cout<<"imame "<<zaTuka.broiSPomalko<<" s po malko i tqhnoto ili e "<<zaTuka.ilito<<endl;
        //cout<<"imame "<<zaTuka.broiSPoveche<<" s poveche i tqhnoto i e "<<zaTuka.ito<<endl;
        //cout<<"imame "<<zaTuka.broq<<" s tochno tolkova ito e "<<zaTuka.iSTolkova<<" a ilito e "<<zaTuka.iliSTolkova<<endl;
        //cout<<"zasq mojeli e "<<mojeLi<<endl;

        //cout<<"ito e "<<tukaI<<" ilito e "<<tukaIli<<" tovhno s tolkova e "<<chislotoSTolkova<<endl;

        if(broiVIlito == 0 && broiVIto > 0 && (chislotoSTolkova | tukaIli) == tukaI){
            //cout<<"sluchai nomer 1"<<endl;
        }else{
            if(broiVIto == 0 && broiVIlito > 0 && (chislotoSTolkova & tukaI) == tukaIli){
                //cout<<"sluchai nomer 2"<<endl;
            }else{
                if(broiVIlito > 0 && (chislotoSTolkova & tukaI) == tukaIli){
                    //cout<<"sluchai nomer 3"<<endl;
                }else{
                    if(broiVIto > 0 && (chislotoSTolkova | tukaIli) == tukaI){
                        //cout<<"sluchai nomer 4"<<endl;
                    }else{
                        if(broiSTolkova >= 2 && ((chislotoSTolkova & tukaI) == (chislotoSTolkova | tukaIli))){
                            //cout<<"sluchai nomer 5"<<endl;
                        }else{
                            mojeLi = false;
                        }
                    }
                }
            }
        }

        if(mojeLi == true){
            //cout<<"kazvame che moje"<<endl;
            stavaLi = true;
            break;
        }
        //cout<<"kazvame che ne moje "<<endl;
    }

    return stavaLi;
}

vector<bool> otgovori;

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    //cin>>broiChisla>>broiPitaniq;

    scanf("%i %i", &broiChisla, &broiPitaniq);

    for(int i = 0; i < broiChisla; i++){
        //cin>>chisla[i];
        scanf("%i", &chisla[i]);
    }

    korenNomer = postroiDarvoto(0, broiChisla - 1);

    /*for(int i = 0; i < (int)varhove.size(); i++){
        cout<<"obhvashta ot "<<varhove[i].otKadeObhvashta<<" do "<<varhove[i].doKadeObhvashta<<" lqvo dete "<<varhove[i].lqvoDete<<" dqsno dete "<<varhove[i].dqsnoDete<<endl;

        for(int j = 0; j < 32; j++){
            cout<<j<<" ilito "<<varhove[i].ilitoSPoMalko.m[j]<<" ito "<<varhove[i].itoSPoveche.m[j];
            cout<<" broq s tolkova "<<varhove[i].broiStolkova.m[j]<<" ilito s tolkova "<<varhove[i].iliSTolkova.m[j]<<" ito s tolkova "<<varhove[i].iSTolkova.m[j]<<endl;
        }
    }
    cout<<endl;*/

    for(int i = 0; i < broiPitaniq; i++){
        int otKade;
        int doKade;

        //cin>>otKade>>doKade;
        scanf("%i %i", &otKade, &doKade);

        otKade--;
        doKade--;

        /*for(int j = 0; j < 32; j++){
            DanniZaVrashtaneto tuka = query(korenNomer, otKade, doKade, j);

            cout<<j<<" broq s tolkova "<<tuka.broq<<" ili s tolkova "<<tuka.iliSTolkova<<" i s tolkova "<<tuka.iSTolkova;
            cout<<", broi s po malko "<<tuka.broiSPomalko<<" ili na po malkite "<<tuka.ilito;
            cout<<", broi s poveche "<<tuka.broiSPoveche<<" i na s povecheto "<<tuka.ito<<endl;
        }*/

        if(mojeLiOtDo(otKade, doKade) == true){
            //cout<<"Yes"<<endl;
            //printf("Yes \n");
            otgovori.push_back(true);
        }else{
            //cout<<"No"<<endl;
            //printf("No \n");
            otgovori.push_back(false);
        }
    }

    for(int i = 0; i < (int)otgovori.size(); i++){
        if(otgovori[i] == true){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
