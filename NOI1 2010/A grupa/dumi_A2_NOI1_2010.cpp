#include<iostream>
#include<stack>
#include<vector>
using namespace std;

string duma;
long long kolkoPrediNeq;

vector<string> otgovori;

long long chisloOtgovarqshtoNaBukvata(char bukva){
    if(bukva == 'A'){
        return 0;
    }
    if(bukva == 'B'){
        return 1;
    }
    if(bukva == 'C'){
        return 2;
    }
    return 3;
}

char koqBukvaEtovaChislo(long long chislo){
    if(chislo == 0){
        return 'A';
    }
    if(chislo == 1){
        return 'B';
    }
    if(chislo == 2){
        return 'C';
    }
    return 'D';
}

long long chisloSTeziBukvi(string koqDuma){
    long long chislo = 0;

    for(unsigned int i = 0; i < koqDuma.size(); i++){
        long long tukashno = chisloOtgovarqshtoNaBukvata(koqDuma[i]);
        chislo += (tukashno << 2*(koqDuma.size() - 1 - i));
    }

    return chislo;
}

string dumaPoChislo(long long chislo, long long kolkoEDulga){
    long long kolkoSaNiBukvite = 0;

    stack<char> s;

    while(chislo > 0){
        char naToziIndex = koqBukvaEtovaChislo(chislo & 3);
        s.push(naToziIndex);
        kolkoSaNiBukvite++;
        chislo >>= 2;
    }

    while(kolkoSaNiBukvite < kolkoEDulga){
        s.push('A');
        kolkoSaNiBukvite++;
    }

    string dumichka;

    while(s.empty() == false){
        dumichka.push_back(s.top());
        s.pop();
    }

    return dumichka;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>duma>>kolkoPrediNeq;

    long long segashnoChislo = 0;

    long long dumataVChislo = chisloSTeziBukvi(duma);

    for(long long i = 0; i < kolkoPrediNeq - 1; i++){
        if(segashnoChislo == dumataVChislo){
            segashnoChislo++;
        }

        otgovori.push_back(dumaPoChislo(segashnoChislo, duma.size()));
        segashnoChislo++;
    }

    otgovori.push_back(dumaPoChislo(segashnoChislo^dumataVChislo, duma.size()));

    if((segashnoChislo^dumataVChislo) <= segashnoChislo || (segashnoChislo^dumataVChislo) == dumataVChislo){
        otgovori.pop_back();
        otgovori.pop_back();
        segashnoChislo = (1 << 2*duma.size()) - 1;
        otgovori.push_back(dumaPoChislo(segashnoChislo, duma.size()));
        otgovori.push_back(dumaPoChislo(segashnoChislo^dumataVChislo, duma.size()));
    }

    for(unsigned int i = 0; i < otgovori.size(); i++){
        cout<<otgovori[i]<<endl;
    }

    return 0;
}
