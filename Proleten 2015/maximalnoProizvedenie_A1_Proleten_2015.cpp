#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int osnovaNaSistemata;
int broiCifri;
int broiChislaZaPrav;

char cifri[40];

int daljini[40];

vector<char> cifriteNaChislata[40];

long long desetichniChisla[40];

bool koeEPoNapred(char a, char b){
    return a > b;
}

int daiCifra(char otCifra){
    if(otCifra >= 'A'){
        return otCifra - 55;
    }

    return otCifra - '0';
}

char daiChar(int cifra){
    if(cifra >= 10){
        return cifra + 55;
    }

    return cifra + '0';
}

vector<char> sabiraneNaChisla(vector<char> parvoChislo, vector<char> vtoroChislo){
    int parvo[40];
    int vtoro[40];

    if(parvoChislo.size() > vtoroChislo.size()){
        for(int i = 0; i < (int)vtoroChislo.size(); i++){
            parvo[i] = daiCifra(vtoroChislo[i]);
            vtoro[i] = daiCifra(parvoChislo[i]);
        }
        for(int i = (int)vtoroChislo.size(); i < (int)parvoChislo.size(); i++){
            parvo[i] = 0;
            vtoro[i] = daiCifra(parvoChislo[i]);
        }
    }else{
        for(int i = 0; i < (int)parvoChislo.size(); i++){
            parvo[i] = daiCifra(parvoChislo[i]);
            vtoro[i] = daiCifra(vtoroChislo[i]);
        }
        for(int i = (int)parvoChislo.size(); i < (int)vtoroChislo.size(); i++){
            parvo[i] = 0;
            vtoro[i] = daiCifra(vtoroChislo[i]);
        }
    }

    int doKade = max((int)parvoChislo.size(), (int)vtoroChislo.size());

    /*cout<<"sabirame ";

    for(int i = 0; i < doKade; i++){
        cout<<parvo[i];
    }
    cout<<" i ";
    for(int i = 0; i < doKade; i++){
        cout<<vtoro[i];
    }*/
    //cout<<endl;

    int naum = 0;

    vector<char> rezultat;

    for(int i = 0; i < doKade; i++){
        int tuka = parvo[i] + vtoro[i] + naum;

        int tukaCifra = tuka%osnovaNaSistemata;
        int tukaNaum = tuka/osnovaNaSistemata;

        naum = tukaNaum;

        rezultat.push_back(daiChar(tukaCifra));
    }

    if(naum > 0){
        rezultat.push_back(daiChar(naum));
    }

    /*cout<<" poluchava se ";

    for(int i = 0; i < (int)rezultat.size(); i++){
        cout<<rezultat[i];
    }
    cout<<endl;*/

    return rezultat;
}

vector<char> umnojenieNaChisla(vector<char> parvoChislo, vector<char> vtoroChislo){
    int parvo[40];
    int vtoro[40];

    if(parvoChislo.size() > vtoroChislo.size()){
        for(int i = 0; i < (int)vtoroChislo.size(); i++){
            parvo[i] = daiCifra(vtoroChislo[i]);
            vtoro[i] = daiCifra(parvoChislo[i]);
        }
        for(int i = (int)vtoroChislo.size(); i < (int)parvoChislo.size(); i++){
            parvo[i] = 0;
            vtoro[i] = daiCifra(parvoChislo[i]);
        }
    }else{
        for(int i = 0; i < (int)parvoChislo.size(); i++){
            parvo[i] = daiCifra(parvoChislo[i]);
            vtoro[i] = daiCifra(vtoroChislo[i]);
        }
        for(int i = (int)parvoChislo.size(); i < (int)vtoroChislo.size(); i++){
            parvo[i] = 0;
            vtoro[i] = daiCifra(vtoroChislo[i]);
        }
    }

    int poMalkoto = min((int)parvoChislo.size(), (int)vtoroChislo.size());
    int poGolqmoto = max((int)parvoChislo.size(), (int)vtoroChislo.size());

    vector<char> dosegashno;

    for(int i = 0; i < poMalkoto; i++){
        vector<char> tukaRezultat;
        for(int j = 0; j < i; j++){
            tukaRezultat.push_back('0');
        }

        int ostatak = 0;

        for(int j = 0; j < poGolqmoto; j++){
            int tuka = parvo[i]*vtoro[j] + ostatak;

            int tukaCifra = tuka%osnovaNaSistemata;
            int tukaOstatak = tuka/osnovaNaSistemata;

            tukaRezultat.push_back(daiChar(tukaCifra));

            ostatak = tukaOstatak;
        }

        if(ostatak > 0){
            tukaRezultat.push_back(daiChar(ostatak));
        }

        /*cout<<"tuka sme umnojili "<<parvo[i]<<" po ";

        for(int j = 0; j < poGolqmoto; j++){
            cout<<vtoro[j];
        }

        cout<<" i se e poluchilo ";

        for(int j = 0; j < (int)tukaRezultat.size(); j++){
            cout<<tukaRezultat[j];
        }
        cout<<endl;*/

        dosegashno = sabiraneNaChisla(dosegashno, tukaRezultat);
    }

    return dosegashno;
}

int main(){

    cin>>osnovaNaSistemata>>broiCifri>>broiChislaZaPrav;

    for(int i = 0; i < broiCifri; i++){
        cin>>cifri[i];
    }

    for(int i = 0; i < broiChislaZaPrav; i++){
        cin>>daljini[i];
    }

    sort(cifri, cifri + broiCifri, koeEPoNapred);

    sort(daljini, daljini + broiChislaZaPrav);

    for(int i = 0; i < broiChislaZaPrav; i++){
        cifriteNaChislata[i].push_back(cifri[i]);
    }

    int indexCifri = broiChislaZaPrav;

    while(indexCifri < broiCifri){
        int indexChisla = broiChislaZaPrav - 1;

        while(indexChisla >= 0){
            if(cifriteNaChislata[indexChisla].size() < daljini[indexChisla]){
                cifriteNaChislata[indexChisla].push_back(cifri[indexCifri]);
                indexCifri++;
            }

            indexChisla--;
        }
    }

    for(int i = 0; i < broiChislaZaPrav; i++){
        reverse(cifriteNaChislata[i].begin(), cifriteNaChislata[i].end());
        /*for(auto j : cifriteNaChislata[i]){
            cout<<j;
        }
        cout<<endl;*/
    }

    //cout<<endl;

    //vector<char> sbor = sabiraneNaChisla(cifriteNaChislata[0], cifriteNaChislata[1]);

    vector<char> proizvedenie = umnojenieNaChisla(cifriteNaChislata[0], cifriteNaChislata[1]);

    for(int i = 2; i < broiChislaZaPrav; i++){
        proizvedenie = umnojenieNaChisla(proizvedenie, cifriteNaChislata[i]);
    }

    for(int i = proizvedenie.size() - 1; i >= 0; i--){
        cout<<proizvedenie[i];
    }
    cout<<endl;


    return 0;
}
