#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int broiSpirki;
int broiPatishta;

int start;
int finaal;

vector<int> sasedstvo[100010];

int razstOtStartaDo[100010];
int roditel[100010];
vector<int> naiKasPat;

struct DanniZaOpashkata{
    int koi;
    int razstDoNego;
    int bashta;
};

void nameriNaiKasPat(){
    queue<DanniZaOpashkata> q;

    q.push({start, 0, 0});

    while(q.empty() == false){
        DanniZaOpashkata naiOtpred = q.front();
        q.pop();

        if(razstOtStartaDo[naiOtpred.koi] > 0){
            continue;
        }

        razstOtStartaDo[naiOtpred.koi] = naiOtpred.razstDoNego;
        roditel[naiOtpred.koi] = naiOtpred.bashta;

        if(naiOtpred.koi == finaal){
            break;
        }

        for(int i = 0; i < (int)sasedstvo[naiOtpred.koi].size(); i++){
            if(razstOtStartaDo[sasedstvo[naiOtpred.koi][i]] == 0 && sasedstvo[naiOtpred.koi][i] != start){
                q.push({sasedstvo[naiOtpred.koi][i], naiOtpred.razstDoNego + 1, naiOtpred.koi});
            }
        }
    }

    for(int i = finaal; i != 0; i = roditel[i]){
        naiKasPat.push_back(i);
    }
}

int broiCikli;
vector<int> cikal[100010];
vector<int> toziOtKoiCikliE[100010];

bool visited[100010];
bool segashnoVisited[100010];

bool toziImaliToziCikul(int koiVrah, int koiCikal){
    bool imaLiGo = false;

    for(int i = 0; i < (int)toziOtKoiCikliE[koiVrah].size(); i++){
        if(toziOtKoiCikliE[koiVrah][i] == koiCikal){
            imaLiGo = true;
            break;
        }
    }

    return imaLiGo;
}

int nameriCikli(int segashen, int otKadeIdvame){
    if(segashnoVisited[segashen] == true){
        broiCikli++;

        cikal[broiCikli].push_back(segashen);
        toziOtKoiCikliE[segashen].push_back(broiCikli);
        return broiCikli;
    }

    if(visited[segashen] == true){
        return 0;
    }

    visited[segashen] = true;
    segashnoVisited[segashen] = true;

    int zaVrasht = 0;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != otKadeIdvame){
            int tuka = nameriCikli(sasedstvo[segashen][i], segashen);
            if(tuka > 0){
                if(toziImaliToziCikul(segashen, tuka) == true){

                }else{
                    zaVrasht = tuka;
                    toziOtKoiCikliE[segashen].push_back(tuka);
                    cikal[tuka].push_back(segashen);
                }
            }
        }
    }

    segashnoVisited[segashen] = false;

    return zaVrasht;
}

int main(){
    cin>>broiSpirki>>broiPatishta>>start>>finaal;

    for(int i = 0; i < broiPatishta; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    nameriNaiKasPat();
    nameriCikli(1, 0);

    vector<int> svarzvashtitePoPatq;

    if(toziOtKoiCikliE[finaal].size() == 1){
        svarzvashtitePoPatq.push_back(finaal);
    }

    for(int i = finaal; i != 0; i = roditel[i]){
        if(toziOtKoiCikliE[i].size() > 1){
            svarzvashtitePoPatq.push_back(i);
        }
    }

    if(toziOtKoiCikliE[start].size() == 1){
        svarzvashtitePoPatq.push_back(start);
    }

    vector<int> nujniteSvarzvashti;

    nujniteSvarzvashti.push_back(finaal);

    int predeCikul = 0;

    for(int i = 2; i < (int)svarzvashtitePoPatq.size(); i++){
        int segashen = svarzvashtitePoPatq[i];
        int preden = svarzvashtitePoPatq[i - 1];

        int otKoiCikulSaIDvamata = 0;

        for(int j = 0; j < (int)toziOtKoiCikliE[segashen].size(); j++){
            for(int k = 0; k < (int)toziOtKoiCikliE[preden].size(); k++){
                if(toziOtKoiCikliE[segashen][j] == toziOtKoiCikliE[preden][k]){
                    otKoiCikulSaIDvamata = toziOtKoiCikliE[segashen][j];
                    break;
                }
            }
            if(otKoiCikulSaIDvamata > 0){
                break;
            }
        }

        if(otKoiCikulSaIDvamata != predeCikul){
            nujniteSvarzvashti.push_back(preden);
        }

        predeCikul = otKoiCikulSaIDvamata;
    }

    nujniteSvarzvashti.push_back(start);

    int sumarenPat = 0;

    for(int i = 1; i < (int)nujniteSvarzvashti.size(); i++){
        int segashen = nujniteSvarzvashti[i];
        int preden = nujniteSvarzvashti[i - 1];

        int otKoiCikulSaIDvamata = 0;

        for(int j = 0; j < (int)toziOtKoiCikliE[segashen].size(); j++){
            for(int k = 0; k < (int)toziOtKoiCikliE[preden].size(); k++){
                if(toziOtKoiCikliE[segashen][j] == toziOtKoiCikliE[preden][k]){
                    otKoiCikulSaIDvamata = toziOtKoiCikliE[segashen][j];
                    break;
                }
            }
            if(otKoiCikulSaIDvamata > 0){
                break;
            }
        }

        int mejduTqh = razstOtStartaDo[preden] - razstOtStartaDo[segashen];
        int drugiqPat = cikal[otKoiCikulSaIDvamata].size() - mejduTqh;

        sumarenPat += max(mejduTqh, drugiqPat);
    }

    cout<<sumarenPat<<endl;

    return 0;
}
