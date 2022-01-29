#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int broiShahti;
int broiDeistviq;

int bashta[150010];

int namalqneNaTozi[150010];

int dalbochina[150010];

int broiVPoddarvotoNa[150010];

vector<int> deca[150010];

int nameriTejestta(int segashenVrah, int dalb){
    dalbochina[segashenVrah] = dalb;

    broiVPoddarvotoNa[segashenVrah] = 1;

    for(int i = 0; i < (int)deca[segashenVrah].size(); i++){
        broiVPoddarvotoNa[segashenVrah] += nameriTejestta(deca[segashenVrah][i], dalb + 1);
    }

    return broiVPoddarvotoNa[segashenVrah];
}

struct DanniZaSkoka{
    int doKoi;
    int naiGolqmotoMahane;
};

DanniZaSkoka skokOt[150010];

int korenKvadratenOtN;

vector<int> redNaVlizane;
int toziKogaEVlqzal[150010];

void napraviSkokovete(int segashenVrah){
    redNaVlizane.push_back(segashenVrah);
    toziKogaEVlqzal[segashenVrah] = redNaVlizane.size() - 1;

    int skokDo = skokOt[bashta[segashenVrah]].doKoi;

    //cout<<"za sega "<<segashenVrah<<" skacha do "<<skokDo<<endl;

    while(skokDo != -1 && broiVPoddarvotoNa[skokDo] - broiVPoddarvotoNa[segashenVrah] > korenKvadratenOtN){
        //cout<<broiVPoddarvotoNa[skokDo]<<" "<<broiVPoddarvotoNa[segashenVrah]<<" "<<korenKvadratenOtN<<endl;
        skokDo = redNaVlizane[toziKogaEVlqzal[skokDo] + 1];
        //cout<<"veche skacha do "<<skokDo<<endl;
    }

    if(segashenVrah == 1){
        skokOt[segashenVrah] = {1, 0};
    }else{
        skokOt[segashenVrah] = {skokDo, 0};
    }

    //cout<<"slojihme "<<segashenVrah<<" da skacha do "<<skokOt[segashenVrah].doKoi<<endl;

    for(int i = 0; i < (int)deca[segashenVrah].size(); i++){
        napraviSkokovete(deca[segashenVrah][i]);
    }

    redNaVlizane.pop_back();
    toziKogaEVlqzal[segashenVrah] = -1;
}

void updatevane(int segashenVrah, int novotoMahane, int otKoiPochnahme){
    if(dalbochina[skokOt[segashenVrah].doKoi] >= dalbochina[otKoiPochnahme]){
        return ;
    }

    if(skokOt[segashenVrah].doKoi != 0){
        skokOt[segashenVrah].naiGolqmotoMahane = max(skokOt[segashenVrah].naiGolqmotoMahane, novotoMahane);
    }

    for(int i = 0; i < (int)deca[segashenVrah].size(); i++){
        updatevane(deca[segashenVrah][i], novotoMahane, otKoiPochnahme);
    }
}

int tukaKolkoEMahaneto(int start, int doKade, int moment){
    int zaVrasht = 0;

    int segashen = start;

    while(true){
        //cout<<segashen<<" "<<skokOt[segashen].doKoi<<endl;
        if(dalbochina[skokOt[segashen].doKoi] >= dalbochina[doKade] && skokOt[segashen].doKoi != 0){
            zaVrasht = max(zaVrasht, skokOt[segashen].naiGolqmotoMahane);
            segashen = skokOt[segashen].doKoi;
        }else{
            break;
        }
    }

    while(segashen != doKade){
        zaVrasht = max(zaVrasht, namalqneNaTozi[segashen]);

        segashen = bashta[segashen];
    }

    zaVrasht = max(zaVrasht, namalqneNaTozi[doKade]);

    return zaVrasht;
}

vector<int> otgovori;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiShahti>>broiDeistviq;

    for(int i = 1; i < broiShahti; i++){
        int tuka;
        cin>>tuka;

        bashta[i + 1] = tuka;
        deca[tuka].push_back(i + 1);
        //dalbochina[i + 1] = dalbochina[tuka] + 1;
    }

    bashta[1] = -1;

    nameriTejestta(1, 0);

    /*for(int i = 1; i <= broiShahti; i++){
        cout<<i<<" "<<dalbochina[i]<<" "<<broiVPoddarvotoNa[i]<<endl;
    }*/

    korenKvadratenOtN = sqrt(broiShahti);

    skokOt[1] = {1, 0};
    napraviSkokovete(1);
    skokOt[1] = {0, 0};

    for(int i = 1; i <= broiShahti; i++){
        if(skokOt[i].doKoi == i){
            skokOt[i].doKoi = bashta[i];
        }
    }

    /*for(int i = 1; i <= broiShahti; i++){
        cout<<i<<" "<<skokOt[i].doKoi<<" "<<skokOt[i].naiGolqmotoMahane<<endl;
    }*/

    for(int i = 0; i < broiDeistviq; i++){
        string tip;
        cin>>tip;

        if(tip == "k4i"){
            int moment;
            int otKade;
            int doKade;

            cin>>moment>>otKade>>doKade;

            int mahanetoTuka = tukaKolkoEMahaneto(otKade, doKade, moment);

            otgovori.push_back(moment*10 - mahanetoTuka);
        }else{
            int moment;
            int koqShahta;
            int mahane;

            cin>>moment>>koqShahta>>mahane;

            namalqneNaTozi[koqShahta] += mahane;
            updatevane(koqShahta, namalqneNaTozi[koqShahta], koqShahta);
        }
    }

    for(int i = 0; i < (int)otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
