#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaPravoagalnik{
    DanniZaTochka gornaLqva;
    DanniZaTochka dolnaDqsna;
};

int broiPravoagalnici;

DanniZaPravoagalnik pravoagalnici[100010];

vector<int> koiSaTochnoVNego[100010];

int dalbochina[100010];
bool visited[100010];

bool toziVDrugiqLiE(DanniZaPravoagalnik vatreshen, DanniZaPravoagalnik vanshen){
    if((vatreshen.gornaLqva.x > vanshen.gornaLqva.x) && (vatreshen.dolnaDqsna.x < vanshen.dolnaDqsna.x) &&
       (vatreshen.gornaLqva.y > vanshen.gornaLqva.y) && (vatreshen.dolnaDqsna.y < vanshen.dolnaDqsna.y))
    {
        return true;
    }

    return false;
}
/*
bool toziTochnoVDrugiqLiE(DanniZaPravoagalnik vatreshen, DanniZaPravoagalnik vanshen){
    bool tochnoVDrugiqLiE = true;
    if(toziVDrugiqLiE(vatreshen, vanshen)){
        for(int i = 0; i < broiPravoagalnici; i++){
            if(toziVDrugiqLiE(pravoagalnici[i], vanshen) && toziVDrugiqLiE(vatreshen, pravoagalnici[i])){
                tochnoVDrugiqLiE = false;
                break;
            }
        }
    }else{
        tochnoVDrugiqLiE = false;
    }
    return tochnoVDrugiqLiE;
}

int vKoiTochnoPravoagalnikSeNamiraTozi(int koiPravoag){
    int pravoagalnikVKoitoE = -1;

    for(int i = 0; i < broiPravoagalnici; i++){
        if(toziTochnoVDrugiqLiE(pravoagalnici[koiPravoag], pravoagalnici[i])){
            pravoagalnikVKoitoE = i;
            break;
        }
    }

    return pravoagalnikVKoitoE;
}
*/
int VkoiTochnoSenamira(int koiPravoagalnik){
    int segashenPrevlagalnikVKoitoE = broiPravoagalnici;
    bool nameriliLSme = true;

    while(nameriliLSme){
        nameriliLSme = false;

        for(unsigned int j = 0; j < koiSaTochnoVNego[segashenPrevlagalnikVKoitoE].size(); j++){
            if(toziVDrugiqLiE(pravoagalnici[koiPravoagalnik], pravoagalnici[koiSaTochnoVNego[segashenPrevlagalnikVKoitoE][j]])){
                nameriliLSme = true;
                segashenPrevlagalnikVKoitoE = koiSaTochnoVNego[segashenPrevlagalnikVKoitoE][j];
                break;
            }
        }
    }

    return segashenPrevlagalnikVKoitoE;
}

void praveneNaSasedstvo(){
    for(int i = 0; i < broiPravoagalnici; i++){
        int vKoiTrqbvaDaSeSlozhi = VkoiTochnoSenamira(i);
        unsigned int j = 0;
        while(j < koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi].size()){
            if(toziVDrugiqLiE(pravoagalnici[koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi][j]], pravoagalnici[i])){
                int zaMahane = koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi][j];

                koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi][j] =
                  koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi][koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi].size() - 1];
                koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi].pop_back();

                koiSaTochnoVNego[i].push_back(zaMahane);
            }else{
                j++;
            }
        }

        koiSaTochnoVNego[vKoiTrqbvaDaSeSlozhi].push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiPravoagalnici;

    for(int i = 0; i < broiPravoagalnici; i++){
        DanniZaTochka gornaLqva;
        int dalzhinaNalqvo;
        int shirinaNadolu;
        cin>>gornaLqva.x>>gornaLqva.y>>dalzhinaNalqvo>>shirinaNadolu;
        DanniZaTochka dolnaDqsna = {gornaLqva.x + dalzhinaNalqvo, gornaLqva.y + shirinaNadolu};
        pravoagalnici[i] = {gornaLqva, dolnaDqsna};
    }

    /*for(int i = 0; i < broiPravoagalnici; i++){
        for(int j = 0; j < broiPravoagalnici; j++){
            if(i == j){
                continue;
            }
            if(toziTochnoVDrugiqLiE(pravoagalnici[j], pravoagalnici[i]) == true){
                koiSaTochnoVNego[i].push_back(j);
            }
        }
    }*/

    praveneNaSasedstvo();

    int broiOstrovcheta = 0;

    for(int k = 0; k < broiPravoagalnici; k++){

        queue<int> q;

        q.push(k);

        while(q.empty() == false){
            int nashiq = q.front();
            q.pop();

            if(visited[nashiq] == true){
                continue;
            }

            visited[nashiq] = true;

            if(dalbochina[nashiq] % 2 == 0){
                broiOstrovcheta++;
                //cout<<nashiq<<endl;
            }

            for(unsigned int i = 0; i < koiSaTochnoVNego[nashiq].size(); i++){
                q.push(koiSaTochnoVNego[nashiq][i]);
                dalbochina[koiSaTochnoVNego[nashiq][i]] = dalbochina[nashiq] + 1;
            }

        }
    }

    cout<<broiOstrovcheta<<endl;

    return 0;
}
