#include<iostream>
using namespace std;

int broiGradove;
int broiOtsechki;
int broiObazhdaniq;

bool sasedstvo[15500][15500];
bool otgovori[105000];
int broiOtgovori;
bool visited[11000];

void nulirane(){
    for(int i=1;i<=broiGradove;i++){
        visited[i]=false;
    }
}

void DFS(int vrah){
    if(visited[vrah]==false){
        visited[vrah] = true;
        for(int i=1; i<=broiGradove;i++){
            if(sasedstvo[vrah][i]==true){
                DFS(i);
            }
        }
    }
}

int main(){
    cin>>broiGradove>>broiOtsechki;

    for(int i=0;i<broiOtsechki;i++){
        int otgrad;
        int dograd;

        cin>>otgrad>>dograd;

        sasedstvo[otgrad][dograd] = true;
        sasedstvo[dograd][otgrad] = true;
    }

    cin>>broiObazhdaniq;

    for(int i =0;i<broiObazhdaniq;i++){
        int vidObazhdane;
        int otgrad;
        int dograd;

        cin>>vidObazhdane>>otgrad>>dograd;

        if(vidObazhdane==1){
            DFS(otgrad);
            otgovori[broiOtgovori]=visited[dograd];
            broiOtgovori++;
            nulirane();
        }else{
            if(vidObazhdane==2){
                sasedstvo[otgrad][dograd] = false;
                sasedstvo[dograd][otgrad] = false;
            }else{
                if(vidObazhdane==3){
                    sasedstvo[otgrad][dograd] = true;
                    sasedstvo[dograd][otgrad] = true;
                }
            }
        }
    }

    for(int i =0;i<broiOtgovori;i++){
        cout<<otgovori[i];
    }

    cout<<endl;

    return 0;
}
