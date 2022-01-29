#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int broiKoncerti;
int broiIzpalneniq;

struct DanniZaIzpalnenie{
    int start;
    int krai;
};

DanniZaIzpalnenie izpalneniq[200010];

vector<int> sasedstvo[400010];

stack<int> s;

bool visited[400010];
bool reverseVisited[400010];

int whichSCC[400010];
int sccCounter;

void dfs(int current){
    if(visited[current] == true){
        return ;
    }

    visited[current] = true;

    for(int i = 0; i < (int)sasedstvo[current].size(); i++){
        if(visited[sasedstvo[current][i]] == false){
            dfs(sasedstvo[current][i]);
        }
    }

    s.push(current);
}

void reverseDfs(int current){
    if(reverseVisited[current] == true){
        return ;
    }

    cout<<"sega sme v "<<current<<" i she go slojim da e ot scc "<<sccCounter<<endl;

    reverseVisited[current] = true;

    for(int i = 0; i < (int)sasedstvo[current].size(); i++){
        if(reverseVisited[sasedstvo[current][i]] == false){
            cout<<"sega ouskame ot "<<current<<" za "<<sasedstvo[current][i]<<endl;
            reverseDfs(sasedstvo[current][i]);
        }
    }

    whichSCC[current] = sccCounter;
}

void solve(){

    for(int i = 0; i < 2*broiIzpalneniq; i++){
        if(visited[i] == false){
            dfs(i);
        }
    }

    while(s.empty() == false){
        int naiOtgore = s.top();
        s.pop();

        if(reverseVisited[naiOtgore] == false){
            cout<<"sega nai otgore e "<<naiOtgore<<" i puskame dfsto"<<endl;

            sccCounter++;
            reverseDfs(naiOtgore);
        }
    }

    bool mojeLi = true;

    for(int i = 0; i < broiIzpalneniq; i++){
        if(whichSCC[i] == whichSCC[i + broiIzpalneniq]){
            cout<<i<<"e v sushtiq komponent kato obratniq si"<<endl;
            mojeLi = false;
            break;
        }
    }

    if(mojeLi == false){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}

int main(){
    cin>>broiKoncerti;

    for(int i = 0; i < broiKoncerti; i++){
        cin>>izpalneniq[i*2].start>>izpalneniq[i*2].krai>>izpalneniq[i*2 + 1].start>>izpalneniq[i*2 + 1].krai;
    }

    broiIzpalneniq = 2*broiKoncerti;

    for(int i = 0; i < broiIzpalneniq; i++){
        for(int j = (i/2 + 1)*2; j < broiIzpalneniq; j++){
            cout<<"sega proverqvame za "<<i<<" i "<<j<<endl;
            if((izpalneniq[i].start <= izpalneniq[j].start && izpalneniq[i].krai >= izpalneniq[j].start) ||
                (izpalneniq[i].start <= izpalneniq[j].krai && izpalneniq[i].krai >= izpalneniq[j].krai) ||
                (izpalneniq[j].start <= izpalneniq[i].start && izpalneniq[j].krai >= izpalneniq[i].start) ||
                (izpalneniq[j].start <= izpalneniq[i].krai && izpalneniq[j].krai >= izpalneniq[i].krai))
            {
                cout<<"i te ne mogat zaedno"<<endl;

                sasedstvo[i].push_back(j + broiIzpalneniq);
                sasedstvo[j].push_back(i + broiIzpalneniq);
            }
        }

        if(i%2 == 0){
            sasedstvo[i + broiIzpalneniq].push_back(i + 1);
            sasedstvo[i + 1].push_back(i + broiIzpalneniq);
        }else{
            sasedstvo[i + broiIzpalneniq].push_back(i - 1);
            sasedstvo[i - 1].push_back(i + broiIzpalneniq);
        }
    }

    solve();

    return 0;
}
