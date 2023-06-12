#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaSaseda{
    int doKoi;
    int razstoqnie;
};

vector<DanniZaSaseda> sasedstvo[1024];

int broiVarhove;
int broiRebra;

struct DanniZaSledvashtiq{
    int koiE;
    int razstoqnieDoNego;

    DanniZaSledvashtiq(int koiE, int razstoqnieDoNego)
        : koiE(koiE), razstoqnieDoNego(razstoqnieDoNego)
    {

    }
};

struct koiEPoNapred{
    bool operator()(DanniZaSledvashtiq const& a, DanniZaSledvashtiq const& b)
    {
        return a.razstoqnieDoNego < b.razstoqnieDoNego;
    }
};

int naiDalagPatDo[1024];

void nameriNaiDalgiqtPat(){

    priority_queue<DanniZaSledvashtiq, vector<DanniZaSledvashtiq>, koiEPoNapred> q;

    q.push({1, 0});

    while(q.empty() == false){
        DanniZaSledvashtiq naiOtgore = q.top();
        q.pop();

        for(int i = 0; i < (int)sasedstvo[naiOtgore.koiE].size(); i++){
            int sledvashtoRazstoqnie = naiOtgore.razstoqnieDoNego + sasedstvo[naiOtgore.koiE][i].razstoqnie;
            int sledvashtVrah = sasedstvo[naiOtgore.koiE][i].doKoi;

            if(sledvashtoRazstoqnie > naiDalagPatDo[sledvashtVrah]){
                naiDalagPatDo[sledvashtVrah] = sledvashtoRazstoqnie;

                q.push({sledvashtVrah, sledvashtoRazstoqnie});
            }
        }

    }

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>broiVarhove>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        int daljina;

        cin>>otKade>>doKade>>daljina;

        sasedstvo[otKade].push_back({doKade, daljina});
    }

    nameriNaiDalgiqtPat();

    int naiDalgiqtPat = 0;

    for(int i = 1; i <= broiVarhove; i++){
        //cout<<i<<" "<<naiDalagPatDo[i]<<endl;
        naiDalgiqtPat = max(naiDalgiqtPat, naiDalagPatDo[i]);
    }

    cout<<naiDalgiqtPat<<endl;

    return 0;
}
