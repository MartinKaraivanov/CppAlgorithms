#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;

int broiDarjavi;
int broiPatishta;

struct DanniZaSaseda{
    int doKoi;
    int daljinaPat;
    int magicheskaSila;
};

vector<DanniZaSaseda> sasedstvo[2048];

bool visited[2048];

bool imaLiPatDoKraq(int nachalo, int krai){

    for(int i = 0; i <= broiDarjavi; i++){
        visited[i] = false;
    }

    //cout<<"qwerty"<<endl;

    queue<int> q;
    q.push(nachalo);

    while(q.empty() == false){
        int naiOtpred = q.front();
        q.pop();

        if(visited[naiOtpred] == true){
            continue;
        }

        visited[naiOtpred] = true;
        if(naiOtpred == krai){
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred].size(); i++){
            q.push(sasedstvo[naiOtpred][i].doKoi);
        }
    }

    return visited[krai];
}

struct DanniZaMomenta{
    int kadeSme;
    int izminatPat;

    DanniZaMomenta(int kadeSme, int izminatPat)
        : kadeSme(kadeSme), izminatPat(izminatPat)
    {

    }
};

struct koiEPoNapred{
    bool operator()(DanniZaMomenta const& a, DanniZaMomenta const& b)
    {
        return a.izminatPat > b.izminatPat;
    }
};

int naiKasPatDo[2048];

int naiKasiqPatDoKraq(int start, int krai){

    for(int i = 0; i <= broiDarjavi; i++){
        naiKasPatDo[i] = 1000000007;
    }

    priority_queue<DanniZaMomenta, vector<DanniZaMomenta>, koiEPoNapred> q;

    q.push({start, 0});

    while(q.empty() == false){
        DanniZaMomenta naiOtpred = q.top();
        q.pop();

        //cout<<naiOtpred.kadeSme<<" "<<naiOtpred.izminatPat<<endl;

        /*if(naiOtpred.izminatPat >= naiKasPatDo[krai]){
            break;
        }*/

        for(int i = 0; i < (int)sasedstvo[naiOtpred.kadeSme].size(); i++){
            int novPat = max(0, naiOtpred.izminatPat - sasedstvo[naiOtpred.kadeSme][i].magicheskaSila) + sasedstvo[naiOtpred.kadeSme][i].daljinaPat;
            if(naiKasPatDo[sasedstvo[naiOtpred.kadeSme][i].doKoi] > novPat){
                q.push({sasedstvo[naiOtpred.kadeSme][i].doKoi, novPat});
                naiKasPatDo[sasedstvo[naiOtpred.kadeSme][i].doKoi] = novPat;
            }
        }
    }

    return naiKasPatDo[krai];
}

int main(){

    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiDarjavi>>broiPatishta;*/

    scanf("%i %i", &broiDarjavi, &broiPatishta);

    for(int i = 0; i < broiPatishta; i++){
        int otKade;
        int doKade;
        int daljina;
        int magiq;

        //cin>>otKade>>doKade>>daljina>>magiq;

        scanf("%i %i %i %i", &otKade, &doKade, &daljina, &magiq);

        sasedstvo[doKade].push_back({otKade, daljina, magiq});
    }

    if(imaLiPatDoKraq(broiDarjavi, 1) == false){
        //cout<<-1<<endl;
        printf("-1 \n");
        return 0;
    }

    int otgovor = naiKasiqPatDoKraq(broiDarjavi, 1);

    //cout<<otgovor<<endl;

    printf("%i \n", otgovor);

    return 0;
}
