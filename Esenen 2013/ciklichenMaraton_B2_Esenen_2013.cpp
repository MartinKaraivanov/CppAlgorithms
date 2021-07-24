#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct DanniZaIzprevarvaneto{
    int koiIzprevarva;
    int koiEIzprevaren;
    double sledKolkoVreme;

    DanniZaIzprevarvaneto(int koiIzprevarva, int koiEIzprevaren, double sledKolkoVreme)
        :koiIzprevarva(koiIzprevarva), koiEIzprevaren(koiEIzprevaren), sledKolkoVreme(sledKolkoVreme)
    {

    }

};

struct koiPravShteEIzprevaren{
    bool operator()(DanniZaIzprevarvaneto const& a, DanniZaIzprevarvaneto const& b){
        return a.sledKolkoVreme > b.sledKolkoVreme;
    }
};

int broiSastezateli;
int dalzhinaNaPistata;

int razstOtStarta[500010];
double skorost[500010];

bool toziIzlqzalLiE[500010];

int koiEPredNego[500010];

priority_queue<DanniZaIzprevarvaneto, vector<DanniZaIzprevarvaneto>, koiPravShteEIzprevaren> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSastezateli>>dalzhinaNaPistata;

    for(int i = 0; i < broiSastezateli; i++){
        cin>>razstOtStarta[i]>>skorost[i];
    }

    for(int i = 0; i < broiSastezateli; i++){
        int j = i + 1;

        if(j >= broiSastezateli){
            j = 0;
        }

        int razstMezhduTqh = razstOtStarta[j] - razstOtStarta[i];
        if(razstMezhduTqh < 0){
            razstMezhduTqh += dalzhinaNaPistata;
        }

        double razlikaVSkorostite = skorost[i] - skorost[j];

        double zaKolkoVreme = -1;

        if(razlikaVSkorostite > 0){
            zaKolkoVreme = razstMezhduTqh/razlikaVSkorostite;
        }else{
            if(razlikaVSkorostite == 0){
                zaKolkoVreme = 0;
            }else{
                zaKolkoVreme = -1;
            }
        }

        q.push({i, j, zaKolkoVreme});
        koiEPredNego[i] = j;
    }



    while(q.empty() == false){
        DanniZaIzprevarvaneto naiOtpred = q.top();
        q.pop();
        //cout<<naiOtpred.koiIzprevarva<<" "<<naiOtpred.koiEIzprevaren<<" "<<naiOtpred.sledKolkoVreme<<endl;
        if(naiOtpred.sledKolkoVreme > 0 &&
           toziIzlqzalLiE[naiOtpred.koiEIzprevaren] == false &&
           toziIzlqzalLiE[naiOtpred.koiIzprevarva] == false)
        {
            toziIzlqzalLiE[naiOtpred.koiEIzprevaren] = true;
            cout<<naiOtpred.koiEIzprevaren + 1<<endl;



            koiEPredNego[naiOtpred.koiIzprevarva] = koiEPredNego[naiOtpred.koiEIzprevaren];
            int sledvashtZaGonene = koiEPredNego[naiOtpred.koiIzprevarva];

            int razstMezhduTqh = razstOtStarta[sledvashtZaGonene] - razstOtStarta[naiOtpred.koiIzprevarva];
            if(razstMezhduTqh < 0){
                razstMezhduTqh += dalzhinaNaPistata;
            }

            double razlikaVSkorostite = skorost[naiOtpred.koiIzprevarva] - skorost[sledvashtZaGonene];

            double zaKolkoVreme = -1;

            if(razlikaVSkorostite > 0){
                zaKolkoVreme = razstMezhduTqh/razlikaVSkorostite;
            }else{
                if(razlikaVSkorostite == 0){
                    zaKolkoVreme = 0;
                }else{
                    zaKolkoVreme = -1;
                }
            }

            q.push({naiOtpred.koiIzprevarva, sledvashtZaGonene, zaKolkoVreme});
        }
    }

    cout<<"Winner(s): ";

    for(int i = 0; i < broiSastezateli; i++){
        if(toziIzlqzalLiE[i] == false){
            cout<<i+1<<" ";
        }
    }

    cout<<endl;

    return 0;
}
