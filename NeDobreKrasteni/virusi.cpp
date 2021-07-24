#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int m;
int n;

long long kletki[101][101];


struct Coordinati {
    int i;
    int j;
};


void ProveriZaVirusiSasStack(int i_nachalno, int j_nachalno, int virus) {
    // obhojdane v dalbochina
    stack<Coordinati> s;

    Coordinati nachalniCoordinati = {i_nachalno, j_nachalno};
    s.push(nachalniCoordinati);

    while (!s.empty()){
        Coordinati c = s.top();
        s.pop();

        if (kletki[c.i][c.j] == 0) {
            kletki[c.i][c.j] = virus;

            if((c.i>0)&&(kletki[c.i-1][c.j]==0)){
                Coordinati c_novo = {c.i-1, c.j};
                s.push(c_novo);
            }
            if( (c.i+1<n) && (kletki[c.i+1][c.j]==0) ){
                Coordinati c_novo = {c.i+1, c.j};
                s.push(c_novo);
            }
            if((c.j>0)&& (kletki[c.i][c.j-1]==0) ){
                Coordinati c_novo = {c.i, c.j-1};
                s.push(c_novo);
            }
            if( (c.j+1<m) && (kletki[c.i][c.j+1]==0) ){
                Coordinati c_novo = {c.i, c.j+1};
                s.push(c_novo);
            }
        }
    }
}


int main(){
    cin>>n>>m;

    long long broiZashtiteniKletki;
    cin>>broiZashtiteniKletki;

    long long redNaZashtita[broiZashtiteniKletki];
    long long kolonaNaZashtita[broiZashtiteniKletki];

    for(int i=0;i<broiZashtiteniKletki;i++){
        cin>>redNaZashtita[i]>>kolonaNaZashtita[i];
    }

    for(int i=0;i<broiZashtiteniKletki;i++){
        kletki[redNaZashtita[i]-1][kolonaNaZashtita[i]-1] = -1;
    }


    long long broiNuzhniVirusi=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(kletki[i][j]==0){
                broiNuzhniVirusi++;
                ProveriZaVirusiSasStack(i,j,broiNuzhniVirusi);
            }
        }
    }


    cout<<broiNuzhniVirusi<<endl;

    return 0;
}
