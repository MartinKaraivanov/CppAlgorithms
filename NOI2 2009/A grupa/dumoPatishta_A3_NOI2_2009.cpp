#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct DanniZaMqstoto{
    int koeKrastovishte;
    int koiIndexSme;
};

int broiKrastovishta;
int broiUlici;

vector<int> sasedstvo[105][30];

int tovaKrastovishteKoqMuEBukvata[105];

string kakvoEZapisalString;
int kakvoEZapisal[12];
int broiZapisaniBukvi;

int broiVazmozhnosti(){
    int broiDumoPatishta = 0;

    stack<DanniZaMqstoto> sq;
    //queue<DanniZaMqstoto> sq;

    sq.push({0, 0});

    while(sq.empty() == false){
        DanniZaMqstoto naiOtpred = sq.top();
        //DanniZaMqstoto naiOtpred = sq.front();
        sq.pop();

        if(naiOtpred.koiIndexSme == broiZapisaniBukvi - 1){
            broiDumoPatishta++;
            continue;
        }

        for(unsigned int i = 0; i < sasedstvo[naiOtpred.koeKrastovishte][kakvoEZapisal[naiOtpred.koiIndexSme + 1]].size(); i++){
            sq.push({sasedstvo[naiOtpred.koeKrastovishte][kakvoEZapisal[naiOtpred.koiIndexSme + 1]][i],
                    naiOtpred.koiIndexSme + 1});
        }
    }

    return broiDumoPatishta;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiKrastovishta>>broiUlici;

    string krst;

    cin>>krst;

    for(unsigned int i = 0; i < krst.size(); i++){
        tovaKrastovishteKoqMuEBukvata[i + 1] = krst[i] - 'A';
        sasedstvo[0][tovaKrastovishteKoqMuEBukvata[i + 1]].push_back(i + 1);
    }

    for(int i = 0; i < broiUlici; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;
        sasedstvo[otKade][tovaKrastovishteKoqMuEBukvata[doKade]].push_back(doKade);
        if(otKade != doKade){
            sasedstvo[doKade][tovaKrastovishteKoqMuEBukvata[otKade]].push_back(otKade);
        }
    }

    /*for(int i = 1; i <= broiKrastovishta; i++){
        sasedstvo[0][0].push_back(i);
    }*/

    cin>>kakvoEZapisalString;

    kakvoEZapisalString = " " + kakvoEZapisalString;

    for(unsigned int i = 1; i < kakvoEZapisalString.size(); i++){
        kakvoEZapisal[i] = kakvoEZapisalString[i] - 'A';
    }

    broiZapisaniBukvi = kakvoEZapisalString.size();

    int otgovor = broiVazmozhnosti();

    cout<<otgovor<<endl;

    return 0;
}
