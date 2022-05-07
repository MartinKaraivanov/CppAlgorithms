#include<iostream>
#include<vector>
using namespace std;

vector<int> sasedstvo[100010];

bool toziSasedLiE[100010];

int broiVarhove;

bool darvoLiE = false;

int momentNaVlizane[100010];
int momentNaIzlizane[100010];

int vreme;

int bashta[100010];

int dalbochina[100010];

void dfs(int segashenVrah, int dalb){
    vreme++;
    momentNaVlizane[segashenVrah] = vreme;

    dalbochina[segashenVrah] = dalb;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(dalbochina[sasedstvo[segashenVrah][i]] == 0){
            dfs(sasedstvo[segashenVrah][i], dalb + 1);
            bashta[sasedstvo[segashenVrah][i]] = segashenVrah;
        }
    }

    vreme++;
    momentNaIzlizane[segashenVrah] = vreme;
}

void initialize(int ID, int N, int M, int Q, vector<pair<int, int> > friendships){

    if(M < N){
        darvoLiE = true;
    }

    broiVarhove = N;

    for(int i = 0; i < (int)friendships.size(); i++){
        sasedstvo[friendships[i].first].push_back(friendships[i].second);
        sasedstvo[friendships[i].second].push_back(friendships[i].first);
    }

    if(darvoLiE == true){
        for(int i = 1; i <= broiVarhove; i++){
            if(dalbochina[i] == 0){
                dfs(i, 1);
            }
        }
    }

}

void connect(int ID, int x, int y){
    sasedstvo[x].push_back(y);
    sasedstvo[y].push_back(x);
}

bool question(int ID, int x, int y){
    if(darvoLiE == false){
        for(int i = 1; i <= broiVarhove; i++){
            toziSasedLiE[i] = false;
        }

        for(int i = 0; i < (int)sasedstvo[x].size(); i++){
            toziSasedLiE[sasedstvo[x][i]] = true;
        }

        bool stavaLi = false;

        for(int i = 0; i < (int)sasedstvo[y].size(); i++){
            if(toziSasedLiE[sasedstvo[y][i]] == true){
                stavaLi = true;
                break;
            }
        }

        return stavaLi;
    }

    if(dalbochina[x] > dalbochina[y]){
        swap(x, y);
    }

    if(dalbochina[x] == dalbochina[y] && bashta[x] == bashta[y]){
        return true;
    }

    if(dalbochina[y] - dalbochina[x] != 2){
        return false;
    }

    if(momentNaVlizane[x] < momentNaVlizane[y] && momentNaIzlizane[x] > momentNaIzlizane[y]){
        return true;
    }

    return false;
}


