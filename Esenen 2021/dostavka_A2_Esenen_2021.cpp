#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

long long broiDostavki;

struct DanniZaDostavkata{
    long long vKoiMoment;
    long long koqKashta;
};

DanniZaDostavkata dostavki[20010];

bool koqEPoNapred(DanniZaDostavkata a, DanniZaDostavkata b){
    return a.vKoiMoment < b.vKoiMoment;
}

struct DanniZaSaseda{
    long long doKoi;
    long long capacitet;
    long long rCapacitet;
    //long long potok;
    //long long indexObratno;
};

const long long nachalenVrah = 0;
const long long kraenVrah = 1;

vector<DanniZaSaseda> sasedstvo[20010];

long long koiOriginalenE(long long nomer){
    return nomer/2;
}

long long parviVrahNa(long long naKoi){
    return naKoi*2;
}

long long vtoriVrahNa(long long naKoi){
    return naKoi*2 + 1;
}

void praveneNaSasedstvoto(){

    for(long long i = 1; i <= broiDostavki; i++){
        /*DanniZaSaseda zaPushvaneVNachalen = {parviVrahNa(i), 1, 0, (long long)sasedstvo[parviVrahNa(i)].size()};
        DanniZaSaseda zaPushvaneVDrugiq = {nachalenVrah, 0, 0, (long long)sasedstvo[nachalenVrah].size()};
        sasedstvo[nachalenVrah].push_back(zaPushvaneVNachalen);
        sasedstvo[parviVrahNa(i)].push_back(zaPushvaneVDrugiq);*/
        sasedstvo[nachalenVrah].push_back({parviVrahNa(i), 1, 0});
        sasedstvo[parviVrahNa(i)].push_back({nachalenVrah, 0, 0});
    }

    for(long long i = 1; i <= broiDostavki; i++){
        for(long long j = i + 1; j <= broiDostavki; j++){
            if(dostavki[j].vKoiMoment > dostavki[i].vKoiMoment && abs(dostavki[j].koqKashta - dostavki[i].koqKashta) <= dostavki[j].vKoiMoment - dostavki[i].vKoiMoment){
                /*DanniZaSaseda zaPushvane = {vtoriVrahNa(j), 1, 0, (long long)sasedstvo[vtoriVrahNa(j)].size()};
                DanniZaSaseda zaPushvane2 = {parviVrahNa(i), 0, 0, (long long)sasedstvo[parviVrahNa(i)].size()};
                sasedstvo[parviVrahNa(i)].push_back(zaPushvane);
                sasedstvo[vtoriVrahNa(j)].push_back(zaPushvane2);*/
                sasedstvo[parviVrahNa(i)].push_back({vtoriVrahNa(j), 1, 0});
                sasedstvo[vtoriVrahNa(j)].push_back({parviVrahNa(i), 0, 0});
            }
        }
    }

    for(long long i = 1; i <= broiDostavki; i++){
        /*DanniZaSaseda zaPushvane = {kraenVrah, 1, 0, (long long)sasedstvo[kraenVrah].size()};
        DanniZaSaseda zaPushvaneVKraen = {vtoriVrahNa(i), 0, 0, (long long)sasedstvo[vtoriVrahNa(i)].size()};
        sasedstvo[vtoriVrahNa(i)].push_back(zaPushvane);
        sasedstvo[kraenVrah].push_back(zaPushvaneVKraen);*/
        sasedstvo[vtoriVrahNa(i)].push_back({kraenVrah, 1, 0});
        sasedstvo[kraenVrah].push_back({vtoriVrahNa(i), 0, 0});
    }

    /*for(long long i = 0; i <= vtoriVrahNa(broiDostavki); i++){
        cout<<i<<" koito originalno e dostavka "<<dostavki[koiOriginalenE(i)].vKoiMoment<<" "<<dostavki[koiOriginalenE(i)].koqKashta<<":"<<endl;
        for(DanniZaSaseda a : sasedstvo[i]){
            //cout<<"do "<<a.doKoi<<" capacitet "<<a.capacitet<<" potok "<<a.potok<<" obraten index "<<a.indexObratno<<endl;
            cout<<"do "<<a.doKoi<<" capacitet "<<a.capacitet<<" rCapacitet "<<a.rCapacitet<<endl;
        }
        cout<<endl;
    }*/
}

