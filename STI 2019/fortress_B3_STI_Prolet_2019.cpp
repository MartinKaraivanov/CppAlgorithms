#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int broiVarhove;
int broiRebra;

int kolkoNaiKasiPatq;

struct DanniZaSaseda{
    int koiE;
    int razstoqnie;

    DanniZaSaseda(int koiE, int razstoqnie)
        : koiE(koiE), razstoqnie(razstoqnie)
    {

    }
};

struct KoiEPoBlizko{
    bool operator()(DanniZaSaseda const& a, DanniZaSaseda const& b)
    {
        return a.razstoqnie > b.razstoqnie;
    }
};

vector<DanniZaSaseda> sasedstvo[10010];

int kolkoNaiKasiPatqImameDo[10010];

vector<int> naiKasiPatishtaDoFinala;

void dijkstra(){
    priority_queue<DanniZaSaseda, vector<DanniZaSaseda>, KoiEPoBlizko> naiMalkiPatishta;

    naiMalkiPatishta.push({1, 0});

    while(naiMalkiPatishta.empty() == false){
        DanniZaSaseda naiOtpred = naiMalkiPatishta.top();
        naiMalkiPatishta.pop();
        //cout<<"sega sme na "<<naiOtpred.koiE<<" s razst "<<naiOtpred.razstoqnie<<endl;

        kolkoNaiKasiPatqImameDo[naiOtpred.koiE]++;

        if(naiOtpred.koiE == broiVarhove){
            //cout<<"tova e tozi koito iskame"<<endl;
            naiKasiPatishtaDoFinala.push_back(naiOtpred.razstoqnie);
            if(kolkoNaiKasiPatqImameDo[naiOtpred.koiE] == kolkoNaiKasiPatq){
                break;
            }
        }

        if(kolkoNaiKasiPatqImameDo[naiOtpred.koiE] > kolkoNaiKasiPatq){
            continue;
        }

        for(int i = 0; i < sasedstvo[naiOtpred.koiE].size(); i++){
            DanniZaSaseda sledvasht = sasedstvo[naiOtpred.koiE][i];
            if(kolkoNaiKasiPatqImameDo[sledvasht.koiE] <= kolkoNaiKasiPatq){
                //cout<<"sega puskame za "<<sledvasht.koiE<<" s razst "<<naiOtpred.razstoqnie + sledvasht.razstoqnie<<endl;
                naiMalkiPatishta.push({sledvasht.koiE, naiOtpred.razstoqnie + sledvasht.razstoqnie});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiVarhove>>broiRebra>>kolkoNaiKasiPatq;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        int razst;

        cin>>otKade>>doKade>>razst;

        sasedstvo[otKade].push_back({doKade, razst});
        sasedstvo[doKade].push_back({otKade, razst});
    }

    dijkstra();

    for(int i = 0; i < naiKasiPatishtaDoFinala.size(); i++){
        cout<<naiKasiPatishtaDoFinala[i]<<" ";
    }

    cout<<endl;

    return 0;
}
