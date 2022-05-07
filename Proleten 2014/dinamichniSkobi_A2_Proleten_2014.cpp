#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int nachalnaRedica[200010];

struct DanniZaVarha{
    int sborVPoddarvoto;
    int maxVPoddarvoto;
    int minVPoddarvoto;
    int lazyStoinost;
    int otKoiIndexObhvashta;
    int doKoiIndexObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVarha> varhove;

int daiNovVrah(DanniZaVarha novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int postroiDarvoto(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah({nachalnaRedica[otKade], nachalnaRedica[otKade], nachalnaRedica[otKade], 1, otKade, doKade, -1, -1});
    }

    int lqvoDeteNomer = postroiDarvoto(otKade, (otKade + doKade)/2);
    int dqsnoDeteNomer = postroiDarvoto((otKade + doKade)/2 + 1, doKade);

    return daiNovVrah({varhove[lqvoDeteNomer].sborVPoddarvoto + varhove[dqsnoDeteNomer].sborVPoddarvoto,
                        max(varhove[lqvoDeteNomer].maxVPoddarvoto, varhove[lqvoDeteNomer].sborVPoddarvoto + varhove[dqsnoDeteNomer].maxVPoddarvoto),
                        min(varhove[lqvoDeteNomer].minVPoddarvoto, varhove[lqvoDeteNomer].sborVPoddarvoto + varhove[dqsnoDeteNomer].minVPoddarvoto),
                        1,
                        otKade,
                        doKade,
                        lqvoDeteNomer,
                        dqsnoDeteNomer});
}

void otpechataiDarvoto(int segashenVrah){

    cout<<"sega sam v "<<segashenVrah<<" koito obhvashta ot "<<varhove[segashenVrah].otKoiIndexObhvashta<<" do "<<varhove[segashenVrah].doKoiIndexObhvashta;
    cout<<" lazy stoinost "<<varhove[segashenVrah].lazyStoinost;
    cout<<" sbora v poddarvoto e "<<varhove[segashenVrah].sborVPoddarvoto<<" maxa e "<<varhove[segashenVrah].maxVPoddarvoto;
    cout<<" mina e "<<varhove[segashenVrah].minVPoddarvoto<<" lqvoto dete e "<<varhove[segashenVrah].lqvoDete<<" a dqsnoto "<<varhove[segashenVrah].dqsnoDete<<endl;

    if(varhove[segashenVrah].lqvoDete > -1){
        otpechataiDarvoto(varhove[segashenVrah].lqvoDete);
    }
    if(varhove[segashenVrah].dqsnoDete > -1){
        otpechataiDarvoto(varhove[segashenVrah].dqsnoDete);
    }

}

void update(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1 || otKade > varhove[segashenVrah].doKoiIndexObhvashta || doKade < varhove[segashenVrah].otKoiIndexObhvashta){
        return ;
    }

    if(otKade <= varhove[segashenVrah].otKoiIndexObhvashta && doKade >= varhove[segashenVrah].doKoiIndexObhvashta){
        varhove[segashenVrah].sborVPoddarvoto *= -1;
        swap(varhove[segashenVrah].minVPoddarvoto, varhove[segashenVrah].maxVPoddarvoto);
        varhove[segashenVrah].minVPoddarvoto *= -1;
        varhove[segashenVrah].maxVPoddarvoto *= -1;
        varhove[segashenVrah].lazyStoinost *= -1;
        return ;
    }

    int lqvoDete = varhove[segashenVrah].lqvoDete;
    int dqsnoDete = varhove[segashenVrah].dqsnoDete;

    update(lqvoDete, otKade, doKade);
    update(dqsnoDete, otKade, doKade);

    if(lqvoDete == -1){
        varhove[segashenVrah].sborVPoddarvoto = varhove[dqsnoDete].sborVPoddarvoto;
        varhove[segashenVrah].maxVPoddarvoto = varhove[dqsnoDete].maxVPoddarvoto;
        varhove[segashenVrah].minVPoddarvoto = varhove[dqsnoDete].minVPoddarvoto;
    }else{
        if(dqsnoDete == -1){
            varhove[segashenVrah].sborVPoddarvoto = varhove[lqvoDete].sborVPoddarvoto;
            varhove[segashenVrah].maxVPoddarvoto = varhove[lqvoDete].maxVPoddarvoto;
            varhove[segashenVrah].minVPoddarvoto = varhove[lqvoDete].minVPoddarvoto;
        }else{
            varhove[segashenVrah].sborVPoddarvoto = varhove[lqvoDete].sborVPoddarvoto + varhove[dqsnoDete].sborVPoddarvoto;
            varhove[segashenVrah].maxVPoddarvoto = max(varhove[lqvoDete].maxVPoddarvoto, varhove[lqvoDete].sborVPoddarvoto + varhove[dqsnoDete].maxVPoddarvoto);
            varhove[segashenVrah].minVPoddarvoto = min(varhove[lqvoDete].minVPoddarvoto, varhove[lqvoDete].sborVPoddarvoto + varhove[dqsnoDete].minVPoddarvoto);
        }
    }


