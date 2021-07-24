#include<iostream>
#include<vector>
using namespace std;

int broiGradove;
int broiPatishta;
int broiPitaniq;

vector<int> sasedstvo[1010];

int otKoiKomponentE[1010];

void dfs(int segashen, int nomerche){
    //cout<<"sega suma na "<<segashen<<" i boqdisvam s "<<nomerche<<endl;

    if(otKoiKomponentE[segashen] == nomerche){
        return ;
    }

    otKoiKomponentE[segashen] = nomerche;

    for(int i = 0; i < (int)sasedstvo[segashen].size(); i++){
        dfs(sasedstvo[segashen][i], nomerche);
    }
}

int nomerche;

void praveneNaKomp(){
    for(int i = 1; i <= broiGradove; i++){
        if(otKoiKomponentE[i] == 0){
            nomerche++;
            dfs(i, nomerche);
        }
    }
}

int otgovori[100010];
int broiOtovori;

bool imaLiTakovaVeche[1010][1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>broiGradove>>broiPatishta;

    for(int i = 0; i < broiPatishta; i++){
        int otKade;
        int doKade;

        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
        imaLiTakovaVeche[otKade][doKade] = true;
        imaLiTakovaVeche[doKade][otKade] = true;
    }

    praveneNaKomp();

    cin>>broiPitaniq;

    for(int i = 0; i < broiPitaniq; i++){
        int tip;
        int otKade;
        int doKade;

        cin>>tip>>otKade>>doKade;

        if(tip == 1){
            if(otKoiKomponentE[otKade] == otKoiKomponentE[doKade]){
                otgovori[broiOtovori] = 1;
                broiOtovori++;
            }else{
                otgovori[broiOtovori] = 0;
                broiOtovori++;
            }
        }else{
            if(tip == 2){
                if(imaLiTakovaVeche[otKade][doKade] == false){
                    sasedstvo[otKade].push_back(doKade);
                    sasedstvo[doKade].push_back(otKade);
                    imaLiTakovaVeche[otKade][doKade] = true;
                    imaLiTakovaVeche[doKade][otKade] = true;

                    if(otKoiKomponentE[otKade] != otKoiKomponentE[doKade]){
                        int nomercheNaParviq = otKoiKomponentE[otKade];
                        int nomercheNaVtoriq = otKoiKomponentE[doKade];
                        for(int j = 1; j <= broiGradove; j++){
                            if(otKoiKomponentE[j] == nomercheNaVtoriq){
                                otKoiKomponentE[j] = nomercheNaParviq;
                            }
                        }

                        //otKoiKomponentE[korenNaDarvotoNa[doKade]] = otKoiKomponentE[korenNaDarvotoNa[otKade]];
                    }
                }

            }else{
                if(otKoiKomponentE[otKade] == otKoiKomponentE[doKade]){
                    for(int j = 0; j < (int)sasedstvo[otKade].size(); j++){
                        if(sasedstvo[otKade][j] == doKade){
                            swap(sasedstvo[otKade][j], sasedstvo[otKade][sasedstvo[otKade].size() - 1]);
                            sasedstvo[otKade].pop_back();
                            break;
                        }
                    }
                    for(int j = 0; j < (int)sasedstvo[doKade].size(); j++){
                        if(sasedstvo[doKade][j] == otKade){
                            swap(sasedstvo[doKade][j], sasedstvo[doKade][sasedstvo[doKade].size() - 1]);
                            sasedstvo[doKade].pop_back();
                            break;
                        }
                    }
                    imaLiTakovaVeche[otKade][doKade] = false;
                    imaLiTakovaVeche[doKade][otKade] = false;

                    /*cout<<"Ot: ";
                    for(int j = 0; j < (int)sasedstvo[otKade].size(); j++){
                        cout<<sasedstvo[otKade][j]<<" ";
                    }
                    cout<<endl<<"Do: ";
                    for(int j = 0; j < (int)sasedstvo[doKade].size(); j++){
                        cout<<sasedstvo[doKade][j]<<" ";
                    }
                    cout<<endl;*/
                    nomerche++;
                    dfs(otKade, nomerche);
                }
                //cout<<endl;

            }
        }
    }

    for(int i = 0; i < broiOtovori; i++){
        cout<<otgovori[i];
    }

    cout<<endl;

    return 0;
}
