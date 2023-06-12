#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

const long long mnogo = 3000000000001;

int broiVarhove;
int broiRebra;
int broiVzimame;

struct DanniZaSaseda{
    int koiE;
    long long razst;
};

vector<DanniZaSaseda> sasedstvo[3010];

struct DanniZaDoTuk{
    int vrah;
    int otKadeIdvame;
    long long totalRazst;
    map<int, int> magistrali;
    int broiMagistrali;

    DanniZaDoTuk(int vrah, int otKadeIdvame, long long totalRazst, map<int, int> magistrali, int broiMagistrali)
        :vrah(vrah), otKadeIdvame(otKadeIdvame), totalRazst(totalRazst), magistrali(magistrali), broiMagistrali(broiMagistrali)
    {

    }

};

struct KoiEPoNablizo{
    bool operator()(DanniZaDoTuk const& a, DanniZaDoTuk const& b)
    {
        return a.totalRazst > b.totalRazst;
    }
};


bool visited[3010][3010];

long long reshi(){
    priority_queue<DanniZaDoTuk, vector<DanniZaDoTuk>, KoiEPoNablizo> q;


    for(int i = 0; i < (int)sasedstvo[1].size(); i++){
        visited[1][sasedstvo[1][i].koiE] = true;
    }


    q.push({1, 0, 0, {}, 0});

    long long otgovor = -1;

    while(q.empty() == false){
        DanniZaDoTuk naiOtpred = q.top();
        q.pop();

        /*
        cout<<"sega sme vav vrah "<<naiOtpred.vrah<<" s razst "<<naiOtpred.totalRazst<<" sastoqshto se ot ";
        for(map<int, int>::iterator i = naiOtpred.magistrali.begin(); i != naiOtpred.magistrali.end(); i++){
            cout<<i->first<<"x"<<i->second<<" ";
        }
        cout<<endl;
        */

        if(naiOtpred.vrah == broiVarhove){
            otgovor = naiOtpred.totalRazst;
            break;
        }

        if(visited[naiOtpred.vrah][naiOtpred.otKadeIdvame] == true){
            continue;
        }
        visited[naiOtpred.vrah][naiOtpred.otKadeIdvame] = true;

        for(int i = 0; i < (int)sasedstvo[naiOtpred.vrah].size(); i++){
            if(sasedstvo[naiOtpred.vrah][i].koiE != naiOtpred.otKadeIdvame && visited[sasedstvo[naiOtpred.vrah][i].koiE][naiOtpred.vrah] == false){

                DanniZaDoTuk sledvasht =
                    {sasedstvo[naiOtpred.vrah][i].koiE,
                        naiOtpred.vrah,
                        naiOtpred.totalRazst + sasedstvo[naiOtpred.vrah][i].razst,
                        naiOtpred.magistrali,
                        naiOtpred.broiMagistrali + 1};
                sledvasht.magistrali[sasedstvo[naiOtpred.vrah][i].razst]++;


                if(sledvasht.broiMagistrali <= broiVzimame){

                }else{
                    int naiMalkoto = sledvasht.magistrali.upper_bound(0)->first;
                    int koetoESega = sasedstvo[naiOtpred.vrah][i].razst;

                    if(koetoESega > naiMalkoto){
                        sledvasht.totalRazst -= naiMalkoto;
                        sledvasht.magistrali[naiMalkoto]--;

                        if(sledvasht.magistrali[naiMalkoto] == 0){
                            sledvasht.magistrali.erase(naiMalkoto);
                        }
                    }else{
                        sledvasht.totalRazst -= koetoESega;
                        sledvasht.magistrali[koetoESega]--;

                        if(sledvasht.magistrali[koetoESega] == 0){
                            sledvasht.magistrali.erase(koetoESega);
                        }
                    }

                    sledvasht.broiMagistrali--;
                }

                /*
                cout<<"sledvashtiq koito she slagame izglejda taka: "<<sledvasht.vrah<<" "<<sledvasht.totalRazst<<"   ";
                for(auto i = sledvasht.magistrali.begin(); i != sledvasht.magistrali.end(); i++){
                    cout<<i->first<<"x"<<i->second<<" ";
                }
                cout<<endl<<endl;
                */

                q.push(sledvasht);

            }

        }

    }

    return otgovor;
}

int main(){

    cin>>broiVarhove>>broiRebra>>broiVzimame;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        long long razst;

        cin>>otKade>>doKade>>razst;

        sasedstvo[otKade].push_back({doKade, razst});
        sasedstvo[doKade].push_back({otKade, razst});
    }

    long long otgovor = reshi();

    cout<<otgovor<<endl;


    return 0;
}
