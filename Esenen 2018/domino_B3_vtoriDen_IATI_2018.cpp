#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct DanniZaRebro{
    int otKade;
    int doKade;
};

int doKoiBroiTochici;
int broiMahnati;

vector<int> sasedstvo[1030];

bool vzetoLiE[1030][1030];

bool zaMahaneLiE[1030][1030];

int broiIzlizashtiOtTozi[1030];

bool toziIzpolzvanLiE[1030];

vector<int> otgovori[1030];
int broiOtgovori;

void obhozhdane(int startov){
    stack<int> s;
    s.push(startov);

    while(s.empty() == false){
        int naiOtgore = s.top();

        bool vsichkiteMuRebraLiSaObhodeni = true;
        int nqkoeNeobhodeno = -1;

        for(unsigned int i = 0; i < sasedstvo[naiOtgore].size(); i++){
            if(vzetoLiE[naiOtgore][sasedstvo[naiOtgore][i]] == false){
                vsichkiteMuRebraLiSaObhodeni = false;
                nqkoeNeobhodeno = sasedstvo[naiOtgore][i];
                break;
            }
        }

        if(vsichkiteMuRebraLiSaObhodeni == true){
            otgovori[broiOtgovori].push_back(naiOtgore);
            toziIzpolzvanLiE[naiOtgore] = true;
            s.pop();
        }else{
            cout<<"na "<<naiOtgore<<" "<<nqkoeNeobhodeno<<" mu e svobodno"<<endl;
            s.push(nqkoeNeobhodeno);
            //cout<<"tuko shto naglasih "<<naiOtgore<<" "<<nqkoeNeobhodeno<<endl;
            vzetoLiE[naiOtgore][nqkoeNeobhodeno] = true;
            vzetoLiE[nqkoeNeobhodeno][naiOtgore] = true;
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>doKoiBroiTochici>>broiMahnati;

    for(int i = 0; i < broiMahnati; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        zaMahaneLiE[otKade][doKade] = true;
        zaMahaneLiE[doKade][otKade] = true;
    }

    for(int i = 0; i <= doKoiBroiTochici; i++){
        for(int j = i; j <= doKoiBroiTochici; j++){
            if(zaMahaneLiE[i][j] == false){
                sasedstvo[i].push_back(j);
                if(i != j){
                    broiIzlizashtiOtTozi[j]++;
                    broiIzlizashtiOtTozi[i]++;
                    sasedstvo[j].push_back(i);
                }
            }
        }
    }

    /*for(int i = 0; i <= doKoiBroiTochici; i++){
        cout<<i<<": ";
        for(unsigned j = 0; j < sasedstvo[i].size(); j++){
            cout<<sasedstvo[i][j]<<" ";
        }
        cout<<endl;
    }*/

    bool pusnaliLiSme = false;

    for(int i = 0; i <= doKoiBroiTochici; i++){
        if(broiIzlizashtiOtTozi[i] % 2 == 1 && toziIzpolzvanLiE[i] == false){
            pusnaliLiSme = true;
            obhozhdane(i);
            broiOtgovori++;
        }
    }

    if(pusnaliLiSme == false){
        for(int i = 0; i <= doKoiBroiTochici; i++){
            if(toziIzpolzvanLiE[i] == false){
                pusnaliLiSme = true;
                obhozhdane(i);
                broiOtgovori++;
            }
        }
    }

    cout<<broiOtgovori<<endl;

    for(int j = 0; j < broiOtgovori; j++){
        for(unsigned int i = 0; i < otgovori[j].size(); i++){
            cout<<otgovori[j][i]<<" ";
        }
        cout<<-1<<endl;
    }

    return 0;
}
