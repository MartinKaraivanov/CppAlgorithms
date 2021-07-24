#include<iostream>
#include<stack>
using namespace std;

int broiKrastovishta;
int broiUlici;

bool sasedstvo[210][210];
int visited[210];

int domPesho;
int domGosho;
int stadion;
int shkola;

bool tablicaNaPeshko[210][210];
bool tablicaNaGoshko[210][210];

void popalvane(int zaKogo){
    for(int i = 0; i < broiKrastovishta; i++){
        if(visited[i] > 0){
            if(zaKogo == 1){
                tablicaNaPeshko[i][visited[i]]=true;
            }else{
                tablicaNaGoshko[i][visited[i]]=true;
            }
        }
    }
}

void pechatane(){
    cout<<endl;
    for(int i = 0; i < broiKrastovishta; i++){
        if(visited[i] > 0){
            cout<<i<<" "<<visited[i]<<endl;
        }
    }
}

void dfs(int vrah, int moment, int doKoiVrahIskameDaStignem, int zaKogo){
    if(visited[vrah] == 0){

        visited[vrah] = moment;

        if(vrah == doKoiVrahIskameDaStignem){

            //pechatane();
            popalvane(zaKogo);
        }else{
            for(int i = 0; i < broiKrastovishta; i++){
                if(sasedstvo[vrah][i]){
                    dfs(i, moment+1, doKoiVrahIskameDaStignem, zaKogo);

                }
            }
        }

        visited[vrah] = 0;
    }
}

int main(){
    cin>>broiKrastovishta>>broiUlici;

    for(int i = 0; i < broiUlici; i++){
        int otKr;
        int doKr;
        cin>>otKr>>doKr;
        sasedstvo[otKr][doKr] = true;
        sasedstvo[doKr][otKr] = true;
    }

    cin>>domPesho>>stadion>>domGosho>>shkola;

    dfs(domPesho, 1, stadion, 1);
    dfs(domGosho, 1, shkola, 2);



    int zasichaneBr = 0;

    for(int i = 0; i < broiKrastovishta; i++){
        for(int j = 0; j < broiKrastovishta; j++){
            if(tablicaNaGoshko[i][j]==true && tablicaNaPeshko[i][j]==true){
                zasichaneBr++;
                break;
            }
        }
    }

    cout<<zasichaneBr<<endl;

    return 0;
}
