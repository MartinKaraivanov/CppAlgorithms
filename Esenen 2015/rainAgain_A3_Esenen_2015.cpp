#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Koordinati{
    long long x;
    long long y;
};

int broiKapki;
long long maxXY;

long long liceNaCqloto;

long long maxXPravoag;
long long maxYPravoag;

Koordinati kapki[100010];

struct DanniZaOtsechka{
    Koordinati lqvKrai;
    Koordinati desenKrai;
    int tip; /// 1 - otv, -1 - zatv
};

bool koqEPoNapred(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.lqvKrai.y < b.lqvKrai.y){
        return true;
    }
    if(a.lqvKrai.y > b.lqvKrai.y){
        return false;
    }
    if(a.tip > b.tip){
        return true;
    }
    if(a.tip < b.tip){
        return false;
    }
    return a.lqvKrai.x < b.lqvKrai.x;
}

struct DanniZaIntervala{
    long long otKade;
    long long doKade;
    int broiAktivniV;
};

long long momentenOtgovor;

map<long long, DanniZaIntervala> intervali;

void update(long long otKade, long long doKade, int delta){

    map<long long, DanniZaIntervala>::iterator segashenInterval = intervali.upper_bound(otKade);

    DanniZaIntervala parviInterval = segashenInterval->second;

    //cout<<"nachalniq interval obhvashta ot "<<parviInterval.otKade<<" do "<<parviInterval.doKade<<endl;

    if(otKade == parviInterval.otKade && doKade == parviInterval.doKade){
        segashenInterval->second.broiAktivniV += delta;

        if(delta == 1){
            if(segashenInterval->second.broiAktivniV == 1){
                momentenOtgovor += doKade - otKade;
            }
        }else{
            if(segashenInterval->second.broiAktivniV == 0){
                momentenOtgovor -= doKade - otKade;
            }
        }

        return ;
    }

    if(otKade >= parviInterval.otKade && doKade <= parviInterval.doKade){
        //cout<<"sega sum v krainiq sluchai v koito izcqlo sum v interval koito e ot "<<segashenInterval -> second.otKade<<" do "<<segashenInterval -> first<<endl;

        intervali.erase(parviInterval.doKade);

        int novoAktivni = parviInterval.broiAktivniV + delta;

        if(parviInterval.otKade < otKade){
            intervali[otKade] = {parviInterval.otKade, otKade, parviInterval.broiAktivniV};
        }
        intervali[doKade] = {otKade, doKade, novoAktivni};
        if(doKade < parviInterval.doKade){
            intervali[parviInterval.doKade] = {doKade, parviInterval.doKade, parviInterval.broiAktivniV};
        }

        if(delta == 1){
            if(novoAktivni == 1){
                momentenOtgovor += doKade - otKade;
            }
        }else{
            if(novoAktivni == 0){
                momentenOtgovor -= doKade - otKade;
            }
        }

        return ;
    }

    bool daNasichameLiparviInterval = false;

    if(segashenInterval->second.otKade < otKade){
        daNasichameLiparviInterval = true;
    }

    if(daNasichameLiparviInterval == true){
        segashenInterval++;
    }
    while(segashenInterval != intervali.end() && segashenInterval->first <= doKade){
        //cout<<"segaa sum v interval ot "<<segashenInterval -> second.otKade<<" do "<<segashenInterval -> first<<endl;

        segashenInterval->second.broiAktivniV += delta;

        if(delta == 1){
            if(segashenInterval->second.broiAktivniV == 1){
                momentenOtgovor += segashenInterval->second.doKade - segashenInterval->second.otKade;
            }
        }else{
            if(segashenInterval->second.broiAktivniV == 0){
                momentenOtgovor -= segashenInterval->second.doKade - segashenInterval->second.otKade;
            }
        }

        segashenInterval++;
        //cout<<"sledvashtiq interval e ot "<<segashenInterval->second.otKade<<" do "<<segashenInterval->second.doKade<<endl;
    }

    if(segashenInterval != intervali.end() && segashenInterval->second.otKade < doKade){
        DanniZaIntervala posledenInterval = segashenInterval->second;

        //cout<<"posledniqt interval obhvashta ot "<<posledenInterval.otKade<<" do "<<posledenInterval.doKade<<endl;

        int novBroiAktivniPosleden = posledenInterval.broiAktivniV + delta;

        //cout<<"noviq broi aktivni na posledniq interval e "<<novBroiAktivniPosleden<<endl;

        intervali.erase(posledenInterval.doKade);
        if(posledenInterval.otKade < doKade){
            intervali[doKade] = {posledenInterval.otKade, doKade, novBroiAktivniPosleden};
        }
        intervali[posledenInterval.doKade] = {doKade, posledenInterval.doKade, posledenInterval.broiAktivniV};

        if(delta == 1){
            if(novBroiAktivniPosleden == 1){
                momentenOtgovor += doKade - posledenInterval.otKade;
            }
        }else{
            if(novBroiAktivniPosleden == 0){
                momentenOtgovor -= doKade - posledenInterval.otKade;
            }
        }
    }

    if(daNasichameLiparviInterval == true){

        int novBroiAktivniParvi = parviInterval.broiAktivniV + delta;

        //cout<<"noviq broi aktvini na parviq interval e "<<novBroiAktivniParvi<<endl;

        intervali.erase(parviInterval.doKade);
        if(parviInterval.otKade < otKade){
            intervali[otKade] = {parviInterval.otKade, otKade, parviInterval.broiAktivniV};
        }
        intervali[parviInterval.doKade] = {otKade, parviInterval.doKade, novBroiAktivniParvi};

        if(delta == 1){
            if(novBroiAktivniParvi == 1){
                momentenOtgovor += parviInterval.doKade - otKade;
            }
        }else{
            if(novBroiAktivniParvi == 0){
                momentenOtgovor -= parviInterval.doKade - otKade;
            }
        }
    }
}

