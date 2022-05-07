#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const long long osnovaStepenNaDeset = 9;

const long long osnova = 1000000000;

long long koqCirfra;

long long ediKoqSiDesCifra(long long chislo, long long kadeCifra){

    for(long long i = 0; i < kadeCifra; i++){
        chislo /= 10;
    }

    return chislo%10;
}

vector<int> umnojiDveChisla(vector<int>& parvo, vector<int>& vtoro){

    vector<int> rezultatNaObratno;
    rezultatNaObratno.resize(parvo.size() + vtoro.size());

    long long doKadeParvo = min((long long)parvo.size(), koqCirfra);
    long long doKadeVtoro = min((long long)vtoro.size(), koqCirfra);

    for(long long i = 0; i < doKadeParvo; i++){

        long long prenos = 0;
        long long cifraParvo = parvo[i];

        for(long long j = 0; j < doKadeVtoro; j++){
            long long cifraVtoro = vtoro[j];

            long long tuka = cifraParvo*cifraVtoro + rezultatNaObratno[i + j] + prenos;

            prenos = tuka/osnova;

            rezultatNaObratno[i + j] = tuka%osnova;
        }

        if(prenos > 0){
            rezultatNaObratno[i + doKadeVtoro] += prenos;
        }

    }

    rezultatNaObratno.resize(min((long long)rezultatNaObratno.size(), koqCirfra/osnovaStepenNaDeset + 1));
    return rezultatNaObratno;
}


vector<int> vdigniChislotoNaStepen(vector<int>& koeChislo, long long stepen){
    vector<int>& kopieChislo = koeChislo;
    vector<int> zaVrasht = {1};

    while(stepen > 0){
        if((stepen & 1) == 1){
            zaVrasht = umnojiDveChisla(zaVrasht, kopieChislo);
        }
        kopieChislo = umnojiDveChisla(kopieChislo, kopieChislo);
        stepen >>= 1;
    }

    return zaVrasht;
}

long long broiTestove;

long long chislo;

long long naKoqStepen;

int main(){

    cin>>broiTestove;

    for(long long t = 0; t < broiTestove; t++){
        cin>>chislo>>naKoqStepen>>koqCirfra;

        vector<int> chisloto;

        while(chislo > 0){
            chisloto.push_back(chislo%osnova);
            chislo/=osnova;
        }

        vector<int> stepenuvano = vdigniChislotoNaStepen(chisloto, naKoqStepen);


        long long otgovor = ediKoqSiDesCifra(stepenuvano[(koqCirfra - 1)/osnovaStepenNaDeset], (koqCirfra - 1)%osnovaStepenNaDeset);
        cout<<otgovor<<endl;
    }

    return 0;
}
