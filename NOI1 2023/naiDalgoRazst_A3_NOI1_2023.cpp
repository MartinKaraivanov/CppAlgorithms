#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

int broiTochki;

int x[2048];
int y[2048];

struct DanniZaSaseda{
    int koiE;
    int razst;
};

vector<DanniZaSaseda> sasedstvo[2048];

struct DanniZaOpashkata{
    int doKoi;
    int razst;

    DanniZaOpashkata(int doKoi, int razst)
        : doKoi(doKoi), razst(razst)
    {

    }
};

struct koiEPonapred{
    bool operator()(DanniZaOpashkata const& a, DanniZaOpashkata const& b)
    {
        return a.razst > b.razst;
    }
};

int naiKasPatOtDo[2048][2048];
bool imameLiNaiKasPat[2048][2048];

int doKolkoImameNaiKas = 0;

priority_queue<DanniZaOpashkata, vector<DanniZaOpashkata>, koiEPonapred> q;

void bfs(int start){
    while(q.empty() == false){
        q.pop();
    }
    q.push({start, 0});
    doKolkoImameNaiKas = 0;

    while(q.empty() == false){
        DanniZaOpashkata naiOtpred = q.top();
        q.pop();

        if(imameLiNaiKasPat[start][naiOtpred.doKoi] == true){
            continue;
        }
        naiKasPatOtDo[start][naiOtpred.doKoi] = naiOtpred.razst;
        imameLiNaiKasPat[start][naiOtpred.doKoi] = true;
        doKolkoImameNaiKas++;

        if(doKolkoImameNaiKas == broiTochki){
            //cout<<broiTochki<<" "<<doKolkoImameNaiKas<<endl;
            return ;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred.doKoi].size(); i++){
            if(imameLiNaiKasPat[start][sasedstvo[naiOtpred.doKoi][i].koiE] == false){
                q.push({sasedstvo[naiOtpred.doKoi][i].koiE, naiOtpred.razst + sasedstvo[naiOtpred.doKoi][i].razst});
            }
        }

    }
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin>>broiTochki;

    for(int i = 0; i < broiTochki; i++){
        cin>>x[i]>>y[i];
    }

    for(int i = 0; i < broiTochki; i++){
        for(int j = i + 1; j < broiTochki; j++){
            if(x[i] == x[j] || y[i] == y[j]){
                int razst = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                sasedstvo[i].push_back({j, razst});
                sasedstvo[j].push_back({i, razst});
            }
        }
    }

    for(int i = 0; i < broiTochki; i++){
        bfs(i);
    }

    int naiDalgiq = 0;

    for(int i = 0; i < broiTochki; i++){
        for(int j = 0; j < broiTochki; j++){
            naiDalgiq = max(naiDalgiq, naiKasPatOtDo[i][j]);
        }
    }

    cout<<naiDalgiq<<endl;

    return 0;
}