/*long long nivo[1000010];

bool bfs(long long start, long long krai){

    for(long long i = 0; i <= vtoriVrahNa(broiDostavki); i++){
        nivo[i] = -1;
    }

    queue<long long> q;
    q.push(start);

    nivo[start] = 0;

    while(q.empty() == false){
        long long naiOtpred = q.front();
        q.pop();

        for(long long i = 0; i < (long long)sasedstvo[naiOtpred].size(); i++){
            DanniZaSaseda sledvasht = sasedstvo[naiOtpred][i];

            if(nivo[sledvasht.doKoi] == -1 && sledvasht.potok < sledvasht.capacitet){
                q.push(sledvasht.doKoi);
                nivo[sledvasht.doKoi] = nivo[naiOtpred] + 1;
            }
        }
    }


    if(nivo[krai] > -1){
        return true;
    }

    return false;
}

long long startNaTozi[1000010];

long long pusniPotok(long long segashen, long long potok, long long kraen){
    if(segashen == kraen){
        return potok;
    }

    for( ; startNaTozi[segashen] < (long long)sasedstvo[segashen].size(); startNaTozi[segashen]++){
        DanniZaSaseda &sledvasht = sasedstvo[segashen][startNaTozi[segashen]];

        if(nivo[sledvasht.doKoi] == nivo[segashen] + 1 && sledvasht.potok < sledvasht.capacitet){
            long long segashenPotok = min(potok, sledvasht.capacitet - sledvasht.potok);

            long long tekushtPotok = pusniPotok(sledvasht.doKoi, segashenPotok, kraen);

            if(tekushtPotok > 0){
                sledvasht.potok += tekushtPotok;

                sasedstvo[sledvasht.doKoi][sledvasht.indexObratno].potok -= tekushtPotok;

                return tekushtPotok;
            }
        }
    }

    return 0;
}

long long dinicFlow(long long start, long long krai){
    long long maxFlow = 0;

    while(true){
        bool stigameLi = bfs(start, krai);

        if(stigameLi == true){
            break;
        }

        for(long long i = 0; i <= vtoriVrahNa(broiDostavki); i++){
            startNaTozi[i] = 0;
        }

        long long tekushtPotok = pusniPotok(start, 1000020, krai);

        while(tekushtPotok > 0){
            maxFlow += tekushtPotok;

            tekushtPotok = pusniPotok(start, 1000020, krai);
        }
    }

    return maxFlow;
}*/

long long parents[20010];
bool visited[20010];

bool bfs(long long start, long long krai){

    for(long long i = 0; i <= vtoriVrahNa(broiDostavki); i++){
        visited[i] = false;
        parents[i] = -1;
    }

    queue<long long> q;
    q.push(start);
    visited[start] = true;

    while(q.empty() == false){
        long long naiOtpred = q.front();
        q.pop();

        if(naiOtpred == krai){
            break;
        }

        for(long long i = 0; i < (long long)sasedstvo[naiOtpred].size(); i++){
            DanniZaSaseda sledvashtiq = sasedstvo[naiOtpred][i];
            if(sledvashtiq.rCapacitet > 0 && visited[sledvashtiq.doKoi] == false){
                q.push(sledvashtiq.doKoi);
                parents[sledvashtiq.doKoi] = naiOtpred;
                visited[sledvashtiq.doKoi] = true;
            }
        }
    }

    return visited[krai];
}

void promeniRCapacitetS(long long otKoi, long long doKoi, long long sRCapacitet){

    for(long long i = 0; i < (long long)sasedstvo[otKoi].size(); i++){
        if(sasedstvo[otKoi][i].doKoi == doKoi){
            sasedstvo[otKoi][i].rCapacitet += sRCapacitet;
            break;
        }
    }
}

void inicializiraneNaRsasedstvo(){

    for(long long i = 0; i <= vtoriVrahNa(broiDostavki); i++){
        for(long long j = 0; j < (long long)sasedstvo[i].size(); j++){
            sasedstvo[i][j].rCapacitet = sasedstvo[i][j].capacitet;
        }
    }

}

long long fordFulkersonFlow(long long start, long long krai){

    long long maximalenPotok = 0;

    inicializiraneNaRsasedstvo();

    while(true){
        bool stigameLi = bfs(start, krai);

        if(stigameLi == false){
            break;
        }

        long long minFlow = 1;

        for(long long vrah = krai; vrah != start; vrah = parents[vrah]){
            long long roditel = parents[vrah];
            promeniRCapacitetS(roditel, vrah, -minFlow);
            promeniRCapacitetS(vrah, roditel, minFlow);
        }

        maximalenPotok += minFlow;
    }

    return maximalenPotok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiDostavki;

    for(long long i = 1; i <= broiDostavki; i++){
        cin>>dostavki[i].vKoiMoment>>dostavki[i].koqKashta;
    }

    sort(dostavki, dostavki + broiDostavki + 1, koqEPoNapred);

    praveneNaSasedstvoto();

    //long long potok = dinicFlow(nachalenVrah, kraenVrah);
    long long potok = fordFulkersonFlow(nachalenVrah, kraenVrah);

    //cout<<"potokat e "<<potok<<endl;

    cout<<max(broiDostavki - potok, (long long)1)<<endl;

    return 0;
}
