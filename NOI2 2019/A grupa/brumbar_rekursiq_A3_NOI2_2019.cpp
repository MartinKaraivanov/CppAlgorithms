#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct DanniZaDaskata{
    int nomer;
    int dalbochina;
};

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaOtsechka{
    DanniZaTochka nachalnaTochka;
    int daljina;
};

int broiOtsechki;
DanniZaOtsechka otsechki[100010];

int maximalenX;

int broiBrambari;
int tochkiNaPuskane[60010];

vector<int> sasedstvo[100010];

bool koqEPoParva(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.nachalnaTochka.y > b.nachalnaTochka.y){
        return false;
    }
    if(a.nachalnaTochka.y < b.nachalnaTochka.y){
        return true;
    }

    return a.nachalnaTochka.x < b.nachalnaTochka.x;
}

struct DanniZaVrah{
    int stoinost;
    int otKoiIndexObhvashta;
    int doKoiIndexObhvashta;
    int lqvoDeteVrahNomer;
    int dqsnoDeteVrahNomer;
};

vector<DanniZaVrah> varhove;
int nomerNaKorena = -1;

int broiChisla;
vector<int> chisla;

int daiNovVrah(DanniZaVrah novVrah){
    varhove.push_back(novVrah);
    return varhove.size() - 1;
}

int napraviDarvo(int otIndex, int doIndex){
    if(otIndex == doIndex){
        return daiNovVrah({0, otIndex, doIndex, -1, -1});
    }

    int lqvoDeteNomer = napraviDarvo(otIndex, (otIndex + doIndex)/2);
    int dqsnoDeteNomer = napraviDarvo((otIndex + doIndex)/2 + 1, doIndex);

    return daiNovVrah({0, otIndex, doIndex, lqvoDeteNomer, dqsnoDeteNomer});
}

void update(int korenNaPoddarvoVrahNomer, int otIndex, int doIndex, int kolko){
    if(korenNaPoddarvoVrahNomer == -1 ||
       otIndex > varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta ||
       doIndex < varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta){

        return;
    }

    if(otIndex <= varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta &&
       doIndex >= varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta){

        //cout<<"updatevam "<<korenNaPoddarvoVrahNomer<<" i go slagam da e "<<kolko<<endl;
        varhove[korenNaPoddarvoVrahNomer].stoinost = kolko;
        return;
    }

    if(varhove[korenNaPoddarvoVrahNomer].stoinost > 0){
        int tekushtaStoinost = varhove[korenNaPoddarvoVrahNomer].stoinost;

        varhove[korenNaPoddarvoVrahNomer].stoinost = 0;

        update(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer,
               varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta,
               otIndex - 1, tekushtaStoinost);

        update(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer,
               varhove[korenNaPoddarvoVrahNomer].otKoiIndexObhvashta,
               otIndex - 1, tekushtaStoinost);

        update(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer,
                doIndex + 1,
                varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta, tekushtaStoinost);

        update(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer,
                doIndex + 1,
                varhove[korenNaPoddarvoVrahNomer].doKoiIndexObhvashta, tekushtaStoinost);

    }

    update(varhove[korenNaPoddarvoVrahNomer].lqvoDeteVrahNomer, otIndex, doIndex, kolko);
    update(varhove[korenNaPoddarvoVrahNomer].dqsnoDeteVrahNomer, otIndex, doIndex, kolko);
}


int query(int korenNaPoddarvoVrahNomer, int naKoiIndex){
    int segashenVrah = korenNaPoddarvoVrahNomer;

    int kvoPishe = 0;

    while(segashenVrah != -1){
        if(varhove[segashenVrah].otKoiIndexObhvashta > naKoiIndex ||
           varhove[segashenVrah].doKoiIndexObhvashta < naKoiIndex)
        {
            break;
        }

        if(varhove[segashenVrah].stoinost > 0){
            kvoPishe = varhove[segashenVrah].stoinost;
            break;
        }

        if(varhove[segashenVrah].lqvoDeteVrahNomer != -1 &&
           varhove[varhove[segashenVrah].lqvoDeteVrahNomer].otKoiIndexObhvashta <= naKoiIndex &&
           varhove[varhove[segashenVrah].lqvoDeteVrahNomer].doKoiIndexObhvashta >= naKoiIndex)
        {
            segashenVrah = varhove[segashenVrah].lqvoDeteVrahNomer;
        }else{
            segashenVrah = varhove[segashenVrah].dqsnoDeteVrahNomer;
        }
    }

    return kvoPishe;
}

bool visited[100010];

int dalbochini[100010];


void bfs(){
    queue<DanniZaDaskata> q;

    q.push({0, 0});

    while(q.empty() == false){
        DanniZaDaskata naiOtgore = q.front();
        q.pop();

        if(visited[naiOtgore.nomer] == true){
            continue;
        }

        visited[naiOtgore.nomer] = true;
        dalbochini[naiOtgore.nomer] = naiOtgore.dalbochina;

        for(unsigned int i = 0; i < sasedstvo[naiOtgore.nomer].size(); i++){
            if(visited[sasedstvo[naiOtgore.nomer][i]] == false){
                q.push({sasedstvo[naiOtgore.nomer][i], naiOtgore.dalbochina + 1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiOtsechki;

    for(int i = 1; i <= broiOtsechki; i++){
        cin>>otsechki[i].nachalnaTochka.x>>otsechki[i].nachalnaTochka.y>>otsechki[i].daljina;
        maximalenX = max(maximalenX, otsechki[i].nachalnaTochka.x + otsechki[i].daljina);
    }

    cin>>broiBrambari;

    for(int i = 0; i < broiBrambari; i++){
        cin>>tochkiNaPuskane[i];
    }

    sort(otsechki, otsechki + broiOtsechki + 1, koqEPoParva);

    nomerNaKorena = napraviDarvo(0, maximalenX);

    for(int i = 1; i <= broiOtsechki; i++){
        int otLqvo = query(nomerNaKorena, otsechki[i].nachalnaTochka.x - 1);
        int otDqsno = query(nomerNaKorena, otsechki[i].nachalnaTochka.x + otsechki[i].daljina);

        sasedstvo[otLqvo].push_back(i);
        sasedstvo[otDqsno].push_back(i);

        update(nomerNaKorena, otsechki[i].nachalnaTochka.x, otsechki[i].nachalnaTochka.x + otsechki[i].daljina - 1, i);

        //cout<<"sega updatenah ot "<<otsechki[i].nachalnaTochka.x<<" do ";
        //cout<<otsechki[i].nachalnaTochka.x + otsechki[i].daljina - 1<<endl;
        //cout<<endl;
    }

    /*for(int i = 0; i <= broiOtsechki; i++){
        cout<<i<<":"<<endl;

        for(auto j : sasedstvo[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/

    bfs();

    for(int i = 0; i < broiBrambari; i++){
        int dalb = dalbochini[query(nomerNaKorena, tochkiNaPuskane[i])];
        cout<<dalb<<" ";
    }

    return 0;
}