    if(varhove[segashenVrah].lazyStoinost == -1){
        varhove[segashenVrah].sborVPoddarvoto *= -1;
        swap(varhove[segashenVrah].minVPoddarvoto, varhove[segashenVrah].maxVPoddarvoto);
        varhove[segashenVrah].minVPoddarvoto *= -1;
        varhove[segashenVrah].maxVPoddarvoto *= -1;
    }
}

struct DanniZaQueryto{
    int suma;
    int minimalno;
    int maximalno;
};

DanniZaQueryto privedi(DanniZaQueryto parvonachalno, int lazyStoinost){
    if(lazyStoinost == -1){
        parvonachalno.suma *= -1;
        swap(parvonachalno.minimalno, parvonachalno.maximalno);
        parvonachalno.minimalno *= -1;
        parvonachalno.maximalno *= -1;
    }

    return parvonachalno;
}

DanniZaQueryto query(int segashenVrah, int otKade, int doKade){
    if(segashenVrah == -1 || otKade > varhove[segashenVrah].doKoiIndexObhvashta || doKade < varhove[segashenVrah].otKoiIndexObhvashta){
        return {0, 0, 0};
    }

    if(otKade <= varhove[segashenVrah].otKoiIndexObhvashta && doKade >= varhove[segashenVrah].doKoiIndexObhvashta){
        return {varhove[segashenVrah].sborVPoddarvoto, varhove[segashenVrah].minVPoddarvoto, varhove[segashenVrah].maxVPoddarvoto};
    }

    DanniZaQueryto lqvoto = query(varhove[segashenVrah].lqvoDete, otKade, doKade);
    DanniZaQueryto dqsnoto = query(varhove[segashenVrah].dqsnoDete, otKade, doKade);

    if(lqvoto.suma == 0 && lqvoto.maximalno == 0 && lqvoto.minimalno == 0){
        return privedi(dqsnoto, varhove[segashenVrah].lazyStoinost);
    }
    if(dqsnoto.suma == 0 && dqsnoto.maximalno == 0 && dqsnoto.minimalno == 0){
        return privedi(lqvoto, varhove[segashenVrah].lazyStoinost);
    }

    int tukaSbor = lqvoto.suma + dqsnoto.suma;
    int tukaMin = min(lqvoto.minimalno, lqvoto.suma + dqsnoto.minimalno);
    int tukaMax = max(lqvoto.maximalno, lqvoto.suma + dqsnoto.maximalno);

    DanniZaQueryto zaVrasht = privedi({tukaSbor, tukaMin, tukaMax}, varhove[segashenVrah].lazyStoinost);

    return zaVrasht;
}

/*
void updateGlupav(int otKade, int doKade){

    for(int i = otKade; i <= doKade; i++){
        nachalnaRedica[i] *= -1;
    }

}

bool queryGlupavo(int otKade, int doKade){

    int suma = 0;
    bool stavaLiOtric = false;

    for(int i = otKade; i <= doKade; i++){
        suma += nachalnaRedica[i];
        if(suma < 0){
            stavaLiOtric = true;
            break;
        }
    }

    if(suma == 0 && stavaLiOtric == false){
        return true;
    }

    return false;
}
*/


vector<int> otgovori;

char vhodniSkobi[200010];

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int broiSkobi;
    string nachalniSkobi;
    int broiZaqvki;

    //cin>>broiSkobi;
    scanf("%i", &broiSkobi);

    //cin>>nachalniSkobi;
    scanf("%200000s", vhodniSkobi);

    nachalniSkobi = vhodniSkobi;


    for(int i = 0; i < broiSkobi; i++){
        if(nachalniSkobi[i] == '('){
            nachalnaRedica[i] = 1;
        }else{
            nachalnaRedica[i] = -1;
        }
    }

    int korenNomer = postroiDarvoto(0, broiSkobi - 1);

    //otpechataiDarvoto(korenNomer);

    //cin>>broiZaqvki;
    scanf("%i", &broiZaqvki);

    for(int i = 0; i < broiZaqvki; i++){
        char tip;
        int otKade;
        int doKade;

        //cin>>tip>>otKade>>doKade;

        scanf(" %c %i %i", &tip, &otKade, &doKade);

        otKade--;
        doKade--;

        if(tip == 'u'){
            update(korenNomer, otKade, doKade);
            //otpechataiDarvoto(korenNomer);
            //updateGlupav(otKade, doKade);
        }else{
            if(otKade%2 == doKade%2){
                //otgovori.push_back(0);
                //cout<<0<<endl;
                printf("0 \n");
                continue;
            }

            DanniZaQueryto pitane = query(korenNomer, otKade, doKade);
            //cout<<"kazvame che sbora e "<<pitane.suma<<" a mina e "<<pitane.minimalno<<endl;
            if(pitane.suma == 0 && pitane.minimalno >= 0){
            //if(queryGlupavo(otKade, doKade) == true){
                //otgovori.push_back(1);
                //cout<<1<<endl;
                printf("1 \n");
            }else{
                //otgovori.push_back(0);
                //cout<<0<<endl;
                printf("0 \n");
            }
        }
    }

    /*for(int i = 0; i < (int)otgovori.size(); i++){
        //cout<<otgovori[i]<<endl;
        printf("%i \n", otgovori[i]);
    }*/

    return 0;
}
