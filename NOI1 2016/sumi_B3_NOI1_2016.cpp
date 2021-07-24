#include<iostream>
#include<cmath>
using namespace std;

int chislo;
long long brVazmZaPredst[3010][15];

long long broiVazmozhnostiZaPredstavqne(long long koeChislo, long long naiVisokaStepen){
    if(koeChislo == 0){
        return 1;
    }

    if(naiVisokaStepen < 0){
        return 0;
    }

    if(koeChislo < 0){
        return 0;
    }

    if(brVazmZaPredst[koeChislo][naiVisokaStepen] > -1){
        //cout<<koeChislo<<" "<<naiVisokaStepen<<" "<<brVazmZaPredst[koeChislo][naiVisokaStepen]<<endl;
        return brVazmZaPredst[koeChislo][naiVisokaStepen];
    }

    long long broiVazmozhniNatatuk = 0;

    for(long long i = 0; i <= koeChislo; i++){
        //cout<<"Sega puskam rekursia s parametri: "<<koeChislo - (i * pow(2, naiVisokaStepen))<<" "<<naiVisokaStepen - 1<<endl;
        broiVazmozhniNatatuk += broiVazmozhnostiZaPredstavqne(koeChislo - (i * pow(2, naiVisokaStepen)), naiVisokaStepen - 1);
    }

    brVazmZaPredst[koeChislo][naiVisokaStepen] = broiVazmozhniNatatuk;
    //cout<<broiVazmozhniNatatuk<<endl;
    return broiVazmozhniNatatuk;
}

int main(){
    cin>>chislo;

    for(long long i = 0; i < 3010; i++){
        for(long long j = 0; j < 15; j++){
            brVazmZaPredst[i][j] = -1;
        }
    }

    long long stepenka = min(chislo/2, 15);

    long long brVazm = broiVazmozhnostiZaPredstavqne(chislo, stepenka);

    cout<<brVazm<<endl;

    return 0;
}
