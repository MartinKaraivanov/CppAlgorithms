#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;

struct DanniZaPromqnata{
    char tipPromqna;
    int koqLampa;
};

struct DanniZaDosegashniPromeniISastoqnie{
    unsigned int sastoqnie;
    DanniZaPromqnata promqnaZaDaSeStigneDoTuk;
};

int broiLampi;

unsigned int nachalen;

unsigned int priVsichkiSvetnati;

bool visited[3000000];
DanniZaPromqnata kakvaPromqnaZaDaStignemDoTuk[3000000];

unsigned int slozhiTamDaEEdno(unsigned int sastoqnie, int poziciq){
    unsigned int maska = 1 << poziciq;
    return sastoqnie | maska;
}

unsigned int slozhiTamDaENula(unsigned int sastoqnie, int poziciq){
    unsigned int maska = 1 << poziciq;
    return sastoqnie & ~maska;
}

unsigned int kakvoPisheTam(unsigned int sastoqnie, int poziciq){
    sastoqnie >>= poziciq;
    return sastoqnie & 1;
}

bool vsichkiLiSaSvetnati(unsigned int sastoqnie){
    return sastoqnie == priVsichkiSvetnati;
}

DanniZaPromqnata promeniParvataLampaVRedicata(unsigned int sastoqnie){
    int parvataLampa = 1;

    /// tova nishto ne promeniq - triava da vrushta novo sastoianie osven dannite za promianata

    if(kakvoPisheTam(sastoqnie, parvataLampa) == 1){
        return {'-', parvataLampa};
    }else{
        return {'+', parvataLampa};
    }
}

DanniZaPromqnata promeniLampataSledNaiMalkataSvetnata(unsigned int sastoqnie){
    int svetnatataLampaSNaiMalakNomer = 0;

    for(int i = 1; i <= broiLampi; i++){
        if(kakvoPisheTam(sastoqnie, i) == 1){
            svetnatataLampaSNaiMalakNomer = i;
            break;
        }
    }

    if(svetnatataLampaSNaiMalakNomer == broiLampi){
        return {'.', -1};
    }

    /// tova nishto ne promenia - triabva da vrushta novo sastoianie osven danni za promianata

    int lampaZaObraotvane = svetnatataLampaSNaiMalakNomer + 1;

    if(kakvoPisheTam(sastoqnie, lampaZaObraotvane) == 1){
        return {'-', lampaZaObraotvane};
    }else{
        return {'+', lampaZaObraotvane};
    }
}

void bfs(){
    queue<DanniZaDosegashniPromeniISastoqnie> q;

    DanniZaPromqnata nachalnaPromqna = {'k', 0};

    kakvaPromqnaZaDaStignemDoTuk[nachalen] = nachalnaPromqna;
    q.push({nachalen, nachalnaPromqna});

    while(q.empty() == false){
        DanniZaDosegashniPromeniISastoqnie segashnoSast = q.front();
        q.pop();

        if(visited[segashnoSast.sastoqnie] == true){
            continue;
        }

        visited[segashnoSast.sastoqnie] = true;
        kakvaPromqnaZaDaStignemDoTuk[segashnoSast.sastoqnie] = segashnoSast.promqnaZaDaSeStigneDoTuk;

        //cout<<segashnoSast.sastoqnie<<" "<<segashnoSast.promqnaZaDaSeStigneDoTuk.tipPromqna<<segashnoSast.promqnaZaDaSeStigneDoTuk.koqLampa<<endl;

        if(vsichkiLiSaSvetnati(segashnoSast.sastoqnie) == true){
            break;
        }

        DanniZaPromqnata parviVid = promeniParvataLampaVRedicata(segashnoSast.sastoqnie);
        DanniZaPromqnata vtoriVid = promeniLampataSledNaiMalkataSvetnata(segashnoSast.sastoqnie);

        //cout<<parviVid.tipPromqna<<parviVid.koqLampa<<endl;
        //cout<<vtoriVid.tipPromqna<<vtoriVid.koqLampa<<endl;

        unsigned int sParviaVidPromqna = segashnoSast.sastoqnie;
        unsigned int sVtoriaVidPromqna = segashnoSast.sastoqnie;

        if(parviVid.tipPromqna == '+'){
            //sParviaVidPromqna[parviVid.koqLampa] = true;
            sParviaVidPromqna = slozhiTamDaEEdno(sParviaVidPromqna, parviVid.koqLampa);
        }else{
            if(parviVid.tipPromqna == '-'){
                //sParviaVidPromqna[parviVid.koqLampa] = false;
                sParviaVidPromqna = slozhiTamDaENula(sParviaVidPromqna, parviVid.koqLampa);
            }
        }

        if(vtoriVid.tipPromqna == '+'){
            //sVtoriaVidPromqna[vtoriVid.koqLampa] = true;
            sVtoriaVidPromqna = slozhiTamDaEEdno(sVtoriaVidPromqna, vtoriVid.koqLampa);
        }else{
            if(vtoriVid.tipPromqna == '-'){
                //sVtoriaVidPromqna[vtoriVid.koqLampa] = false;
                sVtoriaVidPromqna = slozhiTamDaENula(sVtoriaVidPromqna, vtoriVid.koqLampa);
            }
        }

        //cout<<sParviaVidPromqna<<" "<<sVtoriaVidPromqna<<endl;

        if(visited[sParviaVidPromqna] == false){
            q.push({sParviaVidPromqna, parviVid});
        }
        if(visited[sVtoriaVidPromqna] == false){
            q.push({sVtoriaVidPromqna, vtoriVid});
        }

    }
}

unsigned int segashnoSastoqnie;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiLampi;

    for(int i = 1; i <= broiLampi; i++){
        priVsichkiSvetnati = slozhiTamDaEEdno(priVsichkiSvetnati, i);
    }

    bfs();

    stack<DanniZaPromqnata> promenite;

    segashnoSastoqnie = priVsichkiSvetnati;

    /// mnogo slojno
    while(true){

        DanniZaPromqnata segashnaPromqna = kakvaPromqnaZaDaStignemDoTuk[segashnoSastoqnie];

        if(segashnaPromqna.tipPromqna == 'k'){
            break;
        }

        promenite.push(segashnaPromqna);

        if(segashnaPromqna.tipPromqna == '+'){
            //segashnoSastoqnie[segashnaPromqna.koqLampa] = false;
            segashnoSastoqnie = slozhiTamDaENula(segashnoSastoqnie, segashnaPromqna.koqLampa);
        }else{
            if(segashnaPromqna.tipPromqna == '-'){
                //segashnoSastoqnie[segashnaPromqna.koqLampa] = true;
                segashnoSastoqnie = slozhiTamDaEEdno(segashnoSastoqnie, segashnaPromqna.koqLampa);
            }
        }
    }

    while(promenite.empty() == false){
        cout<<promenite.top().tipPromqna<<promenite.top().koqLampa<<endl;
        promenite.pop();
    }

    return 0;
}
