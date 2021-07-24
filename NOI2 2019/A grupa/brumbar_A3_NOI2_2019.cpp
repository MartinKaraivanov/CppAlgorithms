#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct DanniZaTochka{
    int x;
    int y;
};

struct DanniZaOtsechka{
    DanniZaTochka nachalnaTochka;
    int daljina;
};

int broiOtsechki;
DanniZaOtsechka otsechki[100010];

int maximalenX;

int broiBrambari;
int tochkiNaPuskane[60010];

vector<int> sasedstvo[100010];

bool koqEPoParva(DanniZaOtsechka a, DanniZaOtsechka b){
    if(a.nachalnaTochka.y > b.nachalnaTochka.y){
        return false;
    }
    if(a.nachalnaTochka.y < b.nachalnaTochka.y){
        return true;
    }

    return a.nachalnaTochka.x < b.nachalnaTochka.x;
}

int broiNujniVarhove;

int koiENaiGorniqTuka[100010];

void namiraneNaBrNujniVarhove(){
    int proizvedenie = 1;

    while(true){
        proizvedenie *= 2;
        if(proizvedenie > maximalenX){
            broiNujniVarhove = 2*proizvedenie;
            break;
        }
    }
}

int daiListo(int index){
    return index + broiNujniVarhove/2;
}

int query(int index){
    int idx = daiListo(index);

    int posledenSreshtan = 0;

    while(idx > 0){
        cout<<idx<<" "<<koiENaiGorniqTuka[idx]<<endl;

        /*if(koiENaiGorniqTuka[idx] > 0){
            posledenSreshtan = koiENaiGorniqTuka[idx];
        }*/

        posledenSreshtan = max(posledenSreshtan, koiENaiGorniqTuka[idx]);

        idx /= 2;
    }

    return posledenSreshtan;
}

void update(int otKade, int doKade, int koiSlagam){
    int lqvIndex = daiListo(otKade);
    int desenIndex = daiListo(doKade);

    if(otKade == doKade){
        koiENaiGorniqTuka[lqvIndex] = koiSlagam;
        return ;
    }

    koiENaiGorniqTuka[lqvIndex] = koiSlagam;
    koiENaiGorniqTuka[desenIndex] = koiSlagam;

    while(lqvIndex < desenIndex){
        if(lqvIndex%2 == 0){
            koiENaiGorniqTuka[lqvIndex + 1] = koiSlagam;
        }
        if(desenIndex%2 == 1){
            koiENaiGorniqTuka[desenIndex - 1] = koiSlagam;
        }

        lqvIndex /= 2;
        desenIndex /= 2;
    }
}

int main(){
    cin>>broiOtsechki;

    for(int i = 1; i <= broiOtsechki; i++){
        cin>>otsechki[i].nachalnaTochka.x>>otsechki[i].nachalnaTochka.y>>otsechki[i].daljina;
        maximalenX = max(maximalenX, otsechki[i].nachalnaTochka.x + otsechki[i].daljina);
    }

    cin>>broiBrambari;

    for(int i = 0; i < broiBrambari; i++){
        cin>>tochkiNaPuskane[i];
    }

    sort(otsechki, otsechki + broiOtsechki + 1, koqEPoParva);

    namiraneNaBrNujniVarhove();
    cout<<broiNujniVarhove<<endl;

    for(int i = 1; i <= broiOtsechki; i++){
        int otLqvo = query(otsechki[i].nachalnaTochka.x - 1);
        int otDqsno = query(otsechki[i].nachalnaTochka.x + otsechki[i].daljina);

        sasedstvo[i].push_back(otLqvo);
        sasedstvo[i].push_back(otDqsno);

        update(otsechki[i].nachalnaTochka.x, otsechki[i].nachalnaTochka.x + otsechki[i].daljina - 1, i);
        cout<<"sega updatenah ot "<<otsechki[i].nachalnaTochka.x<<" do ";
        cout<<otsechki[i].nachalnaTochka.x + otsechki[i].daljina - 1<<endl;

        for(int j = 0; j <= maximalenX; j++){
            cout<<koiENaiGorniqTuka[daiListo(j)]<<" ";
        }

        cout<<endl;
    }

    for(int i = 0; i <= broiOtsechki; i++){
        cout<<i<<":"<<endl;

        for(auto j : sasedstvo[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
