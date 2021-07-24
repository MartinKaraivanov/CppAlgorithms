#include<iostream>
using namespace std;

struct DanniZaNaiDobroto{
    int kolkoENaiDobroto;
    int doKoiIndexE;
};

int dalzhinaNaSalama;

int vkusNaSantimetara[1000010];

DanniZaNaiDobroto naiDobroZaLeviq[1000010];
DanniZaNaiDobroto naiDobroZaDesniq[1000010];

int main(){
    cin>>dalzhinaNaSalama;

    for(int i = 1; i <= dalzhinaNaSalama; i++){
        cin>>vkusNaSantimetara[i];
    }


    int zasegaSuma = 0;
    int naiDobrotoZaSega = 0;
    int dostigaSePriIndex = 0;

    for(int i = 1; i <= dalzhinaNaSalama; i++){
        zasegaSuma += vkusNaSantimetara[i];
        if(zasegaSuma >= naiDobrotoZaSega){
            naiDobrotoZaSega = zasegaSuma;
            dostigaSePriIndex = i;
        }
        naiDobroZaLeviq[i] = {naiDobrotoZaSega, dostigaSePriIndex};
    }

    zasegaSuma = 0;
    naiDobrotoZaSega = 0;
    dostigaSePriIndex = dalzhinaNaSalama - 1;

    for(int i = dalzhinaNaSalama; i > 0; i--){
        zasegaSuma += vkusNaSantimetara[i];
        if(zasegaSuma >= naiDobrotoZaSega){
            naiDobrotoZaSega = zasegaSuma;
            dostigaSePriIndex = i;
        }
        naiDobroZaDesniq[i] = {naiDobrotoZaSega, dostigaSePriIndex};
    }

    int naiDobraSuma = -100010;
    int doKadeEIvan = 0;
    int doKadeEPetur = dalzhinaNaSalama - 1;

    for(int i = dalzhinaNaSalama; i >= 0; i--){
        int sumaZaTezi = naiDobroZaLeviq[i].kolkoENaiDobroto + naiDobroZaDesniq[i + 1].kolkoENaiDobroto;

        //cout<<i<<" "<<sumaZaTezi<<endl;

        if(sumaZaTezi > naiDobraSuma){
            naiDobraSuma = sumaZaTezi;
            doKadeEIvan = naiDobroZaLeviq[i].doKoiIndexE;
            doKadeEPetur = naiDobroZaDesniq[i + 1].doKoiIndexE;
        }
    }


    cout<<naiDobraSuma<<endl;

    cout<<doKadeEIvan<<" "<<doKadeEPetur<<endl;

    return 0;
}
