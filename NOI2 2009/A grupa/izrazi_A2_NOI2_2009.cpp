#include<iostream>
#include<vector>
#include<set>
using namespace std;

int broiCifri;

int cifri[23];

long long proizvedenietoOtTukaDoTuka[23][23];

int broiRazlichni;
set<long long> imameLiTova;

void praveneNaIzraza(int indexche, char znakPredNego, long long sumaDoSega){
    //cout<<indexche<<" "<<sumaDoSega<<" "<<znakPredNego<<endl;
    if(indexche >= broiCifri){
        if(imameLiTova.find(sumaDoSega) == imameLiTova.end()){
            //cout<<sumaDoSega<<endl;
            imameLiTova.insert(sumaDoSega);
            broiRazlichni++;
        }
        return ;
    }

    int poKakvo = 1;
    if(znakPredNego == '-'){
        poKakvo = -1;
    }
    for(int i = 1; i <= broiCifri - indexche; i++){
        long long proizv = proizvedenietoOtTukaDoTuka[indexche][indexche + i - 1]*poKakvo;
        praveneNaIzraza(indexche + i, '+', sumaDoSega + proizv);
        praveneNaIzraza(indexche + i, '-', sumaDoSega + proizv);
    }

}

void dobavqneKamSet(set<long long>& zaGledane, long long promqna, set<long long>& zaPipane){
    for(set<long long>::iterator i = zaGledane.begin(); i != zaGledane.end(); i++){
        zaPipane.insert(*i + promqna);
    //for(auto i : zaGledane){
        //zaPipane.insert(i + promqna);
    }
}

set<long long> pritTolkova[23];

set<long long> vazmozhniStoinosti(int doKoe){

    set<long long> zaVrasht;

    if(doKoe == 0){
        zaVrasht.insert(cifri[doKoe]);
        return zaVrasht;
    }

    if(pritTolkova[doKoe].size() > 0){
        return pritTolkova[doKoe];
    }

    zaVrasht.insert(proizvedenietoOtTukaDoTuka[0][doKoe]);

    for(int i = 1; i <= doKoe; i++){
        long long proizv = proizvedenietoOtTukaDoTuka[doKoe - i + 1][doKoe];

        set<long long> zaTuk = vazmozhniStoinosti(doKoe - i);

        dobavqneKamSet(zaTuk, proizv, zaVrasht);
        dobavqneKamSet(zaTuk, -proizv, zaVrasht);
    }

    pritTolkova[doKoe] = zaVrasht;
    return zaVrasht;
}

set<long long> sCycli(int zaDoKoe){
    pritTolkova[0].insert(cifri[0]);

    for(int doKoe = 1; doKoe <= zaDoKoe; doKoe++){
        pritTolkova[doKoe].insert(proizvedenietoOtTukaDoTuka[0][doKoe]);

        for(int i = 1; i <= doKoe; i++){
            long long proizv = proizvedenietoOtTukaDoTuka[doKoe - i + 1][doKoe];

            dobavqneKamSet(pritTolkova[doKoe - i], proizv, pritTolkova[doKoe]);
            dobavqneKamSet(pritTolkova[doKoe - i], -proizv, pritTolkova[doKoe]);
        }
    }

    return pritTolkova[zaDoKoe];
}

void praveneNaProizvedenieto(){
    for(int i = 0; i < broiCifri; i++){
        int proizvZaTuka = 1;
        for(int j = i; j < broiCifri; j++){
            proizvZaTuka*=cifri[j];
            proizvedenietoOtTukaDoTuka[i][j] = proizvZaTuka;
        }
    }
}

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/

    cin>>broiCifri;

    for(int i = 0; i < broiCifri; i++){
        cin>>cifri[i];
    }

    praveneNaProizvedenieto();

    //praveneNaIzraza(0, '+', 0);
    //set<long long> otgovori = vazmozhniStoinosti(broiCifri - 1);
    set<long long> otgovori = sCycli(broiCifri - 1);

    /*for(set<long long>::iterator i = otgovori.begin(); i != otgovori.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;*/

    broiRazlichni = otgovori.size();

    cout<<broiRazlichni<<endl;

    return 0;
}
