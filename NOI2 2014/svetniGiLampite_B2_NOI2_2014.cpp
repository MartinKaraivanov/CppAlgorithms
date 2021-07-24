#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct DanniZaPromqnata{
    char tipPromqna;
    int koqLampa;
};

struct DanniZaDosegashniPromeniISastoqnie{
    vector<bool> sastoqnie;
    vector<DanniZaPromqnata> promeni;
};

int broiLampi;

vector<bool> nachalen;

map<vector<bool>, bool> visited;

bool vsichkiLiSaSvetnati(vector<bool> sastoqnie){
    for(int i = 1; i <= broiLampi; i++){
        if(sastoqnie[i] == false){
            return false;
        }
    }
    return true;
}

DanniZaPromqnata promeniParvataLampaVRedicata(vector<bool> sastoqnie){
    int parvataLampa = 1;

    if(sastoqnie[parvataLampa] == true){
        return {'-', parvataLampa};
    }else{
        return {'+', parvataLampa};
    }
}

DanniZaPromqnata promeniLampataSledNaiMalkataSvetnata(vector<bool> sastoqnie){
    int svetnatataLampaSNaiMalakNomer = 0;

    for(int i = 1; i <= broiLampi; i++){
        if(sastoqnie[i] == true){
            svetnatataLampaSNaiMalakNomer = i;
            break;
        }
    }

    if(svetnatataLampaSNaiMalakNomer == broiLampi){
        return {'.', -1};
    }

    int lampaZaObraotvane = svetnatataLampaSNaiMalakNomer + 1;

    if(sastoqnie[lampaZaObraotvane] == true){
        return {'-', lampaZaObraotvane};
    }else{
        return {'+', lampaZaObraotvane};
    }
}

vector<DanniZaPromqnata> bfs(){
    queue<DanniZaDosegashniPromeniISastoqnie> q;

    vector<DanniZaPromqnata> promeni;

    q.push({nachalen, promeni});

    vector<DanniZaPromqnata> otgovor;

    while(q.empty() == false){
        DanniZaDosegashniPromeniISastoqnie segashnoSast = q.front();
        q.pop();

        if(vsichkiLiSaSvetnati(segashnoSast.sastoqnie) == true){
            otgovor = segashnoSast.promeni;
        }

        if(visited[segashnoSast.sastoqnie] == true){
            continue;
        }

        visited[segashnoSast.sastoqnie] = true;

        DanniZaPromqnata parviVid = promeniParvataLampaVRedicata(segashnoSast.sastoqnie);
        DanniZaPromqnata vtoriVid = promeniLampataSledNaiMalkataSvetnata(segashnoSast.sastoqnie);

        vector<bool> sParviaVidPromqna = segashnoSast.sastoqnie;
        vector<bool> sVtoriaVidPromqna = segashnoSast.sastoqnie;

        if(parviVid.tipPromqna == '+'){
            sParviaVidPromqna[parviVid.koqLampa] = true;
        }else{
            if(parviVid.tipPromqna == '-'){
                sParviaVidPromqna[parviVid.koqLampa] = false;
            }
        }

        if(vtoriVid.tipPromqna == '+'){
            sVtoriaVidPromqna[vtoriVid.koqLampa] = true;
        }else{
            if(vtoriVid.tipPromqna == '-'){
                sVtoriaVidPromqna[vtoriVid.koqLampa] = false;
            }
        }

        if(visited[sParviaVidPromqna] == false){
            vector<DanniZaPromqnata> segasshniPromeni = segashnoSast.promeni;
            segasshniPromeni.push_back(parviVid);
            q.push({sParviaVidPromqna, segasshniPromeni});
        }
        if(visited[sVtoriaVidPromqna] == false){
            vector<DanniZaPromqnata> segashniPromeni = segashnoSast.promeni;
            segashniPromeni.push_back(vtoriVid);
            q.push({sVtoriaVidPromqna, segashniPromeni});
        }

    }

    return otgovor;
}

int main(){
    cin>>broiLampi;

    for(int i = 0; i <= broiLampi; i++){
        nachalen.push_back(false);
    }

    vector<DanniZaPromqnata> promeniPoPatq = bfs();

    for(unsigned int i = 0; i < promeniPoPatq.size(); i++){
        cout<<promeniPoPatq[i].tipPromqna<<promeniPoPatq[i].koqLampa<<endl;
    }

    return 0;
}
