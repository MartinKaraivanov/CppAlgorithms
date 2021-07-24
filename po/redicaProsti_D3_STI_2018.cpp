#include<iostream>
#include<cmath>
using namespace std;

int naiGolemiProstiDeliteli[250000];

////int naiGolqmProstDelitelNaChiso[1000001];
int drugNaiGolqmProstDelitelNaChiso[1000001];

int poslednoNaKoqPoziciqGoImame[1000001];

void palneneNaMinusEdinichki(){
    for(int i=0;i<1000001;i++){
        poslednoNaKoqPoziciqGoImame[i]=-1;
    }
}

/////int prosti[1000001];
/////int broiProsti;
bool composite[1000001];

void eratosten(){
    int n=1000001;
    int sqrt_n=sqrt(n);
    for(int i=2; i < n ; i++){
        if(composite[i]==false){
            drugNaiGolqmProstDelitelNaChiso[i]=i;
            for(int x=i+i;x<n;x+=i){
                composite[x]=true;
                drugNaiGolqmProstDelitelNaChiso[x]=i;
            }
        }
    }
/*
    for(int i=2;i<n;i++){
        if(composite[i]==false){
            prosti[broiProsti]=i;
            broiProsti++;
        }
    }
*/
}
/*
int naiGolqmProstDelitelNaTovaChisloKoetoEDadeno(int chislo){
    if(naiGolqmProstDelitelNaChiso[chislo]>0){
        return naiGolqmProstDelitelNaChiso[chislo];
    }

    int copie=chislo;
    for(int j=0;j<broiProsti;j++){
        bool daSeMahnaLi=false;
        while(copie%prosti[j]==0){
            if(copie==prosti[j]){
                daSeMahnaLi=true;
                break;
            }else{
                copie/=prosti[j];
            }
        }
        if(daSeMahnaLi==true){
            break;
        }
    }

    naiGolqmProstDelitelNaChiso[chislo]=copie;
    return copie;
}

int naiGlProstDelitelNaChislo(int chislo){
    if(naiGolqmProstDelitelNaChiso[chislo]>0){
        return naiGolqmProstDelitelNaChiso[chislo];
    }

    int copie=chislo;
    for(int j=0;j<broiProsti;j++){
        bool daSeMahnaLi=false;
        while(copie%prosti[j]==0){
            if(copie==prosti[j]){
                daSeMahnaLi=true;
                break;
            }else{
                copie/=prosti[j];
            }
            if(naiGolqmProstDelitelNaChiso[copie]>0){
                naiGolqmProstDelitelNaChiso[chislo]=naiGolqmProstDelitelNaChiso[copie];
                return naiGolqmProstDelitelNaChiso[copie];
            }
        }
        if(daSeMahnaLi==true){
            break;
        }
    }

    naiGolqmProstDelitelNaChiso[chislo]=copie;
    return copie;
}

int naiGolqmPDNaChisloto(int chislo){
    if(naiGolqmProstDelitelNaChiso[chislo]>0){
        return naiGolqmProstDelitelNaChiso[chislo];
    }

    int naiMalakPDNaTovaCh=naiMalkiqtProstDelitelNaTovaChislo(chislo);

    if(chislo==naiMalakPDNaTovaCh){
        return chislo;
    }

    int naiGPDNTC=max(naiGolqmPDNaChisloto(chislo/naiMalakPDNaTovaCh), naiMalakPDNaTovaCh);

    naiGolqmProstDelitelNaChiso[chislo]=naiGPDNTC;
    return naiGPDNTC;
}
*/
/*
int naiMalkiqtProstDelitelNaTovaChislo(int chislo){
    if(composite[chislo]==false){
        return chislo;
    }
    for(int i=0;i<broiProsti;i++){
        if(chislo%prosti[i]==0){
            return prosti[i];
        }
    }
}

void praveneBezRekursivno(){
    for(int chisla=2;chisla<1000001;chisla++){
        int naiMalakProstDelitel=naiMalkiqtProstDelitelNaTovaChislo(chisla);
        if(chisla==naiMalakProstDelitel){
            naiGolqmProstDelitelNaChiso[chisla]=chisla;
        }else{
            int nGPD=naiGolqmProstDelitelNaChiso[chisla/naiMalakProstDelitel];
            naiGolqmProstDelitelNaChiso[chisla]=nGPD;
        }
    }
}
*/
int main(){
    palneneNaMinusEdinichki();
    eratosten();
    int broiChisla;

    cin>>broiChisla;

    int chisla[broiChisla];

    for(int i=0;i<broiChisla;i++){
        cin>>chisla[i];
    }

    for(int i=0;i<broiChisla;i++){
        int ngpd=drugNaiGolqmProstDelitelNaChiso[chisla[i]];
        naiGolemiProstiDeliteli[i]=ngpd;
    }

    int nachalenElNDR;
    int kraenElNDR;
    int naiDalgaRedica=0;

    int predpolagaemoNachalo=0;
    int predpolagaemKrai=-1;
    int segashnaDalzhina=0;

    for(int i=0;i<broiChisla;i++){
        if(poslednoNaKoqPoziciqGoImame[naiGolemiProstiDeliteli[i]]>=predpolagaemoNachalo){
            int sKolkoDaSeSmaliDalzhinata=poslednoNaKoqPoziciqGoImame[naiGolemiProstiDeliteli[i]]-predpolagaemoNachalo+1;
            predpolagaemoNachalo=poslednoNaKoqPoziciqGoImame[naiGolemiProstiDeliteli[i]]+1;
            segashnaDalzhina-=sKolkoDaSeSmaliDalzhinata;
        }

        poslednoNaKoqPoziciqGoImame[naiGolemiProstiDeliteli[i]]=i;

        segashnaDalzhina++;
        predpolagaemKrai++;

        if(segashnaDalzhina>naiDalgaRedica){
            naiDalgaRedica=segashnaDalzhina;
            nachalenElNDR=predpolagaemoNachalo;
            kraenElNDR=predpolagaemKrai;
        }
    }

    cout<<nachalenElNDR+1<<" "<<kraenElNDR+1<<endl;

    return 0;
}
