#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaPatq{
    int doGrad;
    int razstoqnie;

    DanniZaPatq(int doGrad, int razstoqnie)
        : doGrad(doGrad), razstoqnie(razstoqnie)
    {

    }
};

struct koiPatEPoKas{
    bool operator()(DanniZaPatq const& a, DanniZaPatq const& b)
    {
        return a.razstoqnie > b.razstoqnie;
    }

};

int broiKrastovishta;

int start;
int finaal;

const int MNogo = 100000000;

vector<DanniZaPatq> sasedstvo[200100];

vector<int> gradcheta;

int otKoqKomponentaE[200100];
int nomerche = 1;

int naiKasPatDo[200100];
bool imameLiNaiKasPatDoNego[200100];

void nuliraneNaNaiKasiqPat(){
    for(int i = 1; i <= broiKrastovishta; i++){
        naiKasPatDo[i] = MNogo;
    }
}

/*void dijkstra(){
    for(unsigned int i = 0; i < sasedstvo[start].size(); i++){
        naiKasPatDo[sasedstvo[start][i].doGrad] = sasedstvo[start][i].razstoqnie;
        gradcheta.push_back(sasedstvo[start][i].doGrad);
        //cout<<"Tuko shto slozhih "<<sasedstvo[start][i].doGrad<<endl;
    }

    imameLiNaiKasPatDoNego[start] = true;

    bool nameriliLiSmeNeshto = true;
    while(nameriliLiSmeNeshto == true){
        nameriliLiSmeNeshto = false;

        if(imameLiNaiKasPatDoNego[finaal]){
            return ;
        }

        int naiKaso = MNogo;
        int koiGradENaiKasoto;

        for(int i = 1; i <= broiKrastovishta; i++){
            if(naiKasPatDo[i] < naiKaso && imameLiNaiKasPatDoNego[i] == false){
                naiKaso = naiKasPatDo[i];
                koiGradENaiKasoto = i;
                nameriliLiSmeNeshto = true;
            }
        }

        for(unsigned int i = 0; i < gradcheta.size(); i++){
            if(naiKasPatDo[gradcheta[i]] < naiKaso && imameLiNaiKasPatDoNego[gradcheta[i]] == false){
                naiKaso = naiKasPatDo[gradcheta[i]];
                koiGradENaiKasoto = gradcheta[i];
                nameriliLiSmeNeshto = true;
            }
        }

        //cout<<"Nai kasoto e "<<naiKaso<<" do "<<koiGradENaiKasoto<<endl;

        if(nameriliLiSmeNeshto == true){
            imameLiNaiKasPatDoNego[koiGradENaiKasoto] = true;
            gradcheta.push_back(koiGradENaiKasoto);
            //cout<<"tuko shto slozhih "<<koiGradENaiKasoto<<endl;
            for(unsigned int i = 0; i < sasedstvo[koiGradENaiKasoto].size(); i++){
                gradcheta.push_back(sasedstvo[koiGradENaiKasoto][i].doGrad);
                if(imameLiNaiKasPatDoNego[sasedstvo[koiGradENaiKasoto][i].doGrad] == false &&
                   naiKasPatDo[sasedstvo[koiGradENaiKasoto][i].doGrad] >
                    naiKasPatDo[koiGradENaiKasoto] + sasedstvo[koiGradENaiKasoto][i].razstoqnie)
                {
                    naiKasPatDo[sasedstvo[koiGradENaiKasoto][i].doGrad] =
                    naiKasPatDo[koiGradENaiKasoto] + sasedstvo[koiGradENaiKasoto][i].razstoqnie;
                }
            }
        }

    }

}*/

void sPrioritetnaOpashka(){
    priority_queue<DanniZaPatq, vector<DanniZaPatq>, koiPatEPoKas> q;

    q.push({start, 0});

    while(q.empty() == false){
        DanniZaPatq naiOtpred = q.top();
        q.pop();

        if(imameLiNaiKasPatDoNego[naiOtpred.doGrad] == true){
            continue;
        }

        naiKasPatDo[naiOtpred.doGrad] = naiOtpred.razstoqnie;
        imameLiNaiKasPatDoNego[naiOtpred.doGrad] = true;

        if(naiOtpred.doGrad == finaal){
            break;
        }

        for(unsigned int i = 0; i < sasedstvo[naiOtpred.doGrad].size(); i++){
            if(imameLiNaiKasPatDoNego[sasedstvo[naiOtpred.doGrad][i].doGrad] == false){
                q.push({sasedstvo[naiOtpred.doGrad][i].doGrad, naiOtpred.razstoqnie + sasedstvo[naiOtpred.doGrad][i].razstoqnie});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKrastovishta>>start>>finaal;

    int ot;

    while(cin>>ot){
        int doKade;
        cin>>doKade;
        DanniZaPatq zaDob = {doKade, 0};
        sasedstvo[ot].push_back(zaDob);
        zaDob = {ot, 1};
        sasedstvo[doKade].push_back(zaDob);
    }

    nuliraneNaNaiKasiqPat();

    //dijkstra();
    sPrioritetnaOpashka();

    if(naiKasPatDo[finaal] != MNogo){
        cout<<naiKasPatDo[finaal]<<endl;
    }else{
        cout<<"X"<<endl;
    }

    return 0;
}
