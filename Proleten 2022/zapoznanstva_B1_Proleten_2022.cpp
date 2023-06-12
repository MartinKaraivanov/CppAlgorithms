#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

set<int> sasedstvo[100010];

set<int> poznati[100010];

int broiVarhove;
int broiRebra;

int podKolkoLek;

bool golqmLiE(int koiVrah){
    return (int)sasedstvo[koiVrah].size() >= podKolkoLek;
}

void initialize(int ID, int N, int M, int Q, vector<pair<int, int> > friendships){

    broiVarhove = N;
    broiRebra = M;

    podKolkoLek = sqrt(M) + 1;

    for(int i = 0; i < (int)friendships.size(); i++){
        sasedstvo[friendships[i].first].insert(friendships[i].second);
        sasedstvo[friendships[i].second].insert(friendships[i].first);
    }

    for(int i = 1; i <= N; i++){
        if(golqmLiE(i)){
            for(set<int>::iterator j = sasedstvo[i].begin(); j != sasedstvo[i].end(); j++){
                //if(golqmLiE(*j)){
                    poznati[i].insert(sasedstvo[*j].begin(), sasedstvo[*j].end());
                //}
            }
            poznati[i].erase(i);
        }
    }
}

void connect(int ID, int x, int y){
    sasedstvo[x].insert(y);
    sasedstvo[y].insert(x);

    if(golqmLiE(x)){
        for(set<int>::iterator j = sasedstvo[x].begin(); j != sasedstvo[x].end(); j++){
            //if(golqmLiE(*j)){
                //poznati[x].insert(sasedstvo[*j].begin(), sasedstvo[*j].end());
            for(set<int>::iterator i = sasedstvo[*j].begin(); i != sasedstvo[*j].end(); i++){
                poznati[x].insert(*i);
                if(*i != x){
                    poznati[*i].insert(x);
                }
            }
            //}
        }
        poznati[x].erase(x);
    }

    if(golqmLiE(y)){
        for(set<int>::iterator j = sasedstvo[y].begin(); j != sasedstvo[y].end(); j++){
            //if(golqmLiE(*j)){
                //poznati[y].insert(sasedstvo[*j].begin(), sasedstvo[*j].end());
            for(set<int>::iterator i = sasedstvo[*j].begin(); i != sasedstvo[*j].end(); i++){
                poznati[y].insert(*i);
                if(*i != y){
                    poznati[*i].insert(y);
                }
            }
            //}
        }
        poznati[y].erase(y);
    }
}

bool question(int ID, int x, int y){

    bool xLekLiE = !golqmLiE(x);
    bool yLekLiE = !golqmLiE(y);

    bool okLiE = false;

    if(xLekLiE && yLekLiE){
        set<int>::iterator naParviq = sasedstvo[x].begin();
        set<int>::iterator naVtoriq = sasedstvo[y].begin();

        while(naParviq != sasedstvo[x].end() && naVtoriq != sasedstvo[y].end()){
            if(*naParviq == *naVtoriq){
                okLiE = true;
                break;
            }else{
                if(*naParviq < *naVtoriq){
                    naParviq++;
                }else{
                    naVtoriq++;
                }
            }
        }

    }else{
        if(xLekLiE && !yLekLiE){
            for(set<int>::iterator i = sasedstvo[x].begin(); i != sasedstvo[x].end(); i++){
                if(sasedstvo[y].find(*i) != sasedstvo[y].end()){
                    okLiE = true;
                    break;
                }
            }
        }else{
            if(!xLekLiE && yLekLiE){
                for(set<int>::iterator i = sasedstvo[y].begin(); i != sasedstvo[y].end(); i++){
                    if(sasedstvo[x].find(*i) != sasedstvo[x].end()){
                        okLiE = true;
                        break;
                    }
                }
            }else{
                okLiE = poznati[x].find(y) != poznati[x].end();
            }
        }
    }

    return okLiE;
}


