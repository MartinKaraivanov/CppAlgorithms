#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct DanniZaMahaneto{
    int indexPriEdiniq;
    int indexPriDrugiq;
};

int broiSpirki;
int broiLinii;

vector<int> sasedstvo[50010];

vector<int> predvaritelniPatishta[50010];

vector<int> otgovori[50010];

DanniZaMahaneto premahvaneNaRebro(int otKade, int doKade){
    DanniZaMahaneto zaVrasht;

    for(int i = 0; i < sasedstvo[otKade].size(); i++){
        if(sasedstvo[otKade][i] == doKade){
            zaVrasht.indexPriEdiniq = i;
            sasedstvo[otKade][i] = -1;
            break;
        }
    }

    for(int i = 0; i < sasedstvo[doKade].size(); i++){
        if(sasedstvo[doKade][i] == otKade){
            zaVrasht.indexPriDrugiq = i;
            sasedstvo[doKade][i] = -1;
            break;
        }
    }

    return zaVrasht;
}

int broiNaRebrata(int naKoi){
    int broi = 0;

    for(int i = 0; i < sasedstvo[naKoi].size(); i++){
        if(sasedstvo[naKoi][i] != -1){
            broi++;
        }
    }

    return broi;
}

bool tarseneNaPatishta(int segashen, int koiTarsim, int kadeZapisvame, bool parvotoLiE){
    if(segashen == koiTarsim && parvotoLiE == false){
        predvaritelniPatishta[kadeZapisvame].push_back(segashen);
        return true;
    }

    bool tuka = false;

    for(int i = 0; i < sasedstvo[segashen].size(); i++){
        if(sasedstvo[segashen][i] != -1){
            int originalno = sasedstvo[segashen][i];

            DanniZaMahaneto a = premahvaneNaRebro(segashen, sasedstvo[segashen][i]);

            bool tekushto = tarseneNaPatishta(originalno, koiTarsim, kadeZapisvame, false);

            if(tekushto == true){
                tuka = true;
                premahvaneNaRebro(segashen, sasedstvo[segashen][i]);
                break;
            }else{
                sasedstvo[segashen][a.indexPriEdiniq] = originalno;
                sasedstvo[originalno][a.indexPriDrugiq] = segashen;
            }
        }
    }

    if(tuka == true){
        predvaritelniPatishta[kadeZapisvame].push_back(segashen);
    }

    return tuka;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiSpirki>>broiLinii;

    for(int i = 0; i < broiLinii; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    int broiSNechetnaStepen = 0;

    for(int i = 1; i <= broiSpirki; i++){
        broiSNechetnaStepen += sasedstvo[i].size() % 2;
    }

    int otgovor = broiSNechetnaStepen/2;

    if(otgovor == 0){
        cout<<1<<endl;

        tarseneNaPatishta(1, 1, 0, true);

        int nomerche = 1;

        for(int i = 0; i < predvaritelniPatishta[0].size(); i++){
            otgovori[0].push_back(predvaritelniPatishta[0][i]);

            while(broiNaRebrata(predvaritelniPatishta[0][i]) > 0){
                tarseneNaPatishta(predvaritelniPatishta[0][i], predvaritelniPatishta[0][i], nomerche, true);

                for(int j = 1; j < predvaritelniPatishta[nomerche].size(); j++){
                    otgovori[0].push_back(predvaritelniPatishta[nomerche][j]);
                }
            }
        }

        cout<<otgovori[0].size()<<" ";

        for(int i = 0; i < otgovori[0].size(); i++){
            cout<<otgovori[0][i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<otgovor<<endl;

        int parviq = 0;
        int vtoriq = 0;
        int kade = 0;

        for(int i = 1; i <= broiSpirki; i++){
            if(broiNaRebrata(i)%2 == 1){
                if(parviq == 0){
                    parviq = i;
                }else{
                    vtoriq = i;
                    tarseneNaPatishta(parviq, vtoriq, kade, true);
                    kade++;
                    parviq = 0;
                    vtoriq = 0;
                }
            }
        }

        /*for(int i = 0; i < kade; i++){
            for(int j = 0; j < predvaritelniPatishta[i].size(); j++){
                cout<<predvaritelniPatishta[i][j]<<" ";
            }
            cout<<endl;
        }*/

        int nomerche = kade;

        for(int k = 0; k < kade; k++){

            for(int i = 0; i < predvaritelniPatishta[k].size(); i++){
                otgovori[k].push_back(predvaritelniPatishta[k][i]);

                while(broiNaRebrata(predvaritelniPatishta[k][i]) > 0){
                    tarseneNaPatishta(predvaritelniPatishta[k][i], predvaritelniPatishta[k][i], nomerche, true);

                    for(int j = 1; j < predvaritelniPatishta[nomerche].size(); j++){
                        otgovori[k].push_back(predvaritelniPatishta[nomerche][j]);
                    }
                }
            }
        }

        for(int i = 0; i < kade; i++){
            cout<<otgovori[i].size()<<" ";

            for(int j = 0; j < otgovori[i].size(); j++){
                cout<<otgovori[i][j]<<" ";
            }
            cout<<endl;
        }

    }



    return 0;
}