long long query(){
    return momentenOtgovor;
}

bool mojeLiSTolkova(vector<DanniZaOtsechka> &otsechki){

    intervali.clear();
    momentenOtgovor = 0;

    long long yNaPrednata = -1;

    long long sumarnoLice = 0;

    intervali[maxXY] = {0, maxXY, 0};

    for(int i = 0; i < (int)otsechki.size(); i++){
        cout<<"sega sme na y "<<otsechki[i].lqvKrai.y<<endl;
        if(otsechki[i].lqvKrai.y != yNaPrednata){
            sumarnoLice += (otsechki[i].lqvKrai.y - yNaPrednata)*query();
            cout<<"natrupvameB "<<(otsechki[i].lqvKrai.y - yNaPrednata)<<" * "<<query()<<" sumarno lice "<<sumarnoLice<<endl;
        }

        cout<<"update na y "<<otsechki[i].lqvKrai.y<<" s tip "<<otsechki[i].tip<<" x ot "<<otsechki[i].lqvKrai.x<<" do "<<otsechki[i].desenKrai.x<<endl;
        update(otsechki[i].lqvKrai.x, otsechki[i].desenKrai.x, otsechki[i].tip);
        //cout<<"momentniq otg e "<<query()<<" "<<endl;
        yNaPrednata = otsechki[i].lqvKrai.y;
    }
    //cout<<endl;

    cout<<"nakraq sa sumarnolice "<<sumarnoLice<<" a cqlo lice "<<liceNaCqloto<<endl;

    if(sumarnoLice == liceNaCqloto){
        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiKapki>>maxXY>>maxXPravoag>>maxYPravoag;

    broiKapki += 4;

    kapki[0] = {0, 0};
    kapki[1] = {0, maxXY};
    kapki[2] = {maxXY, 0};
    kapki[3] = {maxXY, maxXY};

    for(int i = 4; i < broiKapki; i++){
        cin>>kapki[i].x>>kapki[i].y;
        //kapki[i].x *= 2;
        //kapki[i].y *= 2;
    }

    //maxXY *= 2;
    //maxXPravoag *= 2;
    //maxYPravoag *= 2;

    liceNaCqloto = maxXY*maxXY;

    int otgovor = -1;

    for(int t = 0; t < broiKapki; t++){
        vector<DanniZaOtsechka> parviteTolkova;

        for(int i = 0; i <= t; i++){
            long long lqvX   = max(kapki[i].x - (maxXPravoag+1)/2, (long long)0);
            long long gorenY = max(kapki[i].y - (maxYPravoag+1)/2, (long long)0);
            long long desenX = min(kapki[i].x + (maxXPravoag+1)/2, (long long)maxXY);
            long long dolenY = min(kapki[i].y + (maxYPravoag+1)/2, (long long)maxXY);

            DanniZaOtsechka gorna = {{lqvX, gorenY}, {desenX, gorenY}, 1};
            DanniZaOtsechka dolna = {{lqvX, dolenY}, {desenX, dolenY}, -1};

            parviteTolkova.push_back(gorna);
            parviteTolkova.push_back(dolna);
        }

        sort(parviteTolkova.begin(), parviteTolkova.end(), koqEPoNapred);

        bool tuka = mojeLiSTolkova(parviteTolkova);

        if(tuka == true){
            otgovor = t;
            break;
        }
    }

    if(otgovor > -1){
        cout<<otgovor + 1 - 4<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}
