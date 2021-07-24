#include<iostream>
#include<vector>
#include<map>
using namespace std;

int broiVarhove;
int broiRebra;

vector<int> sasedstvo[500005];

map<int, int> priTolkova[500005];

bool pechelivshoLiE(int naKoiSme, int otKadeIdvame){
    //cout<<naKoiSme<<" "<<otKadeIdvame<<endl;
    if(sasedstvo[naKoiSme].size() == 1 && otKadeIdvame != -1){
        //cout<<"pri "<<naKoiSme<<" "<<otKadeIdvame<<" returnvame "<<false<<endl;
        return false;
    }

    if(priTolkova[naKoiSme][otKadeIdvame] == 1){
        return false;
    }
    if(priTolkova[naKoiSme][otKadeIdvame] == 2){
        return true;
    }

    bool imameLiLoshIzhod = false;

    for(unsigned int i = 0; i < sasedstvo[naKoiSme].size(); i++){
        if(sasedstvo[naKoiSme][i] != otKadeIdvame){
            bool zaTuk = pechelivshoLiE(sasedstvo[naKoiSme][i], naKoiSme);
            if(zaTuk == false){
                imameLiLoshIzhod = true;
            }
        }
    }

    //cout<<"pri "<<naKoiSme<<" "<<otKadeIdvame<<" returnvame "<<imameLiLoshIzhod<<endl;

    if(imameLiLoshIzhod == false){
        priTolkova[naKoiSme][otKadeIdvame] = 1;
    }else{
        priTolkova[naKoiSme][otKadeIdvame] = 2;
    }

    return imameLiLoshIzhod;
}

int main(){
    cin>>broiVarhove>>broiRebra;

    for(int i = 0; i < broiRebra; i++){
        int otKade;
        int doKade;
        cin>>otKade>>doKade;

        sasedstvo[otKade].push_back(doKade);
        sasedstvo[doKade].push_back(otKade);
    }

    for(int i = 1; i <= broiVarhove; i++){
        cout<<!pechelivshoLiE(i, -1);
    }

    cout<<endl;

    return 0;
}
