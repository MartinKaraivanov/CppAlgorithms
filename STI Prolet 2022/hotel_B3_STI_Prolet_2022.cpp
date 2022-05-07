#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int broiEzici;
int broiHora;

struct DanniZaChoveka{
    int parviEzik;
    int vtoriEzik;
};

DanniZaChoveka hora[1000010];

struct DanniZaRebroto{
    int doKade;
    int originalenNomer;
};

vector<DanniZaRebroto> sasedstvo[100010];

bool zaetoLiE[1000010];
int sKoiEVDvoika[1000010];

struct DanniZaDvoika{
    int ediniq;
    int drugiq;
};

bool slojenLiEVDvoika[1000010];
vector<DanniZaDvoika> dvoiki;

bool visited[100010];

void nameriDvoikite(int segashenVrah, int otKadeIdvame, int nomerChovek){
    if(visited[segashenVrah] == true){
        return ;
    }
    visited[segashenVrah] = true;

    //cout<<"sega sme v "<<segashenVrah<<" i idvame ot "<<otKadeIdvame<<" choveka koito e rebro e "<<nomerChovek<<endl;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        if(sasedstvo[segashenVrah][i].doKade != otKadeIdvame && visited[sasedstvo[segashenVrah][i].doKade] == false){
            nameriDvoikite(sasedstvo[segashenVrah][i].doKade, segashenVrah, sasedstvo[segashenVrah][i].originalenNomer);
        }
    }

    int parviIzbran = -1;

    for(int i = 0; i < (int)sasedstvo[segashenVrah].size(); i++){
        int sledvasht = sasedstvo[segashenVrah][i].doKade;
        int sledvashtKoiE = sasedstvo[segashenVrah][i].originalenNomer;
        if(sledvasht != otKadeIdvame){
            if(zaetoLiE[sledvashtKoiE] == false){
                if(parviIzbran == -1){
                    parviIzbran = sledvashtKoiE;
                }else{
                    zaetoLiE[parviIzbran] = true;
                    zaetoLiE[sledvashtKoiE] = true;
                    sKoiEVDvoika[parviIzbran] = sledvashtKoiE;
                    sKoiEVDvoika[sledvashtKoiE] = parviIzbran;

                    parviIzbran = -1;
                }
            }
        }
    }

    if(parviIzbran != -1 && nomerChovek != 0){
        zaetoLiE[parviIzbran] = true;
        zaetoLiE[nomerChovek] = true;
        sKoiEVDvoika[parviIzbran] = nomerChovek;
        sKoiEVDvoika[nomerChovek] = parviIzbran;
    }

}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    //cin>>broiEzici>>broiHora;

    scanf("%i %i", &broiEzici, &broiHora);

    for(int i = 1; i <= broiHora; i++){
        int parviEzik;
        int vtoriEzik;
        //cin>>parviEzik>>vtoriEzik;
        scanf("%i %i", &parviEzik, &vtoriEzik);

        hora[i] = {parviEzik, vtoriEzik};
    }

    for(int i = 1; i <= broiHora; i++){
        sasedstvo[hora[i].parviEzik].push_back({hora[i].vtoriEzik, i});
        sasedstvo[hora[i].vtoriEzik].push_back({hora[i].parviEzik, i});
    }

    for(int i = 1; i <= broiEzici; i++){
        if(visited[i] == false){
            nameriDvoikite(i, -1, 0);
        }
    }

    //nameriDvoikite(1, -1, 0);

    for(int i = 1; i <= broiHora; i++){
        if(slojenLiEVDvoika[i] == false && sKoiEVDvoika[i] != 0){
            slojenLiEVDvoika[i] = true;
            slojenLiEVDvoika[sKoiEVDvoika[i]] = true;
            dvoiki.push_back({i, sKoiEVDvoika[i]});
        }
    }

    //cout<<dvoiki.size()<<endl;
    printf("%i \n", (int)dvoiki.size());

    for(int i = 0; i < (int)dvoiki.size(); i++){
        //cout<<dvoiki[i].ediniq<<" "<<dvoiki[i].drugiq<<endl;
        printf("%i %i \n", dvoiki[i].ediniq, dvoiki[i].drugiq);
    }

    return 0;
}
