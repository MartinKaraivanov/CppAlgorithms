#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct DanniZaRebroRazstoqnie{
    int otKoi;
    int doKoi;
    int razstoqnie;

    DanniZaRebroRazstoqnie(int otKoi, int doKoi, int razstoqnie)
        :otKoi(otKoi), doKoi(doKoi), razstoqnie(razstoqnie)
    {

    }

};

struct poMalkoRazst{
    bool operator()(DanniZaRebroRazstoqnie const& a, DanniZaRebroRazstoqnie const& b){
        return a.razstoqnie > b.razstoqnie;
    }
};

struct DanniZaRazstoqnieto{
    int doKoi;
    int razstoqnie;
};

int broiModuli;
vector<DanniZaRazstoqnieto> razstoqniq[1030];

priority_queue<DanniZaRebroRazstoqnie, vector<DanniZaRebroRazstoqnie>, poMalkoRazst> q;

bool otGlavnotoLiE[1030];

vector<int> sasedstvo[1030];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiModuli;

    for(int i = 1; i <= broiModuli; i++){
        for(int j = i + 1; j <= broiModuli; j++){
            int razst;
            cin>>razst;
            razstoqniq[i].push_back({j, razst});
            razstoqniq[j].push_back({i, razst});
        }
    }

    otGlavnotoLiE[1] = true;
    for(unsigned int i = 0; i < razstoqniq[1].size(); i++){
        q.push({1, razstoqniq[1][i].doKoi, razstoqniq[1][i].razstoqnie});
    }

    int broiOtGlavnoto = 1;

    while(broiOtGlavnoto < broiModuli && q.empty() == false){
        DanniZaRebroRazstoqnie naiKaso = q.top();
        q.pop();

        if(otGlavnotoLiE[naiKaso.doKoi] == false){
            otGlavnotoLiE[naiKaso.doKoi] = true;
            broiOtGlavnoto++;

            for(unsigned int i = 0; i < razstoqniq[naiKaso.doKoi].size(); i++){
                if(otGlavnotoLiE[razstoqniq[naiKaso.doKoi][i].doKoi] == false){
                    q.push({naiKaso.doKoi, razstoqniq[naiKaso.doKoi][i].doKoi, razstoqniq[naiKaso.doKoi][i].razstoqnie});
                }
            }

            sasedstvo[naiKaso.otKoi].push_back(naiKaso.doKoi);
            sasedstvo[naiKaso.doKoi].push_back(naiKaso.otKoi);
        }

    }

    for(int i = 1; i <= broiModuli; i++){
        sort(sasedstvo[i].begin(), sasedstvo[i].end());

        cout<<sasedstvo[i].size();

        for(unsigned int j = 0; j < sasedstvo[i].size(); j++){
            cout<<" "<<sasedstvo[i][j];
        }

        cout<<endl;
    }

    return 0;
}
