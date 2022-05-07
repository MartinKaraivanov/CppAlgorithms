#include<iostream>
#include<queue>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

int broiVarhove;
int broiLipsvashti;

unordered_set<int> lipsvashti[10010];

int broiPitaniq;

struct DanniZaPitane{
    int otKade;
    int doKade;
    int originalenNomer;
};

DanniZaPitane pitaniq[1000010];

struct DanniZaPoseshtenie{
    int vrah;
    int razstoqnie;
};

bool koePitaneEPoNapred(DanniZaPitane a, DanniZaPitane b){
    return a.otKade < b.otKade;
}

int naiKasoDo[10010];

void daljinaPatOt(int otKade){

    unordered_set<int> neposeteni;

    for(int i = 0; i < broiVarhove; i++){
        naiKasoDo[i] = -1;
        neposeteni.insert(i);
    }

    queue<DanniZaPoseshtenie> q;
    q.push({otKade, 0});
    naiKasoDo[otKade] = 0;
    neposeteni.erase(otKade);

    while(q.empty() == false){
        DanniZaPoseshtenie naiOtgore = q.front();
        q.pop();

        unordered_set<int>::iterator i = neposeteni.begin();
        while(i != neposeteni.end()){
            if(naiKasoDo[*i] == -1 && lipsvashti[naiOtgore.vrah].find(*i) == lipsvashti[naiOtgore.vrah].end()){
                naiKasoDo[*i] = naiOtgore.razstoqnie + 1;
                q.push({*i, naiOtgore.razstoqnie + 1});
                neposeteni.erase(i++);
            }else{
                i++;
            }
        }
    }
}

int otgovori[1000010];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove>>broiLipsvashti;

    for(int i = 0; i < broiLipsvashti; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        lipsvashti[otKade].insert(doKade);
        lipsvashti[doKade].insert(otKade);
    }

    cin>>broiPitaniq;

    for(int i = 0; i < broiPitaniq; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        int razmerOtKade = lipsvashti[otKade].size();
        int razmerDoKade = lipsvashti[doKade].size();

        if(razmerOtKade < razmerDoKade){
            swap(otKade, doKade);
        }else{
            if(razmerOtKade == razmerDoKade && otKade > doKade){
                swap(otKade, doKade);
            }
        }

        pitaniq[i] = {otKade, doKade, i};
    }

    sort(pitaniq, pitaniq + broiPitaniq, koePitaneEPoNapred);

    int predno = -1;

    for(int i = 0; i < broiPitaniq; i++){
        if(pitaniq[i].otKade == pitaniq[i].doKade){
            otgovori[pitaniq[i].originalenNomer] = 0;
        }else{
            if(lipsvashti[pitaniq[i].otKade].find(pitaniq[i].doKade) == lipsvashti[pitaniq[i].otKade].end()){
                otgovori[pitaniq[i].originalenNomer] = 1;
            }else{
                if((int)lipsvashti[pitaniq[i].otKade].size() < broiVarhove/2 && (int)lipsvashti[pitaniq[i].doKade].size() < broiVarhove/2){
                    otgovori[pitaniq[i].originalenNomer] = 2;
                }else{
                    if(pitaniq[i].otKade != predno){
                        daljinaPatOt(pitaniq[i].otKade);
                    }

                    otgovori[pitaniq[i].originalenNomer] = naiKasoDo[pitaniq[i].doKade];
                    predno = pitaniq[i].otKade;
                }
            }
        }
    }

    for(int i = 0; i < broiPitaniq; i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
