#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaSastoqnieto{
    int segashnaTochka;
    int izminatoRazstoqnie;
    vector<int> sastoqnirNaTochkite;

    DanniZaSastoqnieto(int segashnaTochka, int izminatoRazstoqnie, vector<int> sastoqnirNaTochkite)
        : segashnaTochka(segashnaTochka), izminatoRazstoqnie(izminatoRazstoqnie), sastoqnirNaTochkite(sastoqnirNaTochkite)
    {

    }
};

struct KoeESPoMalkoRazstoqnie{
    bool operator()(DanniZaSastoqnieto const& a, DanniZaSastoqnieto const& b)
    {
        return a.izminatoRazstoqnie > b.izminatoRazstoqnie;
    }
};

int n;
DanniZaTochka tochki[20];

int razstoqnieMejduDveTochki(int parva, int vtora){
    return max(abs(tochki[parva].x - tochki[vtora].x), abs(tochki[parva].y - tochki[vtora].y));
}

int nujenBroiSkokove(){
    priority_queue<DanniZaSastoqnieto, vector<DanniZaSastoqnieto>, KoeESPoMalkoRazstoqnie> q;

    vector<int> nachalno;
    for(int i = 0; i <= 2*n; i++){
        nachalno.push_back(0);
    }

    q.push({0, 0, nachalno});

    int izminatiqPat = 0;

    while(q.empty() == false){
        DanniZaSastoqnieto naiOtgore = q.top();
        q.pop();

        int sborTuka = 0;

        for(int i = 0; i <= 2*n; i++){
            sborTuka += naiOtgore.sastoqnirNaTochkite[i];
        }

        //cout<<naiOtgore.segashnaTochka<<" "<<naiOtgore.izminatoRazstoqnie<<" "<<sborTuka<<endl;

        if(sborTuka == n){
            izminatiqPat = naiOtgore.izminatoRazstoqnie;
            break;
        }

        for(int i = 1; i <= 2*n; i++){
            if(i != naiOtgore.segashnaTochka && naiOtgore.sastoqnirNaTochkite[i] == 0){
                vector<int> novoSastoqnie = naiOtgore.sastoqnirNaTochkite;
                novoSastoqnie[i] = 1;

                q.push({i, naiOtgore.izminatoRazstoqnie + razstoqnieMejduDveTochki(naiOtgore.segashnaTochka, i), novoSastoqnie});
            }
        }

    }

    return izminatiqPat;
}

int main(){
    cin>>n;

    tochki[0] = {0, 0};

    for(int i = 1; i <= 2*n; i++){
        cin>>tochki[i].x>>tochki[i].y;
    }

    int izminatiqtPat = nujenBroiSkokove();

    cout<<izminatiqtPat<<endl;

    return 0;
}
