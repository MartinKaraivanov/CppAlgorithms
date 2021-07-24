#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaMqstoto{
    int kadeSme;
    int ostavashtiPari;
    int vremeDoTuk;

    DanniZaMqstoto(int kadeSme, int ostavashtiPari, int vremeDoTuk)
        : kadeSme(kadeSme), ostavashtiPari(ostavashtiPari), vremeDoTuk(vremeDoTuk)
    {
    }
};

struct koePoNapredSmeStignali{
    bool operator()(DanniZaMqstoto const& a, DanniZaMqstoto const& b)
    {
        return a.vremeDoTuk > b.vremeDoTuk;
    }
};

struct DanniZaSasedstvo{
    int doKoi;
    int vreme;
    int cena;
};

int nashiPari;
int broiMesta;
int broiPatishta;

vector<DanniZaSasedstvo> sasedstvo[3035];

bool visited[3035][2024];

int bfs(){
    priority_queue<DanniZaMqstoto, vector<DanniZaMqstoto>, koePoNapredSmeStignali> q;

    int zaVrasht = -1;

    q.push({1, nashiPari, 0});

    while(q.empty() == false){
        DanniZaMqstoto naiOtgore = q.top();
        q.pop();

        //cout<<naiOtgore.kadeSme<<" "<<naiOtgore.ostavashtiPari<<" "<<naiOtgore.vremeDoTuk<<endl;

        /*if(naiOtgore.ostavashtiPari < 0){
            continue;
        }*/

        if(visited[naiOtgore.kadeSme][naiOtgore.ostavashtiPari] == true){
            continue;
        }
        visited[naiOtgore.kadeSme][naiOtgore.ostavashtiPari] = true;

        if(naiOtgore.kadeSme == broiMesta){
            zaVrasht = naiOtgore.vremeDoTuk;
            break;
        }

        for(int i = 0; i < sasedstvo[naiOtgore.kadeSme].size(); i++){
            if(naiOtgore.ostavashtiPari - sasedstvo[naiOtgore.kadeSme][i].cena >= 0 &&
               !visited[sasedstvo[naiOtgore.kadeSme][i].doKoi][naiOtgore.ostavashtiPari - sasedstvo[naiOtgore.kadeSme][i].cena])
            {
                q.push({sasedstvo[naiOtgore.kadeSme][i].doKoi,
                       naiOtgore.ostavashtiPari - sasedstvo[naiOtgore.kadeSme][i].cena,
                       naiOtgore.vremeDoTuk + sasedstvo[naiOtgore.kadeSme][i].vreme});
            }
        }

    }

    return zaVrasht;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>nashiPari>>broiMesta>>broiPatishta;

    for(int i = 0; i < broiPatishta; i++){
        int otKade;
        int doKade;
        int kolkoVreme;
        int kolkoStruva;
        cin>>otKade>>doKade>>kolkoVreme>>kolkoStruva;

        sasedstvo[otKade].push_back({doKade, kolkoVreme, kolkoStruva});
        sasedstvo[doKade].push_back({otKade, kolkoVreme, kolkoStruva});
    }

    int naiBarzoStigane = bfs();

    cout<<naiBarzoStigane<<endl;

    return 0;
}
