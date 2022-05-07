#include<iostream>
#include<vector>
using namespace std;

int broiKoncerti;
int broiIzpalneniq;

struct DanniZaIzpalnenie{
    int start;
    int krai;
};

int naiGolqmo;

DanniZaIzpalnenie izpalneniq[200010];

struct DanniZaVrah{
    int maximalno;
    int lazyDelta;
    int otKadeObhvashta;
    int doKadeObhvashta;
    int lqvoDete;
    int dqsnoDete;
};

vector<DanniZaVrah> varhove;
int korenNomer = -1;

int daiNovVrah(DanniZaVrah novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otKade, int doKade){
    if(otKade == doKade){
        return daiNovVrah({0, 0, otKade, doKade, -1, -1});
    }

    int lqvoDete = napraviDarvo(otKade, (otKade + doKade)/2);
    int dqsnoDete = napraviDarvo((otKade + doKade)/2 + 1, doKade);

    return daiNovVrah({0, 0, otKade, doKade, lqvoDete, dqsnoDete});
}

int maxaTam(int kade){
    if(kade == -1){
        return 0;
    }

    return varhove[kade].maximalno;
}

void update(int segashenVrah, int otKade, int doKade, int delta){

    if(segashenVrah == -1 || otKade > varhove[segashenVrah].doKadeObhvashta || doKade < varhove[segashenVrah].otKadeObhvashta){
        return ;
    }

    if(otKade <= varhove[segashenVrah].otKadeObhvashta && doKade >= varhove[segashenVrah].doKadeObhvashta){
        varhove[segashenVrah].maximalno += delta;
        varhove[segashenVrah].lazyDelta += delta;

        return ;
    }

    update(varhove[segashenVrah].lqvoDete, otKade, doKade, delta);
    update(varhove[segashenVrah].dqsnoDete, otKade, doKade, delta);

    varhove[segashenVrah].maximalno = max(maxaTam(varhove[segashenVrah].lqvoDete), maxaTam(varhove[segashenVrah].dqsnoDete)) + varhove[segashenVrah].lazyDelta;
}

void otpechataiDarvo(int segashenVrah){
    if(segashenVrah == -1){
        return ;
    }

    cout<<"sega sme vav vrah "<<segashenVrah<<" koito obhavshta ot "<<varhove[segashenVrah].otKadeObhvashta<<" do "<<varhove[segashenVrah].doKadeObhvashta;
    cout<<" maximalnoto e "<<varhove[segashenVrah].maximalno<<" lazy deltata e "<<varhove[segashenVrah].lazyDelta;
    cout<<" lqvoto dete e "<<varhove[segashenVrah].lqvoDete<<" a dqsnoto dete e "<<varhove[segashenVrah].dqsnoDete<<endl;

    otpechataiDarvo(varhove[segashenVrah].lqvoDete);
    otpechataiDarvo(varhove[segashenVrah].dqsnoDete);
}

int main(){
    cin>>broiKoncerti;

    for(int i = 0; i < broiKoncerti; i++){
        cin>>izpalneniq[i*2].start>>izpalneniq[i*2].krai>>izpalneniq[i*2 + 1].start>>izpalneniq[i*2 + 1].krai;
    }

    broiIzpalneniq = 2*broiKoncerti;

    for(int i = 0; i < broiIzpalneniq; i++){
        naiGolqmo = max(naiGolqmo, izpalneniq[i].krai);
    }

    cout<<"nai golqmoto e "<<naiGolqmo<<endl;

    korenNomer = napraviDarvo(0, naiGolqmo);

    cout<<"korena e s nomer "<<korenNomer<<endl;

    otpechataiDarvo(korenNomer);
    cout<<endl;

    for(int i = 0; i < broiIzpalneniq; i++){
        update(korenNomer, izpalneniq[i].start, izpalneniq[i].krai, 1);
        cout<<"updatevame ot "<<izpalneniq[i].start<<" do "<<izpalneniq[i].krai<<endl;
        cout<<"darvoto stava "<<endl;
        otpechataiDarvo(korenNomer);
        cout<<endl;
    }

    cout<<varhove[korenNomer].maximalno<<endl;


    return 0;
}
