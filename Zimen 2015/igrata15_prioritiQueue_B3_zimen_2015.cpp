#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct zaRazmestvane{
    vector<int> nov;
    int premestenotoChislo;
};

struct patqDoTuk{
    vector<int> sastoqnie;
    vector<int> pat;
    int kolkoHodaDoPodrezhdane;
};

struct otgovora{
    int kolkoHoda;
    vector<int> hodove;
};

struct poMalkoLiE{
    bool operator()(patqDoTuk const& a, patqDoTuk const& b){
        return a.pat.size() + a.kolkoHodaDoPodrezhdane > b.pat.size() + b.kolkoHodaDoPodrezhdane;
    }
};

vector<int> nachalen;

zaRazmestvane nulataNalqvo(vector<int> daskata){
    vector<int> segashen = daskata;

    bool gotoviLiSme = false;
    int smenen = -1;

    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(segashen[4*i + j] == 0){
                segashen[4*i + j] = segashen[4*i + j - 1];
                segashen[4*i + j - 1] = 0;
                gotoviLiSme = true;
                smenen = segashen[4*i + j];
                break;
            }
        }
        if(gotoviLiSme == true){
            break;
        }
    }

    return {segashen, smenen};
}

zaRazmestvane nulataNadqsno(vector<int> daskata){
    vector<int> segashen = daskata;
    bool gotoviLiSme = false;
    int smenen = -1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(segashen[4*i + j] == 0){
                segashen[4*i + j] = segashen[4*i + j + 1];
                segashen[4*i + j + 1] = 0;
                gotoviLiSme = true;
                smenen = segashen[4*i + j];
                break;
            }
        }
        if(gotoviLiSme == true){
            break;
        }
    }

    return {segashen, smenen};
}

zaRazmestvane nulataNagore(vector<int> daskata){
    vector<int> segashen = daskata;
    bool gotoviLiSme = false;
    int smenen = -1;

    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(segashen[4*i + j] == 0){
                segashen[4*i + j] = segashen[4*(i - 1) + j];
                segashen[4*(i - 1) + j] = 0;
                gotoviLiSme = true;
                smenen = segashen[4*i + j];
                break;
            }
        }
        if(gotoviLiSme == true){
            break;
        }
    }
    return {segashen, smenen};
}

zaRazmestvane nulaaNadolu(vector<int> daskata){
    vector<int> segashen = daskata;

    bool gotoviLiSme = false;
    int smenen = -1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(segashen[4*i + j] == 0){
                segashen[4*i + j] = segashen[4*(i + 1) + j];
                segashen[4*(i + 1) + j] = 0;
                gotoviLiSme = true;
                smenen = segashen[4*i + j];
                break;
            }
        }
        if(gotoviLiSme == true){
            break;
        }
    }
    return {segashen, smenen};
}

bool takuvKakuvtoIskameLiE(vector<int> daska){
    vector<int> segashna = daska;

    segashna[4*3 + 3] += 16;

    bool dobraLiE = true;

    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(segashna[4*i + j] - segashna[4*i + j - 1] != 1){
                dobraLiE = false;
            }
        }

        if(dobraLiE == false){
            break;
        }
    }
    return dobraLiE;
}

int kolkoHodaOstavatDoPodrezhdane(vector<int> segashen){
    int broiRazlichni = 0;
    if(segashen[15] != 0){
        broiRazlichni++;
    }

    for(int i = 0; i < 15; i++){
        if(segashen[i] != i + 1){
            broiRazlichni++;
        }
    }

    return broiRazlichni;
}

map<vector<int>, bool> visited;
map<vector<int>, int> dalbochina;

otgovora bfs(){
    priority_queue<patqDoTuk, vector<patqDoTuk>, poMalkoLiE> q;
    vector<int> nachalenPat;
    int nachalenBroiDoPodredba = kolkoHodaOstavatDoPodrezhdane(nachalen);
    q.push({nachalen, nachalenPat, nachalenBroiDoPodredba});
    dalbochina[nachalen] = 0;

    otgovora zaKolkoHoda;

    while(q.empty() == false){
        patqDoTuk naiOtgore = q.top();
        q.pop();

        if(takuvKakuvtoIskameLiE(naiOtgore.sastoqnie) == true){
            zaKolkoHoda.kolkoHoda = dalbochina[naiOtgore.sastoqnie];
            zaKolkoHoda.hodove = naiOtgore.pat;
            break;
        }

        if(visited[naiOtgore.sastoqnie] == true){
            continue;
        }

        visited[naiOtgore.sastoqnie] = true;

        zaRazmestvane sNulataNalqvo = nulataNalqvo(naiOtgore.sastoqnie);
        zaRazmestvane sNulataNadqsno = nulataNadqsno(naiOtgore.sastoqnie);
        zaRazmestvane sNulataNagore = nulataNagore(naiOtgore.sastoqnie);
        zaRazmestvane sNulataNadolu = nulaaNadolu(naiOtgore.sastoqnie);

        int segashnaDalbochina = dalbochina[naiOtgore.sastoqnie];

        if(visited[sNulataNalqvo.nov] == false){
            dalbochina[sNulataNalqvo.nov] = segashnaDalbochina + 1;
            vector<int> segashenPat = naiOtgore.pat;
            segashenPat.push_back(sNulataNalqvo.premestenotoChislo);
            int novoDoPodrezhdane = kolkoHodaOstavatDoPodrezhdane(sNulataNalqvo.nov);
            q.push({sNulataNalqvo.nov, segashenPat, novoDoPodrezhdane});
        }
        if(visited[sNulataNadqsno.nov] == false){
            dalbochina[sNulataNadqsno.nov] = segashnaDalbochina + 1;
            vector<int> segashenPat = naiOtgore.pat;
            segashenPat.push_back(sNulataNadqsno.premestenotoChislo);
            int novoDoPodrezhdane = kolkoHodaOstavatDoPodrezhdane(sNulataNadqsno.nov);
            q.push({sNulataNadqsno.nov, segashenPat, novoDoPodrezhdane});
        }
        if(visited[sNulataNagore.nov] == false){
            dalbochina[sNulataNagore.nov] = segashnaDalbochina + 1;
            vector<int> segashenPat = naiOtgore.pat;
            segashenPat.push_back(sNulataNagore.premestenotoChislo);
            int novoDoPodrezhdane = kolkoHodaOstavatDoPodrezhdane(sNulataNagore.nov);
            q.push({sNulataNagore.nov, segashenPat, novoDoPodrezhdane});
        }
        if(visited[sNulataNadolu.nov] == false){
            dalbochina[sNulataNadolu.nov] = segashnaDalbochina + 1;
            vector<int> segashenPat = naiOtgore.pat;
            segashenPat.push_back(sNulataNadolu.premestenotoChislo);
            int novoDoPodrezhdane = kolkoHodaOstavatDoPodrezhdane(sNulataNadolu.nov);
            q.push({sNulataNadolu.nov, segashenPat, novoDoPodrezhdane});
        }

    }

    return zaKolkoHoda;
}

int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int tukashnaStoinost;
            cin>>tukashnaStoinost;
            nachalen.push_back(tukashnaStoinost);
        }
    }

    otgovora zaKolkoHoda = bfs();

    cout<<zaKolkoHoda.kolkoHoda<<endl;

    for(int i = 0; i < zaKolkoHoda.hodove.size(); i++){
        cout<<zaKolkoHoda.hodove[i]<<" ";
    }

    cout<<endl;

    return 0;
}
