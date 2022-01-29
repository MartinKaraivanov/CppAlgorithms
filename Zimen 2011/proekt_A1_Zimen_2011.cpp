#include<iostream>
#include<vector>
using namespace std;

int broiVarhove;
int broiRebra;

struct DanniZaRebro{
    int otKade;
    int doKade;
    int daljina;
};

vector<DanniZaRebro> rebra;

int naiMalkoDo[1111];

const int mnogo = 1000000007;

void fordBellman(){

    for(int i = 1; i <= broiVarhove; i++){
        naiMalkoDo[i] = mnogo;
    }
    naiMalkoDo[0] = 0;

    bool pravimLiNeshto = true;

    while(pravimLiNeshto == true){
        pravimLiNeshto = false;

        for(int j = 0; j < broiRebra; j++){
            if(naiMalkoDo[rebra[j].otKade] < mnogo){
                if(naiMalkoDo[rebra[j].doKade] > naiMalkoDo[rebra[j].otKade] + rebra[j].daljina){
                    naiMalkoDo[rebra[j].doKade] = naiMalkoDo[rebra[j].otKade] + rebra[j].daljina;
                    pravimLiNeshto = true;
                }
            }
        }

    }
}

int main(){
    cin>>broiVarhove>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        int doKade;
        int otKade;
        int weight;
        cin>>doKade>>otKade>>weight;

        rebra.push_back({otKade, doKade, weight});
    }

    for(int i = 1; i <= broiVarhove; i++){
        rebra.push_back({0, i, 0});
    }

    broiRebra = rebra.size();

    fordBellman();

    int naiMalkoto = mnogo;

    for(int i = 1; i <= broiVarhove; i++){
        naiMalkoto = min(naiMalkoto, naiMalkoDo[i]);
    }

    for(int i = 1; i <= broiVarhove; i++){
        cout<<naiMalkoDo[i] - naiMalkoto<<" ";
    }
    cout<<endl;

    return 0;
}
