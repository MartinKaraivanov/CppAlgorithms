#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaVarha{
    int nomer;
    int dalbochina;
};

int broiVarhove;
int broiRebra;

vector<int> sasedstvo[1005];

void bfs(int start, int dalbochini[1005]){
    bool visited[1005];
    for(int i = 0; i <= broiVarhove; i++){
        visited[i] = false;
    }

    queue<DanniZaVarha> q;
    DanniZaVarha nachalno = {start, 0};
    q.push(nachalno);

    while(q.empty() == false){
        DanniZaVarha naiOtpred = q.front();
        q.pop();

        if(visited[naiOtpred.nomer] == true){
            continue;
        }
        visited[naiOtpred.nomer] = true;
        dalbochini[naiOtpred.nomer] = naiOtpred.dalbochina;

        for(unsigned int i = 0; i < sasedstvo[naiOtpred.nomer].size(); i++){
            if(visited[sasedstvo[naiOtpred.nomer][i]] == false){
                q.push({sasedstvo[naiOtpred.nomer][i], naiOtpred.dalbochina + 1});
            }
        }
    }

}

void pravenenNaKoiSeOpuvat(int dalbochinaOtStancho[1005], int dalbochinaOtPesho[1005], int razstoqnieMezhduStanchoIPesho, bool koiSeOpuvat[1005]){
    for(int i = 1; i <= broiVarhove; i++){
        if(dalbochinaOtStancho[i] + dalbochinaOtPesho[i] == razstoqnieMezhduStanchoIPesho){
            koiSeOpuvat[i] = true;
        }
    }
}

int izchislqvaneNaVisqshtite(bool koiSeOpuvat[1005]){
    int broiche = 0;

    for(int i = 1; i <= broiVarhove; i++){
        if(koiSeOpuvat[i] == false){
            broiche++;
        }
    }

    return broiche;
}

void nulirane(int dalbochinaOtStancho[1005], int dalbochinaOtPesho[1005], bool koiSeOpuvat[1005]){
    for(int i = 0; i <= broiVarhove; i++){
        koiSeOpuvat[i] = false;
        dalbochinaOtPesho[i] = 0;
        dalbochinaOtStancho[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;
        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    int dalbochinaOtStancho[1005];
    int dalbochinaOtPesho[1005];

    bool koiSeOpuvat[1005];

    int razstoqnieMezhduStanchoIPesho;

    for(int i = 0; i < 2; i++){
        nulirane(dalbochinaOtStancho, dalbochinaOtPesho, koiSeOpuvat);

        int stancho;
        int pesho;
        cin>>stancho>>pesho;

        bfs(stancho, dalbochinaOtStancho);
        bfs(pesho, dalbochinaOtPesho);

        razstoqnieMezhduStanchoIPesho = dalbochinaOtStancho[pesho];
        pravenenNaKoiSeOpuvat(dalbochinaOtStancho, dalbochinaOtPesho, razstoqnieMezhduStanchoIPesho, koiSeOpuvat);

        int broiNeOpunati = izchislqvaneNaVisqshtite(koiSeOpuvat);

        cout<<broiNeOpunati<<" ";
    }

    cout<<endl;

    return 0;
}
