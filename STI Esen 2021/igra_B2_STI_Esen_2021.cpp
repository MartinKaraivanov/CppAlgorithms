#include<iostream>
#include<queue>
using namespace std;

struct Koordinati{
    int y;
    int x;
};

int maxY;
int maxX;

Koordinati startDeni;
Koordinati startBobi;

int tablica[64][64];

/// POSOKI - 1 nagore, 2 nadqsno, 3 nadolu, 4 nalqvo
Koordinati premestiPionkata(Koordinati originalnaPoziciq, int posoka){
    if(posoka == 1){
        if(originalnaPoziciq.y > 0 && tablica[originalnaPoziciq.y - 1][originalnaPoziciq.x] == 0){
            return {originalnaPoziciq.y - 1, originalnaPoziciq.x};
        }else{
            return originalnaPoziciq;
        }
    }
    if(posoka == 2){
        if(originalnaPoziciq.x < maxX - 1 && tablica[originalnaPoziciq.y][originalnaPoziciq.x + 1] == 0){
            return {originalnaPoziciq.y, originalnaPoziciq.x + 1};
        }else{
            return originalnaPoziciq;
        }
    }
    if(posoka == 3){
        if(originalnaPoziciq.y < maxY - 1 && tablica[originalnaPoziciq.y + 1][originalnaPoziciq.x] == 0){
            return {originalnaPoziciq.y + 1, originalnaPoziciq.x};
        }else{
            return originalnaPoziciq;
        }
    }

    if(originalnaPoziciq.x > 0 && tablica[originalnaPoziciq.y][originalnaPoziciq.x - 1] == 0){
        return {originalnaPoziciq.y, originalnaPoziciq.x - 1};
    }else{
        return originalnaPoziciq;
    }
}

struct DanniZaMesteneto{
    Koordinati kadeENashtaPionka;
    Koordinati kadeEDrugataPionka;
    string hodoveDoTuk;
};

bool visited[64][64];

DanniZaMesteneto zavediPionkataVStarta(Koordinati startNasha, Koordinati startDruga){

    for(int i = 0; i <= maxY; i++){
        for(int x = 0; x <= maxX; x++){
            visited[i][x] = false;
        }
    }

    queue<DanniZaMesteneto> q;
    q.push({startNasha, startDruga, ""});

    DanniZaMesteneto zaVrashtane = {{-1, -1}, {-1, -1}, "-1"};

    visited[startNasha.y][startNasha.x] = true;

    while(q.empty() == false){
        DanniZaMesteneto naiOtpred = q.front();
        q.pop();

        if(naiOtpred.kadeENashtaPionka.y == 0 && naiOtpred.kadeENashtaPionka.x == 0){
            zaVrashtane = naiOtpred;
            break;
        }

        Koordinati nashaNagore = premestiPionkata(naiOtpred.kadeENashtaPionka, 1);
        if(visited[nashaNagore.y][nashaNagore.x] == false){
            visited[nashaNagore.y][nashaNagore.x] = true;
            q.push({nashaNagore, premestiPionkata(naiOtpred.kadeEDrugataPionka, 1), naiOtpred.hodoveDoTuk + "U"});
        }

        Koordinati nashaNadqsno = premestiPionkata(naiOtpred.kadeENashtaPionka, 2);
        if(visited[nashaNadqsno.y][nashaNadqsno.x] == false){
            visited[nashaNadqsno.y][nashaNadqsno.x] = true;
            q.push({nashaNadqsno, premestiPionkata(naiOtpred.kadeEDrugataPionka, 2), naiOtpred.hodoveDoTuk + "R"});
        }

        Koordinati nashaNadolu = premestiPionkata(naiOtpred.kadeENashtaPionka, 3);
        if(visited[nashaNadolu.y][nashaNadolu.x] == false){
            visited[nashaNadolu.y][nashaNadolu.x] = true;
            q.push({nashaNadolu, premestiPionkata(naiOtpred.kadeEDrugataPionka, 3), naiOtpred.hodoveDoTuk + "D"});
        }

        Koordinati nashaNalqvo = premestiPionkata(naiOtpred.kadeENashtaPionka, 4);
        if(visited[nashaNalqvo.y][nashaNalqvo.x] == false){
            visited[nashaNalqvo.y][nashaNalqvo.x] = true;
            q.push({nashaNalqvo, premestiPionkata(naiOtpred.kadeEDrugataPionka, 4), naiOtpred.hodoveDoTuk + "L"});
        }
    }

    return zaVrashtane;
}

int main(){

    cin>>maxY>>maxX>>startDeni.y>>startDeni.x>>startBobi.y>>startBobi.x;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cin>>tablica[y][x];
        }
    }

    string posoki = "";

    DanniZaMesteneto zavediEdiniq = zavediPionkataVStarta(startDeni, startBobi);
    startBobi = zavediEdiniq.kadeEDrugataPionka;
    DanniZaMesteneto zavediVtoriq = zavediPionkataVStarta(startBobi, startDeni);

    posoki += zavediEdiniq.hodoveDoTuk + zavediVtoriq.hodoveDoTuk;

    cout<<posoki.size()<<endl;

    cout<<posoki<<endl;

    return 0;
}
