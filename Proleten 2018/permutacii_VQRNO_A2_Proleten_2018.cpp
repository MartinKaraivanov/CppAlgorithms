#include<iostream>
using namespace std;


const int mnogo = 1000000007;

int broiChisla;

int chisla[1000010];

bool visited[1000010];

int cycliSDalj[1000010];

long long factoriel[1000010];

int daljinaCikal(int vrah){
    int dalj = 0;

    while(visited[vrah] == false){
        visited[vrah] = true;
        dalj++;
        vrah = chisla[vrah];
    }

    return dalj;
}

long long barzoStepenuvane(long long chi, long long stepen){
    long long rez = 1;

    while(stepen > 0){
        if((stepen & 1) == 1){
            rez = (rez * chi) % mnogo;
        }

        chi = (chi * chi) % mnogo;

        stepen >>= 1;
    }

    return rez;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiChisla;

    for(int i = 0; i < broiChisla; i++){
        cin>>chisla[i];
        chisla[i]--;
    }

    for(int i = 0; i < broiChisla; i++){
        if(visited[i] == false){
            int dalj = daljinaCikal(i);
            cycliSDalj[dalj]++;
        }
    }

    factoriel[0] = 1;

    for(int i = 1; i <= broiChisla; i++){
        factoriel[i] = (factoriel[i-1] * i)%mnogo;
    }

    long long broi = 1;

    for(int i = 1; i <= broiChisla; i++){
        int brCicli = cycliSDalj[i];

        //cout<<"b "<<factoriel[brCicli]<<" "<<barzoStepenuvane(i, brCicli)<<endl;

        broi *= (factoriel[brCicli] * barzoStepenuvane(i, brCicli)) % mnogo;
        broi %= mnogo;
    }

    cout<<broi<<endl;


    return 0;
}
