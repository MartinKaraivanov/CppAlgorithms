#include<iostream>
#include<vector>
using namespace std;

struct DanniZaPolenceOtKartichka{
    int x;
    int y;
};

struct DanniZaKartichki{
    DanniZaPolenceOtKartichka parvoPolence;
    DanniZaPolenceOtKartichka vtoroPolence;
};

int maxY;
int maxX;

int broiSloeveTuk[750][750];

DanniZaKartichki kartichki[500000];

int gorenSloi[750][750];
int dolenSloi[750][750];

int taziKartichkaKolkoOtgorniImaVNachaloto[500000];

bool naTaziVavedenoLiIEPurvotot[500000];

int broiKartichki;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>maxY>>maxX;

    broiKartichki = (maxX * maxY);

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int tuk;
            cin>>tuk;
            dolenSloi[x][y] = tuk;
            if(naTaziVavedenoLiIEPurvotot[tuk] == false){
                kartichki[tuk].parvoPolence = {x, y};
                naTaziVavedenoLiIEPurvotot[tuk] = true;
            }else{
                kartichki[tuk].vtoroPolence = {x, y};
            }
        }
    }

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            int tuk;
            cin>>tuk;
            gorenSloi[x][y] = tuk;
            taziKartichkaKolkoOtgorniImaVNachaloto[tuk]++;
            broiSloeveTuk[x][y] = 2;
            if(naTaziVavedenoLiIEPurvotot[tuk] == false){
                kartichki[tuk].parvoPolence = {x, y};
                naTaziVavedenoLiIEPurvotot[tuk] = true;
            }else{
                kartichki[tuk].vtoroPolence = {x, y};
            }
        }
    }

    /*for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cout<<dolenSloi[x][y]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int y = 0; y < maxY; y++){
        for(int x = 0; x < maxX; x++){
            cout<<gorenSloi[x][y]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;*/

    /*for(int i = 1; i <= broiKartichki; i++){
        cout<<i<<" "<<taziKartichkaKolkoOtgorniImaVNachaloto[i]<<endl;
    }*/

    vector<int> vzeti;
    vzeti.reserve((maxX * maxY)/2 + 10);

    for(int i = 1; i <= broiKartichki; i++){
        if(taziKartichkaKolkoOtgorniImaVNachaloto[i] == 2){
            vzeti.push_back(i);
            broiSloeveTuk[kartichki[i].parvoPolence.x][kartichki[i].parvoPolence.y]--;
            broiSloeveTuk[kartichki[i].vtoroPolence.x][kartichki[i].vtoroPolence.y]--;
        }
    }

    for(int i = 1; i <= broiKartichki; i++){
        if(taziKartichkaKolkoOtgorniImaVNachaloto[i] == 1){
            if(broiSloeveTuk[kartichki[i].parvoPolence.x][kartichki[i].parvoPolence.y] == 2 &&
               broiSloeveTuk[kartichki[i].vtoroPolence.x][kartichki[i].vtoroPolence.y] == 2)
            {
                vzeti.push_back(i);
                broiSloeveTuk[kartichki[i].parvoPolence.x][kartichki[i].parvoPolence.y]--;
                broiSloeveTuk[kartichki[i].vtoroPolence.x][kartichki[i].vtoroPolence.y]--;
            }
        }
    }

    cout<<vzeti.size()<<endl;

    for(unsigned int i = 0; i < vzeti.size(); i++){
        cout<<vzeti[i]<<endl;
    }

    return 0;
}
